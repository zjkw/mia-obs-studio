#include "win-update-helpers.hpp"
#include "update-window.hpp"
#include "remote-text.hpp"
#include "qt-wrappers.hpp"
#include "win-update.hpp"
#include "obs-app.hpp"

#include <QMessageBox>

#include <string>

#include <util/windows/WinHandle.hpp>
#include <util/util.hpp>
#include <jansson.h>
#include <blake2.h>

#include <time.h>
#include <strsafe.h>
#include <winhttp.h>
#include <shellapi.h>
#include <QFile>
#include <QCryptographicHash>
#include <platform.hpp>

using namespace std;

/* ------------------------------------------------------------------------ */

#ifndef WIN_MANIFEST_URL
#define WIN_MANIFEST_URL "http://mia-upload.oss-cn-shanghai.aliyuncs.com/meten/update/obs.json" //"https://obsproject.com/update_studio/manifest.json"
#endif

#define TEST_BUILD

/* ------------------------------------------------------------------------ */

static bool QuickWriteFile(const char *file, const void *data, size_t size)
{
    try {
        BPtr<wchar_t> w_file;
        if (os_utf8_to_wcs_ptr(file, 0, &w_file) == 0)
            return false;

        WinHandle handle = CreateFileW(
            w_file,
            GENERIC_WRITE,
            0,
            nullptr,
            CREATE_ALWAYS,
            FILE_FLAG_WRITE_THROUGH,
            nullptr);

        if (handle == INVALID_HANDLE_VALUE)
            throw strprintf("Failed to open file '%s': %lu",
                file, GetLastError());

        DWORD written;
        if (!WriteFile(handle, data, (DWORD)size, &written, nullptr))
            throw strprintf("Failed to write file '%s': %lu",
                file, GetLastError());
    }
    catch (string text) {
        blog(LOG_WARNING, "%s: %s", __FUNCTION__, text.c_str());
        return false;
    }
  
    return true;
}

static bool QuickReadFile(const char *file, string &data)
{
    try {
        BPtr<wchar_t> w_file;
        if (os_utf8_to_wcs_ptr(file, 0, &w_file) == 0)
            return false;

        WinHandle handle = CreateFileW(
            w_file,
            GENERIC_READ,
            FILE_SHARE_READ,
            nullptr,
            OPEN_EXISTING,
            0,
            nullptr);

        if (handle == INVALID_HANDLE_VALUE)
            throw strprintf("Failed to open file '%s': %lu",
                file, GetLastError());

        DWORD size = GetFileSize(handle, nullptr);
        data.resize(size);

        DWORD read;
        if (!ReadFile(handle, &data[0], size, &read, nullptr))
            throw strprintf("Failed to write file '%s': %lu",
                file, GetLastError());
    }
    catch (string text) {
        blog(LOG_WARNING, "%s: %s", __FUNCTION__, text.c_str());
        return false;
    }

   return true;
}

QString getFileMD5(const QString &file)
{
    QFile localFile(file);
    if (localFile.open(QFile::ReadOnly))
    {
        QCryptographicHash hash(QCryptographicHash::Md5);
        hash.addData(localFile.readAll());
        localFile.close();

        return QString::fromLatin1(hash.result().toHex());
    }
    return QString();
}


/* ------------------------------------------------------------------------ */

static bool ParseUpdateManifest(const char *manifest, uint& ver, string &url, string &md5)
{
    try {

        json_error_t error;
        Json root(json_loads(manifest, 0, &error));
        if (!root)
            throw strprintf("Failed reading json string (%d): %s",
                error.line, error.text);

        if (!json_is_object(root.get()))
            throw string("Root of manifest is not an object");

        QString ver_s = root.GetString("ver");
        ver = ver_s.toUInt();
        
        if (ver == 0)
            throw strprintf("Invalid version number: %u", ver);

        json_t *jurl = json_object_get(root, "url");
        if (!json_is_string(jurl))
            throw string("'url' value invalid");
        url = json_string_value(jurl);

        json_t *jmd5 = json_object_get(root, "md5");
        if (!json_is_string(jmd5))
            throw string("'md5' value invalid");
        md5 = json_string_value(jmd5);
    }
    catch (string text)
    {
        blog(LOG_WARNING, "%s: %s", __FUNCTION__, text.c_str());
        return false;
    }
    
    return true;
}

void AutoUpdateThread::infoMsg(const QString &title, const QString &text)
{
	OBSMessageBox::information(App()->GetMainWindow(), title, text);
}

void AutoUpdateThread::info(const QString &title, const QString &text)
{
	QMetaObject::invokeMethod(this, "infoMsg",
			Qt::BlockingQueuedConnection,
			Q_ARG(QString, title),
			Q_ARG(QString, text));
}

int AutoUpdateThread::queryUpdateSlot()
{
	OBSUpdate updateDlg(App()->GetMainWindow());
	return updateDlg.exec();
}

int AutoUpdateThread::queryUpdate()
{
	int ret = OBSUpdate::Yes;
	QMetaObject::invokeMethod(this, "queryUpdateSlot",
			Qt::BlockingQueuedConnection,
			Q_RETURN_ARG(int, ret));
	return ret;
}

static bool IsFileInUse(const wstring &file)
{
	WinHandle f = CreateFile(file.c_str(), GENERIC_WRITE, 0, nullptr,
			OPEN_EXISTING, 0, nullptr);
	if (!f.Valid()) {
		int err = GetLastError();
		if (err == ERROR_SHARING_VIOLATION ||
		    err == ERROR_LOCK_VIOLATION)
			return true;
	}

	return false;
}

static bool IsGameCaptureInUse()
{
	wstring path = L"..\\..\\data\\obs-plugins\\win-capture\\graphics-hook";
	return IsFileInUse(path + L"32.dll") ||
	       IsFileInUse(path + L"64.dll");
}

void AutoUpdateThread::run()
{
    try {
        long           responseCode;
        vector<string> extraHeaders;
        string         text;
        string         error;
        bool           success;

        struct FinishedTrigger {
            inline ~FinishedTrigger()
            {
                QMetaObject::invokeMethod(App()->GetMainWindow(),
                    "updateCheckFinished");
            }
        } finishedTrigger;

        auto ActiveOrGameCaptureLocked = [this]()
        {
            if (video_output_active(obs_get_video())) {
                info(QTStr("Updater.Running.Title"),
                    QTStr("Updater.Running.Text"));
                return true;
            }
            if (IsGameCaptureInUse()) {
                info(QTStr("Updater.GameCaptureActive.Title"),
                    QTStr("Updater.GameCaptureActive.Text"));
                return true;
            }

            return false;
        };

        /* ----------------------------------- *
         * warn if running or gc locked        */

        if (ActiveOrGameCaptureLocked())
            return;

        /* ----------------------------------- *
         * get current install GUID            */

         /* NOTE: this is an arbitrary random number that we use to count the
          * number of unique OBS installations and is not associated with any
          * kind of identifiable information */

          /* ----------------------------------- *
           * get manifest from server            */

        string signature;
        success = GetRemoteFile(WIN_MANIFEST_URL, text, error, &responseCode,
            nullptr, nullptr, extraHeaders, &signature);

        if (!success || responseCode != 200) {
            if (responseCode == 404)
                return;

            throw strprintf("Failed to fetch manifest file: %s", error.c_str());
        }

        /* ----------------------------------- *
         * verify file signature               */

         /* ----------------------------------- *
          * write or load manifest              */
          /* ----------------------------------- *
           * check manifest for update           */

        uint ver = 0;
        string url;
        string md5;

        success = ParseUpdateManifest(text.c_str(), ver, url, md5);
        if (!success)
            throw string("Failed to parse manifest");

        if (url.empty() || md5.empty()) {
            info(QTStr("Updater.NoUpdatesAvailable.Title"),
                QTStr("Updater.NoUpdatesAvailable.Text"));
            return;
        }
        if (ver <= MIA_VERNUM)
        {
            if (manualUpdate)
            {
                ///xzl tbd 提示: 你已经是最新版本!
                emit showUpdateTips(Str("Base.Course.Update.TipsTitle"), Str("Base.Course.Update.TipsContentUpdated"), Str("Base.Course.Update.TipsConfirm"));
                //QMessageBox::information(nullptr, Str("Base.Course.Update.TipsTitle"), Str("Base.Course.Update.TipsContentUpdated"), Str("Base.Course.Update.TipsConfirm"));
            }

            return;
        }
        if (ver == config_get_int(GetGlobalConfig(), "General", "TargetVersion"))
        {
            if (manualUpdate)
            {
                ///xzl tbd 提示: 正在升级，请稍候
                emit showUpdateTips(Str("Base.Course.Update.TipsTitle"), Str("Base.Course.Update.TipsContentUpdating"), Str("Base.Course.Update.TipsConfirm"));
                //QMessageBox::information(nullptr, Str("Base.Course.Update.TipsTitle"), Str("Base.Course.Update.TipsContentUpdating"), Str("Base.Course.Update.TipsConfirm"));
            }
            return;
        }
        config_set_int(GetGlobalConfig(), "General", "TargetVersion", ver);

        /* ----------------------------------- *
         * skip this version if set to skip    */

         /* ----------------------------------- *
          * warn again if running or gc locked  */

        if (ActiveOrGameCaptureLocked())
            return;

        /* ----------------------------------- *
         * fetch updater module                */

         /* ----------------------------------- *
          * query user for update               */
        BPtr<char> updateFilePath = GetConfigPathPtr("mia-obs-studio\\updates\\updater.exe");
        if (!os_file_exists(updateFilePath.Get()) || getFileMD5(QString(updateFilePath.Get())).compare(md5.c_str(), Qt::CaseInsensitive))
        {
            text.clear();
            success = GetRemoteFile(url.c_str(), text, error, &responseCode,
                nullptr, nullptr, extraHeaders, &signature);

            if (!success || responseCode != 200) 
            {
                config_set_int(GetGlobalConfig(), "General", "TargetVersion", 0);
                if (responseCode == 404)
                {
                    return;
                }
                throw strprintf("Failed to fetch update file: %s", error.c_str());
            }

            if (!QuickWriteFile(updateFilePath, text.data(), text.size()))
            {
                config_set_int(GetGlobalConfig(), "General", "TargetVersion", 0);
                throw strprintf("QuickWriteFile failed");
            }
        }
 
        if (getFileMD5(QString(updateFilePath.Get())).compare(md5.c_str(), Qt::CaseInsensitive))
        {
            config_set_int(GetGlobalConfig(), "General", "TargetVersion", 0);
              throw strprintf("getFileMD5 failed");
        }

        int queryResult = queryUpdate();

        if (queryResult != OBSUpdate::Yes)
        {
            return;
        }

        /* ----------------------------------- *
         * get working dir                     */

        wchar_t cwd[MAX_PATH];
        GetModuleFileNameW(nullptr, cwd, _countof(cwd) - 1);
        wchar_t *p = wcsrchr(cwd, '\\');
        if (p)
            *p = 0;

        /* ----------------------------------- *
         * execute updater                     */


        BPtr<wchar_t> wUpdateFilePath;

        size_t size = os_utf8_to_wcs_ptr(updateFilePath, 0, &wUpdateFilePath);
        if (!size)
            throw string("Could not convert updateFilePath to wide");

        /* note, can't use CreateProcess to launch as admin. */
        SHELLEXECUTEINFO execInfo = {};

        execInfo.cbSize = sizeof(execInfo);
        execInfo.lpFile = wUpdateFilePath;
#ifndef UPDATE_CHANNEL
#define UPDATE_ARG_SUFFIX L""
#else
#define UPDATE_ARG_SUFFIX UPDATE_CHANNEL
#endif
        if (App()->IsPortableMode())
            execInfo.lpParameters = UPDATE_ARG_SUFFIX L" Portable";
        else
            execInfo.lpParameters = UPDATE_ARG_SUFFIX;

        execInfo.lpDirectory = cwd;
        execInfo.nShow = SW_SHOWNORMAL;

        if (!ShellExecuteEx(&execInfo)) {
            QString msg = QTStr("Updater.FailedToLaunch");
            info(msg, msg);
            throw strprintf("Can't launch updater '%s': %d",
                updateFilePath.Get(), GetLastError());
        }

        /* force OBS to perform another update check immediately after updating
         * in case of issues with the new version */

        config_set_int(GetGlobalConfig(), "General", "TargetVersion", 0);
        QMetaObject::invokeMethod(App()->GetMainWindow(), "close");

    }
    catch (string text) {
        blog(LOG_WARNING, "%s: %s", __FUNCTION__, text.c_str());
    }
}

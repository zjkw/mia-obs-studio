#include "mia-login-dlg.hpp"
#include <QDebug>
#include <QtWebChannel/QWebChannel>
#include "singleton.h"
#include "obs-app.hpp"

// zjg: for debug passby login ui
//#define FAKE_LOGIN 1

bridge::bridge()
{
    qDebug() << "version:" << App()->GetVersionString().c_str();
}

bridge* bridge::instance()
{
	static bridge s_obj;
	return &s_obj;
}

void bridge::OnJs2Cpp(const QString &cmd, const QString &json)
{
	emit JsSign(cmd, json);
}

MiaLoginDialog::MiaLoginDialog(QWidget *parent) :
	QDialog(parent), _suc(false), _view(nullptr)
{
	setWindowTitle(App()->GetMiaAppName());
	resize(320, 450);
	QIcon icon;
	icon.addFile(QStringLiteral(":/res/images/obs.png"), QSize(), QIcon::Normal, QIcon::Off);
	setWindowIcon(icon);
	setStyleSheet(QStringLiteral(""));

	//
	QObject* bridge = (QObject*)bridge::instance();

	connect(bridge, SIGNAL(JsSign(const QString&, const QString&)), this, SLOT(OnWxLoginResult(const QString&, const QString&)));

	_view = new QWebEngineView(this);

    QWebChannel *channel = new QWebChannel(_view->page());
    channel->registerObject(QStringLiteral("MiaBridge"), bridge);                              //lianjie就是交互类
    _view->page()->setWebChannel(channel);

    QString mia_url = QString("http://coursetest.miamusic.com/obs-login.html?varDyna=%1").arg(QDateTime::currentSecsSinceEpoch());
//    QString mia_url = QString("d:/obs-login.html?varDyna=%1").arg(QDateTime::currentSecsSinceEpoch());
//    _view->load(QUrl("d:/index.html"));

#ifndef FAKE_LOGIN
    _view->load(QUrl(mia_url));
#else
    _guid = QString("1619260d8cf5a7bad298c3d7a6dad46eguid");
    _uid = QString("76740");
    _token = QString("ce69b97834ac04efd635ded92a43e1aa_1518185562");
        
//成功提示
    SetPromptText("working");

    //发起Mia服务器连接
    MiaWebsocketClient*	wc = &singleton<MiaWebsocketClient>::instance();
    connect(wc, SIGNAL(SignConnect(MiaWebsocketClient*)), this, SLOT(OnWebSocketConnect(MiaWebsocketClient*)));
    connect(wc, SIGNAL(SignClose(MiaWebsocketClient*)), this, SLOT(OnWebSocketClose(MiaWebsocketClient*)));
    wc->Connect("ws://ws-course-test.miamusic.com");
#endif
    _view->show();
	//
}

MiaLoginDialog::~MiaLoginDialog()
{
	MiaWebsocketClient*	wc = &singleton<MiaWebsocketClient>::instance();
	disconnect(wc, SIGNAL(SignConnect()), this, SLOT(OnWebSocketConnect()));
	disconnect(wc, SIGNAL(SignClose()), this, SLOT(OnWebSocketClose()));

	delete _view;
	qDebug() << "~MiaLoginDialog()";
}

bool MiaLoginDialog::GetResult()
{
	return _suc;
}

void MiaLoginDialog::resizeEvent(QResizeEvent*)
{
	if (_view)
	{
		_view->resize(this->size());
	}
}

///////////////业务处理
bool MiaLoginDialog::EncodePromptText(const QString& in, QString& out)
{
	json_t* root = json_object();
	json_object_set_new(root, "text", json_string(in.toUtf8()));
	char* data1 = json_dumps(root, JSON_INDENT(0));
	out = QString::fromUtf8(data1);
	free(data1);
	json_decref(root);

	return true;
}

bool MiaLoginDialog::DecodeLoginResult(const QString& json, bool& bSuc, QString& guid, QString& uid, QString& token)
{
	bSuc = false;

	json_error_t error;
	json_t* jroot = json_loads(json.toUtf8(), JSON_REJECT_DUPLICATES, &error);

	do
	{
		json_t* jret = json_object_get(jroot, "cmd");
		if (!json_is_string(jret))
		{
			break;
		}
		QString ret = json_string_value(jret);
		if (!ret.compare("success"))
		{
			json_t* jguid = json_object_get(jroot, "guid");
			if (!json_is_string(jguid))
			{
				break;
			}
			json_t* juid = json_object_get(jroot, "uID");
			if (!json_is_string(juid))
			{
				break;
			}
			json_t* jtoken = json_object_get(jroot, "token");
			if (!json_is_string(jtoken))
			{
				break;
			}

			guid = json_string_value(jguid);
			uid = json_string_value(juid);
			token = json_string_value(jtoken);

			bSuc = true;
		}
	} while (0);
	
	json_decref(jroot);

	return bSuc;
}

bool MiaLoginDialog::EncodeMiaWCCommonHead(json_t* root, const QString& guid, const QString& cmd, const QString& stamp)
{
	json_object_set_new(root, "g", json_string(guid.toUtf8()));
	json_object_set_new(root, "c", json_string(cmd.toUtf8()));

	json_object_set_new(root, "r", json_string(QString("1").toUtf8()));
	json_object_set_new(root, "a", json_string(QString("6").toUtf8()));
	json_object_set_new(root, "s", json_string(stamp.toUtf8()));
	json_object_set_new(root, "b", json_string(QString("1.0.0.1").toUtf8()));
	
	return true;
}

bool MiaLoginDialog::EncodeMiaWCLoginReq(const QString& guid, const QString& uid, const QString& token, const QString& stamp, QString& out)
{
	json_t* root = json_object();

	EncodeMiaWCCommonHead(root, guid, "User.Post.Session", stamp);

	json_t* value = json_object();
		json_object_set_new(value, "guid", json_string(guid.toUtf8()));
		json_object_set_new(value, "uID", json_string(uid.toUtf8()));
		json_object_set_new(value, "token", json_string(token.toUtf8()));
	json_object_set_new(root, "v", value);
//	json_decref(value);
	
	char* data1 = json_dumps(root, JSON_INDENT(0));
	out = QString::fromUtf8(data1);
	free(data1);
	json_decref(root);

	return true;
}

bool MiaLoginDialog::DecodeMiaWCLoginRes(const QString& json, bool& bSuc)
{
	bSuc = false;

	json_error_t error;
	json_t* jroot = json_loads(json.toUtf8(), JSON_REJECT_DUPLICATES, &error);

	do
	{
		json_t* jCmd = json_object_get(jroot, "C");
		if (!json_is_string(jCmd))
		{
			break;
		}
		QString cmd = json_string_value(jCmd);
		if (cmd.compare("User.Post.Session", Qt::CaseInsensitive))
		{
			break;
		}

		json_t* jValue = json_object_get(jroot, "v");
		if (!json_is_object(jValue))
		{
			break;
		}

		json_t* jret = json_object_get(jValue, "ret");
		if (!json_is_integer(jret))
		{
			break;
		}
		int64_t ret = json_integer_value(jret);
		if (ret != 0)
		{
			break;
		}


		bSuc = true;
	} while (0);

	json_decref(jroot);

	return bSuc;
}


bool MiaLoginDialog::EncodeMiaWCQueryObsReq(const QString& guid, const QString& stamp, QString& out)
{
	json_t* root = json_object();

	EncodeMiaWCCommonHead(root, guid, "Classroom.Get.Obsconfig", stamp);

	json_t* value = json_object();
	json_object_set_new(root, "v", value);
	//json_decref(value);

	char* data1 = json_dumps(root, JSON_INDENT(0));
	out = QString::fromUtf8(data1);
	free(data1);
	json_decref(root);

	return true;
}

bool MiaLoginDialog::DecodeMiaWCQueryObsRes(const QString& json, bool& bSuc, MiaObsServerConf* conf)
{
	bSuc = false;

	json_error_t error;
	json_t* jroot = json_loads(json.toUtf8(), JSON_REJECT_DUPLICATES, &error);

	do
	{
		json_t* jCmd = json_object_get(jroot, "C");
		if (!json_is_string(jCmd))
		{
			break;
		}
		QString cmd = json_string_value(jCmd);
		if (cmd.compare("Classroom.Get.Obsconfig", Qt::CaseInsensitive))
		{
			break;
		}

		json_t* jValue = json_object_get(jroot, "v");
		if (!json_is_object(jValue))
		{
			break;
		}

		json_t* jret = json_object_get(jValue, "ret");
		if (!json_is_integer(jret))
		{
			break;
		}
		int64_t ret = json_integer_value(jret);
		if (ret != 0)
		{
			break;		
		}

		json_t* jData = json_object_get(jValue, "data");
		if (!json_is_object(jData))
		{
			break;
		}

		json_t* jGeneral = json_object_get(jData, "General");
		if (!json_is_object(jGeneral))
		{
			break;
		}
		json_t* jName = json_object_get(jGeneral, "Name");
		if (!json_is_string(jName))
		{
			break;
		}
		conf->g.name = json_string_value(jName);

		json_t* jStream = json_object_get(jData, "Stream");
		if (!json_is_object(jStream))
		{
            conf->s.valid = false;
		}
        else
        {
            json_t* jUrl = json_object_get(jStream, "URL");
            if (!json_is_string(jUrl))
            {
                break;
            }
            conf->s.url = json_string_value(jUrl);
            json_t* jKey = json_object_get(jStream, "Key");
            if (!json_is_string(jKey))
            {
                break;
            }
            conf->s.key = json_string_value(jKey);

            json_t* jroomID = json_object_get(jStream, "roomID");
            if (!json_is_string(jroomID))
            {
                break;
            }
            conf->s.roomID = json_string_value(jroomID);

            json_t* jTitle = json_object_get(jStream, "Title");
            if (!json_is_string(jTitle))
            {
                break;
            }
            conf->s.title = json_string_value(jTitle);

            conf->s.valid = true;
        }

		json_t* jOutput = json_object_get(jData, "Output");
		if (!json_is_object(jOutput))
		{
			break;
		}
		json_t* jMode = json_object_get(jOutput, "Mode");
		if (!json_is_string(jMode))
		{
			break;
		}
		conf->o.Mode = json_string_value(jMode);

		json_t* jAudio = json_object_get(jOutput, "Audio");
		if (!json_is_object(jAudio))
		{
			break;
		}
		json_t* jTrackIndex = json_object_get(jAudio, "TrackIndex");
		if (!json_is_integer(jTrackIndex))
		{
			break;
		}
		conf->o.a.TrackIndex = json_integer_value(jTrackIndex);

		json_t* jRecType = json_object_get(jAudio, "RecType");
		if (!json_is_string(jRecType))
		{
			break;
		}
		conf->o.a.RecType = json_string_value(jRecType);

		json_t* jRecTracks = json_object_get(jAudio, "RecTracks");
		if (!json_is_integer(jRecTracks))
		{
			break;
		}
		conf->o.a.RecTracks = json_integer_value(jRecTracks);

		json_t* jFFOutputToFile = json_object_get(jAudio, "FFOutputToFile");
		if (!json_is_string(jFFOutputToFile))
		{
			break;
		}
		QString strFFOutputToFile = json_string_value(jFFOutputToFile);
		conf->o.a.FFOutputToFile = strFFOutputToFile.compare("true", Qt::CaseInsensitive) ? false : true;

		json_t* jBitrate = json_object_get(jAudio, "Bitrate");
		if (!json_is_string(jBitrate))
		{
			break;
		}
		conf->o.a.Bitrate = json_string_value(jBitrate);

		json_t* jKeyframe = json_object_get(jAudio, "Keyframe");
		if (!json_is_string(jKeyframe))
		{
			break;
		}
		conf->o.a.Keyframe = json_string_value(jKeyframe);

		json_t* jCPU = json_object_get(jAudio, "CPU");
		if (!json_is_string(jCPU))
		{
			break;
		}
		conf->o.a.CPU = json_string_value(jCPU);

		json_t* jProfile = json_object_get(jAudio, "Profile");
		if (!json_is_string(jProfile))
		{
			break;
		}
		conf->o.a.Profile = json_string_value(jProfile);

		json_t* jTune = json_object_get(jAudio, "Tune");
		if (!json_is_string(jTune))
		{
			break;
		}
		conf->o.a.Tune = json_string_value(jTune);

		json_t* jVideo = json_object_get(jOutput, "Video");
		if (!json_is_object(jVideo))
		{
			break;
		}
		json_t* jOutputCX = json_object_get(jVideo, "OutputCX");
		if (!json_is_string(jOutputCX))
		{
			break;
		}
		conf->o.v.OutputCX = json_string_value(jOutputCX);

		json_t* jOutputCY = json_object_get(jVideo, "OutputCY");
		if (!json_is_string(jOutputCY))
		{
			break;
		}
		conf->o.v.OutputCY = json_string_value(jOutputCY);

		json_t* jFPSType = json_object_get(jVideo, "FPSType");
		if (!json_is_string(jFPSType))
		{
			break;
		}
		conf->o.v.FPSType = json_string_value(jFPSType);

		json_t* jFPSInt = json_object_get(jVideo, "FPSInt");
		if (!json_is_string(jFPSInt))
		{
			break;
		}
		conf->o.v.FPSInt = json_string_value(jFPSInt);

		json_t* jScaleType = json_object_get(jVideo, "ScaleType");
		if (!json_is_string(jScaleType))
		{
			break;
		}
		conf->o.v.ScaleType = json_string_value(jScaleType);

		bSuc = true;
	} while (0);

	json_decref(jroot);

	return bSuc;
}

bool MiaLoginDialog::SetPromptText(const QString& in)
{
	bridge* bridge = bridge::instance();

	QString out;
	EncodePromptText(in, out);
	emit bridge->Cpp2Js("setPromptText", out);

	return true;
}

void MiaLoginDialog::OnWxLoginResult(const QString& cmd, const QString& json)
{
	if (cmd.compare("wxLogin", Qt::CaseInsensitive))
	{
		return;
	}
	
	bool bSuc = false;
	QString guid;
	QString uid;
	QString token;
	if (!DecodeLoginResult(json, bSuc, _guid, _uid, _token) || !bSuc)
	{
		//失败提示
		SetPromptText("fail");
		return;
	}
	
	//成功提示
	SetPromptText("working");

	//发起Mia服务器连接
	MiaWebsocketClient*	wc = &singleton<MiaWebsocketClient>::instance();
	connect(wc, SIGNAL(SignConnect(MiaWebsocketClient*)), this, SLOT(OnWebSocketConnect(MiaWebsocketClient*)));
	connect(wc, SIGNAL(SignClose(MiaWebsocketClient*)), this, SLOT(OnWebSocketClose(MiaWebsocketClient*)));
	wc->Connect("ws://ws-course-test.miamusic.com");
}

void MiaLoginDialog::OnWebSocketConnect(MiaWebsocketClient* wc)
{
	QString out;
	EncodeMiaWCLoginReq(_guid, _uid, _token, wc->UniqueTimeStamp(), out);
	connect(wc, SIGNAL(SignRecvMsg(MiaWebsocketClient*, const QString&)), this, SLOT(OnMiaLoginRes(MiaWebsocketClient*, const QString&)));
	wc->SendJsonReq(out);
}

void MiaLoginDialog::OnWebSocketClose(MiaWebsocketClient* wc)
{
	//失败提示
	SetPromptText("fail");
}

void MiaLoginDialog::OnMiaLoginRes(MiaWebsocketClient* wc, const QString& json)
{
	disconnect(wc, SIGNAL(SignRecvMsg(MiaWebsocketClient*, const QString&)), this, SLOT(OnMiaLoginRes(MiaWebsocketClient*, const QString&)));

	//验证cmd
	bool bSuc = false;
	if (!DecodeMiaWCLoginRes(json, bSuc) || !bSuc)
	{
		SetPromptText("fail");
		return;
	}
	
	QString out;
	EncodeMiaWCQueryObsReq(_guid, wc->UniqueTimeStamp(), out);
	connect(wc, SIGNAL(SignRecvMsg(MiaWebsocketClient*, const QString&)), this, SLOT(OnMiaQueryObsRes(MiaWebsocketClient*, const QString&)));
	wc->SendJsonReq(out);
}

void MiaLoginDialog::OnMiaQueryObsRes(MiaWebsocketClient* wc, const QString& json)
{
	disconnect(wc, SIGNAL(SignRecvMsg(MiaWebsocketClient*, const QString&)), this, SLOT(OnMiaQueryObsRes(MiaWebsocketClient*, const QString&)));
	bool bSuc = false;
	if (!DecodeMiaWCQueryObsRes(json, bSuc, App()->GetMiaObsServerConf()) || !bSuc)
	{
		SetPromptText("fail");
		return;
	}

	App()->SetMiaLogin(_guid, _uid, _token);
	_suc = true;

	//自动销毁窗口
	accept();
}

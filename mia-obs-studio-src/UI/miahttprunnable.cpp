#include "miahttprunnable.h"
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QEventLoop>

CHttpRunnable::CHttpRunnable()
{
	setAutoDelete(true);
	m_manager = new QNetworkAccessManager(this);
	connect(m_manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinish(QNetworkReply *)), Qt::BlockingQueuedConnection);
}

CHttpRunnable::~CHttpRunnable()
{

}

void CHttpRunnable::initRunnable(int key, const QString &url, const QString &data, const QString &path, CHttpCenterPrivate::HttpType type)
{
	m_key = key;
	m_url = QUrl(url);
	m_data = data;
	m_path = path;
	m_type = type;
}

void CHttpRunnable::replyFinish(QNetworkReply *reply)
{
	int code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
	replyFinish(!reply->error(), code);
}

CHttpDownloadRunnable::CHttpDownloadRunnable() :m_pFile(nullptr)
{

}

CHttpDownloadRunnable::~CHttpDownloadRunnable()
{
	if (m_pFile)
	{
		m_pFile->close();
		delete m_pFile;
		m_pFile = nullptr;
	}
}

void CHttpDownloadRunnable::run()
{
	QNetworkRequest request;
	request.setUrl(m_url);
	QNetworkAccessManager manager;

	if (m_pFile)
	{
		m_pFile->close();
		delete m_pFile;
		m_pFile = nullptr;
	}

    QFile file(m_path);
    if (file.exists())
    {
        file.remove();
    }
	m_pFile = new QFile(m_path);
	m_pFile->open(QIODevice::Append);
	m_reply = manager.get(request);

	QEventLoop loop;
	connect(m_reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadProgress(qint64, qint64)), Qt::BlockingQueuedConnection);
	connect(m_reply, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::BlockingQueuedConnection);
	QObject::connect(m_reply, SIGNAL(finished()), &loop, SLOT(quit()));

	loop.exec();

	emit m_manager->finished(m_reply);
}

void CHttpDownloadRunnable::downloadProgress(qint64 receive, qint64 total)
{
	emit progress(m_key, total, receive);
}

void CHttpDownloadRunnable::readyRead()
{
	m_pFile->write(m_reply->readAll());
}

void CHttpDownloadRunnable::replyFinish(bool suc, int code)
{
	if (!suc)
	{
		m_pFile->remove();
	}
	m_pFile->close();
	delete m_pFile;
	m_pFile = nullptr;
	emit finish(m_key, code, m_path);
}

void CHttpUploadRunnable::run()
{

}

void CHttpUploadRunnable::replyFinish(bool suc, int code)
{

}

void CHttpRequestRunnable::run()
{

}

void CHttpRequestRunnable::replyFinish(bool suc, int code)
{

}

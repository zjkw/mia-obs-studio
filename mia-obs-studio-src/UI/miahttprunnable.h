#ifndef MIAHTTPRUNNABLE_H
#define MIAHTTPRUNNABLE_H
#include <QRunnable>
#include <QObject>
#include <QUrl>
#include "miahttpcenterprivate.h"
class QNetworkReply;
class QNetworkAccessManager;
class QNetworkReply;
class QFile;

class CHttpRunnable : public QObject, public QRunnable
{
	Q_OBJECT
public:
	CHttpRunnable();
	virtual ~CHttpRunnable();
	void initRunnable(int key, const QString &url, const QString &data, const QString &path, CHttpCenterPrivate::HttpType type);
signals:
	void progress(int key, int total, int current);
	void finish(int key, int code, const QString &extend);
	protected slots:
	void replyFinish(QNetworkReply *reply);
protected:
	virtual void replyFinish(bool suc, int code) = 0;
protected:
	int m_key;
	QString m_data;
	QString m_path;
	CHttpCenterPrivate::HttpType m_type;
	QNetworkAccessManager *m_manager;
	QUrl m_url;
	QNetworkReply *m_reply;
};

class CHttpDownloadRunnable : public CHttpRunnable
{
	Q_OBJECT
public:
	CHttpDownloadRunnable();
	~CHttpDownloadRunnable();
	void run() override;
	protected slots:
	void downloadProgress(qint64, qint64);
	void readyRead();
protected:
	void replyFinish(bool suc, int code) override;
protected:
	QFile * m_pFile;
};

class CHttpUploadRunnable : public CHttpRunnable
{
	Q_OBJECT
public:
	void run() override;
protected:
	void replyFinish(bool suc, int code) override;
};

class CHttpRequestRunnable : public CHttpRunnable
{
	Q_OBJECT
public:
	void run() override;
protected:
	void replyFinish(bool suc, int code) override;
};

#endif // MIAHTTPRUNNABLE_H

#pragma once

#include <QtCore/QObject>
#include <QtWebSockets/QWebSocket>

class MiaWebsocketClient : public QObject
{
	Q_OBJECT
public:
	explicit MiaWebsocketClient();
	virtual ~MiaWebsocketClient();
	bool Connect(const QString& url);
	bool SendJsonReq(const QString& json);
	QString UniqueTimeStamp();

	virtual void timerEvent(QTimerEvent *event);

signals:
	void SignConnect(MiaWebsocketClient* wc);
	void SignClose(MiaWebsocketClient* wc);
	void SignRecvMsg(MiaWebsocketClient* wc, const QString&);
	
protected slots:
	void OnWebsocketConnected();
	void OnWebsocketClosed();
	void OnWebsocketMessage(QString message);

private:
	QWebSocket m_webSocket;
	quint64  m_stamp;
    QString m_url;
    int     m_retry_connet;

	int m_nTimerID_Pingpong;
    int m_nTimerID_RetryConnect;
};


#include "mia-websocket-client.hpp"
#include "obs-app.hpp"

#define TIMER_TIMEOUT (45 * 1000)

///////////////业务处理
MiaWebsocketClient::MiaWebsocketClient() : m_nTimerID(0)
{
	connect(&m_webSocket, &QWebSocket::connected, this, &MiaWebsocketClient::OnWebsocketConnected);
	connect(&m_webSocket, &QWebSocket::disconnected, this, &MiaWebsocketClient::OnWebsocketClosed);
	connect(&m_webSocket, &QWebSocket::textMessageReceived,	this, &MiaWebsocketClient::OnWebsocketMessage);

	m_stamp = QDateTime::currentMSecsSinceEpoch();
}

MiaWebsocketClient::~MiaWebsocketClient()
{
	if (m_nTimerID)
	{
		killTimer(m_nTimerID);
		m_nTimerID = 0;
	}
}

bool MiaWebsocketClient::Connect(const QString& url)
{
	m_webSocket.open(QUrl(url));
	return true;
}

bool MiaWebsocketClient::SendJsonReq(const QString& json)
{
	if (!m_webSocket.isValid())
	{
		return false;
	}

	m_webSocket.sendTextMessage(json);

	return true;
}

QString MiaWebsocketClient::UniqueTimeStamp()
{
	quint64 stamp = QDateTime::currentMSecsSinceEpoch();
	if (m_stamp == stamp)
	{
		m_stamp++;
	}
	else
	{
		m_stamp = stamp;
	}

	QString text;
	text.number(m_stamp);
	return text;
}

void MiaWebsocketClient::OnWebsocketConnected()
{
	m_nTimerID = startTimer(TIMER_TIMEOUT);
	emit SignConnect(this);
}

void MiaWebsocketClient::OnWebsocketClosed()
{
	killTimer(m_nTimerID);
	m_nTimerID = 0;
	emit SignClose(this);
}

void MiaWebsocketClient::OnWebsocketMessage(QString message)
{
	if (message.compare("PONG", Qt::CaseInsensitive))
	{
		emit SignRecvMsg(this, message);
	}
}

void MiaWebsocketClient::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == m_nTimerID)
	{
		m_webSocket.sendTextMessage("PING");
	}
}




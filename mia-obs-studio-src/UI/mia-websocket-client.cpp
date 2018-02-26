#include "mia-websocket-client.hpp"
#include "obs-app.hpp"

#define TIMER_TIMEOUT_PINGPONG (45 * 1000)
#define TIMER_TIMEOUT_RETRYCONNECT (1* 1000)

///////////////业务处理
MiaWebsocketClient::MiaWebsocketClient() : m_nTimerID_Pingpong(0), m_nTimerID_RetryConnect(0), m_retry_connet(0)
{
	connect(&m_webSocket, &QWebSocket::connected, this, &MiaWebsocketClient::OnWebsocketConnected);
	connect(&m_webSocket, &QWebSocket::disconnected, this, &MiaWebsocketClient::OnWebsocketClosed);
	connect(&m_webSocket, &QWebSocket::textMessageReceived,	this, &MiaWebsocketClient::OnWebsocketMessage);

	m_stamp = QDateTime::currentMSecsSinceEpoch();
}

MiaWebsocketClient::~MiaWebsocketClient()
{
	if (m_nTimerID_Pingpong)
	{
		killTimer(m_nTimerID_Pingpong);
		m_nTimerID_Pingpong = 0;
	}
	if (m_nTimerID_RetryConnect)
	{
		killTimer(m_nTimerID_RetryConnect);
        m_nTimerID_RetryConnect = 0;
	}
}

bool MiaWebsocketClient::Connect(const QString& url)
{
    m_url = url;
    if (m_nTimerID_RetryConnect)
    {
        killTimer(m_nTimerID_RetryConnect);
        m_nTimerID_RetryConnect = 0;
    }
	m_webSocket.open(QUrl(url));
	return true;
}

bool MiaWebsocketClient::SendJsonReq(const QString& json)
{
	if (!m_webSocket.isValid())
	{
        //手工调用，也做一次尝试
        if (!m_url.isEmpty())
        {
            if (!m_nTimerID_RetryConnect)
            {
                m_nTimerID_RetryConnect = startTimer(TIMER_TIMEOUT_RETRYCONNECT);
            }
            m_nTimerID_RetryConnect = 0;
        }
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
    if (m_nTimerID_RetryConnect)
    {
        killTimer(m_nTimerID_RetryConnect);
        m_nTimerID_RetryConnect = 0;
        
        m_retry_connet = 0;
    }

	m_nTimerID_Pingpong = startTimer(TIMER_TIMEOUT_PINGPONG);
	emit SignConnect(this);
}

void MiaWebsocketClient::OnWebsocketClosed()
{
    if (m_nTimerID_Pingpong)
    {
        killTimer(m_nTimerID_Pingpong);
        m_nTimerID_Pingpong = 0;
    }
 
    if(!m_nTimerID_RetryConnect)
    {
        m_nTimerID_RetryConnect = startTimer(TIMER_TIMEOUT_RETRYCONNECT);
        m_retry_connet = 0;
    }

    if (m_retry_connet >= 3)
    {
        emit SignClose(this);
    }
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
	if (event->timerId() == m_nTimerID_Pingpong)
	{
		m_webSocket.sendTextMessage("PING");
	}
    else if (event->timerId() == m_nTimerID_RetryConnect)
    {
        if (++m_retry_connet <= 3)
        {
            if (!m_url.isEmpty())
            {
                m_webSocket.close();
                m_webSocket.open(QUrl(m_url));
            }
        }
        else
        {
            killTimer(m_nTimerID_RetryConnect);
            m_nTimerID_RetryConnect = 0;

            m_retry_connet = 0;
        }
    }
}




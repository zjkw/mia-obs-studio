#include "QMyCustLable.h"

QMyCustLabel::QMyCustLabel(QWidget *parent):QLabel(parent)
{

}
#pragma execution_character_set("utf-8")
void QMyCustLabel::setLive(bool bLive/* = false*/)
{
    m_bLive = bLive;
}

void QMyCustLabel::updataHeadImage(QUrl url)
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotReplyPixmapLoad(QNetworkReply*)));
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);
}


void QMyCustLabel::slotReplyPixmapLoad(QNetworkReply* reply)
{
   QByteArray bytes = reply->readAll();
   QPixmap pixmap;
   pixmap.loadFromData(bytes);
   qDebug() << "1111111111111111111111111111111111";

   setPixmap(pixmap);
}


void QMyCustLabel::paintEvent(QPaintEvent * event)
{
    QLabel::paintEvent(event) ;
    QPainter painter(this) ;
    if(m_bLive)
        painter.drawText(QPoint(250,130),"未直播");
    else
        painter.drawText(QPoint(250,130),"直播中");
}

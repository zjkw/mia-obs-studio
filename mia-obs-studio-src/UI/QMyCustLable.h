#ifndef QMYCUSTLABEL_H
#define QMYCUSTLABEL_H
#include<QLabel>
#include<QWidget>
#include<QPainter>
#include<QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkReply>
#include<QUrl>

#include"QMyCustLable.h"

class QMyCustLabel : public QLabel
{
Q_OBJECT
public:
explicit QMyCustLabel(QWidget *parent = 0);
public:
void setLive(bool bLive = false);
void updataHeadImage(QUrl url);
protected:
virtual  void paintEvent(QPaintEvent * event);
signals:
void clicked();
private slots:
    void slotReplyPixmapLoad(QNetworkReply* reply);
private:
    bool m_bLive;
    QNetworkAccessManager* manager;
};


#endif // QMYCUSTLABEL_H

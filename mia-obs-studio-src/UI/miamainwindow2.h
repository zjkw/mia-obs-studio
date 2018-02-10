#pragma once

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QLCDNumber>
#include <QPixmap>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QPagedPaintDevice>
#include <QLabel>
#include<QListWidgetItem>
#include<QVector>
#include<QImage>
#include<QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkReply>
#include<QMap>

//#pragma comment(lib, "Qt5Network.lib")
#include"QMyCustLable.h"

namespace Ui {
class MiaMainWindow2;
}

struct ST_COURSE_ITEM
{
    QString thumbUrl;
    QString courseName;
    QString beginTime;
    QString price;
    QString slaray;
    QString applyNum;
};

class MiaMainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MiaMainWindow2(QWidget *parent = 0);
    ~MiaMainWindow2();

public:
    //UI
    //初始化数据请求前UI
    void initRequestUI();
    //初始化数据请求后UI
    void initReponseUI();

    //Get Image
    QImage* GetScaledImage(QString imagePath,int scaledWidth =  300,int scaledHeight = 200);

    void SetCourseItem(QListWidget*  listWidget,ST_COURSE_ITEM courseItem);
    //local Data
    void GetLocalData(QVector<ST_COURSE_ITEM> &vecCourseItem);

    //server Data
    void OnGetCourseListResult(const QVector<ST_COURSE_ITEM> &vecCourseItem);

private slots:
    void onDoubleClicked(QListWidgetItem* item);
    void onSureClicked();
    void onCancelClicked();
private:
    //Ui::MainWindow *ui;
    QWidget*       requestWidget;  //开始请求数据是的布局组件
     QWidget*      reponseWidget;  //有数据返回时数据是的布局组件  同时要把请求的布局隐藏
    QListWidget*   listWidget;

    //test
    QMap<QMyCustLabel* , QString> maplistHeadImage;

};


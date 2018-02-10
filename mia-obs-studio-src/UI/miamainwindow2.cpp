#include "miamainwindow2.h"
#include<QListWidgetItem>
#include<QWidgetList>
#include<QRect>
#include<QDesktopWidget>
#include<QTableWidget>
#include<QTextCodec>
#include<QDebug>
#include<QMessageBox>
#include "platform.hpp"

MiaMainWindow2::MiaMainWindow2(QWidget *parent) :
    QMainWindow(parent)//,
   // ui(new Ui::MiaMainWindow2)
{
   // ui->setupUi(this);
    initReponseUI();
}

MiaMainWindow2::~MiaMainWindow2()
{
    //delete ui;
}

#pragma execution_character_set("utf-8")

void MiaMainWindow2::initRequestUI()
{
    //组件
   requestWidget = new QWidget();
  // requestWidget->setStyleSheet(" background-color:#FFF0F0F0;");
   this->setCentralWidget(requestWidget);

   //增加一个垂直布局
   //没有用的填充


    QVBoxLayout * vBoxLayout = new QVBoxLayout();
    //图标
    QHBoxLayout * hBoxLayout= new QHBoxLayout();
    QLabel* labelHead = new QLabel();
    labelHead->setFixedSize(121,105);

    std::string path;
    if (GetDataFilePath("mia-img\emptystate.png", path))
    {
	    labelHead->setPixmap(QPixmap(path.c_str()));
    }

    hBoxLayout->addStretch();

    hBoxLayout->addWidget(labelHead);
    hBoxLayout->addStretch();
    // label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QVBoxLayout * vBoxLayoutTip= new QVBoxLayout();
    vBoxLayoutTip->setSpacing(28);   //控件距离28
    QLabel* label2 = new QLabel();
    label2->setText("正在向服务端请求直播课程数据");
    label2->setFixedHeight(20);
    label2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    //label2->setStyleSheet("border:1px solid gray; color:red;");

    QLabel* label3 = new QLabel();
    label3->setText("前往米亚公开课官网创建课程");
    label3->setFixedHeight(20);
    label3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
   // label3->setStyleSheet("border:1px solid gray; color:red;");

    vBoxLayoutTip->addWidget(label2);
    vBoxLayoutTip->addWidget(label3);

    QVBoxLayout * vBoxLayoutMiddle = new QVBoxLayout();
    vBoxLayoutMiddle->setSpacing(18);
    vBoxLayoutMiddle->addLayout(hBoxLayout);
    vBoxLayoutMiddle->addLayout(vBoxLayoutTip);

    QVBoxLayout * vBoxLayoutTop = new QVBoxLayout();
    QLabel* headlabel = new QLabel();
    headlabel->setFixedHeight(128);
    //headlabel->setStyleSheet("border:1px solid gray; color:red;");
    vBoxLayoutTop->addWidget(headlabel);

    vBoxLayoutTop->setSpacing(0);
    vBoxLayout->addLayout(vBoxLayoutTop);
    vBoxLayout->addLayout(vBoxLayoutMiddle);
    vBoxLayout->addStretch();
    requestWidget->setLayout(vBoxLayout);

    requestWidget->setVisible(true);

    reponseWidget->setVisible(false);

}

void MiaMainWindow2::initReponseUI()
{
    // 继承QMiaMainWindow2 创建的窗口它本身具有一个布局层，要想布局适应窗口，随着窗口的大小一起改变 这里不许自己 增加一个布局 并用setCentralWidget 添加到中心布局中
     reponseWidget   = new QWidget();
    // reponseWidget->setStyleSheet(" background-color:#FFF0F0F0;");
     this->setCentralWidget(reponseWidget);

     //list部件
     listWidget = new QListWidget(this);
     listWidget->sizePolicy();
     listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     connect(listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onDoubleClicked(QListWidgetItem*)));

     //增加一个垂直布局
     QVBoxLayout * vBoxLayout = new QVBoxLayout();

     //增加一个水平布局
     QHBoxLayout* hBoxLayoutTop =  new QHBoxLayout();


     QStringList headList;
     headList << "封面" <<"课名" << "开播时间" << "价格" << "课程收入" << "报名人数";

     for(int nIndex = 0;nIndex < headList.size(); nIndex++)
      {
            QLabel* label = new QLabel();
            label->setText(headList[nIndex]);
            if(nIndex == 0)
            {
              label->setFixedWidth(310);
            }

            label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            //label->setStyleSheet("border:1px solid gray; color:red;width:40");
            hBoxLayoutTop->addWidget(label);
      }

     { //这里是为了对齐
         QLabel* label2 = new QLabel();
         label2->setFixedWidth(6);
         hBoxLayoutTop->addWidget(label2);
     }


     //水平布局增加 确定按钮和 取消按钮
     QHBoxLayout * hBoxLayoutBottom = new QHBoxLayout();
     hBoxLayoutBottom->setSpacing(20);  //部件与部件之间的距离
     hBoxLayoutBottom->setAlignment(Qt::AlignRight);  //设置右对齐

     QPushButton* btnSure =  new QPushButton();
     btnSure->setText("确定");
     btnSure->setFixedSize(73,21);
     connect(btnSure, SIGNAL(clicked()), this, SLOT(onSureClicked()));

  //   btnSure->setStyleSheet("border:1px solid gray; color:red;");

     QPushButton* btnCancel =  new QPushButton();
     btnCancel->setText("取消");
     btnCancel->setFixedSize(73,21);
      connect(btnCancel, SIGNAL(clicked()), this, SLOT(onCancelClicked()));
//     btnCancel->setStyleSheet("border:1px solid gray; color:red;");

     hBoxLayoutBottom->addWidget(btnSure);
     hBoxLayoutBottom->addWidget(btnCancel);

     vBoxLayout->addLayout(hBoxLayoutTop);
     vBoxLayout->addWidget(listWidget);
     vBoxLayout->addLayout(hBoxLayoutBottom);

     reponseWidget->setLayout(vBoxLayout);

//   reponseWidget->setStyleSheet("QListWidget{border:1px solid gray; color:black; }"
//                              "QListWidget::Item{padding-top:20px; padding-bottom:20px; }"
//                             "QListWidget::Item:hover{background:skyblue; }"
//                             "QListWidget::item:selected{background:lightgray; color:red; }"
//                             "QListWidget::item:selected:!active{border-width:0px; background:lightgreen; }"
//                             );


    // listwidget->setGeometry(10, 10, this->frameGeometry().size().width(), this->frameGeometry().size().height());
    // listwidget->setGeometry(50,50,600,600);
    //listwidget->setMovement(QListWidget::Free);
    //   listwidget->setStyleSheet("QListWidget{border:1px solid gray; color:black; }"
    //                              "QListWidget::Item{padding-top:20px; padding-bottom:20px; }"
    //                              "QListWidget::Item:hover{background:skyblue; }"
    //                              "QListWidget::item:selected{background:lightgray; color:red; }"
    //                              "QListWidget::item:selected:!active{border-width:0px; background:lightgreen; }"
    //                              );

    //加载
    QVector<ST_COURSE_ITEM> vecCourseItem;
    GetLocalData(vecCourseItem);

    for (int nIndex= 0; nIndex < vecCourseItem.size(); ++nIndex)
    {
        ST_COURSE_ITEM stItem = vecCourseItem.at(nIndex);

        SetCourseItem(listWidget,stItem);
    }

    //更新头像
    QMap<QMyCustLabel*, QString>::const_iterator it;
    for( it=maplistHeadImage.constBegin(); it!=maplistHeadImage.constEnd(); ++it)
    {
        it.key()->updataHeadImage(it.value());
        qDebug() << it.key() <<"        " << it.value();
    }

}


QImage* MiaMainWindow2::GetScaledImage(QString imagePath,int scaledWidth /*=  300*/,int scaledHeight/* = 200*/)
{
    QImage* img=new QImage,*scaledimg=new QImage;//分别保存原图和缩放之后的图片
    if(!(img->load(imagePath)) )//加载图像
    {
        QMessageBox::information(this,tr("打开图像失败"), tr("打开图像失败!"));
        delete img;
        return NULL;
    }
    int oldWidth  =img->width();
    int oldHeight =img->height();

    int fWidth = 0,fHeight = 0;       //缩放后的图片大小
    int Mul = 0;                      //记录图片与label大小的比例，用于缩放图片
    if(oldWidth/scaledWidth >= oldHeight/scaledHeight)
       Mul=oldWidth/scaledWidth;
    else
       Mul=oldHeight/scaledHeight;
    fWidth  =oldWidth/Mul;
    fHeight =oldHeight/Mul;
    *scaledimg=img->scaled(fWidth,fHeight,Qt::KeepAspectRatio);
    return scaledimg;
}

void MiaMainWindow2::SetCourseItem(QListWidget*  listWidget,ST_COURSE_ITEM courseItem)
 {
    QWidget*  widget = new QWidget;
    widget->setToolTip(courseItem.thumbUrl);
    //widget->setStyleSheet("background-color:red;");
    QHBoxLayout*   layout = new QHBoxLayout();


    QMyCustLabel* label0 = new QMyCustLabel();

    label0->setFixedSize(300,150);

    label0->setScaledContents(true);
    QImage* scaledImg = GetScaledImage(courseItem.thumbUrl,300,150);
    if(scaledImg)   label0->setPixmap(QPixmap::fromImage(*scaledImg));
    //label0->setStyleSheet("border:1px solid gray; color:red;");
    //保存要更新的头像对象控件及url
    maplistHeadImage.insert(label0,"http://avatar.csdn.net/6/9/A/1_u011012932.jpg"); //Test
    //https://mia-upload.oss-cn-shanghai.aliyuncs.com/course-default/roombg_6_20.png

    //标签
    QLabel* label = new QLabel();
    label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label->setText(courseItem.courseName);
    //label->setStyleSheet("border:1px solid gray; color:red;");

    QLabel* label2 = new QLabel();
    label2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label2->setText(courseItem.beginTime);
    //label2->setStyleSheet("border:1px solid gray; color:red;");

    QLabel* label3 = new QLabel();
    label3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label3->setText(courseItem.price);
    //label3->setStyleSheet("border:1px solid gray; color:red;");

    QLabel* label4 = new QLabel();
    label4->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label4->setText(courseItem.slaray);
    //label4->setStyleSheet("border:1px solid gray; color:red;");

    QLabel* label5 = new QLabel();
    label5->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label5->setText(courseItem.applyNum);
    //label5->setStyleSheet("border:1px solid gray; color:red;");

    //水平布局添加控件
    layout->addWidget(label0);
    layout->addWidget(label);
    layout->addWidget(label2);
    layout->addWidget(label3);
    layout->addWidget(label4);
    layout->addWidget(label5);

    widget->setLayout(layout);

    QListWidgetItem *widgetItem = new QListWidgetItem(listWidget);
    widgetItem->setText(courseItem.thumbUrl);
    listWidget->addItem(widgetItem);
    listWidget->setItemWidget(widgetItem,widget);
    widgetItem->setSizeHint(QSize(0,150));


 }


void MiaMainWindow2::GetLocalData(QVector<ST_COURSE_ITEM> &vecCourseItem)
{
    for(int nIndex = 2;nIndex < 10;nIndex++)
    {
        ST_COURSE_ITEM item;
        QString thumUrl;
        thumUrl = QString("http://avatar.csdn.net/6/9/A/1_u011012932.jpg");  //QSting  格式化数据使用arg

	//thumUrl = QString
        qDebug() << thumUrl;
        item.thumbUrl   = thumUrl;
        item.courseName = "今日直播";
        item.beginTime  ="长期";
        item.price      ="免费";
        item.slaray     ="收入";
        item.applyNum   ="报名人数";
        vecCourseItem.append(item);
    }
}


void MiaMainWindow2::OnGetCourseListResult(const QVector<ST_COURSE_ITEM> &vecCourseItem)
{
    //加在服务端请求过来的数据
    for (int nIndex= 0; nIndex < vecCourseItem.size(); ++nIndex)
    {
        ST_COURSE_ITEM stItem = vecCourseItem.at(nIndex);

        //SetCourseItem(listWidget,stItem);
    }
}


 void MiaMainWindow2::onDoubleClicked(QListWidgetItem* item)
 {

   qDebug() << item->text();

   QListWidget* pList = item->listWidget();
   QWidget*     widget2 =  pList->itemWidget(item);

   qDebug()<<   widget2->toolTip();

   QLayout *layout = widget2->layout();
   qDebug()<< layout->count();
 }


 void MiaMainWindow2::onSureClicked()
 {
     initRequestUI();
     //QMessageBox::information(this,tr("MiaMainWindow2"), tr("onSuureClicked!"));
 }



 void MiaMainWindow2::onCancelClicked()
 {
  QMessageBox::information(this,tr("MiaMainWindow2"), tr("onCancelClicked!"));
 }



/*

    //按钮添加图片
//    QPushButton* headImage =  new QPushButton();
//    headImage->setFixedSize(150,150);
//    headImage->setMinimumSize(150,150);
//    headImage->setMaximumSize(150,150);
//    headImage->setIcon(courseItem.thumbUrl);
//    headImage->setIconSize(QSize(150,150));
//    headImage->setFlat(true);
    //添加事件
    //connect(headImage, SIGNAL(clicked()), this, SLOT(OnHeadImage()));
*/

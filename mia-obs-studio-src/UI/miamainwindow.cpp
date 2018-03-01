#include <QDateTime>
#include "miamainwindow.h"
#include "miamainlistwidget.h"
#include "miamainlistwidgetitem.h"
#include "miahttpcenter.h"
#include "miapixmap.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>
#include <QPainterPath>
#include <QPixmap>
#include <QString>
#include <QIcon>
#include <QPushButton>
#include <QFont>
#include <QLabel>
#include <QDesktopServices>
#include <QMessageBox>
#include "obs-app.hpp"
#include "singleton.h"

#pragma execution_character_set("utf-8")

CMainWindow::CMainWindow(const QString &coverPath, QWidget *parent)
    : base(parent)
    , m_coverPath(coverPath)
    , m_type(ettNone)
{
    initView();
    initLayout();
    initSlot();
    changeTipType(ettLoading);

    MiaWebsocketClient*	wc = &singleton<MiaWebsocketClient>::instance();
    connect(wc, SIGNAL(SignConnect(MiaWebsocketClient*)), this, SLOT(OnWebSocketConnect(MiaWebsocketClient*)));
    connect(wc, SIGNAL(SignClose(MiaWebsocketClient*)), this, SLOT(OnWebSocketClose(MiaWebsocketClient*)));
    connect(wc, SIGNAL(SignRecvMsg(MiaWebsocketClient*, const QString&)), this, SLOT(OnMiaQueryCourseRes(MiaWebsocketClient*, const QString&)));
}

CMainWindow::~CMainWindow()
{
	MiaWebsocketClient*	wc = &singleton<MiaWebsocketClient>::instance();
	disconnect(wc, SIGNAL(SignConnect(MiaWebsocketClient*)), this, SLOT(OnWebSocketConnect(MiaWebsocketClient*)));
	disconnect(wc, SIGNAL(SignClose(MiaWebsocketClient*)), this, SLOT(OnWebSocketClose(MiaWebsocketClient*)));
	disconnect(wc, SIGNAL(SignRecvMsg(MiaWebsocketClient*, const QString&)), this, SLOT(OnMiaQueryCourseRes(MiaWebsocketClient*, const QString&)));
}

void CMainWindow::insertLive(int id, const QString &cover_url, const QString &name, const QString &time, const QString &type, const QString &teacher)
{
    m_pMainList->insertCourse(id, QPixmap(":/image/images/chooseLesson/emptystate.png"), name, time, type, teacher);
    connect(CHttpCenter::getInstance(), SIGNAL(finish(int,int,QString)), this, SLOT(onHttpFinish(int,int,QString)));
    int key = 0;
    CHttpCenter::getInstance()->download(cover_url, getTempPath(id), key);
    m_download.insert(key, id);
}

void CMainWindow::initView()
{
    setFixedSize(778, 653);
    setWindowFlags(windowFlags() & ~Qt::WindowMinMaxButtonsHint);
    //setFixedSize(670, 800);
    //setMinimumVisible(false);
    //setMaximumVisible(false);

    m_pListPage = new QWidget(this);
    m_pListPage->setVisible(false);
    m_pListPage->setStyleSheet("QWidget{background: transparent;}");
    m_pListPage->setFixedSize(778, 653);

    m_pTipPage = new QWidget(this);
    m_pTipPage->setVisible(true);
    m_pTipPage->setFixedSize(748, 643);
    m_pTipPage->setStyleSheet("QWidget{background: transparent;}");

    m_pMainList = new CMainListWidget(m_pListPage);
    //m_pMainList->setFixedWidth(736);
    m_pConfirm = new QPushButton(this);
    m_pConfirm->setFixedSize(73, 21);
    m_pConfirm->setStyleSheet("QPushButton{font-size:12px;"
                              "font-family: 微软雅黑;"
                              "border: 1px solid #b4b4b4;"
                              "color: #000000;"
                              "background: transparent; }"
                              "QPushButton:hover{border: 1px solid #187ed4; background: transparent;color: #000000; }"
                              "QPushButton:pressed{border: 2px solid #187ed4; background: transparent;color: #000000; }");
    m_pConfirm->setText(Str("Base.Course.EndPoint.OK"));

    m_pCancel = new QPushButton(this);
    m_pCancel->setFixedSize(73, 21);
    m_pCancel->setStyleSheet("QPushButton{font-size:12px;"
                              "font-family: 微软雅黑;"
                              "border: 1px solid #b4b4b4;"
                              "color: #000000;"
                              "background: transparent; }"
                              "QPushButton:hover{border: 1px solid #187ed4; background: transparent;color: #000000; }"
                              "QPushButton:pressed{border: 2px solid #187ed4; background: transparent;color: #000000; }");
    m_pCancel->setText(Str("Base.Course.EndPoint.Cancel"));

    m_pTipIcon = new QLabel(m_pTipPage);
    //m_pTipIcon->setFixedSize(98,87);
    m_pTipIcon->setAlignment(Qt::AlignCenter);
    m_pTipIcon->setPixmap(QPixmap(":/chooseLesson/images/chooseLesson/loading.png"));

    m_pTipTitle = new QLabel(m_pTipPage);
    m_pTipTitle->setAlignment(Qt::AlignCenter);
    m_pTipTitle->setStyleSheet("QLabel{font-size:14px; font-family: 微软雅黑; border: none; color: #696969; background: transparent; }");
    m_pTipTitle->setFixedHeight(25);

    m_pTipSubTitle = new QLabel(m_pTipPage);
    m_pTipSubTitle->setAlignment(Qt::AlignCenter);
    m_pTipSubTitle->setStyleSheet("QLabel{font-size:14px; font-family: 微软雅黑; border: none; color: #2661e7; background: transparent; }");
    m_pTipSubTitle->setFixedHeight(25);
    m_pTipSubTitle->installEventFilter(this);
#if 0
    m_pTipSubTitleLeft = new QLabel(m_pTipPage);
    m_pTipSubTitleLeft->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    m_pTipSubTitleLeft->setStyleSheet("QLabel{font-size:14px; font-family: 微软雅黑; border: none; color: #696969; background: transparent; }");
    m_pTipSubTitleLeft->setFixedHeight(25);

    m_pTipSubTitleRight = new QLabel(m_pTipPage);
    m_pTipSubTitleRight->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    m_pTipSubTitleRight->setStyleSheet("QLabel{font-size:14px; font-family: 微软雅黑; border: none; color: #696969; background: transparent; }");
    m_pTipSubTitleRight->setFixedHeight(25);

    m_pTipSubTitleCenter = new QLabel(m_pTipPage);
    m_pTipSubTitleCenter->setAlignment(Qt::AlignCenter);
    m_pTipSubTitleCenter->setStyleSheet("QLabel{font-size:14px; font-family: 微软雅黑; border: none; color: #2661e7; background: transparent; }");
    m_pTipSubTitleCenter->setFixedHeight(25);
    m_pTipSubTitleCenter->installEventFilter(this);
#endif

    setWindowTitle(Str("Base.Course.UITitle"));

    //setTitleText(Str("Base.Course.UITitle"));
    //setTitleIcon(windowIcon().pixmap(QSize(20, 20)));

    setStyleSheet("QWidget{background-color:#ffffff;}");
}

void CMainWindow::initLayout()
{
    QVBoxLayout *vTipLayout = new QVBoxLayout;
    vTipLayout->addSpacing(150);
    vTipLayout->setAlignment(Qt::AlignHCenter);
    vTipLayout->setContentsMargins(0, 0, 0, 0);
    vTipLayout->setSpacing(0);
    vTipLayout->addWidget(m_pTipIcon);
    vTipLayout->setSpacing(10);
    vTipLayout->addWidget(m_pTipTitle);
    vTipLayout->setSpacing(10);
    vTipLayout->addWidget(m_pTipSubTitle);

    /*
    vTipLayout->addSpacing(150);
    vTipLayout->setAlignment(Qt::AlignHCenter);
    vTipLayout->setContentsMargins(0, 0, 0, 0);
    vTipLayout->setSpacing(0);

    QHBoxLayout *temp = new QHBoxLayout;
    temp->addStretch();
    temp->addWidget(m_pTipIcon);
    temp->addStretch();
    vTipLayout->addLayout(temp);
    vTipLayout->addStretch(10);
    vTipLayout->addWidget(m_pTipTitle);

    QHBoxLayout *hTipLayout = new QHBoxLayout;
    hTipLayout->setAlignment(Qt::AlignHCenter);
    hTipLayout->setContentsMargins(0, 0, 0, 0);
    hTipLayout->setSpacing(0);
    hTipLayout->addStretch();
    hTipLayout->addWidget(m_pTipSubTitleLeft);
    hTipLayout->addSpacing(3);
    hTipLayout->addWidget(m_pTipSubTitleCenter);
    hTipLayout->addSpacing(3);
    hTipLayout->addWidget(m_pTipSubTitleRight);
    hTipLayout->addStretch();

    vTipLayout->addLayout(hTipLayout);*/

    vTipLayout->addStretch(999);

    m_pTipPage->setLayout(vTipLayout);

    QVBoxLayout *vListLayout = new QVBoxLayout;
    vListLayout->setSpacing(0);
    vListLayout->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addStretch();
    hLayout->addWidget(m_pConfirm);
    hLayout->addSpacing(10);
    hLayout->addWidget(m_pCancel);
    hLayout->setContentsMargins(0, 10, 10, 15);
    vListLayout->addWidget(m_pMainList);
    vListLayout->addLayout(hLayout);
    vListLayout->setContentsMargins(25, 15, 25, 0);
    vListLayout->setAlignment(Qt::AlignHCenter);
    m_pListPage->setLayout(vListLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(m_pListPage);
    mainLayout->addWidget(m_pTipPage);

    setLayout(mainLayout);

    /*mainLayout()->setSpacing(0);
    mainLayout()->setContentsMargins(15, 0, 15, 0);
    mainLayout()->addSpacing(10);
    mainLayout()->addWidget(m_pListPage);
    mainLayout()->addWidget(m_pTipPage);*/

    MiaWebsocketClient*	wc = &singleton<MiaWebsocketClient>::instance();
    QString out;
    EncodeMiaWCCourseReq(App()->GetMiaLoginGuid(), App()->GetMiaLoginUid(), App()->GetMiaLoginToken(), wc->UniqueTimeStamp(), out);
    if (!wc->SendJsonReq(out))
    {
        changeTipType(ettError);
    }
}

void CMainWindow::initSlot()
{
    connect(m_pConfirm, SIGNAL(released()), this,SLOT(onConfirm()));
    connect(m_pCancel, SIGNAL(released()), this, SLOT(onCancel()));
}

//void CMainWindow::paintBackground(QPainter &p, QRect &rect)
//{
//    p.fillRect(rect, QBrush(QColor("#0b65ae")));
//    rect.adjust(0, 40, 0, 0);
//    p.fillRect(rect, QBrush(QColor("#f0f0f0")));
//}

#include "window-basic-main.hpp"
#include "qt-wrappers.hpp"
void CMainWindow::onConfirm()
{
    CMainListWidgetItem *item = m_pMainList->curCourse();
    if (!item)
    {
	    return;
    }

    MiaCourseItem miaitem;
    bool bExisted = false;

    for (std::vector<MiaCourseItem>::iterator it = m_CourseList.begin(); it != m_CourseList.end(); it++)
    {
	    if (item->id() == it->coverID.toInt())
	    {
            bExisted = true;
            miaitem = *it;
		    break;
	    }
    }
    bool ret;
    //onClose(ret);
    close();
    if (bExisted)
    {
        changeStream(miaitem);
    }
}

void CMainWindow::changeStream(MiaCourseItem miaItem)
{
    QString rtmp = miaItem.publishUrl.section('/', 0, -2);
    QString key = miaItem.publishUrl.section('/', -1, -1);

    OBSBasic *main = reinterpret_cast<OBSBasic*>(App()->GetMainWindow());

    obs_service_t *oldService = main->GetService();

    if (oldService)
    {
        obs_data_t *settings = obs_service_get_settings(oldService);
        QString s = obs_data_get_string(settings, "server");
        QString k = obs_data_get_string(settings, "key");
        if (rtmp == s && key == k)
        {//课程未发生变更
            return;
        }
        if (!s.isEmpty() && !k.isEmpty() && (rtmp != s || key != k) && main->StreamingActive())
        {//当前正在直播
            if (1 != QMessageBox::information(main, Str("Base.Course.ChangeStream.TipsTitle"), Str("Base.Course.ChangeStream.TipsContent"), Str("Base.Course.ChangeStream.TipsCancel"), Str("Base.Course.ChangeStream.TipsConfirm")))
            {
                return;
            }
        }
    }

    App()->SetMiaCourseName(miaItem.title);
    main->UpdateTitleBar();
    config_set_string(main->Config(), "Course", "Name", miaItem.title.toStdString().c_str());
    config_save_safe(main->Config(), "tmp", nullptr);
    main->SaveProject();

    main->StopStreaming();

    obs_service_t *service = main->GetService();
    obs_data_t *settings = obs_service_get_settings(service);
    obs_data_set_string(settings, "server", rtmp.toStdString().c_str());
    obs_data_set_string(settings, "key", key.toStdString().c_str());

    obs_data_t *hotkeyData = obs_hotkeys_save_service(oldService);

    obs_service_t *newService = obs_service_create(QT_TO_UTF8(QString("rtmp_custom")), "default_service", settings, hotkeyData);

    obs_data_release(hotkeyData);

    main->SetService(newService);
    main->SaveService();
    obs_service_release(newService);
}


void CMainWindow::onCancel()
{
    close();
    /*bool ret;
    onClose(ret);*/
}

void CMainWindow::onHttpFinish(int key, int code, const QString &extend)
{
    if (!m_download.contains(key))
    {
        return ;
    }
    int id = m_download[key];
    m_download.remove(key);
    if (200 == code)
    {
        m_pMainList->course(id)->updateCover(CPixmap(extend));
    }
}

void CMainWindow::changeTipType(TipType type)
{
    if (type == m_type)
    {
	return ;
    }
    m_type = type;
    if (ettList != m_type)
    {
	m_pListPage->setVisible(false);
	m_pTipPage->setVisible(true);
    }
    else
    {
	m_pTipPage->setVisible(false);
        m_pListPage->setVisible(true);
    }
    if (ettLoading == m_type)
    {
        m_pTipTitle->setText(Str("Base.Course.Note.Loading"));
        m_pTipSubTitle->setText("");
        m_pTipIcon->setPixmap(QPixmap(":/chooseLesson/images/chooseLesson/loading.png"));

	/*m_pTipTitle->setText(Str("Base.Course.Note.FetchingList"));
	m_pTipSubTitleLeft->setText(Str("Base.Course.Note.ClickUrl"));
	m_pTipSubTitleCenter->setText(Str("Base.Course.Note.MiaLesson"));
	m_pTipSubTitleRight->setText(Str("Base.Course.Note.CreateLesson"));*/
    }
    else if (ettError == m_type)
    {
        m_pTipTitle->setText(Str("Base.Course.Note.NetError"));
        m_pTipSubTitle->setText(Str("Base.Course.Note.FetchPage"));
        m_pTipIcon->setPixmap(QPixmap(":/chooseLesson/images/chooseLesson/refresh.png"));
	/*m_pTipTitle->setText(Str("Base.Course.Note.FetchingFail"));
	m_pTipSubTitleLeft->setText(Str("Base.Course.Note.CheckNetwork"));
	m_pTipSubTitleCenter->setText(Str("Base.Course.Note.ClickRetry"));
	m_pTipSubTitleRight->setText(Str("Base.Course.Note.FetchLesson"));*/
    }
    else if (ettEmpty == m_type)
    {
	/*m_pTipTitle->setText(Str("Base.Course.Note.NoLesson"));
	m_pTipSubTitleLeft->setText(Str("Base.Course.Note.ClickUrl"));
	m_pTipSubTitleCenter->setText(Str("Base.Course.Note.MiaLesson"));
	m_pTipSubTitleRight->setText(Str("Base.Course.Note.CreateLesson"));*/
    }
}

QString CMainWindow::getTempPath(int id)
{
	return QString("%1/%2_%3.png").arg(m_coverPath).arg(id).arg(QDateTime::currentDateTime().toTime_t());
}

bool CMainWindow::eventFilter(QObject * watched, QEvent * evt)
{
	if (m_pTipSubTitle == watched)
	{
		if (evt->type() == QEvent::Enter)
		{
			setCursor(Qt::PointingHandCursor);
		}
		else if (evt->type() == QEvent::Leave)
		{
			setCursor(Qt::ArrowCursor);
		}
		else if (evt->type() == QEvent::MouseButtonPress)
		{
			onClickUrl();
			return true;
		}
	}
	return base::eventFilter(watched, evt);
}

void CMainWindow::closeEvent(QCloseEvent * event)
{
    emit closed();
}

void CMainWindow::onClickUrl()
{
	if (ettEmpty == m_type)
	{
		//课程列表为空
	}
	else if (ettError == m_type)
	{
		//获取课程列表失败
        MiaWebsocketClient*	wc = &singleton<MiaWebsocketClient>::instance();
        QString out;
        EncodeMiaWCCourseReq(App()->GetMiaLoginGuid(), App()->GetMiaLoginUid(), App()->GetMiaLoginToken(), wc->UniqueTimeStamp(), out);
        if (!wc->SendJsonReq(out))
        {
            changeTipType(ettError);
        }
        else
        {
            changeTipType(ettLoading);
        }
        return;
	}
	else if (ettLoading == m_type)
	{
		//正在获取课程列表
	}
	//const QUrl url("https://pc.miamusic.com/backend/#/");
	//QDesktopServices::openUrl(url);
}

bool CMainWindow::EncodeMiaWCCommonHead(json_t* root, const QString& guid, const QString& cmd, const QString& stamp)
{
	json_object_set_new(root, "g", json_string(guid.toUtf8()));
	json_object_set_new(root, "c", json_string(cmd.toUtf8()));

	json_object_set_new(root, "r", json_string(QString("1").toUtf8()));
	json_object_set_new(root, "a", json_string(QString("6").toUtf8()));
	json_object_set_new(root, "s", json_string(stamp.toUtf8()));
	json_object_set_new(root, "b", json_string(QString("1.0.0.1").toUtf8()));

	return true;
}

bool CMainWindow::EncodeMiaWCCourseReq(const QString& guid, const QString& uid, const QString& token, const QString& stamp, QString& out)
{
	json_t* root = json_object();

	EncodeMiaWCCommonHead(root, guid, "Course.Get.Coming", stamp);

	json_t* value = json_object();
	json_object_set_new(root, "v", value);
	//json_decref(value);

	char* data1 = json_dumps(root, JSON_INDENT(0));
	out = QString::fromUtf8(data1);
	free(data1);
	json_decref(root);

	return true;
}

bool CMainWindow::DecodeMiaWCCourseRes(const QString& json, bool& bSuc, std::vector<MiaCourseItem>& CourseList)
{
	bSuc = false;
	CourseList.clear();

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
		if (cmd.compare("Course.Get.Coming", Qt::CaseInsensitive))
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

		json_t* jData = json_object_get(jValue, "data");
		if (!json_is_array(jData))
		{
			break;
		}

		json_t *jCourseItem;
		size_t index;
		json_array_foreach(jData, index, jCourseItem)
		{
			if (!json_is_object(jCourseItem))
			{
				continue;
			}

			MiaCourseItem item;

			json_t* jcoverID = json_object_get(jCourseItem, "roomID"); //warn
			if (!json_is_string(jcoverID))
			{
				continue;
			}
			item.coverID = json_string_value(jcoverID);

			json_t* jpublishUrl = json_object_get(jCourseItem, "publishUrl");
			if (!json_is_string(jpublishUrl))
			{
				continue;
			}
			item.publishUrl = json_string_value(jpublishUrl);

			json_t* jtitle = json_object_get(jCourseItem, "title");
			if (!json_is_string(jtitle))
			{
				continue;
			}
			item.title = json_string_value(jtitle);

			json_t* jcoverUrl = json_object_get(jCourseItem, "coverUrl");
			if (!json_is_string(jcoverUrl))
			{
				continue;
			}
			item.coverUrl = json_string_value(jcoverUrl);

			json_t* jstartTime = json_object_get(jCourseItem, "startTime");
			if (!json_is_string(jstartTime))
			{
				continue;
			}
			item.startTime = json_string_value(jstartTime);
			 
			json_t* jliveType = json_object_get(jCourseItem, "liveType");
			if (!json_is_string(jliveType))
			{
				continue;
			}
			item.liveType = json_string_value(jliveType);

			json_t* jteacher = json_object_get(jCourseItem, "teacher");
			if (json_is_string(jteacher))
			{
				item.teacherList = json_string_value(jteacher);
			}

			CourseList.push_back(item);
		}
	} while (0);

	json_decref(jroot);

	return bSuc;
}

void CMainWindow::OnWebSocketConnect(MiaWebsocketClient* wc)
{

}

void CMainWindow::OnWebSocketClose(MiaWebsocketClient* wc)
{
	//QMessageBox::information(this, "warning", QString("net broken, please reopen app"));
    changeTipType(ettError);
}

static QString GetTypeName(const QString& type)
{
  //  return type;//
	if (!type.compare("1"))
	{
		return Str("Base.Course.Lesson.VideoLive");
	}
//	else if (!type.compare("2"))
//	{
//		return Str("Base.Course.Lesson.VideoRecord");
//	}
	else if (!type.compare("3"))
	{
		return Str("Base.Course.Lesson.AudioLive");
	}
	else
	{
		return Str("Base.Course.Lesson.UnknownType");
	}
}

void CMainWindow::OnMiaQueryCourseRes(MiaWebsocketClient* wc, const QString& json)
{
	//验证cmd
	bool bSuc = false;
	m_CourseList.clear();
	if (!DecodeMiaWCCourseRes(json, bSuc, m_CourseList) || !bSuc)
	{
		changeTipType(ettError);
		return;
	}

	for (std::vector<MiaCourseItem>::iterator it = m_CourseList.begin(); it != m_CourseList.end(); it++)
	{
        QString startTime;
        if (it->startTime.toInt() > 0)
        {
            startTime = QDateTime::fromTime_t(it->startTime.toInt()).toString("yyyy-MM-dd\nhh:mm:ss");
        }
        else
        {
            startTime = Str("Base.Course.Lesson.AlwayUseful");
        }
		insertLive(it->coverID.toInt(), it->coverUrl, it->title, startTime, GetTypeName(it->liveType), it->teacherList);
	}
	changeTipType(m_CourseList.empty() ? ettEmpty : ettList);
}


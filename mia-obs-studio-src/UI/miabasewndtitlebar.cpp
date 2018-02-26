#include "miabasewndtitlebar.h"
#include "miabasewndtitlebarprivate.h"
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QEvent>
#include <QMouseEvent>

CBaseWndTitleBar::CBaseWndTitleBar(QWidget *parent):
    QWidget(parent),
    d_ptr(new CBaseWndTitleBarPrivate(this)),
    m_bMoving(false)
{
    initView();
    initLayout();
    initSlots();
}

CBaseWndTitleBar::~CBaseWndTitleBar()
{

}

void CBaseWndTitleBar::setMinimumVisible(bool visible)
{
    Q_D(CBaseWndTitleBar);
    d->m_pMinimum->setVisible(visible);
}

void CBaseWndTitleBar::setMaximumVisible(bool visible)
{
    Q_D(CBaseWndTitleBar);
    d->m_pMaximum->setVisible(visible);
}

void CBaseWndTitleBar::setCloseVisible(bool visible)
{
    Q_D(CBaseWndTitleBar);
    d->m_pClose->setVisible(visible);
}

void CBaseWndTitleBar::setMinimumEnable(bool enable)
{
    Q_D(CBaseWndTitleBar);
    d->m_pMinimum->setEnabled(enable);
}

void CBaseWndTitleBar::setMaximumEnable(bool enable)
{
    Q_D(CBaseWndTitleBar);
    d->m_pMaximum->setEnabled(enable);
}

void CBaseWndTitleBar::setCloseEnable(bool enable)
{
    Q_D(CBaseWndTitleBar);
    d->m_pClose->setEnabled(enable);
}

void CBaseWndTitleBar::setTitleIcon(const QPixmap &pixmap)
{
    Q_D(CBaseWndTitleBar);
    d->m_pIcon->setPixmap(pixmap);
}

void CBaseWndTitleBar::setTitleText(const QString &text)
{
    Q_D(CBaseWndTitleBar);
    d->m_pTitle->setText(text);
}

bool CBaseWndTitleBar::isMinimumVisible()
{
    Q_D(CBaseWndTitleBar);
    return d->m_pMinimum->isVisible();
}

bool CBaseWndTitleBar::isMaximumVisible()
{
    Q_D(CBaseWndTitleBar);
    return d->m_pMaximum->isVisible();
}

bool CBaseWndTitleBar::isCloseVisible()
{
    Q_D(CBaseWndTitleBar);
    return d->m_pClose->isVisible();
}

bool CBaseWndTitleBar::isMinimumEnable()
{
    Q_D(CBaseWndTitleBar);
    return d->m_pMinimum->isEnabled();
}

bool CBaseWndTitleBar::isMaximumEnable()
{
    Q_D(CBaseWndTitleBar);
    return d->m_pMaximum->isEnabled();
}

bool CBaseWndTitleBar::isCloseEnable()
{
    Q_D(CBaseWndTitleBar);
    return d->m_pClose->isEnabled();
}

QString CBaseWndTitleBar::titleText()
{
    Q_D(CBaseWndTitleBar);
    return d->m_pTitle->text();
}

void CBaseWndTitleBar::initView()
{
    Q_D(CBaseWndTitleBar);
    d->m_pIcon = new QLabel(this);
    d->m_pIcon->setFixedSize(25, 25);
    d->m_pIcon->setStyleSheet("QWidget{background-color: #0b65ae;}");
    d->m_pTitle = new QLabel(this);
    d->m_pTitle->setFixedHeight(25);
    d->m_pTitle->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);

    QFont font("微软雅黑");
    font.setPixelSize(14);
    d->m_pTitle->setFont(font);
    d->m_pTitle->setStyleSheet("QWidget{background-color: #0b65ae;}");
    d->m_pMinimum = new QPushButton(this);
    d->m_pMinimum->setFixedSize(29, 22);
    d->m_pMaximum = new QPushButton(this);
    d->m_pMaximum->setFixedSize(29, 22);
    d->m_pClose = new QPushButton(this);
    d->m_pClose->setFixedSize(29, 22);

    QString styleSheetFmt = QString("QPushButton{background:url(%1); background-color:transparent;border: none; }"
                                    "QPushButton:hover{background:url(%2); background-color:transparent; }"
                                    "QPushButton:pressed{background:url(%3); background-color:transparent; }");
    d->m_pMinimum->setStyleSheet(QString(styleSheetFmt).arg(":/chooseLesson/images/chooseLesson/man_min_default.png")
                                 .arg(":/chooseLesson/images/chooseLesson/man_min_enter.png")
                                 .arg(":/chooseLesson/images/chooseLesson/man_min_down.png"));

    d->m_pMaximum->setStyleSheet(QString(styleSheetFmt).arg(":/chooseLesson/images/chooseLesson/man_max_default.png")
                                 .arg(":/chooseLesson/images/chooseLesson/man_max_enter.png")
                                 .arg(":/chooseLesson/images/chooseLesson/man_max_down.png"));

    d->m_pClose->setStyleSheet(QString(styleSheetFmt).arg(":/chooseLesson/images/chooseLesson/man_Close_default.png")
                                 .arg(":/chooseLesson/images/chooseLesson/man_Close_enter.png")
                                 .arg(":/chooseLesson/images/chooseLesson/man_Close_down.png"));
				 
    d->m_pTitle->installEventFilter(this);
    this->installEventFilter(this);
    setFixedHeight(30);
}

void CBaseWndTitleBar::initLayout()
{
    Q_D(CBaseWndTitleBar);
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(d->m_pIcon);

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->setContentsMargins(0, 0, 0, 0);
    vLayout->addSpacing(8);
    vLayout->addWidget(d->m_pTitle);
    vLayout->addStretch();
    hLayout->addLayout(vLayout);;
    hLayout->addStretch();
    hLayout->addWidget(d->m_pMinimum);
    hLayout->addWidget(d->m_pMaximum);
    hLayout->addWidget(d->m_pClose);
    hLayout->setContentsMargins(0, 0, 0, 0);
    hLayout->setSpacing(0);
    setLayout(hLayout);
}

void CBaseWndTitleBar::initSlots()
{
    Q_D(CBaseWndTitleBar);
    connect(d->m_pMinimum, SIGNAL(clicked(bool)), this, SLOT(onClickMinimum(bool)));
    connect(d->m_pMaximum, SIGNAL(clicked(bool)), this, SLOT(onClickMaximum(bool)));
    connect(d->m_pClose, SIGNAL(clicked(bool)), this, SLOT(onClickClose(bool)));
}

void CBaseWndTitleBar::onClickMinimum(bool)
{
    bool ret = false;
    emit onMinimum(ret);
}

void CBaseWndTitleBar::onClickMaximum(bool)
{
    bool ret = false;
    emit onMaximum(ret);
}

void CBaseWndTitleBar::onClickClose(bool)
{
    bool ret = false;
    emit onClose(ret);
}

bool CBaseWndTitleBar::eventFilter(QObject *target, QEvent *event)
{
    Q_D(CBaseWndTitleBar);
    QWidget *pParentWidget = window();
    if (pParentWidget)
    {
        if ((target == d->m_pTitle || target == target) && event->type() == QEvent::MouseButtonPress)
        {
            m_bMoving = true;
            QMouseEvent *mouseEvent = (QMouseEvent *)event;
            m_movePos = mouseEvent->globalPos();
            return true;
        }

        if ((target == d->m_pTitle || target == target) && event->type() == QEvent::MouseMove)
        {
            if(m_bMoving && isVisible())
            {
                QMouseEvent *mouseEvent = (QMouseEvent *)event;
                QPoint pos = mouseEvent->globalPos() - m_movePos;
                pParentWidget->move(pParentWidget->pos() + pos);
                m_movePos = mouseEvent->globalPos();
            }
            return true;
        }

        if ((target == d->m_pTitle || target == target) && event->type() == QEvent::MouseButtonRelease)
        {
            m_bMoving = false;
            m_movePos = QPoint(0, 0);
            return true;
        }

        if ((target == d->m_pTitle || target == target) && event->type() == QEvent::MouseButtonDblClick && d->m_pMaximum->isVisible())
        {
            onClickMaximum(true);
            return true;
        }
    }
    return QWidget::eventFilter(target, event);
}

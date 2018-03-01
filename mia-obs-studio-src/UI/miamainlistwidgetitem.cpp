#include "miamainlistwidgetitem.h"
#include "miamainlistwidgetitemprivate.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

CMainListWidgetItem::CMainListWidgetItem(QWidget *parent):
    QWidget(parent),
    d_ptr(new CMainListWidgetItemPrivate(this))
{
    initView();
    initLayout();
    initSlots();
}

CMainListWidgetItem::~CMainListWidgetItem()
{

}

void CMainListWidgetItem::init(int id, const QPixmap &pixmap, const QString &name, const QString &time, const QString &type, const QString &teacher)
{
    Q_D(CMainListWidgetItem);
    d->m_id = id;
    d->m_pCover->setPixmap(pixmap.scaled(d->m_pCover->size(), Qt::KeepAspectRatio));
    if (name.length() > 17)
    {
        d->m_pName->setText(name.left(17) + "...");
    }
    else
    {
        d->m_pName->setText(name);
    }
    d->m_pTime->setText(time);
    if (type.length() > 15)
    {
        d->m_pType->setText(type.left(15) + "...");
    }
    else
    {
        d->m_pType->setText(type);
    }
    if (teacher.length() > 13)
    {
        d->m_pTeacher->setText(teacher.left(13) + "...");
    }
    else
    {
        d->m_pTeacher->setText(teacher);
    }
    d->m_live = false;
    d->m_selected = false;
}

void CMainListWidgetItem::selectItem(bool selected)
{
    Q_D(CMainListWidgetItem);
    if (selected)
    {
        d->m_pStatus->setPixmap(QPixmap(":/chooseLesson/images/chooseLesson/success.png").scaled(d->m_pStatus->size(), Qt::KeepAspectRatio));
    }
    else
    {
        d->m_pStatus->setPixmap(QPixmap());
    }
}

void CMainListWidgetItem::updateLiveState(bool live)
{
    Q_D(CMainListWidgetItem);
    d->m_pLive->setText(live ? "Live" : "Rest");
}

void CMainListWidgetItem::updateCover(const QPixmap &pixmap)
{
    Q_D(CMainListWidgetItem);
    d->m_pCover->setPixmap(pixmap.scaled(d->m_pCover->size()));
}

void CMainListWidgetItem::updateName(const QString &name)
{
    Q_D(CMainListWidgetItem);
    d->m_pName->setText(name);
}

void CMainListWidgetItem::updateTime(const QString &time)
{
    Q_D(CMainListWidgetItem);
    d->m_pTime->setText(time);
}

void CMainListWidgetItem::updateType(const QString &type)
{
    Q_D(CMainListWidgetItem);
    d->m_pType->setText(type);
}

void CMainListWidgetItem::updateTeacher(const QString &teacher)
{
    Q_D(CMainListWidgetItem);
    d->m_pTeacher->setText(teacher);
}

int CMainListWidgetItem::id()
{
    Q_D(CMainListWidgetItem);
    return d->m_id;
}

void CMainListWidgetItem::initView()
{
    QFont font("微软雅黑");
    font.setPixelSize(12);
    Q_D(CMainListWidgetItem);
    d->m_pCover = new QLabel(this);
    d->m_pCover->setFixedSize(90, 51);
    d->m_pCover->setAlignment(Qt::AlignCenter);
    d->m_pCover->setFont(font);
    d->m_pCover->setStyleSheet("background-color:#777777");
    d->m_pLive = new QLabel(d->m_pCover);
    d->m_pLive->setFixedSize(59, 23);
    d->m_pLive->setAlignment(Qt::AlignCenter);
    d->m_pLive->setStyleSheet("QLabel{color:#ffffff; background: transparent; background-color:#6c6d6a15;font-size:12px; font-family:'微软雅黑';}");
    d->m_pLive->setText("Live");

    d->m_pName = new QLabel(this);
    d->m_pName->setFixedSize(102, 40);
    d->m_pName->setAlignment(Qt::AlignCenter);
    d->m_pName->setWordWrap(true);
    d->m_pName->setFont(font);
    d->m_pName->setStyleSheet("QLabel{background: transparent;color:#333000; font-size:14px; font-family:'微软雅黑';}");

    d->m_pTime = new QLabel(this);
    d->m_pTime->setFixedSize(77, 40);
    d->m_pTime->setAlignment(Qt::AlignCenter);
    d->m_pTime->setWordWrap(true);
    d->m_pTime->setFont(font);
    d->m_pTime->setStyleSheet("QLabel{background: transparent;color:#333000; font-size:14px; font-family:'微软雅黑';}");

    d->m_pType = new QLabel(this);
    d->m_pType->setFixedSize(97, 40);
    d->m_pType->setAlignment(Qt::AlignCenter);
    d->m_pType->setWordWrap(true);
    d->m_pType->setFont(font);
    d->m_pType->setStyleSheet("QLabel{background: transparent;color:#333000; font-size:14px; font-family:'微软雅黑';}");

    d->m_pTeacher = new QLabel(this);
    d->m_pTeacher->setFixedSize(82, 40);
    d->m_pTeacher->setAlignment(Qt::AlignCenter);
    d->m_pTeacher->setFont(font);
    d->m_pTeacher->setWordWrap(true);
    d->m_pTeacher->setStyleSheet("QLabel{background: transparent;color:#333000; font-size:14px; font-family:'微软雅黑';}");

    d->m_pStatus = new QLabel(this);
    d->m_pStatus->setFixedSize(25, 25);
    d->m_pStatus->setAlignment(Qt::AlignCenter);
    d->m_pStatus->setStyleSheet("QLabel{background: transparent;color:#333000; font-size:14px; font-family:'微软雅黑';}");

    d->m_pBottomBorder = new QLabel(this);
    d->m_pBottomBorder->setFixedHeight(1);
    d->m_pBottomBorder->setStyleSheet("QLabel{background-color: #e9e9e9;}");
    setFixedHeight(80);

    d->m_live = false;
    d->m_selected = false;

    //setStyleSheet("QWidget{background-color:#ffffff;}");
}

void CMainListWidgetItem::initLayout()
{
    Q_D(CMainListWidgetItem);
    QHBoxLayout *hLayout = new QHBoxLayout;
    QHBoxLayout *temp = new QHBoxLayout;
    hLayout->addSpacing(36);
    hLayout->addWidget(d->m_pCover);
    temp->setAlignment(Qt::AlignRight | Qt::AlignBottom);
    temp->setContentsMargins(0, 0, 0, 0);
    temp->addWidget(d->m_pLive);
    d->m_pCover->setLayout(temp);
    hLayout->addSpacing(44);
    hLayout->addWidget(d->m_pName);
    hLayout->addSpacing(44);
    hLayout->addWidget(d->m_pTime);
    hLayout->addSpacing(44);
    hLayout->addWidget(d->m_pType);
    hLayout->addSpacing(34);
    hLayout->addWidget(d->m_pTeacher);
    hLayout->addSpacing(22);
    hLayout->addWidget(d->m_pStatus);
    hLayout->addSpacing(10);
    hLayout->setContentsMargins(0, 0, 0, 0);
    hLayout->setSpacing(0);
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->setContentsMargins(0, 0, 0, 0);
    vLayout->addStretch(14);
    vLayout->addLayout(hLayout);
    vLayout->addStretch(14);
    vLayout->addWidget(d->m_pBottomBorder);
    vLayout->setSpacing(0);
    vLayout->setAlignment(Qt::AlignBottom);
    setLayout(vLayout);
}

void CMainListWidgetItem::initSlots()
{

}

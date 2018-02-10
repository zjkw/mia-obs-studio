#include "miamainlistwidgetheader.h"
#include <QLabel>
#include <QHBoxLayout>

CMainListWidgetHeader::CMainListWidgetHeader(QWidget *parent):
    QWidget(parent)
{
    initView();
    initLayout();
}

CMainListWidgetHeader::~CMainListWidgetHeader()
{

}

void CMainListWidgetHeader::init(const QString &cover, const QString &name, const QString &time, const QString &type, const QString &teacher)
{
    m_pCover->setText(cover);
    m_pCover->setStyleSheet("QLabel{background: #f4f7f9; color:#333000; font-size:14px; font-family:'微软雅黑'; border:none; border-left:1px solid #cdd1d3;border-top:1px solid #cdd1d3;}");
    m_pName->setText(name);
    m_pName->setStyleSheet("QLabel{background: #f4f7f9; color:#333000; font-size:14px; font-family:'微软雅黑'; border:none; border-top:1px solid #cdd1d3;}");
    m_pTime->setText(time);
    m_pTime->setStyleSheet("QLabel{background: #f4f7f9; color:#333000; font-size:14px; font-family:'微软雅黑'; border:none; border-top:1px solid #cdd1d3;}");
    m_pType->setText(type);
    m_pType->setStyleSheet("QLabel{background: #f4f7f9; color:#333000; font-size:14px; font-family:'微软雅黑'; border:none; border-top:1px solid #cdd1d3;}");
    m_pTeacher->setText(teacher);
    m_pTeacher->setStyleSheet("QLabel{background: #f4f7f9; color:#333000; font-size:14px; font-family:'微软雅黑'; border:none; border-right:1px solid #cdd1d3;border-top:1px solid #cdd1d3;}");
}

void CMainListWidgetHeader::initView()
{
    m_pCover = new QLabel(this);
    m_pCover->setAlignment(Qt::AlignCenter);
    m_pName = new QLabel(this);
    m_pName->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    m_pTime = new QLabel(this);
    m_pTime->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    m_pType = new QLabel(this);
    m_pType->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    m_pTeacher = new QLabel(this);
    m_pTeacher->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    setFixedHeight(42);
}

void CMainListWidgetHeader::initLayout()
{
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(m_pCover);
    hLayout->addWidget(m_pName);
    hLayout->addWidget(m_pTime);
    hLayout->addWidget(m_pType);
    hLayout->addWidget(m_pTeacher);
    hLayout->setSpacing(0);
    hLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(hLayout);
}

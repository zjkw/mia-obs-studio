#include "miamainlistwidget.h"
#include "miamainlistwidgetitem.h"
#include "miamainlistwidgetprivate.h"
#include "miamainlistwidgetheader.h"
#include <QListWidget>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include <QScrollBar>
#include "obs-app.hpp"

CMainListWidget::CMainListWidget(QWidget *parent):
    QWidget(parent),
    d_ptr(new CMainListWidgetPrivate(this))
{
    initView();
    initLayout();
    initSlots();
}

CMainListWidget::~CMainListWidget()
{

}

void CMainListWidget::insertCourse(int id, const QPixmap &pixmap, const QString &name, const QString &time, const QString &type, const QString &teacher)
{
    Q_D(CMainListWidget);

    if (d->m_mapItems.contains(id))
    {
        return ;
    }
    CMainListWidgetPrivate::ItemData data;
    data.item = new QListWidgetItem(d->m_pList);
    data.widget = new CMainListWidgetItem(this);
    QSize size = data.item->sizeHint();
    size.setHeight(data.widget->height());
    data.item->setSizeHint(size);
    data.item->background();
    d->m_pList->setItemWidget(data.item, data.widget);
    d->m_pList->addItem(data.item);
    data.widget->init(id, pixmap, name, time, type, teacher);
    d->m_items.push_back(data.widget);
    d->m_mapItems.insert(id, data);

}

void CMainListWidget::removeCourse(int id)
{
    Q_D(CMainListWidget);
    QMap<int, CMainListWidgetPrivate::ItemData>::iterator iter = d->m_mapItems.find(id);
    if (iter != d->m_mapItems.end())
    {
        for (QList<CMainListWidgetItem*>::iterator it = d->m_items.begin(); it != d->m_items.end(); ++it)
        {
            if (*it == iter.value().widget)
            {
                d->m_items.erase(it);
                break;
            }
        }
        d->m_pList->removeItemWidget(iter.value().item);
        d->m_mapItems.erase(iter);
    }
}

CMainListWidgetItem* CMainListWidget::course(int id)
{
    Q_D(CMainListWidget);
    QMap<int, CMainListWidgetPrivate::ItemData>::iterator iter = d->m_mapItems.find(id);
    if (iter != d->m_mapItems.end())
    {
        return iter.value().widget;
    }
    return nullptr;
}

CMainListWidgetItem* CMainListWidget::curCourse()
{
    Q_D(CMainListWidget);
    return course(d->m_current);
}

void CMainListWidget::initView()
{
    Q_D(CMainListWidget);

    d->m_pHeader = new CMainListWidgetHeader(this);
    d->m_pHeader->init(Str("Base.Course.Head.Cover"), Str("Base.Course.Head.Name"), Str("Base.Course.Head.StartTime"), Str("Base.Course.Head.Type"), Str("Base.Course.Head.Teacher"));
    d->m_pList = new QListWidget(this);
    d->m_pList->setViewMode(QListView::ListMode);
    //d->m_pList->setSelectionMode(QAbstractItemView::NoSelection);
    //d->m_pList->setFocusPolicy(Qt::NoFocus);

    QString styleSheet("QScrollBar:vertical{background-color:#F7F7F7;    border:0px solid #C6C6C6;	padding-top:2px;    padding-bottom:2px;	width: 10px;}"
                       "QScrollBar::handle:vertical{	background:rgba(0,0,0,25%);    background-color:#CECECE;     width: 7px;    border:1px solid #B7B7B7;     border-radius:3.5px;	margin: 2px 1px 2px 1px;	min-height: 20px;}"
                       "QScrollBar::handle:vertical:hover{	background:rgba(0,0,0,25%);    background-color:#C0C0C0;    width: 7px;    border:1px solid #A4A3A3;    border-radius:3.5px;	margin: 2px 1px 2px 1px;}"
                       "QScrollBar::handle:vertical:pressed{	background:rgba(0,0,0,25%);    background-color:#A6A6A6;    width: 7px;    border:1px solid #7D7D7D;    border-radius:3.5px;	margin: 2px 1px 2px 1px;}"
                       "QScrollBar::add-line:vertical{    background:transparent;	width: 0px;}"
                       "QScrollBar::sub-line:vertical{    background:transparent;	width: 0px;}");

    d->m_pList->verticalScrollBar()->setStyleSheet(styleSheet);
    d->m_pList->setStyleSheet("QListWidget{border: none; border-left: 1px solid #cdd1d3; border-bottom: 1px solid #cdd1d3; border-right: 1px solid #cdd1d3;}");
}

void CMainListWidget::initLayout()
{
    Q_D(CMainListWidget);
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(d->m_pHeader);
    vLayout->addWidget(d->m_pList);
    vLayout->setSpacing(0);
    vLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(vLayout);
}

void CMainListWidget::initSlots()
{
    Q_D(CMainListWidget);
    connect(d->m_pList, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), this, SLOT(onCurrentItemChanged(QListWidgetItem*,QListWidgetItem*)));
}

void CMainListWidget::onCurrentItemChanged(QListWidgetItem *current ,QListWidgetItem *previous)
{
    Q_D(CMainListWidget);
    for (QMap<int, CMainListWidgetPrivate::ItemData>::iterator iter = d->m_mapItems.begin(); iter != d->m_mapItems.end(); ++iter)
    {
        if (iter.value().item == previous)
        {
            iter.value().widget->selectItem(false);
        }
        else if (iter.value().item == current)
        {
            iter.value().widget->selectItem(true);
            d->m_current = iter.value().widget->id();
        }
    }
}

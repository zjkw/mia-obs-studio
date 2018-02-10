#ifndef MAINLISTWIDGETPRIVATE_H
#define MAINLISTWIDGETPRIVATE_H
#include <qglobal.h>
#include <QList>
#include <QMap>

class QListWidget;
class CMainListWidget;
class CMainListWidgetItem;
class CMainListWidgetHeader;
class QListWidgetItem;
class CMainListWidgetPrivate
{
    struct ItemData
    {
        QListWidgetItem *item;
        CMainListWidgetItem *widget;
    };
    Q_DECLARE_PUBLIC(CMainListWidget)
public:
    CMainListWidgetPrivate(CMainListWidget *qp);
    ~CMainListWidgetPrivate();
protected:
    CMainListWidget *q_ptr;
    QList<CMainListWidgetItem*> m_items;
    QMap<int, ItemData> m_mapItems;
    QListWidget *m_pList;
    CMainListWidgetHeader *m_pHeader;
    int m_current;
};

#endif // MAINLISTWIDGETPRIVATE_H

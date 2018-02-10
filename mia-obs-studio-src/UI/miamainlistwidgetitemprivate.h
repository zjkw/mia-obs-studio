#ifndef MAINLISTWIDGETITEMPRIVATE_H
#define MAINLISTWIDGETITEMPRIVATE_H
#include <qglobal.h>
class QLabel;
class CMainListWidgetItem;
class CMainListWidgetItemPrivate
{
    Q_DECLARE_PUBLIC(CMainListWidgetItem)
public:
    CMainListWidgetItemPrivate(CMainListWidgetItem *qp);
    ~CMainListWidgetItemPrivate();
private:
    CMainListWidgetItem *q_ptr;

    QLabel *m_pCover;
    QLabel *m_pLive;
    QLabel *m_pName;
    QLabel *m_pTime;
    QLabel *m_pType;
    QLabel *m_pTeacher;
    QLabel *m_pStatus;
    QLabel *m_pBottomBorder;
    int m_id;
    bool m_selected;
    bool m_live;
};

#endif // MAINLISTWIDGETITEMPRIVATE_H

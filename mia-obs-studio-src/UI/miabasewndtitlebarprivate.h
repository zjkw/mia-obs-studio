#ifndef BASEWNDTITLEBARPRIVATE_H
#define BASEWNDTITLEBARPRIVATE_H
#include <qglobal.h>
#include <QPixmap>

class CBaseWndTitleBar;
class QPushButton;
class QLabel;
class CBaseWndTitleBarPrivate
{
Q_DECLARE_PUBLIC(CBaseWndTitleBar)
public:
    CBaseWndTitleBarPrivate(CBaseWndTitleBar *qp);
    ~CBaseWndTitleBarPrivate();
protected:
    CBaseWndTitleBar *q_ptr;
    QPixmap m_icon;
    QString m_text;
    QLabel *m_pIcon;
    QLabel *m_pTitle;
    QPushButton *m_pMinimum;
    QPushButton *m_pMaximum;
    QPushButton *m_pClose;
};


#endif // BASEWNDTITLEBARPRIVATE_H

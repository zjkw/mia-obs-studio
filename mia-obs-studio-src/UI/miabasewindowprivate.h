#ifndef BASEWINDOWPRIVATE_H
#define BASEWINDOWPRIVATE_H
#include <qglobal.h>
class CBaseWindow;
class CBaseWndTitleBar;
class QVBoxLayout;
class CBaseWindowPrivate
{
    Q_DECLARE_PUBLIC(CBaseWindow)
public:
    CBaseWindowPrivate(CBaseWindow *qp);
    ~CBaseWindowPrivate();
protected:
    int m_shadowWidth;
    bool m_hasShadow;
    bool m_shadowVisible;
    int m_captionHeight;
    CBaseWndTitleBar *m_pTitleBar;
    QVBoxLayout *m_pMainLayout;
protected:
    CBaseWindow *q_ptr;
};

#endif // BASEWINDOWPRIVATE_H

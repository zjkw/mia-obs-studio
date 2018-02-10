#include "miabasewindowprivate.h"
#include "miabasewindow.h"

CBaseWindowPrivate::CBaseWindowPrivate(CBaseWindow *qp):
    m_shadowWidth(8),
    m_hasShadow(true),
    m_shadowVisible(true),
    m_captionHeight(30),
    q_ptr(qp)
{

}

CBaseWindowPrivate::~CBaseWindowPrivate()
{

}



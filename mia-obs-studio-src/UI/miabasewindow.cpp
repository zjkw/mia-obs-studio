#include "miabasewindow.h"
#include "miabasewindowprivate.h"
#include "miabasewndtitlebar.h"
#include <QPaintEvent>
#include <QPainter>
#include <QtMath>
#include <QVBoxLayout>

CBaseWindow::CBaseWindow(QWidget *parent):
    QDialog(parent),
    d_ptr(new CBaseWindowPrivate(this))
{
    initView();
    initLayout();
    initSlot();
}

CBaseWindow::~CBaseWindow()
{

}

void CBaseWindow::initView()
{
    setWindowOpacity(1);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setFixedSize(400, 300);

    Q_D(CBaseWindow);
    d->m_pTitleBar = new CBaseWndTitleBar(this);
    d->m_pMainLayout = new QVBoxLayout;

    d->m_pTitleBar->setTitleText(windowTitle());
}

void CBaseWindow::initLayout()
{
    Q_D(CBaseWindow);
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(d->m_pTitleBar);
    vLayout->addLayout(d->m_pMainLayout);
    if (d->m_hasShadow)
    {
        vLayout->setContentsMargins(d->m_shadowWidth, d->m_shadowWidth, d->m_shadowWidth, d->m_shadowWidth);
    }
    else
    {
        vLayout->setContentsMargins(0, 0, 0, 0);
    }
    setLayout(vLayout);
}

void CBaseWindow::initSlot()
{
    Q_D(CBaseWindow);
    connect(d->m_pTitleBar, SIGNAL(onMinimum(bool&)), this, SLOT(onMinimum(bool&)));
    connect(d->m_pTitleBar, SIGNAL(onMaximum(bool&)), this, SLOT(onMaximum(bool&)));
    connect(d->m_pTitleBar, SIGNAL(onClose(bool&)), this, SLOT(onClose(bool&)));
}

QVBoxLayout* CBaseWindow::mainLayout()
{
    Q_D(CBaseWindow);
    return d->m_pMainLayout;
}

void CBaseWindow::setMinimumVisible(bool visible)
{
    Q_D(CBaseWindow);
    d->m_pTitleBar->setMinimumVisible(visible);
}

void CBaseWindow::setMaximumVisible(bool visible)
{
    Q_D(CBaseWindow);
    d->m_pTitleBar->setMaximumVisible(visible);
}

void CBaseWindow::setCloseVisible(bool visible)
{
    Q_D(CBaseWindow);
    d->m_pTitleBar->setCloseVisible(visible);
}

void CBaseWindow::setMinimumEnable(bool enable)
{
    Q_D(CBaseWindow);
    d->m_pTitleBar->setMinimumEnable(enable);
}

void CBaseWindow::setMaximumEnable(bool enable)
{
    Q_D(CBaseWindow);
    d->m_pTitleBar->setMaximumEnable(enable);
}

void CBaseWindow::setCloseEnable(bool enable)
{
    Q_D(CBaseWindow);
    d->m_pTitleBar->setCloseEnable(enable);
}

void CBaseWindow::setTitleIcon(const QPixmap &pixmap)
{
    Q_D(CBaseWindow);
    d->m_pTitleBar->setTitleIcon(pixmap);
}

void CBaseWindow::setTitleText(const QString &text)
{
    Q_D(CBaseWindow);
    setWindowTitle(text);
    d->m_pTitleBar->setTitleText(text);
}

bool CBaseWindow::isMinimumVisible()
{
    Q_D(CBaseWindow);
    return d->m_pTitleBar->isMinimumVisible();
}

bool CBaseWindow::isMaximumVisible()
{
    Q_D(CBaseWindow);
    return d->m_pTitleBar->isMaximumVisible();
}

bool CBaseWindow::isCloseVisible()
{
    Q_D(CBaseWindow);
    return d->m_pTitleBar->isCloseVisible();
}

bool CBaseWindow::isMinimumEnable()
{
    Q_D(CBaseWindow);
    return d->m_pTitleBar->isMinimumEnable();
}

bool CBaseWindow::isMaximumEnable()
{
    Q_D(CBaseWindow);
    return d->m_pTitleBar->isMaximumEnable();
}

bool CBaseWindow::isCloseEnable()
{
    Q_D(CBaseWindow);
    return d->m_pTitleBar->isCloseEnable();
}

QString CBaseWindow::titleText()
{
    Q_D(CBaseWindow);
    return d->m_pTitleBar->titleText();
}

void CBaseWindow::paintEvent(QPaintEvent *)
{
    Q_D(CBaseWindow);
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);

    int shadowWidth = (d->m_hasShadow && !isFullScreen()) ? d->m_shadowWidth : 0;
    QRect rect(shadowWidth, shadowWidth, this->width() - shadowWidth * 2, this->height() - shadowWidth * 2);
    path.addRect(rect);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    paintBackground(painter, rect);
    QColor color(140, 140, 140, 55);
    for (int i = 0; i != shadowWidth; ++i)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRoundRect(shadowWidth - i, shadowWidth - i, this->width() - (shadowWidth - i) * 2, this->height() - (shadowWidth - i) * 2, 0);
        color.setAlpha(140 - qSqrt(i) * 50);
        painter.setPen(color);
        painter.drawPath(path);
    }
}

void CBaseWindow::paintBackground(QPainter &p, QRect &rect)
{
    p.fillRect(rect, QBrush(Qt::white));
}

void CBaseWindow::onMinimum(bool & ret)
{
    ret = true;
    showMinimized();
}

void CBaseWindow::onMaximum(bool & ret)
{
    ret = true;
    if (!isMaximized())
    {
        showMaximized();
    }
    else
    {
        showNormal();
    }
}

void CBaseWindow::onClose(bool & ret)
{
    ret = true;
    close();
    emit closed();
}

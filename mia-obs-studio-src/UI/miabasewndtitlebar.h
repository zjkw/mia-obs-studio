#ifndef BASEWNDTITLEBAR_H
#define BASEWNDTITLEBAR_H

#include <QWidget>
#include <QPoint>
class CBaseWndTitleBarPrivate;

class CBaseWndTitleBar : public QWidget
{
    Q_OBJECT
public:
    CBaseWndTitleBar(QWidget *parent);
    ~CBaseWndTitleBar();
public:
    void setMinimumVisible(bool visible);
    void setMaximumVisible(bool visible);
    void setCloseVisible(bool visible);
    void setMinimumEnable(bool enable);
    void setMaximumEnable(bool enable);
    void setCloseEnable(bool enable);
    void setTitleIcon(const QPixmap &pixmap);
    void setTitleText(const QString &text);
    bool isMinimumVisible();
    bool isMaximumVisible();
    bool isCloseVisible();
    bool isMinimumEnable();
    bool isMaximumEnable();
    bool isCloseEnable();
    QString titleText();
protected:
    void initView();
    void initLayout();
    void initSlots();
protected slots:
    void onClickMinimum(bool);
    void onClickMaximum(bool);
    void onClickClose(bool);
signals:
    void onMinimum(bool & ret);
    void onMaximum(bool & ret);
    void onClose(bool & ret);
protected:
    bool eventFilter(QObject *target, QEvent *event) override;
private:
    Q_DECLARE_PRIVATE(CBaseWndTitleBar)
    Q_DISABLE_COPY(CBaseWndTitleBar)
protected:
    CBaseWndTitleBarPrivate* const d_ptr; /*!<私有数据*/
    bool m_bMoving;
    QPoint m_movePos;
};

#endif // BASEWNDTITLEBAR_H

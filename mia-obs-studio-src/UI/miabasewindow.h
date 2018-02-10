#ifndef BASEWINDOW_H
#define BASEWINDOW_H


#include <QDialog>
class QVBoxLayout;
class CBaseWindowPrivate;
class CBaseWindow : public QDialog
{
    Q_OBJECT
public:
    CBaseWindow(QWidget *parent);
    ~CBaseWindow();
public:
    QVBoxLayout* mainLayout();
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
    void paintEvent(QPaintEvent *) override;
    virtual void paintBackground(QPainter &p, QRect &rect);
    void initView();
    void initLayout();
    void initSlot();
protected slots:
    void onMinimum(bool & ret);
    void onMaximum(bool & ret);
    void onClose(bool & ret);
signals:
    void closed();
private:
    Q_DECLARE_PRIVATE(CBaseWindow)
    Q_DISABLE_COPY(CBaseWindow)
protected:
    CBaseWindowPrivate* const d_ptr; /*!<私有数据*/
};

#endif // BASEWINDOW_H

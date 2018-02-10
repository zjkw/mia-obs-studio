#ifndef MAINLISTWIDGET_H
#define MAINLISTWIDGET_H
#include <QWidget>
#include <QList>
#include <QMap>

class QListWidgetItem;
class CMainListWidgetItem;
class CMainListWidgetPrivate;

class CMainListWidget : public QWidget
{
    Q_OBJECT
public:
    CMainListWidget(QWidget *parent);
    ~CMainListWidget();
public:
    void insertCourse(int id, const QPixmap &pixmap, const QString &name, const QString &time, const QString &type, const QString &teacher);
    void removeCourse(int id);
    CMainListWidgetItem* course(int id);
    CMainListWidgetItem* curCourse();
protected:
    void initView();
    void initLayout();
    void initSlots();
protected slots:
    void onCurrentItemChanged(QListWidgetItem *current ,QListWidgetItem *previous);
private:
    Q_DECLARE_PRIVATE(CMainListWidget)
    Q_DISABLE_COPY(CMainListWidget)
protected:
    CMainListWidgetPrivate* const d_ptr; /*!<私有数据*/
};

#endif // MAINLISTWIDGET_H

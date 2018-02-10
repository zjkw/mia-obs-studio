#ifndef MAINLISTWIDGETITEM_H
#define MAINLISTWIDGETITEM_H
#include <QWidget>

class CMainListWidgetItemPrivate;
class CMainListWidgetItem : public QWidget
{
    Q_OBJECT
public:
    CMainListWidgetItem(QWidget *parent);
    ~CMainListWidgetItem();
public:
    void init(int id, const QPixmap &pixmap, const QString &name, const QString &time, const QString &type, const QString &teacher);
    void selectItem(bool selected);
    void updateLiveState(bool live);
    void updateCover(const QPixmap &pixmap);
    void updateName(const QString &name);
    void updateTime(const QString &time);
    void updateType(const QString &type);
    void updateTeacher(const QString &teacher);
    int id();
protected:
    void initView();
    void initLayout();
    void initSlots();
private:
    Q_DECLARE_PRIVATE(CMainListWidgetItem)
    Q_DISABLE_COPY(CMainListWidgetItem)
protected:
    CMainListWidgetItemPrivate* const d_ptr; /*!<私有数据*/
};

#endif // MAINLISTWIDGETITEM_H

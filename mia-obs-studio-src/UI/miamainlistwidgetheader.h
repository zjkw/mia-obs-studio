#ifndef MIAMAINLISTWIDGETHEADER_H
#define MIAMAINLISTWIDGETHEADER_H
#include <QWidget>
class QLabel;
class CMainListWidgetHeader : public QWidget
{
    Q_OBJECT
public:
    CMainListWidgetHeader(QWidget *parent);
    ~CMainListWidgetHeader();
public:
    void init(const QString &cover, const QString &name, const QString &time, const QString &type, const QString &teacher);
protected:
    void initView();
    void initLayout();
protected:
    QLabel *m_pCover;
    QLabel *m_pName;
    QLabel *m_pTime;
    QLabel *m_pType;
    QLabel *m_pTeacher;
};

#endif // MIAMAINLISTWIDGETHEADER_H

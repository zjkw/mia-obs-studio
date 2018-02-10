#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "miabasewindow.h"
#include <QMap>
#include <jansson.h>
#include "mia-websocket-client.hpp"

class QLabel;
class QPushButton;
class CMainListWidget;
class CMainWindow : public CBaseWindow
{
    enum TipType
    {
	ettLoading = 0,
	ettEmpty   = 1,
	ettError   = 2,
	ettList    = 3,
	ettNone    = 10,
    };
    typedef CBaseWindow base;
    Q_OBJECT
public:
    CMainWindow(const QString &coverPath, QWidget *parent = 0);
    ~CMainWindow();
protected:
    void initView();
    void initLayout();
    void initSlot();
    void paintBackground(QPainter &p, QRect &rect) override;
    void insertLive(int id, const QString &cover_url, const QString &name, const QString &time, const QString &type, const QString &teacher);
protected slots:
    void onConfirm();
    void onCancel();
    void onHttpFinish(int key, int code, const QString &extend);
    void OnWebSocketConnect(MiaWebsocketClient* wc);
    void OnWebSocketClose(MiaWebsocketClient* wc);
    void OnMiaQueryCourseRes(MiaWebsocketClient* wc, const QString& json);
protected:
    void changeTipType(TipType type);
    QString getTempPath(int id);
    bool eventFilter(QObject * watched, QEvent * evt) override;
    void onClickUrl();
private:
    QWidget *m_pListPage;
    QWidget *m_pTipPage;
    QLabel *m_pTipIcon;
    QLabel *m_pTipTitle;
    QLabel *m_pTipSubTitleLeft;
    QLabel *m_pTipSubTitleCenter;
    QLabel *m_pTipSubTitleRight;
    CMainListWidget *m_pMainList;
    QPushButton *m_pConfirm;
    QPushButton *m_pCancel;
    QMap<int, int> m_download;
    QString m_coverPath;
    TipType m_type;
    struct MiaCourseItem
    {
	    QString coverID;
	    QString coverUrl;
	    QString title;
	    QString startTime;
	    QString courseType;
	    QString publishUrl;
	    QString teacherList;
    };

    bool EncodeMiaWCCommonHead(json_t* root, const QString& guid, const QString& cmd, const QString& stamp);
    bool EncodeMiaWCCourseReq(const QString& guid, const QString& uid, const QString& token, const QString& stamp, QString& out);
    bool DecodeMiaWCCourseRes(const QString& json, bool& bSuc, std::vector<MiaCourseItem>& CourseList);

    std::vector<MiaCourseItem> m_CourseList;
};

#endif // MAINWINDOW_H

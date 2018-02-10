#ifndef MIAHTTPCENTERPRIVATE_H
#define MIAHTTPCENTERPRIVATE_H
#include <qglobal.h>
#include <QMap>
#include <QObject>

class CHttpCenter;
class QThreadPool;
class CHttpRunnable;
class CHttpCenterPrivate : public QObject
{
    Q_DECLARE_PUBLIC(CHttpCenter)
    Q_OBJECT
public:
    enum HttpType
    {
        ehtDownload = 0,
        ehtUpload = 1,
        ehtRequest = 2,
    };
    struct HttpNode
    {
        CHttpRunnable *runnable;
        QString url;
        QString data;
        QString path;
        HttpType type;
    };
    CHttpCenterPrivate(CHttpCenter *qp);
    ~CHttpCenterPrivate();
public:
    bool download(const QString &url, const QString &path, int &key);
    bool upload(const QString &url, const QString &path, int &key);
    bool request(const QString &url, const QString &data, int &key);
public slots:
    void progress(int key, int total, int current);
    void finish(int key, int code, const QString &extend);
protected:
    void doTask(HttpNode node, int key);
protected:
    CHttpCenter *q_ptr;
    QMap<int, HttpNode> m_mapNodes;
    QThreadPool *m_pThreadPool;
    int m_key;
};

#endif // MIAHTTPCENTERPRIVATE_H

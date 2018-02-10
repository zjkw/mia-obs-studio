#pragma once

#include "miasingleton.h"
#include <QObject>
class CHttpCenterPrivate;
class CHttpCenter : public QObject, public CSingleton<CHttpCenter>
{
    Q_OBJECT
public:
    bool download(const QString &url, const QString &path, int &key);
    bool upload(const QString &url, const QString &path, int &key);
    bool request(const QString &url, const QString &data, int &key);
signals:
    void progress(int key, int total, int current);
    void finish(int key, int code, const QString &extend);
private:
    Q_DECLARE_PRIVATE(CHttpCenter)
    Q_DISABLE_COPY(CHttpCenter)
protected:
    CHttpCenter();
    ~CHttpCenter();
    friend class CSingleton<CHttpCenter>;
    CHttpCenterPrivate* const d_ptr; /*!<私有数据*/
};


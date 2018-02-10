#include "miahttpcenter.h"
#include "miahttpcenterprivate.h"

CHttpCenter::CHttpCenter():
    d_ptr(new CHttpCenterPrivate(this))
{

}

CHttpCenter::~CHttpCenter()
{

}

bool CHttpCenter::download(const QString &url, const QString &path, int &key)
{
    Q_D(CHttpCenter);
    return d->download(url, path, key);
}
bool CHttpCenter::upload(const QString &url, const QString &path, int &key)
{
    Q_D(CHttpCenter);
    return d->upload(url, path, key);
}

bool CHttpCenter::request(const QString &url, const QString &data, int &key)
{
    Q_D(CHttpCenter);
    return d->request(url, data, key);
}

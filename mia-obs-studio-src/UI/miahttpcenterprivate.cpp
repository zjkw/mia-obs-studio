#include "miahttpcenterprivate.h"
#include "miahttpcenter.h"
#include "miahttprunnable.h"
#include <QThreadPool>

CHttpCenterPrivate::CHttpCenterPrivate(CHttpCenter *qp):
    q_ptr(qp),
    m_key(0)
{
    m_pThreadPool = QThreadPool::globalInstance();
    m_pThreadPool->setMaxThreadCount(5);
}

CHttpCenterPrivate::~CHttpCenterPrivate()
{
    m_pThreadPool->releaseThread();
    m_pThreadPool->waitForDone();
}

bool CHttpCenterPrivate::download(const QString &url, const QString &path, int &key)
{
    key = ++m_key;
    HttpNode node;
    node.type = ehtDownload;
    node.path = path;
    node.url = url;
    node.runnable = new CHttpDownloadRunnable;
    node.runnable->initRunnable(key, node.url, node.data, node.path, node.type);
    doTask(node, key);
    return true;
}

bool CHttpCenterPrivate::upload(const QString &url, const QString &path, int &key)
{
    key = ++m_key;
    HttpNode node;
    node.type = ehtUpload;
    node.path = path;
    node.url = url;
    node.runnable = new CHttpUploadRunnable;
    node.runnable->initRunnable(key, node.url, node.data, node.path, node.type);
    doTask(node, key);
    return true;
}

bool CHttpCenterPrivate::request(const QString &url, const QString &data, int &key)
{
    key = ++m_key;
    HttpNode node;
    node.type = ehtRequest;
    node.data = data;
    node.url = url;
    node.runnable = new CHttpRequestRunnable;
    node.runnable->initRunnable(key, node.url, node.data, node.path, node.type);
    doTask(node, key);
    return true;
}

void CHttpCenterPrivate::progress(int key, int total, int current)
{
    if (!m_mapNodes.contains(key))
    {
        return;
    }
    emit q_ptr->progress(key, total, current);
}

void CHttpCenterPrivate::finish(int key, int code, const QString &extend)
{
    if (!m_mapNodes.contains(key))
    {
        return;
    }
    m_mapNodes.remove(key);
    emit q_ptr->finish(key, code, extend);
}

void CHttpCenterPrivate::doTask(HttpNode node, int key)
{
    m_mapNodes.insert(key, node);
    connect(node.runnable, SIGNAL(progress(int,int,int)), this, SLOT(progress(int,int,int)));
    connect(node.runnable, SIGNAL(finish(int,int,QString)), this, SLOT(finish(int,int,QString)));
    m_pThreadPool->start(node.runnable);
}

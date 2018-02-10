#pragma once

#include <QDialog>
#include <QtWebEngineWidgets/QWebEngineView> 
#include "mia-websocket-client.hpp"
#include <jansson.h>
#include "obs-app.hpp"

#include <vector>

class bridge : QObject
{
	Q_OBJECT
public:
	static bridge* instance();

public:
	Q_INVOKABLE void OnJs2Cpp(const QString &cmd, const QString &json);

signals:
	void Cpp2Js(const QString &cmd, const QString &json);
	void JsSign(const QString &cmd, const QString &json);

private:
	bridge();
};

// 微信登陆 以及关键数据数据拉取
class MiaLoginDialog : public QDialog
{
	Q_OBJECT
protected slots:
	void OnWxLoginResult(const QString &cmd, const QString &json);
	void OnWebSocketConnect(MiaWebsocketClient* wc);
	void OnWebSocketClose(MiaWebsocketClient* wc);
	void OnMiaLoginRes(MiaWebsocketClient* wc, const QString& json);
	void OnMiaQueryObsRes(MiaWebsocketClient* wc, const QString& json);

public:
	MiaLoginDialog(QWidget *parent = 0);
	~MiaLoginDialog();

	//成功返回true
	bool GetResult();
	void resizeEvent(QResizeEvent*);
	
private:
	//临时缓存
	bool	_suc;
	QString _guid;
	QString _uid;
	QString _token;

	QWebEngineView* _view;

	bool EncodePromptText(const QString& in, QString& out);
	bool DecodeLoginResult(const QString& json, bool& bSuc, QString& guid, QString& uid, QString& token); 
	bool EncodeMiaWCCommonHead(json_t* root, const QString& guid, const QString& cmd, const QString& stamp);
	bool EncodeMiaWCLoginReq(const QString& guid, const QString& uid, const QString& token, const QString& stamp, QString& out);
	bool DecodeMiaWCLoginRes(const QString& json, bool& bSuc);
	bool EncodeMiaWCQueryObsReq(const QString& guid, const QString& stamp, QString& out);
	bool DecodeMiaWCQueryObsRes(const QString& json, bool& bSuc, MiaObsServerConf* conf);

	bool SetPromptText(const QString& in);
};

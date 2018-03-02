#pragma once

#include <QThread>
#include <QString>

class AutoUpdateThread : public QThread {
	Q_OBJECT

	bool manualUpdate;
	bool user_confirmed = false;

	virtual void run() override;

	void info(const QString &title, const QString &text);
	int queryUpdate();
signals:
    void showUpdateTips(const QString &title, const QString &content, const QString &button);
private slots:
	void infoMsg(const QString &title, const QString &text);
	int queryUpdateSlot();

public:
	AutoUpdateThread(bool manualUpdate_) : manualUpdate(manualUpdate_) {}
};

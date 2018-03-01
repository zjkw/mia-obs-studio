#pragma once

#include <QDialog>
#include <memory>

//#include "ui_OBSUpdate.h"

class QPushButton;
class QLabel;
class OBSUpdate : public QDialog {
	Q_OBJECT

public:
	enum ReturnVal {
		No,
		Yes,
		Skip
	};

	OBSUpdate(QWidget *parent);

public slots:
	void on_yes_clicked();
	void on_no_clicked();
	void on_skip_clicked();
	virtual void accept() override;
	virtual void reject() override;
protected:
    void initView();
    void initLayout();
    void initSlots();
private:
	//std::unique_ptr<Ui_OBSUpdate> ui;
    QPushButton *m_pBtnUpdate;
    QPushButton *m_pBtnCancel;
    QLabel *m_pLbContent;
};

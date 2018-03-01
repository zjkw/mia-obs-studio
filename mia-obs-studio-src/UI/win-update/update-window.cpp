#include "update-window.hpp"
#include "obs-app.hpp"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

OBSUpdate::OBSUpdate(QWidget *parent)
	: QDialog (parent, Qt::WindowSystemMenuHint |
	                   Qt::WindowTitleHint |
	                   Qt::WindowCloseButtonHint)
    //, ui      (new Ui_OBSUpdate)
{
	//ui->setupUi(this);
//	ui->text->setHtml(text);

		//delete ui->skip;
		//ui->skip = nullptr;

		//ui->no->setText(QTStr("Cancel"));

    initView();
    initLayout();
    initSlots();
}

void OBSUpdate::on_yes_clicked()
{
	done(OBSUpdate::Yes);
}

void OBSUpdate::on_no_clicked()
{
	done(OBSUpdate::No);
}

void OBSUpdate::on_skip_clicked()
{
	done(OBSUpdate::Skip);
}

void OBSUpdate::accept()
{
	done(OBSUpdate::Yes);
}

void OBSUpdate::reject()
{
	done(OBSUpdate::No);
}

void OBSUpdate::initView()
{
    setFixedSize(360, 110);
    m_pLbContent = new QLabel(this);
    m_pLbContent->setText(Str("Updater.Text"));

    m_pBtnUpdate = new QPushButton(this);
    m_pBtnCancel = new QPushButton(this);

    m_pBtnUpdate->setText(Str("Updater.UpdateNow"));
    m_pBtnCancel->setText(Str("Updater.RemindMeLater"));

    setWindowTitle(Str("Updater.Title"));

}
void OBSUpdate::initLayout()
{
    QVBoxLayout *vLayout = new QVBoxLayout;
    QHBoxLayout *hLayout = new QHBoxLayout;
    
    vLayout->addWidget(m_pLbContent);
    hLayout->addStretch();
    hLayout->addWidget(m_pBtnUpdate);
    hLayout->addWidget(m_pBtnCancel);

    vLayout->addLayout(hLayout);
    setLayout(vLayout);
}
void OBSUpdate::initSlots()
{
    connect(m_pBtnUpdate, SIGNAL(pressed()), this, SLOT(on_yes_clicked()));
    connect(m_pBtnCancel, SIGNAL(pressed()), this, SLOT(on_no_clicked()));
}
/********************************************************************************
** Form generated from reading UI file 'AutoConfigStreamPage.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOCONFIGSTREAMPAGE_H
#define UI_AUTOCONFIGSTREAMPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AutoConfigStreamPage
{
public:
    QFormLayout *formLayout;
    QLabel *serviceLabel;
    QComboBox *service;
    QLabel *streamKeyLabel;
    QHBoxLayout *horizontalLayout;
    QLineEdit *key;
    QPushButton *show;
    QCheckBox *doBandwidthTest;
    QCheckBox *preferHardware;
    QSpacerItem *horizontalSpacer;
    QLabel *serverLabel;
    QLabel *label_3;
    QComboBox *streamType;
    QStackedWidget *serverStackedWidget;
    QWidget *servicePage;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *server;
    QWidget *customPage;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *customServer;
    QGroupBox *region;
    QGridLayout *gridLayout;
    QCheckBox *regionAsia;
    QCheckBox *regionUS;
    QCheckBox *regionEU;
    QCheckBox *regionOther;
    QSpinBox *bitrate;
    QLabel *bitrateLabel;

    void setupUi(QWidget *AutoConfigStreamPage)
    {
        if (AutoConfigStreamPage->objectName().isEmpty())
            AutoConfigStreamPage->setObjectName(QStringLiteral("AutoConfigStreamPage"));
        AutoConfigStreamPage->resize(566, 335);
        AutoConfigStreamPage->setWindowTitle(QStringLiteral(""));
        formLayout = new QFormLayout(AutoConfigStreamPage);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        serviceLabel = new QLabel(AutoConfigStreamPage);
        serviceLabel->setObjectName(QStringLiteral("serviceLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, serviceLabel);

        service = new QComboBox(AutoConfigStreamPage);
        service->setObjectName(QStringLiteral("service"));

        formLayout->setWidget(1, QFormLayout::FieldRole, service);

        streamKeyLabel = new QLabel(AutoConfigStreamPage);
        streamKeyLabel->setObjectName(QStringLiteral("streamKeyLabel"));
        streamKeyLabel->setOpenExternalLinks(true);

        formLayout->setWidget(3, QFormLayout::LabelRole, streamKeyLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        key = new QLineEdit(AutoConfigStreamPage);
        key->setObjectName(QStringLiteral("key"));
        key->setInputMask(QStringLiteral(""));
        key->setText(QStringLiteral(""));
        key->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(key);

        show = new QPushButton(AutoConfigStreamPage);
        show->setObjectName(QStringLiteral("show"));

        horizontalLayout->addWidget(show);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout);

        doBandwidthTest = new QCheckBox(AutoConfigStreamPage);
        doBandwidthTest->setObjectName(QStringLiteral("doBandwidthTest"));
        doBandwidthTest->setChecked(true);

        formLayout->setWidget(6, QFormLayout::FieldRole, doBandwidthTest);

        preferHardware = new QCheckBox(AutoConfigStreamPage);
        preferHardware->setObjectName(QStringLiteral("preferHardware"));
        preferHardware->setChecked(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, preferHardware);

        horizontalSpacer = new QSpacerItem(90, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        formLayout->setItem(6, QFormLayout::LabelRole, horizontalSpacer);

        serverLabel = new QLabel(AutoConfigStreamPage);
        serverLabel->setObjectName(QStringLiteral("serverLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, serverLabel);

        label_3 = new QLabel(AutoConfigStreamPage);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        streamType = new QComboBox(AutoConfigStreamPage);
        streamType->setObjectName(QStringLiteral("streamType"));

        formLayout->setWidget(0, QFormLayout::FieldRole, streamType);

        serverStackedWidget = new QStackedWidget(AutoConfigStreamPage);
        serverStackedWidget->setObjectName(QStringLiteral("serverStackedWidget"));
        servicePage = new QWidget();
        servicePage->setObjectName(QStringLiteral("servicePage"));
        horizontalLayout_2 = new QHBoxLayout(servicePage);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        server = new QComboBox(servicePage);
        server->setObjectName(QStringLiteral("server"));

        horizontalLayout_2->addWidget(server);

        serverStackedWidget->addWidget(servicePage);
        customPage = new QWidget();
        customPage->setObjectName(QStringLiteral("customPage"));
        horizontalLayout_3 = new QHBoxLayout(customPage);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        customServer = new QLineEdit(customPage);
        customServer->setObjectName(QStringLiteral("customServer"));

        horizontalLayout_3->addWidget(customServer);

        serverStackedWidget->addWidget(customPage);

        formLayout->setWidget(2, QFormLayout::FieldRole, serverStackedWidget);

        region = new QGroupBox(AutoConfigStreamPage);
        region->setObjectName(QStringLiteral("region"));
        gridLayout = new QGridLayout(region);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        regionAsia = new QCheckBox(region);
        regionAsia->setObjectName(QStringLiteral("regionAsia"));

        gridLayout->addWidget(regionAsia, 2, 0, 1, 1);

        regionUS = new QCheckBox(region);
        regionUS->setObjectName(QStringLiteral("regionUS"));

        gridLayout->addWidget(regionUS, 0, 0, 1, 1);

        regionEU = new QCheckBox(region);
        regionEU->setObjectName(QStringLiteral("regionEU"));

        gridLayout->addWidget(regionEU, 0, 1, 1, 1);

        regionOther = new QCheckBox(region);
        regionOther->setObjectName(QStringLiteral("regionOther"));

        gridLayout->addWidget(regionOther, 2, 1, 1, 1);


        formLayout->setWidget(7, QFormLayout::FieldRole, region);

        bitrate = new QSpinBox(AutoConfigStreamPage);
        bitrate->setObjectName(QStringLiteral("bitrate"));
        bitrate->setSuffix(QStringLiteral(""));
        bitrate->setMinimum(500);
        bitrate->setMaximum(10000);
        bitrate->setValue(2500);

        formLayout->setWidget(4, QFormLayout::FieldRole, bitrate);

        bitrateLabel = new QLabel(AutoConfigStreamPage);
        bitrateLabel->setObjectName(QStringLiteral("bitrateLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, bitrateLabel);

#ifndef QT_NO_SHORTCUT
        serviceLabel->setBuddy(service);
        streamKeyLabel->setBuddy(key);
        bitrateLabel->setBuddy(bitrate);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(streamType, service);
        QWidget::setTabOrder(service, server);
        QWidget::setTabOrder(server, customServer);
        QWidget::setTabOrder(customServer, key);
        QWidget::setTabOrder(key, show);
        QWidget::setTabOrder(show, preferHardware);
        QWidget::setTabOrder(preferHardware, doBandwidthTest);
        QWidget::setTabOrder(doBandwidthTest, regionUS);
        QWidget::setTabOrder(regionUS, regionEU);
        QWidget::setTabOrder(regionEU, regionAsia);
        QWidget::setTabOrder(regionAsia, regionOther);

        retranslateUi(AutoConfigStreamPage);

        serverStackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AutoConfigStreamPage);
    } // setupUi

    void retranslateUi(QWidget *AutoConfigStreamPage)
    {
        serviceLabel->setText(QApplication::translate("AutoConfigStreamPage", "Basic.AutoConfig.StreamPage.Service", Q_NULLPTR));
        streamKeyLabel->setText(QApplication::translate("AutoConfigStreamPage", "Basic.AutoConfig.StreamPage.StreamKey", Q_NULLPTR));
        show->setText(QApplication::translate("AutoConfigStreamPage", "Show", Q_NULLPTR));
        doBandwidthTest->setText(QApplication::translate("AutoConfigStreamPage", "Basic.AutoConfig.StreamPage.PerformBandwidthTest", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        preferHardware->setToolTip(QApplication::translate("AutoConfigStreamPage", "Basic.AutoConfig.StreamPage.PreferHardwareEncoding.ToolTip", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        preferHardware->setText(QApplication::translate("AutoConfigStreamPage", "Basic.AutoConfig.StreamPage.PreferHardwareEncoding", Q_NULLPTR));
        serverLabel->setText(QApplication::translate("AutoConfigStreamPage", "Basic.AutoConfig.StreamPage.Server", Q_NULLPTR));
        label_3->setText(QApplication::translate("AutoConfigStreamPage", "Basic.Settings.Stream.StreamType", Q_NULLPTR));
        region->setTitle(QApplication::translate("AutoConfigStreamPage", "BandwidthTest.Region", Q_NULLPTR));
        regionAsia->setText(QApplication::translate("AutoConfigStreamPage", "BandwidthTest.Region.Asia", Q_NULLPTR));
        regionUS->setText(QApplication::translate("AutoConfigStreamPage", "BandwidthTest.Region.US", Q_NULLPTR));
        regionEU->setText(QApplication::translate("AutoConfigStreamPage", "BandwidthTest.Region.EU", Q_NULLPTR));
        regionOther->setText(QApplication::translate("AutoConfigStreamPage", "BandwidthTest.Region.Other", Q_NULLPTR));
        bitrateLabel->setText(QApplication::translate("AutoConfigStreamPage", "Basic.Settings.Output.VideoBitrate", Q_NULLPTR));
        Q_UNUSED(AutoConfigStreamPage);
    } // retranslateUi

};

namespace Ui {
    class AutoConfigStreamPage: public Ui_AutoConfigStreamPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOCONFIGSTREAMPAGE_H

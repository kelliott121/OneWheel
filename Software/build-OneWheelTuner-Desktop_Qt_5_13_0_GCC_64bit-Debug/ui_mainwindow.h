/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabSerial;
    QGridLayout *gridLayout_2;
    QPushButton *btnConnect;
    QComboBox *cmbPort;
    QLabel *lblPort;
    QLabel *lblStatusText;
    QLabel *lblStatusValue;
    QTextEdit *txtSerial;
    QWidget *tabTune;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *vlGainP;
    QLabel *lblGainPName;
    QLabel *lblGainPValue;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnGainPMinus001;
    QPushButton *btnGainPPlus001;
    QHBoxLayout *hlGainP01;
    QPushButton *btnGainPMinus01;
    QPushButton *btnGainPPlus01;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnGainPMinus10;
    QPushButton *btnGainPPlus10;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnGainPMinus100;
    QPushButton *btnGainPPlus100;
    QVBoxLayout *vlGainI;
    QLabel *lblGainIName;
    QLabel *lblGainIValue;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *btnGainIMinus001;
    QPushButton *btnGainIPlus001;
    QHBoxLayout *hlGainI;
    QPushButton *btnGainIMinus01;
    QPushButton *btnGainIPlus01;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btnGainIMinus10;
    QPushButton *btnGainIPlus10;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnGainIMinus100;
    QPushButton *btnGainIPlus100;
    QVBoxLayout *vlGainD;
    QLabel *lblGainDName;
    QLabel *lblGainDValue;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *btnGainDMinus001;
    QPushButton *btnGainDPlus001;
    QHBoxLayout *hlGainD;
    QPushButton *btnGainDMinus01;
    QPushButton *btnGainDPlus01;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *btnGainDMinus10;
    QPushButton *btnGainDPlus10;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btnGainDMinus100;
    QPushButton *btnGainDPlus100;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *cbClosedLoop;
    QWidget *tabTiming;
    QVBoxLayout *verticalLayout_5;
    QLabel *lblLoopTimer;
    QChartView *grphControlTime;
    QLabel *label;
    QChartView *grphIdleTime;
    QWidget *tab;
    QVBoxLayout *verticalLayout_6;
    QChartView *grphAngleData;
    QChartView *grphPIDData;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(564, 500);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabSerial = new QWidget();
        tabSerial->setObjectName(QString::fromUtf8("tabSerial"));
        sizePolicy.setHeightForWidth(tabSerial->sizePolicy().hasHeightForWidth());
        tabSerial->setSizePolicy(sizePolicy);
        tabSerial->setMaximumSize(QSize(9999, 9999));
        tabSerial->setLayoutDirection(Qt::LeftToRight);
        gridLayout_2 = new QGridLayout(tabSerial);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btnConnect = new QPushButton(tabSerial);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setFocusPolicy(Qt::StrongFocus);

        gridLayout_2->addWidget(btnConnect, 0, 2, 1, 1);

        cmbPort = new QComboBox(tabSerial);
        cmbPort->setObjectName(QString::fromUtf8("cmbPort"));

        gridLayout_2->addWidget(cmbPort, 0, 1, 1, 1);

        lblPort = new QLabel(tabSerial);
        lblPort->setObjectName(QString::fromUtf8("lblPort"));

        gridLayout_2->addWidget(lblPort, 0, 0, 1, 1);

        lblStatusText = new QLabel(tabSerial);
        lblStatusText->setObjectName(QString::fromUtf8("lblStatusText"));

        gridLayout_2->addWidget(lblStatusText, 1, 0, 1, 1);

        lblStatusValue = new QLabel(tabSerial);
        lblStatusValue->setObjectName(QString::fromUtf8("lblStatusValue"));

        gridLayout_2->addWidget(lblStatusValue, 1, 1, 1, 1);

        txtSerial = new QTextEdit(tabSerial);
        txtSerial->setObjectName(QString::fromUtf8("txtSerial"));
        txtSerial->setEnabled(true);
        sizePolicy.setHeightForWidth(txtSerial->sizePolicy().hasHeightForWidth());
        txtSerial->setSizePolicy(sizePolicy);
        txtSerial->setLineWidth(1);
        txtSerial->setReadOnly(true);

        gridLayout_2->addWidget(txtSerial, 2, 0, 1, 3);

        tabWidget->addTab(tabSerial, QString());
        tabTune = new QWidget();
        tabTune->setObjectName(QString::fromUtf8("tabTune"));
        sizePolicy1.setHeightForWidth(tabTune->sizePolicy().hasHeightForWidth());
        tabTune->setSizePolicy(sizePolicy1);
        verticalLayout_3 = new QVBoxLayout(tabTune);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        vlGainP = new QVBoxLayout();
        vlGainP->setSpacing(6);
        vlGainP->setObjectName(QString::fromUtf8("vlGainP"));
        lblGainPName = new QLabel(tabTune);
        lblGainPName->setObjectName(QString::fromUtf8("lblGainPName"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        lblGainPName->setFont(font);
        lblGainPName->setScaledContents(false);
        lblGainPName->setAlignment(Qt::AlignCenter);

        vlGainP->addWidget(lblGainPName);

        lblGainPValue = new QLabel(tabTune);
        lblGainPValue->setObjectName(QString::fromUtf8("lblGainPValue"));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setWeight(50);
        lblGainPValue->setFont(font1);
        lblGainPValue->setAlignment(Qt::AlignCenter);

        vlGainP->addWidget(lblGainPValue);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        btnGainPMinus001 = new QPushButton(tabTune);
        btnGainPMinus001->setObjectName(QString::fromUtf8("btnGainPMinus001"));
        btnGainPMinus001->setFont(font);

        horizontalLayout_4->addWidget(btnGainPMinus001);

        btnGainPPlus001 = new QPushButton(tabTune);
        btnGainPPlus001->setObjectName(QString::fromUtf8("btnGainPPlus001"));
        btnGainPPlus001->setFont(font);

        horizontalLayout_4->addWidget(btnGainPPlus001);


        vlGainP->addLayout(horizontalLayout_4);

        hlGainP01 = new QHBoxLayout();
        hlGainP01->setSpacing(6);
        hlGainP01->setObjectName(QString::fromUtf8("hlGainP01"));
        btnGainPMinus01 = new QPushButton(tabTune);
        btnGainPMinus01->setObjectName(QString::fromUtf8("btnGainPMinus01"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnGainPMinus01->sizePolicy().hasHeightForWidth());
        btnGainPMinus01->setSizePolicy(sizePolicy2);
        btnGainPMinus01->setFont(font);

        hlGainP01->addWidget(btnGainPMinus01);

        btnGainPPlus01 = new QPushButton(tabTune);
        btnGainPPlus01->setObjectName(QString::fromUtf8("btnGainPPlus01"));
        sizePolicy2.setHeightForWidth(btnGainPPlus01->sizePolicy().hasHeightForWidth());
        btnGainPPlus01->setSizePolicy(sizePolicy2);
        btnGainPPlus01->setFont(font);

        hlGainP01->addWidget(btnGainPPlus01);


        vlGainP->addLayout(hlGainP01);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnGainPMinus10 = new QPushButton(tabTune);
        btnGainPMinus10->setObjectName(QString::fromUtf8("btnGainPMinus10"));
        btnGainPMinus10->setFont(font);

        horizontalLayout_2->addWidget(btnGainPMinus10);

        btnGainPPlus10 = new QPushButton(tabTune);
        btnGainPPlus10->setObjectName(QString::fromUtf8("btnGainPPlus10"));
        btnGainPPlus10->setFont(font);

        horizontalLayout_2->addWidget(btnGainPPlus10);


        vlGainP->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnGainPMinus100 = new QPushButton(tabTune);
        btnGainPMinus100->setObjectName(QString::fromUtf8("btnGainPMinus100"));
        btnGainPMinus100->setFont(font);

        horizontalLayout_3->addWidget(btnGainPMinus100);

        btnGainPPlus100 = new QPushButton(tabTune);
        btnGainPPlus100->setObjectName(QString::fromUtf8("btnGainPPlus100"));
        btnGainPPlus100->setFont(font);

        horizontalLayout_3->addWidget(btnGainPPlus100);


        vlGainP->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(vlGainP);

        vlGainI = new QVBoxLayout();
        vlGainI->setSpacing(6);
        vlGainI->setObjectName(QString::fromUtf8("vlGainI"));
        lblGainIName = new QLabel(tabTune);
        lblGainIName->setObjectName(QString::fromUtf8("lblGainIName"));
        lblGainIName->setFont(font);
        lblGainIName->setScaledContents(false);
        lblGainIName->setAlignment(Qt::AlignCenter);

        vlGainI->addWidget(lblGainIName);

        lblGainIValue = new QLabel(tabTune);
        lblGainIValue->setObjectName(QString::fromUtf8("lblGainIValue"));
        lblGainIValue->setFont(font1);
        lblGainIValue->setAlignment(Qt::AlignCenter);

        vlGainI->addWidget(lblGainIValue);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        btnGainIMinus001 = new QPushButton(tabTune);
        btnGainIMinus001->setObjectName(QString::fromUtf8("btnGainIMinus001"));
        btnGainIMinus001->setFont(font);

        horizontalLayout_9->addWidget(btnGainIMinus001);

        btnGainIPlus001 = new QPushButton(tabTune);
        btnGainIPlus001->setObjectName(QString::fromUtf8("btnGainIPlus001"));
        btnGainIPlus001->setFont(font);

        horizontalLayout_9->addWidget(btnGainIPlus001);


        vlGainI->addLayout(horizontalLayout_9);

        hlGainI = new QHBoxLayout();
        hlGainI->setSpacing(6);
        hlGainI->setObjectName(QString::fromUtf8("hlGainI"));
        btnGainIMinus01 = new QPushButton(tabTune);
        btnGainIMinus01->setObjectName(QString::fromUtf8("btnGainIMinus01"));
        sizePolicy2.setHeightForWidth(btnGainIMinus01->sizePolicy().hasHeightForWidth());
        btnGainIMinus01->setSizePolicy(sizePolicy2);
        btnGainIMinus01->setFont(font);

        hlGainI->addWidget(btnGainIMinus01);

        btnGainIPlus01 = new QPushButton(tabTune);
        btnGainIPlus01->setObjectName(QString::fromUtf8("btnGainIPlus01"));
        sizePolicy2.setHeightForWidth(btnGainIPlus01->sizePolicy().hasHeightForWidth());
        btnGainIPlus01->setSizePolicy(sizePolicy2);
        btnGainIPlus01->setFont(font);

        hlGainI->addWidget(btnGainIPlus01);


        vlGainI->addLayout(hlGainI);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        btnGainIMinus10 = new QPushButton(tabTune);
        btnGainIMinus10->setObjectName(QString::fromUtf8("btnGainIMinus10"));
        btnGainIMinus10->setFont(font);

        horizontalLayout_6->addWidget(btnGainIMinus10);

        btnGainIPlus10 = new QPushButton(tabTune);
        btnGainIPlus10->setObjectName(QString::fromUtf8("btnGainIPlus10"));
        btnGainIPlus10->setFont(font);

        horizontalLayout_6->addWidget(btnGainIPlus10);


        vlGainI->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        btnGainIMinus100 = new QPushButton(tabTune);
        btnGainIMinus100->setObjectName(QString::fromUtf8("btnGainIMinus100"));
        btnGainIMinus100->setFont(font);

        horizontalLayout_5->addWidget(btnGainIMinus100);

        btnGainIPlus100 = new QPushButton(tabTune);
        btnGainIPlus100->setObjectName(QString::fromUtf8("btnGainIPlus100"));
        btnGainIPlus100->setFont(font);

        horizontalLayout_5->addWidget(btnGainIPlus100);


        vlGainI->addLayout(horizontalLayout_5);


        horizontalLayout->addLayout(vlGainI);

        vlGainD = new QVBoxLayout();
        vlGainD->setSpacing(6);
        vlGainD->setObjectName(QString::fromUtf8("vlGainD"));
        lblGainDName = new QLabel(tabTune);
        lblGainDName->setObjectName(QString::fromUtf8("lblGainDName"));
        lblGainDName->setFont(font);
        lblGainDName->setScaledContents(false);
        lblGainDName->setAlignment(Qt::AlignCenter);

        vlGainD->addWidget(lblGainDName);

        lblGainDValue = new QLabel(tabTune);
        lblGainDValue->setObjectName(QString::fromUtf8("lblGainDValue"));
        lblGainDValue->setFont(font1);
        lblGainDValue->setAlignment(Qt::AlignCenter);

        vlGainD->addWidget(lblGainDValue);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        btnGainDMinus001 = new QPushButton(tabTune);
        btnGainDMinus001->setObjectName(QString::fromUtf8("btnGainDMinus001"));
        btnGainDMinus001->setFont(font);

        horizontalLayout_10->addWidget(btnGainDMinus001);

        btnGainDPlus001 = new QPushButton(tabTune);
        btnGainDPlus001->setObjectName(QString::fromUtf8("btnGainDPlus001"));
        btnGainDPlus001->setFont(font);

        horizontalLayout_10->addWidget(btnGainDPlus001);


        vlGainD->addLayout(horizontalLayout_10);

        hlGainD = new QHBoxLayout();
        hlGainD->setSpacing(6);
        hlGainD->setObjectName(QString::fromUtf8("hlGainD"));
        btnGainDMinus01 = new QPushButton(tabTune);
        btnGainDMinus01->setObjectName(QString::fromUtf8("btnGainDMinus01"));
        sizePolicy2.setHeightForWidth(btnGainDMinus01->sizePolicy().hasHeightForWidth());
        btnGainDMinus01->setSizePolicy(sizePolicy2);
        btnGainDMinus01->setFont(font);

        hlGainD->addWidget(btnGainDMinus01);

        btnGainDPlus01 = new QPushButton(tabTune);
        btnGainDPlus01->setObjectName(QString::fromUtf8("btnGainDPlus01"));
        sizePolicy2.setHeightForWidth(btnGainDPlus01->sizePolicy().hasHeightForWidth());
        btnGainDPlus01->setSizePolicy(sizePolicy2);
        btnGainDPlus01->setFont(font);

        hlGainD->addWidget(btnGainDPlus01);


        vlGainD->addLayout(hlGainD);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        btnGainDMinus10 = new QPushButton(tabTune);
        btnGainDMinus10->setObjectName(QString::fromUtf8("btnGainDMinus10"));
        btnGainDMinus10->setFont(font);

        horizontalLayout_8->addWidget(btnGainDMinus10);

        btnGainDPlus10 = new QPushButton(tabTune);
        btnGainDPlus10->setObjectName(QString::fromUtf8("btnGainDPlus10"));
        btnGainDPlus10->setFont(font);

        horizontalLayout_8->addWidget(btnGainDPlus10);


        vlGainD->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        btnGainDMinus100 = new QPushButton(tabTune);
        btnGainDMinus100->setObjectName(QString::fromUtf8("btnGainDMinus100"));
        btnGainDMinus100->setFont(font);

        horizontalLayout_7->addWidget(btnGainDMinus100);

        btnGainDPlus100 = new QPushButton(tabTune);
        btnGainDPlus100->setObjectName(QString::fromUtf8("btnGainDPlus100"));
        btnGainDPlus100->setFont(font);

        horizontalLayout_7->addWidget(btnGainDPlus100);


        vlGainD->addLayout(horizontalLayout_7);


        horizontalLayout->addLayout(vlGainD);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        cbClosedLoop = new QCheckBox(tabTune);
        cbClosedLoop->setObjectName(QString::fromUtf8("cbClosedLoop"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(cbClosedLoop->sizePolicy().hasHeightForWidth());
        cbClosedLoop->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(cbClosedLoop);


        verticalLayout_3->addLayout(verticalLayout_2);

        tabWidget->addTab(tabTune, QString());
        tabTiming = new QWidget();
        tabTiming->setObjectName(QString::fromUtf8("tabTiming"));
        verticalLayout_5 = new QVBoxLayout(tabTiming);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        lblLoopTimer = new QLabel(tabTiming);
        lblLoopTimer->setObjectName(QString::fromUtf8("lblLoopTimer"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        lblLoopTimer->setFont(font2);
        lblLoopTimer->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lblLoopTimer);

        grphControlTime = new QChartView(tabTiming);
        grphControlTime->setObjectName(QString::fromUtf8("grphControlTime"));
        sizePolicy1.setHeightForWidth(grphControlTime->sizePolicy().hasHeightForWidth());
        grphControlTime->setSizePolicy(sizePolicy1);

        verticalLayout_5->addWidget(grphControlTime);

        label = new QLabel(tabTiming);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label);

        grphIdleTime = new QChartView(tabTiming);
        grphIdleTime->setObjectName(QString::fromUtf8("grphIdleTime"));
        sizePolicy1.setHeightForWidth(grphIdleTime->sizePolicy().hasHeightForWidth());
        grphIdleTime->setSizePolicy(sizePolicy1);

        verticalLayout_5->addWidget(grphIdleTime);

        tabWidget->addTab(tabTiming, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_6 = new QVBoxLayout(tab);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        grphAngleData = new QChartView(tab);
        grphAngleData->setObjectName(QString::fromUtf8("grphAngleData"));
        sizePolicy.setHeightForWidth(grphAngleData->sizePolicy().hasHeightForWidth());
        grphAngleData->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(grphAngleData);

        grphPIDData = new QChartView(tab);
        grphPIDData->setObjectName(QString::fromUtf8("grphPIDData"));
        sizePolicy.setHeightForWidth(grphPIDData->sizePolicy().hasHeightForWidth());
        grphPIDData->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(grphPIDData);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        lblPort->setText(QCoreApplication::translate("MainWindow", "Serial Port:", nullptr));
        lblStatusText->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        lblStatusValue->setText(QCoreApplication::translate("MainWindow", "Disconnected", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSerial), QCoreApplication::translate("MainWindow", "Serial", nullptr));
        lblGainPName->setText(QCoreApplication::translate("MainWindow", "<b>Gain P</b>", nullptr));
        lblGainPValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnGainPMinus001->setText(QCoreApplication::translate("MainWindow", "-0.01", nullptr));
        btnGainPPlus001->setText(QCoreApplication::translate("MainWindow", "+0.01", nullptr));
        btnGainPMinus01->setText(QCoreApplication::translate("MainWindow", "-0.1", nullptr));
        btnGainPPlus01->setText(QCoreApplication::translate("MainWindow", "+0.1", nullptr));
        btnGainPMinus10->setText(QCoreApplication::translate("MainWindow", "-1.0", nullptr));
        btnGainPPlus10->setText(QCoreApplication::translate("MainWindow", "+1.0", nullptr));
        btnGainPMinus100->setText(QCoreApplication::translate("MainWindow", "-10.0", nullptr));
        btnGainPPlus100->setText(QCoreApplication::translate("MainWindow", "+10.0", nullptr));
        lblGainIName->setText(QCoreApplication::translate("MainWindow", "<b>Gain I</b>", nullptr));
        lblGainIValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnGainIMinus001->setText(QCoreApplication::translate("MainWindow", "-0.01", nullptr));
        btnGainIPlus001->setText(QCoreApplication::translate("MainWindow", "+0.01", nullptr));
        btnGainIMinus01->setText(QCoreApplication::translate("MainWindow", "-0.1", nullptr));
        btnGainIPlus01->setText(QCoreApplication::translate("MainWindow", "+0.1", nullptr));
        btnGainIMinus10->setText(QCoreApplication::translate("MainWindow", "-1.0", nullptr));
        btnGainIPlus10->setText(QCoreApplication::translate("MainWindow", "+1.0", nullptr));
        btnGainIMinus100->setText(QCoreApplication::translate("MainWindow", "-10.0", nullptr));
        btnGainIPlus100->setText(QCoreApplication::translate("MainWindow", "+10.0", nullptr));
        lblGainDName->setText(QCoreApplication::translate("MainWindow", "<b>Gain D</b>", nullptr));
        lblGainDValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnGainDMinus001->setText(QCoreApplication::translate("MainWindow", "-0.01", nullptr));
        btnGainDPlus001->setText(QCoreApplication::translate("MainWindow", "+0.01", nullptr));
        btnGainDMinus01->setText(QCoreApplication::translate("MainWindow", "-0.1", nullptr));
        btnGainDPlus01->setText(QCoreApplication::translate("MainWindow", "+0.1", nullptr));
        btnGainDMinus10->setText(QCoreApplication::translate("MainWindow", "-1.0", nullptr));
        btnGainDPlus10->setText(QCoreApplication::translate("MainWindow", "+1.0", nullptr));
        btnGainDMinus100->setText(QCoreApplication::translate("MainWindow", "-10.0", nullptr));
        btnGainDPlus100->setText(QCoreApplication::translate("MainWindow", "+10.0", nullptr));
        cbClosedLoop->setText(QCoreApplication::translate("MainWindow", "Closed Loop", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTune), QCoreApplication::translate("MainWindow", "Tune", nullptr));
        lblLoopTimer->setText(QCoreApplication::translate("MainWindow", "Control Loop Time (us)", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Idle Loop Time (us)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTiming), QCoreApplication::translate("MainWindow", "Timing", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Graphs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

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
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *vlLoopTimer;
    QLabel *lblLoopTimer;
    QChartView *grphControlTime;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QChartView *grphIdleTime;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *vlGainP;
    QLabel *lblGainPName;
    QLabel *lblGainPValue;
    QHBoxLayout *hlGainP;
    QPushButton *btnGainPMinus;
    QPushButton *btnGainPPlus;
    QVBoxLayout *vlGainI;
    QLabel *lblGainIName;
    QLabel *lblGainIValue;
    QHBoxLayout *hlGainI;
    QPushButton *btnGainIMinus;
    QPushButton *btnGainIPlus;
    QVBoxLayout *vlGainD;
    QLabel *lblGainDName;
    QLabel *lblGainDValue;
    QHBoxLayout *hlGainD;
    QPushButton *btnGainDMinus;
    QPushButton *btnGainDPlus;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *cbClosedLoop;
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
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
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
        verticalLayout_3 = new QVBoxLayout(tabTune);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        vlLoopTimer = new QVBoxLayout();
        vlLoopTimer->setSpacing(6);
        vlLoopTimer->setObjectName(QString::fromUtf8("vlLoopTimer"));
        lblLoopTimer = new QLabel(tabTune);
        lblLoopTimer->setObjectName(QString::fromUtf8("lblLoopTimer"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lblLoopTimer->setFont(font);
        lblLoopTimer->setAlignment(Qt::AlignCenter);

        vlLoopTimer->addWidget(lblLoopTimer);

        grphControlTime = new QChartView(tabTune);
        grphControlTime->setObjectName(QString::fromUtf8("grphControlTime"));

        vlLoopTimer->addWidget(grphControlTime);


        horizontalLayout_3->addLayout(vlLoopTimer);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label = new QLabel(tabTune);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label);

        grphIdleTime = new QChartView(tabTune);
        grphIdleTime->setObjectName(QString::fromUtf8("grphIdleTime"));

        verticalLayout_4->addWidget(grphIdleTime);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        vlGainP = new QVBoxLayout();
        vlGainP->setSpacing(6);
        vlGainP->setObjectName(QString::fromUtf8("vlGainP"));
        lblGainPName = new QLabel(tabTune);
        lblGainPName->setObjectName(QString::fromUtf8("lblGainPName"));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        lblGainPName->setFont(font1);
        lblGainPName->setScaledContents(false);
        lblGainPName->setAlignment(Qt::AlignCenter);

        vlGainP->addWidget(lblGainPName);

        lblGainPValue = new QLabel(tabTune);
        lblGainPValue->setObjectName(QString::fromUtf8("lblGainPValue"));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(false);
        font2.setWeight(50);
        lblGainPValue->setFont(font2);
        lblGainPValue->setAlignment(Qt::AlignCenter);

        vlGainP->addWidget(lblGainPValue);

        hlGainP = new QHBoxLayout();
        hlGainP->setSpacing(6);
        hlGainP->setObjectName(QString::fromUtf8("hlGainP"));
        btnGainPMinus = new QPushButton(tabTune);
        btnGainPMinus->setObjectName(QString::fromUtf8("btnGainPMinus"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnGainPMinus->sizePolicy().hasHeightForWidth());
        btnGainPMinus->setSizePolicy(sizePolicy1);
        btnGainPMinus->setFont(font1);

        hlGainP->addWidget(btnGainPMinus);

        btnGainPPlus = new QPushButton(tabTune);
        btnGainPPlus->setObjectName(QString::fromUtf8("btnGainPPlus"));
        sizePolicy1.setHeightForWidth(btnGainPPlus->sizePolicy().hasHeightForWidth());
        btnGainPPlus->setSizePolicy(sizePolicy1);
        btnGainPPlus->setFont(font1);

        hlGainP->addWidget(btnGainPPlus);


        vlGainP->addLayout(hlGainP);


        horizontalLayout->addLayout(vlGainP);

        vlGainI = new QVBoxLayout();
        vlGainI->setSpacing(6);
        vlGainI->setObjectName(QString::fromUtf8("vlGainI"));
        lblGainIName = new QLabel(tabTune);
        lblGainIName->setObjectName(QString::fromUtf8("lblGainIName"));
        lblGainIName->setFont(font1);
        lblGainIName->setScaledContents(false);
        lblGainIName->setAlignment(Qt::AlignCenter);

        vlGainI->addWidget(lblGainIName);

        lblGainIValue = new QLabel(tabTune);
        lblGainIValue->setObjectName(QString::fromUtf8("lblGainIValue"));
        lblGainIValue->setFont(font2);
        lblGainIValue->setAlignment(Qt::AlignCenter);

        vlGainI->addWidget(lblGainIValue);

        hlGainI = new QHBoxLayout();
        hlGainI->setSpacing(6);
        hlGainI->setObjectName(QString::fromUtf8("hlGainI"));
        btnGainIMinus = new QPushButton(tabTune);
        btnGainIMinus->setObjectName(QString::fromUtf8("btnGainIMinus"));
        sizePolicy1.setHeightForWidth(btnGainIMinus->sizePolicy().hasHeightForWidth());
        btnGainIMinus->setSizePolicy(sizePolicy1);
        btnGainIMinus->setFont(font1);

        hlGainI->addWidget(btnGainIMinus);

        btnGainIPlus = new QPushButton(tabTune);
        btnGainIPlus->setObjectName(QString::fromUtf8("btnGainIPlus"));
        sizePolicy1.setHeightForWidth(btnGainIPlus->sizePolicy().hasHeightForWidth());
        btnGainIPlus->setSizePolicy(sizePolicy1);
        btnGainIPlus->setFont(font1);

        hlGainI->addWidget(btnGainIPlus);


        vlGainI->addLayout(hlGainI);


        horizontalLayout->addLayout(vlGainI);

        vlGainD = new QVBoxLayout();
        vlGainD->setSpacing(6);
        vlGainD->setObjectName(QString::fromUtf8("vlGainD"));
        lblGainDName = new QLabel(tabTune);
        lblGainDName->setObjectName(QString::fromUtf8("lblGainDName"));
        lblGainDName->setFont(font1);
        lblGainDName->setScaledContents(false);
        lblGainDName->setAlignment(Qt::AlignCenter);

        vlGainD->addWidget(lblGainDName);

        lblGainDValue = new QLabel(tabTune);
        lblGainDValue->setObjectName(QString::fromUtf8("lblGainDValue"));
        lblGainDValue->setFont(font2);
        lblGainDValue->setAlignment(Qt::AlignCenter);

        vlGainD->addWidget(lblGainDValue);

        hlGainD = new QHBoxLayout();
        hlGainD->setSpacing(6);
        hlGainD->setObjectName(QString::fromUtf8("hlGainD"));
        btnGainDMinus = new QPushButton(tabTune);
        btnGainDMinus->setObjectName(QString::fromUtf8("btnGainDMinus"));
        sizePolicy1.setHeightForWidth(btnGainDMinus->sizePolicy().hasHeightForWidth());
        btnGainDMinus->setSizePolicy(sizePolicy1);
        btnGainDMinus->setFont(font1);

        hlGainD->addWidget(btnGainDMinus);

        btnGainDPlus = new QPushButton(tabTune);
        btnGainDPlus->setObjectName(QString::fromUtf8("btnGainDPlus"));
        sizePolicy1.setHeightForWidth(btnGainDPlus->sizePolicy().hasHeightForWidth());
        btnGainDPlus->setSizePolicy(sizePolicy1);
        btnGainDPlus->setFont(font1);

        hlGainD->addWidget(btnGainDPlus);


        vlGainD->addLayout(hlGainD);


        horizontalLayout->addLayout(vlGainD);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        cbClosedLoop = new QCheckBox(tabTune);
        cbClosedLoop->setObjectName(QString::fromUtf8("cbClosedLoop"));

        verticalLayout_2->addWidget(cbClosedLoop);

        grphAngleData = new QChartView(tabTune);
        grphAngleData->setObjectName(QString::fromUtf8("grphAngleData"));

        verticalLayout_2->addWidget(grphAngleData);

        grphPIDData = new QChartView(tabTune);
        grphPIDData->setObjectName(QString::fromUtf8("grphPIDData"));

        verticalLayout_2->addWidget(grphPIDData);


        verticalLayout_3->addLayout(verticalLayout_2);

        tabWidget->addTab(tabTune, QString());

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
        lblLoopTimer->setText(QCoreApplication::translate("MainWindow", "Control Loop Time (us)", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Idle Loop Time (us)", nullptr));
        lblGainPName->setText(QCoreApplication::translate("MainWindow", "<b>Gain P</b>", nullptr));
        lblGainPValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnGainPMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        btnGainPPlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        lblGainIName->setText(QCoreApplication::translate("MainWindow", "<b>Gain I</b>", nullptr));
        lblGainIValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnGainIMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        btnGainIPlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        lblGainDName->setText(QCoreApplication::translate("MainWindow", "<b>Gain D</b>", nullptr));
        lblGainDValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnGainDMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        btnGainDPlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        cbClosedLoop->setText(QCoreApplication::translate("MainWindow", "Closed Loop", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTune), QCoreApplication::translate("MainWindow", "Tune", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

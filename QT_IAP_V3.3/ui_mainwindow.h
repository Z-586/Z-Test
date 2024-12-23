/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "softupdata.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_help;
    QAction *actionSetting;
    QAction *action_TempCali;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    softupdata *updata;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *RefreshCanCard;
    QComboBox *CanCardInfo;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioButtonStatus;
    QPushButton *pushButtonConnect;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(873, 495);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/picture/myico.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAnimated(false);
        MainWindow->setDockNestingEnabled(false);
        action_help = new QAction(MainWindow);
        action_help->setObjectName(QString::fromUtf8("action_help"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/picture/help.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        action_help->setIcon(icon1);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        action_help->setFont(font);
        actionSetting = new QAction(MainWindow);
        actionSetting->setObjectName(QString::fromUtf8("actionSetting"));
        actionSetting->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/picture/set.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetting->setIcon(icon2);
        actionSetting->setFont(font);
        actionSetting->setAutoRepeat(true);
        actionSetting->setVisible(true);
        action_TempCali = new QAction(MainWindow);
        action_TempCali->setObjectName(QString::fromUtf8("action_TempCali"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/picture/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_TempCali->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        tabWidget->setFont(font1);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        updata = new softupdata(tab);
        updata->setObjectName(QString::fromUtf8("updata"));
        horizontalLayout_4 = new QHBoxLayout(updata);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));

        horizontalLayout_2->addWidget(updata);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        RefreshCanCard = new QPushButton(centralWidget);
        RefreshCanCard->setObjectName(QString::fromUtf8("RefreshCanCard"));

        horizontalLayout->addWidget(RefreshCanCard);

        CanCardInfo = new QComboBox(centralWidget);
        CanCardInfo->addItem(QString());
        CanCardInfo->setObjectName(QString::fromUtf8("CanCardInfo"));
        CanCardInfo->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(CanCardInfo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        radioButtonStatus = new QRadioButton(centralWidget);
        radioButtonStatus->setObjectName(QString::fromUtf8("radioButtonStatus"));
        radioButtonStatus->setEnabled(false);
        radioButtonStatus->setAutoFillBackground(true);
        radioButtonStatus->setAutoExclusive(false);

        horizontalLayout->addWidget(radioButtonStatus);

        pushButtonConnect = new QPushButton(centralWidget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));
        QFont font2;
        font2.setPointSize(12);
        pushButtonConnect->setFont(font2);

        horizontalLayout->addWidget(pushButtonConnect);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setFont(font);
        toolBar->setIconSize(QSize(40, 40));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionSetting);
        toolBar->addAction(action_help);
        toolBar->addAction(action_TempCali);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        CanCardInfo->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "IAP\345\233\272\344\273\266\345\215\207\347\272\247_V2.1(2020-06-07)", nullptr));
        action_help->setText(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251\346\226\207\346\241\243\n"
"", nullptr));
        actionSetting->setText(QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        actionSetting->setToolTip(QCoreApplication::translate("MainWindow", "Setting", nullptr));
#endif // QT_CONFIG(tooltip)
        action_TempCali->setText(QCoreApplication::translate("MainWindow", "\346\240\207\345\256\232\345\206\231\345\205\245", nullptr));
#if QT_CONFIG(tooltip)
        action_TempCali->setToolTip(QCoreApplication::translate("MainWindow", "\346\270\251\345\272\246\346\240\207\345\256\232\345\206\231\345\205\245", nullptr));
#endif // QT_CONFIG(tooltip)
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\345\233\272\344\273\266\345\215\207\347\272\247", nullptr));
        RefreshCanCard->setText(QCoreApplication::translate("MainWindow", "\346\233\264\346\226\260CAN\345\210\227\350\241\250", nullptr));
        CanCardInfo->setItemText(0, QString());

        radioButtonStatus->setText(QString());
        pushButtonConnect->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

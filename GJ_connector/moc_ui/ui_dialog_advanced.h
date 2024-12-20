/********************************************************************************
** Form generated from reading UI file 'dialog_advanced.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ADVANCED_H
#define UI_DIALOG_ADVANCED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Dialog_advanced
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox_rtcm_select;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QFrame *frameEthernet;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *lineEditAccountNumber;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QLineEdit *lineEditAccountPassword;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QLineEdit *lineEdit_port;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_IP1;
    QLabel *label_4;
    QLineEdit *lineEdit_IP2;
    QLabel *label_5;
    QLineEdit *lineEdit_IP3;
    QLabel *label_6;
    QLineEdit *lineEdit_IP4;
    QCheckBox *checkBoxETH_enable;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QPushButton *btnRead;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *Dialog_advanced)
    {
        if (Dialog_advanced->objectName().isEmpty())
            Dialog_advanced->setObjectName(QString::fromUtf8("Dialog_advanced"));
        Dialog_advanced->resize(572, 433);
        Dialog_advanced->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: rgb(250, 250, 250);\n"
"}\n"
"QPushButton{\n"
"	background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9,\n"
"		stop:0.494318 rgba(214, 214, 214, 255), stop:0.5 rgba(236, 236, 236, 255));\n"
"	border: 1px solid rgb(124, 124, 124);\n"
"	border-radius:2px;\n"
"}\n"
"QPushButton:hover{\n"
"background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9,\n"
"	stop:0.494318 rgba(181, 225, 250, 255), stop:0.5 rgba(222, 242, 251, 255));\n"
"border: 1px solid #3C80B1;\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9,\n"
"		stop:0.494318 rgba(134, 198, 233, 255), stop:0.5 rgba(206, 234, 248, 255));\n"
"	border: 1px solid #5F92B2;\n"
"}\n"
"\n"
"\n"
""));
        gridLayout_3 = new QGridLayout(Dialog_advanced);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(Dialog_advanced);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font;
        font.setPointSize(15);
        groupBox->setFont(font);
        groupBox->setAlignment(Qt::AlignCenter);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        comboBox_rtcm_select = new QComboBox(groupBox);
        comboBox_rtcm_select->addItem(QString());
        comboBox_rtcm_select->addItem(QString());
        comboBox_rtcm_select->addItem(QString());
        comboBox_rtcm_select->setObjectName(QString::fromUtf8("comboBox_rtcm_select"));
        comboBox_rtcm_select->setStyleSheet(QString::fromUtf8("/* \346\234\252\344\270\213\346\213\211\346\227\266\357\274\214QComboBox\347\232\204\346\240\267\345\274\217 */\n"
"QComboBox {\n"
"    border: 1px solid gray;   /* \350\276\271\346\241\206 */\n"
"    border-radius: 3px;   /* \345\234\206\350\247\222 */\n"
"    padding: 1px 18px 1px 3px;   /* \345\255\227\344\275\223\345\241\253\350\241\254 */\n"
"    color: #000;\n"
"    font: normal normal 15px \"Microsoft YaHei\";\n"
"    background: transparent;\n"
"}\n"
"\n"
"/* \344\270\213\346\213\211\345\220\216\357\274\214\346\225\264\344\270\252\344\270\213\346\213\211\347\252\227\344\275\223\346\240\267\345\274\217 */\n"
"QComboBox QAbstractItemView {\n"
"    outline: 0px solid gray;   /* \351\200\211\345\256\232\351\241\271\347\232\204\350\231\232\346\241\206 */\n"
"}"));

        gridLayout_2->addWidget(comboBox_rtcm_select, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(100, 0));

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setTextFormat(Qt::AutoText);

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        frameEthernet = new QFrame(Dialog_advanced);
        frameEthernet->setObjectName(QString::fromUtf8("frameEthernet"));
        frameEthernet->setFrameShape(QFrame::StyledPanel);
        frameEthernet->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frameEthernet);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(frameEthernet);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        lineEditAccountNumber = new QLineEdit(frameEthernet);
        lineEditAccountNumber->setObjectName(QString::fromUtf8("lineEditAccountNumber"));

        horizontalLayout_4->addWidget(lineEditAccountNumber);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_8 = new QLabel(frameEthernet);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_5->addWidget(label_8);

        lineEditAccountPassword = new QLineEdit(frameEthernet);
        lineEditAccountPassword->setObjectName(QString::fromUtf8("lineEditAccountPassword"));

        horizontalLayout_5->addWidget(lineEditAccountPassword);


        gridLayout->addLayout(horizontalLayout_5, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_7 = new QLabel(frameEthernet);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font1;
        font1.setPointSize(11);
        label_7->setFont(font1);

        horizontalLayout_2->addWidget(label_7);

        lineEdit_port = new QLineEdit(frameEthernet);
        lineEdit_port->setObjectName(QString::fromUtf8("lineEdit_port"));

        horizontalLayout_2->addWidget(lineEdit_port);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(frameEthernet);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout->addWidget(label_3);

        lineEdit_IP1 = new QLineEdit(frameEthernet);
        lineEdit_IP1->setObjectName(QString::fromUtf8("lineEdit_IP1"));
        QFont font2;
        font2.setPointSize(12);
        lineEdit_IP1->setFont(font2);

        horizontalLayout->addWidget(lineEdit_IP1);

        label_4 = new QLabel(frameEthernet);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        label_4->setFont(font3);

        horizontalLayout->addWidget(label_4);

        lineEdit_IP2 = new QLineEdit(frameEthernet);
        lineEdit_IP2->setObjectName(QString::fromUtf8("lineEdit_IP2"));
        lineEdit_IP2->setFont(font2);

        horizontalLayout->addWidget(lineEdit_IP2);

        label_5 = new QLabel(frameEthernet);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font3);

        horizontalLayout->addWidget(label_5);

        lineEdit_IP3 = new QLineEdit(frameEthernet);
        lineEdit_IP3->setObjectName(QString::fromUtf8("lineEdit_IP3"));
        lineEdit_IP3->setFont(font2);

        horizontalLayout->addWidget(lineEdit_IP3);

        label_6 = new QLabel(frameEthernet);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font3);

        horizontalLayout->addWidget(label_6);

        lineEdit_IP4 = new QLineEdit(frameEthernet);
        lineEdit_IP4->setObjectName(QString::fromUtf8("lineEdit_IP4"));
        lineEdit_IP4->setFont(font2);

        horizontalLayout->addWidget(lineEdit_IP4);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        checkBoxETH_enable = new QCheckBox(frameEthernet);
        checkBoxETH_enable->setObjectName(QString::fromUtf8("checkBoxETH_enable"));

        gridLayout->addWidget(checkBoxETH_enable, 0, 0, 1, 1);

        frame = new QFrame(frameEthernet);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        btnRead = new QPushButton(frame);
        btnRead->setObjectName(QString::fromUtf8("btnRead"));

        gridLayout_4->addWidget(btnRead, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(400, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 0, 0, 1, 1);


        gridLayout->addWidget(frame, 5, 0, 1, 1);


        gridLayout_3->addWidget(frameEthernet, 1, 0, 1, 1);


        retranslateUi(Dialog_advanced);

        QMetaObject::connectSlotsByName(Dialog_advanced);
    } // setupUi

    void retranslateUi(QDialog *Dialog_advanced)
    {
        Dialog_advanced->setWindowTitle(QCoreApplication::translate("Dialog_advanced", "\351\253\230\347\272\247\345\212\237\350\203\275", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog_advanced", "\345\267\256\345\210\206\346\263\250\345\205\245\351\200\211\346\213\251", nullptr));
        comboBox_rtcm_select->setItemText(0, QCoreApplication::translate("Dialog_advanced", "\345\206\205\347\275\256DTU", nullptr));
        comboBox_rtcm_select->setItemText(1, QCoreApplication::translate("Dialog_advanced", "\345\244\226\347\275\256", nullptr));
        comboBox_rtcm_select->setItemText(2, QCoreApplication::translate("Dialog_advanced", "Ethernet", nullptr));

        pushButton->setText(QCoreApplication::translate("Dialog_advanced", "\345\272\224\347\224\250", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog_advanced", "\350\257\245\345\212\237\350\203\275\344\273\205\351\200\202\347\224\250\344\272\216GJ_A660\343\200\201GJA920\344\272\247\345\223\201", nullptr));
        label->setText(QCoreApplication::translate("Dialog_advanced", "\345\267\256\345\210\206\350\264\246\345\217\267", nullptr));
        label_8->setText(QCoreApplication::translate("Dialog_advanced", "\350\264\246\345\217\267\345\257\206\347\240\201", nullptr));
        label_7->setText(QCoreApplication::translate("Dialog_advanced", "\347\253\257\345\217\243\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog_advanced", "\351\235\231\346\200\201IP", nullptr));
        lineEdit_IP1->setText(QString());
        label_4->setText(QCoreApplication::translate("Dialog_advanced", ".", nullptr));
        lineEdit_IP2->setText(QString());
        label_5->setText(QCoreApplication::translate("Dialog_advanced", ".", nullptr));
        lineEdit_IP3->setText(QString());
        label_6->setText(QCoreApplication::translate("Dialog_advanced", ".", nullptr));
        lineEdit_IP4->setText(QString());
        checkBoxETH_enable->setText(QCoreApplication::translate("Dialog_advanced", "Enble", nullptr));
        btnRead->setText(QCoreApplication::translate("Dialog_advanced", "\350\257\273\345\217\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_advanced: public Ui_Dialog_advanced {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ADVANCED_H

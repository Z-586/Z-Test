/********************************************************************************
** Form generated from reading UI file 'dlg_ipconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_IPCONFIG_H
#define UI_DLG_IPCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_dlg_ipConfig
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_IP1;
    QLabel *label_4;
    QLineEdit *lineEdit_IP2;
    QLabel *label_5;
    QLineEdit *lineEdit_IP3;
    QLabel *label_6;
    QLineEdit *lineEdit_IP4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_port;
    QPushButton *pushButton_sendIP;

    void setupUi(QDialog *dlg_ipConfig)
    {
        if (dlg_ipConfig->objectName().isEmpty())
            dlg_ipConfig->setObjectName(QString::fromUtf8("dlg_ipConfig"));
        dlg_ipConfig->resize(460, 117);
        gridLayout = new QGridLayout(dlg_ipConfig);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(dlg_ipConfig);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(11);
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        lineEdit_IP1 = new QLineEdit(dlg_ipConfig);
        lineEdit_IP1->setObjectName(QString::fromUtf8("lineEdit_IP1"));
        QFont font1;
        font1.setPointSize(12);
        lineEdit_IP1->setFont(font1);

        horizontalLayout->addWidget(lineEdit_IP1);

        label_4 = new QLabel(dlg_ipConfig);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        label_4->setFont(font2);

        horizontalLayout->addWidget(label_4);

        lineEdit_IP2 = new QLineEdit(dlg_ipConfig);
        lineEdit_IP2->setObjectName(QString::fromUtf8("lineEdit_IP2"));
        lineEdit_IP2->setFont(font1);

        horizontalLayout->addWidget(lineEdit_IP2);

        label_5 = new QLabel(dlg_ipConfig);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);

        horizontalLayout->addWidget(label_5);

        lineEdit_IP3 = new QLineEdit(dlg_ipConfig);
        lineEdit_IP3->setObjectName(QString::fromUtf8("lineEdit_IP3"));
        lineEdit_IP3->setFont(font1);

        horizontalLayout->addWidget(lineEdit_IP3);

        label_6 = new QLabel(dlg_ipConfig);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        horizontalLayout->addWidget(label_6);

        lineEdit_IP4 = new QLineEdit(dlg_ipConfig);
        lineEdit_IP4->setObjectName(QString::fromUtf8("lineEdit_IP4"));
        lineEdit_IP4->setFont(font1);

        horizontalLayout->addWidget(lineEdit_IP4);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_7 = new QLabel(dlg_ipConfig);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        horizontalLayout_2->addWidget(label_7);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        lineEdit_port = new QLineEdit(dlg_ipConfig);
        lineEdit_port->setObjectName(QString::fromUtf8("lineEdit_port"));

        horizontalLayout_2->addWidget(lineEdit_port);

        pushButton_sendIP = new QPushButton(dlg_ipConfig);
        pushButton_sendIP->setObjectName(QString::fromUtf8("pushButton_sendIP"));

        horizontalLayout_2->addWidget(pushButton_sendIP);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        retranslateUi(dlg_ipConfig);

        QMetaObject::connectSlotsByName(dlg_ipConfig);
    } // setupUi

    void retranslateUi(QDialog *dlg_ipConfig)
    {
        dlg_ipConfig->setWindowTitle(QCoreApplication::translate("dlg_ipConfig", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("dlg_ipConfig", "\351\235\231\346\200\201IP", nullptr));
        lineEdit_IP1->setText(QString());
        label_4->setText(QCoreApplication::translate("dlg_ipConfig", ".", nullptr));
        lineEdit_IP2->setText(QString());
        label_5->setText(QCoreApplication::translate("dlg_ipConfig", ".", nullptr));
        lineEdit_IP3->setText(QString());
        label_6->setText(QCoreApplication::translate("dlg_ipConfig", ".", nullptr));
        lineEdit_IP4->setText(QString());
        label_7->setText(QCoreApplication::translate("dlg_ipConfig", "\347\253\257\345\217\243\345\217\267", nullptr));
        pushButton_sendIP->setText(QCoreApplication::translate("dlg_ipConfig", "IP\345\222\214\347\253\257\345\217\243\351\205\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlg_ipConfig: public Ui_dlg_ipConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_IPCONFIG_H

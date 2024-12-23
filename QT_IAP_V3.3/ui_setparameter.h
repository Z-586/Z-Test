/********************************************************************************
** Form generated from reading UI file 'setparameter.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPARAMETER_H
#define UI_SETPARAMETER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_setParameter
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *setportNumberList;
    QLabel *label_2;
    QComboBox *uart_baudRate;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QLabel *label_10;
    QComboBox *comboBox_10;
    QLabel *label_4;
    QComboBox *comboBox_4;
    QLabel *label_5;
    QComboBox *uartCheckSum;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_15;
    QSpinBox *rs485Addr;
    QRadioButton *radioButton_Uart;
    QRadioButton *rs485En;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QLabel *label_7;
    QComboBox *canChannels;
    QLabel *label_6;
    QComboBox *can_baudRate;
    QLabel *label_13;
    QComboBox *can_device;
    QLabel *label_16;
    QSpinBox *spinBox_2;
    QSpacerItem *verticalSpacer_4;
    QRadioButton *radioButton_Can;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout_3;
    QLabel *label_8;
    QSpinBox *AnswerTimeOut;
    QRadioButton *CodMode;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *setParameter)
    {
        if (setParameter->objectName().isEmpty())
            setParameter->setObjectName(QString::fromUtf8("setParameter"));
        setParameter->resize(641, 348);
        horizontalLayout = new QHBoxLayout(setParameter);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(setParameter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        setportNumberList = new QComboBox(groupBox);
        setportNumberList->setObjectName(QString::fromUtf8("setportNumberList"));

        formLayout->setWidget(0, QFormLayout::FieldRole, setportNumberList);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        uart_baudRate = new QComboBox(groupBox);
        uart_baudRate->addItem(QString());
        uart_baudRate->addItem(QString());
        uart_baudRate->addItem(QString());
        uart_baudRate->addItem(QString());
        uart_baudRate->addItem(QString());
        uart_baudRate->addItem(QString());
        uart_baudRate->addItem(QString());
        uart_baudRate->addItem(QString());
        uart_baudRate->setObjectName(QString::fromUtf8("uart_baudRate"));
        uart_baudRate->setEnabled(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, uart_baudRate);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setEnabled(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox_3);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_10);

        comboBox_10 = new QComboBox(groupBox);
        comboBox_10->addItem(QString());
        comboBox_10->setObjectName(QString::fromUtf8("comboBox_10"));
        comboBox_10->setEnabled(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBox_10);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        comboBox_4 = new QComboBox(groupBox);
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setEnabled(false);

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBox_4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        uartCheckSum = new QComboBox(groupBox);
        uartCheckSum->addItem(QString());
        uartCheckSum->addItem(QString());
        uartCheckSum->addItem(QString());
        uartCheckSum->setObjectName(QString::fromUtf8("uartCheckSum"));
        uartCheckSum->setEnabled(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, uartCheckSum);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(6, QFormLayout::FieldRole, verticalSpacer_3);

        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_15);

        rs485Addr = new QSpinBox(groupBox);
        rs485Addr->setObjectName(QString::fromUtf8("rs485Addr"));

        formLayout->setWidget(7, QFormLayout::FieldRole, rs485Addr);


        verticalLayout->addWidget(groupBox);

        radioButton_Uart = new QRadioButton(setParameter);
        radioButton_Uart->setObjectName(QString::fromUtf8("radioButton_Uart"));
        radioButton_Uart->setChecked(true);

        verticalLayout->addWidget(radioButton_Uart);

        rs485En = new QRadioButton(setParameter);
        rs485En->setObjectName(QString::fromUtf8("rs485En"));

        verticalLayout->addWidget(rs485En);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox_2 = new QGroupBox(setParameter);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(180, 0));
        formLayout_2 = new QFormLayout(groupBox_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_7);

        canChannels = new QComboBox(groupBox_2);
        canChannels->addItem(QString());
        canChannels->addItem(QString());
        canChannels->setObjectName(QString::fromUtf8("canChannels"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, canChannels);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_6);

        can_baudRate = new QComboBox(groupBox_2);
        can_baudRate->addItem(QString());
        can_baudRate->addItem(QString());
        can_baudRate->addItem(QString());
        can_baudRate->addItem(QString());
        can_baudRate->addItem(QString());
        can_baudRate->addItem(QString());
        can_baudRate->setObjectName(QString::fromUtf8("can_baudRate"));
        can_baudRate->setEnabled(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, can_baudRate);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_13);

        can_device = new QComboBox(groupBox_2);
        can_device->addItem(QString());
        can_device->addItem(QString());
        can_device->setObjectName(QString::fromUtf8("can_device"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, can_device);

        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_16);

        spinBox_2 = new QSpinBox(groupBox_2);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, spinBox_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(3, QFormLayout::FieldRole, verticalSpacer_4);


        verticalLayout_4->addWidget(groupBox_2);

        radioButton_Can = new QRadioButton(setParameter);
        radioButton_Can->setObjectName(QString::fromUtf8("radioButton_Can"));

        verticalLayout_4->addWidget(radioButton_Can);


        horizontalLayout->addLayout(verticalLayout_4);

        groupBox_3 = new QGroupBox(setParameter);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        formLayout_3 = new QFormLayout(groupBox_3);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_8);

        AnswerTimeOut = new QSpinBox(groupBox_3);
        AnswerTimeOut->setObjectName(QString::fromUtf8("AnswerTimeOut"));
        AnswerTimeOut->setMinimum(10);
        AnswerTimeOut->setMaximum(10000);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, AnswerTimeOut);

        CodMode = new QRadioButton(groupBox_3);
        CodMode->setObjectName(QString::fromUtf8("CodMode"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, CodMode);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_3->setItem(2, QFormLayout::LabelRole, verticalSpacer);


        horizontalLayout->addWidget(groupBox_3);


        retranslateUi(setParameter);

        QMetaObject::connectSlotsByName(setParameter);
    } // setupUi

    void retranslateUi(QDialog *setParameter)
    {
        setParameter->setWindowTitle(QCoreApplication::translate("setParameter", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("setParameter", "\344\270\262\345\217\243", nullptr));
        label->setText(QCoreApplication::translate("setParameter", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("setParameter", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        uart_baudRate->setItemText(0, QCoreApplication::translate("setParameter", "115200", nullptr));
        uart_baudRate->setItemText(1, QCoreApplication::translate("setParameter", "57600", nullptr));
        uart_baudRate->setItemText(2, QCoreApplication::translate("setParameter", "38400", nullptr));
        uart_baudRate->setItemText(3, QCoreApplication::translate("setParameter", "19200", nullptr));
        uart_baudRate->setItemText(4, QCoreApplication::translate("setParameter", "9600", nullptr));
        uart_baudRate->setItemText(5, QCoreApplication::translate("setParameter", "4800", nullptr));
        uart_baudRate->setItemText(6, QCoreApplication::translate("setParameter", "2400", nullptr));
        uart_baudRate->setItemText(7, QCoreApplication::translate("setParameter", "1200", nullptr));

        label_3->setText(QCoreApplication::translate("setParameter", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("setParameter", "8", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("setParameter", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));

        label_10->setText(QCoreApplication::translate("setParameter", "\350\265\267\345\247\213\344\275\215\357\274\232", nullptr));
        comboBox_10->setItemText(0, QCoreApplication::translate("setParameter", "1", nullptr));

        label_4->setText(QCoreApplication::translate("setParameter", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("setParameter", "1", nullptr));

        label_5->setText(QCoreApplication::translate("setParameter", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        uartCheckSum->setItemText(0, QCoreApplication::translate("setParameter", "\346\227\240\346\240\241\351\252\214", nullptr));
        uartCheckSum->setItemText(1, QCoreApplication::translate("setParameter", "\345\245\207\346\240\241\351\252\214", nullptr));
        uartCheckSum->setItemText(2, QCoreApplication::translate("setParameter", "\345\201\266\346\240\241\351\252\214", nullptr));

        label_15->setText(QCoreApplication::translate("setParameter", "485\345\234\260\345\235\200\357\274\232", nullptr));
        radioButton_Uart->setText(QCoreApplication::translate("setParameter", "\344\270\262\345\217\243\345\215\207\347\272\247", nullptr));
        rs485En->setText(QCoreApplication::translate("setParameter", "RS485\345\215\207\347\272\247", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("setParameter", "CAN", nullptr));
        label_7->setText(QCoreApplication::translate("setParameter", "CAN\351\200\232\351\201\223\357\274\232", nullptr));
        canChannels->setItemText(0, QCoreApplication::translate("setParameter", "1", nullptr));
        canChannels->setItemText(1, QCoreApplication::translate("setParameter", "2", nullptr));

        label_6->setText(QCoreApplication::translate("setParameter", "\346\263\242\347\211\271\347\216\207(KBps)\357\274\232", nullptr));
        can_baudRate->setItemText(0, QCoreApplication::translate("setParameter", "250", nullptr));
        can_baudRate->setItemText(1, QCoreApplication::translate("setParameter", "50", nullptr));
        can_baudRate->setItemText(2, QCoreApplication::translate("setParameter", "100", nullptr));
        can_baudRate->setItemText(3, QCoreApplication::translate("setParameter", "125", nullptr));
        can_baudRate->setItemText(4, QCoreApplication::translate("setParameter", "500", nullptr));
        can_baudRate->setItemText(5, QCoreApplication::translate("setParameter", "1000", nullptr));

        label_13->setText(QCoreApplication::translate("setParameter", "\350\256\276\345\244\207\357\274\232", nullptr));
        can_device->setItemText(0, QCoreApplication::translate("setParameter", "\345\210\233\350\212\257\347\247\221\346\212\200", nullptr));
        can_device->setItemText(1, QCoreApplication::translate("setParameter", "\345\221\250\347\253\213\345\212\237", nullptr));

        label_16->setText(QCoreApplication::translate("setParameter", "CAN\345\234\260\345\235\200\357\274\232", nullptr));
        radioButton_Can->setText(QCoreApplication::translate("setParameter", "CAN\346\216\245\345\217\243\345\215\207\347\272\247", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("setParameter", "\345\205\266\345\256\203\345\217\202\346\225\260", nullptr));
        label_8->setText(QCoreApplication::translate("setParameter", "\345\272\224\347\255\224\350\266\205\346\227\266\346\227\266\351\227\264\357\274\210ms\357\274\211\357\274\232", nullptr));
        CodMode->setText(QCoreApplication::translate("setParameter", "Cod\345\257\206\346\226\207\344\274\240\350\276\223", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setParameter: public Ui_setParameter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPARAMETER_H

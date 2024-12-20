/********************************************************************************
** Form generated from reading UI file 'dlg_protocol.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_PROTOCOL_H
#define UI_DLG_PROTOCOL_H

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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dlg_Protocol
{
public:
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout;
    QFrame *frameOtherProtocol;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCheckBox *CheckBox_GJ;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QCheckBox *CheckBox_GPGGA;
    QCheckBox *CheckBox_GPRMC;
    QCheckBox *CheckBox_GPVTG;
    QCheckBox *CheckBox_GPGLL;
    QCheckBox *CheckBox_GPZDA;
    QCheckBox *CheckBox_GPHDT;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QCheckBox *CheckBox_GPFPD;
    QCheckBox *CheckBox_GPCHC;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *ComboBox_Protocol_Frequency;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *ComboBox_Protocol_BaudRate;
    QGroupBox *groupBoxCustomProtocol;
    QGridLayout *gridLayout_4;
    QCheckBox *CheckBoxCustomProtocol;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditCustomProtocolName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditCustomProtocolRate;
    QFrame *frame_3;
    QGridLayout *gridLayout_6;
    QLabel *Label;
    QPushButton *PushButton_ProtocolChange;

    void setupUi(QDialog *Dlg_Protocol)
    {
        if (Dlg_Protocol->objectName().isEmpty())
            Dlg_Protocol->setObjectName(QString::fromUtf8("Dlg_Protocol"));
        Dlg_Protocol->resize(615, 721);
        QFont font;
        font.setPointSize(15);
        Dlg_Protocol->setFont(font);
        gridLayout_7 = new QGridLayout(Dlg_Protocol);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frameOtherProtocol = new QFrame(Dlg_Protocol);
        frameOtherProtocol->setObjectName(QString::fromUtf8("frameOtherProtocol"));
        frameOtherProtocol->setFrameShape(QFrame::StyledPanel);
        frameOtherProtocol->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frameOtherProtocol);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox = new QGroupBox(frameOtherProtocol);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFont(font);
        groupBox->setAlignment(Qt::AlignCenter);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        CheckBox_GJ = new QCheckBox(groupBox);
        CheckBox_GJ->setObjectName(QString::fromUtf8("CheckBox_GJ"));
        CheckBox_GJ->setChecked(true);

        gridLayout->addWidget(CheckBox_GJ, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(frameOtherProtocol);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFont(font);
        groupBox_2->setAlignment(Qt::AlignCenter);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        CheckBox_GPGGA = new QCheckBox(groupBox_2);
        CheckBox_GPGGA->setObjectName(QString::fromUtf8("CheckBox_GPGGA"));

        gridLayout_2->addWidget(CheckBox_GPGGA, 0, 0, 1, 1);

        CheckBox_GPRMC = new QCheckBox(groupBox_2);
        CheckBox_GPRMC->setObjectName(QString::fromUtf8("CheckBox_GPRMC"));

        gridLayout_2->addWidget(CheckBox_GPRMC, 1, 0, 1, 1);

        CheckBox_GPVTG = new QCheckBox(groupBox_2);
        CheckBox_GPVTG->setObjectName(QString::fromUtf8("CheckBox_GPVTG"));

        gridLayout_2->addWidget(CheckBox_GPVTG, 2, 0, 1, 1);

        CheckBox_GPGLL = new QCheckBox(groupBox_2);
        CheckBox_GPGLL->setObjectName(QString::fromUtf8("CheckBox_GPGLL"));

        gridLayout_2->addWidget(CheckBox_GPGLL, 3, 0, 1, 1);

        CheckBox_GPZDA = new QCheckBox(groupBox_2);
        CheckBox_GPZDA->setObjectName(QString::fromUtf8("CheckBox_GPZDA"));

        gridLayout_2->addWidget(CheckBox_GPZDA, 4, 0, 1, 1);

        CheckBox_GPHDT = new QCheckBox(groupBox_2);
        CheckBox_GPHDT->setObjectName(QString::fromUtf8("CheckBox_GPHDT"));

        gridLayout_2->addWidget(CheckBox_GPHDT, 5, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(frameOtherProtocol);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setFont(font);
        groupBox_3->setAlignment(Qt::AlignCenter);
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        CheckBox_GPFPD = new QCheckBox(groupBox_3);
        CheckBox_GPFPD->setObjectName(QString::fromUtf8("CheckBox_GPFPD"));

        gridLayout_3->addWidget(CheckBox_GPFPD, 0, 0, 1, 1);

        CheckBox_GPCHC = new QCheckBox(groupBox_3);
        CheckBox_GPCHC->setObjectName(QString::fromUtf8("CheckBox_GPCHC"));

        gridLayout_3->addWidget(CheckBox_GPCHC, 1, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_3, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(frameOtherProtocol);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        ComboBox_Protocol_Frequency = new QComboBox(frameOtherProtocol);
        ComboBox_Protocol_Frequency->addItem(QString());
        ComboBox_Protocol_Frequency->addItem(QString());
        ComboBox_Protocol_Frequency->addItem(QString());
        ComboBox_Protocol_Frequency->addItem(QString());
        ComboBox_Protocol_Frequency->setObjectName(QString::fromUtf8("ComboBox_Protocol_Frequency"));

        horizontalLayout_3->addWidget(ComboBox_Protocol_Frequency);


        gridLayout_5->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(frameOtherProtocol);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        ComboBox_Protocol_BaudRate = new QComboBox(frameOtherProtocol);
        ComboBox_Protocol_BaudRate->addItem(QString());
        ComboBox_Protocol_BaudRate->addItem(QString());
        ComboBox_Protocol_BaudRate->addItem(QString());
        ComboBox_Protocol_BaudRate->addItem(QString());
        ComboBox_Protocol_BaudRate->addItem(QString());
        ComboBox_Protocol_BaudRate->addItem(QString());
        ComboBox_Protocol_BaudRate->addItem(QString());
        ComboBox_Protocol_BaudRate->addItem(QString());
        ComboBox_Protocol_BaudRate->addItem(QString());
        ComboBox_Protocol_BaudRate->addItem(QString());
        ComboBox_Protocol_BaudRate->setObjectName(QString::fromUtf8("ComboBox_Protocol_BaudRate"));

        horizontalLayout_4->addWidget(ComboBox_Protocol_BaudRate);


        gridLayout_5->addLayout(horizontalLayout_4, 4, 0, 1, 1);


        verticalLayout->addWidget(frameOtherProtocol);

        groupBoxCustomProtocol = new QGroupBox(Dlg_Protocol);
        groupBoxCustomProtocol->setObjectName(QString::fromUtf8("groupBoxCustomProtocol"));
        groupBoxCustomProtocol->setFont(font);
        groupBoxCustomProtocol->setAlignment(Qt::AlignCenter);
        gridLayout_4 = new QGridLayout(groupBoxCustomProtocol);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        CheckBoxCustomProtocol = new QCheckBox(groupBoxCustomProtocol);
        CheckBoxCustomProtocol->setObjectName(QString::fromUtf8("CheckBoxCustomProtocol"));

        gridLayout_4->addWidget(CheckBoxCustomProtocol, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBoxCustomProtocol);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditCustomProtocolName = new QLineEdit(groupBoxCustomProtocol);
        lineEditCustomProtocolName->setObjectName(QString::fromUtf8("lineEditCustomProtocolName"));

        horizontalLayout->addWidget(lineEditCustomProtocolName);


        gridLayout_4->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBoxCustomProtocol);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditCustomProtocolRate = new QLineEdit(groupBoxCustomProtocol);
        lineEditCustomProtocolRate->setObjectName(QString::fromUtf8("lineEditCustomProtocolRate"));

        horizontalLayout_2->addWidget(lineEditCustomProtocolRate);


        gridLayout_4->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        verticalLayout->addWidget(groupBoxCustomProtocol);


        gridLayout_7->addLayout(verticalLayout, 0, 0, 2, 1);

        frame_3 = new QFrame(Dlg_Protocol);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
""));
        frame_3->setFrameShape(QFrame::NoFrame);
        gridLayout_6 = new QGridLayout(frame_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        Label = new QLabel(frame_3);
        Label->setObjectName(QString::fromUtf8("Label"));
        Label->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(11);
        Label->setFont(font1);
        Label->setTextFormat(Qt::PlainText);
        Label->setAlignment(Qt::AlignCenter);
        Label->setWordWrap(true);
        Label->setOpenExternalLinks(false);

        gridLayout_6->addWidget(Label, 0, 0, 1, 1);


        gridLayout_7->addWidget(frame_3, 0, 1, 1, 1);

        PushButton_ProtocolChange = new QPushButton(Dlg_Protocol);
        PushButton_ProtocolChange->setObjectName(QString::fromUtf8("PushButton_ProtocolChange"));

        gridLayout_7->addWidget(PushButton_ProtocolChange, 1, 1, 1, 1);


        retranslateUi(Dlg_Protocol);

        QMetaObject::connectSlotsByName(Dlg_Protocol);
    } // setupUi

    void retranslateUi(QDialog *Dlg_Protocol)
    {
        Dlg_Protocol->setWindowTitle(QCoreApplication::translate("Dlg_Protocol", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dlg_Protocol", "\351\273\230\350\256\244", nullptr));
        CheckBox_GJ->setText(QCoreApplication::translate("Dlg_Protocol", "GJ_Protocol", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Dlg_Protocol", "NMEA0183\345\215\217\350\256\256", nullptr));
        CheckBox_GPGGA->setText(QCoreApplication::translate("Dlg_Protocol", "GPGGA_Protocol", nullptr));
        CheckBox_GPRMC->setText(QCoreApplication::translate("Dlg_Protocol", "GPRMC_Protocol", nullptr));
        CheckBox_GPVTG->setText(QCoreApplication::translate("Dlg_Protocol", "GPVTG_Protocol", nullptr));
        CheckBox_GPGLL->setText(QCoreApplication::translate("Dlg_Protocol", "GPGLL_Protocol", nullptr));
        CheckBox_GPZDA->setText(QCoreApplication::translate("Dlg_Protocol", "GPZDA_Protocol", nullptr));
        CheckBox_GPHDT->setText(QCoreApplication::translate("Dlg_Protocol", "GPHDT_Protocol", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Dlg_Protocol", "\345\217\257\351\200\211", nullptr));
        CheckBox_GPFPD->setText(QCoreApplication::translate("Dlg_Protocol", "GPFPD_Protocol", nullptr));
        CheckBox_GPCHC->setText(QCoreApplication::translate("Dlg_Protocol", "GPCHC_Protocol", nullptr));
        label_3->setText(QCoreApplication::translate("Dlg_Protocol", "\351\242\221\347\216\207\357\274\210Hz\357\274\211", nullptr));
        ComboBox_Protocol_Frequency->setItemText(0, QCoreApplication::translate("Dlg_Protocol", "1", nullptr));
        ComboBox_Protocol_Frequency->setItemText(1, QCoreApplication::translate("Dlg_Protocol", "5", nullptr));
        ComboBox_Protocol_Frequency->setItemText(2, QCoreApplication::translate("Dlg_Protocol", "10", nullptr));
        ComboBox_Protocol_Frequency->setItemText(3, QCoreApplication::translate("Dlg_Protocol", "100", nullptr));

        ComboBox_Protocol_Frequency->setCurrentText(QCoreApplication::translate("Dlg_Protocol", "100", nullptr));
        label_4->setText(QCoreApplication::translate("Dlg_Protocol", "\346\263\242\347\211\271\347\216\207", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(0, QCoreApplication::translate("Dlg_Protocol", "1200", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(1, QCoreApplication::translate("Dlg_Protocol", "2400", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(2, QCoreApplication::translate("Dlg_Protocol", "4800", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(3, QCoreApplication::translate("Dlg_Protocol", "9600", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(4, QCoreApplication::translate("Dlg_Protocol", "14400", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(5, QCoreApplication::translate("Dlg_Protocol", "19200", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(6, QCoreApplication::translate("Dlg_Protocol", "28800", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(7, QCoreApplication::translate("Dlg_Protocol", "38400", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(8, QCoreApplication::translate("Dlg_Protocol", "57600", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(9, QCoreApplication::translate("Dlg_Protocol", "115200", nullptr));

        groupBoxCustomProtocol->setTitle(QCoreApplication::translate("Dlg_Protocol", "\350\207\252\345\256\232\344\271\211", nullptr));
        CheckBoxCustomProtocol->setText(QString());
        label->setText(QCoreApplication::translate("Dlg_Protocol", "\345\215\217\350\256\256\345\220\215\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("Dlg_Protocol", "\350\276\223\345\207\272\351\242\221\347\216\207", nullptr));
        Label->setText(QCoreApplication::translate("Dlg_Protocol", "\351\273\230\350\256\244\345\217\252\350\276\223\345\207\272\345\205\261\350\277\271\345\215\217\350\256\256\343\200\202\n"
"\345\213\276\351\200\211\344\273\273\346\204\217\345\205\266\344\273\226\345\215\217\350\256\256\357\274\214\345\260\206\344\270\215\345\206\215\350\276\223\345\207\272\345\205\261\350\277\271\345\215\217\350\256\256\343\200\202\344\270\212\344\275\215\346\234\272\344\271\237\344\270\215\345\206\215\346\233\264\346\226\260\346\230\276\347\244\272\346\225\260\346\215\256\343\200\202\n"
"\345\205\266\344\273\226\345\215\217\350\256\256\347\232\204\350\276\223\345\207\272\346\225\260\346\215\256\351\200\232\350\277\207\344\270\262\345\217\243\350\216\267\345\217\226\343\200\202", nullptr));
        PushButton_ProtocolChange->setText(QCoreApplication::translate("Dlg_Protocol", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dlg_Protocol: public Ui_Dlg_Protocol {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_PROTOCOL_H

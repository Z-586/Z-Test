/********************************************************************************
** Form generated from reading UI file 'dialog_protocolchange.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_PROTOCOLCHANGE_H
#define UI_DIALOG_PROTOCOLCHANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_ProtocolChange
{
public:
    QFrame *frame;
    QLabel *label_6;
    QFrame *line_3;
    QFrame *line;
    QLabel *label_4;
    QLabel *label_7;
    QCheckBox *CheckBox_GJ;
    QCheckBox *CheckBox_GPGGA;
    QCheckBox *CheckBox_GPGLL;
    QCheckBox *CheckBox_GPRMC;
    QCheckBox *CheckBox_GPVTG;
    QCheckBox *CheckBox_GPZDA;
    QCheckBox *CheckBox_GPHDT;
    QCheckBox *CheckBox_GPFPD;
    QCheckBox *CheckBox_GPCHC;
    QFrame *frame_2;
    QLabel *label_5;
    QComboBox *ComboBox_Protocol_Frequency;
    QLabel *label_8;
    QComboBox *ComboBox_Protocol_BaudRate;
    QFrame *frame_3;
    QLabel *Label;
    QPushButton *PushButton_ProtocolChange;

    void setupUi(QDialog *Dialog_ProtocolChange)
    {
        if (Dialog_ProtocolChange->objectName().isEmpty())
            Dialog_ProtocolChange->setObjectName(QString::fromUtf8("Dialog_ProtocolChange"));
        Dialog_ProtocolChange->resize(491, 412);
        Dialog_ProtocolChange->setMinimumSize(QSize(491, 412));
        Dialog_ProtocolChange->setMaximumSize(QSize(491, 412));
        Dialog_ProtocolChange->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgb(255, 255, 255);"));
        frame = new QFrame(Dialog_ProtocolChange);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 211, 391));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 10, 181, 21));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(10);
        label_6->setFont(font);
        line_3 = new QFrame(frame);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 60, 191, 20));
        line_3->setFrameShadow(QFrame::Raised);
        line_3->setFrameShape(QFrame::HLine);
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 280, 191, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 80, 181, 21));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMaximumSize(QSize(16777215, 16777215));
        label_4->setFont(font);
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 300, 181, 21));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMaximumSize(QSize(16777215, 16777215));
        label_7->setFont(font);
        CheckBox_GJ = new QCheckBox(frame);
        CheckBox_GJ->setObjectName(QString::fromUtf8("CheckBox_GJ"));
        CheckBox_GJ->setEnabled(true);
        CheckBox_GJ->setGeometry(QRect(10, 40, 191, 21));
        CheckBox_GJ->setChecked(true);
        CheckBox_GPGGA = new QCheckBox(frame);
        CheckBox_GPGGA->setObjectName(QString::fromUtf8("CheckBox_GPGGA"));
        CheckBox_GPGGA->setGeometry(QRect(10, 110, 191, 21));
        CheckBox_GPGLL = new QCheckBox(frame);
        CheckBox_GPGLL->setObjectName(QString::fromUtf8("CheckBox_GPGLL"));
        CheckBox_GPGLL->setGeometry(QRect(10, 200, 191, 21));
        CheckBox_GPRMC = new QCheckBox(frame);
        CheckBox_GPRMC->setObjectName(QString::fromUtf8("CheckBox_GPRMC"));
        CheckBox_GPRMC->setGeometry(QRect(10, 140, 191, 21));
        CheckBox_GPVTG = new QCheckBox(frame);
        CheckBox_GPVTG->setObjectName(QString::fromUtf8("CheckBox_GPVTG"));
        CheckBox_GPVTG->setGeometry(QRect(10, 170, 191, 21));
        CheckBox_GPZDA = new QCheckBox(frame);
        CheckBox_GPZDA->setObjectName(QString::fromUtf8("CheckBox_GPZDA"));
        CheckBox_GPZDA->setGeometry(QRect(10, 230, 191, 21));
        CheckBox_GPHDT = new QCheckBox(frame);
        CheckBox_GPHDT->setObjectName(QString::fromUtf8("CheckBox_GPHDT"));
        CheckBox_GPHDT->setGeometry(QRect(10, 260, 191, 21));
        CheckBox_GPFPD = new QCheckBox(frame);
        CheckBox_GPFPD->setObjectName(QString::fromUtf8("CheckBox_GPFPD"));
        CheckBox_GPFPD->setGeometry(QRect(10, 330, 191, 21));
        CheckBox_GPCHC = new QCheckBox(frame);
        CheckBox_GPCHC->setObjectName(QString::fromUtf8("CheckBox_GPCHC"));
        CheckBox_GPCHC->setGeometry(QRect(10, 360, 191, 21));
        frame_2 = new QFrame(Dialog_ProtocolChange);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(230, 10, 251, 71));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 10, 81, 21));
        QFont font1;
        font1.setPointSize(11);
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);
        ComboBox_Protocol_Frequency = new QComboBox(frame_2);
        ComboBox_Protocol_Frequency->addItem(QString());
        ComboBox_Protocol_Frequency->addItem(QString());
        ComboBox_Protocol_Frequency->addItem(QString());
        ComboBox_Protocol_Frequency->addItem(QString());
        ComboBox_Protocol_Frequency->setObjectName(QString::fromUtf8("ComboBox_Protocol_Frequency"));
        ComboBox_Protocol_Frequency->setGeometry(QRect(130, 10, 101, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        ComboBox_Protocol_Frequency->setFont(font2);
        ComboBox_Protocol_Frequency->setStyleSheet(QString::fromUtf8("/* \346\234\252\344\270\213\346\213\211\346\227\266\357\274\214QComboBox\347\232\204\346\240\267\345\274\217 */\n"
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
        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 40, 81, 21));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignCenter);
        ComboBox_Protocol_BaudRate = new QComboBox(frame_2);
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
        ComboBox_Protocol_BaudRate->addItem(QString());
        ComboBox_Protocol_BaudRate->addItem(QString());
        ComboBox_Protocol_BaudRate->addItem(QString());
        ComboBox_Protocol_BaudRate->setObjectName(QString::fromUtf8("ComboBox_Protocol_BaudRate"));
        ComboBox_Protocol_BaudRate->setGeometry(QRect(130, 40, 101, 21));
        ComboBox_Protocol_BaudRate->setFont(font2);
        ComboBox_Protocol_BaudRate->setStyleSheet(QString::fromUtf8("/* \346\234\252\344\270\213\346\213\211\346\227\266\357\274\214QComboBox\347\232\204\346\240\267\345\274\217 */\n"
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
        frame_3 = new QFrame(Dialog_ProtocolChange);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(229, 90, 251, 311));
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
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        Label = new QLabel(frame_3);
        Label->setObjectName(QString::fromUtf8("Label"));
        Label->setGeometry(QRect(10, 10, 231, 231));
        Label->setMinimumSize(QSize(0, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(11);
        Label->setFont(font3);
        Label->setTextFormat(Qt::AutoText);
        Label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        Label->setWordWrap(true);
        Label->setOpenExternalLinks(false);
        PushButton_ProtocolChange = new QPushButton(frame_3);
        PushButton_ProtocolChange->setObjectName(QString::fromUtf8("PushButton_ProtocolChange"));
        PushButton_ProtocolChange->setGeometry(QRect(10, 260, 231, 40));
        PushButton_ProtocolChange->setMinimumSize(QSize(0, 40));

        retranslateUi(Dialog_ProtocolChange);

        ComboBox_Protocol_Frequency->setCurrentIndex(3);
        ComboBox_Protocol_BaudRate->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog_ProtocolChange);
    } // setupUi

    void retranslateUi(QDialog *Dialog_ProtocolChange)
    {
        Dialog_ProtocolChange->setWindowTitle(QCoreApplication::translate("Dialog_ProtocolChange", "Dialog", nullptr));
        label_6->setText(QCoreApplication::translate("Dialog_ProtocolChange", "\351\273\230\350\256\244", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog_ProtocolChange", "NMEA0183\345\215\217\350\256\256", nullptr));
        label_7->setText(QCoreApplication::translate("Dialog_ProtocolChange", "\345\217\257\351\200\211", nullptr));
        CheckBox_GJ->setText(QCoreApplication::translate("Dialog_ProtocolChange", "GJ_Protocol", nullptr));
        CheckBox_GPGGA->setText(QCoreApplication::translate("Dialog_ProtocolChange", "GPGGA_Protocol", nullptr));
        CheckBox_GPGLL->setText(QCoreApplication::translate("Dialog_ProtocolChange", "GPGLL_Protocol", nullptr));
        CheckBox_GPRMC->setText(QCoreApplication::translate("Dialog_ProtocolChange", "GPRMC_Protocol", nullptr));
        CheckBox_GPVTG->setText(QCoreApplication::translate("Dialog_ProtocolChange", "GPVTG_Protocol", nullptr));
        CheckBox_GPZDA->setText(QCoreApplication::translate("Dialog_ProtocolChange", "GPZDA_Protocol", nullptr));
        CheckBox_GPHDT->setText(QCoreApplication::translate("Dialog_ProtocolChange", "GPHDT_Protocol", nullptr));
        CheckBox_GPFPD->setText(QCoreApplication::translate("Dialog_ProtocolChange", "GPFPD_Protocol", nullptr));
        CheckBox_GPCHC->setText(QCoreApplication::translate("Dialog_ProtocolChange", "GPCHC_Protocol", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog_ProtocolChange", "\351\242\221\347\216\207(HZ)", nullptr));
        ComboBox_Protocol_Frequency->setItemText(0, QCoreApplication::translate("Dialog_ProtocolChange", "1", nullptr));
        ComboBox_Protocol_Frequency->setItemText(1, QCoreApplication::translate("Dialog_ProtocolChange", "5", nullptr));
        ComboBox_Protocol_Frequency->setItemText(2, QCoreApplication::translate("Dialog_ProtocolChange", "10", nullptr));
        ComboBox_Protocol_Frequency->setItemText(3, QCoreApplication::translate("Dialog_ProtocolChange", "100", nullptr));

        label_8->setText(QCoreApplication::translate("Dialog_ProtocolChange", "\346\263\242\347\211\271\347\216\207", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(0, QCoreApplication::translate("Dialog_ProtocolChange", "1200", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(1, QCoreApplication::translate("Dialog_ProtocolChange", "2400", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(2, QCoreApplication::translate("Dialog_ProtocolChange", "4800", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(3, QCoreApplication::translate("Dialog_ProtocolChange", "9600", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(4, QCoreApplication::translate("Dialog_ProtocolChange", "14400", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(5, QCoreApplication::translate("Dialog_ProtocolChange", "19200", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(6, QCoreApplication::translate("Dialog_ProtocolChange", "28800", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(7, QCoreApplication::translate("Dialog_ProtocolChange", "38400", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(8, QCoreApplication::translate("Dialog_ProtocolChange", "57600", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(9, QCoreApplication::translate("Dialog_ProtocolChange", "115200", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(10, QCoreApplication::translate("Dialog_ProtocolChange", "230400", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(11, QCoreApplication::translate("Dialog_ProtocolChange", "460800", nullptr));
        ComboBox_Protocol_BaudRate->setItemText(12, QCoreApplication::translate("Dialog_ProtocolChange", "921600", nullptr));

        Label->setText(QCoreApplication::translate("Dialog_ProtocolChange", "<html><head/><body><p>\351\273\230\350\256\244\345\217\252\350\276\223\345\207\272\345\205\261\350\277\271\345\215\217\350\256\256\343\200\202</p><p>\345\213\276\351\200\211\344\273\273\346\204\217\345\205\266\344\273\226\345\215\217\350\256\256\357\274\214\345\260\206\344\270\215\345\206\215\350\276\223\345\207\272\345\205\261\350\277\271\345\215\217\350\256\256\343\200\202\344\270\212\344\275\215\346\234\272\344\271\237\344\270\215\345\206\215\346\233\264\346\226\260\346\230\276\347\244\272\346\225\260\346\215\256\343\200\202</p><p>\345\205\266\344\273\226\345\215\217\350\256\256\347\232\204\350\276\223\345\207\272\346\225\260\346\215\256\351\200\232\350\277\207\344\270\262\345\217\243\350\216\267\345\217\226\343\200\202</p></body></html>", nullptr));
        PushButton_ProtocolChange->setText(QCoreApplication::translate("Dialog_ProtocolChange", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_ProtocolChange: public Ui_Dialog_ProtocolChange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_PROTOCOLCHANGE_H

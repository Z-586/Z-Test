/********************************************************************************
** Form generated from reading UI file 'dialog_firmware.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_FIRMWARE_H
#define UI_DIALOG_FIRMWARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_FirmWare
{
public:
    QPushButton *PushButton_FirmWare_Updata;
    QLabel *Label_FirmWare_Msg;
    QLabel *label_2;
    QProgressBar *ProgressBar_FirmWare_ProgressBar;
    QPushButton *PushButton_FirmWare_Complete;
    QPushButton *PushButton_FirmWare_SeleteFile;
    QLabel *label;

    void setupUi(QDialog *Dialog_FirmWare)
    {
        if (Dialog_FirmWare->objectName().isEmpty())
            Dialog_FirmWare->setObjectName(QString::fromUtf8("Dialog_FirmWare"));
        Dialog_FirmWare->resize(600, 500);
        Dialog_FirmWare->setMinimumSize(QSize(600, 500));
        Dialog_FirmWare->setMaximumSize(QSize(600, 500));
        Dialog_FirmWare->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);"));
        PushButton_FirmWare_Updata = new QPushButton(Dialog_FirmWare);
        PushButton_FirmWare_Updata->setObjectName(QString::fromUtf8("PushButton_FirmWare_Updata"));
        PushButton_FirmWare_Updata->setGeometry(QRect(240, 410, 101, 28));
        QFont font;
        font.setPointSize(10);
        PushButton_FirmWare_Updata->setFont(font);
        PushButton_FirmWare_Updata->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9,\n"
"		stop:0.494318 rgba(214, 214, 214, 255), stop:0.5 rgba(236, 236, 236, 255));\n"
"	border: 1px solid rgb(124, 124, 124);\n"
"	border-radius:2px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9,\n"
"		stop:0.494318 rgba(134, 198, 233, 255), stop:0.5 rgba(206, 234, 248, 255));\n"
"	border: 1px solid #5F92B2;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9,\n"
"	stop:0.494318 rgba(181, 225, 250, 255), stop:0.5 rgba(222, 242, 251, 255));\n"
"border: 1px solid #3C80B1;\n"
"}"));
        Label_FirmWare_Msg = new QLabel(Dialog_FirmWare);
        Label_FirmWare_Msg->setObjectName(QString::fromUtf8("Label_FirmWare_Msg"));
        Label_FirmWare_Msg->setGeometry(QRect(90, 180, 401, 111));
        QFont font1;
        font1.setPointSize(12);
        Label_FirmWare_Msg->setFont(font1);
        Label_FirmWare_Msg->setFrameShape(QFrame::Box);
        Label_FirmWare_Msg->setAlignment(Qt::AlignCenter);
        Label_FirmWare_Msg->setWordWrap(true);
        label_2 = new QLabel(Dialog_FirmWare);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 20, 121, 41));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignCenter);
        ProgressBar_FirmWare_ProgressBar = new QProgressBar(Dialog_FirmWare);
        ProgressBar_FirmWare_ProgressBar->setObjectName(QString::fromUtf8("ProgressBar_FirmWare_ProgressBar"));
        ProgressBar_FirmWare_ProgressBar->setGeometry(QRect(150, 330, 280, 31));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ProgressBar_FirmWare_ProgressBar->sizePolicy().hasHeightForWidth());
        ProgressBar_FirmWare_ProgressBar->setSizePolicy(sizePolicy);
        ProgressBar_FirmWare_ProgressBar->setMaximumSize(QSize(16777215, 16777215));
        ProgressBar_FirmWare_ProgressBar->setValue(0);
        ProgressBar_FirmWare_ProgressBar->setAlignment(Qt::AlignCenter);
        ProgressBar_FirmWare_ProgressBar->setTextVisible(true);
        ProgressBar_FirmWare_ProgressBar->setInvertedAppearance(false);
        PushButton_FirmWare_Complete = new QPushButton(Dialog_FirmWare);
        PushButton_FirmWare_Complete->setObjectName(QString::fromUtf8("PushButton_FirmWare_Complete"));
        PushButton_FirmWare_Complete->setGeometry(QRect(430, 410, 101, 28));
        PushButton_FirmWare_Complete->setFont(font);
        PushButton_FirmWare_Complete->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9,\n"
"		stop:0.494318 rgba(214, 214, 214, 255), stop:0.5 rgba(236, 236, 236, 255));\n"
"	border: 1px solid rgb(124, 124, 124);\n"
"	border-radius:2px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9,\n"
"		stop:0.494318 rgba(134, 198, 233, 255), stop:0.5 rgba(206, 234, 248, 255));\n"
"	border: 1px solid #5F92B2;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9,\n"
"	stop:0.494318 rgba(181, 225, 250, 255), stop:0.5 rgba(222, 242, 251, 255));\n"
"border: 1px solid #3C80B1;\n"
"}"));
        PushButton_FirmWare_SeleteFile = new QPushButton(Dialog_FirmWare);
        PushButton_FirmWare_SeleteFile->setObjectName(QString::fromUtf8("PushButton_FirmWare_SeleteFile"));
        PushButton_FirmWare_SeleteFile->setGeometry(QRect(50, 410, 101, 28));
        PushButton_FirmWare_SeleteFile->setFont(font);
        PushButton_FirmWare_SeleteFile->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9,\n"
"		stop:0.494318 rgba(214, 214, 214, 255), stop:0.5 rgba(236, 236, 236, 255));\n"
"	border: 1px solid rgb(124, 124, 124);\n"
"	border-radius:2px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9,\n"
"		stop:0.494318 rgba(134, 198, 233, 255), stop:0.5 rgba(206, 234, 248, 255));\n"
"	border: 1px solid #5F92B2;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9,\n"
"	stop:0.494318 rgba(181, 225, 250, 255), stop:0.5 rgba(222, 242, 251, 255));\n"
"border: 1px solid #3C80B1;\n"
"}"));
        label = new QLabel(Dialog_FirmWare);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 60, 511, 81));

        retranslateUi(Dialog_FirmWare);
        QObject::connect(PushButton_FirmWare_Complete, SIGNAL(clicked()), Dialog_FirmWare, SLOT(accept()));

        QMetaObject::connectSlotsByName(Dialog_FirmWare);
    } // setupUi

    void retranslateUi(QDialog *Dialog_FirmWare)
    {
        Dialog_FirmWare->setWindowTitle(QCoreApplication::translate("Dialog_FirmWare", "Dialog", nullptr));
        PushButton_FirmWare_Updata->setText(QCoreApplication::translate("Dialog_FirmWare", "\346\233\264\346\226\260", nullptr));
        Label_FirmWare_Msg->setText(QCoreApplication::translate("Dialog_FirmWare", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog_FirmWare", "<html><head/><body><p><span style=\" font-size:11pt;\">\346\217\220\347\244\272\346\266\210\346\201\257:</span></p></body></html>", nullptr));
        PushButton_FirmWare_Complete->setText(QCoreApplication::translate("Dialog_FirmWare", "\345\256\214\346\210\220", nullptr));
        PushButton_FirmWare_SeleteFile->setText(QCoreApplication::translate("Dialog_FirmWare", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        label->setText(QCoreApplication::translate("Dialog_FirmWare", "<html><head/><body><p>\345\233\272\344\273\266\346\233\264\346\226\260\344\270\255\350\257\267\344\270\215\350\246\201\346\226\255\347\224\265\357\274\214\344\270\215\350\246\201\345\205\263\351\227\255\346\255\244\347\252\227\345\217\243\357\274\201\357\274\201\357\274\201</p><p>1\357\274\232\347\202\271\345\207\273\351\200\211\346\213\251\346\226\207\344\273\266\344\273\216\346\234\254\345\234\260\347\224\265\350\204\221\344\270\255\346\211\276\345\210\260\350\246\201\346\233\264\346\226\260\347\232\204.bin\346\226\207\344\273\266\343\200\202</p><p>2\357\274\232\351\200\211\345\245\275.bin\346\226\207\344\273\266\345\220\216\347\202\271\345\207\273\346\233\264\346\226\260\357\274\214\347\255\211\345\276\2052\345\210\206\351\222\237\357\274\214\347\233\264\350\207\263\345\207\272\347\216\260\346\217\220\347\244\272\342\200\234\345\233\272\344\273\266\346\233\264\346\226\260\345\256\214\346\210\220\342\200\235\343\200\202</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_FirmWare: public Ui_Dialog_FirmWare {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_FIRMWARE_H

/********************************************************************************
** Form generated from reading UI file 'dialog_tempcali.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_TEMPCALI_H
#define UI_DIALOG_TEMPCALI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_TempCali
{
public:
    QLabel *Label_TempCali_Msg;
    QPushButton *PushButton_TempCali_ReadFile;
    QPushButton *PushButton_TempCali_SendFile;
    QPushButton *PushButton_TempCali_StopSendFile;
    QPushButton *PushButton_next;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *PushButton_pre;
    QLabel *Label_CurPage;
    QLineEdit *LineEdit_T;
    QLineEdit *LineEdit_Bay;
    QLineEdit *LineEdit_Baz;
    QLineEdit *LineEdit_Bgx;
    QLineEdit *LineEdit_Bgz;
    QLineEdit *LineEdit_Bgy;
    QLineEdit *LineEdit_Ka7;
    QLineEdit *LineEdit_Ka2;
    QLineEdit *LineEdit_Ka1;
    QLineEdit *LineEdit_Ka3;
    QLineEdit *LineEdit_Ka5;
    QLineEdit *LineEdit_Ka4;
    QLineEdit *LineEdit_Ka9;
    QLineEdit *LineEdit_Ka8;
    QLineEdit *LineEdit_Ka6;
    QLineEdit *LineEdit_Kg7;
    QLineEdit *LineEdit_Kg1;
    QLineEdit *LineEdit_Kg4;
    QLineEdit *LineEdit_Kg5;
    QLineEdit *LineEdit_Kg2;
    QLineEdit *LineEdit_Kg3;
    QLineEdit *LineEdit_Kg8;
    QLineEdit *LineEdit_Kg9;
    QLineEdit *LineEdit_Kg6;
    QLineEdit *LineEdit_G7;
    QLineEdit *LineEdit_G1;
    QLineEdit *LineEdit_G4;
    QLineEdit *LineEdit_G2;
    QLineEdit *LineEdit_G8;
    QLineEdit *LineEdit_G5;
    QLineEdit *LineEdit_G9;
    QLineEdit *LineEdit_G3;
    QLineEdit *LineEdit_G6;
    QLineEdit *LineEdit_Bax;

    void setupUi(QDialog *Dialog_TempCali)
    {
        if (Dialog_TempCali->objectName().isEmpty())
            Dialog_TempCali->setObjectName(QString::fromUtf8("Dialog_TempCali"));
        Dialog_TempCali->resize(893, 585);
        Label_TempCali_Msg = new QLabel(Dialog_TempCali);
        Label_TempCali_Msg->setObjectName(QString::fromUtf8("Label_TempCali_Msg"));
        Label_TempCali_Msg->setGeometry(QRect(50, 30, 371, 221));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        Label_TempCali_Msg->setFont(font);
        Label_TempCali_Msg->setFrameShape(QFrame::StyledPanel);
        Label_TempCali_Msg->setFrameShadow(QFrame::Plain);
        Label_TempCali_Msg->setLineWidth(1);
        Label_TempCali_Msg->setMidLineWidth(1);
        Label_TempCali_Msg->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        PushButton_TempCali_ReadFile = new QPushButton(Dialog_TempCali);
        PushButton_TempCali_ReadFile->setObjectName(QString::fromUtf8("PushButton_TempCali_ReadFile"));
        PushButton_TempCali_ReadFile->setGeometry(QRect(50, 280, 93, 28));
        PushButton_TempCali_SendFile = new QPushButton(Dialog_TempCali);
        PushButton_TempCali_SendFile->setObjectName(QString::fromUtf8("PushButton_TempCali_SendFile"));
        PushButton_TempCali_SendFile->setGeometry(QRect(190, 280, 93, 28));
        PushButton_TempCali_StopSendFile = new QPushButton(Dialog_TempCali);
        PushButton_TempCali_StopSendFile->setObjectName(QString::fromUtf8("PushButton_TempCali_StopSendFile"));
        PushButton_TempCali_StopSendFile->setGeometry(QRect(330, 280, 93, 28));
        PushButton_next = new QPushButton(Dialog_TempCali);
        PushButton_next->setObjectName(QString::fromUtf8("PushButton_next"));
        PushButton_next->setEnabled(false);
        PushButton_next->setGeometry(QRect(760, 30, 93, 31));
        label_2 = new QLabel(Dialog_TempCali);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(440, 10, 72, 15));
        label_3 = new QLabel(Dialog_TempCali);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(440, 60, 91, 31));
        label_4 = new QLabel(Dialog_TempCali);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(440, 120, 91, 31));
        label_8 = new QLabel(Dialog_TempCali);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(440, 180, 111, 41));
        label_9 = new QLabel(Dialog_TempCali);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(440, 310, 131, 41));
        label_10 = new QLabel(Dialog_TempCali);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(440, 440, 91, 41));
        PushButton_pre = new QPushButton(Dialog_TempCali);
        PushButton_pre->setObjectName(QString::fromUtf8("PushButton_pre"));
        PushButton_pre->setEnabled(false);
        PushButton_pre->setGeometry(QRect(620, 30, 93, 31));
        Label_CurPage = new QLabel(Dialog_TempCali);
        Label_CurPage->setObjectName(QString::fromUtf8("Label_CurPage"));
        Label_CurPage->setGeometry(QRect(730, 30, 31, 31));
        LineEdit_T = new QLineEdit(Dialog_TempCali);
        LineEdit_T->setObjectName(QString::fromUtf8("LineEdit_T"));
        LineEdit_T->setEnabled(true);
        LineEdit_T->setGeometry(QRect(440, 30, 141, 31));
        LineEdit_T->setReadOnly(true);
        LineEdit_Bay = new QLineEdit(Dialog_TempCali);
        LineEdit_Bay->setObjectName(QString::fromUtf8("LineEdit_Bay"));
        LineEdit_Bay->setGeometry(QRect(580, 90, 141, 31));
        LineEdit_Bay->setReadOnly(true);
        LineEdit_Baz = new QLineEdit(Dialog_TempCali);
        LineEdit_Baz->setObjectName(QString::fromUtf8("LineEdit_Baz"));
        LineEdit_Baz->setGeometry(QRect(720, 90, 141, 31));
        LineEdit_Baz->setReadOnly(true);
        LineEdit_Bgx = new QLineEdit(Dialog_TempCali);
        LineEdit_Bgx->setObjectName(QString::fromUtf8("LineEdit_Bgx"));
        LineEdit_Bgx->setGeometry(QRect(440, 150, 141, 31));
        LineEdit_Bgx->setReadOnly(true);
        LineEdit_Bgz = new QLineEdit(Dialog_TempCali);
        LineEdit_Bgz->setObjectName(QString::fromUtf8("LineEdit_Bgz"));
        LineEdit_Bgz->setGeometry(QRect(720, 150, 141, 31));
        LineEdit_Bgz->setReadOnly(true);
        LineEdit_Bgy = new QLineEdit(Dialog_TempCali);
        LineEdit_Bgy->setObjectName(QString::fromUtf8("LineEdit_Bgy"));
        LineEdit_Bgy->setGeometry(QRect(580, 150, 141, 31));
        LineEdit_Bgy->setReadOnly(true);
        LineEdit_Ka7 = new QLineEdit(Dialog_TempCali);
        LineEdit_Ka7->setObjectName(QString::fromUtf8("LineEdit_Ka7"));
        LineEdit_Ka7->setGeometry(QRect(720, 220, 141, 31));
        LineEdit_Ka7->setReadOnly(true);
        LineEdit_Ka2 = new QLineEdit(Dialog_TempCali);
        LineEdit_Ka2->setObjectName(QString::fromUtf8("LineEdit_Ka2"));
        LineEdit_Ka2->setGeometry(QRect(440, 250, 141, 31));
        LineEdit_Ka2->setReadOnly(true);
        LineEdit_Ka1 = new QLineEdit(Dialog_TempCali);
        LineEdit_Ka1->setObjectName(QString::fromUtf8("LineEdit_Ka1"));
        LineEdit_Ka1->setGeometry(QRect(440, 220, 141, 31));
        LineEdit_Ka1->setReadOnly(true);
        LineEdit_Ka3 = new QLineEdit(Dialog_TempCali);
        LineEdit_Ka3->setObjectName(QString::fromUtf8("LineEdit_Ka3"));
        LineEdit_Ka3->setGeometry(QRect(440, 280, 141, 31));
        LineEdit_Ka3->setReadOnly(true);
        LineEdit_Ka5 = new QLineEdit(Dialog_TempCali);
        LineEdit_Ka5->setObjectName(QString::fromUtf8("LineEdit_Ka5"));
        LineEdit_Ka5->setGeometry(QRect(580, 250, 141, 31));
        LineEdit_Ka5->setReadOnly(true);
        LineEdit_Ka4 = new QLineEdit(Dialog_TempCali);
        LineEdit_Ka4->setObjectName(QString::fromUtf8("LineEdit_Ka4"));
        LineEdit_Ka4->setGeometry(QRect(580, 220, 141, 31));
        LineEdit_Ka4->setReadOnly(true);
        LineEdit_Ka9 = new QLineEdit(Dialog_TempCali);
        LineEdit_Ka9->setObjectName(QString::fromUtf8("LineEdit_Ka9"));
        LineEdit_Ka9->setGeometry(QRect(720, 280, 141, 31));
        LineEdit_Ka9->setReadOnly(true);
        LineEdit_Ka8 = new QLineEdit(Dialog_TempCali);
        LineEdit_Ka8->setObjectName(QString::fromUtf8("LineEdit_Ka8"));
        LineEdit_Ka8->setGeometry(QRect(720, 250, 141, 31));
        LineEdit_Ka8->setReadOnly(true);
        LineEdit_Ka6 = new QLineEdit(Dialog_TempCali);
        LineEdit_Ka6->setObjectName(QString::fromUtf8("LineEdit_Ka6"));
        LineEdit_Ka6->setGeometry(QRect(580, 280, 141, 31));
        LineEdit_Ka6->setReadOnly(true);
        LineEdit_Kg7 = new QLineEdit(Dialog_TempCali);
        LineEdit_Kg7->setObjectName(QString::fromUtf8("LineEdit_Kg7"));
        LineEdit_Kg7->setGeometry(QRect(720, 350, 141, 31));
        LineEdit_Kg7->setReadOnly(true);
        LineEdit_Kg1 = new QLineEdit(Dialog_TempCali);
        LineEdit_Kg1->setObjectName(QString::fromUtf8("LineEdit_Kg1"));
        LineEdit_Kg1->setGeometry(QRect(440, 350, 141, 31));
        LineEdit_Kg1->setReadOnly(true);
        LineEdit_Kg4 = new QLineEdit(Dialog_TempCali);
        LineEdit_Kg4->setObjectName(QString::fromUtf8("LineEdit_Kg4"));
        LineEdit_Kg4->setGeometry(QRect(580, 350, 141, 31));
        LineEdit_Kg4->setReadOnly(true);
        LineEdit_Kg5 = new QLineEdit(Dialog_TempCali);
        LineEdit_Kg5->setObjectName(QString::fromUtf8("LineEdit_Kg5"));
        LineEdit_Kg5->setGeometry(QRect(580, 380, 141, 31));
        LineEdit_Kg5->setReadOnly(true);
        LineEdit_Kg2 = new QLineEdit(Dialog_TempCali);
        LineEdit_Kg2->setObjectName(QString::fromUtf8("LineEdit_Kg2"));
        LineEdit_Kg2->setGeometry(QRect(440, 380, 141, 31));
        LineEdit_Kg2->setReadOnly(true);
        LineEdit_Kg3 = new QLineEdit(Dialog_TempCali);
        LineEdit_Kg3->setObjectName(QString::fromUtf8("LineEdit_Kg3"));
        LineEdit_Kg3->setGeometry(QRect(440, 410, 141, 31));
        LineEdit_Kg3->setReadOnly(true);
        LineEdit_Kg8 = new QLineEdit(Dialog_TempCali);
        LineEdit_Kg8->setObjectName(QString::fromUtf8("LineEdit_Kg8"));
        LineEdit_Kg8->setGeometry(QRect(720, 380, 141, 31));
        LineEdit_Kg8->setReadOnly(true);
        LineEdit_Kg9 = new QLineEdit(Dialog_TempCali);
        LineEdit_Kg9->setObjectName(QString::fromUtf8("LineEdit_Kg9"));
        LineEdit_Kg9->setGeometry(QRect(720, 410, 141, 31));
        LineEdit_Kg9->setReadOnly(true);
        LineEdit_Kg6 = new QLineEdit(Dialog_TempCali);
        LineEdit_Kg6->setObjectName(QString::fromUtf8("LineEdit_Kg6"));
        LineEdit_Kg6->setGeometry(QRect(580, 410, 141, 31));
        LineEdit_Kg6->setReadOnly(true);
        LineEdit_G7 = new QLineEdit(Dialog_TempCali);
        LineEdit_G7->setObjectName(QString::fromUtf8("LineEdit_G7"));
        LineEdit_G7->setGeometry(QRect(720, 480, 141, 31));
        LineEdit_G7->setReadOnly(true);
        LineEdit_G1 = new QLineEdit(Dialog_TempCali);
        LineEdit_G1->setObjectName(QString::fromUtf8("LineEdit_G1"));
        LineEdit_G1->setGeometry(QRect(440, 480, 141, 31));
        LineEdit_G1->setReadOnly(true);
        LineEdit_G4 = new QLineEdit(Dialog_TempCali);
        LineEdit_G4->setObjectName(QString::fromUtf8("LineEdit_G4"));
        LineEdit_G4->setGeometry(QRect(580, 480, 141, 31));
        LineEdit_G4->setReadOnly(true);
        LineEdit_G2 = new QLineEdit(Dialog_TempCali);
        LineEdit_G2->setObjectName(QString::fromUtf8("LineEdit_G2"));
        LineEdit_G2->setGeometry(QRect(440, 510, 141, 31));
        LineEdit_G2->setReadOnly(true);
        LineEdit_G8 = new QLineEdit(Dialog_TempCali);
        LineEdit_G8->setObjectName(QString::fromUtf8("LineEdit_G8"));
        LineEdit_G8->setGeometry(QRect(720, 510, 141, 31));
        LineEdit_G8->setReadOnly(true);
        LineEdit_G5 = new QLineEdit(Dialog_TempCali);
        LineEdit_G5->setObjectName(QString::fromUtf8("LineEdit_G5"));
        LineEdit_G5->setGeometry(QRect(580, 510, 141, 31));
        LineEdit_G5->setReadOnly(true);
        LineEdit_G9 = new QLineEdit(Dialog_TempCali);
        LineEdit_G9->setObjectName(QString::fromUtf8("LineEdit_G9"));
        LineEdit_G9->setGeometry(QRect(720, 540, 141, 31));
        LineEdit_G9->setReadOnly(true);
        LineEdit_G3 = new QLineEdit(Dialog_TempCali);
        LineEdit_G3->setObjectName(QString::fromUtf8("LineEdit_G3"));
        LineEdit_G3->setGeometry(QRect(440, 540, 141, 31));
        LineEdit_G3->setReadOnly(true);
        LineEdit_G6 = new QLineEdit(Dialog_TempCali);
        LineEdit_G6->setObjectName(QString::fromUtf8("LineEdit_G6"));
        LineEdit_G6->setGeometry(QRect(580, 540, 141, 31));
        LineEdit_G6->setReadOnly(true);
        LineEdit_Bax = new QLineEdit(Dialog_TempCali);
        LineEdit_Bax->setObjectName(QString::fromUtf8("LineEdit_Bax"));
        LineEdit_Bax->setGeometry(QRect(440, 90, 141, 31));
        LineEdit_Bax->setReadOnly(true);

        retranslateUi(Dialog_TempCali);

        QMetaObject::connectSlotsByName(Dialog_TempCali);
    } // setupUi

    void retranslateUi(QDialog *Dialog_TempCali)
    {
        Dialog_TempCali->setWindowTitle(QCoreApplication::translate("Dialog_TempCali", "Dialog", nullptr));
        Label_TempCali_Msg->setText(QCoreApplication::translate("Dialog_TempCali", "                 \350\257\267\351\200\211\346\213\251\345\217\221\351\200\201\347\232\204\346\225\260\346\215\256", nullptr));
        PushButton_TempCali_ReadFile->setText(QCoreApplication::translate("Dialog_TempCali", "\350\257\273\345\217\226\346\225\260\346\215\256", nullptr));
        PushButton_TempCali_SendFile->setText(QCoreApplication::translate("Dialog_TempCali", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        PushButton_TempCali_StopSendFile->setText(QCoreApplication::translate("Dialog_TempCali", "\347\273\210\346\255\242\345\217\221\351\200\201", nullptr));
        PushButton_next->setText(QCoreApplication::translate("Dialog_TempCali", "\344\270\213\344\270\200\351\241\265", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog_TempCali", "\346\270\251\345\272\246", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog_TempCali", "\345\212\240\351\200\237\345\272\246\351\233\266\345\201\217", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog_TempCali", "\351\231\200\350\236\272\344\273\252\351\233\266\345\201\217", nullptr));
        label_8->setText(QCoreApplication::translate("Dialog_TempCali", "\345\212\240\351\200\237\345\272\246\347\263\273\346\225\260\347\237\251\351\230\265", nullptr));
        label_9->setText(QCoreApplication::translate("Dialog_TempCali", "\351\231\200\350\236\272\344\273\252\347\263\273\346\225\260\347\237\251\351\230\265", nullptr));
        label_10->setText(QCoreApplication::translate("Dialog_TempCali", "G\346\225\217\346\204\237\347\237\251\351\230\265", nullptr));
        PushButton_pre->setText(QCoreApplication::translate("Dialog_TempCali", "\344\270\212\344\270\200\351\241\265", nullptr));
        Label_CurPage->setText(QCoreApplication::translate("Dialog_TempCali", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_TempCali: public Ui_Dialog_TempCali {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_TEMPCALI_H

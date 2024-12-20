/********************************************************************************
** Form generated from reading UI file 'dialog_encryption.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ENCRYPTION_H
#define UI_DIALOG_ENCRYPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Encryption
{
public:
    QPushButton *PushButton_Encryption;
    QLabel *label_6;
    QLineEdit *LineEdit_SN;
    QLabel *label_7;
    QLineEdit *LineEdit_ActiveTime;
    QLabel *label_8;
    QLabel *label1;
    QFrame *line;
    QLabel *label_9;
    QLineEdit *LineEdit_ActiveCode;
    QPushButton *PushButton_SendActiveCode;

    void setupUi(QDialog *Dialog_Encryption)
    {
        if (Dialog_Encryption->objectName().isEmpty())
            Dialog_Encryption->setObjectName(QString::fromUtf8("Dialog_Encryption"));
        Dialog_Encryption->resize(480, 159);
        Dialog_Encryption->setMinimumSize(QSize(480, 159));
        Dialog_Encryption->setMaximumSize(QSize(480, 159));
        PushButton_Encryption = new QPushButton(Dialog_Encryption);
        PushButton_Encryption->setObjectName(QString::fromUtf8("PushButton_Encryption"));
        PushButton_Encryption->setGeometry(QRect(410, 210, 61, 41));
        QFont font;
        font.setPointSize(12);
        PushButton_Encryption->setFont(font);
        label_6 = new QLabel(Dialog_Encryption);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 170, 71, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);
        label_6->setWordWrap(true);
        LineEdit_SN = new QLineEdit(Dialog_Encryption);
        LineEdit_SN->setObjectName(QString::fromUtf8("LineEdit_SN"));
        LineEdit_SN->setEnabled(true);
        LineEdit_SN->setGeometry(QRect(10, 210, 251, 41));
        LineEdit_SN->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        LineEdit_SN->setFont(font2);
        LineEdit_SN->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(Dialog_Encryption);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(280, 170, 81, 41));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);
        label_7->setWordWrap(true);
        LineEdit_ActiveTime = new QLineEdit(Dialog_Encryption);
        LineEdit_ActiveTime->setObjectName(QString::fromUtf8("LineEdit_ActiveTime"));
        LineEdit_ActiveTime->setEnabled(true);
        LineEdit_ActiveTime->setGeometry(QRect(280, 210, 111, 41));
        LineEdit_ActiveTime->setMaximumSize(QSize(16777215, 16777215));
        LineEdit_ActiveTime->setFont(font2);
        LineEdit_ActiveTime->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(Dialog_Encryption);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 260, 71, 41));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignCenter);
        label_8->setWordWrap(true);
        label1 = new QLabel(Dialog_Encryption);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(80, 260, 391, 41));
        QFont font3;
        font3.setPointSize(11);
        label1->setFont(font3);
        label1->setFrameShape(QFrame::StyledPanel);
        label1->setAlignment(Qt::AlignCenter);
        line = new QFrame(Dialog_Encryption);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 150, 481, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_9 = new QLabel(Dialog_Encryption);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 10, 481, 41));
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignCenter);
        label_9->setWordWrap(true);
        LineEdit_ActiveCode = new QLineEdit(Dialog_Encryption);
        LineEdit_ActiveCode->setObjectName(QString::fromUtf8("LineEdit_ActiveCode"));
        LineEdit_ActiveCode->setEnabled(true);
        LineEdit_ActiveCode->setGeometry(QRect(30, 50, 421, 41));
        LineEdit_ActiveCode->setMaximumSize(QSize(16777215, 16777215));
        LineEdit_ActiveCode->setFont(font2);
        LineEdit_ActiveCode->setEchoMode(QLineEdit::Password);
        LineEdit_ActiveCode->setAlignment(Qt::AlignCenter);
        PushButton_SendActiveCode = new QPushButton(Dialog_Encryption);
        PushButton_SendActiveCode->setObjectName(QString::fromUtf8("PushButton_SendActiveCode"));
        PushButton_SendActiveCode->setGeometry(QRect(30, 100, 421, 41));
        PushButton_SendActiveCode->setFont(font);

        retranslateUi(Dialog_Encryption);

        QMetaObject::connectSlotsByName(Dialog_Encryption);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Encryption)
    {
        Dialog_Encryption->setWindowTitle(QCoreApplication::translate("Dialog_Encryption", "Dialog", nullptr));
        PushButton_Encryption->setText(QCoreApplication::translate("Dialog_Encryption", "\345\212\240\345\257\206", nullptr));
        label_6->setText(QCoreApplication::translate("Dialog_Encryption", "SN\347\240\201", nullptr));
        LineEdit_SN->setText(QCoreApplication::translate("Dialog_Encryption", "32000000001211091900", nullptr));
        label_7->setText(QCoreApplication::translate("Dialog_Encryption", "\345\210\260\346\234\237\346\227\266\351\227\264", nullptr));
        LineEdit_ActiveTime->setText(QCoreApplication::translate("Dialog_Encryption", "20221011", nullptr));
        label_8->setText(QCoreApplication::translate("Dialog_Encryption", "\347\273\223\346\236\234", nullptr));
        label1->setText(QCoreApplication::translate("Dialog_Encryption", "-----", nullptr));
        label_9->setText(QCoreApplication::translate("Dialog_Encryption", "\346\277\200\346\264\273\347\240\201", nullptr));
        LineEdit_ActiveCode->setInputMask(QString());
        LineEdit_ActiveCode->setText(QString());
        PushButton_SendActiveCode->setText(QCoreApplication::translate("Dialog_Encryption", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Encryption: public Ui_Dialog_Encryption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ENCRYPTION_H

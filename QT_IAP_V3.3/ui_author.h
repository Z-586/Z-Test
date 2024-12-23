/********************************************************************************
** Form generated from reading UI file 'author.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHOR_H
#define UI_AUTHOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_author
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;

    void setupUi(QDialog *author)
    {
        if (author->objectName().isEmpty())
            author->setObjectName(QString::fromUtf8("author"));
        author->resize(400, 300);
        verticalLayout = new QVBoxLayout(author);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(author);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);


        retranslateUi(author);

        QMetaObject::connectSlotsByName(author);
    } // setupUi

    void retranslateUi(QDialog *author)
    {
        author->setWindowTitle(QCoreApplication::translate("author", "Dialog", nullptr));
        textEdit->setHtml(QCoreApplication::translate("author", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:20pt;\">\350\247\243\345\206\263\346\226\271\346\241\210</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:12pt;\">1.STM32F103\347\263\273\345\210\227\357\274\214STM32F407\347\263\273\345\210\227\357\274\214STM32F205\347\263\273\345\210\227\357\274\214IAP\345\215\207\347\272\247\350\247\243\345\206\263\346\226\271\346\241\210</span></p>\n"
"<p style=\" margin-top:0px; mar"
                        "gin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:12pt;\">2.S32K144\347\263\273\345\210\227\357\274\214S9KEAZ\347\263\273\345\210\227\357\274\214IAP\350\247\243\345\206\263\346\226\271\346\241\210</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:12pt;\">3.\345\215\207\347\272\247\346\226\271\345\274\217\345\214\205\346\213\254\357\274\232CAN\357\274\214\344\270\262\345\217\243\357\274\214RS485\347\255\211</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:12pt;\">4. \346\217\220\344\276\233Qt\344\270\212\344\275\215\346\234\272\350\275\257\344\273\266\345\256\232\345\210\266</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-righ"
                        "t:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:12pt;\">5. \346\217\220\344\276\233\345\215\225\347\211\207\346\234\272\350\275\257\344\273\266\345\256\232\345\210\266\345\274\200\345\217\221\357\274\214\345\214\205\346\213\254STM32\347\263\273\345\210\227\357\274\214S32K144\345\222\214S9KEAZ\347\263\273\345\210\227\347\255\211</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:12pt;\">6. \346\217\220\344\276\233\345\215\225\347\211\207\346\234\272\345\216\237\347\220\206\345\233\276\357\274\214PCB\350\256\276\350\256\241</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:12pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text"
                        "-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:12pt;\">\344\275\234\350\200\205\357\274\232\346\255\246\346\261\211\350\205\276\350\267\203\347\224\265\345\255\220\345\267\245\344\275\234\345\256\244</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:12pt;\">\350\201\224\347\263\273QQ\357\274\232 435835181</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:12pt;\">\350\201\224\347\263\273\347\224\265\350\257\235\357\274\23218086640929</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class author: public Ui_author {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHOR_H

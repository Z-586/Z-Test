/********************************************************************************
** Form generated from reading UI file 'softupdata.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOFTUPDATA_H
#define UI_SOFTUPDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_softupdata
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *soft_status;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QPushButton *updata_route_select;
    QLabel *label;
    QLineEdit *updata_route_show;
    QPushButton *Update_Run;
    QPushButton *Cancel_update;
    QProgressBar *updata_percent;

    void setupUi(QWidget *softupdata)
    {
        if (softupdata->objectName().isEmpty())
            softupdata->setObjectName(QString::fromUtf8("softupdata"));
        softupdata->resize(927, 570);
        verticalLayout_3 = new QVBoxLayout(softupdata);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_2 = new QGroupBox(softupdata);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QFont font;
        font.setPointSize(12);
        groupBox_2->setFont(font);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        soft_status = new QPlainTextEdit(groupBox_2);
        soft_status->setObjectName(QString::fromUtf8("soft_status"));

        verticalLayout_2->addWidget(soft_status);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(softupdata);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setFont(font);
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        updata_route_select = new QPushButton(groupBox_3);
        updata_route_select->setObjectName(QString::fromUtf8("updata_route_select"));
        updata_route_select->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(updata_route_select, 0, 6, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        updata_route_show = new QLineEdit(groupBox_3);
        updata_route_show->setObjectName(QString::fromUtf8("updata_route_show"));
        updata_route_show->setEnabled(true);
        updata_route_show->setAlignment(Qt::AlignCenter);
        updata_route_show->setReadOnly(false);

        gridLayout->addWidget(updata_route_show, 0, 1, 1, 5);

        Update_Run = new QPushButton(groupBox_3);
        Update_Run->setObjectName(QString::fromUtf8("Update_Run"));
        Update_Run->setMaximumSize(QSize(80, 16777215));
        Update_Run->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Update_Run, 1, 6, 1, 1);

        Cancel_update = new QPushButton(groupBox_3);
        Cancel_update->setObjectName(QString::fromUtf8("Cancel_update"));
        Cancel_update->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(Cancel_update, 1, 5, 1, 1);

        updata_percent = new QProgressBar(groupBox_3);
        updata_percent->setObjectName(QString::fromUtf8("updata_percent"));
        updata_percent->setEnabled(true);
        updata_percent->setMinimumSize(QSize(0, 20));
        updata_percent->setMaximumSize(QSize(16777215, 20));
        updata_percent->setValue(0);

        gridLayout->addWidget(updata_percent, 1, 0, 1, 5);


        verticalLayout_3->addWidget(groupBox_3);


        retranslateUi(softupdata);

        QMetaObject::connectSlotsByName(softupdata);
    } // setupUi

    void retranslateUi(QWidget *softupdata)
    {
        softupdata->setWindowTitle(QCoreApplication::translate("softupdata", "Form", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("softupdata", "\350\256\260\345\275\225", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("softupdata", "\346\223\215\344\275\234", nullptr));
        updata_route_select->setText(QCoreApplication::translate("softupdata", "\351\200\211\346\213\251\345\233\272\344\273\266", nullptr));
        label->setText(QCoreApplication::translate("softupdata", "\345\215\207\347\272\247\345\233\272\344\273\266\357\274\232", nullptr));
        Update_Run->setText(QCoreApplication::translate("softupdata", "\345\215\207\347\272\247\345\233\272\344\273\266", nullptr));
        Cancel_update->setText(QCoreApplication::translate("softupdata", "\345\217\226\346\266\210\345\215\207\347\272\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class softupdata: public Ui_softupdata {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOFTUPDATA_H

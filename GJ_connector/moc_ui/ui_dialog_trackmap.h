/********************************************************************************
** Form generated from reading UI file 'dialog_trackmap.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_TRACKMAP_H
#define UI_DIALOG_TRACKMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Dialog_TrackMap
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QCustomPlot *QCustomPlot_TrackMap;

    void setupUi(QDialog *Dialog_TrackMap)
    {
        if (Dialog_TrackMap->objectName().isEmpty())
            Dialog_TrackMap->setObjectName(QString::fromUtf8("Dialog_TrackMap"));
        Dialog_TrackMap->resize(711, 632);
        Dialog_TrackMap->setMinimumSize(QSize(711, 632));
        verticalLayout = new QVBoxLayout(Dialog_TrackMap);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Dialog_TrackMap);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        QCustomPlot_TrackMap = new QCustomPlot(Dialog_TrackMap);
        QCustomPlot_TrackMap->setObjectName(QString::fromUtf8("QCustomPlot_TrackMap"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QCustomPlot_TrackMap->sizePolicy().hasHeightForWidth());
        QCustomPlot_TrackMap->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(QCustomPlot_TrackMap);


        retranslateUi(Dialog_TrackMap);

        QMetaObject::connectSlotsByName(Dialog_TrackMap);
    } // setupUi

    void retranslateUi(QDialog *Dialog_TrackMap)
    {
        Dialog_TrackMap->setWindowTitle(QCoreApplication::translate("Dialog_TrackMap", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog_TrackMap", "\"\302\267\351\274\240\346\240\207\346\213\226\345\212\250\345\217\257\347\247\273\345\212\250\345\233\276\345\275\242    \302\267\351\274\240\346\240\207\346\273\232\350\275\256\345\217\257\347\274\251\346\224\276\345\233\276\345\275\242\"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_TrackMap: public Ui_Dialog_TrackMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_TRACKMAP_H

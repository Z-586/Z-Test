/********************************************************************************
** Form generated from reading UI file 'dlg_selectprojectmodel.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_SELECTPROJECTMODEL_H
#define UI_DLG_SELECTPROJECTMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>

QT_BEGIN_NAMESPACE

class Ui_Dlg_SelectProjectModel
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBoxSelectProjectMoudle;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dlg_SelectProjectModel)
    {
        if (Dlg_SelectProjectModel->objectName().isEmpty())
            Dlg_SelectProjectModel->setObjectName(QString::fromUtf8("Dlg_SelectProjectModel"));
        Dlg_SelectProjectModel->resize(414, 83);
        gridLayout = new QGridLayout(Dlg_SelectProjectModel);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboBoxSelectProjectMoudle = new QComboBox(Dlg_SelectProjectModel);
        comboBoxSelectProjectMoudle->addItem(QString());
        comboBoxSelectProjectMoudle->addItem(QString());
        comboBoxSelectProjectMoudle->addItem(QString());
        comboBoxSelectProjectMoudle->addItem(QString());
        comboBoxSelectProjectMoudle->addItem(QString());
        comboBoxSelectProjectMoudle->setObjectName(QString::fromUtf8("comboBoxSelectProjectMoudle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxSelectProjectMoudle->sizePolicy().hasHeightForWidth());
        comboBoxSelectProjectMoudle->setSizePolicy(sizePolicy);
        comboBoxSelectProjectMoudle->setMinimumSize(QSize(100, 20));

        gridLayout->addWidget(comboBoxSelectProjectMoudle, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(Dlg_SelectProjectModel);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(Dlg_SelectProjectModel);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dlg_SelectProjectModel, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dlg_SelectProjectModel, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dlg_SelectProjectModel);
    } // setupUi

    void retranslateUi(QDialog *Dlg_SelectProjectModel)
    {
        Dlg_SelectProjectModel->setWindowTitle(QCoreApplication::translate("Dlg_SelectProjectModel", "\351\200\211\346\213\251\351\241\271\347\233\256", nullptr));
        comboBoxSelectProjectMoudle->setItemText(0, QCoreApplication::translate("Dlg_SelectProjectModel", "VSMS1000", nullptr));
        comboBoxSelectProjectMoudle->setItemText(1, QCoreApplication::translate("Dlg_SelectProjectModel", "A920", nullptr));
        comboBoxSelectProjectMoudle->setItemText(2, QCoreApplication::translate("Dlg_SelectProjectModel", "A660", nullptr));
        comboBoxSelectProjectMoudle->setItemText(3, QCoreApplication::translate("Dlg_SelectProjectModel", "A802", nullptr));
        comboBoxSelectProjectMoudle->setItemText(4, QCoreApplication::translate("Dlg_SelectProjectModel", "A602", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Dlg_SelectProjectModel: public Ui_Dlg_SelectProjectModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_SELECTPROJECTMODEL_H

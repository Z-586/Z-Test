#include "dlg_selectprojectmodel.h"
#include "ui_dlg_selectprojectmodel.h"
#include "./global/globalsetting.h"
#include <QDebug>
namespace  {
    GlobalSetting *pGlobalSetting = GlobalSetting::getInstance();
}


Dlg_SelectProjectModel::Dlg_SelectProjectModel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_SelectProjectModel)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, [this](){
        pGlobalSetting->setMoudelType(static_cast<ProjectMoudel>(ui->comboBoxSelectProjectMoudle->currentIndex()));
        qDebug() << pGlobalSetting->getMoudelType();
    });
}

Dlg_SelectProjectModel::~Dlg_SelectProjectModel()
{
    delete ui;
}

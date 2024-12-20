#ifndef DLG_SELECTPROJECTMODEL_H
#define DLG_SELECTPROJECTMODEL_H

#include <QDialog>

namespace Ui {
class Dlg_SelectProjectModel;
}

class Dlg_SelectProjectModel : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_SelectProjectModel(QWidget *parent = nullptr);
    ~Dlg_SelectProjectModel();

private:
    Ui::Dlg_SelectProjectModel *ui;
};

#endif // DLG_SELECTPROJECTMODEL_H

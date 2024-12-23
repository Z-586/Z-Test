#ifndef SETPARAMETER_H
#define SETPARAMETER_H

#include <QDialog>


typedef struct parameterSetStruct
{

}_parameterSetStruct;


namespace Ui {
class setParameter;
}

class setParameter : public QDialog
{
    Q_OBJECT

public:
    explicit setParameter(QWidget *parent = nullptr);
    ~setParameter();
    void CfgFromUi(void);


private:
    Ui::setParameter *ui;
    void updataParameter(void);

protected:
    void closeEvent(QCloseEvent *e);


public slots:
    void CfgToUi(void);
};

#endif // SETPARAMETER_H

#include "setboard.h"
#include <QDebug>


setBoard::setBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setBoard)
{
    ui->setupUi(this);
}

setBoard::~setBoard()
{
    delete ui;
}


void setBoard::closeEvent(QCloseEvent *e)
{
    boardNewType = CfgFromUi();
}

void setBoard:: CfgToUi(_boardSetEnum dat)
{
    if( dat == STM32F103)
    {
      ui->radioButton_STM32F103->setChecked(true);
    }
    else if(dat==  STM32F407)
    {
        ui->radioButton_STM32F407->setChecked(true);
    }
    else
    {
        qDebug()<<"BoardType Parameter Error!";
    }
}

_boardSetEnum setBoard:: CfgFromUi(void)
{
    _boardSetEnum ret= STM32F103;
    if(ui->radioButton_STM32F103->isChecked() == true)
    {
        ret = STM32F103;
    }
    else if(ui->radioButton_STM32F407->isChecked() ==true)
    {
        ret = STM32F407;
    }
    return ret;
}

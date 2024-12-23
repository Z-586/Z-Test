#include "setparameter.h"
#include "ui_setparameter.h"
#include "set.h"

setParameter::setParameter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setParameter)
{
    ui->setupUi(this);
    CfgToUi();
}

setParameter::~setParameter()
{
    delete ui;
}

void setParameter:: CfgFromUi(void)
{
    QStringList Ports;
    int dat = ui->setportNumberList->count();
    for(int i=0;i<dat;i++)
    {
        Ports.append(ui->setportNumberList->itemText(i));
    }
    Set::portNumberList = Ports;
    Set::uartEn = ui->radioButton_Uart->isChecked();
    Set::currentSelectPort = ui->setportNumberList->currentText();
    Set::uartCheckSum      = ui->uartCheckSum->currentIndex();

    Set::uartBaud    =   ui->uart_baudRate->currentText().toInt();
    Set::canEn       =   ui->radioButton_Can->isChecked();
    Set::canChannel  =   ui->canChannels->currentIndex();
    Set::canDevice   =   ui->can_device->currentIndex();
    Set::canBaud     =   ui->can_baudRate->currentText().toInt();

    Set::rs485En   = ui->rs485En->isChecked();
    Set::rs485Addr = ui->rs485Addr->value();
    Set::AnswerTimeOut = ui->AnswerTimeOut->value();
    Set::CodMode    = ui->CodMode->isChecked();
}

void setParameter::CfgToUi(void)
{
    ui->radioButton_Uart->setChecked(Set::uartEn);
    ui->setportNumberList->clear();
    ui->setportNumberList->addItems(Set::portNumberList);

    ui->uart_baudRate->setCurrentText(QString("%1").arg(Set::uartBaud) );
    ui->uartCheckSum->setCurrentIndex(Set::uartCheckSum);
    ui->radioButton_Can->setChecked(Set::canEn);
    ui->canChannels->setCurrentIndex(Set::canChannel);
    ui->can_device->setCurrentIndex(Set::canDevice);

    ui->can_baudRate->setCurrentText(QString("%1").arg(Set::canBaud) );

    ui->rs485En->setChecked(Set::rs485En);
    ui->rs485Addr->setValue(Set::rs485Addr);

    ui->AnswerTimeOut->setValue(Set::AnswerTimeOut) ;
    ui->CodMode->setChecked(Set::CodMode);
}

//关闭事件
void setParameter::closeEvent(QCloseEvent *e)
{
    CfgFromUi();
}

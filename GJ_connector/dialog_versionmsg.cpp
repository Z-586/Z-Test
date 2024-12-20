#include "dialog_versionmsg.h"
#include "ui_dialog_versionmsg.h"


Dialog_VersionMsg::Dialog_VersionMsg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_VersionMsg)
{
    ui->setupUi(this);
    Dialog_VersionMsg_Init();
    get_VisionMsg();
}

Dialog_VersionMsg::~Dialog_VersionMsg()
{
    delete ui;
}

void Dialog_VersionMsg::Dialog_VersionMsg_Init()    // 初始化函数
{
    this->setWindowTitle("版本号");

    QWidget::setAttribute(Qt::WA_QuitOnClose,false);     // 所有子窗口要写false
    QWidget::setAttribute(Qt::WA_DeleteOnClose);     // 所有子窗口要写false
    setWindowFlags((windowFlags()&~Qt::WindowContextHelpButtonHint) | Qt::WindowMinimizeButtonHint);
}

void Dialog_VersionMsg::get_VisionMsg()     // 获取版本号信息
{
    QString SN = QString("%1%2%3%4%5%6")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.SN_S1, 2, 10, QLatin1Char('0'))
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.SN_D2, 9, 10, QLatin1Char('0'))
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.SN_D3, 3, 10, QLatin1Char('0'))
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.SN_D4, 2, 10, QLatin1Char('0'))
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.SN_D5, 2, 10, QLatin1Char('0'))
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.SN_D6, 2, 10, QLatin1Char('0'));

    QString Algri_Ver = QString("%1%2%3%4%5%6%7%8%9%10%11%12%13%14%15%16")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Algri_Ver_S1, 2, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Algri_Ver_S2, 2, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Algri_Ver_S3, 2, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Algri_Ver_A4, 3, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Algri_Ver_A5, 5, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Algri_Ver_A6, 3, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Algri_Ver_A7, 2, 10, QLatin1Char('0'))
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Algri_Ver_A8, 2, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Algri_Ver_A9, 2, 10, QLatin1Char('0'));

    QString BSW_Ver = QString("%1%2%3%4%5%6%7%8%9%10%11%12%13%14%15%16")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BSW_Ver_S1, 2, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BSW_Ver_S2, 2, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BSW_Ver_S3, 2, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BSW_Ver_B4, 3, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BSW_Ver_B5, 5, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BSW_Ver_B6, 3, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BSW_Ver_B7, 2, 10, QLatin1Char('0'))
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BSW_Ver_B8, 2, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BSW_Ver_B9, 2, 10, QLatin1Char('0'));

    QString BootVer_BOOT = QString("%1%2%3%4%5%6%7%8%9%10%11%12%13%14%15%16")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BootVer_BOOT_S1, 2, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BootVer_BOOT_S2, 2, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BootVer_BOOT_S3, 2, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BootVer_BOOT_C4, 3, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BootVer_BOOT_C5, 5, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BootVer_BOOT_C6, 3, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BootVer_BOOT_C7, 2, 10, QLatin1Char('0'))
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BootVer_BOOT_C8, 2, 10, QLatin1Char('0')).arg(".")
            .arg(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BootVer_BOOT_C9, 2, 10, QLatin1Char('0'));

    ui->Label_Sn->setText(SN);
    ui->Label_Algri_Ver->setText(Algri_Ver);
    ui->Label_BSW_Ver->setText(BSW_Ver);
    ui->Label_BootVer_BOOT->setText(BootVer_BOOT);
}

void Dialog_VersionMsg::Send_SNCode()   // 发送SN码
{
    if(ui->LineEdit_s1->text() == NULL ||
       ui->LineEdit_d2->text() == NULL ||
       ui->LineEdit_d3->text() == NULL ||
       ui->LineEdit_d4->text() == NULL ||
       ui->LineEdit_d5->text() == NULL ||
       ui->LineEdit_d6->text() == NULL)
    {
        QMessageBox::about(this,"提示","请完整输入各项");
        return;
    }

    SN.SN.SN_S1 = ui->LineEdit_s1->text().toInt();
    SN.SN.SN_D2 = ui->LineEdit_d2->text().toInt();
    SN.SN.SN_D3 = ui->LineEdit_d3->text().toInt();
    SN.SN.SN_D4 = ui->LineEdit_d4->text().toInt();
    SN.SN.SN_D5 = ui->LineEdit_d5->text().toInt();
    SN.SN.SN_D6 = ui->LineEdit_d6->text().toInt();
    SN.SN.CRC = base_function::Calculate_Crc8(send_SN_SendSN, SN.bytes,15);

    emit Serial_Write(base_function::Serial_DataFormat(send_SN_SendSN, SN.bytes, 16));
}


// 按钮函数
void Dialog_VersionMsg::on_PushButton_SendSN_clicked()
{
    Send_SNCode();
}

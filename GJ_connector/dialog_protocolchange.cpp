#include "dialog_protocolchange.h"
//#include "ui_dialog_protocolchange.h"
#include "./moc_ui/ui_dlg_protocol.h"


namespace{
    quint8 calculateChecksum(const quint8* data, int len)
    {
        quint8 checksum = 0;
        for (int i = 0; i < len; ++i)
        {
            checksum ^= data[i];
        }
        return checksum;
    }
}


Dialog_ProtocolChange::Dialog_ProtocolChange(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::Dlg_Protocol)
{
    ui->setupUi(this);
    Dialog_ProtocolChange_Init();
}

Dialog_ProtocolChange::~Dialog_ProtocolChange()
{
        delete ui;
        timeOut_timer->stop();
        timeOut_timer->deleteLater();
}

void Dialog_ProtocolChange::Dialog_ProtocolChange_Init()    // 初始化函数
{
    this->setWindowTitle("切换协议");

    QWidget::setAttribute(Qt::WA_QuitOnClose,false);     // 所有子窗口要写false
    QWidget::setAttribute(Qt::WA_DeleteOnClose);     // 所有子窗口要写false
    setWindowFlags((windowFlags()&~Qt::WindowContextHelpButtonHint) | Qt::WindowMinimizeButtonHint);

    connect(timeOut_timer, &QTimer::timeout, this, &Dialog_ProtocolChange::Response_TimeOut);//绑定超时

    // 将这些checkbox放到指针数组里，方便循环处理
    checkboxes[CheckBox_GJ   ] = ui->CheckBox_GJ;
    checkboxes[CheckBox_GPGGA] = ui->CheckBox_GPGGA;
    checkboxes[CheckBox_GPRMC] = ui->CheckBox_GPRMC;
    checkboxes[CheckBox_GPVTG] = ui->CheckBox_GPVTG;
    checkboxes[CheckBox_GPGLL] = ui->CheckBox_GPGLL;
    checkboxes[CheckBox_GPZDA] = ui->CheckBox_GPZDA;
    checkboxes[CheckBox_GPHDT] = ui->CheckBox_GPHDT;
    checkboxes[CheckBox_GPFPD] = ui->CheckBox_GPFPD;
    checkboxes[CheckBox_GPCHC] = ui->CheckBox_GPCHC;
    ui->lineEditCustomProtocolName->setEnabled(false);
    ui->lineEditCustomProtocolRate->setEnabled(false);
    connect(ui->CheckBoxCustomProtocol, &QCheckBox::stateChanged, [this](int state){
        ui->lineEditCustomProtocolName->setEnabled(state);
        ui->lineEditCustomProtocolRate->setEnabled(state);
        ui->frameOtherProtocol->setEnabled(!state);
    });
}

void Dialog_ProtocolChange::DefaultOptional_ButtonDisable()     // 共迹协议和可选协议，3个协议的按钮变灰函数
{
    ui->CheckBox_GJ->setChecked(false);
    ui->CheckBox_GPFPD->setChecked(false);
    ui->CheckBox_GPCHC->setChecked(false);
}

void Dialog_ProtocolChange::NMEA0183_ButtonDisable()    // NMEA0183协议，6个协议的按钮变灰函数
{
    ui->CheckBox_GPGGA->setChecked(false);
    ui->CheckBox_GPRMC->setChecked(false);
    ui->CheckBox_GPVTG->setChecked(false);
    ui->CheckBox_GPGLL->setChecked(false);
    ui->CheckBox_GPZDA->setChecked(false);
    ui->CheckBox_GPHDT->setChecked(false);
}

bool Dialog_ProtocolChange::NMEA0183_isAllButtonDisable()   // 判断NMEA0183协议，6个协议的按钮是否全部变灰函数
{
    for (int i = CheckBox_GPGGA; i<= CheckBox_GPHDT; i++)
    {
        if(checkboxes[i]->isChecked())
        {
            return false;
        }
    }
    return true;
}

void Dialog_ProtocolChange::Selete_DefaultOptional(CheckBox_Protocol Protocol)  // 当改变了共迹协议和可选协议中某一个按钮时触发
{
    if(checkboxes[Protocol]->isChecked())
    {
        DefaultOptional_ButtonDisable();
        NMEA0183_ButtonDisable();
        checkboxes[Protocol]->setChecked(true);
    }
    else
    {
        checkboxes[Protocol]->setChecked(true);
    }
}

void Dialog_ProtocolChange::Selete_NMEA0183(CheckBox_Protocol Protocol) // 当改变了NMEA0183协议中某一个按钮时触发
{
    if(checkboxes[Protocol]->isChecked())
    {
        DefaultOptional_ButtonDisable();
    }
    else
    {
        if(NMEA0183_isAllButtonDisable())
        {
            checkboxes[CheckBox_GJ]->setChecked(true);
        }
    }

}

void Dialog_ProtocolChange::Change_DeviceProtocol()     // 发送频率以及选择的协议给底层
{

    if(ui->CheckBoxCustomProtocol->isChecked())
    {
        CustomProtocolBuf_t txMsg;
        QByteArray byteArray = ui->lineEditCustomProtocolName->text().toUtf8();
        memcpy(txMsg.msg.protocolName, byteArray.constData(),
                      qMin(byteArray.size(), static_cast<int>(sizeof(txMsg.msg.protocolName) - 1)));
        txMsg.msg.protocolName[qMin(byteArray.size(), static_cast<int>(sizeof(txMsg.msg.protocolName) - 1))] = '\0';
        txMsg.msg.rate = ui->lineEditCustomProtocolRate->text().toUInt();

        txMsg.buf[CUSTOM_LEN-1] = 0;
        quint8 checkSum = calculateChecksum(txMsg.buf, CUSTOM_LEN-1);
        txMsg.buf[CUSTOM_LEN-1] = checkSum;
        emit Serial_Write(base_function::Serial_DataFormat(sendCustomProtocolHead, txMsg.buf, CUSTOM_LEN));
    }

    else
    {
        ProtocolChange.ProtocolChange.Protocol_sel = 0;
        for(int i = CheckBox_GJ;i<=CheckBox_GPCHC;i++){
            if(checkboxes[i]->isChecked()){
                ProtocolChange.ProtocolChange.Protocol_sel += 1<<(i-1);
            }
        }
        switch (ui->ComboBox_Protocol_Frequency->currentIndex()) {
            case 0:
                ProtocolChange.ProtocolChange.Frequency = 100;
                break;
            case 1:
                ProtocolChange.ProtocolChange.Frequency = 20;
                break;
            case 2:
                ProtocolChange.ProtocolChange.Frequency = 10;
                break;
            case 3:
                ProtocolChange.ProtocolChange.Frequency = 1;
                break;
        }
        ProtocolChange.ProtocolChange.BaudRate = ui->ComboBox_Protocol_BaudRate->currentText().toUInt();

        emit Serial_Write(base_function::Serial_DataFormat(send_Protocol_Change, ProtocolChange.bytes, 7));


    }
    Switch_Timer(true);
}

void Dialog_ProtocolChange::receiveACK_ChangeProtocolOK_head()
{
    Switch_Timer(false);
    QMessageBox::about(this,"提示", " 切换成功 ");
}

void Dialog_ProtocolChange::slot_recCustomProtocolResponse()
{
    Switch_Timer(false);
    QMessageBox::about(this,"提示", " 切换成功 ");
}

void Dialog_ProtocolChange::Switch_Timer(bool state)
{
    if(state)
    {
        // 开启计时器
        timeOut_timer->start(3 * 1000);
        // 限制用户操作
        ui->PushButton_ProtocolChange->setText("切换中");
        ui->PushButton_ProtocolChange->setEnabled(!state);
    }
    else
    {
        // 关闭计时器
        timeOut_timer->stop();
        // 释放用户操作
        ui->PushButton_ProtocolChange->setText("切换");
        ui->PushButton_ProtocolChange->setEnabled(!state);

    }
}

void Dialog_ProtocolChange::Response_TimeOut()
{
            // 关闭计时器
    QMessageBox::about(this,"提示", " 切换失败 ");
    Switch_Timer(false);
}
// Button SLOTS
// 所有按钮信号槽
void Dialog_ProtocolChange::on_CheckBox_GJ_clicked()
{
    Selete_DefaultOptional(CheckBox_GJ);
}

void Dialog_ProtocolChange::on_CheckBox_GPGGA_clicked()
{
    Selete_NMEA0183(CheckBox_GPGGA);
}

void Dialog_ProtocolChange::on_CheckBox_GPRMC_clicked()
{
    Selete_NMEA0183(CheckBox_GPRMC);
}

void Dialog_ProtocolChange::on_CheckBox_GPVTG_clicked()
{
    Selete_NMEA0183(CheckBox_GPVTG);
}

void Dialog_ProtocolChange::on_CheckBox_GPGLL_clicked()
{
    Selete_NMEA0183(CheckBox_GPGLL);
}

void Dialog_ProtocolChange::on_CheckBox_GPZDA_clicked()
{
    Selete_NMEA0183(CheckBox_GPZDA);
}

void Dialog_ProtocolChange::on_CheckBox_GPHDT_clicked()
{
    Selete_NMEA0183(CheckBox_GPHDT);
}

void Dialog_ProtocolChange::on_CheckBox_GPFPD_clicked()
{
    Selete_DefaultOptional(CheckBox_GPFPD);
}

void Dialog_ProtocolChange::on_CheckBox_GPCHC_clicked()
{
    Selete_DefaultOptional(CheckBox_GPCHC);
}

void Dialog_ProtocolChange::on_PushButton_ProtocolChange_clicked()
{
    Change_DeviceProtocol();
}

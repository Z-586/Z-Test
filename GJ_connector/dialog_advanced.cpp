#include "dialog_advanced.h"
#include "./moc_ui/ui_dialog_advanced.h"

static quint8 calculateChecksum(const quint8* data, int len)
{
    quint8 checksum = 0;
    for (int i = 0; i < len; ++i)
    {
        checksum ^= data[i];
    }
    return checksum;
}

Dialog_advanced::Dialog_advanced(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_advanced)
{
    ui->setupUi(this);
    Dialog_Advanced_Init();
}

Dialog_advanced::~Dialog_advanced()
{
    delete ui;
}

// Init
void Dialog_advanced::Dialog_Advanced_Init()      // 初始化函数
{
    this->setWindowTitle("高级功能");

    QWidget::setAttribute(Qt::WA_QuitOnClose,false);     // 所有子窗口要写false
    QWidget::setAttribute(Qt::WA_DeleteOnClose);     // 所有子窗口要写false
    setWindowFlags((windowFlags()&~Qt::WindowContextHelpButtonHint) | Qt::WindowMinimizeButtonHint);

    ui->frameEthernet->setVisible(false);
    //选第三种的时候，可见
    connect(ui->comboBox_rtcm_select, QOverload<int>::of(&QComboBox::currentIndexChanged), [this](int idx){
        ui->frameEthernet->setVisible(idx == 2? 1:0);
    });

    connect(timeOut_timer, &QTimer::timeout, this, &Dialog_advanced::Response_TimeOut);//关联计时器

    connect(ui->btnRead, &QPushButton::clicked, [this](){
        emit Serial_Write(QString(send_ReadETHCfg_data).toUtf8().data());
        timeOut_timer->start(3 * 1000);
    });

}

void Dialog_advanced::Response_TimeOut()
{
    // 关闭计时器
    QMessageBox::about(this,"提示", " 切换失败 ");
    // 关闭计时器
    timeOut_timer->stop();
}

void Dialog_advanced::receiveACK_RTCMSelectType_head()
{
    // 关闭计时器
    timeOut_timer->stop();
    QMessageBox::about(this,"提示", " 切换成功 ");
}

void Dialog_advanced::slot_recETHCfg_Ack()
{
    timeOut_timer->stop();
    QMessageBox::about(this,"提示", " 配置成功 ");
}

void Dialog_advanced::slot_recETHCfg_ReturnData(QByteArray data)
{
    timeOut_timer->stop();
    ETHCfgMsg_t txMsg;
    memcpy(&txMsg, data.constData(), sizeof(txMsg));
    ui->checkBoxETH_enable->setChecked(txMsg.ETHCfginfo.enable);
    ui->lineEdit_IP1->setText(QString::number(txMsg.ETHCfginfo.ip[0], 10));
    ui->lineEdit_IP2->setText(QString::number(txMsg.ETHCfginfo.ip[1], 10));
    ui->lineEdit_IP3->setText(QString::number(txMsg.ETHCfginfo.ip[2], 10));
    ui->lineEdit_IP4->setText(QString::number(txMsg.ETHCfginfo.ip[3], 10));
    ui->lineEdit_port->setText(QString::number(txMsg.ETHCfginfo.ipPort, 10));

    QString txt = QString::fromUtf8(txMsg.ETHCfginfo.accountNum, sizeof(txMsg.ETHCfginfo.accountNum));

    ui->lineEditAccountNumber->setText(txt);

    txt =  QString::fromUtf8(txMsg.ETHCfginfo.accountPwd, sizeof(txMsg.ETHCfginfo.accountPwd));
    ui->lineEditAccountPassword->setText(txt);

    QMessageBox::about(this,"提示", " 读取成功 ");
}

//void Dialog_advanced::receiveACK_StaticIPPort_head()
//{
//    timeOut_timer->stop();
//    QMessageBox::about(this,"提示", " IP及端口号配置成功 ");
//}

void Dialog_advanced::on_pushButton_clicked()
{
    if(ui->comboBox_rtcm_select->currentText() != "Ethernet")
    {
        RTCMSelectBut_t tx_msg;
        if (ui->comboBox_rtcm_select->currentText() == "内置DTU") {
            tx_msg.data.SelectType.internal_dtu_or_external_rs232 = 1;
        }
        if (ui->comboBox_rtcm_select->currentText() == "外置") {
            tx_msg.data.SelectType.internal_dtu_or_external_rs232 = 0;
        }

        emit Serial_Write(base_function::Serial_DataFormat(send_RTCMSelectType_SendCanMsg, tx_msg.buf, AA44CC5A_MSG_LEN));
    }
    else
    {
        ETHCfgMsg_t txMsg;
        txMsg.ETHCfginfo.enable = ui->checkBoxETH_enable->isChecked();
        txMsg.ETHCfginfo.ip[0] = ui->lineEdit_IP1->text().toUInt();
        txMsg.ETHCfginfo.ip[1] = ui->lineEdit_IP2->text().toUInt();
        txMsg.ETHCfginfo.ip[2] = ui->lineEdit_IP3->text().toUInt();
        txMsg.ETHCfginfo.ip[3] = ui->lineEdit_IP4->text().toUInt();

        for(int i=0;i<4;i++)
        {
            if(txMsg.ETHCfginfo.ip[i]<0||txMsg.ETHCfginfo.ip[3]>255)
            {
                QMessageBox::about(this,"警告", " IP地址格式错误，配置失败 ");
                return;
            }
        }

        txMsg.ETHCfginfo.ipPort = ui->lineEdit_port->text().toUInt();
        if(txMsg.ETHCfginfo.ipPort < 1||txMsg.ETHCfginfo.ipPort>0xFFFFFFFF)
        {
            QMessageBox::about(this,"警告", " 端口号格式错误，配置失败 ");
            return;
        }

        QByteArray byteArray = ui->lineEditAccountNumber->text().toUtf8();
        memcpy(txMsg.ETHCfginfo.accountNum, byteArray.constData(),
                      qMin(byteArray.size(), static_cast<int>(sizeof(txMsg.ETHCfginfo.accountNum) - 1)));
        txMsg.ETHCfginfo.accountNum[qMin(byteArray.size(), static_cast<int>(sizeof(txMsg.ETHCfginfo.accountNum) - 1))] = '\0';

        byteArray.clear();
        byteArray = ui->lineEditAccountPassword->text().toUtf8();
        memcpy(txMsg.ETHCfginfo.accountPwd, byteArray.constData(),
                      qMin(byteArray.size(), static_cast<int>(sizeof(txMsg.ETHCfginfo.accountPwd) - 1)));
        txMsg.ETHCfginfo.accountPwd[qMin(byteArray.size(), static_cast<int>(sizeof(txMsg.ETHCfginfo.accountPwd) - 1))] = '\0';
        txMsg.buf[ETH_BUF_LEN - 1] = 0;
        quint8 checksum = calculateChecksum(txMsg.buf, ETH_BUF_LEN - 1);
        txMsg.buf[ETH_BUF_LEN - 1] = checksum;

        emit Serial_Write(base_function::Serial_DataFormat(send_ETHCfg_Uartdata, txMsg.buf, ETH_BUF_LEN));

    }
   timeOut_timer->start(3 * 1000);

}

//void Dialog_advanced::on_pushButton_sendIP_clicked()
//{
//    IPData_Buf_t tx_msg;
//    tx_msg.IPData.IP[0] = ui->lineEdit_IP1->text().toUInt();
//    tx_msg.IPData.IP[1] = ui->lineEdit_IP2->text().toUInt();
//    tx_msg.IPData.IP[2] = ui->lineEdit_IP3->text().toUInt();
//    tx_msg.IPData.IP[3] = ui->lineEdit_IP4->text().toUInt();
//    for(int i=0;i<4;i++)
//    {
//        if(tx_msg.IPData.IP[i]<0||tx_msg.IPData.IP[3]>255)
//        {
//            QMessageBox::about(this,"警告", " IP地址格式错误，配置失败 ");
//            return;
//        }
//    }

//    tx_msg.IPData.port = ui->lineEdit_port->text().toUInt();
//    if(tx_msg.IPData.port<1||tx_msg.IPData.port>9999)
//    {
//        QMessageBox::about(this,"警告", " 端口号格式错误，配置失败 ");
//        return;
//    }

//    emit Serial_Write(base_function::Serial_DataFormat(send_StaticIPPort_SendMsg, tx_msg.buf, AA44CC5B_MSG_LEN));

//    timeOut_timer->start(3 * 1000);
//}

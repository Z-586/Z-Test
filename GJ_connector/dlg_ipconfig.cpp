#include "dlg_ipconfig.h"
#include "ui_dlg_ipconfig.h"
#include <QTimer>
#include <QMessageBox>

Dlg_ipConfig::Dlg_ipConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_ipConfig)
  , pCheckTimer_(new QTimer{this})
{
    ui->setupUi(this);
    this->setWindowTitle("IP配置");


    connect(ui->pushButton_sendIP, &QPushButton::clicked, [&](){
        IPData_Buf_t tx_msg;
            tx_msg.IPData.IP[0] = ui->lineEdit_IP1->text().toUInt();
            tx_msg.IPData.IP[1] = ui->lineEdit_IP2->text().toUInt();
            tx_msg.IPData.IP[2] = ui->lineEdit_IP3->text().toUInt();
            tx_msg.IPData.IP[3] = ui->lineEdit_IP4->text().toUInt();
            for(int i=0;i<4;i++)
            {
                if(tx_msg.IPData.IP[i]<0||tx_msg.IPData.IP[3]>255)
                {
                    QMessageBox::about(this,"警告", " IP地址格式错误，配置失败 ");
                    return;
                }
            }

            tx_msg.IPData.port = ui->lineEdit_port->text().toUInt();
            if(tx_msg.IPData.port<1||tx_msg.IPData.port>9999)
            {
                QMessageBox::about(this,"警告", " 端口号格式错误，配置失败 ");
                return;
            }

            emit sig_Serial_Write(base_function::Serial_DataFormat(send_StaticIPPort_SendMsg, tx_msg.buf, AA44CC5B_MSG_LEN));

            if(pCheckTimer_)
            {
                pCheckTimer_->start(3 * 1000);
            }

    });
    connect(pCheckTimer_, &QTimer::timeout, [this](){
        QMessageBox::information(this, "提示", "切换失败");
        pCheckTimer_->stop();
    });

}

Dlg_ipConfig::~Dlg_ipConfig()
{
    delete ui;
}

void Dlg_ipConfig::slot_receiveACK_StaticIPPort_head()
{
    pCheckTimer_->stop();
    QMessageBox::about(this,"提示", " IP及端口号配置成功 ");
}

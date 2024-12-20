#ifndef DIALOG_ADVANCED_H
#define DIALOG_ADVANCED_H

#include "MainWindow.h"

#define AA44CC5A_MSG_LEN 12
//#define AA44CC5B_MSG_LEN 6
namespace  {
    const int ETH_BUF_LEN = 50;
}
namespace Ui {
class Dialog_advanced;

}


class Dialog_advanced : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_advanced(QWidget *parent = nullptr);
    ~Dialog_advanced();

    void Dialog_Advanced_Init();
    void Response_TimeOut();
    void receiveACK_ChangeSelectOK_head();
#pragma pack(push, 1)
    typedef struct
    {
        struct
        {
            uint8_t internal_dtu_or_external_rs232 : 1;
            //uint8_t external_rs232 : 1;
            uint8_t reserved : 7;
        }SelectType;
        uint8_t reseved[11];
    }RTCMSelectMsg_t;

    typedef union
    {
        RTCMSelectMsg_t data;
        uint8_t buf[AA44CC5A_MSG_LEN];
    }RTCMSelectBut_t;

    typedef struct ETHCfg
    {

        quint8 enable;
        quint8 ip[4];
        quint32 ipPort;
        char accountNum[20];
        char accountPwd[20];
        quint8 checksum;
    }ETHCfg_t;
    typedef union
    {
        ETHCfg_t ETHCfginfo;
        quint8 buf[ETH_BUF_LEN];

    }ETHCfgMsg_t;
#pragma pack(pop)
private slots:
    void on_pushButton_clicked();

    //void on_pushButton_sendIP_clicked();

private:
    Ui::Dialog_advanced *ui;

    QTimer *timeOut_timer = new QTimer(this);   // 标定握手超时判断计时器

signals:
    // 串口调用发送信号
    void Serial_Write(QByteArray);

public slots:

    void receiveACK_RTCMSelectType_head();
    void slot_recETHCfg_Ack();

    void slot_recETHCfg_ReturnData(QByteArray data);
    //void receiveACK_StaticIPPort_head();

};

#endif // DIALOG_ADVANCED_H

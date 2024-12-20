#ifndef DIALOG_VERSIONMSG_H
#define DIALOG_VERSIONMSG_H

#include "MainWindow.h"

namespace Ui {
class Dialog_VersionMsg;
}

class Dialog_VersionMsg : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_VersionMsg(QWidget *parent = nullptr);
    ~Dialog_VersionMsg();

public:
    typedef struct SN
    {

        uint8_t SN_S1;
        uint32_t SN_D2;
        uint8_t SN_D3;
        uint8_t SN_D4;
        uint8_t SN_D5;
        uint8_t SN_D6;
        uint8_t reserved[6];
        uint8_t CRC;
    }SN_t;

    typedef union SN_Buf
    {
        SN_t SN;
        uint8_t bytes[16] = {0};
    }SN_Buf_t;

private:
    Ui::Dialog_VersionMsg *ui;
    SN_Buf_t SN;

public:

private:
    void Dialog_VersionMsg_Init();  // 初始化函数
    void get_VisionMsg();   // 获取版本号信息
    void Send_SNCode();     // 发送SN码


private slots:
    // 按钮函数
    void on_PushButton_SendSN_clicked();

signals:
    // 串口调用发送信号
    void Serial_Write(QByteArray);
};

#endif // DIALOG_VERSIONMSG_H

#ifndef DIALOG_FIRMWARE_H
#define DIALOG_FIRMWARE_H

#include "MainWindow.h"
#include <QCloseEvent>

namespace Ui {
class Dialog_FirmWare;
}

class Dialog_FirmWare : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_FirmWare(QWidget *parent = nullptr);
    ~Dialog_FirmWare();

public:
    void closeEvent(QCloseEvent *);

private:
    Ui::Dialog_FirmWare *ui;

    QString FileName_Path;
    QTimer *FirmWareFile_sendtimer = new QTimer(this);

    uint8_t close_Flag = 0;

    bool rangeBar;

public:

private:
    void Dialog_FirmWare_Init();    // 初始化函数
    void FirmWare_ButtonState(bool Selete, bool Updata, bool Complete); // 三个按钮的使能控制，第一个按钮只有在更新中时变灰，第二个按钮只有在读取文件或者发送完成后变亮，第三个只有在发送成功后变亮
    void Selete_FirmWare_File();    // 选择固件更新文件
    void Send_FirmWare_File();    // 发送固件
    void WaitUpdate_FirmWare_File();    // 等待固件更新
    void FirmWareFile_sendtimeout();    // 超时会根据提示来判断什么阶段超时了

public slots:
    // 上位机收到底层发送的消息码
    void receive_Firmware_PleaseWaitUpdata_head();
    void receive_Firmware_ReceiveError_head();
    void receive_Firmware_FileError_head();
    void receive_Firmware_UpdataError_head();
    void receive_Firmware_UpdataSuccess_head();

private slots:
    // 所有按钮信号槽
    void on_PushButton_FirmWare_SeleteFile_clicked();
    void on_PushButton_FirmWare_Updata_clicked();
    void on_PushButton_FirmWare_Complete_clicked();

signals:
    // 串口调用发送信号
    void Serial_Write(QByteArray);
};

#endif // DIALOG_FIRMWARE_H

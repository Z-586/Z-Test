#ifndef DIALOG_PROTOCOLCHANGE_H
#define DIALOG_PROTOCOLCHANGE_H

#include <MainWindow.h>

namespace Ui {
class Dlg_Protocol;
}


const int CUSTOM_LEN = 18;

class Dialog_ProtocolChange : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_ProtocolChange(QWidget *parent = 0);
    ~Dialog_ProtocolChange();

public:
    typedef enum
    {
        CheckBox_GJ = 0,
        CheckBox_GPGGA,
        CheckBox_GPRMC,
        CheckBox_GPVTG,
        CheckBox_GPGLL,
        CheckBox_GPZDA,
        CheckBox_GPHDT,
        CheckBox_GPFPD,
        CheckBox_GPCHC,
    }CheckBox_Protocol;

    typedef struct ProtocolChange
    {
        uint16_t Protocol_sel;
        uint8_t Frequency;
        uint32_t BaudRate;
    }ProtocolChange_t;

    typedef union ProtocolChange_Buf
    {
        ProtocolChange_t ProtocolChange;
        uint8_t bytes[7] = {0};
    }ProtocolChange_Buf_t;
#pragma pack(push, 1)
    typedef struct CustomProtocol
    {
        char protocolName[15];
        quint16 rate;
        quint8 checksum;
    }CustomProtocol_t;

    typedef union CustomProtocolBuf
    {
        CustomProtocol_t msg;
        quint8 buf[CUSTOM_LEN];
    }CustomProtocolBuf_t;
#pragma pack(pop)

private:
    Ui::Dlg_Protocol *ui;

    QCheckBox *checkboxes[Kindof_Protocol]; // 协议选择checkbox的指针数组
    ProtocolChange_Buf_t ProtocolChange;

    QTimer *timeOut_timer = new QTimer(this);   // 标定握手超时判断计时器

public:

private:
    void Dialog_ProtocolChange_Init();      // 初始化函数
    void DefaultOptional_ButtonDisable();   // 共迹协议和可选协议，3个协议的按钮变灰函数
    void NMEA0183_ButtonDisable();          // NMEA0183协议，6个协议的按钮变灰函数
    bool NMEA0183_isAllButtonDisable();     // 判断NMEA0183协议，6个协议的按钮是否全部变灰函数
    void Selete_DefaultOptional(CheckBox_Protocol Protocol);    // 当改变了共迹协议和可选协议中某一个按钮时触发
    void Selete_NMEA0183(CheckBox_Protocol Protocol);   // 当改变了NMEA0183协议中某一个按钮时触发

    void Change_DeviceProtocol();   // 发送频率以及选择的协议给底层

    void Switch_Timer(bool state);      // 计时器开关函数，来判断时候握手超时
    void Response_TimeOut();

public slots:

    void receiveACK_ChangeProtocolOK_head();
    void slot_recCustomProtocolResponse();

private slots:
    // 所有按钮信号槽
    void on_CheckBox_GJ_clicked();
    void on_CheckBox_GPGGA_clicked();
    void on_CheckBox_GPRMC_clicked();
    void on_CheckBox_GPVTG_clicked();
    void on_CheckBox_GPGLL_clicked();
    void on_CheckBox_GPZDA_clicked();
    void on_CheckBox_GPHDT_clicked();
    void on_CheckBox_GPFPD_clicked();
    void on_CheckBox_GPCHC_clicked();
    void on_PushButton_ProtocolChange_clicked();

signals:
    // 串口调用发送信号
    void Serial_Write(QByteArray);
};
#endif // DIALOG_PROTOCOLCHANGE_H

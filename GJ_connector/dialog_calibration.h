#ifndef DIALOG_CALIBRATION_H
#define DIALOG_CALIBRATION_H

#include "MainWindow.h"
#include "workerthread.h"

namespace Ui {
class Dialog_Calibration;
}

class Dialog_Calibration : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Calibration(QWidget *parent = 0);
    ~Dialog_Calibration();

public:
    typedef struct Calibration_Level1
    {
        int16_t LeverOutput[3];
        uint8_t reserved[9];
        uint8_t CRC;
    }Calibration_Level1_t;

    typedef union Calibration_Level1_Buf
    {
        Calibration_Level1_t Calibration_Level1;
        uint8_t bytes[16] = {0};
    }Calibration_Level1_Buf_t;

    typedef struct Calibration_Level2
    {
        int16_t level[3];
        int16_t AngGNSS2Vehicle[3];
        int16_t AngIMU2Vehicle[3];
        uint8_t reserved[21];
        uint8_t CRC;
    }Calibration_Level2_t;

    typedef union Calibration_Level2_Buf
    {
        Calibration_Level2_t Calibration_Level2;
        uint8_t bytes[40] = {0};
    }Calibration_Level2_Buf_t;

    typedef struct Calibration_Level3
    {
        float LeverINS2Rear[3];
        uint8_t CRC;
    }Calibration_Level3_t;

    typedef union Calibration_Level3_Buf
    {
        Calibration_Level3_t Calibration_Level3;
        uint8_t bytes[13] = {0};
    }Calibration_Level3_Buf_t;

    typedef struct Calibration_Level4
    {
        float  FrontWheelBase,RearWheelBase,WheelBase;
        uint8_t CRC;
    }Calibration_Level4_t;

    typedef union Calibration_Level4_Buf
    {
        Calibration_Level4_t Calibration_Level4;
        uint8_t bytes[13] = {0};
    }Calibration_Level4_Buf_t;

private:
    Ui::Dialog_Calibration *ui;

    Calibration_Level1_Buf_t calibration_level1_data;   // 输出点相对惯导的位置 结构体
    Calibration_Level2_Buf_t calibration_level2_data;   // GNSS双天线相对车身的角度、GNSS主天线相对惯导的位置、惯导相对车身的角度 结构体
    Calibration_Level3_Buf_t calibration_level3_data;   // 前轮距、后轮距、轴距 结构体
    Calibration_Level4_Buf_t calibration_level4_data;   // 前后轮中心相对INS位置 结构体

    QTimer *Calibration_sendtimer = new QTimer(this);   // 标定握手超时判断计时器
    QString send_Calibration_head = "";                 // 最后一次执行的操作名称

    bool flag_ui_init = true;

    WorkerThread* updateThread = nullptr;
    QTimer *selectDynamicTimer_ = nullptr;
private:
    void Dialog_Calibration_Init();             // 初始化函数
    void Send_Level1Data();                     // 发送输出点相对惯导的位置
    void Send_Level2Data();                     // 发送GNSS双天线相对车身的角度、GNSS主天线相对惯导的位置、惯导相对车身的角度
    void Send_Level3Data();                     // 发送前轮距、后轮距、轴距
    void Send_Level4Data();                     // 发送前后轮中心相对INS位置
    void Get_CurLevel_data();                   // 将当前存在底层的输出点相对惯导的位置、GNSS双天线相对车身的角度、GNSS主天线相对惯导的位置、惯导相对车身的角度输出

    void Calibration_Static();                  // 静态标定
    void Calibration_Dynamic();                 // 动态标定
    void Calibration_Cancle();                  // 取消动态静态标定
    void Calibration_SaveResult();              // 保存动态标定结果
    void Calibration_ButtonState(bool state);   // 设计各种按钮状态
    void Calibration_SetTimer(bool state);      // 计时器开关函数，来判断时候握手超时

    void Calibration_Timeout();                 // 握手超时函数



public slots:
    // 上位机收到底层发送的确认消息码
    void receiveACK_Calibration_UserInstallationAngle_head();
    void receiveACK_Calibration_SystemInstallationAangle_head();
    void receiveACK_Calibration_Static_head();
    void receiveACK_Calibration_Dynamic_head();
    void receiveACK_Calibration_Cancel_head();
    void receiveACK_Calibration_SaveResult_head();
    void receiveACK_Calibration_WheelBase_head();
    void receiveACK_Calibration_LeverINS2Rear_head();

    // 上位机收到底层发送的消息码
    void receive_Calibration_StaticCalibrating_head();
    void receive_Calibration_StaticSuccess_head();
    void receive_Calibration_DynamicCalibrating_head();
    void receive_Calibration_IncTurningRatio_head();
    void receive_Calibration_IncForwardRatio_head();
    void receive_Calibration_PleaseChangeCaliSites_head();
    void receive_Calibration_DynamicSuccess_head();

    //刷新实时动态标定数据
    void updateDynamicCaliData();
private slots:
    // 所有按钮信号槽
    void on_PushButton_Lever1_Send_clicked();
    void on_PushButton_Lever2_Send_clicked();
    void on_PushButton_Lever3_Send_clicked();
    void on_PushButton_Lever4_Send_clicked();
    void on_PushButton_CurLever_Get_clicked();
    void on_PushButton_Calibration_Static_clicked();
    void on_PushButton_Calibration_Dynamic_clicked();
    void on_PushButton_Calibration_SaveResult_clicked();
    void on_PushButton_Calibration_AbandonResult_clicked();

signals:
    // 串口调用发送信号
    void Serial_Write(QByteArray);
};

#endif // DIALOG_CALIBRATION_H

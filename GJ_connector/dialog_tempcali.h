#ifndef DIALOG_CALI_T_H
#define DIALOG_CALI_T_H

#include "MainWindow.h"

namespace Ui {
class Dialog_TempCali;
}

class Dialog_TempCali : public QDialog
{
        Q_OBJECT

public:
        explicit Dialog_TempCali(QWidget *parent = 0);
        ~Dialog_TempCali();

public:

#pragma pack(push, 1)
    typedef struct TempCali_Msg
    {
        int16_t Temp;
        int16_t AccBias[3];
        int16_t GyroBias[3];
        float Matrix_Ka[9];
        float Matrix_Kg[9];
        float Matrix_G[9];
    }TempCali_Msg_t;

    typedef union TempCali_MsgBuf
    {
        TempCali_Msg_t TempCali_Msg;
        uint8_t bytes[122] = {0};
    }TempCali_MsgBuf_t;
#pragma unpack(pop)


private:
    Ui::Dialog_TempCali *ui;

    QString fileName_path = "";

    int TempCali_File_RightData_number = 0;     // 文件里正确温度的个数
    int TempCali_File_ErrorData_number = 0;     // 文件里错误数据的个数
    int TempCali_File_OverflowData_number = 0;  // 文件里，温度点个数超出50个的数量

    int TempCali_ShouldSendData_number = 0;     // 当前应该向设备发送的温度编号

    TempCali_MsgBuf_t TempCaliData[50];     //

public:


private:
    void Dialog_TempCali_Init();    // 初始化函数
    void TempCali_VariablesInit();  // 温度标定的变量初始化函数
    void TempCali_ButtonState(bool Read, bool Send, bool Stop); // 所有按钮使能控制
    void Read_TempCali_File();      // 读稳定标定数据
    void FindTrueData_TempCali_File(QString FileContent_String);// 寻找正确数据
    void ProcessTrueData_TempCali_File(QStringList FileContent_StringList); // 开始处理正确数据
    void Display_Msg_TempCali_File();   // 显示结果

    void Send_TempCali_Data();  // 发送温度标定数据
    void DisplayState_Send_TempCali_Data(); // 展示发送的状态
    void StopSend_TempCali_Data();  // 停止发送

    void Display_TempCali_DeviceHasSavedData(int num);  // 根据板子反馈消息，展示已经存在板子里的温度标定数据
    void Display_TempCali_PrePage();    // 上一个温度的信息
    void Display_TempCali_NextPage();   // 下一个温度的信息

public slots:
    // 上位机收到底层发送的消息码
    void receive_TempCali_RequestData_head();
    void receive_TempCali_RepeatData_head();
    void receive_TempCali_CompleteData_head();
    void receive_TempCali_DeviceHasSavedData_head(QByteArray data);

private slots:
    // 所有按钮信号槽
    void on_PushButton_TempCali_ReadFile_clicked();
    void on_PushButton_TempCali_SendFile_clicked();
    void on_PushButton_TempCali_StopSendFile_clicked();
    void on_PushButton_pre_clicked();
    void on_PushButton_next_clicked();

signals:
    // 串口调用发送信号
    void Serial_Write(QByteArray);
};


#endif

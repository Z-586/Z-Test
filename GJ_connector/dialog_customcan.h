#ifndef DIALOG_CUSTOMCAN_H
#define DIALOG_CUSTOMCAN_H

#include <QDialog>
#include "base_function.h"
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QSettings>
#include <QFileDialog>
#include "MainWindow.h"

namespace Ui {
class Dialog_CustomCan;
}

class Dialog_CustomCan : public QDialog
{
        Q_OBJECT

public:
        explicit Dialog_CustomCan(QWidget *parent = 0);
        ~Dialog_CustomCan();

public:
    typedef union CanControlMsg // 使能，1表示有该帧，0表示无该帧
    {
        struct
        {
           uint8_t VehicleSpd_En:1;
           uint8_t FLWheelSpd_En:1;
           uint8_t FRWheelSpd_En:1;
           uint8_t RLWheelSpd_En:1;
           uint8_t RRWheelSpd_En:1;
           uint8_t Gear_EN:1;
           uint8_t InterorMotorola:1;
           uint8_t reserved:1;
        }b;
        uint8_t byte;
    }CanControlMsg_t;
    typedef union CanSymbolMsg  // 符号位，1表示有符号数，0表示无符号数
    {
        struct
        {
           uint8_t VehicleSpd_UorI:1;
           uint8_t FLWheelSpd_UorI:1;
           uint8_t FRWheelSpd_UorI:1;
           uint8_t RLWheelSpd_UorI:1;
           uint8_t RRWheelSpd_UorI:1;
           uint8_t Gear_UorI:1;
           uint8_t reserved:2;
        }b;
        uint8_t byte;
    }CanSymbolMsg_t;
    typedef union CanUnitMsg    // 单位，0表示m/s，1表示km/h
    {
        struct
        {
           uint8_t VehicleSpd_Unit:1;
           uint8_t FLWheelSpd_Unit:1;
           uint8_t FRWheelSpd_Unit:1;
           uint8_t RLWheelSpd_Unit:1;
           uint8_t RRWheelSpd_Unit:1;
           uint8_t reserved:3;
        }b;
        uint8_t byte;
    }CanUnitMsg_t;
    typedef struct GJDeVice_CAN_Msg
    {
        CanControlMsg_t CanControlMsg;
        CanSymbolMsg_t CanSymbolMsg;
        CanUnitMsg_t CanUnitMsg;

        uint32_t VehicleSpd_ID;
        uint8_t  VehicleSpd_Start;
        uint8_t  VehicleSpd_Length;
        float    VehicleSpd_Offset;
        float    VehicleSpd_Factor;

        uint32_t FLWheelSpd_ID;
        uint8_t  FLWheelSpd_Start;
        uint8_t  FLWheelSpd_Length;
        float    FLWheelSpd_Offset;
        float    FLWheelSpd_Factor;

        uint32_t FRWheelSpd_ID;
        uint8_t  FRWheelSpd_Start;
        uint8_t  FRWheelSpd_Length;
        float    FRWheelSpd_Offset;
        float    FRWheelSpd_Factor;

        uint32_t RLWheelSpd_ID;
        uint8_t  RLWheelSpd_Start;
        uint8_t  RLWheelSpd_Length;
        float    RLWheelSpd_Offset;
        float    RLWheelSpd_Factor;

        uint32_t RRWheelSpd_ID;
        uint8_t  RRWheelSpd_Start;
        uint8_t  RRWheelSpd_Length;
        float    RRWheelSpd_Offset;
        float    RRWheelSpd_Factor;

        uint32_t Gear_ID;
        uint8_t  Gear_Start;
        uint8_t  Gear_Length;
        float    Gear_Offset;
        float    Gear_Factor;
        uint32_t Gear_P;
        uint32_t Gear_D;
        uint32_t Gear_R;
        uint32_t Gear_N;
    }GJDeVice_CAN_Msg_t;
    typedef union GJDeVice_CAN_Msgbuf
    {
        GJDeVice_CAN_Msg_t GJDeVice_CAN_Msg;
        uint8_t bytes[103] = {0};
    }GJDeVice_CAN_Msgbuf_t;


private:
    Ui::Dialog_CustomCan *ui;

    GJDeVice_CAN_Msgbuf_t GJDeVice_CAN_Msgbuf;  // 自定义can的所有信息联合体

    int Message_num = 0;    // DBC的can ID总数
    QString Mseeage_IDName[50]; // ID名称
    int Signal_num[50] = {0};   // 每个ID里的信号总数
    QString Signal[50][20];     // 每个ID里的每个信号消息字符串
    QTimer *timeOut_Timer = new QTimer(this);   //超时定时器

    QString name[6] = {"车速","左前轮速","右前轮速","左后轮速","右后轮速","档位"};
public:

private:
    void Dialog_CustomCanInit();                        // 初始化函数
    void EN_ControlEnable(int num);                     // 第num消息被使能或者取消使能， 规定0：车速；1：左前轮；2：右前轮；3：左后轮；4：右后轮；5：档位
    void GearEN_ControlEnable(int num);                 // 档位里4个不同档位的使能
    void Input_ControlEnable();                         // 根据输入方式，初始化各种按钮应有的状态

    void Read_DBCFile();                                // 读DBC的TXT文件
    void Add_DBCFile_Message();                         // 将字头信息添加到元器件中
    void Add_DBCFile_Signal(int num1, int num);         // 将信号名称添加到元器件中
    void Add_DBCFile_SignalData(int num, int signalnum);// 将信号消息添加到对应元器件中

    bool Check_CanMsgValid();                           // 发送消息前，判断当前用户编写是否存在的错误，或者无法让底层正常解析
    void Get_CanMsg();                                  // 获取用户填写的值发送底层
    void Send_CanMsg();                                 // 发送用户自定义can信息
public slots:



private slots:
    // 所有按钮的信号槽
    void on_PushButton_ReadDBC_clicked();
    void on_PushButton_SendCAN_clicked();

    void on_CheckBox_ManualInput_clicked();
    void on_CheckBox_DBCInput_clicked();

    void on_CheckBox_VehicleSpd_En_clicked();
    void on_CheckBox_FLWheelSpd_En_clicked();
    void on_CheckBox_RLWheelSpd_En_clicked();
    void on_CheckBox_FRWheelSpd_En_clicked();
    void on_CheckBox_RRWheelSpd_En_clicked();
    void on_CheckBox_Gear_En_clicked();

    void on_CheckBox_Gear_PEN_clicked();
    void on_CheckBox_Gear_DEN_clicked();
    void on_CheckBox_Gear_REN_clicked();
    void on_CheckBox_Gear_NEN_clicked();

    void on_ComboBox_VehicleSpd_ID_currentIndexChanged(int index);
    void on_ComboBox_FLWheelSpd_ID_currentIndexChanged(int index);
    void on_ComboBox_FRWheelSpd_ID_currentIndexChanged(int index);
    void on_ComboBox_RLWheelSpd_ID_currentIndexChanged(int index);
    void on_ComboBox_RRWheelSpd_ID_currentIndexChanged(int index);
    void on_ComboBox_Gear_ID_currentIndexChanged(int index);

    void on_ComboBox_VehicleSpd_SignalName_currentIndexChanged(int index);
    void on_ComboBox_FLWheelSpd_SignalName_currentIndexChanged(int index);
    void on_ComboBox_FRWheelSpd_SignalName_currentIndexChanged(int index);
    void on_ComboBox_RLWheelSpd_SignalName_currentIndexChanged(int index);
    void on_ComboBox_RRWheelSpd_SignalName_currentIndexChanged(int index);
    void on_ComboBox_Gear_SignalName_currentIndexChanged(int index);

    void receiveACK_CustomCan_head();

    void TimeOut();

signals:
    // 串口调用发送信号
    void Serial_Write(QByteArray);
};

#endif  // DIALOG_CUSTOMCAN_H

#ifndef SERAILPORT_H
#define SERAILPORT_H

#include <QSerialPort>
#include <QObject>
#include <QDebug>
#include <QMessageBox>
#include <QCoreApplication>

#include "constant.h"
#include "base_function.h"
class SerialPort : public QObject
{
    Q_OBJECT

public:
    explicit SerialPort(QObject *parent = 0);

public:
#pragma pack(push, 1)
    typedef struct GJDeVice_Polling_Msg
    {
        int16_t Level[3];
        int16_t AngGNSS2Vehicle[3];
        int16_t AngIMU2Vehicle[3];
        int16_t LeverINS2Rear[3];
        int16_t VehicleSpdFactorErr;
        int16_t RearWheelBase;
        int16_t FrontWheelBase;
        int16_t WheelBase;
        int16_t IC_Level[3];
        int16_t IC_AngGNSS2Vehicle[3];
        int16_t IC_AngIMU2Vehicle[3];
        int16_t reserved_1[3];
        int16_t LeverOutput[3];
        int16_t accuracy[4];
        int16_t reserved_2[9];
        uint8_t Algri_Ver_S1;
        uint8_t Algri_Ver_S2;
        uint8_t Algri_Ver_S3;
        uint8_t Algri_Ver_A4;
        uint16_t Algri_Ver_A5;
        uint8_t Algri_Ver_A6;
        uint8_t Algri_Ver_A7;
        uint8_t Algri_Ver_A8;
        uint8_t Algri_Ver_A9;
        uint8_t BSW_Ver_S1;
        uint8_t BSW_Ver_S2;
        uint8_t BSW_Ver_S3;
        uint8_t BSW_Ver_B4;
        uint16_t BSW_Ver_B5;
        uint8_t BSW_Ver_B6;
        uint8_t BSW_Ver_B7;
        uint8_t BSW_Ver_B8;
        uint8_t BSW_Ver_B9;
        uint8_t BootVer_BOOT_S1;
        uint8_t BootVer_BOOT_S2;
        uint8_t BootVer_BOOT_S3;
        uint8_t BootVer_BOOT_C4;
        uint16_t BootVer_BOOT_C5;
        uint8_t BootVer_BOOT_C6;
        uint8_t BootVer_BOOT_C7;
        uint8_t BootVer_BOOT_C8;
        uint8_t BootVer_BOOT_C9;
        uint8_t SN_D6;
        uint8_t SN_D5;
        uint8_t SN_D4;
        uint8_t SN_D3;
        uint32_t SN_D2;
        uint8_t SN_S1;
        uint8_t reserved_3;
        int16_t INS_Db_g[3];
        int16_t INS_Eb_radps[3];
        int16_t reserved_4[6];
        float X_ACC_std_threshold_stop;
        float Y_ACC_std_threshold_stop;
        float Z_ACC_std_threshold_stop;
        float X_GYRO_std_threshold_stop;
        float Y_GYRO_std_threshold_stop;
        float Z_GYRO_std_threshold_stop;
        float X_ACC_std_threshold_move;
        float Y_ACC_std_threshold_move;
        float Z_ACC_std_threshold_move;
        float X_GYRO_std_threshold_move;
        float Y_GYRO_std_threshold_move;
        float Z_GYRO_std_threshold_move;
        float X_ACC_dt_threshold_move;
        float Y_ACC_dt_threshold_move;
        float Z_ACC_dt_threshold_move;
        float X_GYRO_dt_threshold_move;
        float Y_GYRO_dt_threshold_move;
        float Z_GYRO_dt_threshold_move;
        uint8_t temp_count;
        int16_t IMU_TEMP;
        int16_t IMU_Tempera_Calib1;
        int16_t IMU_Tempera_Calib2;
        uint8_t reserved_5;
        int16_t ACCBias_g_Calib1[3];
        int16_t GyroBias_degps_Calib1[3];
        int16_t ACCBias_g_Calib2[3];
        int16_t GyroBias_degps_Calib2[3];
        float deltaKa_Calib1[9];
        float reserved_6;
        float deltaKg_Calib1[9];
        float reserved_7;
        float G_Calib1[9];
        float reserved_8;
        float deltaKa_Calib2[9];
        float reserved_9;
        float deltaKg_Calib2[9];
        float reserved_10;
        float G_Calib2[9];
        float reserved_11;
    }GJDeVice_Polling_Msg_t;

    typedef union GJDeVice_Polling_MsgBuf
    {
        GJDeVice_Polling_Msg_t GJDeVice_Polling_Msg;
        uint8_t bytes[receive_GJProtocol_PollingNumber * 8] = {0};
    }GJDeVice_Polling_MsgBuf_t;
#pragma pack(pop)
    static GJDeVice_Polling_MsgBuf_t gjDevicePollingData;

private:
    QSerialPort *Serial;
    QByteArray serialbuffer;
public:
    void OpenSerial_Init();     // 打开串口后初始化函数

    bool Open_Serial(QString PortName,
                     int BaudRate,
                     QSerialPort::DataBits DataBits,
                     QSerialPort::Parity Parity,
                     QSerialPort::StopBits StopBits);    // 打开串口
    void Close_Serial();        // 关闭串口

    bool FindHead_withoutData();    // 找不带数据的共迹消息
    bool FindHead_withData();       // 找带字头的共迹消息

    void DealHead_GJProtocol_Head(QByteArray data);     // 处理共迹协议

    void DealHead_Calibration_DynamicSuccess(QByteArray data);  // 处理动态标定ok的数据

public slots:
    void Serial_readyRead();  // 读取串口数据
    void Serial_Write(QByteArray data); // 串口发送

signals:
    // 各种信号，整体控制上位机操作
    void delDoneData(QByteArray data);//
    void delDone_GJProtocol_Data();//
    void delDone_GJProtocol_PollingData();
    void delDone_GJProtocol_TrackMap_Point();

    void receive_Firmware_PleaseUpdata_head();
    void receive_Firmware_PleaseWaitUpdata_head();//
    void receive_Firmware_ReceiveError_head();//
    void receive_Firmware_FileError_head();//
    void receive_Firmware_UpdataError_head();//
    void receive_Firmware_UpdataSuccess_head();//
    void receive_Calibration_StaticCalibrating_head();//
    void receive_Calibration_StaticSuccess_head();//
    void receive_Calibration_DynamicCalibrating_head();//
    void receive_Calibration_IncTurningRatio_head();//
    void receive_Calibration_IncForwardRatio_head();//
    void receive_Calibration_PleaseChangeCaliSites_head();//
    void receive_Calibration_DynamicSuccess_head();//
    void receive_TempCali_RequestData_head();
    void receive_TempCali_RepeatData_head();
    void receive_TempCali_CompleteData_head();
    void receive_TempCali_DeviceHasSavedData_head(QByteArray data);

    void receiveACK_Calibration_UserInstallationAngle_head();//
    void receiveACK_Calibration_SystemInstallationAangle_head();//
    void receiveACK_Calibration_Static_head();//
    void receiveACK_Calibration_Dynamic_head();//
    void receiveACK_Calibration_Cancel_head();//
    void receiveACK_Calibration_SaveResult_head();//
    void receiveACK_Calibration_DontSaveResult_head();//
    void receiveACK_Calibration_WheelBase_head();//
    void receiveACK_Calibration_LeverINS2Rear_head();//

    void receiveACK_ChangeProtocolOK_head();

    void receiveACK_CustomCan_head();
    void receiveACK_RTCMSelectType_head();
    void receiveACK_StaticIPPort_head();

    void sig_recETHCfg_data_head();
    void sig_recETHCfg_ReturnData(QByteArray data);

    void sig_recCusmtomProtocolResponseHead();
};

#endif // SERAILPORT_H

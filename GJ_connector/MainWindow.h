#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <QMessageBox>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <math.h>
#include <QSettings>
#include <QDebug>

#include "constant.h"
#include "base_function.h"
#include "SerialPort.h"
#include "SerialDataSave.h"

#include "dialog_firmware.h"
#include "dialog_calibration.h"
#include "dialog_trackmap.h"
#include "dialog_versionmsg.h"
#include "dialog_tempcali.h"
#include "dialog_pollingdata.h"
#include "dialog_protocolchange.h"
#include "dialog_encryption.h"
#include "dialog_customcan.h"
#include "dialog_advanced.h"
#include "dlg_ipconfig.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class Dlg_ipConfig;
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    Ui::MainWindow *ui;

    SerialPort *serialport;     // 串口类对象
    QThread *thread_SerialPort; // 串口线程

    SaveSerialData *saveserialdata; // 串口数据保存对象
    QThread *thread_SerialDataSave; // 串口数据保存线程

    bool checkVersionNum = false;

private:
    QString SaveSerialData_FileName_Path = "";

    // 判断子界面是否已经打开，避免重复打开
    bool isOpen_Dialog_FirmWare = false;
    bool isOpen_Dialog_Calibration = false;
    bool isOpen_Dialog_TrackMap = false;
    bool isOpen_Dialog_VersionMsg = false;
    bool isOpen_Dialog_TempCali = false;
    bool isOpen_Dialog_PollingData = false;
    bool isOpen_Dialog_ProtocolChange = false;
    bool isOpen_Dialog_Encryption = false;
    bool isOpen_Dialog_CustomCan = false;
    bool isOpen_Dialog_advanced = false;

    // 判断管理员权限是否已经打开，避免重复打开
    bool AdministratorMode_flag = false;

    Dlg_ipConfig*pDlg_ipConfig_ = nullptr;

public :
    void MainWindow_Init(); // 初始化函数
    void AfterOpenSerial_Init();    // 打开串口后的初始化函数

    void Search_Serial();   // 检测串口
    void Open_Serial();     // 打开串口
    void Close_Serial();    // 关闭串口
    void Serial_ButtonState(bool state);    //控制串口元器件的使能情况

    void Selete_SaveSerialData_File();  // 选择保存路径
    void Start_SaveSerialData();        // 开始保存数据
    void Stop_SaveSerialData();         // 停止保存数据

    template<typename T>
    void extractAndCalculateMsgData(T *msgBuf);
    void setVSMS1000Visible();

public slots:
    void delDone_GJProtocol_Data();     // 共迹协议解析ok时，展示
    void AdministratorMode();           // 管理员权限打开

private slots:
    // 响应类型按钮
    void on_PushButton_CheckSerial_clicked();
    void on_PushButton_OpenSerial_clicked();

    void on_PushButton_SaveSerialData_SeletePath_clicked();
    void on_PushButton_SaveSerialData_StartSave_clicked();

    // 创建新界面类型按钮
    void on_action_FirmWare_triggered();
    void on_PushButton_CaliDialog_clicked();
    void on_action_TrackMap_triggered();
    void on_action_VersionMsg_triggered();
    void on_action_TempCali_triggered();
    void on_action_PollingData_triggered();
    void on_action_ProtocolChange_triggered();
    void on_action_Encryption_triggered();
    void on_action_CustomCan_triggered();

    void on_action_advanced_triggered();

    void on_actionactIStaticIPCfg_triggered();
};
#endif // MAINWINDOW_H

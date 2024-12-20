#include "dialog_calibration.h"
#include "./moc_ui/ui_dialog_calibration.h"
#include "./global/globalsetting.h"
#include <QDebug>

namespace  {
    GlobalSetting *pGlobalSetting = GlobalSetting::getInstance();
    QVariant msgBufVariant = pGlobalSetting->getMsgBuf();
}


Dialog_Calibration::Dialog_Calibration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Calibration)
  , selectDynamicTimer_{new QTimer(this)}
{
    ui->setupUi(this);
    updateThread = new WorkerThread(this);
    connect(updateThread,&WorkerThread::updateDynamicCaliData,this,&Dialog_Calibration::updateDynamicCaliData);
    updateThread->start();
    updateThread->pauseThread();
    Dialog_Calibration_Init();
}

Dialog_Calibration::~Dialog_Calibration()
{
    delete ui;
    Calibration_sendtimer->stop();
    Calibration_sendtimer->deleteLater();
}

// Init
void Dialog_Calibration::Dialog_Calibration_Init()      // 初始化函数
{
    this->setWindowTitle("标定模块");

    QWidget::setAttribute(Qt::WA_QuitOnClose,false);     // 所有子窗口要写false
    QWidget::setAttribute(Qt::WA_DeleteOnClose);     // 所有子窗口要写false
    setWindowFlags((windowFlags()&~Qt::WindowContextHelpButtonHint) | Qt::WindowMinimizeButtonHint);

    connect(Calibration_sendtimer, &QTimer::timeout, this, &Dialog_Calibration::Calibration_Timeout);//关联计时器
}

// Base Function
void Dialog_Calibration::Send_Level1Data()      // 发送输出点相对惯导的位置
{
    float LeverOutput_temp[3] = {0};
    // 获取输入的数
    LeverOutput_temp[0] = ui->LineEdit_X1_Input->text().toFloat();
    LeverOutput_temp[1] = ui->LineEdit_Y1_Input->text().toFloat();
    LeverOutput_temp[2] = ui->LineEdit_Z1_Input->text().toFloat();

    // 根据范围修正数据，并乘上比例系数
    for (int i = 0;i<3;i++) {
        if(LeverOutput_temp[i] >= 20)
        {
            LeverOutput_temp[i] = 19.999;
        }
        else if(LeverOutput_temp[i] < -20)
        {
            LeverOutput_temp[i] = -20;
        }
        LeverOutput_temp[i] /= POLL_RATIO_46;
    }

    // 四舍五入
    for (int i = 0;i<3;i++) {
        calibration_level1_data.Calibration_Level1.LeverOutput[i] = (int16_t)qRound(LeverOutput_temp[i]);
    }

    // CRC
    calibration_level1_data.Calibration_Level1.CRC = base_function::Calculate_Crc8(send_Calibration_UserInstallationAngle, calibration_level1_data.bytes,15);
    // 串口发送规范化消息
    emit Serial_Write(base_function::Serial_DataFormat(send_Calibration_UserInstallationAngle, calibration_level1_data.bytes, 16));
    // 记录最后一次执行的操作，方便增加限制用户操作
    send_Calibration_head = send_Calibration_UserInstallationAngle;
    // 计时，如果没有成功握手就报错
    Calibration_SetTimer(true);
}

void Dialog_Calibration::Send_Level2Data()      // 发送GNSS双天线相对车身的角度、GNSS主天线相对惯导的位置、惯导相对车身的角度
{
    float level_temp[3] = {0}, AngIMU2Vehicle_temp[3] = {0}, AngGNSS2Vehicle_temp[3] = {0};
    // 获取输入的数
    level_temp[0] = ui->LineEdit_X2_Input->text().toFloat();
    level_temp[1] = ui->LineEdit_Y2_Input->text().toFloat();
    level_temp[2] = ui->LineEdit_Z2_Input->text().toFloat();

    // 根据范围修正数据，并乘上比例系数
    for (int i = 0;i<3;i++) {
        if(level_temp[i] >= 20)
        {
            level_temp[i] = 19.999;
        }
        else if(level_temp[i] < -20)
        {
            level_temp[i] = -20;
        }
        level_temp[i] /= POLL_RATIO_04;
    }

    // 获取输入的数
    AngGNSS2Vehicle_temp[0] = ui->LineEdit_Pitch1_Input->text().toFloat();
    AngGNSS2Vehicle_temp[1] = ui->LineEdit_Roll1_Input->text().toFloat();
    AngGNSS2Vehicle_temp[2] = ui->LineEdit_Yaw1_Input->text().toFloat();

    AngIMU2Vehicle_temp[0] = ui->LineEdit_Pitch2_Input->text().toFloat();
    AngIMU2Vehicle_temp[1] = ui->LineEdit_Roll2_Input->text().toFloat();
    AngIMU2Vehicle_temp[2] = ui->LineEdit_Yaw2_Input->text().toFloat();

    // 根据范围修正数据，并乘上比例系数
    for (int i = 0;i<2;i++) {
        if(AngIMU2Vehicle_temp[i] > 30)
        {
            AngIMU2Vehicle_temp[i] = 30;
        }
        else if(AngIMU2Vehicle_temp[i] < -30)
        {
            AngIMU2Vehicle_temp[i] = -30;
        }

        if(AngGNSS2Vehicle_temp[i] > 30)
        {
            AngGNSS2Vehicle_temp[i] = 30;
        }
        else if(AngGNSS2Vehicle_temp[i] < -30)
        {
            AngGNSS2Vehicle_temp[i] = -30;
        }
    }

    while (AngIMU2Vehicle_temp[2]>=180 || AngIMU2Vehicle_temp[2]<-180) {
        if(AngIMU2Vehicle_temp[2]>=180)
        {
            AngIMU2Vehicle_temp[2] -= 360;
        }
        else
        {
            AngIMU2Vehicle_temp[2] += 360;
        }
    }

    while (AngGNSS2Vehicle_temp[2]>=180 || AngGNSS2Vehicle_temp[2]<-180) {
        if(AngGNSS2Vehicle_temp[2]>=180)
        {
            AngGNSS2Vehicle_temp[2] -= 360;
        }
        else
        {
            AngGNSS2Vehicle_temp[2] += 360;
        }
    }

    for (int i = 0;i<3;i++)
    {
        AngIMU2Vehicle_temp[i] /= POLL_RATIO_07;
        AngGNSS2Vehicle_temp[i] /= POLL_RATIO_12;
    }

    for (int i = 0;i<3;i++) {
        calibration_level2_data.Calibration_Level2.level[i] = (int16_t)qRound(level_temp[i]);
        calibration_level2_data.Calibration_Level2.AngIMU2Vehicle[i] = (int16_t)qRound(AngIMU2Vehicle_temp[i]);
        calibration_level2_data.Calibration_Level2.AngGNSS2Vehicle[i] = (int16_t)qRound(AngGNSS2Vehicle_temp[i]);
    }

    // CRC
    calibration_level2_data.Calibration_Level2.CRC = base_function::Calculate_Crc8(send_Calibration_SystemInstallationAangle, calibration_level2_data.bytes,39);
    // 串口发送规范化消息
    emit Serial_Write(base_function::Serial_DataFormat(send_Calibration_SystemInstallationAangle, calibration_level2_data.bytes, 40));
    // 记录最后一次执行的操作，方便增加限制用户操作
    send_Calibration_head = send_Calibration_SystemInstallationAangle;
    // 计时，如果没有成功握手就报错
    Calibration_SetTimer(true);
}

void Dialog_Calibration::Send_Level3Data()
{
    float LeverINS2Rear_temp[3] = {0};
    // 获取输入的数
    LeverINS2Rear_temp[0] = ui->LineEdit_X3_Input->text().toFloat();
    LeverINS2Rear_temp[1] = ui->LineEdit_Y3_Input->text().toFloat();
    LeverINS2Rear_temp[2] = ui->LineEdit_Z3_Input->text().toFloat();

    // 根据范围修正数据，并乘上比例系数
    for (int i = 0;i<3;i++) {
        if(LeverINS2Rear_temp[i] >= 20)
        {
            LeverINS2Rear_temp[i] = 19.999;
        }
        else if(LeverINS2Rear_temp[i] < -20)
        {
            LeverINS2Rear_temp[i] = -20;
        }
    }

    for (int i = 0;i<3;i++) {
        calibration_level3_data.Calibration_Level3.LeverINS2Rear[i] = LeverINS2Rear_temp[i];
    }
    // CRC
    calibration_level3_data.Calibration_Level3.CRC = base_function::Calculate_Crc8(send_Calibration_LeverINS2Rear, calibration_level3_data.bytes,12);
    // 串口发送规范化消息
    emit Serial_Write(base_function::Serial_DataFormat(send_Calibration_LeverINS2Rear, calibration_level3_data.bytes, 13));
    // 记录最后一次执行的操作，方便增加限制用户操作
    send_Calibration_head = send_Calibration_LeverINS2Rear;
    // 计时，如果没有成功握手就报错
    Calibration_SetTimer(true);
}

void Dialog_Calibration::Send_Level4Data()
{
    float FrontWheelBase_temp,RearWheelBase_temp,WheelBase_temp;
    // 获取输入的数
    FrontWheelBase_temp = ui->LineEdit_FrontWheelBase_Input->text().toFloat();
    RearWheelBase_temp  = ui->LineEdit_RearWheelBase_Input ->text().toFloat();
    WheelBase_temp      = ui->LineEdit_WheelBase_Input     ->text().toFloat();

    // 根据范围修正数据，并乘上比例系数

    if(FrontWheelBase_temp >= 20)
    {
        FrontWheelBase_temp = 19.999;
    }
    else if(FrontWheelBase_temp < -20)
    {
        FrontWheelBase_temp = -20;
    }

    if(RearWheelBase_temp >= 20)
    {
        RearWheelBase_temp = 19.999;
    }
    else if(RearWheelBase_temp < -20)
    {
        RearWheelBase_temp = -20;
    }

    if(WheelBase_temp >= 20)
    {
        WheelBase_temp = 19.999;
    }
    else if(WheelBase_temp < -20)
    {
        WheelBase_temp = -20;
    }

    calibration_level4_data.Calibration_Level4.FrontWheelBase = FrontWheelBase_temp;
    calibration_level4_data.Calibration_Level4.RearWheelBase  = RearWheelBase_temp;
    calibration_level4_data.Calibration_Level4.WheelBase      = WheelBase_temp;

    // CRC
    calibration_level4_data.Calibration_Level4.CRC = base_function::Calculate_Crc8(send_Calibration_WheelBase, calibration_level4_data.bytes,12);
    // 串口发送规范化消息
    emit Serial_Write(base_function::Serial_DataFormat(send_Calibration_WheelBase, calibration_level4_data.bytes, 13));
    // 记录最后一次执行的操作，方便增加限制用户操作
    send_Calibration_head = send_Calibration_WheelBase;
    // 计时，如果没有成功握手就报错
    Calibration_SetTimer(true);
}

void Dialog_Calibration::Get_CurLevel_data()    // 将当前存在底层的输出点相对惯导的位置、GNSS双天线相对车身的角度、GNSS主天线相对惯导的位置、惯导相对车身的角度输出
{
    float X1            = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.LeverOutput[0]     * POLL_RATIO_46;
    float Y1            = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.LeverOutput[1]     * POLL_RATIO_47;
    float Z1            = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.LeverOutput[2]     * POLL_RATIO_48;

    float X2            = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Level[0]           * POLL_RATIO_04;
    float Y2            = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Level[1]           * POLL_RATIO_05;
    float Z2            = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Level[2]           * POLL_RATIO_06;

    float Pitch1        = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.AngGNSS2Vehicle[0] * POLL_RATIO_07;
    float Roll1         = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.AngGNSS2Vehicle[1] * POLL_RATIO_10;
    float Yaw1          = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.AngGNSS2Vehicle[2] * POLL_RATIO_11;

    float Pitch2        = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.AngIMU2Vehicle[0]  * POLL_RATIO_12;
    float Roll2         = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.AngIMU2Vehicle[1]  * POLL_RATIO_13;
    float Yaw2          = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.AngIMU2Vehicle[2]  * POLL_RATIO_16;

    float X3            = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.LeverINS2Rear[0]   * POLL_RATIO_17;
    float Y3            = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.LeverINS2Rear[1]   * POLL_RATIO_18;
    float Z3            = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.LeverINS2Rear[2]   * POLL_RATIO_19;

    float FrontWheelBase= SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.FrontWheelBase     * POLL_RATIO_23;
    float RearWheelBase = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.RearWheelBase      * POLL_RATIO_24;
    float WheelBase     = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.WheelBase          * POLL_RATIO_25;

    ui->LineEdit_X1_Result            ->setText(QString::number(X1              , 'f', 2));
    ui->LineEdit_Y1_Result            ->setText(QString::number(Y1              , 'f', 2));
    ui->LineEdit_Z1_Result            ->setText(QString::number(Z1              , 'f', 2));

    ui->LineEdit_X2_Result            ->setText(QString::number(X2              , 'f', 2));
    ui->LineEdit_Y2_Result            ->setText(QString::number(Y2              , 'f', 2));
    ui->LineEdit_Z2_Result            ->setText(QString::number(Z2              , 'f', 2));

    ui->LineEdit_Pitch1_Result        ->setText(QString::number(Pitch1          , 'f', 2));
    ui->LineEdit_Roll1_Result         ->setText(QString::number(Roll1           , 'f', 2));
    ui->LineEdit_Yaw1_Result          ->setText(QString::number(Yaw1            , 'f', 2));

    ui->LineEdit_Pitch2_Result        ->setText(QString::number(Pitch2          , 'f', 2));
    ui->LineEdit_Roll2_Result         ->setText(QString::number(Roll2           , 'f', 2));
    ui->LineEdit_Yaw2_Result          ->setText(QString::number(Yaw2            , 'f', 2));
    
    ui->LineEdit_X3_Result            ->setText(QString::number(X3              , 'f', 2));
    ui->LineEdit_Y3_Result            ->setText(QString::number(Y3              , 'f', 2));
    ui->LineEdit_Z3_Result            ->setText(QString::number(Z3              , 'f', 2));

    ui->LineEdit_FrontWheelBase_Result->setText(QString::number(FrontWheelBase  , 'f', 2));
    ui->LineEdit_RearWheelBase_Result ->setText(QString::number(RearWheelBase   , 'f', 2));
    ui->LineEdit_WheelBase_Result     ->setText(QString::number(WheelBase       , 'f', 2));
}

void Dialog_Calibration::Calibration_Static()   // 静态标定
{



    if (msgBufVariant.canConvert<GJDeVice_MsgBuf_920Vertion*>())
    {
         GJDeVice_MsgBuf_920Vertion *msgBuf920 = msgBufVariant.value<GJDeVice_MsgBuf_920Vertion*>();

        if(msgBuf920->GJDeVice_Msg.GNSS_PosStatus != 4 && msgBuf920->GJDeVice_Msg.GNSS_PosStatus != 8)
        {
            QMessageBox::about(this,"错误", " 定位状态不是4或者8,无法静态标定! ");
            return;
        }

    }
    else if (msgBufVariant.canConvert<GJDeVice_MsgBuf_1000Vertion*>())
    {
       GJDeVice_MsgBuf_1000Vertion *msgBuf1000 = msgBufVariant.value<GJDeVice_MsgBuf_1000Vertion*>();

       if(msgBuf1000->GJDeVice_Msg.GNSS_PosStatus != 4 && msgBuf1000->GJDeVice_Msg.GNSS_PosStatus != 8)
       {
           QMessageBox::about(this,"错误", " 定位状态不是4或者8,无法静态标定! ");
           return;
       }
    }
    else
    {
        qDebug() << "Unknown type in QVariant";
    }

    // 串口发送规范化消息
    emit Serial_Write(base_function::Serial_DataFormat(send_Calibration_Static));
    // 记录最后一次执行的操作，方便增加限制用户操作
    send_Calibration_head = send_Calibration_Static;
    // 计时，如果没有成功握手就报错
    Calibration_SetTimer(true);
}
void Dialog_Calibration::Calibration_Dynamic()   // 动态标定
{
//    if(SerialPort::gjDeviceData.GJDeVice_Msg.GNSS_PosStatus != 4 && SerialPort::gjDeviceData.GJDeVice_Msg.GNSS_PosStatus != 8)
//    {
//        QMessageBox::about(this,"错误", " 定位状态不是4或者8,无法动态标定! ");
//        return;
//    }
    // 串口发送规范化消息
    emit Serial_Write(base_function::Serial_DataFormat(send_Calibration_Dynamic));
    // 记录最后一次执行的操作，方便增加限制用户操作
    send_Calibration_head = send_Calibration_Dynamic;
    // 计时，如果没有成功握手就报错
    Calibration_SetTimer(true);

    //ui->PushButton_Calibration_SaveResult   ->setEnabled(true);
}

void Dialog_Calibration::Calibration_Cancle()   // 取消动态静态标定
{
    // 串口发送规范化消息
    emit Serial_Write(base_function::Serial_DataFormat(send_Calibration_Cancel));
    // 记录最后一次执行的操作，方便增加限制用户操作
    send_Calibration_head = send_Calibration_Cancel;
    // 计时，如果没有成功握手就报错
    Calibration_SetTimer(true);
}

void Dialog_Calibration::Calibration_SaveResult()   // 保存动态标定结果
{
    // 串口发送规范化消息
    emit Serial_Write(base_function::Serial_DataFormat(send_Calibration_SaveResult));
    // 记录最后一次执行的操作，方便增加限制用户操作
    send_Calibration_head = send_Calibration_SaveResult;
    // 计时，如果没有成功握手就报错
    Calibration_SetTimer(true);
}

void Dialog_Calibration::Calibration_ButtonState(bool state)    // 设计各种按钮状态
{
    ui->PushButton_Lever1_Send              ->setEnabled(state);
    ui->PushButton_Lever2_Send              ->setEnabled(state);
    ui->PushButton_Lever3_Send              ->setEnabled(state);
    ui->PushButton_Lever4_Send              ->setEnabled(state);
    ui->PushButton_Calibration_Static       ->setEnabled(state);
    ui->PushButton_Calibration_Dynamic      ->setEnabled(state);
    ui->PushButton_Calibration_SaveResult   ->setEnabled(!state);
}

void Dialog_Calibration::Calibration_SetTimer(bool state)   // 计时器开关函数，来判断时候握手超时
{
    if(state)
    {
        // 开启计时器
        Calibration_sendtimer->start(3 * 1000);
        // 限制用户操作
        Calibration_ButtonState(!state);
    }
    else
    {
        // 关闭计时器
        Calibration_sendtimer->stop();
        // 释放用户操作
        Calibration_ButtonState(!state);
    }
}

void Dialog_Calibration::Calibration_Timeout()      // 握手超时函数
{
    Calibration_SetTimer(false);        // 关闭计时器
    ui->Label_Calibration_Message->setText("设备接收信号超时！");

    // 如果上一步执行的（不）保存功能，那么当响应超时时，不取消这两个按钮的使能
    if(send_Calibration_head == send_Calibration_SaveResult || send_Calibration_head == send_Calibration_DontSaveResult)
    {
        ui->PushButton_Calibration_SaveResult   ->setEnabled(true);
    }
    QMessageBox::about(this,"错误", " 设备接收信号超时! ");
}

// SLOTS
// 上位机收到底层发送的确认消息码
void Dialog_Calibration::receiveACK_Calibration_UserInstallationAngle_head()
{
    if(send_Calibration_head != send_Calibration_UserInstallationAngle)
    {
        return;
    }

    Calibration_SetTimer(false);
    QMessageBox::about(this,"提示", " 发送成功 ");

}

void Dialog_Calibration::receiveACK_Calibration_SystemInstallationAangle_head()
{
    if(send_Calibration_head != send_Calibration_SystemInstallationAangle)
    {
        return;
    }

    Calibration_SetTimer(false);
    QMessageBox::about(this,"提示", " 发送成功 ");
}

void Dialog_Calibration::receiveACK_Calibration_Static_head()
{
    if(send_Calibration_head != send_Calibration_Static)
    {
        return;
    }
    Calibration_sendtimer->stop();
    ui->PushButton_Calibration_Static->setEnabled(true);
    ui->PushButton_Calibration_Static->setText("取消标定");
    ui->PushButton_Calibration_SaveResult->setEnabled(false);

    ui->Label_Calibration_Message->setText("设备响应完成，请等待静态标定开始");
}

void Dialog_Calibration::receiveACK_Calibration_Dynamic_head()
{
    if(send_Calibration_head != send_Calibration_Dynamic)
    {
        return;
    }
    Calibration_sendtimer->stop();
    updateThread->continueThread();
    ui->PushButton_Calibration_Dynamic->setEnabled(true);
    ui->PushButton_Calibration_Dynamic->setText("取消标定");


    ui->Label_Calibration_Message->setText("设备响应完成，请等待动态标定开始");
}

void Dialog_Calibration::receiveACK_Calibration_Cancel_head()
{
    if(send_Calibration_head != send_Calibration_Cancel)
    {
        return;
    }
    Calibration_SetTimer(false);
    updateThread->pauseThread();
    ui->PushButton_Calibration_Static->setText("静态标定");
    ui->PushButton_Calibration_Dynamic->setText("动态标定");

    ui->Label_Calibration_Message->setText("设备取消标定成功！");
}

void Dialog_Calibration::receiveACK_Calibration_SaveResult_head()
{
    if(send_Calibration_head != send_Calibration_SaveResult)
    {
        return;
    }
    Calibration_SetTimer(false);
    updateThread->pauseThread();
    ui->Label_Calibration_Message->setText("设备标定数据保存成功！");
    ui->PushButton_Calibration_Dynamic->setText("动态标定");
}

void Dialog_Calibration::receiveACK_Calibration_WheelBase_head()
{
    if(send_Calibration_head != send_Calibration_WheelBase)
    {
        return;
    }
    Calibration_SetTimer(false);
    QMessageBox::about(this,"提示", " 前轮距、后轮距、轴距设置成功 ");
}

void Dialog_Calibration::receiveACK_Calibration_LeverINS2Rear_head()
{
    if(send_Calibration_head != send_Calibration_LeverINS2Rear)
    {
        return;
    }
    Calibration_SetTimer(false);
    QMessageBox::about(this,"提示", " 后轮中心相对INS位置设置成功 ");
}

// 上位机收到底层发送的消息码
void Dialog_Calibration::receive_Calibration_StaticCalibrating_head()
{
    if(flag_ui_init)
    {
        flag_ui_init = false;
        Calibration_ButtonState(false);
        ui->PushButton_Calibration_Static->setEnabled(true);
        ui->PushButton_Calibration_Static->setText("取消标定");
    }
    ui->Label_Calibration_Message->setText("设备正在静态标定中，车辆请不要晃动！");
}

void Dialog_Calibration::receive_Calibration_StaticSuccess_head()
{
    Calibration_SetTimer(false);
    ui->PushButton_Calibration_Static->setText("静态标定");
    ui->Label_Calibration_Message->setText("设备静态标定成功,可以通过读取配置按钮查看静态标定结果！");
}

void Dialog_Calibration::receive_Calibration_DynamicCalibrating_head()
{
    if(flag_ui_init)
    {
        flag_ui_init = false;
        Calibration_ButtonState(false);
        ui->PushButton_Calibration_Dynamic->setEnabled(true);
        ui->PushButton_Calibration_Dynamic->setText("取消标定");
    }

    ui->Label_Calibration_Message->setText("设备正在动态标定中...");
    updateThread->continueThread();
}

void Dialog_Calibration::receive_Calibration_IncTurningRatio_head()
{
    if(flag_ui_init)
    {
        flag_ui_init = false;
        Calibration_ButtonState(false);
        ui->PushButton_Calibration_Dynamic->setEnabled(true);
        ui->PushButton_Calibration_Dynamic->setText("取消标定");
    }
    ui->Label_Calibration_Message->setText("设备正在动态标定中，请提高标定路线的转弯比例！");
}

void Dialog_Calibration::receive_Calibration_IncForwardRatio_head()
{
    if(flag_ui_init)
    {
        flag_ui_init = false;
        Calibration_ButtonState(false);
        ui->PushButton_Calibration_Dynamic->setEnabled(true);
        ui->PushButton_Calibration_Dynamic->setText("取消标定");
    }
    ui->Label_Calibration_Message->setText("设备正在动态标定中，请提高标定路线的直线比例！");
}

void Dialog_Calibration::receive_Calibration_PleaseChangeCaliSites_head()
{
    if(flag_ui_init)
    {
        flag_ui_init = false;
        Calibration_ButtonState(false);
        ui->PushButton_Calibration_Dynamic->setEnabled(true);
        ui->PushButton_Calibration_Dynamic->setText("取消标定");
    }
    ui->Label_Calibration_Message->setText("标定过程中部分时间GNSS状态较差，请检测设备连接或更换标定场地！");
}

void Dialog_Calibration::receive_Calibration_DynamicSuccess_head()
{

    Calibration_SetTimer(false);
    ui->PushButton_Calibration_Dynamic->setText("动态标定");
    ui->Label_Calibration_Message->setText("动态标定成功,请确认是否保存动态标定数据！");
    std::unique_ptr<GJDeVice_Dynamic_MsgBuf_t>& msgBufRef = pGlobalSetting->getMsg1000DynamicDataRef();
    float X2            = msgBufRef->GJDeVice_Dynamic_Msg.Level[0]           * POLL_RATIO_04;
    float Y2            = msgBufRef->GJDeVice_Dynamic_Msg.Level[1]           * POLL_RATIO_05;
    float Z2            = msgBufRef->GJDeVice_Dynamic_Msg.Level[2]           * POLL_RATIO_06;

    float Pitch1        = msgBufRef->GJDeVice_Dynamic_Msg.AngGNSS2Vehicle[0] * POLL_RATIO_07;
    float Roll1         = msgBufRef->GJDeVice_Dynamic_Msg.AngGNSS2Vehicle[1] * POLL_RATIO_10;
    float Yaw1          = msgBufRef->GJDeVice_Dynamic_Msg.AngGNSS2Vehicle[2] * POLL_RATIO_11;

    float Pitch2        = msgBufRef->GJDeVice_Dynamic_Msg.AngIMU2Vehicle[0]  * POLL_RATIO_12;
    float Roll2         = msgBufRef->GJDeVice_Dynamic_Msg.AngIMU2Vehicle[1]  * POLL_RATIO_13;
    float Yaw2          = msgBufRef->GJDeVice_Dynamic_Msg.AngIMU2Vehicle[2]  * POLL_RATIO_16;

    ui->LineEdit_X2_CaliOutput      ->setText(QString::number(X2 , 'f', 2));
    ui->LineEdit_Y2_CaliOutput      ->setText(QString::number(Y2  , 'f', 2));
    ui->LineEdit_Z2_CaliOutput      ->setText(QString::number(Z2   , 'f', 2));

    ui->LineEdit_Pitch1_CaliOutput  ->setText(QString::number(Pitch1 , 'f', 2));
    ui->LineEdit_Roll1_CaliOutput   ->setText(QString::number(Roll1  , 'f', 2));
    ui->LineEdit_Yaw1_CaliOutput    ->setText(QString::number(Yaw1   , 'f', 2));

    ui->LineEdit_Pitch2_CaliOutput  ->setText(QString::number(Pitch2     , 'f', 2));
    ui->LineEdit_Roll2_CaliOutput   ->setText(QString::number(Roll2     , 'f', 2));
    ui->LineEdit_Yaw2_CaliOutput    ->setText(QString::number(Yaw2     , 'f', 2));

    ui->PushButton_Calibration_SaveResult   ->setEnabled(true);

    //ui->PushButton_Calibration_AbandonResult->setEnabled(true);


}

//更新动态标定数据
void Dialog_Calibration::updateDynamicCaliData()
{
       float X2            = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.IC_Level[0]                 * POLL_RATIO_28;
       float Y2            = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.IC_Level[1]                 * POLL_RATIO_29;
       float Z2            = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.IC_Level[2]                 * POLL_RATIO_30;

       float Pitch1        = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.IC_AngGNSS2Vehicle[0]       * POLL_RATIO_31;
       float Roll1         = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.IC_AngGNSS2Vehicle[1]       * POLL_RATIO_34;
       float Yaw1          = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.IC_AngGNSS2Vehicle[2]       * POLL_RATIO_35;

       float Pitch2        = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.IC_AngIMU2Vehicle[0]        * POLL_RATIO_36;
       float Roll2         = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.IC_AngIMU2Vehicle[1]        * POLL_RATIO_37;
       float Yaw2          = SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.IC_AngIMU2Vehicle[2]        * POLL_RATIO_40;

       ui->LineEdit_X2_CaliOutput      ->setText(QString::number(X2 , 'f', 2));
       ui->LineEdit_Y2_CaliOutput      ->setText(QString::number(Y2  , 'f', 2));
       ui->LineEdit_Z2_CaliOutput      ->setText(QString::number(Z2   , 'f', 2));

       ui->LineEdit_Pitch1_CaliOutput  ->setText(QString::number(Pitch1 , 'f', 2));
       ui->LineEdit_Roll1_CaliOutput   ->setText(QString::number(Roll1  , 'f', 2));
       ui->LineEdit_Yaw1_CaliOutput    ->setText(QString::number(Yaw1   , 'f', 2));

       ui->LineEdit_Pitch2_CaliOutput  ->setText(QString::number(Pitch2     , 'f', 2));
       ui->LineEdit_Roll2_CaliOutput   ->setText(QString::number(Roll2     , 'f', 2));
       ui->LineEdit_Yaw2_CaliOutput    ->setText(QString::number(Yaw2     , 'f', 2));
}

// Button SLOTS
// 所有按钮信号槽
void Dialog_Calibration::on_PushButton_Lever1_Send_clicked()
{
    Send_Level1Data();
}

void Dialog_Calibration::on_PushButton_Lever2_Send_clicked()
{
    Send_Level2Data();
}

void Dialog_Calibration::on_PushButton_Lever3_Send_clicked()
{
    Send_Level3Data();
}

void Dialog_Calibration::on_PushButton_Lever4_Send_clicked()
{
    Send_Level4Data();
}

void Dialog_Calibration::on_PushButton_CurLever_Get_clicked()
{
    Get_CurLevel_data();
}

void Dialog_Calibration::on_PushButton_Calibration_Static_clicked()
{
    if(ui->PushButton_Calibration_Static->text() == "静态标定")
    {
        Calibration_Static();
    }
    else
    {
        Calibration_Cancle();
    }
}

void Dialog_Calibration::on_PushButton_Calibration_Dynamic_clicked()
{
    if(ui->PushButton_Calibration_Dynamic->text() == "动态标定")
    {
        Calibration_Dynamic();
    }
    else
    {
        Calibration_Cancle();
    }
}

void Dialog_Calibration::on_PushButton_Calibration_SaveResult_clicked()
{
    Calibration_SaveResult();
    ui->Label_Calibration_Message->setText("设备标定数据保存成功！");

}

void Dialog_Calibration::on_PushButton_Calibration_AbandonResult_clicked()
{
//    // 串口发送规范化消息
//       emit Serial_Write(base_function::Serial_DataFormat(send_Calibration_DontSaveResult));
//       // 记录最后一次执行的操作，方便增加限制用户操作
//       send_Calibration_head = send_Calibration_DontSaveResult;
//       // 计时，如果没有成功握手就报错
//       Calibration_SetTimer(true);
}


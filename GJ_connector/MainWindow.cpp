#include "MainWindow.h"
//#include "ui_MainWindow.h"
#include "./moc_ui/ui_GJMainWindow.h"
#include "./global/globalsetting.h"

namespace  {
    GlobalSetting *pGlobalSetting = GlobalSetting::getInstance();
    const QString VERSION("Version: 1.0.6");
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow_Init();
}

MainWindow::~MainWindow()
{
    delete serialport;
    thread_SerialPort->quit();
    thread_SerialPort->wait();

    delete saveserialdata;
    thread_SerialDataSave->quit();
    thread_SerialDataSave->wait();

    delete ui;
}

// 初始化函数
void MainWindow::MainWindow_Init()  // 初始化函数
{
    QWidget::setAttribute(Qt::WA_QuitOnClose,true);

    this->setWindowTitle("上海共迹科技有限公司");
    QLabel *label = new QLabel(VERSION);
    label->setAlignment(Qt::AlignRight);
    ui->statusBar_position->addWidget(label, 1); // 第二个参数是伸缩因子

    // toolBar增加按钮和分隔符
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->action_FirmWare);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->action_TrackMap);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->action_ProtocolChange);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->action_CustomCan);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->action_VersionMsg);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->action_Encryption);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->action_advanced);
    ui->toolBar->addSeparator();

    ui->toolBar->addAction(ui->actionactIStaticIPCfg);
    ui->toolBar->addSeparator();

    // ui->toolBar.addAction()

    // 线程建立
    thread_SerialPort = new QThread();      // 创建串口线程
    serialport = new SerialPort();          // 创建串口类对象
    serialport->moveToThread(thread_SerialPort);    // 将对象放线程里
    thread_SerialPort->start();             // 线程启动

    thread_SerialDataSave = new QThread();  // 创建串口数据保存线程
    saveserialdata = new SaveSerialData();  // 创建串口数据保存类对象
    saveserialdata->moveToThread(thread_SerialDataSave);    // 将对象放线程里
    thread_SerialDataSave->start();         // 线程启动

//    AdministratorMode();
    ui->frameVSMS1000InstallInfo->setVisible(false);
}

void MainWindow::AfterOpenSerial_Init()     // 打开串口后的初始化函数
{
    Serial_ButtonState(false);
    connect(serialport, SIGNAL(delDone_GJProtocol_Data()), this, SLOT(delDone_GJProtocol_Data()));
}

// 串口相关的关函数
void MainWindow::Search_Serial()        // 检测串口
{
    if(ui->PushButton_OpenSerial->text()=="关闭串口")
    {
        QMessageBox::critical(this,"错误", " 请先关闭串口! ");
        return;
    }
    else
    {
        ui->ComboBox_Port->clear();//清除历史记录
        foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) // 获得端口名
        {
            QSerialPort serial;
            if(!info.isBusy())      // 判断端口是否已经被占用了
            {
                serial.setPort(info);
                if(serial.open(QIODevice::ReadWrite))   //端口数据获取是否成功
                {
                    ui->ComboBox_Port->addItem(serial.portName());
                    serial.close();
                }
            }
        }
        ui->ComboBox_Baud->setCurrentIndex(11); //设置默认波特率
    }
}

void MainWindow::Open_Serial()      // 打开串口
{
    if(ui->ComboBox_Port->currentIndex()==-1)
    {
        QMessageBox::critical(this,"错误", " 请选择串口! ");
        return;
    }
    else
    {
        QString PortName;
        int BaudRate;
        QSerialPort::DataBits DataBits;
        QSerialPort::Parity Parity;
        QSerialPort::StopBits StopBits;

        PortName = ui->ComboBox_Port->currentText();
        BaudRate = ui->ComboBox_Baud->currentText().toInt();
        //设置数据位数
        switch(ui->ComboBox_BitNum->currentIndex())
        {
            case 1: DataBits = QSerialPort::Data5; break;
            case 2: DataBits = QSerialPort::Data6; break;
            case 3: DataBits = QSerialPort::Data7; break;
            case 0: DataBits = QSerialPort::Data8; break;
            default: DataBits = QSerialPort::Data8; break;

        }
        //设置奇偶校验
        switch(ui->ComboBox_Parity->currentIndex())
        {
            case 0: Parity = QSerialPort::NoParity; break;
            case 2: Parity = QSerialPort::EvenParity; break;
            case 3: Parity = QSerialPort::OddParity; break;
            case 4: Parity = QSerialPort::SpaceParity; break;
            case 5: Parity = QSerialPort::MarkParity; break;
            case -1: Parity = QSerialPort::UnknownParity; break;
            default: Parity = QSerialPort::NoParity; break;
        }
        //设置停止位
        switch(ui->ComboBox_Stop->currentIndex())
        {
            case 1: StopBits = QSerialPort::OneStop; break;
            case 2: StopBits = QSerialPort::TwoStop; break;
            default: StopBits = QSerialPort::OneStop; break;
        }

        if(serialport->Open_Serial(PortName,
                                BaudRate,
                                DataBits,
                                Parity,
                                StopBits)       // 将主界面信息发送给串口类实体
                                == true)
        {
            //初始化
            AfterOpenSerial_Init();     // 打开串口后的初始化函数
        }
        else
        {
            QMessageBox::about(this,"错误", "串口已被占用");
        }


    }
}

void MainWindow::Close_Serial()     // 关闭串口
{
    if(ui->PushButton_SaveSerialData_StartSave->text() == "停止保存")
    {
        QMessageBox::about(this,"提示","请停止保存数据！");
        return;
    }

    serialport->Close_Serial();
    disconnect(serialport, SIGNAL(delDone_GJProtocol_Data()), this, SLOT(delDone_GJProtocol_Data()));

    Serial_ButtonState(true);   //恢复设置使能
}

void MainWindow::Serial_ButtonState(bool state) //控制串口元器件的使能情况
{
    if(state)
    {
        ui->PushButton_OpenSerial->setText(tr("打开串口"));
    }
    else
    {
        ui->PushButton_OpenSerial->setText(tr("关闭串口"));
    }
    ui->ComboBox_Port->setEnabled(state);
    ui->ComboBox_Baud->setEnabled(state);
    ui->ComboBox_BitNum->setEnabled(state);
    ui->ComboBox_Parity->setEnabled(state);
    ui->ComboBox_Stop->setEnabled(state);
}

void MainWindow::Selete_SaveSerialData_File()   // 选择保存路径
{
    QSettings setting("./Setting.ini", QSettings::IniFormat);          //为了能记住上次打开的路径
    QString lastPath = setting.value("LastFilePath").toString();

    SaveSerialData_FileName_Path = QFileDialog::getSaveFileName(this,
                                                tr("选择文件"),
                                                lastPath,
                                                tr("ALL Files(*)"));
    if(SaveSerialData_FileName_Path.isEmpty())
    {
        ui->Label_SaveSerialData_StateMsg->setText("请选择数据存储文件！");
        ui->PushButton_SaveSerialData_StartSave->setEnabled(false);
    }
    else
    {
        ui->Label_SaveSerialData_StateMsg->setText("文件将存在/n" + SaveSerialData_FileName_Path + "！");
        ui->PushButton_SaveSerialData_StartSave->setEnabled(true);
    }
}

void MainWindow::Start_SaveSerialData()     // 开始保存数据
{
    ui->PushButton_SaveSerialData_StartSave->setText("停止保存");
    ui->PushButton_SaveSerialData_SeletePath->setEnabled(false);
    ui->CheckBox_SaveSerialData_WithTime->setEnabled(false);

    saveserialdata->Open_File(SaveSerialData_FileName_Path,  ui->CheckBox_SaveSerialData_WithTime->isChecked());
    connect(serialport,&SerialPort::delDoneData,saveserialdata,&SaveSerialData::SaveData_File);

}

void MainWindow::Stop_SaveSerialData()      // 停止保存数据
{
    ui->PushButton_SaveSerialData_StartSave->setText("开始保存");
    ui->PushButton_SaveSerialData_SeletePath->setEnabled(true);
    ui->CheckBox_SaveSerialData_WithTime->setEnabled(true);

    saveserialdata->close_File();
    disconnect(serialport,&SerialPort::delDoneData,saveserialdata,&SaveSerialData::SaveData_File);
}

void MainWindow::setVSMS1000Visible()
{
    ui->frameVSMS1000InstallInfo->setVisible(pGlobalSetting->getMoudelType() == E_VSMS1000 ? 1:0);//显示or隐形
}

void MainWindow::delDone_GJProtocol_Data()  // 共迹协议解析ok时，展示
{
    if(ui->PushButton_CaliDialog->isEnabled() == false)
    {
        return;
    }
    if(checkVersionNum)
    {
        //已检测过
    }
    else
    {
        // if(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BSW_Ver_B4 < 200 && SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.BSW_Ver_B4 > 0)
        // {
        //     checkVersionNum = true;
        //     QMessageBox::critical(this,"错误", " 固件版本较低，请联系工作人员更新固件或更换旧版上位机 ");

        // }
    }
    //判断选择产品对应的结构体
    QVariant msgBufVariant = pGlobalSetting->getMsgBuf();
    if (msgBufVariant.canConvert<GJDeVice_MsgBuf_920Vertion*>())
    {

        GJDeVice_MsgBuf_920Vertion *msgBuf920 = msgBufVariant.value<GJDeVice_MsgBuf_920Vertion*>();
        extractAndCalculateMsgData(msgBuf920);
    }
    else if (msgBufVariant.canConvert<GJDeVice_MsgBuf_1000Vertion*>())
    {
        GJDeVice_MsgBuf_1000Vertion *msgBuf1000 = msgBufVariant.value<GJDeVice_MsgBuf_1000Vertion*>();
        extractAndCalculateMsgData(msgBuf1000);

        //1000产品 多了一个frameVSMS1000InstallInfo框架
        double VehicleLongitudinal = msgBuf1000->GJDeVice_Msg.INS_Vehicle_longitudinal  * RATIO_21;
        double VehicleLateral = msgBuf1000->GJDeVice_Msg.INS_Vehicle_lateral  * RATIO_21;
        double VehicleVertical = msgBuf1000->GJDeVice_Msg.INS_Vehicle_vertical  * RATIO_21;
        double VehicleSideslipangle = msgBuf1000->GJDeVice_Msg.INS_Vehicle_Sideslipangle  * RATIO_21;
        ui->LineEditINSVehicleLongitudinal->setText(QString::number(VehicleLongitudinal, 'f', 7));
        ui->LineEditINSVehicleLateral->setText(QString::number(VehicleLateral, 'f', 7));
        ui->LineEditINSVehicleVertical->setText(QString::number(VehicleVertical, 'f', 7));
        ui->LineEditINSVehicleSlideslipangle->setText(QString::number(VehicleSideslipangle, 'f', 7));
    }

}

void MainWindow::AdministratorMode()    // 管理员权限打开
{
    if(!AdministratorMode_flag)
    {
        AdministratorMode_flag = true;
        ui->toolBar->addAction(ui->action_TempCali);
        ui->toolBar->addSeparator();
        ui->toolBar->addAction(ui->action_PollingData);
        ui->toolBar->addSeparator();
    }
}

// 响应类型按钮
void MainWindow::on_PushButton_CheckSerial_clicked()
{
    Search_Serial();
}

void MainWindow::on_PushButton_OpenSerial_clicked()
{
    if(ui->PushButton_OpenSerial->text()=="打开串口")
    {
        checkVersionNum = false;
        Open_Serial();
    }
    else
    {
        Close_Serial();
    }
}

void MainWindow::on_PushButton_SaveSerialData_SeletePath_clicked()
{
    Selete_SaveSerialData_File();
}

void MainWindow::on_PushButton_SaveSerialData_StartSave_clicked()
{
    if(ui->PushButton_SaveSerialData_StartSave->text() == "开始保存")
    {
        Start_SaveSerialData();
    }
    else
    {
        Stop_SaveSerialData();
    }
}


// 创建新界面类型按钮
void MainWindow::on_action_FirmWare_triggered()
{
    /*if(ui->PushButton_OpenSerial->text()=="打开串口")
    {
        QMessageBox::about(this,"提示","请打开串口！");
        return;
    }*/

    if(isOpen_Dialog_FirmWare)
    {
        return;
    }
    isOpen_Dialog_FirmWare = true;


    Dialog_FirmWare *dialog_FirmWare = new Dialog_FirmWare;

    connect(serialport,SIGNAL(receive_Firmware_PleaseWaitUpdata_head()),dialog_FirmWare,
                         SLOT(receive_Firmware_PleaseWaitUpdata_head()));
    connect(serialport,SIGNAL(receive_Firmware_ReceiveError_head()),dialog_FirmWare,
                         SLOT(receive_Firmware_ReceiveError_head()));
    connect(serialport,SIGNAL(receive_Firmware_FileError_head()),dialog_FirmWare,
                         SLOT(receive_Firmware_FileError_head()));
    connect(serialport,SIGNAL(receive_Firmware_UpdataError_head()),dialog_FirmWare,
                         SLOT(receive_Firmware_UpdataError_head()));
    connect(serialport,SIGNAL(receive_Firmware_UpdataSuccess_head()),dialog_FirmWare,
                         SLOT(receive_Firmware_UpdataSuccess_head()));

    connect(dialog_FirmWare, SIGNAL(Serial_Write(QByteArray)), serialport, SLOT(Serial_Write(QByteArray)));

    dialog_FirmWare->show();
    dialog_FirmWare->exec();
    checkVersionNum = false;
    isOpen_Dialog_FirmWare = false;
}

void MainWindow::on_PushButton_CaliDialog_clicked()
{
    /*if(ui->PushButton_OpenSerial->text()=="打开串口")
    {
        QMessageBox::about(this,"提示","请打开串口！");
        return;
    }*/

    if(isOpen_Dialog_Calibration)
    {
        return;
    }
    isOpen_Dialog_Calibration = true;

    Dialog_Calibration *dialog_Calibration = new Dialog_Calibration;

    connect(serialport,SIGNAL(receiveACK_Calibration_UserInstallationAngle_head()),dialog_Calibration,
                         SLOT(receiveACK_Calibration_UserInstallationAngle_head()));
    connect(serialport,SIGNAL(receiveACK_Calibration_SystemInstallationAangle_head()),dialog_Calibration,
                         SLOT(receiveACK_Calibration_SystemInstallationAangle_head()));
    connect(serialport,SIGNAL(receiveACK_Calibration_Static_head()),dialog_Calibration,
                         SLOT(receiveACK_Calibration_Static_head()));
    connect(serialport,SIGNAL(receiveACK_Calibration_Dynamic_head()),dialog_Calibration,
                         SLOT(receiveACK_Calibration_Dynamic_head()));
    connect(serialport,SIGNAL(receiveACK_Calibration_Cancel_head()),dialog_Calibration,
                         SLOT(receiveACK_Calibration_Cancel_head()));
    connect(serialport,SIGNAL(receiveACK_Calibration_SaveResult_head()),dialog_Calibration,
                         SLOT(receiveACK_Calibration_SaveResult_head()));
    connect(serialport,SIGNAL(receiveACK_Calibration_DontSaveResult_head()),dialog_Calibration,
                         SLOT(receiveACK_Calibration_DontSaveResult_head()));
    connect(serialport,SIGNAL(receiveACK_Calibration_WheelBase_head()),dialog_Calibration,
                         SLOT(receiveACK_Calibration_WheelBase_head()));
    connect(serialport,SIGNAL(receiveACK_Calibration_LeverINS2Rear_head()),dialog_Calibration,
                         SLOT(receiveACK_Calibration_LeverINS2Rear_head()));

    connect(serialport,SIGNAL(receive_Calibration_StaticCalibrating_head()),dialog_Calibration,
                         SLOT(receive_Calibration_StaticCalibrating_head()));
    connect(serialport,SIGNAL(receive_Calibration_StaticSuccess_head()),dialog_Calibration,
                         SLOT(receive_Calibration_StaticSuccess_head()));
    connect(serialport,SIGNAL(receive_Calibration_DynamicCalibrating_head()),dialog_Calibration,
                         SLOT(receive_Calibration_DynamicCalibrating_head()));
    connect(serialport,SIGNAL(receive_Calibration_IncTurningRatio_head()),dialog_Calibration,
                         SLOT(receive_Calibration_IncTurningRatio_head()));
    connect(serialport,SIGNAL(receive_Calibration_IncForwardRatio_head()),dialog_Calibration,
                         SLOT(receive_Calibration_IncForwardRatio_head()));
    connect(serialport,SIGNAL(receive_Calibration_PleaseChangeCaliSites_head()),dialog_Calibration,
                         SLOT(receive_Calibration_PleaseChangeCaliSites_head()));
    connect(serialport,SIGNAL(receive_Calibration_DynamicSuccess_head()),dialog_Calibration,
                         SLOT(receive_Calibration_DynamicSuccess_head()));

    connect(dialog_Calibration, SIGNAL(Serial_Write(QByteArray)), serialport, SLOT(Serial_Write(QByteArray)));

    dialog_Calibration->show();
    dialog_Calibration->exec();
    isOpen_Dialog_Calibration = false;
}

void MainWindow::on_action_TrackMap_triggered()
{
    /*if(ui->PushButton_OpenSerial->text()=="打开串口")
    {
        QMessageBox::about(this,"提示","请打开串口！");
        return;
    }*/

    if(isOpen_Dialog_TrackMap)
    {
        return;
    }
    isOpen_Dialog_TrackMap = true;

    Dialog_TrackMap *dialog_TrackMap = new Dialog_TrackMap;

    connect(serialport,SIGNAL(delDone_GJProtocol_TrackMap_Point()),dialog_TrackMap,SLOT(delDone_GJProtocol_TrackMap_Point()));

    dialog_TrackMap->show();
    dialog_TrackMap->exec();
    isOpen_Dialog_TrackMap = false;
}

void MainWindow::on_action_VersionMsg_triggered()
{
    /*if(ui->PushButton_OpenSerial->text()=="打开串口")
    {
        QMessageBox::about(this,"提示","请打开串口！");
        return;
    }*/

    if(isOpen_Dialog_VersionMsg)
    {
        return;
    }
    isOpen_Dialog_VersionMsg = true;

    Dialog_VersionMsg *dialog_VersionMsg = new Dialog_VersionMsg;

    if(AdministratorMode_flag)
    {
        dialog_VersionMsg->setMaximumSize(580,339);
        dialog_VersionMsg->setMinimumSize(580,339);
        dialog_VersionMsg->resize(QSize(580, 339));
    }
    else
    {
        dialog_VersionMsg->setMaximumSize(580,180);
        dialog_VersionMsg->setMinimumSize(580,180);
        dialog_VersionMsg->resize(QSize(580, 180));
    }

    connect(dialog_VersionMsg, SIGNAL(Serial_Write(QByteArray)), serialport, SLOT(Serial_Write(QByteArray)));

    dialog_VersionMsg->show();
    dialog_VersionMsg->exec();
    isOpen_Dialog_VersionMsg = false;
}

void MainWindow::on_action_TempCali_triggered()
{
    /*if(ui->PushButton_OpenSerial->text()=="打开串口")
    {
        QMessageBox::about(this,"提示","请打开串口！");
        return;
    }*/

    if(isOpen_Dialog_TempCali)
    {
        return;
    }
    isOpen_Dialog_TempCali = true;

    Dialog_TempCali *dialog_TempCali = new Dialog_TempCali;

    connect(serialport,SIGNAL(receive_TempCali_RequestData_head()),dialog_TempCali,
                         SLOT(receive_TempCali_RequestData_head()));
    connect(serialport,SIGNAL(receive_TempCali_RepeatData_head()),dialog_TempCali,
                         SLOT(receive_TempCali_RepeatData_head()));
    connect(serialport,SIGNAL(receive_TempCali_CompleteData_head()),dialog_TempCali,
                         SLOT(receive_TempCali_CompleteData_head()));
    connect(serialport,&SerialPort::receive_TempCali_DeviceHasSavedData_head,
            dialog_TempCali,&Dialog_TempCali::receive_TempCali_DeviceHasSavedData_head);

    connect(dialog_TempCali, SIGNAL(Serial_Write(QByteArray)), serialport, SLOT(Serial_Write(QByteArray)));

    dialog_TempCali->show();
    dialog_TempCali->exec();
    isOpen_Dialog_TempCali = false;
}

void MainWindow::on_action_PollingData_triggered()
{
    /*if(ui->PushButton_OpenSerial->text()=="打开串口")
    {
        QMessageBox::about(this,"提示","请打开串口！");
        return;
    }*/

    if(isOpen_Dialog_PollingData)
    {
        return;
    }
    isOpen_Dialog_PollingData = true;

    Dialog_PollingData *dialog_PollingData = new Dialog_PollingData;

    connect(serialport, SIGNAL(delDone_GJProtocol_PollingData()), dialog_PollingData, SLOT(delDone_GJProtocol_PollingData()));

    dialog_PollingData->show();
    dialog_PollingData->exec();
    isOpen_Dialog_PollingData = false;
}

void MainWindow::on_action_ProtocolChange_triggered()
{
    /*if(ui->PushButton_OpenSerial->text()=="打开串口")
    {
        QMessageBox::about(this,"提示","请打开串口！");
        return;
    }*/

    if(isOpen_Dialog_ProtocolChange)
    {
        return;
    }
    isOpen_Dialog_ProtocolChange = true;

    Dialog_ProtocolChange *dialog_ProtocolChange = new Dialog_ProtocolChange;

    connect(dialog_ProtocolChange, SIGNAL(Serial_Write(QByteArray)), serialport, SLOT(Serial_Write(QByteArray)));
    connect(serialport,SIGNAL(receiveACK_ChangeProtocolOK_head()),dialog_ProtocolChange,
                 SLOT(receiveACK_ChangeProtocolOK_head()));

    connect(serialport, &SerialPort::sig_recCusmtomProtocolResponseHead, dialog_ProtocolChange, &Dialog_ProtocolChange::slot_recCustomProtocolResponse);


    dialog_ProtocolChange->show();
    dialog_ProtocolChange->exec();
    isOpen_Dialog_ProtocolChange = false;
}

void MainWindow::on_action_Encryption_triggered()
{
    /*if(ui->PushButton_OpenSerial->text()=="打开串口")
    {
        QMessageBox::about(this,"提示","请打开串口！");
        return;
    }*/

    if(isOpen_Dialog_Encryption)
    {
        return;
    }
    isOpen_Dialog_Encryption = true;

    Dialog_Encryption *dialog_Encryption = new Dialog_Encryption;

    if(AdministratorMode_flag)
    {

        dialog_Encryption->setMaximumSize(482,330);
        dialog_Encryption->setMinimumSize(482,330);
        dialog_Encryption->resize(QSize(482, 330));
    }
    else
    {
        dialog_Encryption->setMaximumSize(480,159);
        dialog_Encryption->setMinimumSize(480,159);
        dialog_Encryption->resize(QSize(480, 159));
    }

    connect(dialog_Encryption, SIGNAL(AdministratorMode()), this, SLOT(AdministratorMode()));
    connect(dialog_Encryption, SIGNAL(Serial_Write(QByteArray)), serialport, SLOT(Serial_Write(QByteArray)));

    dialog_Encryption->show();
    dialog_Encryption->exec();
    isOpen_Dialog_Encryption = false;
}

void MainWindow::on_action_CustomCan_triggered()
{
    /*if(ui->PushButton_OpenSerial->text()=="打开串口")
    {
        QMessageBox::about(this,"提示","请打开串口！");
        return;
    }*/

    if(isOpen_Dialog_CustomCan)
    {
        return;
    }
    isOpen_Dialog_CustomCan = true;

    Dialog_CustomCan *dialog_CustomCan = new Dialog_CustomCan;

    connect(dialog_CustomCan, SIGNAL(Serial_Write(QByteArray)), serialport, SLOT(Serial_Write(QByteArray)));
    connect(serialport,SIGNAL(receiveACK_CustomCan_head()),dialog_CustomCan,
                        SLOT(receiveACK_CustomCan_head()));

    dialog_CustomCan->show();
    dialog_CustomCan->exec();
    isOpen_Dialog_CustomCan = false;

}

void MainWindow::on_action_advanced_triggered()
{
    /*if(ui->PushButton_OpenSerial->text()=="打开串口")
    {
        QMessageBox::about(this,"提示","请打开串口！");
        return;
    }*/

    if(isOpen_Dialog_advanced)
    {
        return;
    }
    isOpen_Dialog_advanced = true;

    Dialog_advanced *dialog_advanced = new Dialog_advanced;

    connect(dialog_advanced, SIGNAL(Serial_Write(QByteArray)), serialport, SLOT(Serial_Write(QByteArray)));
    connect(serialport,SIGNAL(receiveACK_RTCMSelectType_head()),dialog_advanced,
                        SLOT(receiveACK_RTCMSelectType_head()));

    connect(serialport, &SerialPort::sig_recETHCfg_data_head, dialog_advanced, &Dialog_advanced::slot_recETHCfg_Ack);
    connect(serialport, &SerialPort::sig_recETHCfg_ReturnData, dialog_advanced, &Dialog_advanced::slot_recETHCfg_ReturnData);
    dialog_advanced->show();
    dialog_advanced->exec();
    isOpen_Dialog_advanced = false;
}

void MainWindow::on_actionactIStaticIPCfg_triggered()
{
    /*if(ui->PushButton_OpenSerial->text()=="打开串口")
    {
        QMessageBox::about(this,"提示","请打开串口！");
        return;
    }*/
    if (nullptr == pDlg_ipConfig_)
    {
        pDlg_ipConfig_ = new Dlg_ipConfig(this);
    }
    if (!pDlg_ipConfig_->isVisible())
    {
        pDlg_ipConfig_->show();
        pDlg_ipConfig_->raise();
        pDlg_ipConfig_->activateWindow();
        connect(serialport, &SerialPort::receiveACK_StaticIPPort_head, pDlg_ipConfig_, &Dlg_ipConfig::slot_receiveACK_StaticIPPort_head, Qt::UniqueConnection);
        connect(pDlg_ipConfig_,  &Dlg_ipConfig::sig_Serial_Write, serialport, &SerialPort::Serial_Write);
    }
}

template <typename T>
void MainWindow::extractAndCalculateMsgData(T *msgBuf)
{
    double ax            = msgBuf->GJDeVice_Msg.ALG_Accl_X  * RATIO_17;
    double ay            = msgBuf->GJDeVice_Msg.ALG_Accl_Y  * RATIO_18;
    double az            = msgBuf->GJDeVice_Msg.ALG_Accl_Z  * RATIO_19;
    double gx            = msgBuf->GJDeVice_Msg.ALG_Gyro_X  * RATIO_20;
    double gy            = msgBuf->GJDeVice_Msg.ALG_Gyro_Y  * RATIO_21;
    double gz            = msgBuf->GJDeVice_Msg.ALG_Gyro_Z  * RATIO_22;
    double Lat           = msgBuf->GJDeVice_Msg.Latitude    * RATIO_02;
    double Lon           = msgBuf->GJDeVice_Msg.Longitude   * RATIO_03;
    double Height        = msgBuf->GJDeVice_Msg.Height      * RATIO_04;
    double VE            = msgBuf->GJDeVice_Msg.VE          * RATIO_05;
    double VN            = msgBuf->GJDeVice_Msg.VN          * RATIO_06;
    double VU            = msgBuf->GJDeVice_Msg.VU          * RATIO_07;
    double Pitch         = msgBuf->GJDeVice_Msg.Pitch       * RATIO_08;
    double Roll          = msgBuf->GJDeVice_Msg.Roll        * RATIO_09;
    double Heading       = msgBuf->GJDeVice_Msg.Yaw         * RATIO_10;
    double VehicleSpeed  = msgBuf->GJDeVice_Msg.VehicleSpd  * RATIO_79;
    double FLSpeed       = msgBuf->GJDeVice_Msg.WheelSpd_FL * RATIO_75;
    double FRSpeed       = msgBuf->GJDeVice_Msg.WheelSpd_FR * RATIO_76;
    double RLSpeed       = msgBuf->GJDeVice_Msg.WheelSpd_RL * RATIO_77;
    double RRSpeed       = msgBuf->GJDeVice_Msg.WheelSpd_RR * RATIO_78;
    ui->LineEdit_ax->setText            (QString::number(ax           , 'f', 7));
    ui->LineEdit_ay->setText            (QString::number(ay           , 'f', 7));
    ui->LineEdit_az->setText            (QString::number(az           , 'f', 7));
    ui->LineEdit_gx->setText            (QString::number(gx           , 'f', 7));
    ui->LineEdit_gy->setText            (QString::number(gy           , 'f', 7));
    ui->LineEdit_gz->setText            (QString::number(gz           , 'f', 7));
    ui->LineEdit_Lat1->setText           (QString::number(Lat          , 'f', 7));
    ui->LineEdit_Lon->setText           (QString::number(Lon          , 'f', 7));
    ui->LineEdit_Height->setText        (QString::number(Height       , 'f', 7));
    ui->LineEdit_VE->setText            (QString::number(VE           , 'f', 7));
    ui->LineEdit_VN->setText            (QString::number(VN           , 'f', 7));
    ui->LineEdit_VU->setText            (QString::number(VU           , 'f', 7));
    ui->LineEdit_Pitch->setText         (QString::number(Pitch        , 'f', 7));
    ui->LineEdit_Roll->setText          (QString::number(Roll         , 'f', 7));
    ui->LineEdit_Heading->setText       (QString::number(Heading      , 'f', 7));
    ui->LineEdit_VehicleSpeed->setText  (QString::number(VehicleSpeed , 'f', 7));
    ui->LineEdit_FLSpeed->setText       (QString::number(FLSpeed      , 'f', 7));
    ui->LineEdit_FRSpeed->setText       (QString::number(FRSpeed      , 'f', 7));
    ui->LineEdit_RLSpeed->setText       (QString::number(RLSpeed      , 'f', 7));
    ui->LineEdit_RRSpeed->setText       (QString::number(RRSpeed      , 'f', 7));

    ui->statusBar_position->showMessage("定位状态: " +      QString::number(msgBuf->GJDeVice_Msg.GNSS_PosStatus) +
                                        "  主天线个数: " +  QString::number(msgBuf->GJDeVice_Msg.GNSS_Antenna) +
                                        "  副天线个数: " +  QString::number(msgBuf->GJDeVice_Msg.GNSS_Antenna2));
}

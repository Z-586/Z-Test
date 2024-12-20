#include "dialog_firmware.h"
#include "MainWindow.h"
#include "ui_dialog_firmware.h"

Dialog_FirmWare::Dialog_FirmWare(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_FirmWare)
{
    ui->setupUi(this);
    Dialog_FirmWare_Init();
}

Dialog_FirmWare::~Dialog_FirmWare()
{
    FirmWareFile_sendtimer->stop();
    FirmWareFile_sendtimer->deleteLater();

    delete ui;
}

void Dialog_FirmWare :: closeEvent(QCloseEvent *e)
{
    close_Flag = 1;
}

// Init
void Dialog_FirmWare::Dialog_FirmWare_Init()    // 初始化函数
{
    this->setWindowTitle("固件更新");

    QWidget::setAttribute(Qt::WA_QuitOnClose,false);     // 所有子窗口要写false
    QWidget::setAttribute(Qt::WA_DeleteOnClose);     // 所有子窗口要写false
    setWindowFlags((windowFlags()&~Qt::WindowContextHelpButtonHint) | Qt::WindowMinimizeButtonHint);

    FileName_Path = "";
    FirmWare_ButtonState(1,0,1);

    ui->ProgressBar_FirmWare_ProgressBar->setRange(0,100);      // 进度条
    connect(FirmWareFile_sendtimer, &QTimer::timeout, this, &Dialog_FirmWare::FirmWareFile_sendtimeout);//关联计时器
}

// Base Function
void Dialog_FirmWare::FirmWare_ButtonState(bool Selete, bool Updata, bool Complete) // 三个按钮的使能控制，第一个按钮只有在更新中时变灰，第二个按钮只有在读取文件或者发送完成后变亮，第三个只有在发送成功后变亮
{
    ui->PushButton_FirmWare_SeleteFile->setEnabled(Selete);
    ui->PushButton_FirmWare_Updata->setEnabled(Updata);
    ui->PushButton_FirmWare_Complete->setEnabled(Complete);
}

void Dialog_FirmWare::Selete_FirmWare_File()    // 选择固件更新文件
{
    QSettings setting("./Setting.ini", QSettings::IniFormat);          //为了能记住上次打开的路径
    QString lastPath = setting.value("LastFilePath").toString();

    FileName_Path = QFileDialog::getOpenFileName(this,
                                                tr("选择文件"),
                                                lastPath,
                                                tr("*bin"));
    if(FileName_Path.isEmpty())     // 没选择文件
    {
        ui->Label_FirmWare_Msg->setText("请选择需要更新的文件！");
        FirmWare_ButtonState(1,0,0);    // 不使能第二个按钮
    }
    else
    {
        ui->Label_FirmWare_Msg->setText(FileName_Path);
        FirmWare_ButtonState(1,1,0);    // 使能第二个按钮
    }
}

void Dialog_FirmWare::Send_FirmWare_File()    // 更新（发送）固件
{
    QByteArray FirmWare_binByteArray;

    QFile file(FileName_Path);
    if (file.open(QIODevice::ReadOnly))
    {
        FirmWare_binByteArray = file.readAll();     // 获取全部数据
        file.close();
    }
    else
    {
        ui->Label_FirmWare_Msg->setText("文件打开错误！\n"+FileName_Path);
        return;
    }

    if (FirmWare_binByteArray.size()!=0)
    {
        ui->Label_FirmWare_Msg->setText("正在发送固件,请耐心等待...");
        FirmWare_ButtonState(0,0,0);

        emit Serial_Write(base_function::Serial_DataFormat(send_Firmware_Updata));  // 发送字头
        base_function::sleep(3000);                 // 等待3s

        FirmWareFile_sendtimer->stop();
        emit Serial_Write(FirmWare_binByteArray);   // 发送数据
        FirmWareFile_sendtimer->start(120 * 1000);
    }
}

void Dialog_FirmWare::WaitUpdate_FirmWare_File()    // 等待固件更新
{

    rangeBar = false;

    for (int i = 0;i<100;i++)       // 进度条变化
    {
        if(ui->ProgressBar_FirmWare_ProgressBar->value() == 100)
        {
            break;
        }
        if(close_Flag)
        {
            break;
        }
        if(rangeBar)
        {
            rangeBar = false;
            ui->ProgressBar_FirmWare_ProgressBar->setValue(100);
            break;
        }
        ui->ProgressBar_FirmWare_ProgressBar->setValue(i+1);
        base_function::sleep(600);
    }
}


void Dialog_FirmWare::FirmWareFile_sendtimeout()    // 超时会根据提示来判断什么阶段超时了
{
    FirmWareFile_sendtimer->stop();
    FirmWare_ButtonState(1,0,0);

    if(ui->Label_FirmWare_Msg->text() == "正在发送固件,请耐心等待...")
    {
        ui->Label_FirmWare_Msg->setText("固件接收超时！");
    }
    else
    {
        ui->Label_FirmWare_Msg->setText("固件更新超时！");
    }
}

// SLOTS
// 上位机收到底层发送的消息码
void Dialog_FirmWare::receive_Firmware_PleaseWaitUpdata_head()
{
    FirmWareFile_sendtimer->stop();
    ui->Label_FirmWare_Msg->setText("固件发送完成，请等待设备内部更新固件！");
    FirmWareFile_sendtimer->start(120 * 1000);
    WaitUpdate_FirmWare_File();
}

void Dialog_FirmWare::receive_Firmware_ReceiveError_head()
{
    FirmWareFile_sendtimer->stop();
    FirmWare_ButtonState(1,0,0);
    ui->Label_FirmWare_Msg->setText("接收固件错误！请检查设备连接，并尝试重启上位机和设备。");
}

void Dialog_FirmWare::receive_Firmware_FileError_head()
{
    rangeBar = true;
    FirmWareFile_sendtimer->stop();
    FirmWare_ButtonState(1,0,0);
    ui->Label_FirmWare_Msg->setText("不是正确固件！");
}

void Dialog_FirmWare::receive_Firmware_UpdataError_head()
{
    FirmWareFile_sendtimer->stop();
    FirmWare_ButtonState(1,0,0);
    ui->Label_FirmWare_Msg->setText("固件更新失败！请检查设备连接，并尝试重启上位机和设备。");
}

void Dialog_FirmWare::receive_Firmware_UpdataSuccess_head()
{
    FirmWareFile_sendtimer->stop();
    FirmWare_ButtonState(1,0,1);
    ui->Label_FirmWare_Msg->setText("固件更新完成！");
}

// Button SLOTS
// 所有按钮信号槽
void Dialog_FirmWare::on_PushButton_FirmWare_SeleteFile_clicked()
{
    Selete_FirmWare_File();
}

void Dialog_FirmWare::on_PushButton_FirmWare_Updata_clicked()
{
    Send_FirmWare_File();
}

void Dialog_FirmWare::on_PushButton_FirmWare_Complete_clicked()
{
    this->done(QDialog::Rejected);
}

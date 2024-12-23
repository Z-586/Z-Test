#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTime"
#include "QLabel"
#include "QFile"
#include  <QDesktopServices>
#include <QUrl>
#include <QDir>
#include "set.h"

extern uint8_t startWriteCaliData_flag_can;

int RunFlag =0;
int canBaud;
int can_index;

HW_CAN CANalyst;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    parameterSet = new setParameter(this);
    ui->radioButtonStatus->setStyleSheet("QRadioButton::indicator {width:15px;height:15px;border-radius:7px}"
                                         "QRadioButton::indicator:checked {background-color:green;}"
                                         "QRadioButton::indicator:unchecked {background-color:grey;}"
                                        );
    QStringList Port = initComm();   // 初始化串口
    // parameterInit(Port);
    Set::readConfig();
    statusBarInfor = new QLabel(this);

    aboutSoft   = new about(this);
    aboutAuthor = new author(this);


    ui->statusBar->addWidget(statusBarInfor,0); // 状态信息
    updateStatusBar();                          // 更新状态栏
    connect(this,&MainWindow::parameterSetPress, MainWindow::parameterSet,
                &setParameter::CfgToUi);
}

// 更新状态栏
void MainWindow::updateStatusBar(void)
{
    QString inf;
    QString infBoard;
    if( (true == Set::uartEn) || (true == Set::rs485En) ) // 串口通信
    {
        if( Set::currentSelectPort.isEmpty() )
        {
             inf = QString("通信类型：串口  端口号：未选择    ");
        }
        else
        {
            if(true == Set::uartEn)
                inf = QString("通信类型：串口  端口号：%1   波特率：%2 bps ,升级方式：串口").arg(Set::currentSelectPort).arg(Set::uartBaud);
            else
                inf = QString("通信类型：串口  端口号：%1   波特率：%2 bps ,升级方式：RS485， 地址:%3")
                        .arg(Set::currentSelectPort).arg(Set::uartBaud).arg(Set::rs485Addr);
        }
    }
    else if(true == Set::canEn)      //  CAN通信
    {    
        inf =QString("通信类型：CAN      CAN通道：%1  波特率：%2 Kbps ").arg(Set::canChannel+1).arg(Set::canBaud);
    }

    statusBarInfor->setText(inf + infBoard);
}

void MainWindow::parameterInit(QStringList Port)
{

    if( Port.isEmpty() )  // 扫描到的端口号为空
    {
        Set::currentSelectPort.clear();
    }
    else
    {
       Set::currentSelectPort = Port.first();
    }
    Set::uartBaud = 9600;
    Set::uartCheckSum =0;
    Set::canEn =false;
    Set::canChannel = 0;
    Set::canDevice = 0;
    Set::canBaud   =250;

    Set::canDevice = 1;      // CAN 设备类型，默认zlg
}

MainWindow::~MainWindow()
{
    delete ui;
}

//
void MainWindow::closeEvent(QCloseEvent *event)
 {
    RunFlag =0;
    serialport->close();
    Set::writeConfig();
    QTime reachTime = QTime::currentTime().addMSecs(100);
    while(QTime::currentTime() < reachTime);
 }

// 串口初始化
QStringList MainWindow::initComm()
{
    serialport = new QSerialPort();

    // 创建信号槽，接收串口数据
    connect(serialport, SIGNAL(readyRead()), this, SLOT(getCommData()));
    QStringList Ret = ComUpdate();
    return Ret;
}

QStringList MainWindow:: ComUpdate(void)
{
    // 初始化下拉控件
    QStringList PortNumber;
    PortNumber.clear();

    foreach(QSerialPortInfo info, QSerialPortInfo::availablePorts())
    {
        if(!info.isBusy())
        {
            PortNumber.append(info.portName());
        }
    }
    Set::portNumberList = PortNumber;
    return PortNumber;
}

// 接收数据
void MainWindow::getCommData()
{
    uint8_t RxBuf[12];

    QByteArray recvByteArray = serialport->readAll();
    qDebug() << "接收" << recvByteArray;

    int len = recvByteArray.length();
    if(len <=0) return ;

    UartRxDate.append(recvByteArray);
    while( UartRxDate.length() >=12  )
    {
        if      ( (uint8_t)UartRxDate[0] != 0xAA)
        {    UartRxDate.remove(0,1);        continue;}
        if ( (uint8_t)UartRxDate[1] != 0xAA)
        {    UartRxDate.remove(0,2);        continue;}
        if ( (uint8_t)UartRxDate[2] != 0xAA)
        {    UartRxDate.remove(0,3);        continue;}
        if ( (uint8_t)UartRxDate[3] != 0xFF)
        {    UartRxDate.remove(0,4);        continue;}
        if ((uint8_t)UartRxDate[6] != 0x04)
        {    UartRxDate.remove(0,7);        continue;}
        if ((uint8_t)UartRxDate[7] != 0x00)
        {    UartRxDate.remove(0,8);        continue;}

        memcpy(&RxBuf[0], UartRxDate.data(),12);
        UartRxDate.remove(0,12);
        ui->updata->SetRxFrame(&RxBuf[0],12);
    }
}

int MainWindow::closeUart()
{
    serialport->close();
    return 0;
}

/******************************************/
int MainWindow::openUart(void)
{
        // 配置串口，同时查看是否配置成功
        if(  Set::currentSelectPort.isEmpty() )  // 端口号为空
        {
            return -1;
        }
        serialport->setPortName(Set::currentSelectPort);
        qDebug() << serialport->portName() << Set::currentSelectPort;
        serialport->setBaudRate(Set::uartBaud);

        if(Set::uartCheckSum ==1)
            serialport->setParity(  QSerialPort::OddParity);

        else if(Set::uartCheckSum ==2)
            serialport->setParity(  QSerialPort::EvenParity);
        else
            serialport->setParity(  QSerialPort::NoParity);

        qDebug()<<"checksum is:"<< Set::uartCheckSum;


        serialport->setDataBits(QSerialPort::Data8);
        serialport->setStopBits(QSerialPort::OneStop);

        if(serialport->open(QSerialPort::ReadWrite))
        {
            return 0;
        }
        else
        {
            return -2;
        }
}

//参数设置 parameterSetStruct
void MainWindow::on_actionSetting_triggered()
{
    // 扫描端口号
    Set::portNumberList = ComUpdate();
    emit parameterSetPress();           //发射一个信号
    parameterSet->exec();
    updateStatusBar();                  //更新状态栏

}


void MainWindow::on_pushButtonConnect_clicked()
{
    if(ui->pushButtonConnect->text() == "连接" )//
    {
        if( (true == Set::uartEn) || (true == Set::rs485En)) //  串口模式
        {
            int ret =openUart();
            if(ret == -1)   // 端口号为空
            {
                ui->updata->addInformationShow("串口打开失败：端口号为空！.");
            }
            else if(ret == -2) //串口打开失败
            {
                ui->updata->addInformationShow("串口打开失败：端口可能被占用！.");
            }
            else if( ret == 0)  // 串口打开成功
            {
                QString Str;
                if( true == Set::uartEn )
                    Str = QString("串口打开成功，端口号：%1, 波特率:%2 bps  ,升级方式：串口")
                                .arg(Set::currentSelectPort).arg(Set::uartBaud);
                else
                    Str = QString("串口打开成功，端口号：%1, 波特率:%2 bps  ,升级方式：RS485, 地址: %3")
                                .arg(Set::currentSelectPort).arg(Set::uartBaud).arg(Set::rs485Addr);


                ui->updata->addInformationShow(Str);
                ui->radioButtonStatus->setChecked(true);
                ui->pushButtonConnect->setText("断开");
            }

            else
            {
                qDebug()<<"ret is:"<< ret;
            }
        }
        else if(true == Set::canEn)   // CAN 通讯模式
        {
            bool bCanConnected;
            if(Set::canDevice==0)
            {
                 canBaud = Set::canBaud;
                 can_index = ui->CanCardInfo->currentIndex();
                 bCanConnected =  CANalyst.OpenCan(Set::canBaud,ui->CanCardInfo->currentIndex());
            }
            else
            {
                 bCanConnected =  zlgCan.OpenCan(Set::canBaud,ui->CanCardInfo->currentIndex());
            }

            if(bCanConnected)
            {

                QString str1 = QString("Can Card Connected ok, Can baud is:%1 Kbps").arg(Set::canBaud);
                ui->updata->addInformationShow(str1);

                ui->radioButtonStatus->setChecked(true);
                ui->pushButtonConnect->setText("断开");

            }
            else
            {
                ui->updata->addInformationShow("Can Card Error!");
            }
        }

    }
    else if(ui->pushButtonConnect->text() == "断开")
    {
        if( ( true == Set::uartEn) || ( true == Set::rs485En) ) //  串口模式
        {
            closeUart();
            ui->updata->addInformationShow("串口关闭成功");
        }
        else if(true == Set::canEn)
        {
            if(Set::canDevice==0)    CANalyst.CloseCan();
            else                                zlgCan.CloseCan();
            ui->updata->addInformationShow("CAN关闭成功");
        }

        RunFlag =0;

        ui->radioButtonStatus->setChecked(false);
        ui->pushButtonConnect->setText("连接");
    }
}




// 帮助文档
void MainWindow::on_action_help_triggered()
{
    QString fileName = "./IAP_Help.docx";
    QString currentDir = QDir::currentPath();
    QFile file(fileName);
    if (file.exists())
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
    }
    else
    {
        QMessageBox::information(this,"提示","未找到帮助文档！");
    }
}


// 更新CAN列表
void MainWindow::on_RefreshCanCard_clicked()
{
    VCI_BOARD_INFO1 Info;
    int num = CANalyst.GetCanCardInfo(&Info);

    ui->CanCardInfo->clear();
    for(int i=0;i<num;i++)
    {
        char  s[9] = "CAN_";
        s[4] = Info.str_Usb_Serial[i][0];
        s[5] = Info.str_Usb_Serial[i][1];
        s[6] = Info.str_Usb_Serial[i][2];
        s[7] = Info.str_Usb_Serial[i][3];
        s[8] = 0;
        ui->CanCardInfo->addItem(s);
    }
}

// 联系作者
void MainWindow::on_action_Designer_triggered()
{
    aboutAuthor->exec();
}

// 关于
void MainWindow::on_actionabout_triggered()
{
    aboutSoft->exec();
}

void MainWindow::on_action_TempCali_triggered()
{
    WriteCali *writeCali = new WriteCali(this);
    writeCali->show();
    writeCali->exec();
}

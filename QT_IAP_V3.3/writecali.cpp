#include "writecali.h"
#include "ui_writecali.h"
#include "mainwindow.h"

#include <QSettings>
#include <QFileDialog>
#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include "hw_can.h"
#include    "set.h"

uint8_t  startWriteCaliData_flag_can;

WriteCali::WriteCali(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WriteCali)
{
    ui->setupUi(this);
    Init();
}

WriteCali::~WriteCali()
{
    delete ui;
}


void WriteCali::Init()    // 初始化函数
{
    this->setWindowTitle("发送温度标定数据");

    QWidget::setAttribute(Qt::WA_QuitOnClose,false);     // 所有子窗口要写false
    QWidget::setAttribute(Qt::WA_DeleteOnClose);     // 所有子窗口要写false
    setWindowFlags((windowFlags()&~Qt::WindowContextHelpButtonHint) | Qt::WindowMinimizeButtonHint);

    TempCali_ButtonState(1, 0, 0);
    TempCali_VariablesInit();
}

void WriteCali::TempCali_VariablesInit()  // 温度标定的变量初始化函数
{
    TempCali_ShouldSendData_number = 0;
    TempCali_File_ErrorData_number = 0;
    TempCali_File_RightData_number = 0;
    TempCali_File_OverflowData_number = 0;
}

void WriteCali::TempCali_ButtonState(bool Read, bool Send, bool Stop) // 所有按钮使能控制
{
    ui->PushButton_TempCali_ReadFile->setEnabled(Read);
    ui->PushButton_TempCali_SendFile->setEnabled(Send);
    ui->PushButton_TempCali_StopSendFile->setEnabled(Stop);
    ui->PushButton_pre->setEnabled(false);
    ui->PushButton_next->setEnabled(false);
}

void WriteCali::Read_TempCali_File()  // 读稳定标定数据
{
    TempCali_ButtonState(1, 0, 0);
    TempCali_VariablesInit();

    QSettings setting("./Setting.ini", QSettings::IniFormat);          //为了能记住上次打开的路径
    QString lastPath = setting.value("LastFilePath").toString();
    fileName_path = QFileDialog::getOpenFileName(this,
                                                    tr("选择文件"),
                                                    lastPath,
                                                    tr("*txt"));
    if(fileName_path.isEmpty())
    {
        ui->Label_TempCali_Msg->setText("请选择需要更新的文件！");
    }
    else
    {
        QByteArray TempCali_binByteArray;
        QFile file(fileName_path);
        if (file.open(QIODevice::ReadOnly))
        {
            TempCali_binByteArray = file.readAll();     // 提取文件所有数据
            file.close();
        }
        else
        {
            ui->Label_TempCali_Msg->setText("文件打开错误！\n"+fileName_path);
            return;
        }

        QString FileContent_String(TempCali_binByteArray);
        int indexof_star = FileContent_String.indexOf("*", 1);  // 判断是否有一个*号，没有表示没数据，报错
        if(indexof_star)
        {
            FindTrueData_TempCali_File(FileContent_String.mid(indexof_star));   // 开始找正确数据
        }
        else
        {
            ui->Label_TempCali_Msg->setText("请检查文件里是否有数据！");
        }
    }
}

void WriteCali::FindTrueData_TempCali_File(QString FileContent_String)    // 寻找正确数据
{
    QRegExp Separator = QRegExp("\t|\n|\r\n|\r| |,|;");
    QStringList FileContent_StringList;

    while(!FileContent_String.isEmpty())
    {
        int indexof_star = FileContent_String.indexOf("*", 1);  // 从*开始找数据
        if(indexof_star < 0)
        {
            indexof_star = FileContent_String.size()+1;
        }
        FileContent_StringList = FileContent_String.mid(1, indexof_star-1).split(Separator,QString::SkipEmptyParts);    // 分割数据
        FileContent_String.remove(0, indexof_star); // 移除已解析的数据

        if(TempCali_File_RightData_number < 50)
        {
            if(FileContent_StringList.size() == 34) // 数据长度是否正确？
            {
                ProcessTrueData_TempCali_File(FileContent_StringList);  // 开始处理正确数据
                TempCali_File_RightData_number++;
            }
            else
            {
                TempCali_File_ErrorData_number++;
            }
        }
        else
        {
            TempCali_File_OverflowData_number++;
        }
    }

    caliData_pages_can = (TempCali_File_RightData_number * 136 + 3) / 4;
    if(caliData_pages_can > 50 * 136)
    {
        QMessageBox::warning(this,"错误","温度点数大于50个！");
    }
    else
    {
        for(int page=0;page<caliData_pages_can;page++)  //文件数据装入can Update结构
        {
            wirteCaliData_Can[page].pages = caliData_pages_can;
            wirteCaliData_Can[page].page  = page;
            memcpy(&wirteCaliData_Can[page].pData[0] , &all_cali_data_bin[page*4], 4 );
        }
    }


    Display_Msg_TempCali_File();    // 显示结果
}

void WriteCali::ProcessTrueData_TempCali_File(QStringList FileContent_StringList)     // 开始处理正确数据
{
    TempCaliData[TempCali_File_RightData_number].TempCali_Msg.Temp = FileContent_StringList[0].toDouble();

    for (int i = 0;i < 3;i++) {
        TempCaliData[TempCali_File_RightData_number].TempCali_Msg.AccBias[i] = FileContent_StringList[1+i].toDouble();
        TempCaliData[TempCali_File_RightData_number].TempCali_Msg.GyroBias[i] = FileContent_StringList[4+i].toDouble();
    }
    for (int i = 0;i < 9;i++) {
        TempCaliData[TempCali_File_RightData_number].TempCali_Msg.Matrix_Ka[i] = FileContent_StringList[7+i].toDouble();
        TempCaliData[TempCali_File_RightData_number].TempCali_Msg.Matrix_Kg[i] = FileContent_StringList[16+i].toDouble();
        TempCaliData[TempCali_File_RightData_number].TempCali_Msg.Matrix_G[i]  = FileContent_StringList[25+i].toDouble();
    }

    memcpy(&all_cali_data_bin[TempCali_File_RightData_number*136],TempCaliData[TempCali_File_RightData_number].bytes, 136);

}

void WriteCali::Display_Msg_TempCali_File()   // 显示结果
{
    TempCali_ButtonState(1, 1, 0);
    QString msg = "";
    msg += fileName_path + "\n该文件一共有"+QString::number(TempCali_File_RightData_number + TempCali_File_ErrorData_number + TempCali_File_OverflowData_number)+"组数据。\n";
    msg += "其中：\n有效正确数据共计"+QString::number(TempCali_File_RightData_number)+"组;\n";
    if(!TempCali_File_RightData_number)
    {
        TempCali_ButtonState(1, 0, 0);
        msg += "(没有有效数据！请检查文件！)\n";
    }
    if(TempCali_File_ErrorData_number)
    {
        msg += "有问题数据共计"+QString::number(TempCali_File_ErrorData_number)+"组;\n";
        msg += "(请确定后再发送数据！)\n";
    }
    if(TempCali_File_OverflowData_number)
    {
        msg += "超出预期温度点个数的数据共计"+QString::number(TempCali_File_OverflowData_number)+"组;\n";
        msg += "(超出50个温度点的数据将被默认放弃！请注意！)\n";
    }
    ui->Label_TempCali_Msg->setText(msg);
}

void WriteCali::Send_TempCali_Data()  // 发送温度标定数据
{
    startWriteCaliData_flag_can = 1;
    TempCali_ButtonState(false,false,true);

    unsigned long CAN_Start_WriteCaliData_TX_ID = 0xF9;
    unsigned long CAN_End_WriteCaliData_TX_ID = 0xF8;
    unsigned long CAN_WriteCaliData_TX_ID = 0xF7;
    unsigned long CAN_WriteCaliData_RX_ID;
    unsigned char CAN_WriteCaliData_RX_Len;
    uint8_t CAN_tx[8] = {0};
    uint8_t CAN_rx[8] = {0};

    //开始发送，让设备进入就绪状态
    CanTx0(CAN_Start_WriteCaliData_TX_ID, 8, CAN_tx);

    Delay(300);

    CANalyst.CloseCan();
    CANalyst.OpenCan(canBaud,can_index);

    Delay(300);

    for(int i = 0; i < caliData_pages_can; i++)
    {
        calidata_buf_can senbuf;
        senbuf.msg = wirteCaliData_Can[i];
        memcpy(CAN_tx, senbuf.byte, 8);

        while(1)
        {

            CanTx0(CAN_WriteCaliData_TX_ID, 8, CAN_tx);

            Delay(50);

            CanRx0(&CAN_WriteCaliData_RX_ID, &CAN_WriteCaliData_RX_Len, CAN_rx);
            qDebug()<<wirteCaliData_Can[i].pages;
            qDebug()<<wirteCaliData_Can[i].page;
            qDebug()<<CAN_WriteCaliData_RX_ID;
            qDebug()<<"---";

            QString msg = "一共";
            msg += QString::number(caliData_pages_can);
            msg += "条报文\r\n 发送中：";
            msg += QString::number(i+1);
            msg += "/";
            msg += QString::number(caliData_pages_can);
            msg += "。\n";

            if(CAN_WriteCaliData_RX_ID != CAN_WriteCaliData_TX_ID)
            {
                msg += "第:";
                msg += QString::number(i+1);;
                msg += "接收错误重新发送。。。";
            }

            ui->Label_TempCali_Msg->setText(msg);

            uint16_t Rx_Total_Current = *( (uint16_t *)(&CAN_rx[0]));
            uint16_t Rx_Current = *( (uint16_t *)(&CAN_rx[2]));

            if( (Rx_Total_Current == caliData_pages_can) && (Rx_Current == i))
            {
                break;
            }

            if(startWriteCaliData_flag_can == 0)
            {
                CanTx0(CAN_End_WriteCaliData_TX_ID, 8, CAN_tx);
                ui->Label_TempCali_Msg->setText("发送终止！");
                return ;
            }
        }

    }

    CanTx0(CAN_End_WriteCaliData_TX_ID, 8, CAN_tx);

    ui->Label_TempCali_Msg->setText("发送完成！");

    TempCali_ButtonState(true,true,false);

}

void WriteCali::DisplayState_Send_TempCali_Data() // 展示发送的状态
{

}

void WriteCali::StopSend_TempCali_Data()  // 停止发送
{

    startWriteCaliData_flag_can = 0;
    TempCali_ButtonState(true,true,false);
}

void WriteCali::Display_TempCali_DeviceHasSavedData(int num)  // 根据板子反馈消息，展示已经存在板子里的温度标定数据
{

}

void WriteCali::Display_TempCali_PrePage()    // 上一个温度的信息
{

}

void WriteCali::Display_TempCali_NextPage()   // 下一个温度的信息
{

}



// 所有按钮信号槽
void WriteCali::on_PushButton_TempCali_ReadFile_clicked()
{
    Read_TempCali_File();
}

void WriteCali::on_PushButton_TempCali_SendFile_clicked()
{
    Send_TempCali_Data();
}

void WriteCali::on_PushButton_TempCali_StopSendFile_clicked()
{
    StopSend_TempCali_Data();
}

void WriteCali::on_PushButton_pre_clicked()
{
    Display_TempCali_PrePage();
}

void WriteCali::on_PushButton_next_clicked()
{
    Display_TempCali_NextPage();
}



bool WriteCali::writeCaliData_GetTxFrame_Can(uint32_t *CanID, unsigned char *pData, unsigned short *Len)
{
        unsigned  long  TimeMs = QTime::currentTime().msecsSinceStartOfDay();
        if(DelayMs >0)
        {
            unsigned  long  TimeIncMs= TimeMs - LastMs;
            if(DelayMs>=TimeIncMs)  DelayMs -= TimeIncMs;
            else                    DelayMs  = 0;
        }
        LastMs = TimeMs;
        if(DelayMs >0)  return  false;

        if(startWriteCaliData_flag_can)//写入温度标定数据
        {
                 memcpy(&pData[0],&wirteCaliData_Can[caliData_nPage_can],sizeof(calidata_struct_can));
                 *Len       = 8;
                 int addr = Set::canAddr;
                 *CanID     = (addr<<8)+ 0xF1;

                 DelayMs    = 500;                  // 数据帧与帧之间的时间间隔
                 return true;
        }
        *Len = 0;
        return false;
}



bool WriteCali::writeCaliData_SetRxFrame_Can( unsigned int CanId, unsigned short  Len,unsigned char *pData )
{
    unsigned char Rx[8];
    if(Len != 4 )       {   qDebug()<<"Can Data Len error！\r\n"; return 0;  }
    if(CanId != 0xF2)   {   qDebug()<< "Error Can ID is:"<< CanId <<"  Not 0xF2! \r\n"; return 0; }

    memcpy(&Rx[0],pData,Len );
    uint16_t Rx_Total   = *( (uint16_t *)(&Rx[0]));
    uint16_t Rx_Current = *( (uint16_t *)(&Rx[2]));

      if( ( Rx_Total == caliData_pages_can ) && (Rx_Current == caliData_nPage_can) )
      {
           caliData_nPage_can++;
           if(caliData_nPage_can >= caliData_pages_can)
           {
               caliData_nPage_can = 0;
               startWriteCaliData_flag_can = 0;
               QString page_total_can  =   QString::number(caliData_pages_can,10);

           }
           DelayMs =   0;
           return true;
      }
      else
      {
        return 0;
      }
}


void WriteCali::Delay(int msec)
{   // 这个最准
    /*非阻塞方式延时,现在很多人推荐的方法*/
    QEventLoop loop;
    QTimer::singleShot(msec, &loop, SLOT(quit()));
    loop.exec();
}

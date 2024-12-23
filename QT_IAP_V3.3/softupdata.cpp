#include "softupdata.h"
#include "ui_softupdata.h"
#include "QTime"
#include    "mainwindow.h"
#include    "ui_mainwindow.h"
#include    <QFile>
#include    <QFileDialog>
#include    <QDataStream>
#include    <QMessageBox>
#include    <QString>
#include    <QFile>
#include    "set.h"
#include    "QProcess"

//#include    "string.h"

softupdata::softupdata(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::softupdata)
{
    bUpdate_flag =0;
    bUpdate_flag_can =0;


    ui->setupUi(this);
}

softupdata::~softupdata()
{
    delete ui;
}

void softupdata::on_Hex_path_clicked()
{
    filePath = QFileDialog::getOpenFileName(this,"打开文件","/","Hex/bin File(*.hex *.bin);;All files(*.*)");
    Update_Preview();
}

void softupdata::saveToBin(QString FileName,char *dat,uint32_t len)
{
    QFile fileSave(FileName);
    fileSave.open(QIODevice::WriteOnly);        // 只写模式打开
    fileSave.write(dat,len);
    fileSave.close();
}

void softupdata::Update_Preview()
{
    QString   fileName;
    QFileInfo fileInfo;


    if(filePath.isNull())
    {
        ui->soft_status->appendPlainText("path is empty!");
        return;
    }

    ui->updata_route_show->setText(filePath);


        if(filePath.indexOf(".hex",0)>0 ) //hex 文件
        {
                QProcess p(0);
                QString Cmd=QString("./hex2bin.exe %1").arg(filePath);
                p.start(Cmd);
                p.waitForStarted();
                p.waitForFinished();
                ui->soft_status->appendPlainText("Out:\n"+ QString::fromLocal8Bit(p.readAllStandardOutput()));

                QString ErrorOut = QString::fromLocal8Bit(p.readAllStandardError());
                if( ErrorOut.isEmpty() == false  )
                    ui->soft_status->appendPlainText("Error:\n"+ErrorOut);
                QString filePathBin = filePath.replace(".hex",".bin");
        }

        fileInfo = QFileInfo(filePath);
        fileName = fileInfo.fileName();
        QFile readFile(filePath);
        QDataStream in(&readFile);
        if(readFile.open(QIODevice::ReadOnly) ==  false)
        {
            ui->soft_status->appendPlainText("file ReadOnly open false !");
            return;
        }

        if(filePath.indexOf(".bin",0)>0 )           // bin 文件
        {
            Set::CodMode = false;                   // 明文传输
            memset(BinBuf,0xff,sizeof(BinBuf));

            LenBin = in.readRawData((char *)BinBuf, sizeof(BinBuf));

            readFile.close();
            if(LenBin >= 1024*1024)
            {
                QMessageBox::warning(this,"提示","Bin 文件超限，最大支持1024KB！");
            }
            else
            {
                QString show_append = QString("bin文件大小: %1 \r\n ").arg(LenBin)  ;
                ui->soft_status->appendPlainText(show_append);
            }
        }

        else if( filePath.indexOf(".cod",0)>0  )  // cod 加密文件
        {
            if(Set::CodMode == true)    // 密文传输
            {
                memset(BinBuf,0xff,sizeof(BinBuf));
                LenBin = in.readRawData((char *)BinBuf, sizeof(BinBuf));
                readFile.close();
                QString show_append = QString("密文传输... cod文件大小: %1 \r\n ").arg(LenBin)  ;
                ui->soft_status->appendPlainText(show_append);
            }
            else            // 明文传输
            {
                readFile.close();
                if( AesUser.FileDecryptorToDate(filePath, &LenBin, BinBuf)==0)
                {
                   QString show_append = QString("cod文件解析出错！ \r\n ")  ;
                   ui->soft_status->appendPlainText(show_append);
                }
                else
                {

                    QString show_append = QString("明文传输... cod文件大小: %1 \r\n ").arg(LenBin)  ;
                    ui->soft_status->appendPlainText(show_append);
                }

            }
        }

}

void softupdata::Load_File(void)
{
    if( Set::canEn == true)
    {
        pages_can   = (LenBin + 3)/4 ;
        if(pages_can > 64*1024)
        {
            QMessageBox::warning(this,"错误","CAN 升级模式文件不能大于256KB");
        }
        else
        {
            for(int page=0;page<pages_can;page++)  //文件数据装入can Update结构
            {
                Update_Can[page].pages = pages_can;
                Update_Can[page].page  = page;
                memcpy(&Update_Can[page].pData[0] , &BinBuf[page*4], 4 );
            }
        }
    }
    else if( (Set::uartEn == true) || (Set::rs485En == true) )
    {
        pages       = (LenBin + 127)/128 ;
        if(pages > 8*1024)
        {
            QMessageBox::warning(this,"错误","串口 升级模式文件不能大于1024KB");
        }
        else
        {
            if(Set::CodMode)
            {
                pages = pages|0x8000;
            }
            else
            {
                pages = pages&0x7FFF;
            }
            for(int page=0;page<(pages & 0xFFFF);page++)  //文件数据装入uart Update结构
            {
                Update[page].pages = pages;
                Update[page].page  = page;
                memcpy(&Update[page].pData[0], &BinBuf[page*128],128);
            }
        }
    }
}

// 路径选择
void softupdata::on_updata_route_select_clicked()
{
    filePath = QFileDialog::getOpenFileName(this,"打开文件","./HexBin","Hex/bin/cod File(*.hex *.bin *.cod);;All files(*.*)");
    Update_Preview();
}

// 升级
void softupdata::on_Update_Run_clicked()
{
    Update_Preview();
    Load_File();

    bUpdate_flag = 1;
    bUpdate_flag_can = 1;

    QString show_append = "开始升级...";
    ui->soft_status->appendPlainText(show_append);
    Run();
}

// 取消升级
void softupdata::on_Cancel_update_clicked()
{
    bUpdate_flag = 0;
    bUpdate_flag_can = 0;

    nPage =0;
    QString show_append = "取消升级...";
    updata_now_state();
    ui->soft_status->appendPlainText(show_append);
}

bool softupdata::SetRxFrame( unsigned char *pData, unsigned short  Len)
{
    unsigned char Rx[128];
    qDebug()<<"Rx Frame!";

    memcpy(&Rx[0],pData,Len );

        if( (Rx[0] != 0xAA) ||  (Rx[1] != 0xAA) || (Rx[2] != 0xAA) )
        {
            QString show_append = "帧头错误！\r\n";
            ui->soft_status->appendPlainText(show_append);
           return 0; //帧头
        }
        if( Rx[3] != 0xFF)
        {
            QString show_append = QString("功能码错误 %1！\r\n").arg(Rx[3]);
            ui->soft_status->appendPlainText(show_append);
            return 0;      //功能码
        }

        if( (Rx[6] != 0x04) ||  (Rx[7] != 0x00) )
        {
            QString show_append = QString("长度错误 %1 \r\n").arg(Rx[6] + (Rx[7]<<8));
            ui->soft_status->appendPlainText(show_append);
            return 0;      //长度
        }

      if(((Rx[8]+(Rx[9]<<8))== pages) && ((Rx[10]+(Rx[11]<<8))==nPage))
      {
           updata_now_state();
           nPage++;
           if(nPage >= (pages & 0x7FFF)  )
           {
               nPage = 0;
               bUpdate_flag = false;
               QString page_total  =   QString::number( (pages&0x7FFF),10);

               QString show_append = "程序升级..完成."+ page_total;
               ui->soft_status->appendPlainText(show_append);
               bUpdateFinished = true;
           }
           DelayMs =   0;
           return true;
      }
      else
      {
          QString show_append = QString("帧序号错误，total: %1 now:%2 \r\n").arg(Rx[8]+(Rx[9]<<8)).arg(Rx[10]+(Rx[11]<<8));
          ui->soft_status->appendPlainText(show_append);
          return 0;
      }
}

bool softupdata::softupdata_GetTxFrame( unsigned char *pData, unsigned short *Len)
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

        int timeOut = Set::AnswerTimeOut;
        if(bUpdate_flag)//升级
        {
                 memcpy(&pData[8],&Update[nPage],sizeof(vcu_Update_Struct));
                 pData[0]=0xAA;
                 pData[1]=0xAA;
                 pData[2]=0xAA;
                 pData[3]=0xFF;

                 pData[4]=0x00;
                 pData[5]=0x00;

                 if( (Set::rs485En) == true )   // Rs485升级
                 {
                     pData[6]=(Set::rs485Addr)>>0;
                     pData[7]=(Set::rs485Addr)>>8;
                 }
                 else               // 串口升级
                 {
                    pData[6]=132;
                    pData[7]=0;
                 }

                 uint16_t crcResult = crc_16(&pData[6],134);
                 pData[4] = uint8_t(crcResult);
                 pData[5] = uint8_t(crcResult>>8);

                 *Len        = sizeof(vcu_Update_Struct)+8;
                 DelayMs =   timeOut;                  // 数据帧与帧之间的时间间隔

                 QString show_append = QString("Send one frame!");
                 ui->soft_status->appendPlainText(show_append);

                 return true;
        }
        *Len = 0;
        return false;
}


uint16_t softupdata::crc_16(uint8_t *data, uint16_t len)
{
    uint16_t crc16 = 0x0000;

    while( len-- ) {
        for(uint8_t i=0x80; i!=0; i>>=1) {
            if((crc16 & 0x8000) != 0) {
                crc16 = crc16 << 1;
                crc16 = crc16 ^ 0x1021;
            }
            else {
                crc16 = crc16 << 1;
            }
            if((*data & i) != 0) {
                crc16 = crc16 ^ 0x1021;  //crc16 = crc16 ^ (0x10000 ^ 0x11021)
            }
        }
        data++;
    }

    return crc16;
}



void softupdata::updata_now_state(void)
{
    QString page_curent =   QString::number(nPage,10);
    QString page_total  =   QString::number( (pages & 0x7FFF),10);

    QString show_append = "updata... " + page_curent+"/"+ page_total ;
    ui->soft_status->appendPlainText(show_append);

    if(pages ==0)
    {
        QMessageBox::warning(this,"错误","总帧数为0！");
    }
    else
        ui->updata_percent->setValue( (nPage+1)*100/(pages&0x7FFF) );
}

void softupdata::updata_now_state_can(void)
{
    QString page_curent =  QString::number(nPage_can,10);
    QString page_total  =   QString::number(pages_can,10);

    QString show_append = "updata... " + page_curent+"/"+ page_total ;
    ui->soft_status->appendPlainText(show_append);

    ui->updata_percent->setValue( (nPage_can+1)*100/pages_can);
}



void softupdata::   addInformationShow(QString dat)
{
    ui->soft_status->appendPlainText(dat);
}

// 大循环
void softupdata:: Run()
{
    unsigned long   CanIdx;

    QCoreApplication::processEvents();   //更新界面显示
    static QByteArray SendStr;
    if( true == Set::canEn )        // 如果当前是CAN模式
    {

        uint32_t Id;
        unsigned char TxData[8];
        unsigned short TxLen;


        uint8_t         CanLen;
        uint8_t         CanDate[8];

        if( Set::canChannel >1)  Set::canChannel =1;

        if(Set::canDevice==0)
        {

            CanTx[0]        = CanTx0;
            CanRx[0]        = CanRx0;
            CanTx[1]        = CanTx1;
            CanRx[1]        = CanRx1;

            while(true)
            {
                if(softupdata_GetTxFrame_Can(&Id,&TxData[0],&TxLen) )
                {

                    CanTx[Set::canChannel](Id,TxLen, &TxData[0]);

                }
                if( true == CanRx[Set::canChannel](&CanIdx,&CanLen,&CanDate[0])  )
                {

                    SetRxFrame_Can(CanIdx , CanLen, &CanDate[0]); //

                }
                if(bUpdateFinished_can) break;
            }

        }
    }

}


// CAN updata
bool softupdata::softupdata_GetTxFrame_Can(uint32_t *CanID, unsigned char *pData, unsigned short *Len)
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

        if(bUpdate_flag_can)//VCU升级
        {
                 memcpy(&pData[0],&Update_Can[nPage_can],sizeof(update_struct_can));
                 *Len       = 8;
                 int addr = Set::canAddr;
                 *CanID     = (addr<<8)+ 0xF1;

                 DelayMs    = 500;                  // 数据帧与帧之间的时间间隔
//                 QString show_append = QString("总数据帧:%1,当前数据帧:%2 \r\n").arg(Update_Can[nPage_can].pages &0xFFFF).arg( Update_Can[nPage_can].page);
//                 ui->soft_status->appendPlainText(show_append);
                 return true;
        }
        *Len = 0;
        return false;
}


bool softupdata::SetRxFrame_Can( unsigned int CanId, unsigned short  Len,unsigned char *pData )
{
    unsigned char Rx[8];
    if(Len != 4 )       {   qDebug()<<"Can Data Len error！\r\n"; return 0;  }
    if(CanId != 0xF2)   {   qDebug()<< "Error Can ID is:"<< CanId <<"  Not 0xF2! \r\n"; return 0; }

    memcpy(&Rx[0],pData,Len );
    uint16_t Rx_Total   = *( (uint16_t *)(&Rx[0]));
    uint16_t Rx_Current = *( (uint16_t *)(&Rx[2]));

      if( ( Rx_Total == pages_can ) && (Rx_Current == nPage_can) )
      {
           updata_now_state_can();
           nPage_can++;
           if(nPage_can >= pages_can)
           {
               nPage_can = 0;
               bUpdate_flag_can = false;
               QString page_total_can  =   QString::number(pages_can,10);

               QString show_append = "程序升级..完成."+ page_total_can;
               ui->soft_status->appendPlainText(show_append);
               bUpdateFinished_can = true;
           }
           DelayMs =   0;
           return true;
      }
      else
      {
          QString show_append = QString("Can帧序号错误，total_request: %1 total_rx:%2  cnt_request: %3  cnt_rx:%4")
                  .arg(pages_can).arg( Rx_Total).arg(nPage_can).arg( Rx_Current);

          qDebug()<<"Rx_Total:"<<Rx_Total;
          qDebug()<<"Rx_Current:"<<Rx_Current;
          qDebug()<<"pages_can:"<<pages_can;
          qDebug()<<"Rx_Current:"<<nPage_can;

          ui->soft_status->appendPlainText(show_append);

          return 0;
      }
}




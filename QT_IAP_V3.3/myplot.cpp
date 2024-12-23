#include "myplot.h"
#include "ui_myplot.h"
#include <cmath>
#include <QTime>
#include <QMessageBox>

MyPlot::MyPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyPlot)
{
    // saveClass =new save(this->saveClass);
    saveClass =new save();
    CurName[0] = "XX0";
    CurName[0] = "XX1";
    CurNum =2;

    MinYLeft = -300;
    MaxYLeft =  300;


    ui->setupUi(this);

    ShowFlag = 1;
    ui->ShowFlag->setChecked(ShowFlag);

    SaveFlag =0;  //
    ui->SaveFlag->setChecked(SaveFlag);

    QFile NumberFile("./saveNumber.txt");  // 获取保存序号
    if( NumberFile.open(QIODevice::ReadOnly) )
    {
        bool ret ;
        QByteArray ReadDat =  NumberFile.readAll();
        saveNumber =  ReadDat.toInt(&ret, 10);

        ui->saveNumber->setValue(saveNumber);
        qDebug()<<"序号文件打开成功！number is:"<<saveNumber;
    }
    else
    {
        saveNumber =  1;
        ui->saveNumber->setValue(saveNumber);
        qDebug()<<"序号文件打开失败！\r\n";
    }
    NumberFile.close();         // 关闭文件
}

MyPlot::~MyPlot()
{
    delete ui;
}

// DataChannel
void MyPlot::RePlot(bool bInit,int DataChannel)
{
    static  bool  repeat = false;
    int     i,n;

    if(repeat)  return;
    repeat = true;

    if(bInit)
    {
        ui->PointsValue->setText(QString("%1").arg(Points));

        ui->PositionValue->setValue(MinX);
        ui->WidthValue->setValue(MaxX);
        ui->LeftYMinValue->setValue(MinYLeft);
        ui->LeftYMaxValue->setValue(MaxYLeft);

//        for(i=0;i<CurNum;i++)
//        {
//            QPen pen;
//            pen.setColor(QColor(qSin(i*2+1.2)*80+80, qSin(i*0.6+0)*80+80, qSin(i*0.6+1.5)*80+80));
//            ui->plotLegend->addGraph();
//            ui->plotLegend->graph()->setPen(pen);
//            ui->plotLegend->graph()->setName(CurName[i]);
//        }
//        ui->plotLegend->replot();

        // 清除曲线
        int count = ui->plotData->graphCount();
        for(i=0;i<count;i++)
        {
            ui->plotData->removeGraph(ui->plotData->graph());
        }

        // 添加数据
        QVector <double>  x(Points);
        QVector <double>  y(Points);


        for(n=0;n<Points;n++)   x[n] = n;
        for(i=0;i<CurNum;i++)
        {
            QPen pen;
            pen.setColor(QColor(qSin(i*2+1.2)*80+80, qSin(i*0.6+0)*80+80, qSin(i*0.6+1.5)*80+80));
            pGraph[i] = ui->plotData->addGraph(ui->plotData->xAxis,ui->plotData->yAxis);
            pGraph[i]->setLineStyle((QCPGraph::LineStyle)4);
            pGraph[i]->setPen(pen);
            if(DataChannel ==1)
            {
                for(n=0;n<Points;n++)
                    y[n] = showDates[i][n];
            }
            else
            {
                for(n=0;n<Points;n++)
                    y[n] = CurDates[i][n];
            }

            pGraph[i]->setData(x, y);
        }
    }
    pGraph[0]->setVisible(ui->radioButton_1->isChecked());
    pGraph[1]->setVisible(ui->radioButton_2->isChecked());

    ui->plotData->xAxis->setRange(MinX,MaxX);
    ui->plotData->yAxis->setRange(MinYLeft,MaxYLeft);
    ui->plotData->replot();

    repeat = false;
}

void MyPlot::  WriteDataInBuf(unsigned char *dat,uint32_t len)
{
    if(len != 8)        return;
    if(SaveFlag == 1)       // 保存标志
    {
        CurDates[0][SaveCnt] = (dat[2]<<8) + dat[3];            // 通道1数据
        CurDates[1][SaveCnt] = (dat[4]<<8) + dat[5];            // 通道2数据
        QDateTime TimeNow =  QDateTime::currentDateTime();      // 时间
        TimeDate[SaveCnt] = TimeNow.toTime_t();
        SaveCnt++;
        if( SaveCnt >= MaxPoints) SaveCnt= MaxPoints-1;
    }
    if(ShowFlag == 1)       // 显示标志
    {
        if( ShowCnt >= MaxShowPoints )
        {
            ShowCnt = MaxShowPoints  ;
            for(int i=0;i<MaxShowPoints-1;i++)                      // 数据移动
            {
                showDates[0][i] =  showDates[0][i+1];
                showDates[1][i] =  showDates[1][i+1];
            }
            showDates[0][MaxShowPoints-1] = (dat[2]<<8) + dat[3];    // 通道1数据
            showDates[1][MaxShowPoints-1] = (dat[4]<<8) + dat[5];    // 通道2数据
        }
        else
        {
            showDates[0][ShowCnt] = (dat[2]<<8) + dat[3];    // 通道1数据
            showDates[1][ShowCnt] = (dat[4]<<8) + dat[5];    // 通道2数据
            ShowCnt++;
        }
        Points = ShowCnt-1;    // 点数
        CurNum = 2;            // 曲线条数2
        {
            // Plot
            MinX = 0;
            MaxX = Points;
            RePlot(true,ShowFlag);
         }
    }
}



//void MyPlot::on_pushButton_8_clicked(bool checked)
//{
////    test();
//////    static int ShowCnt =0;
//////    if(len != 8)    return;
//////    else
//    for(int i=0;i<100;i++)
//    {
//        CurDates[0][i] = i;
//        CurDates[1][i] = i;
//    }
//    Points = 100;
//    CurNum = 2;
////   if( LoadDataFlag & LoadData_END )
//    {
////        BeginItem = 0;
//        // Plot
//        MinX = 0;
//        MaxX = Points;

//        MinYLeft = -150;
//        MaxYLeft = 150;

//        RePlot(true);
//     }
//}

void MyPlot::on_PositionValue_valueChanged(int arg1)
{
    MinX = ui->PositionValue->value();
    RePlot(1,ShowFlag);
}

void MyPlot::on_WidthValue_valueChanged(int arg1)
{
    MaxX = ui->WidthValue->value();
    RePlot(1,ShowFlag);
}

void MyPlot::on_LeftYMinValue_valueChanged(int arg1)
{
    MinYLeft = arg1;
    RePlot(1,ShowFlag);

}

void MyPlot::on_LeftYMaxValue_valueChanged(int arg1)
{
    MaxYLeft = arg1;
    RePlot(1,ShowFlag);
}



// 保存数据
void MyPlot::on_ShowSave_clicked()
{
    SaveFlag =0;
    ShowFlag =0;
    ui->SaveFlag->setChecked(SaveFlag);
    ui->ShowFlag->setChecked(ShowFlag);

    if(SaveCnt ==0)
    {
       QMessageBox::information(this, "提示", "没有需要保存的数据！");
       return;
    }
    QString name = "./";
    QString timeNow = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");
    QString strBuffer = QString::number( ui->saveNumber->value(),10) + "_" + timeNow + ".Dat";
    name += strBuffer;

    QFile   writeFile(name);

    if(writeFile.open(QIODevice::WriteOnly))
    {
        QDataStream out(&writeFile);
        out.writeRawData((char *)(&SaveCnt), sizeof(int));   // 先记录总点数
        out.writeRawData((char *)(&CurDates[0][0]), SaveCnt*4);
        out.writeRawData((char *)(&CurDates[1][0]), SaveCnt*4);

        writeFile.close();
        QMessageBox::information(this, "提示", "数据保存成功！");

        QFile NumberFile("./saveNumber.txt");  // 获取保存序号
        if( NumberFile.open(QIODevice::WriteOnly) )
        {
            QByteArray writeDat;
            writeDat    =   QString ::number(saveNumber,10).toUtf8();
            if( NumberFile.write(writeDat) )
            {
                ui->saveNumber->setValue(saveNumber);
                qDebug()<<"序号文件写入成功！number is:"<<saveNumber;
            }
            else
            {
                qDebug()<<"序号文件写入失败！\r\n";
            }
            dataToDataBase(SaveCnt);

            saveNumber++;
            ui->saveNumber->setValue(saveNumber);

        }
        else
        {
            saveNumber =  1;
            ui->saveNumber->setValue(saveNumber);
            qDebug()<<"序号文件打开失败！\r\n";
        }
        NumberFile.close();         // 关闭文件
    }
    else QMessageBox::information(this, "提示", "数据保存失败！");
}

#include <header.h>
//Cnt 表示数据总点数
void MyPlot::dataToDataBase(int Cnt)
{
    record dat;
    for(int i=0;i<Cnt;i++)
    {
        dat.time = QDateTime::fromTime_t(TimeDate[i]);
        dat.rxNumber = i;
        dat.ID   = saveNumber;
        dat.Dat1 = CurDates[0][i];
        dat.Dat2 = CurDates[1][i];
        saveClass->insert_Data(&dat);
    }
}
// 显示历史曲线
void MyPlot::on_ShowLast_clicked()
{
    SaveFlag =0;
    ShowFlag =0;
    ui->SaveFlag->setChecked(SaveFlag);
    ui->ShowFlag->setChecked(ShowFlag);

    QString path = QFileDialog::getOpenFileName(this, tr("装入"), "./", tr("Config Files(*.Dat)"));
    QFile   readFile(path);

    if(readFile.open(QIODevice::ReadOnly))
    {
            QDataStream in(&readFile);
            in.readRawData((char *)(&Points), sizeof(int));
            in.readRawData((char *)(&CurDates[0][0]), Points*4);
            in.readRawData((char *)(&CurDates[1][0]), Points*4);
            readFile.close();
            RePlot(1,ShowFlag);

            QMessageBox::information(this, "提示", "数据载入成功！");
    }
    else    QMessageBox::information(this, "提示", "数据载入失败！");
}

//
void MyPlot::on_ShowAll_clicked()
{
    MinX = 0;
    MaxX = Points;    
    RePlot(1,ShowFlag);
}
// 右移
void MyPlot::on_MoveRight_clicked()
{
    int pointNum = Points;
    int Scale    = ui->Scale->value();

    MinX = MinX - pointNum/Scale;
    MaxX = MaxX - pointNum/Scale;
    RePlot(1,ShowFlag);
}

// 左移
void MyPlot::on_MoveLeft_clicked()
{
    int pointNum = Points;
    int Scale    = ui->Scale->value();

    MinX = MinX + pointNum/Scale;
    MaxX = MaxX + pointNum/Scale;
    RePlot(1,ShowFlag);
}

// 缩小
void MyPlot::on_ShowSmall_clicked()
{
    int pointNum = Points;
    int Scale    = ui->Scale->value();

    MinX = MinX - pointNum/Scale/2;
    MaxX = MaxX + pointNum/Scale/2;
    RePlot(1,ShowFlag);
}

// 放大
void MyPlot::on_ShowBig_clicked()
{
    int pointNum = Points;
    int Scale    = ui->Scale->value();

    if( (MaxX - MinX) > pointNum/Scale)
    {
        MinX = MinX + pointNum/Scale/2;
        MaxX = MaxX - pointNum/Scale/2;
    }
    RePlot(1,ShowFlag);
}

void MyPlot::on_radioButton_1_clicked(bool checked)
{
    RePlot(1,ShowFlag);
}

void MyPlot::on_radioButton_2_clicked(bool checked)
{
    RePlot(1,ShowFlag);
}

// 显示开
void MyPlot::on_ShowFlag_clicked(bool checked)
{
    ShowFlag = checked;
}
// 记录开
void MyPlot::on_SaveFlag_clicked(bool checked)
{
    SaveFlag = checked;

}

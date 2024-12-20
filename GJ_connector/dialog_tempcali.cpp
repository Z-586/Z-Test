#include "dialog_tempcali.h"
#include "ui_dialog_tempcali.h"

Dialog_TempCali::Dialog_TempCali(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_TempCali)
{
    ui->setupUi(this);
    Dialog_TempCali_Init();
}

Dialog_TempCali::~Dialog_TempCali()
{
        delete ui;
}

void Dialog_TempCali::Dialog_TempCali_Init()    // 初始化函数
{
    this->setWindowTitle("发送温度标定数据");

    QWidget::setAttribute(Qt::WA_QuitOnClose,false);     // 所有子窗口要写false
    QWidget::setAttribute(Qt::WA_DeleteOnClose);     // 所有子窗口要写false
    setWindowFlags((windowFlags()&~Qt::WindowContextHelpButtonHint) | Qt::WindowMinimizeButtonHint);

    TempCali_ButtonState(1, 0, 0);
    TempCali_VariablesInit();
}

void Dialog_TempCali::TempCali_VariablesInit()  // 温度标定的变量初始化函数
{
    TempCali_ShouldSendData_number = 0;
    TempCali_File_ErrorData_number = 0;
    TempCali_File_RightData_number = 0;
    TempCali_File_OverflowData_number = 0;
}

void Dialog_TempCali::TempCali_ButtonState(bool Read, bool Send, bool Stop) // 所有按钮使能控制
{
    ui->PushButton_TempCali_ReadFile->setEnabled(Read);
    ui->PushButton_TempCali_SendFile->setEnabled(Send);
    ui->PushButton_TempCali_StopSendFile->setEnabled(Stop);
    ui->PushButton_pre->setEnabled(false);
    ui->PushButton_next->setEnabled(false);
}

void Dialog_TempCali::Read_TempCali_File()  // 读稳定标定数据
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

void Dialog_TempCali::FindTrueData_TempCali_File(QString FileContent_String)    // 寻找正确数据
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
    Display_Msg_TempCali_File();    // 显示结果
}

void Dialog_TempCali::ProcessTrueData_TempCali_File(QStringList FileContent_StringList)     // 开始处理正确数据
{
    TempCaliData[TempCali_File_RightData_number].TempCali_Msg.Temp = (int16_t)qRound(FileContent_StringList[0].toDouble() / POLL_RATIO_169);

    for (int i = 0;i < 3;i++) {
        TempCaliData[TempCali_File_RightData_number].TempCali_Msg.AccBias[i] = (int16_t)qRound(FileContent_StringList[1+i].toDouble() / POLL_RATIO_175);
        TempCaliData[TempCali_File_RightData_number].TempCali_Msg.GyroBias[i] = (int16_t)qRound(FileContent_StringList[4+i].toDouble() / POLL_RATIO_178);
    }
    for (int i = 0;i < 9;i++) {
        TempCaliData[TempCali_File_RightData_number].TempCali_Msg.Matrix_Ka[i] = FileContent_StringList[7+i].toDouble();
        TempCaliData[TempCali_File_RightData_number].TempCali_Msg.Matrix_Kg[i] = FileContent_StringList[16+i].toDouble();
        TempCaliData[TempCali_File_RightData_number].TempCali_Msg.Matrix_G[i]  = FileContent_StringList[25+i].toDouble();
    }
}

void Dialog_TempCali::Display_Msg_TempCali_File()   // 显示结果
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

void Dialog_TempCali::Send_TempCali_Data()  // 发送温度标定数据
{
    if(TempCali_ShouldSendData_number == TempCali_File_RightData_number)
    {
        TempCali_ShouldSendData_number++;
        ui->Label_TempCali_Msg->setText("温度数据已经发送完成！");
        StopSend_TempCali_Data();
        return;
    }
    TempCali_ButtonState(0, 0, 1);

    emit Serial_Write(base_function::Serial_DataFormat(send_TempCali_SendData, TempCaliData[TempCali_ShouldSendData_number].bytes, 122));
    TempCali_ShouldSendData_number++;
    DisplayState_Send_TempCali_Data();
}

void Dialog_TempCali::DisplayState_Send_TempCali_Data() // 展示发送的状态
{
    QString msg = "";
    msg += "一共有"+QString::number(TempCali_File_RightData_number)+"组数据需要发送。\n";
    msg += "目前正在发送第"+QString::number(TempCali_ShouldSendData_number)+"组数据。\n";
    ui->Label_TempCali_Msg->setText(msg);
}

void Dialog_TempCali::StopSend_TempCali_Data()  // 停止发送
{
    if(TempCali_ShouldSendData_number != TempCali_File_RightData_number)
    {
        TempCali_ButtonState(1, 0, 0);
        ui->Label_TempCali_Msg->setText("温度数据已经停止发送！");
    }
    emit Serial_Write(base_function::Serial_DataFormat(send_TempCali_StopSendData));

}

void Dialog_TempCali::Display_TempCali_DeviceHasSavedData(int num)  // 根据板子反馈消息，展示已经存在板子里的温度标定数据
{
    num--;
    float Temp, AccBias[3], GyroBias[3], Matrix_Ka[9], Matrix_Kg[9], Matrix_G[9];
    Temp = TempCaliData[num].TempCali_Msg.Temp *  POLL_RATIO_169;
    for (int i = 0;i < 3;i++) {
        AccBias[i] =  TempCaliData[num].TempCali_Msg.AccBias[i]  * POLL_RATIO_175;
        GyroBias[i] = TempCaliData[num].TempCali_Msg.GyroBias[i] * POLL_RATIO_178;
    }
    for (int i = 0;i < 9;i++) {
        Matrix_Ka[i] = TempCaliData[num].TempCali_Msg.Matrix_Ka[i];
        Matrix_Kg[i] = TempCaliData[num].TempCali_Msg.Matrix_Kg[i];
        Matrix_G[i]  = TempCaliData[num].TempCali_Msg.Matrix_G[i] ;
    }

    ui->LineEdit_T->   setText(QString::number(Temp          , 'f', 7));

    ui->LineEdit_Bax-> setText(QString::number(AccBias[0]    , 'f', 7));
    ui->LineEdit_Bay-> setText(QString::number(AccBias[1]    , 'f', 7));
    ui->LineEdit_Baz-> setText(QString::number(AccBias[2]    , 'f', 7));

    ui->LineEdit_Bgx-> setText(QString::number(GyroBias[0]   , 'f', 7));
    ui->LineEdit_Bgy-> setText(QString::number(GyroBias[1]   , 'f', 7));
    ui->LineEdit_Bgz-> setText(QString::number(GyroBias[2]   , 'f', 7));

    ui->LineEdit_Ka1-> setText(QString::number(Matrix_Ka[0]  , 'f', 7));
    ui->LineEdit_Ka2-> setText(QString::number(Matrix_Ka[1]  , 'f', 7));
    ui->LineEdit_Ka3-> setText(QString::number(Matrix_Ka[2]  , 'f', 7));
    ui->LineEdit_Ka4-> setText(QString::number(Matrix_Ka[3]  , 'f', 7));
    ui->LineEdit_Ka5-> setText(QString::number(Matrix_Ka[4]  , 'f', 7));
    ui->LineEdit_Ka6-> setText(QString::number(Matrix_Ka[5]  , 'f', 7));
    ui->LineEdit_Ka7-> setText(QString::number(Matrix_Ka[6]  , 'f', 7));
    ui->LineEdit_Ka8-> setText(QString::number(Matrix_Ka[7]  , 'f', 7));
    ui->LineEdit_Ka9-> setText(QString::number(Matrix_Ka[8]  , 'f', 7));

    ui->LineEdit_Kg1-> setText(QString::number(Matrix_Kg[0]  , 'f', 7));
    ui->LineEdit_Kg2-> setText(QString::number(Matrix_Kg[1]  , 'f', 7));
    ui->LineEdit_Kg3-> setText(QString::number(Matrix_Kg[2]  , 'f', 7));
    ui->LineEdit_Kg4-> setText(QString::number(Matrix_Kg[3]  , 'f', 7));
    ui->LineEdit_Kg5-> setText(QString::number(Matrix_Kg[4]  , 'f', 7));
    ui->LineEdit_Kg6-> setText(QString::number(Matrix_Kg[5]  , 'f', 7));
    ui->LineEdit_Kg7-> setText(QString::number(Matrix_Kg[6]  , 'f', 7));
    ui->LineEdit_Kg8-> setText(QString::number(Matrix_Kg[7]  , 'f', 7));
    ui->LineEdit_Kg9-> setText(QString::number(Matrix_Kg[8]  , 'f', 7));

    ui->LineEdit_G1->  setText(QString::number(Matrix_G[0]   , 'f', 7));
    ui->LineEdit_G2->  setText(QString::number(Matrix_G[1]   , 'f', 7));
    ui->LineEdit_G3->  setText(QString::number(Matrix_G[2]   , 'f', 7));
    ui->LineEdit_G4->  setText(QString::number(Matrix_G[3]   , 'f', 7));
    ui->LineEdit_G5->  setText(QString::number(Matrix_G[4]   , 'f', 7));
    ui->LineEdit_G6->  setText(QString::number(Matrix_G[5]   , 'f', 7));
    ui->LineEdit_G7->  setText(QString::number(Matrix_G[6]   , 'f', 7));
    ui->LineEdit_G8->  setText(QString::number(Matrix_G[7]   , 'f', 7));
    ui->LineEdit_G9->  setText(QString::number(Matrix_G[8]   , 'f', 7));
}

void Dialog_TempCali::Display_TempCali_PrePage()    // 上一个温度的信息
{
    int prepage = ui->Label_CurPage->text().toInt() - 1;
    Display_TempCali_DeviceHasSavedData(prepage);
    ui->Label_CurPage->setText(QString::number(prepage));

    ui->PushButton_next->setEnabled(true);
    if(prepage == 1)
    {
        ui->PushButton_pre->setEnabled(false);
    }
    else
    {
        ui->PushButton_pre->setEnabled(true);
    }
}

void Dialog_TempCali::Display_TempCali_NextPage()   // 下一个温度的信息
{
    int nextpage = ui->Label_CurPage->text().toInt() + 1;
    Display_TempCali_DeviceHasSavedData(nextpage);
    ui->Label_CurPage->setText(QString::number(nextpage));

    ui->PushButton_pre->setEnabled(true);
    if(nextpage == TempCali_File_RightData_number)
    {
        ui->PushButton_next->setEnabled(false);
    }
    else
    {
        ui->PushButton_next->setEnabled(true);
    }
}

// 上位机收到底层发送的消息码
void Dialog_TempCali::receive_TempCali_RequestData_head()
{
//    qDebug()<<"Request";
    Send_TempCali_Data();
}

void Dialog_TempCali::receive_TempCali_RepeatData_head()
{
//    qDebug()<<"Repeat";
    TempCali_ShouldSendData_number--;
    Send_TempCali_Data();
}

void Dialog_TempCali::receive_TempCali_CompleteData_head()
{
//    qDebug()<<"Complete";
    TempCali_ButtonState(0, 0, 0);
    ui->Label_TempCali_Msg->setText("数据发送完成，设备正在自检数据！");
}

void Dialog_TempCali::receive_TempCali_DeviceHasSavedData_head(QByteArray data)
{

    if(ui->Label_TempCali_Msg->text() == "温度数据已经停止发送！")
    {
        return;
    }
    int num = (uint8_t)data.at(8);
    for (int i = 9; i < receive_TempCali_DeviceHasSavedData_length; i++)
    {
        if((uint8_t)data.at(i) != TempCaliData[num - 1].bytes[i - 9])
        {
            if(ui->Label_TempCali_Msg->text().right(10) != "没有正确输入设备中！")
            {
                ui->Label_TempCali_Msg->setText("第"+QString::number(num - 1)+"数据没有正确输入设备中！");
            }
            TempCali_ButtonState(1, 0, 0);
            return;
        }
    }
    if(num == TempCali_File_RightData_number)
    {
        ui->Label_TempCali_Msg->setText("数据已经全部正确输入设备中！");
        Display_TempCali_DeviceHasSavedData(1);
        TempCali_ButtonState(1, 0, 0);
        if(TempCali_File_RightData_number != 1)
        {
            ui->PushButton_next->setEnabled(true);
        }     
    }
}

// 所有按钮信号槽
void Dialog_TempCali::on_PushButton_TempCali_ReadFile_clicked()
{
    Read_TempCali_File();
}

void Dialog_TempCali::on_PushButton_TempCali_SendFile_clicked()
{
    Send_TempCali_Data();
}

void Dialog_TempCali::on_PushButton_TempCali_StopSendFile_clicked()
{
    StopSend_TempCali_Data();
}

void Dialog_TempCali::on_PushButton_pre_clicked()
{
    Display_TempCali_PrePage();
}

void Dialog_TempCali::on_PushButton_next_clicked()
{
    Display_TempCali_NextPage();
}

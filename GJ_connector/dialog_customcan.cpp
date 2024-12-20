#include "dialog_customcan.h"
#include "ui_dialog_customcan.h"

QCheckBox *checkbox_En[6];
QComboBox *combobox_ID[6];
QLineEdit *lineedit_ID[6];
QComboBox *combobox_SignalName[6];
QLineEdit *lineedit_Start[6];
QLineEdit *lineedit_Length[6];
QComboBox *combobox_UorI[6];
QLineEdit *lineedit_Unit[6];
QLineEdit *lineedit_Factor[6];
QLineEdit *lineedit_Offset[6];
QCheckBox *checkbox_GearEn[4];
QLineEdit *lineedit_GearValue[4];
QLabel *label[6];


Dialog_CustomCan::Dialog_CustomCan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_CustomCan)
{
    ui->setupUi(this);
    Dialog_CustomCanInit();
}

Dialog_CustomCan::~Dialog_CustomCan()
{
    delete ui;
}



void Dialog_CustomCan::Dialog_CustomCanInit()       // 初始化函数
{
    this->setWindowTitle("自定义CAN");
    QWidget::setAttribute(Qt::WA_QuitOnClose,false);     // 所有子窗口要写false
    QWidget::setAttribute(Qt::WA_DeleteOnClose);     // 所有子窗口要写false
    setWindowFlags((windowFlags()&~Qt::WindowContextHelpButtonHint) | Qt::WindowMinimizeButtonHint);

    connect(timeOut_Timer, &QTimer::timeout, this, &Dialog_CustomCan::TimeOut);//关联计时器

    // 初始化指针数组，方便后续循环调用

    {
        checkbox_En[0] = ui->CheckBox_VehicleSpd_En;
        checkbox_En[1] = ui->CheckBox_FLWheelSpd_En;
        checkbox_En[2] = ui->CheckBox_FRWheelSpd_En;
        checkbox_En[3] = ui->CheckBox_RLWheelSpd_En;
        checkbox_En[4] = ui->CheckBox_RRWheelSpd_En;
        checkbox_En[5] = ui->CheckBox_Gear_En;
    }

    {
        combobox_ID[0] = ui->ComboBox_VehicleSpd_ID;
        combobox_ID[1] = ui->ComboBox_FLWheelSpd_ID;
        combobox_ID[2] = ui->ComboBox_FRWheelSpd_ID;
        combobox_ID[3] = ui->ComboBox_RLWheelSpd_ID;
        combobox_ID[4] = ui->ComboBox_RRWheelSpd_ID;
        combobox_ID[5] = ui->ComboBox_Gear_ID;
    }

    {
        lineedit_ID[0] = ui->LineEdit_VehicleSpd_ID;
        lineedit_ID[1] = ui->LineEdit_FLWheelSpd_ID;
        lineedit_ID[2] = ui->LineEdit_FRWheelSpd_ID;
        lineedit_ID[3] = ui->LineEdit_RLWheelSpd_ID;
        lineedit_ID[4] = ui->LineEdit_RRWheelSpd_ID;
        lineedit_ID[5] = ui->LineEdit_Gear_ID;
    }

    {
        combobox_SignalName[0] = ui->ComboBox_VehicleSpd_SignalName;
        combobox_SignalName[1] = ui->ComboBox_FLWheelSpd_SignalName;
        combobox_SignalName[2] = ui->ComboBox_FRWheelSpd_SignalName;
        combobox_SignalName[3] = ui->ComboBox_RLWheelSpd_SignalName;
        combobox_SignalName[4] = ui->ComboBox_RRWheelSpd_SignalName;
        combobox_SignalName[5] = ui->ComboBox_Gear_SignalName;
    }

    {
        label[0] = ui->Label_VehicleSpd;
        label[1] = ui->Label_FLWheelSpd;
        label[2] = ui->Label_FRWheelSpd;
        label[3] = ui->Label_RLWheelSpd;
        label[4] = ui->Label_RRWheelSpd;
        label[5] = ui->Label_Gear;
    }

    {
        lineedit_Start[0] = ui->LineEdit_VehicleSpd_Start;
        lineedit_Start[1] = ui->LineEdit_FLWheelSpd_Start;
        lineedit_Start[2] = ui->LineEdit_FRWheelSpd_Start;
        lineedit_Start[3] = ui->LineEdit_RLWheelSpd_Start;
        lineedit_Start[4] = ui->LineEdit_RRWheelSpd_Start;
        lineedit_Start[5] = ui->LineEdit_Gear_Start;
    }

    {
        lineedit_Length[0] = ui->LineEdit_VehicleSpd_Length;
        lineedit_Length[1] = ui->LineEdit_FLWheelSpd_Length;
        lineedit_Length[2] = ui->LineEdit_FRWheelSpd_Length;
        lineedit_Length[3] = ui->LineEdit_RLWheelSpd_Length;
        lineedit_Length[4] = ui->LineEdit_RRWheelSpd_Length;
        lineedit_Length[5] = ui->LineEdit_Gear_Length;
    }

    {
        combobox_UorI[0] = ui->ComboBox_VehicleSpd_UorI;
        combobox_UorI[1] = ui->ComboBox_FLWheelSpd_UorI;
        combobox_UorI[2] = ui->ComboBox_FRWheelSpd_UorI;
        combobox_UorI[3] = ui->ComboBox_RLWheelSpd_UorI;
        combobox_UorI[4] = ui->ComboBox_RRWheelSpd_UorI;
        combobox_UorI[5] = ui->ComboBox_Gear_UorI;
    }

    {
        lineedit_Unit[0] = ui->LineEdit_VehicleSpd_Unit;
        lineedit_Unit[1] = ui->LineEdit_FLWheelSpd_Unit;
        lineedit_Unit[2] = ui->LineEdit_FRWheelSpd_Unit;
        lineedit_Unit[3] = ui->LineEdit_RLWheelSpd_Unit;
        lineedit_Unit[4] = ui->LineEdit_RRWheelSpd_Unit;
        lineedit_Unit[5] = ui->LineEdit_Gear_Unit;
    }

    {
        lineedit_Factor[0] = ui->LineEdit_VehicleSpd_Factor;
        lineedit_Factor[1] = ui->LineEdit_FLWheelSpd_Factor;
        lineedit_Factor[2] = ui->LineEdit_FRWheelSpd_Factor;
        lineedit_Factor[3] = ui->LineEdit_RLWheelSpd_Factor;
        lineedit_Factor[4] = ui->LineEdit_RRWheelSpd_Factor;
        lineedit_Factor[5] = ui->LineEdit_Gear_Factor;
    }

    {
        lineedit_Offset[0] = ui->LineEdit_VehicleSpd_Offset;
        lineedit_Offset[1] = ui->LineEdit_FLWheelSpd_Offset;
        lineedit_Offset[2] = ui->LineEdit_FRWheelSpd_Offset;
        lineedit_Offset[3] = ui->LineEdit_RLWheelSpd_Offset;
        lineedit_Offset[4] = ui->LineEdit_RRWheelSpd_Offset;
        lineedit_Offset[5] = ui->LineEdit_Gear_Offset;
    }

    {
        checkbox_GearEn[0] = ui->CheckBox_Gear_PEN;
        checkbox_GearEn[1] = ui->CheckBox_Gear_DEN;
        checkbox_GearEn[2] = ui->CheckBox_Gear_REN;
        checkbox_GearEn[3] = ui->CheckBox_Gear_NEN;
    }

    {
        lineedit_GearValue[0] = ui->LineEdit_Gear_P;
        lineedit_GearValue[1] = ui->LineEdit_Gear_D;
        lineedit_GearValue[2] = ui->LineEdit_Gear_R;
        lineedit_GearValue[3] = ui->LineEdit_Gear_N;
    }

    // 初始化界面元器件
    Input_ControlEnable();
    for (int i = 0; i < 6; i++) {
        combobox_ID[i]->setVisible(false);
        label[i]->setVisible(false);
        combobox_SignalName[i]->setVisible(false);
    }
}

void Dialog_CustomCan::EN_ControlEnable(int num)        // 第num消息被使能或者取消使能， 规定0：车速；1：左前轮；2：右前轮；3：左后轮；4：右后轮；5：档位
{
    // 先判断手动输入和DBC输入的状态
    if(ui->CheckBox_ManualInput->isChecked() == true)
    {
        combobox_ID[num]->setVisible(false);
        label[num]->setVisible(false);
        combobox_SignalName[num]->setVisible(false);
        lineedit_ID[num]->setVisible(true);
    }
    else
    {
        combobox_ID[num]->setVisible(true);
        label[num]->setVisible(true);
        combobox_SignalName[num]->setVisible(true);
        lineedit_ID[num]->setVisible(false);
        Add_DBCFile_SignalData(num, combobox_SignalName[num]->currentIndex()-1);
    }

    // 如果是使能的档位的话，需要特殊做一些处理
    if(num == 5)
    {
        for (int i = 0; i<4; i++) {
            checkbox_GearEn[i]->setChecked(false);
            checkbox_GearEn[i]->setEnabled(true);
            lineedit_GearValue[i]->setEnabled(false);
        }

    }

    if(checkbox_En[num]->isChecked() == false)  // 当前该can是不使能
    {
        combobox_ID         [num]->setEnabled(false);
        lineedit_ID         [num]->setEnabled(false);
        combobox_SignalName [num]->setEnabled(false);
        lineedit_Start      [num]->setEnabled(false);
        lineedit_Length     [num]->setEnabled(false);
        combobox_UorI       [num]->setEnabled(false);
        lineedit_Unit       [num]->setEnabled(false);
        lineedit_Factor     [num]->setEnabled(false);
        lineedit_Offset     [num]->setEnabled(false);

        // 档位特殊处理
        if(num == 5)
        {
            for (int i = 0; i<4; i++) {
                checkbox_GearEn[i]->setChecked(false);
                checkbox_GearEn[i]->setEnabled(false);
                lineedit_GearValue[i]->setEnabled(false);
            }
        }
    }
    else if(ui->CheckBox_ManualInput->isChecked() == true)  // 当前该can是使能，根据手动输入和DBC输入的状态，来确定如何更改按钮状态
    {
        combobox_ID         [num]->setEnabled(false);
        lineedit_ID         [num]->setEnabled(true);
        combobox_SignalName [num]->setEnabled(false);
        lineedit_Start      [num]->setEnabled(true);
        lineedit_Length     [num]->setEnabled(true);
        combobox_UorI       [num]->setEnabled(true);
        lineedit_Unit       [num]->setEnabled(true);
        lineedit_Factor     [num]->setEnabled(true);
        lineedit_Offset     [num]->setEnabled(true);
    }
    else
    {
        combobox_ID         [num]->setEnabled(true);
        lineedit_ID         [num]->setEnabled(false);
        combobox_SignalName [num]->setEnabled(true);
        lineedit_Start      [num]->setEnabled(false);
        lineedit_Length     [num]->setEnabled(false);
        combobox_UorI       [num]->setEnabled(false);
        lineedit_Unit       [num]->setEnabled(false);
        lineedit_Factor     [num]->setEnabled(false);
        lineedit_Offset     [num]->setEnabled(false);
    }
}

void Dialog_CustomCan::GearEN_ControlEnable(int num)    // 档位里4个不同档位的使能
{
    lineedit_GearValue[num]->setEnabled(checkbox_GearEn[num]->isChecked());
}

void Dialog_CustomCan::Input_ControlEnable()    // 根据输入方式，初始化各种按钮应有的状态
{
    if(ui->CheckBox_ManualInput->isChecked() == true)
    {
        ui->PushButton_ReadDBC->setEnabled(false);
        ui->ComboBox_DataFormat->setEnabled(true);
    }
    else
    {
        ui->PushButton_ReadDBC->setEnabled(true);
        ui->ComboBox_DataFormat->setEnabled(false);
    }
    for (int i = 0; i<6; i++) {
        EN_ControlEnable(i);
    }
}

void Dialog_CustomCan::Read_DBCFile()   // 读DBC的TXT文件
{
    QSettings setting("./Setting.ini", QSettings::IniFormat);          //为了能记住上次打开的路径
    QString lastPath = setting.value("LastFilePath").toString();

    QString FileName_Path = QFileDialog::getOpenFileName(this,
                                                tr("选择文件"),
                                                lastPath,
                                                tr("*dbc"));
    if(FileName_Path.isEmpty()) // 没选择文件
    {
        return;
    }

    QFile file(FileName_Path);
    if (!file.open(QIODevice::ReadOnly|QIODevice::Text))    // 打开失败
    {
        qDebug() << "open file error";
        return;
    }
    else
    {
        Message_num = 0;
        while(!file.atEnd())    // 读取整个txt文件
        {
            QString line = QString(file.readLine());
            if(line.mid(0, 4) == "BO_ ")    // 帧ID的信息提示字头
            {
                QStringList line_list = line.split(QRegExp(" |:"));
                Message_num++;
                Mseeage_IDName[Message_num-1] = QString::number(line_list[1].toUInt(), 16).toUpper();   // 获取所有帧ID，并记录数量
            }
            else if(line.mid(0, 5) == " SG_ ")  // 每个帧的信号信息提示字头
            {
                Signal[Message_num-1][Signal_num[Message_num-1]] = line;    // 将整个信号信息存到一个二维数组里
                Signal_num[Message_num-1]++;
                ui->ComboBox_DataFormat->setCurrentIndex(line.mid(line.indexOf('@')+1, 1).toUInt());    // 获取整个dbc的消息格式，inter还是motorola
            }
        }
        file.close();

        // 将字头信息添加到元器件中
        Add_DBCFile_Message();
    }
}

void Dialog_CustomCan::Add_DBCFile_Message()    // 将字头信息添加到元器件中
{
    for (int i = 0; i < 6; i++) {
        combobox_ID[i]->clear();
        combobox_ID[i]->addItem("请选择帧ID");
        for (int j = 0; j < Message_num; j++) {
            combobox_ID[i]->addItem(Mseeage_IDName[j]);
        }
    }
}

void Dialog_CustomCan::Add_DBCFile_Signal(int num, int messagenum)  // 将信号名称添加到元器件中
{
    combobox_SignalName[num]->clear();
    if(messagenum < 0)
    {
        return;
    }
    combobox_SignalName[num]->addItem("请选择信号名");
    for (int j = 0; j < Signal_num[messagenum]; j++) {
        QString Signal_stringtemp = Signal[messagenum][j];
        QStringList Signal_stringlisttemp = Signal_stringtemp.split(" ");
        combobox_SignalName[num]->addItem(Signal_stringlisttemp[2]);
    }

}

void Dialog_CustomCan::Add_DBCFile_SignalData(int num, int signalnum)   // 将信号消息添加到对应元器件中
{
    // 初始化
    lineedit_Start [num]->setText("");
    lineedit_Length[num]->setText("");
    lineedit_Unit  [num]->setText("");
    lineedit_Factor[num]->setText("");
    lineedit_Offset[num]->setText("");
    combobox_UorI  [num]->setCurrentIndex(0);

    // 没选任何信号
    if(signalnum < 0)
    {
        return;
    }

    // 信号字符串进行切割
    int messagenum = combobox_ID[num]->currentIndex() - 1;
    QString SignalData_stringtemp = Signal[messagenum][signalnum];
    SignalData_stringtemp.replace("|"," ").replace("[","").replace("]","")
                         .replace("(","").replace(")","").replace(": ","")
                         .replace("\"","").replace("\n","");
    QStringList SignalData_stringlisttemp = SignalData_stringtemp.split(QRegExp(" |,|@"));

    // 根据inter还是motorola来确定起始位如何求解
    if(ui->ComboBox_DataFormat->currentIndex())
    {
        lineedit_Start [num]->setText(QString::number(SignalData_stringlisttemp[3].toUInt()));
    }
    else
    {
        uint8_t temp = SignalData_stringlisttemp[3].toUInt();
        for (int i = 0;i<SignalData_stringlisttemp[4].toInt() - 1;i++)
        {
            (temp % 8 == 0)?temp = temp + 15:temp--;
        }
        lineedit_Start [num]->setText(QString::number(temp));

    }

    // 数据长度，单位，比例，偏移，有无符号的获取
    lineedit_Length[num]->setText(SignalData_stringlisttemp[4]);
    lineedit_Unit  [num]->setText(SignalData_stringlisttemp[10]);
    lineedit_Factor[num]->setText(SignalData_stringlisttemp[6]);
    lineedit_Offset[num]->setText(SignalData_stringlisttemp[7]);
    SignalData_stringlisttemp[5].right(1)=="+"?combobox_UorI[num]->setCurrentIndex(0):combobox_UorI[num]->setCurrentIndex(1);
}

bool Dialog_CustomCan::Check_CanMsgValid()      // 发送消息前，判断当前用户编写是否存在的错误，或者无法让底层正常解析
{
    int spd_num = 0;    // 车速，右后轮，左后轮 用户一共填写了几个。0个的话有问题
    int dir_num = 0;    // 判断有符号数，或者档位，用户一共写了几个。0个的话有问题
    for (int i = 0;i<6;i++)
    {
        if(checkbox_En[i]->isChecked() == true)     // 某个帧用户使能了
        {
            if((!ui->CheckBox_ManualInput->isChecked() && combobox_ID    [i]->currentText() == "") ||
               (ui->CheckBox_ManualInput->isChecked() && lineedit_ID    [i]->text() == "" )||
               lineedit_Start [i]->text() == "" ||
               lineedit_Length[i]->text() == "" ||
               lineedit_Offset[i]->text() == "" ||
               lineedit_Factor[i]->text() == "")        // 某个帧用户使能了但出现了某个值没写数据的情况
            {
                QMessageBox::about(this,"错误", name[i] + "有数据没有填写，请检查！");
                return false;
            }

            if(i == 0 || i == 3 || i == 4)      // 计数车速，右后轮，左后轮 用户一共填写了几个
            {
                spd_num++;;
                if(combobox_UorI[i]->currentIndex() == 1)   // 计数方向用户填写了几个
                {
                    dir_num++;
                }
            }

            int start = lineedit_Start[i]->text().toInt();      // 获取起始位
            int length = lineedit_Length[i]->text().toInt();    // 获取信号长度
            if(start < 0 || start > 63 || length < 1 || length >63)     // 如果数据超过本该有的值，报错
            {
                QMessageBox::about(this,"错误", name[i] + "数据长度或起始位有问题，请检查！");
                return false;
            }
            if(ui->ComboBox_DataFormat->currentIndex()==1)  // 如果帧是inter，就这样判断
            {
                if(start + length > 64 || start + length < 0)
                {
                    QMessageBox::about(this,"错误", name[i] + "数据格式有误，检查can报文的编码格式！");
                    return false;
                }
            }
            else    // 如果帧是motorola，就这样判断
            {
                int temp = ((int)(start / 8) * 2 + 1) * 8;
                if(start + length > temp || start > 63)
                {
                    QMessageBox::about(this,"错误", name[i] + "数据格式有误，检查can报文的编码格式！");
                    return false;
                }
            }

            if(i == 5)  // 档位特殊判断
            {
                int en_num = 0; // 挡位值用户勾选的个数
                int valid_num = 0;  // 前进档和倒车档用户填写的个数
                for (int i = 0;i<4;i++)
                {
                    if(checkbox_GearEn[i]->isChecked() == true && lineedit_GearValue[1]->text() != "")  // 按钮使能并且有数
                    {
                        en_num++;   // 计数
                        if(i == 1 || i == 2)    // 有效计数
                        {
                            valid_num++;
                        }
                    }
                }
                if(en_num == 0)
                {
                    QMessageBox::about(this,"错误", "档位所表示的值没有填写！\n请取消档位CAN，或者填写前进和后退档位表示的值！");
                    return false;
                }
                if(valid_num == 2)  // 如果档位有前进后退，那么该档位可以用来获取方向，否则不行
                {
                    dir_num++;
                }
            }
        }
    }

    if(!spd_num)
    {
        QMessageBox::about(this,"错误","请给出车速、左后轮轮速、右后轮速其中之一！");
        return false;
    }

    if(!dir_num)
    {
        QMessageBox::about(this,"错误","请给出档位信息，或者车速、后轮速符号位！");
        return false;
    }

    return true;
}

void Dialog_CustomCan::Get_CanMsg() // 获取用户填写的值发送底层
{
    uint8_t en_temp = 0, uori_temp = 0, unit_temp = 0;
    for (int i = 0; i < 6; i++) {       // en，单位，有无符号的获取
        if(checkbox_En[i]->isChecked())
        {
            en_temp += (1<<i);
        }
        if(combobox_UorI[i]->currentIndex())
        {
            uori_temp += (1<<i);
        }
        if(lineedit_Unit[i]->text().contains("k") || lineedit_Unit[i]->text().contains("K"))
        {
            unit_temp += (1<<i);
        }
    }
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.CanControlMsg.byte = en_temp;
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.CanControlMsg.b.InterorMotorola = ui->ComboBox_DataFormat->currentIndex();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.CanUnitMsg.byte = unit_temp;
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.CanSymbolMsg.byte = uori_temp;

    // ID获取
    if(ui->CheckBox_ManualInput->isChecked())
    {
        GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.VehicleSpd_ID = lineedit_ID[0]->text().toUInt(0, 16);
        GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.FLWheelSpd_ID = lineedit_ID[1]->text().toUInt(0, 16);
        GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.FRWheelSpd_ID = lineedit_ID[2]->text().toUInt(0, 16);
        GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.RLWheelSpd_ID = lineedit_ID[3]->text().toUInt(0, 16);
        GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.RRWheelSpd_ID = lineedit_ID[4]->text().toUInt(0, 16);
        GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.Gear_ID       = lineedit_ID[5]->text().toUInt(0, 16);
    }
    else
    {
        GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.VehicleSpd_ID = combobox_ID[0]->currentIndex()<=0?0:combobox_ID[0]->currentText().toUInt(0, 16);
        GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.FLWheelSpd_ID = combobox_ID[1]->currentIndex()<=0?0:combobox_ID[1]->currentText().toUInt(0, 16);
        GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.FRWheelSpd_ID = combobox_ID[2]->currentIndex()<=0?0:combobox_ID[2]->currentText().toUInt(0, 16);
        GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.RLWheelSpd_ID = combobox_ID[3]->currentIndex()<=0?0:combobox_ID[3]->currentText().toUInt(0, 16);
        GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.RRWheelSpd_ID = combobox_ID[4]->currentIndex()<=0?0:combobox_ID[4]->currentText().toUInt(0, 16);
        GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.      Gear_ID = combobox_ID[5]->currentIndex()<=0?0:combobox_ID[5]->currentText().toUInt(0, 16);
    }

    // 起始位获取
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.VehicleSpd_Start = lineedit_Start[0]->text().toUInt();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.FLWheelSpd_Start = lineedit_Start[1]->text().toUInt();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.FRWheelSpd_Start = lineedit_Start[2]->text().toUInt();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.RLWheelSpd_Start = lineedit_Start[3]->text().toUInt();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.RRWheelSpd_Start = lineedit_Start[4]->text().toUInt();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.      Gear_Start = lineedit_Start[5]->text().toUInt();

    // 长度获取
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.VehicleSpd_Length = lineedit_Length[0]->text().toUInt();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.FLWheelSpd_Length = lineedit_Length[1]->text().toUInt();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.FRWheelSpd_Length = lineedit_Length[2]->text().toUInt();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.RLWheelSpd_Length = lineedit_Length[3]->text().toUInt();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.RRWheelSpd_Length = lineedit_Length[4]->text().toUInt();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.      Gear_Length = lineedit_Length[5]->text().toUInt();

    // 偏移获取
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.VehicleSpd_Offset = lineedit_Offset[0]->text().toFloat();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.FLWheelSpd_Offset = lineedit_Offset[1]->text().toFloat();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.FRWheelSpd_Offset = lineedit_Offset[2]->text().toFloat();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.RLWheelSpd_Offset = lineedit_Offset[3]->text().toFloat();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.RRWheelSpd_Offset = lineedit_Offset[4]->text().toFloat();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.      Gear_Offset = lineedit_Offset[5]->text().toFloat();

    // 比例获取
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.VehicleSpd_Factor = lineedit_Factor[0]->text().toFloat();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.FLWheelSpd_Factor = lineedit_Factor[1]->text().toFloat();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.FRWheelSpd_Factor = lineedit_Factor[2]->text().toFloat();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.RLWheelSpd_Factor = lineedit_Factor[3]->text().toFloat();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.RRWheelSpd_Factor = lineedit_Factor[4]->text().toFloat();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.      Gear_Factor = lineedit_Factor[5]->text().toFloat();

    // 档位值表示的意义获取
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.Gear_P = lineedit_GearValue[0]->text().toUInt();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.Gear_D = lineedit_GearValue[1]->text().toUInt();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.Gear_R = lineedit_GearValue[2]->text().toUInt();
    GJDeVice_CAN_Msgbuf.GJDeVice_CAN_Msg.Gear_N = lineedit_GearValue[3]->text().toUInt();
}

void Dialog_CustomCan::Send_CanMsg()    // 发送用户自定义can信息
{
    if(Check_CanMsgValid()) // 判断是否正确，并且底层可以解析
    {
        Get_CanMsg();   // 获取数据
        // 发送规格化消息给底层
        emit Serial_Write(base_function::Serial_DataFormat(send_CustomCan_SendCanMsg, GJDeVice_CAN_Msgbuf.bytes, 103));

        ui->PushButton_SendCAN->setEnabled(false);
        timeOut_Timer->start(3000);
    }
}

void Dialog_CustomCan::TimeOut()
{
    timeOut_Timer->stop();
    ui->PushButton_SendCAN->setEnabled(true);
    QMessageBox::about(this,"提示","响应超时！");
}

void Dialog_CustomCan::receiveACK_CustomCan_head()
{
    timeOut_Timer->stop();
    ui->PushButton_SendCAN->setEnabled(true);
    QMessageBox::about(this,"提示","发送成功！");
}

// private slots:
// 所有按钮的信号槽
void Dialog_CustomCan::on_PushButton_ReadDBC_clicked()
{
    Read_DBCFile();
}

void Dialog_CustomCan::on_PushButton_SendCAN_clicked()
{
    Send_CanMsg();
}

void Dialog_CustomCan::on_CheckBox_ManualInput_clicked()
{
    Input_ControlEnable();
}

void Dialog_CustomCan::on_CheckBox_DBCInput_clicked()
{
    Input_ControlEnable();
}

void Dialog_CustomCan::on_CheckBox_VehicleSpd_En_clicked()
{
    EN_ControlEnable(0);
}

void Dialog_CustomCan::on_CheckBox_FLWheelSpd_En_clicked()
{
    EN_ControlEnable(1);
}

void Dialog_CustomCan::on_CheckBox_FRWheelSpd_En_clicked()
{
    EN_ControlEnable(2);
}

void Dialog_CustomCan::on_CheckBox_RLWheelSpd_En_clicked()
{
    EN_ControlEnable(3);
}

void Dialog_CustomCan::on_CheckBox_RRWheelSpd_En_clicked()
{
    EN_ControlEnable(4);
}

void Dialog_CustomCan::on_CheckBox_Gear_En_clicked()
{
    EN_ControlEnable(5);
}

void Dialog_CustomCan::on_CheckBox_Gear_PEN_clicked()
{
    GearEN_ControlEnable(0);
}

void Dialog_CustomCan::on_CheckBox_Gear_DEN_clicked()
{
    GearEN_ControlEnable(1);
}

void Dialog_CustomCan::on_CheckBox_Gear_REN_clicked()
{
    GearEN_ControlEnable(2);
}

void Dialog_CustomCan::on_CheckBox_Gear_NEN_clicked()
{
    GearEN_ControlEnable(3);
}

void Dialog_CustomCan::on_ComboBox_VehicleSpd_ID_currentIndexChanged(int index)
{
    Add_DBCFile_Signal(0, index-1);
}

void Dialog_CustomCan::on_ComboBox_FLWheelSpd_ID_currentIndexChanged(int index)
{
    Add_DBCFile_Signal(1, index-1);
}

void Dialog_CustomCan::on_ComboBox_FRWheelSpd_ID_currentIndexChanged(int index)
{
    Add_DBCFile_Signal(2, index-1);
}

void Dialog_CustomCan::on_ComboBox_RLWheelSpd_ID_currentIndexChanged(int index)
{
    Add_DBCFile_Signal(3, index-1);
}

void Dialog_CustomCan::on_ComboBox_RRWheelSpd_ID_currentIndexChanged(int index)
{
    Add_DBCFile_Signal(4, index-1);
}

void Dialog_CustomCan::on_ComboBox_Gear_ID_currentIndexChanged(int index)
{
    Add_DBCFile_Signal(5, index-1);
}

void Dialog_CustomCan::on_ComboBox_VehicleSpd_SignalName_currentIndexChanged(int index)
{
    Add_DBCFile_SignalData(0, index-1);
}

void Dialog_CustomCan::on_ComboBox_FLWheelSpd_SignalName_currentIndexChanged(int index)
{
    Add_DBCFile_SignalData(1, index-1);
}

void Dialog_CustomCan::on_ComboBox_FRWheelSpd_SignalName_currentIndexChanged(int index)
{
    Add_DBCFile_SignalData(2, index-1);
}

void Dialog_CustomCan::on_ComboBox_RLWheelSpd_SignalName_currentIndexChanged(int index)
{
    Add_DBCFile_SignalData(3, index-1);
}

void Dialog_CustomCan::on_ComboBox_RRWheelSpd_SignalName_currentIndexChanged(int index)
{
    Add_DBCFile_SignalData(4, index-1);
}

void Dialog_CustomCan::on_ComboBox_Gear_SignalName_currentIndexChanged(int index)
{
    Add_DBCFile_SignalData(5, index-1);
}


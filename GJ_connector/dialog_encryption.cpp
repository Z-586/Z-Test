#include "dialog_encryption.h"
#include "ui_dialog_encryption.h"


Dialog_Encryption::Dialog_Encryption(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::Dialog_Encryption)
{
    ui->setupUi(this);
    Dialog_EncryptionInit();
}

Dialog_Encryption::~Dialog_Encryption()
{
        delete ui;
}

void Dialog_Encryption::Dialog_EncryptionInit()     // 初始化函数
{
    this->setWindowTitle("激活码");

    QWidget::setAttribute(Qt::WA_QuitOnClose,false);     // 所有子窗口要写false
    QWidget::setAttribute(Qt::WA_DeleteOnClose);     // 所有子窗口要写false
    setWindowFlags((windowFlags()&~Qt::WindowContextHelpButtonHint) | Qt::WindowMinimizeButtonHint);

    ui->label1->setTextInteractionFlags(Qt::TextSelectableByMouse);
}

void Dialog_Encryption::Encryption(QString str)     // 加密函数
{
    srand(time(NULL));
    int randomkey = (int)((double)rand()/(double)(RAND_MAX)*899999)+100000;    //随机获取一个密钥的长度
    int key2 = randomkey/100;
    unsigned long temp[4] = {0},temp1[4] = {0};
    for(int i = 0; i < 6; i++)
    {
        temp[0] = temp[0]*5 + key + i + key2*(temp[0]%100);
        temp[1] = temp[1]*7 + key + i + key2*(temp[1]%100);
        temp[2] = temp[2]*11+ key + i + key2*(temp[2]%100);
        temp[3] = temp[3]*13+ key + i + key2*(temp[3]%100);
    }

    QString b;
    for(int i = 0; i < 4; i++)
    {
        temp1[i] = str.mid(5 * i,5).append(str.mid(26-2*i,2)).toULong() ^ (temp[i]%1000000);
        b = QString("%1%2").arg(b).arg(temp1[i],7,10,QLatin1Char('0'));
    }
    b = QString("%1%2").arg(b).arg(randomkey,6,10,QLatin1Char('0'));
    unsigned long temp2 = 0;
    unsigned long temp3 = 0;
    for (int i =0;i<b.size()/2;i++) {
        temp2 ^= b.mid(i*2,2).toULong();
        temp3 ^= b.mid(i*2,1).toULong() ^ b.mid(i*2+1,1).toULong();
    }
    b = QString("%1%2%3").arg(b).arg(temp2%10).arg(temp3%10);
    ui->label1->setText(b);
}

void Dialog_Encryption::Decryption(QString str)     // 解密函数，测试用的，输入是加密获得的超长字符串，已移植底层
{
//    int i,j;
//    uint8_t test1[36];
//    for (i = 0;i<36;i++) {
//        test1[i] = str.mid(i,1).toUInt();
//    }
//    uint8_t crc1 = 0,crc2 = 0;
//    for (i = 0;i<17;i++) {
//        crc1 ^= (test1[2 * i] * 10 + test1[2* i+1]);
//        crc2 ^= test1[2 * i] ^ test1[2* i+1];
//    }

//    if(crc1 % 10 == test1[34] && crc2 % 10 == test1[35])
//    {
//        uint8_t key1 = 49;
//        uint16_t key2 = 0;
//        for (i = 28; i < 32; i++) {
//            key2 = test1[i] + key2 * 10;
//        }

//        unsigned long temp[4] = {0},temp1[4] = {0},temp2 = 0;
//        for(i = 0; i < 6; i++)
//        {
//            temp[0] = temp[0]*5 + key1 + i + key2*(temp[0]%100);
//            temp[1] = temp[1]*7 + key1 + i + key2*(temp[1]%100);
//            temp[2] = temp[2]*11+ key1 + i + key2*(temp[2]%100);
//            temp[3] = temp[3]*13+ key1 + i + key2*(temp[3]%100);
//        }
//        uint32_t sec = 0;
//        for(i = 3; i >= 0; i--)
//        {
//            temp2 = 0;
//            for(j = 0; j < 7; j++)
//            {
//                temp2 = test1[7*i+j] + temp2*10;
//            }
//            temp1[i] = temp2 ^ (temp[i] % 1000000);
//            sec = temp1[i] % 100 + sec * 100;
//            temp1[i] /= 100;
//        }
//        uint32_t s1,d2,d3,d4,d5,d6;
//        sec *= 100;
//        d6 = temp1[3] % 100;
//        d5 = (temp1[3] / 100) % 100;
//        d4 = (temp1[3] / 10000) + (temp1[2] % 10) * 10;
//        d3 = (temp1[2] / 10) % 1000;
//        d2 = (temp1[0] % 100) * 1000000 + temp1[1] * 10 + (temp1[2] / 10000);
//        s1 = temp1[0] / 1000;
//    }
//    else
//    {
//        // 激活码有问题
//    }
}

QString Dialog_Encryption::GetEncryptionString()        // 获取需要加密的字符串（SN+到期时间）
{
    QDateTime dateTime;
    int timeT = QDateTime::fromString(ui->LineEdit_ActiveTime->text(), "yyyyMMdd").toTime_t();
    int timeT1 = QDateTime::fromString("19800106", "yyyyMMdd").toTime_t();
    return ui->LineEdit_SN->text().append(QString("%1").arg((timeT-timeT1)/100,8,10,QLatin1Char('0')));
}

bool Dialog_Encryption::IsAdministrator(QString str)    // 特殊操作时，解锁管理员功能
{
    if(str == "gongji813")
    {
        emit AdministratorMode();
        return true;
    }
    return false;
}

// Button SLOTS
// 所有按钮信号槽
void Dialog_Encryption::on_PushButton_Encryption_clicked()
{
    Encryption(GetEncryptionString());
}

void Dialog_Encryption::on_PushButton_SendActiveCode_clicked()
{
    if(!IsAdministrator(ui->LineEdit_ActiveCode->text()))
    {
        emit Serial_Write(base_function::Serial_DataFormat(send_ActCode_SendActCode, ui->LineEdit_ActiveCode->text()));
        this->done(QDialog::Rejected);
    }
    else
    {
        this->done(QDialog::Rejected);
    }
}


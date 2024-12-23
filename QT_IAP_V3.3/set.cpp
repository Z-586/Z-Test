#include "set.h"
#include "QSettings"
#include "QFile"

QString Set::ConfigFile = "config.ini";


bool Set:: uartEn = true;                       // 串口通讯
bool Set:: rs485En =false;                              // Rs485通讯
QStringList Set::portNumberList;             // 端口号
int         Set::uartBaud=115200;               // 波特率
int         Set::uartCheckSum =0;               // none
QString     Set::currentSelectPort="";          // 当前选择的端口号

uint8_t     Set::rs485Addr=1;                   // 设备地址

bool Set::canEn = false;        // CAN通讯
int  Set::canChannel =0;       // CAN通道
int  Set::canDevice  =0;       // CAN设备 0：CANalyst  1:zlg
int  Set::canBaud=250;         // CAN   波特率
int  Set::canAddr=0;           // Can 地址

int  Set::AnswerTimeOut =500;
bool Set::CodMode = false;

void Set::readConfig()
{
    if (!checkConfig())
    {
        return;
    }

    QSettings set(Set::ConfigFile, QSettings::IniFormat);
    set.beginGroup("ComConfig");
    Set::uartEn = set.value("uartEn").toBool();
    Set::portNumberList = set.value("portNumberList").toStringList();
    Set::uartBaud = set.value("uartBaud").toInt();
    Set::uartCheckSum = set.value("uartCheckSum").toInt();
    Set::currentSelectPort = set.value("currentSelectPort").toString();
    Set::rs485Addr = set.value("rs485Addr").toInt();
    Set::rs485En   = set.value("rs485En").toBool();
    set.endGroup();

    set.beginGroup("CanConfig");
    Set::canEn = set.value("canEn").toBool();
    Set::canChannel = set.value("canChannel").toInt();
    Set::canDevice = set.value("canDevice").toInt();
    Set::canBaud = set.value("canBaud").toInt();
    Set::canAddr = set.value("canAddr").toInt();

    Set::AnswerTimeOut = set.value("AnswerTimeOut").toInt();
    Set::CodMode = set.value("CodMode").toBool();

    set.endGroup();
}

void Set::writeConfig()
{
    QSettings set(Set::ConfigFile, QSettings::IniFormat);

    set.beginGroup("ComConfig");
    set.setValue("uartEn", Set::uartEn);
    set.setValue("portNumberList", Set::portNumberList);
    set.setValue("uartBaud", Set::uartBaud);
    set.setValue("uartCheckSum", Set::uartCheckSum);

    set.setValue("currentSelectPort", Set::currentSelectPort);
    set.setValue("rs485Addr", Set::rs485Addr);
    set.setValue("rs485En", Set::rs485En);
    set.endGroup();

    set.beginGroup("CanConfig");
    set.setValue("canEn", Set::canEn);
    set.setValue("canChannel", Set::canChannel);
    set.setValue("canDevice", Set::canDevice);
    set.setValue("canBaud", Set::canBaud);
    set.setValue("canAddr", Set::canAddr);
    set.setValue("AnswerTimeOut", Set::AnswerTimeOut);
    set.setValue("CodMode", Set::CodMode);
    set.endGroup();
}

void Set::newConfig()
{
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
    Set::Parity = Set::Parity.toLatin1();
#endif
    writeConfig();
}

bool Set::checkConfig()
{
    //如果配置文件大小为0,则以初始值继续运行,并生成配置文件
    QFile file(Set::ConfigFile);
    if (file.size() == 0) {
        newConfig();
        return false;
    }

    //如果配置文件不完整,则以初始值继续运行,并生成配置文件
    if (file.open(QFile::ReadOnly)) {
        bool ok = true;
        while (!file.atEnd()) {
            QString line = file.readLine();
            line = line.replace("\r", "");
            line = line.replace("\n", "");
            QStringList list = line.split("=");

            if (list.count() == 2) {
                if (list.at(1) == "") {
                    ok = false;
                    break;
                }
            }
        }

        if (!ok) {
            newConfig();
            return false;
        }
    } else {
        newConfig();
        return false;
    }

    return true;
}



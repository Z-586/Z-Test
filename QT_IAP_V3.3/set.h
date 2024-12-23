#ifndef SET_H
#define SET_H

#include "QString"

class Set
{
public:
    static QString ConfigFile;              //配置文件路径

    static bool uartEn;                      // 串口通讯
    static bool rs485En;                     // Rs485通讯
    static QStringList portNumberList;           // 端口号
    static int         uartBaud;             // 波特率
    static int          uartCheckSum;                   //
    static QString     currentSelectPort;    // 当前选择的端口号
    static uint8_t     rs485Addr;            // 设备地址

    static bool canEn;        // CAN通讯
    static int  canChannel;   // CAN通道
    static int  canDevice;    // CAN设备 0：CANalyst  1:zlg
    static int  canBaud;      // CAN   波特率
    static int  canAddr;      // Can 地址

    static int  AnswerTimeOut;   // 通讯应答超时时间
    static bool CodMode;         // 0: 明文传输  1： 密文传输


    //读写配置参数及其他操作
    static void readConfig();           //读取配置参数
    static void writeConfig();          //写入配置参数
    static void newConfig();            //以初始值新建配置文件
    static bool checkConfig();          //校验配置文件
};


#endif // SET_H

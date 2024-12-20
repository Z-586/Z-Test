#ifndef BASE_FUNCTION_H
#define BASE_FUNCTION_H

#include <stdint.h>
#include <QTime>
#include <QCoreapplication.h>
#include "constant.h"

class base_function
{

public:
    base_function();

    // CRC函数
    static uint8_t crc8(uint8_t data, unsigned int crc);
    static uint8_t Calculate_Crc8(uint8_t* buf, uint16_t len);
    static uint8_t Calculate_Crc8(QString head, uint8_t *buf, uint16_t len);


    // 串口数据规范函数，根据不同输入，做相同的事情（填满192）
    static QByteArray Serial_DataFormat(QString head);
    static QByteArray Serial_DataFormat(QString head, QByteArray data);
    static QByteArray Serial_DataFormat(QString head, QString data);
    static QByteArray Serial_DataFormat(QString head, uint8_t *data, int len);

    static void sleep(unsigned int msec);   // 延迟函数
};

#endif // BASE_FUNCTION_H

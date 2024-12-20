#include "base_function.h"

base_function::base_function()
{

}


// CRC函数
uint8_t base_function::crc8(uint8_t data, unsigned int crc)
{
    uint8_t crc8 = (0x107 & 0xFF);
    crc ^= data;    //前一字节计算CRC后的结果异或上后一字节，再次计算CRC
    for (uint8_t i=0; i<8; i++){
        if (crc & 0x80)
        {
           crc <<= 1;
           crc ^= crc8;
        }
        else
        {
           crc <<= 1;
        }
    }
    return crc;
}

uint8_t base_function::Calculate_Crc8(uint8_t *buf, uint16_t len)
{
    uint8_t crc = 0x00;
    while(len--)
    {
        crc = crc8(*buf, crc);

        if(len>0x00)
        {
            buf++;
        }
    }
    return crc;
}

uint8_t base_function::Calculate_Crc8(QString head, uint8_t *buf, uint16_t len)
{
    uint8_t crc = 0x00;
    for(int i = 0;i<head.size();i++)
    {
        crc = crc8(head.toUtf8().at(i), crc);
    }
    for(int i = 0;i<len;i++)
    {
        crc = crc8(*(buf+i), crc);
    }
    return crc;
}

// 串口数据规范函数，根据不同输入，做相同的事情（填满192）
QByteArray base_function::Serial_DataFormat(QString head)
{
    QByteArray temp;
    temp.append(head.toUtf8().data());  // QString字头转QByteArray
    for (int i = temp.length(); i<send_GJProtocol_length ; i++) // 填充0
    {
        temp.append(QByteArray(0x00), 1);
    }
    return temp;
}

QByteArray base_function::Serial_DataFormat(QString head, QString data)
{
    QByteArray temp;
    temp.append(head.append(data).toUtf8().data()); // QString字头，QString数据转QByteArray
    for (int i = temp.length(); i<send_GJProtocol_length ; i++) // 填充0
    {
        temp.append(QByteArray(0x00), 1);
    }
    return temp;
}

QByteArray base_function::Serial_DataFormat(QString head, QByteArray data)
{
    QByteArray temp;
    temp.append(head.toUtf8().data()).append(data); // QString字头转QByteArray，然后和QByteArray数据合并
    for (int i = temp.length(); i<send_GJProtocol_length ; i++) // 填充0
    {
        temp.append(QByteArray(0x00), 1);
    }
    return temp;
}

QByteArray base_function::Serial_DataFormat(QString head, uint8_t *data, int len)
{
    QByteArray temp;
    QByteArray data_temp((const char*)data, len);   // uint8_t数据转QByteArray
    temp.append(head.toUtf8().data()).append(data_temp);    // QString字头转QByteArray，然后和QByteArray数据合并
    for (int i = temp.length(); i<send_GJProtocol_length ; i++) // 填充0
    {
        temp.append(QByteArray(0x00), 1);
    }
    return temp;
}

void base_function::sleep(unsigned int msec)    // 延迟函数
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

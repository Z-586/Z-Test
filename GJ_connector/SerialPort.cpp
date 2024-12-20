#include "SerialPort.h"
#include "./global/globalsetting.h"


SerialPort::GJDeVice_Polling_MsgBuf_t SerialPort::gjDevicePollingData;

namespace  {
    GlobalSetting *pGlobalSetting = GlobalSetting::getInstance();
    QMap<ProjectMoudel, QString> headMap{
        {E_VSMS1000,  "AA44AA46"},
        {E_A920, "AA44AA45"},
        {E_660, "AA44AA45"},
        {E_802, "AA44AA45"},
        {E_602, "AA44AA45"},
    };
}

SerialPort::SerialPort(QObject *parent) : QObject(parent)
{
    Serial = new QSerialPort();
}

void SerialPort::OpenSerial_Init()  // 打开串口后初始化函数
{
    connect(Serial, SIGNAL(readyRead()), this, SLOT(Serial_readyRead()));
}

bool SerialPort::Open_Serial(QString PortName,
                                int BaudRate,
                                QSerialPort::DataBits DataBits,
                                QSerialPort::Parity Parity,
                                QSerialPort::StopBits StopBits)     // 打开串口
{

    //设置串口名
    Serial->setPortName(PortName);
    //设置波特率
    Serial->setBaudRate(BaudRate);
    //设置数据位数
    Serial->setDataBits(DataBits);
    //设置奇偶校验
    Serial->setParity(Parity);
    //设置停止位
    Serial->setStopBits(StopBits);
    //设置流控制
    Serial->setFlowControl(QSerialPort::NoFlowControl);

    if (Serial->open(QIODevice::ReadWrite))
    {
        qDebug() << "Port have been opened";
        OpenSerial_Init();
        return true;
    }
    else
    {
        qDebug() << "open it failed";
        return false;
    }    
}

void SerialPort::Close_Serial()     // 关闭串口
{
    Serial->close();
}

void SerialPort::Serial_readyRead() // 读取串口数据
{
    QByteArray serialbuffer_temp = Serial->readAll();
    serialbuffer.append(serialbuffer_temp);

    while(true)
    {
        if(!FindHead_withoutData() && !FindHead_withData()) // 看是否有字头
        {
            if(serialbuffer.length()>receive_GJProtocol_length) // 担心缓冲区积累很多无用垃圾消息，稍微清除一下
            {
                serialbuffer = serialbuffer.mid(serialbuffer.length() - receive_GJProtocol_length, receive_GJProtocol_length);
            }
            break;
        }
    }
}

bool SerialPort::FindHead_withoutData() // 找不带数据的共迹消息
{
    int serialbuffer_length = serialbuffer.size();
    if(serialbuffer.contains(receive_Firmware_PleaseUpdata))
    {
        serialbuffer.remove(serialbuffer.indexOf(receive_Firmware_PleaseUpdata),
                            QString(receive_Firmware_PleaseUpdata).length());
        emit receive_Firmware_PleaseUpdata_head();
    }

    if(serialbuffer.contains(receive_Firmware_PleaseWaitUpdata))
    {
        serialbuffer.remove(serialbuffer.indexOf(receive_Firmware_PleaseWaitUpdata),
                            QString(receive_Firmware_PleaseWaitUpdata).length());
        emit receive_Firmware_PleaseWaitUpdata_head();
    }

    if(serialbuffer.contains(receive_Firmware_ReceiveError))
    {
        serialbuffer.remove(serialbuffer.indexOf(receive_Firmware_ReceiveError),
                            QString(receive_Firmware_ReceiveError).length());
        emit receive_Firmware_ReceiveError_head();
    }

    if(serialbuffer.contains(receive_Firmware_FileError))
    {
        serialbuffer.remove(serialbuffer.indexOf(receive_Firmware_FileError),
                            QString(receive_Firmware_FileError).length());
        emit receive_Firmware_FileError_head();
    }

    if(serialbuffer.contains(receive_Firmware_UpdataError))
    {
        serialbuffer.remove(serialbuffer.indexOf(receive_Firmware_UpdataError),
                            QString(receive_Firmware_UpdataError).length());
        emit receive_Firmware_UpdataError_head();
    }

    if(serialbuffer.contains(receive_Firmware_UpdataSuccess))
    {
        serialbuffer.remove(serialbuffer.indexOf(receive_Firmware_UpdataSuccess),
                            QString(receive_Firmware_UpdataSuccess).length());
        emit receive_Firmware_UpdataSuccess_head();
    }

    if(serialbuffer.contains(receive_Calibration_StaticCalibrating))
    {
        serialbuffer.remove(serialbuffer.indexOf(receive_Calibration_StaticCalibrating),
                            QString(receive_Calibration_StaticCalibrating).length());
        emit receive_Calibration_StaticCalibrating_head();
    }

    if(serialbuffer.contains(receive_Calibration_StaticSuccess))
    {
        serialbuffer.remove(serialbuffer.indexOf(receive_Calibration_StaticSuccess),
                            QString(receive_Calibration_StaticSuccess).length());
        emit receive_Calibration_StaticSuccess_head();
    }

    if(serialbuffer.contains(receive_Calibration_DynamicCalibrating))
    {
        serialbuffer.remove(serialbuffer.indexOf(receive_Calibration_DynamicCalibrating),
                            QString(receive_Calibration_DynamicCalibrating).length());
        emit receive_Calibration_DynamicCalibrating_head();
    }

    if(serialbuffer.contains(receive_Calibration_IncTurningRatio))
    {
        serialbuffer.remove(serialbuffer.indexOf(receive_Calibration_IncTurningRatio),
                            QString(receive_Calibration_IncTurningRatio).length());
        emit receive_Calibration_IncTurningRatio_head();
    }

    if(serialbuffer.contains(receive_Calibration_IncForwardRatio))
    {
        serialbuffer.remove(serialbuffer.indexOf(receive_Calibration_IncForwardRatio),
                            QString(receive_Calibration_IncForwardRatio).length());
        emit receive_Calibration_IncForwardRatio_head();
    }

    if(serialbuffer.contains(receive_Calibration_PleaseChangeCaliSites))
    {
        serialbuffer.remove(serialbuffer.indexOf(receive_Calibration_PleaseChangeCaliSites),
                            QString(receive_Calibration_PleaseChangeCaliSites).length());
        emit receive_Calibration_PleaseChangeCaliSites_head();
    }

    if(serialbuffer.contains(receive_TempCali_RequestData))
    {
        serialbuffer.remove(serialbuffer.indexOf(receive_TempCali_RequestData),
                            QString(receive_TempCali_RequestData).length());
        emit receive_TempCali_RequestData_head();
    }

    if(serialbuffer.contains(receive_TempCali_RepeatData))
    {
        serialbuffer.remove(serialbuffer.indexOf(receive_TempCali_RepeatData),
                            QString(receive_TempCali_RepeatData).length());
        emit receive_TempCali_RepeatData_head();
    }

    if(serialbuffer.contains(receive_TempCali_CompleteData))
    {
        serialbuffer.remove(serialbuffer.indexOf(receive_TempCali_CompleteData),
                            QString(receive_TempCali_CompleteData).length());
        emit receive_TempCali_CompleteData_head();
    }

    //-----------------------------------------------------
    if(serialbuffer.contains(receiveACK_Calibration_UserInstallationAngle))
    {
        serialbuffer.remove(serialbuffer.indexOf(receiveACK_Calibration_UserInstallationAngle),
                            QString(receiveACK_Calibration_UserInstallationAngle).length());
        emit receiveACK_Calibration_UserInstallationAngle_head();
    }

    if(serialbuffer.contains(receiveACK_Calibration_SystemInstallationAangle))
    {
        serialbuffer.remove(serialbuffer.indexOf(receiveACK_Calibration_SystemInstallationAangle),
                            QString(receiveACK_Calibration_SystemInstallationAangle).length());
        emit receiveACK_Calibration_SystemInstallationAangle_head();
    }

    if(serialbuffer.contains(receiveACK_Calibration_Static))
    {
        serialbuffer.remove(serialbuffer.indexOf(receiveACK_Calibration_Static),
                            QString(receiveACK_Calibration_Static).length());
        emit receiveACK_Calibration_Static_head();
    }

    if(serialbuffer.contains(receiveACK_Calibration_Dynamic))
    {
        serialbuffer.remove(serialbuffer.indexOf(receiveACK_Calibration_Dynamic),
                            QString(receiveACK_Calibration_Dynamic).length());
        emit receiveACK_Calibration_Dynamic_head();
    }

    if(serialbuffer.contains(receiveACK_Calibration_Cancel))
    {
        serialbuffer.remove(serialbuffer.indexOf(receiveACK_Calibration_Cancel),
                            QString(receiveACK_Calibration_Cancel).length());
        emit receiveACK_Calibration_Cancel_head();
    }

    if(serialbuffer.contains(receiveACK_Calibration_SaveResult))
    {
        serialbuffer.remove(serialbuffer.indexOf(receiveACK_Calibration_SaveResult),
                            QString(receiveACK_Calibration_SaveResult).length());
        emit receiveACK_Calibration_SaveResult_head();
    }

    if(serialbuffer.contains(receiveACK_Calibration_DontSaveResult))
    {
        serialbuffer.remove(serialbuffer.indexOf(receiveACK_Calibration_DontSaveResult),
                            QString(receiveACK_Calibration_DontSaveResult).length());
        emit receiveACK_Calibration_DontSaveResult_head();
    }

    if(serialbuffer.contains(receiveACK_Calibration_WheelBase))
    {
        serialbuffer.remove(serialbuffer.indexOf(receiveACK_Calibration_WheelBase),
                            QString(receiveACK_Calibration_WheelBase).length());
        emit receiveACK_Calibration_WheelBase_head();
    }

    if(serialbuffer.contains(receiveACK_Calibration_LeverINS2Rear))
    {
        serialbuffer.remove(serialbuffer.indexOf(receiveACK_Calibration_LeverINS2Rear),
                            QString(receiveACK_Calibration_LeverINS2Rear).length());
        emit receiveACK_Calibration_LeverINS2Rear_head();
    }

    if(serialbuffer.contains(receiveACK_ProtocolChange_OK))
    {
        serialbuffer.remove(serialbuffer.indexOf(receiveACK_ProtocolChange_OK),
                            QString(receiveACK_ProtocolChange_OK).length());
        emit receiveACK_ChangeProtocolOK_head();
    }

    if(serialbuffer.contains(receiveACK_CustomCan_OK))
    {
        serialbuffer.remove(serialbuffer.indexOf(receiveACK_CustomCan_OK),
                            QString(receiveACK_CustomCan_OK).length());
        emit receiveACK_CustomCan_head();
    }

    if(serialbuffer.contains(receiveACK_RTCMSelect_OK))
    {
        serialbuffer.remove(serialbuffer.indexOf(receiveACK_RTCMSelect_OK),
                            QString(receiveACK_RTCMSelect_OK).length());
        emit receiveACK_RTCMSelectType_head();
    }

    if(serialbuffer.contains(receiveACK_StaticIPPort_OK))
    {
        serialbuffer.remove(serialbuffer.indexOf(receiveACK_StaticIPPort_OK),
                            QString(receiveACK_StaticIPPort_OK).length());
        emit receiveACK_StaticIPPort_head();
    }


    if(serialbuffer.contains(rec_ETHCfg_Resonse))
    {
        serialbuffer.remove(serialbuffer.indexOf(rec_ETHCfg_Resonse),
                            QString(rec_ETHCfg_Resonse).length());
        emit sig_recETHCfg_data_head();
    }

    if(serialbuffer.contains(recCustomProtocolReturnHead))
    {
        serialbuffer.remove(serialbuffer.indexOf(recCustomProtocolReturnHead),
                            QString(recCustomProtocolReturnHead).length());
        emit sig_recCusmtomProtocolResponseHead();
    }

    if (serialbuffer.contains(rec_ReadEHTCfdResponse))
    {
        int headerIndex = serialbuffer.indexOf(rec_ReadEHTCfdResponse);
        int totalRequiredLength = headerIndex + 8 + ETH_CFG_LEN;
            if (serialbuffer.size() >=  totalRequiredLength)
            {
                QByteArray extractedData = serialbuffer.mid(headerIndex, totalRequiredLength);
                serialbuffer.remove(headerIndex, totalRequiredLength);
                emit sig_recETHCfg_ReturnData(extractedData.mid(8, ETH_CFG_LEN));
            }

    }

    if(serialbuffer_length == serialbuffer.size())
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool SerialPort::FindHead_withData()    // 找带字头的共迹消息
{
    int serialbuffer_length = serialbuffer.size();
    QString curHead = headMap.value(pGlobalSetting->getMoudelType());
    if(serialbuffer.toHex().toUpper().contains(curHead.toUtf8()))
    {
        uint16_t index = serialbuffer.toHex().toUpper().indexOf(curHead) / 2;
        if(serialbuffer.size() - index >= receive_GJProtocol_length)
        {
            QByteArray data = serialbuffer.mid(index, receive_GJProtocol_length);
            emit delDoneData(data); // 触发存信号

            DealHead_GJProtocol_Head(data); // 处理数据
            serialbuffer.remove(index, receive_GJProtocol_length);  // 移除数据

            emit delDone_GJProtocol_Data(); // 触发共迹协议解析ok信号
            emit delDone_GJProtocol_PollingData();  // 触发共迹协议轮询解析ok信号
            emit delDone_GJProtocol_TrackMap_Point();   // 触发共迹协议经纬度解析ok信号

        }
    }
    if(serialbuffer.contains(receive_Calibration_DynamicSuccess))
    {
//
//        qDebug() << 346;
        uint16_t index = serialbuffer.indexOf(receive_Calibration_DynamicSuccess);
        if(serialbuffer.size() - index >= receive_GJProtocol_length)
        {
            DealHead_Calibration_DynamicSuccess(serialbuffer.mid(index, receive_Calibration_DynamicSuccess_length));
            serialbuffer.remove(index, receive_Calibration_DynamicSuccess_length);
            emit receive_Calibration_DynamicSuccess_head();
        }
    }


    if(serialbuffer.contains(receive_TempCali_DeviceHasSavedData))
    {
        uint16_t index = serialbuffer.indexOf(receive_TempCali_DeviceHasSavedData);
        if(serialbuffer.size() - index >= receive_TempCali_DeviceHasSavedData_length)
        {
            emit receive_TempCali_DeviceHasSavedData_head(serialbuffer.mid(index, receive_TempCali_DeviceHasSavedData_length));
            serialbuffer.remove(index, receive_TempCali_DeviceHasSavedData_length);
        }
    }
    if(serialbuffer_length == serialbuffer.size())  // 通过判断有没有数据被移除，来确定是否全部能解析的都解析ok
    {
        return false;
    }
    else
    {
        return true;
    }
}

void SerialPort::DealHead_GJProtocol_Head(QByteArray data)      // 处理共迹协议
{
    QVariant msgBufVariant = pGlobalSetting->getMsgBuf();

    if (msgBufVariant.canConvert<GJDeVice_MsgBuf_920Vertion*>())
    {
        // 这里可以安全地将 QVariant 转换为 GJDeVice_MsgBuf_920Vertion*
        GJDeVice_MsgBuf_920Vertion *msgBuf920 = msgBufVariant.value<GJDeVice_MsgBuf_920Vertion*>();
        for (int i = 0; i < receive_GJProtocol_length; i++)
        {
            msgBuf920->bytes[i] = (uint8_t)data.at(i);
        }
        for (int i = 0; i < 8; i++)
        {
             gjDevicePollingData.bytes[i+(msgBuf920->GJDeVice_Msg.PollIndex-1) * 8] = msgBuf920->GJDeVice_Msg.PollData_u8[i];
        }

    }
    else if (msgBufVariant.canConvert<GJDeVice_MsgBuf_1000Vertion*>())
    {
        GJDeVice_MsgBuf_1000Vertion *msgBuf1000 = msgBufVariant.value<GJDeVice_MsgBuf_1000Vertion*>();

        for (int i = 0; i < receive_GJProtocol_length; i++)
        {
            msgBuf1000->bytes[i] = (uint8_t)data.at(i);
        }
        for (int i = 0; i < 8; i++)
        {
            gjDevicePollingData.bytes[i+(msgBuf1000->GJDeVice_Msg.PollIndex-1) * 8] = msgBuf1000->GJDeVice_Msg.PollData_u8[i];
        }
    }
    else
    {
        // 处理类型不匹配的情况
        qDebug() << "Unknown type in QVariant";
    }

}

void SerialPort::DealHead_Calibration_DynamicSuccess(QByteArray data)
{
    std::unique_ptr<GJDeVice_Dynamic_MsgBuf_t>& msgBufRef = pGlobalSetting->getMsg1000DynamicDataRef();
    for (int i = 0; i < receive_Calibration_DynamicSuccess_length; i++)
    {
            msgBufRef->bytes[i] = (uint8_t)data.at(i);
    }
}

void SerialPort::Serial_Write(QByteArray data)  // 串口发送
{
//    qDebug()<<data.toHex();
    Serial->write(data);
    QCoreApplication::processEvents();
}




//bool SerialPort::FindHead_withData()    // 找带字头的共迹消息
//{
//    int serialbuffer_length = serialbuffer.size();
//    if(serialbuffer.toHex().toUpper().contains(receive_GJProtocol_Head))
//    {
//        uint16_t index = serialbuffer.toHex().toUpper().indexOf(receive_GJProtocol_Head) / 2;
//        if(serialbuffer.size() - index >= receive_GJProtocol_length)
//        {
//            QByteArray data = serialbuffer.mid(index, receive_GJProtocol_length);
//            emit delDoneData(data); // 触发存信号

//            DealHead_GJProtocol_Head(data); // 处理数据
//            serialbuffer.remove(index, receive_GJProtocol_length);  // 移除数据

//            emit delDone_GJProtocol_Data(); // 触发共迹协议解析ok信号
//            emit delDone_GJProtocol_PollingData();  // 触发共迹协议轮询解析ok信号
//            emit delDone_GJProtocol_TrackMap_Point();   // 触发共迹协议经纬度解析ok信号

//        }
//    }
////    if(serialbuffer.contains(receive_Calibration_DynamicSuccess))
////    {
////        uint16_t index = serialbuffer.indexOf(receive_Calibration_DynamicSuccess);
////        if(serialbuffer.size() - index >= receive_GJProtocol_length)
////        {
////            serialbuffer.remove(index, receive_Calibration_DynamicSuccess_length);
////            emit receive_Calibration_DynamicSuccess_head();
////        }
////    }
//    if(serialbuffer.contains(receive_TempCali_DeviceHasSavedData))
//    {
//        uint16_t index = serialbuffer.indexOf(receive_TempCali_DeviceHasSavedData);
//        if(serialbuffer.size() - index >= receive_TempCali_DeviceHasSavedData_length)
//        {
//            emit receive_TempCali_DeviceHasSavedData_head(serialbuffer.mid(index, receive_TempCali_DeviceHasSavedData_length));
//            serialbuffer.remove(index, receive_TempCali_DeviceHasSavedData_length);
//        }
//    }
//    if(serialbuffer_length == serialbuffer.size())  // 通过判断有没有数据被移除，来确定是否全部能解析的都解析ok
//    {
//        return false;
//    }
//    else
//    {
//        return true;
//    }
//}

//void SerialPort::DealHead_GJProtocol_Head(QByteArray data)      // 处理共迹协议
//{
//    for (int i = 0; i < receive_GJProtocol_length; i++) {
//        gjDeviceData.bytes[i] = (uint8_t)data.at(i);
//    }
//    for (int i = 0; i < 8; i++)
//    {
//        gjDevicePollingData.bytes[i+(gjDeviceData.GJDeVice_Msg.PollIndex-1) * 8] = gjDeviceData.GJDeVice_Msg.PollData_u8[i];
//    }
//}

//void SerialPort::Serial_Write(QByteArray data)  // 串口发送
//{
////    qDebug()<<data.toHex();
//    Serial->write(data);
//    QCoreApplication::processEvents();
//}


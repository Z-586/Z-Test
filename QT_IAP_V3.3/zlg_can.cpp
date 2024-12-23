#include "zlg_can.h"

ZLGCan::ZLGCan()
{
    devtype=4;//设备类型USBCAN2
    devind=0;//设备索引号
    res=0;
    canind=0;//CAN通道0
    reftype=0;//参数类型

    QLibrary lib("usbcan.dll");
    if(true==lib.load())
        qDebug()<<"usbcan.dll load ok";

    QLibrary lib2("ControlCAN1.dll");
    if(true==lib2.load())
        qDebug()<<"ContorlCAN1.dll load ok";

    pOpenDevice = (VCI_OpenDevice *)lib.resolve("VCI_OpenDevice");
    pCloseDevice = (VCI_CloseDevice *)lib.resolve("VCI_CloseDevice");
    pInitCAN = (VCI_InitCAN *)lib.resolve("VCI_InitCAN");
    pStartCAN = (VCI_StartCAN *)lib.resolve("VCI_StartCAN");
    pTransmitCAN = (VCI_Transmit *)lib.resolve("VCI_Transmit");
    pReceive = (VCI_Receive *)lib.resolve("VCI_Receive");
    pGetReceiveNum = (VCI_GetReceiveNum *)lib.resolve("VCI_GetReceiveNum");
    pClearBuffer = (VCI_ClearBuffer *)lib.resolve("VCI_ClearBuffer");
    pReadErrInfoCAN = (VCI_ReadErrInfo*)lib.resolve("VCI_ReadErrInfo");
    pResetCAN=(VCI_ResetCAN *)lib.resolve("VCI_ResetCAN");
    pSetReference=(VCI_SetReference *)lib.resolve("VCI_SetReference");
    pReadBoardInfo=(VCI_ReadBoardInfo *)lib.resolve("VCI_ReadBoardInfo");
    pReadCANStatus=(VCI_ReadCANStatus *)lib.resolve("VCI_ReadCANStatus");
}

int ZLGCan::OpenCan(int baud, int no)
{
    QLibrary lib("usbcan.dll");
    if(true==lib.load())
        qDebug()<<"usbcan.dll load ok";

    QLibrary lib2("ControlCAN.dll");
    if(true==lib2.load())
        qDebug()<<"ContorlCAN.dll load ok";

    VCI_ERR_INFO vei;
    int baudADR=0x10000000;//参数有关数据缓冲区地址首指针

    devind = no;
    if(pOpenDevice(devtype,devind,res)==STATUS_ERR )
    {
        if(pReadErrInfoCAN(devtype,devind,canind,&vei)!=STATUS_ERR)
        {
            qDebug()<<"打开失败："<<QString::number(vei.ErrCode,16);
        }
        else
        {
             qDebug()<<"error";
             return 0;
        }
    }
    else
        qDebug()<<"open successed";

    //初始化
    VCI_INIT_CONFIG init_config;
    init_config.Mode=0;//正常模式，1为只听模式
    init_config.Filter=1;//滤波方式，单滤波
    init_config.AccCode=0x00000000;//验收码
    init_config.AccMask=0xFFFFFFFF;//屏蔽码

    if(baud<=50)
    {
        init_config.Timing0 = 0x09; // 50k
        init_config.Timing1 = 0x1C; // 50k
    }
    else if(baud<=100)
    {
        init_config.Timing0 = 0x04; // 100k
        init_config.Timing1 = 0x1C; // 100k
    }
    else if(baud<=125)
    {
        init_config.Timing0 = 0x03; // 125k
        init_config.Timing1 = 0x1C; // 125k
    }
    else if(baud<=250)
    {
        init_config.Timing0 = 0x01; // 250k
        init_config.Timing1 = 0x1C; // 250k
    }
    else if(baud<=500)
    {
        init_config.Timing0 = 0x00; // 500k
        init_config.Timing1 = 0x1C; // 500k
    }
    else
    {
        init_config.Timing0 = 0x00; // 1M
        init_config.Timing1 = 0x14; // 1M
    }

    if(pInitCAN(devtype,devind,canind,&init_config)==STATUS_ERR)
    {
        qDebug("Init Error");
        pCloseDevice(devtype,devind);
        return 0;
    }
    else
        qDebug()<<"Init successed";


    //读取设备信息
    VCI_BOARD_INFO vbi;
    if(pReadBoardInfo(devtype,devind,&vbi)!=STATUS_ERR){
        qDebug()<<"CAN通道数："<<vbi.can_Num;
        qDebug()<<"硬件版本号:"<<vbi.hw_Version;
        qDebug()<<"接口库版本号："<<vbi.in_Version;
        qDebug()<<"中断号"<<vbi.irq_Num;
    }
    //设置设备参数
    if(pSetReference(devtype,devind,canind,reftype,&baudADR)==STATUS_ERR)
    {
        qDebug("set reference error");
        pCloseDevice(devtype,devind);
        return 0;
    }
    //清除缓冲区
    pClearBuffer(devtype,devind,canind);

    //启动设备
    if(pStartCAN(devtype,devind,canind)==STATUS_ERR)
    {
        qDebug()<<"start fail";
        pCloseDevice(devtype,devind);
        return 0;
    }else
        qDebug()<<"start successed";

    return 1;

}

int ZLGCan::CloseCan(void)
{
    pCloseDevice(devtype,devind);
    qDebug()<<"closed";
    return 1;
}

unsigned short  ZLGCan::zlgCanTx0(unsigned long  ID,  unsigned char DLC,    unsigned char *pData)
{
    VCI_CAN_OBJ obj;
    canind = 0;     //通道0

    obj.ID          = ID;
    obj.SendType    = 0;
    obj.RemoteFlag  = 0;
    obj.ExternFlag  = 1;
    obj.DataLen     = DLC;
    for(int i=0;i<DLC;i++)
        obj.Data[i] = pData[i];

    int dw = pTransmitCAN(devtype,devind,canind,&obj,1);

    if(dw==1)   return 1;
    else        return 0;

}

unsigned short  ZLGCan::zlgCanRx0(unsigned long *pID, unsigned char *pDLC,  unsigned char *pData)
{
    VCI_CAN_OBJ     obj;
    canind = 0;         //通道0

    int dw = pReceive(devtype,devind,canind,&obj,1,0);
    if(dw==1)
    {
        *pID    = obj.ID;
        *pDLC   = obj.DataLen;
        for(int i=0;i<obj.DataLen;i++)
             pData[i] = obj.Data[i];
        return  1;
    }
    return  0;
}

unsigned short  ZLGCan::zlgCanTx1(unsigned long  ID,  unsigned char DLC,    unsigned char *pData)
{
    VCI_CAN_OBJ obj;
    canind = 1;     //通道1

    obj.ID          = ID;
    obj.SendType    = 0;
    obj.RemoteFlag  = 0;
    obj.ExternFlag  = 1;
    obj.DataLen     = DLC;
    for(int i=0;i<DLC;i++)
        obj.Data[i] = pData[i];

    int dw = pTransmitCAN(devtype,devind,canind,&obj,1);

    if(dw==1)   return 1;
    else        return 0;

}

unsigned short  ZLGCan::zlgCanRx1(unsigned long *pID, unsigned char *pDLC,  unsigned char *pData)
{
    VCI_CAN_OBJ     obj;
    canind = 1;          //通道1

    int dw = pReceive(devtype,devind,canind,&obj,1,0);
    if(dw==1)
    {
        *pID    = obj.ID;
        *pDLC   = obj.DataLen;
        for(int i=0;i<obj.DataLen;i++)
             pData[i] = obj.Data[i];
        return  1;
    }
    return  0;
}



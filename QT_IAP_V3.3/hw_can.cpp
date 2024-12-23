#include "hw_can.h"

#include <QLibrary>
#include <QDebug>

#include "hw_can.h"

int CanCardNo  = 0;

int HW_CAN::GetCanCardInfo(PVCI_BOARD_INFO1 pInfo)
{
    return VCI_FindUsbDevice(pInfo);
}

int   HW_CAN::CloseCan(void)
{
    return VCI_CloseDevice(4,CanCardNo);
}

int   HW_CAN::OpenCan(int baud, int no)
{
    int dw;
    
    CanCardNo = no;

    qDebug() << "Open Can ......";
    dw  =  VCI_OpenDevice(4,CanCardNo,0);
    if(dw!=1)
    {
        qDebug()<< "Open Can Error!";
        return dw;
    }
    qDebug() << "Open Can OK.";

    VCI_INIT_CONFIG cfg;
    cfg.AccCode = 0xFFFFFFFF;
    cfg.AccMask = 0xFFFFFFFF;
    cfg.Filter  = 0;

    if(baud<=50)
    {
        cfg.Timing0 = 0x09; // 50k
        cfg.Timing1 = 0x1C; // 50k
    }
    else if(baud<=100)
    {
        cfg.Timing0 = 0x04; // 100k
        cfg.Timing1 = 0x1C; // 100k
    }
    else if(baud<=125)
    {
        cfg.Timing0 = 0x03; // 125k
        cfg.Timing1 = 0x1C; // 125k
    }
    else if(baud<=250)
    {
        cfg.Timing0 = 0x01; // 250k
        cfg.Timing1 = 0x1C; // 250k
    }
    else if(baud<=500)
    {
        cfg.Timing0 = 0x00; // 500k
        cfg.Timing1 = 0x1C; // 500k
    }
    else
    {
        cfg.Timing0 = 0x00; // 1M
        cfg.Timing1 = 0x14; // 1M
    }
    cfg.Mode    = 0;
    dw = VCI_InitCAN(4,CanCardNo,0,&cfg);
    if(dw!=1)
    {
        CloseCan();
        return dw;
    }

    dw = VCI_StartCAN(4,CanCardNo,0);
    if(dw!=1)
    {
        CloseCan();
        return dw;
    }

    dw = VCI_InitCAN(4,CanCardNo,1,&cfg);
    if(dw!=1)
    {
        CloseCan();
        return dw;
    }

    dw = VCI_StartCAN(4,CanCardNo,1);
    if(dw!=1)
    {
        CloseCan();
        return dw;
    }

    qDebug() << "Start Can OK!";
    return  dw;
}

unsigned short   CanTx0(unsigned long  ID,  unsigned char DLC, unsigned char *pData)
{
    VCI_CAN_OBJ     obj;

    obj.ID          = ID;
    obj.SendType    = 0;
    obj.RemoteFlag  = 0;
    obj.ExternFlag  = 1;
    obj.DataLen     = DLC;
    for(int i=0;i<DLC;i++)
        obj.Data[i] = pData[i];

    int dw =  VCI_Transmit(4,CanCardNo,0,&obj,1);
    if(dw==1)   return 1;
    else        return 0;
}

unsigned short   CanRx0(unsigned long *pID, unsigned char *pDLC, unsigned char *pData)
{
    VCI_CAN_OBJ     obj;


    int dw = VCI_Receive(4,CanCardNo,0,&obj,1,0);
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

unsigned short   CanTx1(unsigned long  ID,  unsigned char DLC, unsigned char *pData)
{
    VCI_CAN_OBJ     obj;


    obj.ID          = ID;
    obj.SendType    = 0;
    obj.RemoteFlag  = 0;
    obj.ExternFlag  = 1;
    obj.DataLen     = DLC;
    for(int i=0;i<DLC;i++)
        obj.Data[i] = pData[i];

    int dw =  VCI_Transmit(4,CanCardNo,1,&obj,1);
    if(dw==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

unsigned short   CanRx1(unsigned long *pID, unsigned char *pDLC, unsigned char *pData)
{
    VCI_CAN_OBJ     obj;

    int dw = VCI_Receive(4,CanCardNo,1,&obj,1,0);
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


#ifndef ZLG_CAN_H
#define ZLG_CAN_H

#include "Controlcan.h"
#include <QWidget>
#include <QLibrary>
#include <QDebug>

class ZLGCan
{
public:
    ZLGCan();
public:
    typedef DWORD(__stdcall VCI_OpenDevice)(DWORD,DWORD,DWORD);
    typedef DWORD(__stdcall VCI_ResetCAN)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);
    typedef DWORD(__stdcall VCI_CloseDevice)(DWORD DeviceType,DWORD DeviceInd);
    typedef DWORD(__stdcall VCI_InitCAN)(DWORD DeviceType, DWORD DeviceInd, DWORD CANInd, PVCI_INIT_CONFIG pInitConfig);
    typedef DWORD(__stdcall VCI_StartCAN)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);
    typedef ULONG(__stdcall VCI_Transmit)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,PVCI_CAN_OBJ pSend,ULONG Len);

    typedef ULONG(__stdcall VCI_Receive)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,PVCI_CAN_OBJ pReceive,ULONG Len,INT WaitTime/*=-1*/);
    typedef ULONG(__stdcall VCI_GetReceiveNum)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);
    typedef DWORD(__stdcall VCI_ClearBuffer)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);
    typedef DWORD(__stdcall VCI_ReadErrInfo)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,PVCI_ERR_INFO pErrInfo);
    typedef DWORD(__stdcall VCI_ReadCANStatus)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,PVCI_CAN_STATUS pCANStatus);
    typedef DWORD(__stdcall VCI_SetReference)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,DWORD RefType,PVOID pData);
    typedef DWORD(__stdcall VCI_ReadBoardInfo)(DWORD DeviceType,DWORD DeviceInd,PVCI_BOARD_INFO pInfo);

    int devtype;//设备类型USBCAN2
    int devind;//设备索引号
    int res;//保留参数，通常为0
    int canind;//第几路can
    int reftype;//参数类型

public:
    VCI_OpenDevice *pOpenDevice;
    VCI_ResetCAN *pResetCAN;
    VCI_CloseDevice *pCloseDevice;
    VCI_InitCAN *pInitCAN;
    VCI_StartCAN *pStartCAN;
    VCI_Transmit *pTransmitCAN;
    VCI_Receive *pReceive;
    VCI_GetReceiveNum *pGetReceiveNum;
    VCI_ClearBuffer *pClearBuffer;
    VCI_ReadErrInfo *pReadErrInfoCAN;
    VCI_ReadCANStatus *pReadCANStatus;
    VCI_SetReference *pSetReference;
    VCI_ReadBoardInfo *pReadBoardInfo;

public:
    int             CloseCan(void);
    int             OpenCan(int baud, int no);
    unsigned short  zlgCanTx0(unsigned long  ID,  unsigned char DLC,    unsigned char *pData);
    unsigned short  zlgCanRx0(unsigned long *pID, unsigned char *pDLC,  unsigned char *pData);

    unsigned short  zlgCanTx1(unsigned long  ID,  unsigned char DLC,    unsigned char *pData);
    unsigned short  zlgCanRx1(unsigned long *pID, unsigned char *pDLC,  unsigned char *pData);
};




#endif // HW_CAN_H

#ifndef HW_CAN_H
#define HW_CAN_H

#include "ControlCAN.h"

class HW_CAN
{
public:
    int             GetCanCardInfo(PVCI_BOARD_INFO1 pInfo);
    int             OpenCan(int baud, int no);
    void            CanClear(void);
    int             CloseCan(void);
};

unsigned short  CanTx0(unsigned long  ID,  unsigned char DLC,    unsigned char *pData);
unsigned short  CanRx0(unsigned long *pID, unsigned char *pDLC,  unsigned char *pData);

unsigned short  CanTx1(unsigned long  ID,  unsigned char DLC,    unsigned char *pData);
unsigned short  CanRx1(unsigned long *pID, unsigned char *pDLC,  unsigned char *pData);

#endif // HW_CAN_H

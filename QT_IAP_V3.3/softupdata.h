#ifndef SOFTUPDATA_H
#define SOFTUPDATA_H

#include    <QWidget>
#include    <stdint.h>
#include    <stdbool.h>
#include    "AES/aestools.h"



namespace Ui
{
    class softupdata;
}


typedef struct
{
    uint16_t pages;
    uint16_t page;
    uint8_t  pData[128];
}  vcu_Update_Struct;

typedef struct _update_struct_can
{
    uint16_t pages;
    uint16_t page;
    uint8_t  pData[4];
}update_struct_can;


typedef struct _update_struct_usb
{
    uint16_t pages;
    uint16_t page;
    uint8_t  pData[58];
}update_struct_usb;

class softupdata : public QWidget
{
    Q_OBJECT

public:
    explicit softupdata(QWidget *parent = 0);
    ~softupdata();

    void    Load_File(void);
    void    Update_Preview();

    bool    SetRxFrame( unsigned char *pData, unsigned short  Len);
    bool    softupdata_GetTxFrame(unsigned char *pData, unsigned short *Len);
    bool    softupdata_SetTxResult(unsigned char   Des,  unsigned long   PGN24, int Result);

    void    on_Hex_path_clicked();
    void    addInformationShow(QString dat);

    bool    softupdata_GetTxFrame_Can(uint32_t *CanID, unsigned char *pData, unsigned short *Len);
    bool    softupdata_GetTxFrame_Usb( unsigned char *pData, unsigned short *Len);

    bool    SetRxFrame_Can( unsigned int CanId, unsigned short  Len , unsigned char *pData);
    bool    SetRxFrame_Usb(  unsigned short  Len,unsigned char *pData );



private slots:
    void on_updata_route_select_clicked();
    void on_Update_Run_clicked();
    uint16_t crc_16(uint8_t *data, uint16_t len);

    void on_Cancel_update_clicked();

private:
    Ui::softupdata *ui;
    AesTools AesUser;

    QString                 filePath;
    unsigned long           DelayMs;
    unsigned long           LastMs;
    uint16_t                LastStatus;


    char            encryption_Flag=0;    // 密文标志0：明文  1：密文
    char            HexBuf[1024*1024];
    unsigned long   LenHex;
    unsigned char   BinBuf[1024*1024];
    unsigned long   LenBin=0;
    long            StartAddr=-1;


    uint16_t                        nPage = 0;
    uint16_t                        pages = 0;
    bool                            bUpdateFinished = false;
    char                            bUpdate_flag;
    vcu_Update_Struct               Update[8192];     // 支持的文件大小为8K * 128 = 1024K

    int nPage_can =0;
    int pages_can =0;
    bool                        bUpdateFinished_can = false;
    char                        bUpdate_flag_can ;
    update_struct_can           Update_Can[64*1024]; //支持的文件大小为64K *4 = 256K

    unsigned short      (*CanTx[2])(unsigned long  ID,  unsigned char DLC,    unsigned char *pData);
    unsigned short      (*CanRx[2])(unsigned long *pID, unsigned char *pDLC,  unsigned char *pData);


    void    Run(void);
    void    updata_now_state(void);
    void    updata_now_state_can(void);
    void    updata_now_state_usb(void);
    void    saveToBin(QString FileName,char *dat,uint32_t len);
};

#endif // SOFTUPDATA_H

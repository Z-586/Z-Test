#ifndef WRITECALI_H
#define WRITECALI_H

#include <QDialog>

namespace Ui {
class WriteCali;
}

typedef struct _calidata_struct_can
{
    uint16_t pages;
    uint16_t page;
    uint8_t  pData[4];
}calidata_struct_can;

typedef union _calidata_buf_can
{
    calidata_struct_can msg;
    uint8_t  byte[8];
}calidata_buf_can;

class WriteCali : public QDialog
{
    Q_OBJECT

public:
    explicit WriteCali(QWidget *parent = nullptr);
    ~WriteCali();

    bool writeCaliData_GetTxFrame_Can(uint32_t *CanID, unsigned char *pData, unsigned short *Len);
    bool writeCaliData_SetRxFrame_Can( unsigned int CanId, unsigned short  Len,unsigned char *pData );
    void Delay(int msec);

private:
    Ui::WriteCali *ui;

    int caliData_nPage_can =0;
    int caliData_pages_can =0;

    unsigned long           DelayMs;
    unsigned long           LastMs;

public:
    typedef struct TempCali_Msg
    {
        float Temp;
        float AccBias[3];
        float GyroBias[3];
        float Matrix_Ka[9];
        float Matrix_Kg[9];
        float Matrix_G[9];
    }TempCali_Msg_t;

    typedef union TempCali_MsgBuf
    {
        TempCali_Msg_t TempCali_Msg;
        uint8_t bytes[136] = {0};
    }TempCali_MsgBuf_t;

private:

    QString fileName_path = "";
    unsigned char   all_cali_data_bin[50 * 136];

    int TempCali_File_RightData_number = 0;     // 文件里正确温度的个数
    int TempCali_File_ErrorData_number = 0;     // 文件里错误数据的个数
    int TempCali_File_OverflowData_number = 0;  // 文件里，温度点个数超出50个的数量

    int TempCali_ShouldSendData_number = 0;     // 当前应该向设备发送的温度编号

    TempCali_MsgBuf_t TempCaliData[50];     //

    calidata_struct_can           wirteCaliData_Can[50 * 136 / 4];



public:


private:
    void Init();    // 初始化函数
    void TempCali_VariablesInit();  // 温度标定的变量初始化函数
    void TempCali_ButtonState(bool Read, bool Send, bool Stop); // 所有按钮使能控制
    void Read_TempCali_File();      // 读稳定标定数据
    void FindTrueData_TempCali_File(QString FileContent_String);// 寻找正确数据
    void ProcessTrueData_TempCali_File(QStringList FileContent_StringList); // 开始处理正确数据
    void Display_Msg_TempCali_File();   // 显示结果

    void Send_TempCali_Data();  // 发送温度标定数据
    void DisplayState_Send_TempCali_Data(); // 展示发送的状态
    void StopSend_TempCali_Data();  // 停止发送

    void Display_TempCali_DeviceHasSavedData(int num);  // 根据板子反馈消息，展示已经存在板子里的温度标定数据
    void Display_TempCali_PrePage();    // 上一个温度的信息
    void Display_TempCali_NextPage();   // 下一个温度的信息


private slots:
    // 所有按钮信号槽
    void on_PushButton_TempCali_ReadFile_clicked();
    void on_PushButton_TempCali_SendFile_clicked();
    void on_PushButton_TempCali_StopSendFile_clicked();
    void on_PushButton_pre_clicked();
    void on_PushButton_next_clicked();
};

#endif // WRITECALI_H

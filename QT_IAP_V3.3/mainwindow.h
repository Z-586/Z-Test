#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>

#include "setparameter.h"  // 参数设置
#include "setboard.h"      // 主板选择
#include "hidapi.h"
#include "hw_can.h"
#include "zlg_can.h"
#include "about.h"
#include "author.h"
#include "writecali.h"

extern int RunFlag;
extern HW_CAN CANalyst;
extern int canBaud;
extern int can_index;


namespace Ui {
class MainWindow;
}

//typedef struct parameterSetStruct
//{
//  bool uartEn;                      // 串口通讯
//  QStringList portNumber;           // 端口号

//  bool canEn;        // CAN通讯
//  int  canChannel;   // CAN通道

//  bool usbEn;      // USB通讯
//  bool networkEn;  // 网络通讯

//}_parameterSetStruct;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);

    unsigned char    RxBuf[1024];   // 接收串口数据
    int             RxCnt =0;

public:

    ZLGCan zlgCan;

private slots:   
    void getCommData();
    void on_actionSetting_triggered();
    void on_pushButtonConnect_clicked();
    void on_action_Designer_triggered();
    void on_action_help_triggered();
    void on_RefreshCanCard_clicked();

    void on_actionabout_triggered();

    void on_action_TempCali_triggered();

signals:
    void parameterSetPress();
    void boardSetPress(_boardSetEnum dat);

private:
    Ui::MainWindow *ui;    
    hid_device *handle;

    QByteArray UartRxDate;


    QStringList  initComm();
    bool isOpen();
    void showData(QString data);
    void parameterInit(QStringList Port);
    int     openUart(void);
    int     closeUart(void);

    QStringList  ComUpdate(void);  // 扫描端口号
    // 更新状态栏
    void updateStatusBar(void);

    setParameter *parameterSet;
    about       *aboutSoft;
    author      *aboutAuthor;
    QLabel       *statusBarInfor;

    _parameterSetStruct  parameterStruct;



public:
    QSerialPort *serialport;
};

#endif // MAINWINDOW_H

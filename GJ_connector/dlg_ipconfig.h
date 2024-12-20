#ifndef DLG_IPCONFIG_H
#define DLG_IPCONFIG_H

#include <QDialog>
#include "MainWindow.h"
namespace  {
    const int AA44CC5B_MSG_LEN{6};
}

namespace Ui {
class dlg_ipConfig;
}

class Dlg_ipConfig : public QDialog
{
    Q_OBJECT
    typedef struct
     {
         uint8_t IP[4];
         uint16_t port;
     }IPData_t;

     typedef union IPData_Buf
     {
         IPData_t IPData;
         uint8_t buf[AA44CC5B_MSG_LEN] = {0};
     }IPData_Buf_t;

public:
    explicit Dlg_ipConfig(QWidget *parent = nullptr);
    ~Dlg_ipConfig();

signals:
    // 串口调用发送信号
    void sig_Serial_Write(QByteArray);

public slots:
    void slot_receiveACK_StaticIPPort_head();

private:
    Ui::dlg_ipConfig *ui;
    QTimer* pCheckTimer_ = nullptr;


};

#endif // DLG_IPCONFIG_H

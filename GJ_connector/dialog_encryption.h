#ifndef DIALOG_ENCRYPTION_H
#define DIALOG_ENCRYPTION_H

#include "MainWindow.h"

namespace Ui {
class Dialog_Encryption;
}

class Dialog_Encryption : public QDialog
{
        Q_OBJECT

public:
        explicit Dialog_Encryption(QWidget *parent = nullptr);
        ~Dialog_Encryption();
public:
private:
        Ui::Dialog_Encryption *ui;

        uint8_t key = 49;       // 与底层共同持有的钥匙1，改的时候，底层也需要改

public:
private:
    void Dialog_EncryptionInit();       // 初始化函数
    void Encryption(QString str);       // 加密函数
    void Decryption(QString str);       // 解密函数，测试用的，输入是加密获得的超长字符串，已移植底层
    QString GetEncryptionString();      // 获取需要加密的字符串（SN+到期时间）
    bool IsAdministrator(QString str);  // 特殊操作时，解锁管理员功能
public slots:



private slots:
    // 所有按钮信号槽
    void on_PushButton_Encryption_clicked();
    void on_PushButton_SendActiveCode_clicked();

signals:
    void AdministratorMode();   // 解锁管理员功能信号
    void Serial_Write(QByteArray);  // 串口调用发送信号
};


#endif // DIALOG_ENCRYPTION_H

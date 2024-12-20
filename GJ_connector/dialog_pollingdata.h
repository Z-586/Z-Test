#ifndef DIALOG_POLLINGDATA_H
#define DIALOG_POLLINGDATA_H

#include <MainWindow.h>

namespace Ui {
class Dialog_PollingData;
}

class Dialog_PollingData : public QDialog
{
        Q_OBJECT

public:
        explicit Dialog_PollingData(QWidget *parent = 0);
        ~Dialog_PollingData();

public:

private:
    Ui::Dialog_PollingData *ui;

public:

private:
    void Dialog_PollingDataInit();  // 初始化函数
    void Display_PollingData(); // 显示轮询数据

public slots:
    // 串口将轮询数据处理完后发的信号，以便实时更新
    void delDone_GJProtocol_PollingData();

};

#endif // DIALOG_POLLINGDATA_H

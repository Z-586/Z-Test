#ifndef DIALOG_TRACKMAP_H
#define DIALOG_TRACKMAP_H

#include "qcustomplot.h"
//#include "SerialPort.h"
#include "MainWindow.h"

namespace Ui {
class Dialog_TrackMap;
}

class Dialog_TrackMap : public QDialog
{
        Q_OBJECT

public:
        explicit Dialog_TrackMap(QWidget *parent = nullptr);
        ~Dialog_TrackMap();

public:

private:
        Ui::Dialog_TrackMap *ui;
        QCPCurve *qcurve;

        int32_t base_Lat = 0, base_Lon = 0; // 第一个点坐标
        int32_t last_Lat = 0, last_Lon = 0; // 上一个点的坐标
        int point_number = 0;               // 每计数point_number画一个点

public:

private:
        void Dialog_TrackMap_Init();        // 初始化函数
        void setBase_TrackMap_Point(int32_t Lat, int32_t Lon);  // 获取第一个点的值
        void Updata_TrackMap_Point(double Lat, double Lon);     // 更新图形

public slots:
        void delDone_GJProtocol_TrackMap_Point();   // 当经共迹协议解析好以后，触发该函数

};

#endif // DIALOG_TRACKMAP_H

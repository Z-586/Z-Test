#include "dialog_trackmap.h"
#include "ui_dialog_trackmap.h"
#include "./global/globalsetting.h"
namespace  {
    GlobalSetting *pGlobalSetting = GlobalSetting::getInstance();
}

Dialog_TrackMap::Dialog_TrackMap(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::Dialog_TrackMap)
{
    ui->setupUi(this);
    Dialog_TrackMap_Init();
}

Dialog_TrackMap::~Dialog_TrackMap()
{
    delete ui;
}

void Dialog_TrackMap::Dialog_TrackMap_Init()    // 初始化函数gjDeviceData
{
    this->setWindowTitle("轨迹图");

    QWidget::setAttribute(Qt::WA_QuitOnClose,false);     // 所有子窗口要写false
    QWidget::setAttribute(Qt::WA_DeleteOnClose);     // 所有子窗口要写false
    this->setWindowFlags(Qt::Dialog | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);

    ui->QCustomPlot_TrackMap->xAxis->setRange(-150,150);
    ui->QCustomPlot_TrackMap->yAxis->setRange(-150,150);
    ui->QCustomPlot_TrackMap->setInteraction(QCP::iRangeDrag,true);//鼠标单击拖动
    ui->QCustomPlot_TrackMap->setInteraction(QCP::iRangeZoom,true);//滚轮滑动缩放
    qcurve = new QCPCurve(ui->QCustomPlot_TrackMap->xAxis,ui->QCustomPlot_TrackMap->yAxis);
    qcurve->setAntialiasedFill(true); //设置抗锯齿
}

void Dialog_TrackMap::setBase_TrackMap_Point(int32_t Lat, int32_t Lon)  // 获取第一个点的值
{
     base_Lat = Lat;
     base_Lon = Lon;
}

void Dialog_TrackMap::Updata_TrackMap_Point(double Lat, double Lon)     // 更新图形
{
    qcurve->addData(Lat, Lon);
    ui->QCustomPlot_TrackMap->replot();
}

void Dialog_TrackMap::delDone_GJProtocol_TrackMap_Point()   // 当经共迹协议解析好以后，触发该函数
{
    int32_t Lat = 0;
    int32_t Lon = 0;
    QVariant msgBufVariant = pGlobalSetting->getMsgBuf();
    if (msgBufVariant.canConvert<GJDeVice_MsgBuf_920Vertion*>())
    {

        GJDeVice_MsgBuf_920Vertion *msgBuf920 = msgBufVariant.value<GJDeVice_MsgBuf_920Vertion*>();
        Lat = msgBuf920->GJDeVice_Msg.Latitude;
        Lon = msgBuf920->GJDeVice_Msg.Longitude;

    }
    else if (msgBufVariant.canConvert<GJDeVice_MsgBuf_1000Vertion*>())
    {
        GJDeVice_MsgBuf_1000Vertion *msgBuf1000 = msgBufVariant.value<GJDeVice_MsgBuf_1000Vertion*>();
        Lat = msgBuf1000->GJDeVice_Msg.Latitude;
        Lon = msgBuf1000->GJDeVice_Msg.Longitude;
    }
    if(Lat != 0 && Lon != 0)
    {
        if(base_Lat == 0 && base_Lon == 0)  // 判断是否是第一个点
        {
            setBase_TrackMap_Point(Lat, Lon);
            Updata_TrackMap_Point(0, 0);
        }

        point_number++;
        if(point_number % 20 == 0)  // 每20个点画一次
        {
            point_number = 0;
            if(Lat != last_Lat || Lon != last_Lon)  // 当点有变化时进函数
            {
                last_Lat = Lat;
                last_Lon = Lon;

                double Lat_Relative_Position, Lon_Relative_Position;
                Lat_Relative_Position = (Lat - base_Lat) * RATIO_02 * (double)Pos_ratio_lati;//获得当前x相对坐标
                Lon_Relative_Position = (Lon - base_Lon) * RATIO_03 * (double)Pos_ratio_longi;//获得当前y相对坐标

                Updata_TrackMap_Point(Lon_Relative_Position, Lat_Relative_Position);    // 更新点
            }
        }
    }
}



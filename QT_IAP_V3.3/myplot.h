#ifndef MYPLOT_H
#define MYPLOT_H

#include <QWidget>
#include <QRadioButton>
#include "qcustomplot.h"
#include "save.h"


#define  MaxPoints  (9000L * 60 * 15)
#define  MaxCurves  (2)

#define MaxShowPoints   500
#define MaxShowCurves   2


namespace Ui {
class MyPlot;
}

class MyPlot : public QWidget
{
    Q_OBJECT

public:
    explicit MyPlot(QWidget *parent = nullptr);
    ~MyPlot();

    float   showDates[MaxShowCurves][MaxShowPoints];
    float   CurDates[MaxCurves][MaxPoints];
    
    uint32_t TimeDate[MaxPoints];

    bool    CurVisable[MaxCurves];
    QString CurName[MaxCurves];
    int     Points;     // 曲线点数
    int     CurNum;     // 曲线条数
    int     MaxX, MinX;
    int     MaxYLeft, MinYLeft;

    int     ShowFlag =1;    // 显示状态
    int     SaveFlag =1;

    int     ShowCnt  =0;
    int     SaveCnt  =0;

    void    WriteDataInBuf(unsigned char *dat,uint32_t len);
    void    PositionChanged(void);

private slots:
//    void on_pushButton_8_clicked(bool checked);
    void on_PositionValue_valueChanged(int arg1);
    void on_WidthValue_valueChanged(int arg1);
    void on_LeftYMinValue_valueChanged(int arg1);
    void on_LeftYMaxValue_valueChanged(int arg1);


    void on_ShowSave_clicked();
    void on_ShowLast_clicked();
    void on_MoveRight_clicked();
    void on_MoveLeft_clicked();
    void on_ShowSmall_clicked();
    void on_ShowBig_clicked();

    void on_radioButton_1_clicked(bool checked);

    void on_radioButton_2_clicked(bool checked);

    void on_ShowAll_clicked();

    void on_ShowFlag_clicked(bool checked);

    void on_SaveFlag_clicked(bool checked);

private:
    Ui::MyPlot *ui;
    QCPGraph   *pGraph[MaxCurves];
    save        *saveClass;


    void    RePlot(bool bInit,int DataChannel);
    void    test(void);
    void    dataToDataBase(int Cnt);

    int    saveNumber;
};

#endif // MYPLOT_H

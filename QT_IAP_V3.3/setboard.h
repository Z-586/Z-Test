#ifndef SETBOARD_H
#define SETBOARD_H

#include <QDialog>


typedef enum   boardSetEnum
{
    STM32F103=0,
    STM32F407=1,
}_boardSetEnum;

namespace Ui {
class setBoard;
}

class setBoard : public QDialog
{
    Q_OBJECT

public:
    explicit setBoard(QWidget *parent = nullptr);
    ~setBoard();

    _boardSetEnum           boardNewType;      // 主板类型
    _boardSetEnum           CfgFromUi(void);

private:
    Ui::setBoard *ui;    


protected :
    void closeEvent(QCloseEvent *e);

public slots:
     void CfgToUi(_boardSetEnum dat);
};

#endif // SETBOARD_H

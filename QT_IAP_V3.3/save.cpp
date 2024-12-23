#include "save.h"
#include "ui_save.h"


save::save(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::save)
{
    ui->setupUi(this);
    ui->dateTimeEdit_start->setDateTime( QDateTime::currentDateTime() );
    ui->dateTimeEdit_end->setDateTime( QDateTime::currentDateTime() );

    //打开数据库
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("saveManager.db");
    if (!m_db.open())
    {
        qDebug()<<"save database open fail！\r\n";
    }
    else qDebug()<<"save database open successful! \r\n";
    QSqlQuery query;

    query.exec("create table savetable (时间 Datetime,批次号 int , 序号 int, 通道1数据 int, 通道2数据 int)");  // 创建一个表

    m_DBTableName = "savetable";

    m_model = new QSqlTableModel(this, m_db);
    m_model->setTable(m_DBTableName);
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit); //手动提交后才修改
    m_model->select();

    ui->m_TabView->setEditTriggers(QAbstractItemView::NoEditTriggers);	//设置内容不可编辑
    /*************模型关联视图*******************/
    ui->m_TabView->setModel(m_model);

    /*************选中行为为整行选中*************/
    ui->m_TabView->setSelectionBehavior(QAbstractItemView::SelectRows);
}


// 0 :失败  1：成功
int save::insert_Data(record *dat)
{
    int row = m_model->rowCount();
    m_model->insertRow(row);

    m_model->setData(m_model->index(row, 0), dat->time.toString("yyyyMMddhhmmss"));

    m_model->setData(m_model->index(row, 1), dat->ID);      // 批次号
    m_model->setData(m_model->index(row, 2), dat->rxNumber);// 序号
    m_model->setData(m_model->index(row, 3), dat->Dat1);
    m_model->setData(m_model->index(row, 4), dat->Dat2);

    if( m_model->submitAll() != true)	//提交修改
    {
        qDebug()<<"数据插入失败！";
        return 0;
    }
    return 1;
}
save::~save()
{
    delete ui;
}

void save::on_B_showAll_clicked()
{
    m_model->setTable("savetable");      // 重新关联表
    m_model->select();                   // 这样才能再次显示整个表的内容
}

// 指定字符串查找，指定类型
void save::Serch_On_type(QString type, QString  toFind)
{
    m_model->setTable("savetable");      // 重新关联表
    m_model->setFilter(type + "=\'" + toFind + "\'");
    m_model->select();
}


void save::on_B_Serch_clicked()
{
    QString toFind = ui->lineEdit_serchID->text();
    QString ID = m_model->headerData(1, Qt::Horizontal).toString();
    Serch_On_type(ID,toFind);
}

void save::on_Btn_Serch_time_clicked()
{
    QDateTime time_start = ui->dateTimeEdit_start->dateTime();
    QDateTime time_end   = ui->dateTimeEdit_end->dateTime();

    QString time_start_QStr  = time_start.toString("yyyyMMddhhmmss");
    QString time_end_QStr    = time_end.toString("yyyyMMddhhmmss");

    if( time_start > time_end)
    {
         QMessageBox::critical(this,"提示","结束时间必须大于开始时间！","确定");
         return  ;
    }
    QString ID = m_model->headerData(0, Qt::Horizontal).toString();

    qDebug()<<"time start is:"<<time_start_QStr<<"time start is:"<<time_end_QStr;
    m_model->setFilter(QString("时间 > %1 and 时间 < %2").arg(time_start_QStr).arg(time_end_QStr));
    m_model->select();
}

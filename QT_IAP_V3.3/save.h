#ifndef SAVE_H
#define SAVE_H

#include <QWidget>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QTableView>

#include <QDebug>
#include <QMessageBox>
#include <header.h>

namespace Ui {
class save;
}

class save : public QWidget
{
    Q_OBJECT

public:
    explicit save(QWidget *parent = nullptr);
    ~save();


    int insert_Data(record *dat);

private slots:
    void on_B_showAll_clicked();

    void on_B_Serch_clicked();

    void on_Btn_Serch_time_clicked();

private:
    Ui::save *ui;

    QSqlDatabase m_db;
    QString m_DBName;
    QString m_DBTableName;
    int m_operator;
    QSqlTableModel* m_model;


    void Serch_On_type(QString type, QString  toFind);

};

#endif // SAVE_H

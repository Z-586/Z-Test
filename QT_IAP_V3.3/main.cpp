#include "mainwindow.h"
#include <QApplication>
#include <QDate>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    static QDate buildDate = QLocale(QLocale::English).toDate(QString(__DATE__).replace("  "," 0"),"MMM dd yyyy");
    QString     DateStr = buildDate.toString("yyyy-MM-dd");
    QString     Title = QString("IAP_上位机版本") + DateStr;


    w.setWindowTitle(Title);
    w.show();

    return a.exec();
}




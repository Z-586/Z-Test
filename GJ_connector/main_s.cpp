#include "MainWindow.h"
#include <QApplication>
#include "dlg_selectprojectmodel.h"
#include "./global/GJ_Protocol.h"

static void loadStyleSheet(const QString &qssFilePath) {
    QFile file(qssFilePath);
    if (!file.exists()) {
        qDebug() << "QSS file not found:" << qssFilePath;
        return;
    }

    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QString::fromUtf8(file.readAll());
        //qApp->setStyleSheet(styleSheet);
        file.close();
        qDebug() << "QSS file loaded successfully:" << qssFilePath;
    } else {
        qDebug() << "Failed to open QSS file:" << qssFilePath;
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //自定义信号和槽
    qRegisterMetaType<GJDeVice_MsgBuf_1000*>("GJDeVice_MsgBuf_1000Vertion*");
    qRegisterMetaType<GJDeVice_MsgBuf_920Vertion*>("GJDeVice_MsgBuf_920Vertion*");
    qRegisterMetaType<GJDeVice_Dynamic_MsgBuf_t*>("GJDeVice_Dynamic_MsgBuf_t*");
    //qRegisterMetaType<GJDeVice_MsgBuf_1000>("GJDeVice_MsgBuf_1000*");
    MainWindow w;
    Dlg_SelectProjectModel dlg_SelectProjectModel;
    if (dlg_SelectProjectModel.exec() == QDialog::Accepted)
    {
        w.setVSMS1000Visible();
        loadStyleSheet(":/Image/style.qss");
        w.show();
        return a.exec();
    }
    return 0;
}

QT          += core gui

QT          += serialport

QT          += widgets printsupport

QT          +=charts


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

RC_ICONS = gongjiV2.ico
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

UI_DIR += ./moc_ui

msvc {
    msvc:QMAKE_CXXFLAGS += -execution-charset:utf-8
    msvc:QMAKE_CXXFLAGS += -source-charset:utf-8
}

SOURCES += \
    MainWindow.cpp \
    SerialDataSave.cpp \
    SerialPort.cpp \
    base_function.cpp \
    dialog_advanced.cpp \
    dialog_calibration.cpp \
    dialog_customcan.cpp \
    dialog_encryption.cpp \
    dialog_firmware.cpp \
    dialog_pollingdata.cpp \
    dialog_protocolchange.cpp \
    dialog_tempcali.cpp \
    dialog_trackmap.cpp \
    dialog_versionmsg.cpp \
    dlg_ipconfig.cpp \
    dlg_selectprojectmodel.cpp \
    global/globalsetting.cpp \
    main_s.cpp \
    qcustomplot.cpp \
    workerthread.cpp

HEADERS += \
    MainWindow.h \
    SerialDataSave.h \
    SerialPort.h \
    base_function.h \
    constant.h \
    dialog_advanced.h \
    dialog_calibration.h \
    dialog_customcan.h \
    dialog_encryption.h \
    dialog_firmware.h \
    dialog_pollingdata.h \
    dialog_protocolchange.h \
    dialog_tempcali.h \
    dialog_trackmap.h \
    dialog_versionmsg.h \
    dlg_ipconfig.h \
    dlg_selectprojectmodel.h \
    global/GJ_Protocol.h \
    global/globalsetting.h \
    qcustomplot.h \ \
    workerthread.h

FORMS += \
    GJMainWindow.ui \
    MainWindow.ui \
    dialog_advanced.ui \
    dialog_calibration.ui \
    dialog_customcan.ui \
    dialog_encryption.ui \
    dialog_firmware.ui \
    dialog_pollingdata.ui \
    dialog_protocolchange.ui \
    dialog_tempcali.ui \
    dialog_trackmap.ui \
    dialog_versionmsg.ui \
    dlg_ipconfig.ui \
    dlg_protocol.ui \
    dlg_selectprojectmodel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#DISTFILES += \
#    Image/logo.jpg

#RESOURCES += \
#    tjlogo.qrc

RESOURCES += \
    resource.qrc


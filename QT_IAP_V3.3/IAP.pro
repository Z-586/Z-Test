#-------------------------------------------------
#
# Project created by QtCreator 2019-10-17T16:02:06
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport
QT       += sql
QT       += serialport

RC_ICONS = myico.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IAP
TEMPLATE = app



# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        AES/aes.cpp \
        AES/aestools.cpp \
        about.cpp \
        author.cpp \
        hw_can.cpp \
        main.cpp \
        mainwindow.cpp \
        set.cpp \
        setparameter.cpp \
        softupdata.cpp \
        help.cpp \
        writecali.cpp \
        zlg_can.cpp

HEADERS += \
        AES/aes.h \
        AES/aestools.h \
        about.h \
        author.h \
        hidapi.h \
        mainwindow.h \
        set.h \
        setparameter.h \
        softupdata.h \
        help.h \
        writecali.h \
        zlg_can.h \
        hw_can.h \
        ControlCAN.h

FORMS += \
        about.ui \
        author.ui \
        mainwindow.ui \
        setparameter.ui \
        softupdata.ui \
        help.ui \
        writecali.ui


unix|win32: LIBS += -L$$PWD/./Lib/ -lControlCAN
unix|win32: LIBS += -L$$PWD/./Lib/ -lControlCAN1


INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


#RESOURCES += \
#    ../../../../../TYAD-4206/Modbus_Debug_Qt/picture/picture.qrc \
#    pic.qrc

RESOURCES += \
    pic.qrc

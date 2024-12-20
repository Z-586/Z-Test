/****************************************************************************
** Meta object code from reading C++ file 'SerialPort.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../SerialPort.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SerialPort.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialPort_t {
    QByteArrayData data[42];
    char stringdata0[1371];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPort_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPort_t qt_meta_stringdata_SerialPort = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SerialPort"
QT_MOC_LITERAL(1, 11, 11), // "delDoneData"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "data"
QT_MOC_LITERAL(4, 29, 23), // "delDone_GJProtocol_Data"
QT_MOC_LITERAL(5, 53, 30), // "delDone_GJProtocol_PollingData"
QT_MOC_LITERAL(6, 84, 33), // "delDone_GJProtocol_TrackMap_P..."
QT_MOC_LITERAL(7, 118, 34), // "receive_Firmware_PleaseUpdata..."
QT_MOC_LITERAL(8, 153, 38), // "receive_Firmware_PleaseWaitUp..."
QT_MOC_LITERAL(9, 192, 34), // "receive_Firmware_ReceiveError..."
QT_MOC_LITERAL(10, 227, 31), // "receive_Firmware_FileError_head"
QT_MOC_LITERAL(11, 259, 33), // "receive_Firmware_UpdataError_..."
QT_MOC_LITERAL(12, 293, 35), // "receive_Firmware_UpdataSucces..."
QT_MOC_LITERAL(13, 329, 42), // "receive_Calibration_StaticCal..."
QT_MOC_LITERAL(14, 372, 38), // "receive_Calibration_StaticSuc..."
QT_MOC_LITERAL(15, 411, 43), // "receive_Calibration_DynamicCa..."
QT_MOC_LITERAL(16, 455, 40), // "receive_Calibration_IncTurnin..."
QT_MOC_LITERAL(17, 496, 40), // "receive_Calibration_IncForwar..."
QT_MOC_LITERAL(18, 537, 46), // "receive_Calibration_PleaseCha..."
QT_MOC_LITERAL(19, 584, 39), // "receive_Calibration_DynamicSu..."
QT_MOC_LITERAL(20, 624, 33), // "receive_TempCali_RequestData_..."
QT_MOC_LITERAL(21, 658, 32), // "receive_TempCali_RepeatData_head"
QT_MOC_LITERAL(22, 691, 34), // "receive_TempCali_CompleteData..."
QT_MOC_LITERAL(23, 726, 40), // "receive_TempCali_DeviceHasSav..."
QT_MOC_LITERAL(24, 767, 49), // "receiveACK_Calibration_UserIn..."
QT_MOC_LITERAL(25, 817, 52), // "receiveACK_Calibration_System..."
QT_MOC_LITERAL(26, 870, 34), // "receiveACK_Calibration_Static..."
QT_MOC_LITERAL(27, 905, 35), // "receiveACK_Calibration_Dynami..."
QT_MOC_LITERAL(28, 941, 34), // "receiveACK_Calibration_Cancel..."
QT_MOC_LITERAL(29, 976, 38), // "receiveACK_Calibration_SaveRe..."
QT_MOC_LITERAL(30, 1015, 42), // "receiveACK_Calibration_DontSa..."
QT_MOC_LITERAL(31, 1058, 37), // "receiveACK_Calibration_WheelB..."
QT_MOC_LITERAL(32, 1096, 41), // "receiveACK_Calibration_LeverI..."
QT_MOC_LITERAL(33, 1138, 32), // "receiveACK_ChangeProtocolOK_head"
QT_MOC_LITERAL(34, 1171, 25), // "receiveACK_CustomCan_head"
QT_MOC_LITERAL(35, 1197, 30), // "receiveACK_RTCMSelectType_head"
QT_MOC_LITERAL(36, 1228, 28), // "receiveACK_StaticIPPort_head"
QT_MOC_LITERAL(37, 1257, 23), // "sig_recETHCfg_data_head"
QT_MOC_LITERAL(38, 1281, 24), // "sig_recETHCfg_ReturnData"
QT_MOC_LITERAL(39, 1306, 34), // "sig_recCusmtomProtocolRespons..."
QT_MOC_LITERAL(40, 1341, 16), // "Serial_readyRead"
QT_MOC_LITERAL(41, 1358, 12) // "Serial_Write"

    },
    "SerialPort\0delDoneData\0\0data\0"
    "delDone_GJProtocol_Data\0"
    "delDone_GJProtocol_PollingData\0"
    "delDone_GJProtocol_TrackMap_Point\0"
    "receive_Firmware_PleaseUpdata_head\0"
    "receive_Firmware_PleaseWaitUpdata_head\0"
    "receive_Firmware_ReceiveError_head\0"
    "receive_Firmware_FileError_head\0"
    "receive_Firmware_UpdataError_head\0"
    "receive_Firmware_UpdataSuccess_head\0"
    "receive_Calibration_StaticCalibrating_head\0"
    "receive_Calibration_StaticSuccess_head\0"
    "receive_Calibration_DynamicCalibrating_head\0"
    "receive_Calibration_IncTurningRatio_head\0"
    "receive_Calibration_IncForwardRatio_head\0"
    "receive_Calibration_PleaseChangeCaliSites_head\0"
    "receive_Calibration_DynamicSuccess_head\0"
    "receive_TempCali_RequestData_head\0"
    "receive_TempCali_RepeatData_head\0"
    "receive_TempCali_CompleteData_head\0"
    "receive_TempCali_DeviceHasSavedData_head\0"
    "receiveACK_Calibration_UserInstallationAngle_head\0"
    "receiveACK_Calibration_SystemInstallationAangle_head\0"
    "receiveACK_Calibration_Static_head\0"
    "receiveACK_Calibration_Dynamic_head\0"
    "receiveACK_Calibration_Cancel_head\0"
    "receiveACK_Calibration_SaveResult_head\0"
    "receiveACK_Calibration_DontSaveResult_head\0"
    "receiveACK_Calibration_WheelBase_head\0"
    "receiveACK_Calibration_LeverINS2Rear_head\0"
    "receiveACK_ChangeProtocolOK_head\0"
    "receiveACK_CustomCan_head\0"
    "receiveACK_RTCMSelectType_head\0"
    "receiveACK_StaticIPPort_head\0"
    "sig_recETHCfg_data_head\0"
    "sig_recETHCfg_ReturnData\0"
    "sig_recCusmtomProtocolResponseHead\0"
    "Serial_readyRead\0Serial_Write"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPort[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      37,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  209,    2, 0x06 /* Public */,
       4,    0,  212,    2, 0x06 /* Public */,
       5,    0,  213,    2, 0x06 /* Public */,
       6,    0,  214,    2, 0x06 /* Public */,
       7,    0,  215,    2, 0x06 /* Public */,
       8,    0,  216,    2, 0x06 /* Public */,
       9,    0,  217,    2, 0x06 /* Public */,
      10,    0,  218,    2, 0x06 /* Public */,
      11,    0,  219,    2, 0x06 /* Public */,
      12,    0,  220,    2, 0x06 /* Public */,
      13,    0,  221,    2, 0x06 /* Public */,
      14,    0,  222,    2, 0x06 /* Public */,
      15,    0,  223,    2, 0x06 /* Public */,
      16,    0,  224,    2, 0x06 /* Public */,
      17,    0,  225,    2, 0x06 /* Public */,
      18,    0,  226,    2, 0x06 /* Public */,
      19,    0,  227,    2, 0x06 /* Public */,
      20,    0,  228,    2, 0x06 /* Public */,
      21,    0,  229,    2, 0x06 /* Public */,
      22,    0,  230,    2, 0x06 /* Public */,
      23,    1,  231,    2, 0x06 /* Public */,
      24,    0,  234,    2, 0x06 /* Public */,
      25,    0,  235,    2, 0x06 /* Public */,
      26,    0,  236,    2, 0x06 /* Public */,
      27,    0,  237,    2, 0x06 /* Public */,
      28,    0,  238,    2, 0x06 /* Public */,
      29,    0,  239,    2, 0x06 /* Public */,
      30,    0,  240,    2, 0x06 /* Public */,
      31,    0,  241,    2, 0x06 /* Public */,
      32,    0,  242,    2, 0x06 /* Public */,
      33,    0,  243,    2, 0x06 /* Public */,
      34,    0,  244,    2, 0x06 /* Public */,
      35,    0,  245,    2, 0x06 /* Public */,
      36,    0,  246,    2, 0x06 /* Public */,
      37,    0,  247,    2, 0x06 /* Public */,
      38,    1,  248,    2, 0x06 /* Public */,
      39,    0,  251,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      40,    0,  252,    2, 0x0a /* Public */,
      41,    1,  253,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    3,

       0        // eod
};

void SerialPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SerialPort *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->delDoneData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->delDone_GJProtocol_Data(); break;
        case 2: _t->delDone_GJProtocol_PollingData(); break;
        case 3: _t->delDone_GJProtocol_TrackMap_Point(); break;
        case 4: _t->receive_Firmware_PleaseUpdata_head(); break;
        case 5: _t->receive_Firmware_PleaseWaitUpdata_head(); break;
        case 6: _t->receive_Firmware_ReceiveError_head(); break;
        case 7: _t->receive_Firmware_FileError_head(); break;
        case 8: _t->receive_Firmware_UpdataError_head(); break;
        case 9: _t->receive_Firmware_UpdataSuccess_head(); break;
        case 10: _t->receive_Calibration_StaticCalibrating_head(); break;
        case 11: _t->receive_Calibration_StaticSuccess_head(); break;
        case 12: _t->receive_Calibration_DynamicCalibrating_head(); break;
        case 13: _t->receive_Calibration_IncTurningRatio_head(); break;
        case 14: _t->receive_Calibration_IncForwardRatio_head(); break;
        case 15: _t->receive_Calibration_PleaseChangeCaliSites_head(); break;
        case 16: _t->receive_Calibration_DynamicSuccess_head(); break;
        case 17: _t->receive_TempCali_RequestData_head(); break;
        case 18: _t->receive_TempCali_RepeatData_head(); break;
        case 19: _t->receive_TempCali_CompleteData_head(); break;
        case 20: _t->receive_TempCali_DeviceHasSavedData_head((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 21: _t->receiveACK_Calibration_UserInstallationAngle_head(); break;
        case 22: _t->receiveACK_Calibration_SystemInstallationAangle_head(); break;
        case 23: _t->receiveACK_Calibration_Static_head(); break;
        case 24: _t->receiveACK_Calibration_Dynamic_head(); break;
        case 25: _t->receiveACK_Calibration_Cancel_head(); break;
        case 26: _t->receiveACK_Calibration_SaveResult_head(); break;
        case 27: _t->receiveACK_Calibration_DontSaveResult_head(); break;
        case 28: _t->receiveACK_Calibration_WheelBase_head(); break;
        case 29: _t->receiveACK_Calibration_LeverINS2Rear_head(); break;
        case 30: _t->receiveACK_ChangeProtocolOK_head(); break;
        case 31: _t->receiveACK_CustomCan_head(); break;
        case 32: _t->receiveACK_RTCMSelectType_head(); break;
        case 33: _t->receiveACK_StaticIPPort_head(); break;
        case 34: _t->sig_recETHCfg_data_head(); break;
        case 35: _t->sig_recETHCfg_ReturnData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 36: _t->sig_recCusmtomProtocolResponseHead(); break;
        case 37: _t->Serial_readyRead(); break;
        case 38: _t->Serial_Write((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SerialPort::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::delDoneData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::delDone_GJProtocol_Data)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::delDone_GJProtocol_PollingData)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::delDone_GJProtocol_TrackMap_Point)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receive_Firmware_PleaseUpdata_head)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receive_Firmware_PleaseWaitUpdata_head)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receive_Firmware_ReceiveError_head)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receive_Firmware_FileError_head)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receive_Firmware_UpdataError_head)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receive_Firmware_UpdataSuccess_head)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receive_Calibration_StaticCalibrating_head)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receive_Calibration_StaticSuccess_head)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receive_Calibration_DynamicCalibrating_head)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receive_Calibration_IncTurningRatio_head)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receive_Calibration_IncForwardRatio_head)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receive_Calibration_PleaseChangeCaliSites_head)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receive_Calibration_DynamicSuccess_head)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receive_TempCali_RequestData_head)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receive_TempCali_RepeatData_head)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receive_TempCali_CompleteData_head)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receive_TempCali_DeviceHasSavedData_head)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receiveACK_Calibration_UserInstallationAngle_head)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receiveACK_Calibration_SystemInstallationAangle_head)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receiveACK_Calibration_Static_head)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receiveACK_Calibration_Dynamic_head)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receiveACK_Calibration_Cancel_head)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receiveACK_Calibration_SaveResult_head)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receiveACK_Calibration_DontSaveResult_head)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receiveACK_Calibration_WheelBase_head)) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receiveACK_Calibration_LeverINS2Rear_head)) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receiveACK_ChangeProtocolOK_head)) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receiveACK_CustomCan_head)) {
                *result = 31;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receiveACK_RTCMSelectType_head)) {
                *result = 32;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::receiveACK_StaticIPPort_head)) {
                *result = 33;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::sig_recETHCfg_data_head)) {
                *result = 34;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::sig_recETHCfg_ReturnData)) {
                *result = 35;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::sig_recCusmtomProtocolResponseHead)) {
                *result = 36;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SerialPort::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SerialPort.data,
    qt_meta_data_SerialPort,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SerialPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPort::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPort.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SerialPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 39)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 39;
    }
    return _id;
}

// SIGNAL 0
void SerialPort::delDoneData(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialPort::delDone_GJProtocol_Data()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SerialPort::delDone_GJProtocol_PollingData()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SerialPort::delDone_GJProtocol_TrackMap_Point()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SerialPort::receive_Firmware_PleaseUpdata_head()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SerialPort::receive_Firmware_PleaseWaitUpdata_head()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void SerialPort::receive_Firmware_ReceiveError_head()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void SerialPort::receive_Firmware_FileError_head()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void SerialPort::receive_Firmware_UpdataError_head()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void SerialPort::receive_Firmware_UpdataSuccess_head()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void SerialPort::receive_Calibration_StaticCalibrating_head()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void SerialPort::receive_Calibration_StaticSuccess_head()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void SerialPort::receive_Calibration_DynamicCalibrating_head()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void SerialPort::receive_Calibration_IncTurningRatio_head()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void SerialPort::receive_Calibration_IncForwardRatio_head()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void SerialPort::receive_Calibration_PleaseChangeCaliSites_head()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void SerialPort::receive_Calibration_DynamicSuccess_head()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void SerialPort::receive_TempCali_RequestData_head()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void SerialPort::receive_TempCali_RepeatData_head()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void SerialPort::receive_TempCali_CompleteData_head()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void SerialPort::receive_TempCali_DeviceHasSavedData_head(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void SerialPort::receiveACK_Calibration_UserInstallationAngle_head()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void SerialPort::receiveACK_Calibration_SystemInstallationAangle_head()
{
    QMetaObject::activate(this, &staticMetaObject, 22, nullptr);
}

// SIGNAL 23
void SerialPort::receiveACK_Calibration_Static_head()
{
    QMetaObject::activate(this, &staticMetaObject, 23, nullptr);
}

// SIGNAL 24
void SerialPort::receiveACK_Calibration_Dynamic_head()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void SerialPort::receiveACK_Calibration_Cancel_head()
{
    QMetaObject::activate(this, &staticMetaObject, 25, nullptr);
}

// SIGNAL 26
void SerialPort::receiveACK_Calibration_SaveResult_head()
{
    QMetaObject::activate(this, &staticMetaObject, 26, nullptr);
}

// SIGNAL 27
void SerialPort::receiveACK_Calibration_DontSaveResult_head()
{
    QMetaObject::activate(this, &staticMetaObject, 27, nullptr);
}

// SIGNAL 28
void SerialPort::receiveACK_Calibration_WheelBase_head()
{
    QMetaObject::activate(this, &staticMetaObject, 28, nullptr);
}

// SIGNAL 29
void SerialPort::receiveACK_Calibration_LeverINS2Rear_head()
{
    QMetaObject::activate(this, &staticMetaObject, 29, nullptr);
}

// SIGNAL 30
void SerialPort::receiveACK_ChangeProtocolOK_head()
{
    QMetaObject::activate(this, &staticMetaObject, 30, nullptr);
}

// SIGNAL 31
void SerialPort::receiveACK_CustomCan_head()
{
    QMetaObject::activate(this, &staticMetaObject, 31, nullptr);
}

// SIGNAL 32
void SerialPort::receiveACK_RTCMSelectType_head()
{
    QMetaObject::activate(this, &staticMetaObject, 32, nullptr);
}

// SIGNAL 33
void SerialPort::receiveACK_StaticIPPort_head()
{
    QMetaObject::activate(this, &staticMetaObject, 33, nullptr);
}

// SIGNAL 34
void SerialPort::sig_recETHCfg_data_head()
{
    QMetaObject::activate(this, &staticMetaObject, 34, nullptr);
}

// SIGNAL 35
void SerialPort::sig_recETHCfg_ReturnData(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 35, _a);
}

// SIGNAL 36
void SerialPort::sig_recCusmtomProtocolResponseHead()
{
    QMetaObject::activate(this, &staticMetaObject, 36, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

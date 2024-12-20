/****************************************************************************
** Meta object code from reading C++ file 'dialog_calibration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../dialog_calibration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_calibration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_Calibration_t {
    QByteArrayData data[28];
    char stringdata0[1025];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_Calibration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_Calibration_t qt_meta_stringdata_Dialog_Calibration = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Dialog_Calibration"
QT_MOC_LITERAL(1, 19, 12), // "Serial_Write"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 49), // "receiveACK_Calibration_UserIn..."
QT_MOC_LITERAL(4, 83, 52), // "receiveACK_Calibration_System..."
QT_MOC_LITERAL(5, 136, 34), // "receiveACK_Calibration_Static..."
QT_MOC_LITERAL(6, 171, 35), // "receiveACK_Calibration_Dynami..."
QT_MOC_LITERAL(7, 207, 34), // "receiveACK_Calibration_Cancel..."
QT_MOC_LITERAL(8, 242, 38), // "receiveACK_Calibration_SaveRe..."
QT_MOC_LITERAL(9, 281, 37), // "receiveACK_Calibration_WheelB..."
QT_MOC_LITERAL(10, 319, 41), // "receiveACK_Calibration_LeverI..."
QT_MOC_LITERAL(11, 361, 42), // "receive_Calibration_StaticCal..."
QT_MOC_LITERAL(12, 404, 38), // "receive_Calibration_StaticSuc..."
QT_MOC_LITERAL(13, 443, 43), // "receive_Calibration_DynamicCa..."
QT_MOC_LITERAL(14, 487, 40), // "receive_Calibration_IncTurnin..."
QT_MOC_LITERAL(15, 528, 40), // "receive_Calibration_IncForwar..."
QT_MOC_LITERAL(16, 569, 46), // "receive_Calibration_PleaseCha..."
QT_MOC_LITERAL(17, 616, 39), // "receive_Calibration_DynamicSu..."
QT_MOC_LITERAL(18, 656, 21), // "updateDynamicCaliData"
QT_MOC_LITERAL(19, 678, 33), // "on_PushButton_Lever1_Send_cli..."
QT_MOC_LITERAL(20, 712, 33), // "on_PushButton_Lever2_Send_cli..."
QT_MOC_LITERAL(21, 746, 33), // "on_PushButton_Lever3_Send_cli..."
QT_MOC_LITERAL(22, 780, 33), // "on_PushButton_Lever4_Send_cli..."
QT_MOC_LITERAL(23, 814, 34), // "on_PushButton_CurLever_Get_cl..."
QT_MOC_LITERAL(24, 849, 40), // "on_PushButton_Calibration_Sta..."
QT_MOC_LITERAL(25, 890, 41), // "on_PushButton_Calibration_Dyn..."
QT_MOC_LITERAL(26, 932, 44), // "on_PushButton_Calibration_Sav..."
QT_MOC_LITERAL(27, 977, 47) // "on_PushButton_Calibration_Aba..."

    },
    "Dialog_Calibration\0Serial_Write\0\0"
    "receiveACK_Calibration_UserInstallationAngle_head\0"
    "receiveACK_Calibration_SystemInstallationAangle_head\0"
    "receiveACK_Calibration_Static_head\0"
    "receiveACK_Calibration_Dynamic_head\0"
    "receiveACK_Calibration_Cancel_head\0"
    "receiveACK_Calibration_SaveResult_head\0"
    "receiveACK_Calibration_WheelBase_head\0"
    "receiveACK_Calibration_LeverINS2Rear_head\0"
    "receive_Calibration_StaticCalibrating_head\0"
    "receive_Calibration_StaticSuccess_head\0"
    "receive_Calibration_DynamicCalibrating_head\0"
    "receive_Calibration_IncTurningRatio_head\0"
    "receive_Calibration_IncForwardRatio_head\0"
    "receive_Calibration_PleaseChangeCaliSites_head\0"
    "receive_Calibration_DynamicSuccess_head\0"
    "updateDynamicCaliData\0"
    "on_PushButton_Lever1_Send_clicked\0"
    "on_PushButton_Lever2_Send_clicked\0"
    "on_PushButton_Lever3_Send_clicked\0"
    "on_PushButton_Lever4_Send_clicked\0"
    "on_PushButton_CurLever_Get_clicked\0"
    "on_PushButton_Calibration_Static_clicked\0"
    "on_PushButton_Calibration_Dynamic_clicked\0"
    "on_PushButton_Calibration_SaveResult_clicked\0"
    "on_PushButton_Calibration_AbandonResult_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog_Calibration[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  144,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  147,    2, 0x0a /* Public */,
       4,    0,  148,    2, 0x0a /* Public */,
       5,    0,  149,    2, 0x0a /* Public */,
       6,    0,  150,    2, 0x0a /* Public */,
       7,    0,  151,    2, 0x0a /* Public */,
       8,    0,  152,    2, 0x0a /* Public */,
       9,    0,  153,    2, 0x0a /* Public */,
      10,    0,  154,    2, 0x0a /* Public */,
      11,    0,  155,    2, 0x0a /* Public */,
      12,    0,  156,    2, 0x0a /* Public */,
      13,    0,  157,    2, 0x0a /* Public */,
      14,    0,  158,    2, 0x0a /* Public */,
      15,    0,  159,    2, 0x0a /* Public */,
      16,    0,  160,    2, 0x0a /* Public */,
      17,    0,  161,    2, 0x0a /* Public */,
      18,    0,  162,    2, 0x0a /* Public */,
      19,    0,  163,    2, 0x08 /* Private */,
      20,    0,  164,    2, 0x08 /* Private */,
      21,    0,  165,    2, 0x08 /* Private */,
      22,    0,  166,    2, 0x08 /* Private */,
      23,    0,  167,    2, 0x08 /* Private */,
      24,    0,  168,    2, 0x08 /* Private */,
      25,    0,  169,    2, 0x08 /* Private */,
      26,    0,  170,    2, 0x08 /* Private */,
      27,    0,  171,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,

 // slots: parameters
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Dialog_Calibration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog_Calibration *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Serial_Write((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->receiveACK_Calibration_UserInstallationAngle_head(); break;
        case 2: _t->receiveACK_Calibration_SystemInstallationAangle_head(); break;
        case 3: _t->receiveACK_Calibration_Static_head(); break;
        case 4: _t->receiveACK_Calibration_Dynamic_head(); break;
        case 5: _t->receiveACK_Calibration_Cancel_head(); break;
        case 6: _t->receiveACK_Calibration_SaveResult_head(); break;
        case 7: _t->receiveACK_Calibration_WheelBase_head(); break;
        case 8: _t->receiveACK_Calibration_LeverINS2Rear_head(); break;
        case 9: _t->receive_Calibration_StaticCalibrating_head(); break;
        case 10: _t->receive_Calibration_StaticSuccess_head(); break;
        case 11: _t->receive_Calibration_DynamicCalibrating_head(); break;
        case 12: _t->receive_Calibration_IncTurningRatio_head(); break;
        case 13: _t->receive_Calibration_IncForwardRatio_head(); break;
        case 14: _t->receive_Calibration_PleaseChangeCaliSites_head(); break;
        case 15: _t->receive_Calibration_DynamicSuccess_head(); break;
        case 16: _t->updateDynamicCaliData(); break;
        case 17: _t->on_PushButton_Lever1_Send_clicked(); break;
        case 18: _t->on_PushButton_Lever2_Send_clicked(); break;
        case 19: _t->on_PushButton_Lever3_Send_clicked(); break;
        case 20: _t->on_PushButton_Lever4_Send_clicked(); break;
        case 21: _t->on_PushButton_CurLever_Get_clicked(); break;
        case 22: _t->on_PushButton_Calibration_Static_clicked(); break;
        case 23: _t->on_PushButton_Calibration_Dynamic_clicked(); break;
        case 24: _t->on_PushButton_Calibration_SaveResult_clicked(); break;
        case 25: _t->on_PushButton_Calibration_AbandonResult_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Dialog_Calibration::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog_Calibration::Serial_Write)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog_Calibration::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Dialog_Calibration.data,
    qt_meta_data_Dialog_Calibration,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dialog_Calibration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog_Calibration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog_Calibration.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog_Calibration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void Dialog_Calibration::Serial_Write(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

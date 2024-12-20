/****************************************************************************
** Meta object code from reading C++ file 'dialog_customcan.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../dialog_customcan.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_customcan.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_CustomCan_t {
    QByteArrayData data[32];
    char stringdata0[1094];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_CustomCan_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_CustomCan_t qt_meta_stringdata_Dialog_CustomCan = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Dialog_CustomCan"
QT_MOC_LITERAL(1, 17, 12), // "Serial_Write"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 29), // "on_PushButton_ReadDBC_clicked"
QT_MOC_LITERAL(4, 61, 29), // "on_PushButton_SendCAN_clicked"
QT_MOC_LITERAL(5, 91, 31), // "on_CheckBox_ManualInput_clicked"
QT_MOC_LITERAL(6, 123, 28), // "on_CheckBox_DBCInput_clicked"
QT_MOC_LITERAL(7, 152, 33), // "on_CheckBox_VehicleSpd_En_cli..."
QT_MOC_LITERAL(8, 186, 33), // "on_CheckBox_FLWheelSpd_En_cli..."
QT_MOC_LITERAL(9, 220, 33), // "on_CheckBox_RLWheelSpd_En_cli..."
QT_MOC_LITERAL(10, 254, 33), // "on_CheckBox_FRWheelSpd_En_cli..."
QT_MOC_LITERAL(11, 288, 33), // "on_CheckBox_RRWheelSpd_En_cli..."
QT_MOC_LITERAL(12, 322, 27), // "on_CheckBox_Gear_En_clicked"
QT_MOC_LITERAL(13, 350, 28), // "on_CheckBox_Gear_PEN_clicked"
QT_MOC_LITERAL(14, 379, 28), // "on_CheckBox_Gear_DEN_clicked"
QT_MOC_LITERAL(15, 408, 28), // "on_CheckBox_Gear_REN_clicked"
QT_MOC_LITERAL(16, 437, 28), // "on_CheckBox_Gear_NEN_clicked"
QT_MOC_LITERAL(17, 466, 45), // "on_ComboBox_VehicleSpd_ID_cur..."
QT_MOC_LITERAL(18, 512, 5), // "index"
QT_MOC_LITERAL(19, 518, 45), // "on_ComboBox_FLWheelSpd_ID_cur..."
QT_MOC_LITERAL(20, 564, 45), // "on_ComboBox_FRWheelSpd_ID_cur..."
QT_MOC_LITERAL(21, 610, 45), // "on_ComboBox_RLWheelSpd_ID_cur..."
QT_MOC_LITERAL(22, 656, 45), // "on_ComboBox_RRWheelSpd_ID_cur..."
QT_MOC_LITERAL(23, 702, 39), // "on_ComboBox_Gear_ID_currentIn..."
QT_MOC_LITERAL(24, 742, 53), // "on_ComboBox_VehicleSpd_Signal..."
QT_MOC_LITERAL(25, 796, 53), // "on_ComboBox_FLWheelSpd_Signal..."
QT_MOC_LITERAL(26, 850, 53), // "on_ComboBox_FRWheelSpd_Signal..."
QT_MOC_LITERAL(27, 904, 53), // "on_ComboBox_RLWheelSpd_Signal..."
QT_MOC_LITERAL(28, 958, 53), // "on_ComboBox_RRWheelSpd_Signal..."
QT_MOC_LITERAL(29, 1012, 47), // "on_ComboBox_Gear_SignalName_c..."
QT_MOC_LITERAL(30, 1060, 25), // "receiveACK_CustomCan_head"
QT_MOC_LITERAL(31, 1086, 7) // "TimeOut"

    },
    "Dialog_CustomCan\0Serial_Write\0\0"
    "on_PushButton_ReadDBC_clicked\0"
    "on_PushButton_SendCAN_clicked\0"
    "on_CheckBox_ManualInput_clicked\0"
    "on_CheckBox_DBCInput_clicked\0"
    "on_CheckBox_VehicleSpd_En_clicked\0"
    "on_CheckBox_FLWheelSpd_En_clicked\0"
    "on_CheckBox_RLWheelSpd_En_clicked\0"
    "on_CheckBox_FRWheelSpd_En_clicked\0"
    "on_CheckBox_RRWheelSpd_En_clicked\0"
    "on_CheckBox_Gear_En_clicked\0"
    "on_CheckBox_Gear_PEN_clicked\0"
    "on_CheckBox_Gear_DEN_clicked\0"
    "on_CheckBox_Gear_REN_clicked\0"
    "on_CheckBox_Gear_NEN_clicked\0"
    "on_ComboBox_VehicleSpd_ID_currentIndexChanged\0"
    "index\0on_ComboBox_FLWheelSpd_ID_currentIndexChanged\0"
    "on_ComboBox_FRWheelSpd_ID_currentIndexChanged\0"
    "on_ComboBox_RLWheelSpd_ID_currentIndexChanged\0"
    "on_ComboBox_RRWheelSpd_ID_currentIndexChanged\0"
    "on_ComboBox_Gear_ID_currentIndexChanged\0"
    "on_ComboBox_VehicleSpd_SignalName_currentIndexChanged\0"
    "on_ComboBox_FLWheelSpd_SignalName_currentIndexChanged\0"
    "on_ComboBox_FRWheelSpd_SignalName_currentIndexChanged\0"
    "on_ComboBox_RLWheelSpd_SignalName_currentIndexChanged\0"
    "on_ComboBox_RRWheelSpd_SignalName_currentIndexChanged\0"
    "on_ComboBox_Gear_SignalName_currentIndexChanged\0"
    "receiveACK_CustomCan_head\0TimeOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog_CustomCan[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  159,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  162,    2, 0x08 /* Private */,
       4,    0,  163,    2, 0x08 /* Private */,
       5,    0,  164,    2, 0x08 /* Private */,
       6,    0,  165,    2, 0x08 /* Private */,
       7,    0,  166,    2, 0x08 /* Private */,
       8,    0,  167,    2, 0x08 /* Private */,
       9,    0,  168,    2, 0x08 /* Private */,
      10,    0,  169,    2, 0x08 /* Private */,
      11,    0,  170,    2, 0x08 /* Private */,
      12,    0,  171,    2, 0x08 /* Private */,
      13,    0,  172,    2, 0x08 /* Private */,
      14,    0,  173,    2, 0x08 /* Private */,
      15,    0,  174,    2, 0x08 /* Private */,
      16,    0,  175,    2, 0x08 /* Private */,
      17,    1,  176,    2, 0x08 /* Private */,
      19,    1,  179,    2, 0x08 /* Private */,
      20,    1,  182,    2, 0x08 /* Private */,
      21,    1,  185,    2, 0x08 /* Private */,
      22,    1,  188,    2, 0x08 /* Private */,
      23,    1,  191,    2, 0x08 /* Private */,
      24,    1,  194,    2, 0x08 /* Private */,
      25,    1,  197,    2, 0x08 /* Private */,
      26,    1,  200,    2, 0x08 /* Private */,
      27,    1,  203,    2, 0x08 /* Private */,
      28,    1,  206,    2, 0x08 /* Private */,
      29,    1,  209,    2, 0x08 /* Private */,
      30,    0,  212,    2, 0x08 /* Private */,
      31,    0,  213,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Dialog_CustomCan::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog_CustomCan *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Serial_Write((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->on_PushButton_ReadDBC_clicked(); break;
        case 2: _t->on_PushButton_SendCAN_clicked(); break;
        case 3: _t->on_CheckBox_ManualInput_clicked(); break;
        case 4: _t->on_CheckBox_DBCInput_clicked(); break;
        case 5: _t->on_CheckBox_VehicleSpd_En_clicked(); break;
        case 6: _t->on_CheckBox_FLWheelSpd_En_clicked(); break;
        case 7: _t->on_CheckBox_RLWheelSpd_En_clicked(); break;
        case 8: _t->on_CheckBox_FRWheelSpd_En_clicked(); break;
        case 9: _t->on_CheckBox_RRWheelSpd_En_clicked(); break;
        case 10: _t->on_CheckBox_Gear_En_clicked(); break;
        case 11: _t->on_CheckBox_Gear_PEN_clicked(); break;
        case 12: _t->on_CheckBox_Gear_DEN_clicked(); break;
        case 13: _t->on_CheckBox_Gear_REN_clicked(); break;
        case 14: _t->on_CheckBox_Gear_NEN_clicked(); break;
        case 15: _t->on_ComboBox_VehicleSpd_ID_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_ComboBox_FLWheelSpd_ID_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_ComboBox_FRWheelSpd_ID_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->on_ComboBox_RLWheelSpd_ID_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_ComboBox_RRWheelSpd_ID_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->on_ComboBox_Gear_ID_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->on_ComboBox_VehicleSpd_SignalName_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_ComboBox_FLWheelSpd_SignalName_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_ComboBox_FRWheelSpd_SignalName_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_ComboBox_RLWheelSpd_SignalName_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->on_ComboBox_RRWheelSpd_SignalName_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_ComboBox_Gear_SignalName_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->receiveACK_CustomCan_head(); break;
        case 28: _t->TimeOut(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Dialog_CustomCan::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog_CustomCan::Serial_Write)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog_CustomCan::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Dialog_CustomCan.data,
    qt_meta_data_Dialog_CustomCan,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dialog_CustomCan::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog_CustomCan::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog_CustomCan.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog_CustomCan::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 29;
    }
    return _id;
}

// SIGNAL 0
void Dialog_CustomCan::Serial_Write(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

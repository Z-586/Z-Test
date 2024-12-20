/****************************************************************************
** Meta object code from reading C++ file 'dialog_advanced.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../dialog_advanced.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_advanced.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_advanced_t {
    QByteArrayData data[8];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_advanced_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_advanced_t qt_meta_stringdata_Dialog_advanced = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Dialog_advanced"
QT_MOC_LITERAL(1, 16, 12), // "Serial_Write"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(4, 52, 30), // "receiveACK_RTCMSelectType_head"
QT_MOC_LITERAL(5, 83, 18), // "slot_recETHCfg_Ack"
QT_MOC_LITERAL(6, 102, 25), // "slot_recETHCfg_ReturnData"
QT_MOC_LITERAL(7, 128, 4) // "data"

    },
    "Dialog_advanced\0Serial_Write\0\0"
    "on_pushButton_clicked\0"
    "receiveACK_RTCMSelectType_head\0"
    "slot_recETHCfg_Ack\0slot_recETHCfg_ReturnData\0"
    "data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog_advanced[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   42,    2, 0x08 /* Private */,
       4,    0,   43,    2, 0x0a /* Public */,
       5,    0,   44,    2, 0x0a /* Public */,
       6,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    7,

       0        // eod
};

void Dialog_advanced::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog_advanced *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Serial_Write((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->receiveACK_RTCMSelectType_head(); break;
        case 3: _t->slot_recETHCfg_Ack(); break;
        case 4: _t->slot_recETHCfg_ReturnData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Dialog_advanced::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog_advanced::Serial_Write)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog_advanced::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Dialog_advanced.data,
    qt_meta_data_Dialog_advanced,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dialog_advanced::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog_advanced::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog_advanced.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog_advanced::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Dialog_advanced::Serial_Write(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

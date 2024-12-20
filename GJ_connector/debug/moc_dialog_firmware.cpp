/****************************************************************************
** Meta object code from reading C++ file 'dialog_firmware.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../dialog_firmware.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_firmware.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_FirmWare_t {
    QByteArrayData data[11];
    char stringdata0[326];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_FirmWare_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_FirmWare_t qt_meta_stringdata_Dialog_FirmWare = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Dialog_FirmWare"
QT_MOC_LITERAL(1, 16, 12), // "Serial_Write"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 38), // "receive_Firmware_PleaseWaitUp..."
QT_MOC_LITERAL(4, 69, 34), // "receive_Firmware_ReceiveError..."
QT_MOC_LITERAL(5, 104, 31), // "receive_Firmware_FileError_head"
QT_MOC_LITERAL(6, 136, 33), // "receive_Firmware_UpdataError_..."
QT_MOC_LITERAL(7, 170, 35), // "receive_Firmware_UpdataSucces..."
QT_MOC_LITERAL(8, 206, 41), // "on_PushButton_FirmWare_Selete..."
QT_MOC_LITERAL(9, 248, 37), // "on_PushButton_FirmWare_Updata..."
QT_MOC_LITERAL(10, 286, 39) // "on_PushButton_FirmWare_Comple..."

    },
    "Dialog_FirmWare\0Serial_Write\0\0"
    "receive_Firmware_PleaseWaitUpdata_head\0"
    "receive_Firmware_ReceiveError_head\0"
    "receive_Firmware_FileError_head\0"
    "receive_Firmware_UpdataError_head\0"
    "receive_Firmware_UpdataSuccess_head\0"
    "on_PushButton_FirmWare_SeleteFile_clicked\0"
    "on_PushButton_FirmWare_Updata_clicked\0"
    "on_PushButton_FirmWare_Complete_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog_FirmWare[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   62,    2, 0x0a /* Public */,
       4,    0,   63,    2, 0x0a /* Public */,
       5,    0,   64,    2, 0x0a /* Public */,
       6,    0,   65,    2, 0x0a /* Public */,
       7,    0,   66,    2, 0x0a /* Public */,
       8,    0,   67,    2, 0x08 /* Private */,
       9,    0,   68,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,

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

       0        // eod
};

void Dialog_FirmWare::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog_FirmWare *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Serial_Write((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->receive_Firmware_PleaseWaitUpdata_head(); break;
        case 2: _t->receive_Firmware_ReceiveError_head(); break;
        case 3: _t->receive_Firmware_FileError_head(); break;
        case 4: _t->receive_Firmware_UpdataError_head(); break;
        case 5: _t->receive_Firmware_UpdataSuccess_head(); break;
        case 6: _t->on_PushButton_FirmWare_SeleteFile_clicked(); break;
        case 7: _t->on_PushButton_FirmWare_Updata_clicked(); break;
        case 8: _t->on_PushButton_FirmWare_Complete_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Dialog_FirmWare::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog_FirmWare::Serial_Write)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog_FirmWare::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Dialog_FirmWare.data,
    qt_meta_data_Dialog_FirmWare,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dialog_FirmWare::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog_FirmWare::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog_FirmWare.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog_FirmWare::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Dialog_FirmWare::Serial_Write(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'dialog_tempcali.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../dialog_tempcali.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_tempcali.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_TempCali_t {
    QByteArrayData data[13];
    char stringdata0[355];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_TempCali_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_TempCali_t qt_meta_stringdata_Dialog_TempCali = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Dialog_TempCali"
QT_MOC_LITERAL(1, 16, 12), // "Serial_Write"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 33), // "receive_TempCali_RequestData_..."
QT_MOC_LITERAL(4, 64, 32), // "receive_TempCali_RepeatData_head"
QT_MOC_LITERAL(5, 97, 34), // "receive_TempCali_CompleteData..."
QT_MOC_LITERAL(6, 132, 40), // "receive_TempCali_DeviceHasSav..."
QT_MOC_LITERAL(7, 173, 4), // "data"
QT_MOC_LITERAL(8, 178, 39), // "on_PushButton_TempCali_ReadFi..."
QT_MOC_LITERAL(9, 218, 39), // "on_PushButton_TempCali_SendFi..."
QT_MOC_LITERAL(10, 258, 43), // "on_PushButton_TempCali_StopSe..."
QT_MOC_LITERAL(11, 302, 25), // "on_PushButton_pre_clicked"
QT_MOC_LITERAL(12, 328, 26) // "on_PushButton_next_clicked"

    },
    "Dialog_TempCali\0Serial_Write\0\0"
    "receive_TempCali_RequestData_head\0"
    "receive_TempCali_RepeatData_head\0"
    "receive_TempCali_CompleteData_head\0"
    "receive_TempCali_DeviceHasSavedData_head\0"
    "data\0on_PushButton_TempCali_ReadFile_clicked\0"
    "on_PushButton_TempCali_SendFile_clicked\0"
    "on_PushButton_TempCali_StopSendFile_clicked\0"
    "on_PushButton_pre_clicked\0"
    "on_PushButton_next_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog_TempCali[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   67,    2, 0x0a /* Public */,
       4,    0,   68,    2, 0x0a /* Public */,
       5,    0,   69,    2, 0x0a /* Public */,
       6,    1,   70,    2, 0x0a /* Public */,
       8,    0,   73,    2, 0x08 /* Private */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Dialog_TempCali::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog_TempCali *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Serial_Write((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->receive_TempCali_RequestData_head(); break;
        case 2: _t->receive_TempCali_RepeatData_head(); break;
        case 3: _t->receive_TempCali_CompleteData_head(); break;
        case 4: _t->receive_TempCali_DeviceHasSavedData_head((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->on_PushButton_TempCali_ReadFile_clicked(); break;
        case 6: _t->on_PushButton_TempCali_SendFile_clicked(); break;
        case 7: _t->on_PushButton_TempCali_StopSendFile_clicked(); break;
        case 8: _t->on_PushButton_pre_clicked(); break;
        case 9: _t->on_PushButton_next_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Dialog_TempCali::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog_TempCali::Serial_Write)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog_TempCali::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Dialog_TempCali.data,
    qt_meta_data_Dialog_TempCali,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dialog_TempCali::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog_TempCali::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog_TempCali.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog_TempCali::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Dialog_TempCali::Serial_Write(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'openvideo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../openvideo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'openvideo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_openvideo_t {
    QByteArrayData data[8];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_openvideo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_openvideo_t qt_meta_stringdata_openvideo = {
    {
QT_MOC_LITERAL(0, 0, 9), // "openvideo"
QT_MOC_LITERAL(1, 10, 15), // "on_play_clicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 19), // "on_detector_clicked"
QT_MOC_LITERAL(4, 47, 11), // "RecvmodelID"
QT_MOC_LITERAL(5, 59, 2), // "id"
QT_MOC_LITERAL(6, 62, 16), // "on_ratio_clicked"
QT_MOC_LITERAL(7, 79, 16) // "on_rect1_clicked"

    },
    "openvideo\0on_play_clicked\0\0"
    "on_detector_clicked\0RecvmodelID\0id\0"
    "on_ratio_clicked\0on_rect1_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_openvideo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void openvideo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        openvideo *_t = static_cast<openvideo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_play_clicked(); break;
        case 1: _t->on_detector_clicked(); break;
        case 2: _t->RecvmodelID((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_ratio_clicked(); break;
        case 4: _t->on_rect1_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject openvideo::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_openvideo.data,
      qt_meta_data_openvideo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *openvideo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *openvideo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_openvideo.stringdata0))
        return static_cast<void*>(const_cast< openvideo*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int openvideo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

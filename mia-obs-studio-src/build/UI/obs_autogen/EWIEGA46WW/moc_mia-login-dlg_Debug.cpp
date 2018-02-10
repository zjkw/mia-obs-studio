/****************************************************************************
** Meta object code from reading C++ file 'mia-login-dlg.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../UI/mia-login-dlg.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mia-login-dlg.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_bridge_t {
    QByteArrayData data[7];
    char stringdata0[40];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_bridge_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_bridge_t qt_meta_stringdata_bridge = {
    {
QT_MOC_LITERAL(0, 0, 6), // "bridge"
QT_MOC_LITERAL(1, 7, 6), // "Cpp2Js"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 3), // "cmd"
QT_MOC_LITERAL(4, 19, 4), // "json"
QT_MOC_LITERAL(5, 24, 6), // "JsSign"
QT_MOC_LITERAL(6, 31, 8) // "OnJs2Cpp"

    },
    "bridge\0Cpp2Js\0\0cmd\0json\0JsSign\0OnJs2Cpp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_bridge[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       5,    2,   34,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       6,    2,   39,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

       0        // eod
};

void bridge::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        bridge *_t = static_cast<bridge *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Cpp2Js((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->JsSign((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->OnJs2Cpp((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (bridge::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bridge::Cpp2Js)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (bridge::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bridge::JsSign)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject bridge::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_bridge.data,
      qt_meta_data_bridge,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *bridge::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bridge::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_bridge.stringdata0))
        return static_cast<void*>(const_cast< bridge*>(this));
    return QObject::qt_metacast(_clname);
}

int bridge::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void bridge::Cpp2Js(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void bridge::JsSign(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_MiaLoginDialog_t {
    QByteArrayData data[11];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MiaLoginDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MiaLoginDialog_t qt_meta_stringdata_MiaLoginDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MiaLoginDialog"
QT_MOC_LITERAL(1, 15, 15), // "OnWxLoginResult"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 3), // "cmd"
QT_MOC_LITERAL(4, 36, 4), // "json"
QT_MOC_LITERAL(5, 41, 18), // "OnWebSocketConnect"
QT_MOC_LITERAL(6, 60, 19), // "MiaWebsocketClient*"
QT_MOC_LITERAL(7, 80, 2), // "wc"
QT_MOC_LITERAL(8, 83, 16), // "OnWebSocketClose"
QT_MOC_LITERAL(9, 100, 13), // "OnMiaLoginRes"
QT_MOC_LITERAL(10, 114, 16) // "OnMiaQueryObsRes"

    },
    "MiaLoginDialog\0OnWxLoginResult\0\0cmd\0"
    "json\0OnWebSocketConnect\0MiaWebsocketClient*\0"
    "wc\0OnWebSocketClose\0OnMiaLoginRes\0"
    "OnMiaQueryObsRes"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MiaLoginDialog[] = {

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
       1,    2,   39,    2, 0x09 /* Protected */,
       5,    1,   44,    2, 0x09 /* Protected */,
       8,    1,   47,    2, 0x09 /* Protected */,
       9,    2,   50,    2, 0x09 /* Protected */,
      10,    2,   55,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString,    7,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString,    7,    4,

       0        // eod
};

void MiaLoginDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MiaLoginDialog *_t = static_cast<MiaLoginDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnWxLoginResult((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->OnWebSocketConnect((*reinterpret_cast< MiaWebsocketClient*(*)>(_a[1]))); break;
        case 2: _t->OnWebSocketClose((*reinterpret_cast< MiaWebsocketClient*(*)>(_a[1]))); break;
        case 3: _t->OnMiaLoginRes((*reinterpret_cast< MiaWebsocketClient*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->OnMiaQueryObsRes((*reinterpret_cast< MiaWebsocketClient*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MiaWebsocketClient* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MiaWebsocketClient* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MiaWebsocketClient* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MiaWebsocketClient* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MiaLoginDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MiaLoginDialog.data,
      qt_meta_data_MiaLoginDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MiaLoginDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MiaLoginDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MiaLoginDialog.stringdata0))
        return static_cast<void*>(const_cast< MiaLoginDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MiaLoginDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

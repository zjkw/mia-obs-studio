/****************************************************************************
** Meta object code from reading C++ file 'miahttpcenter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../UI/miahttpcenter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'miahttpcenter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CHttpCenter_t {
    QByteArrayData data[9];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CHttpCenter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CHttpCenter_t qt_meta_stringdata_CHttpCenter = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CHttpCenter"
QT_MOC_LITERAL(1, 12, 8), // "progress"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 3), // "key"
QT_MOC_LITERAL(4, 26, 5), // "total"
QT_MOC_LITERAL(5, 32, 7), // "current"
QT_MOC_LITERAL(6, 40, 6), // "finish"
QT_MOC_LITERAL(7, 47, 4), // "code"
QT_MOC_LITERAL(8, 52, 6) // "extend"

    },
    "CHttpCenter\0progress\0\0key\0total\0current\0"
    "finish\0code\0extend"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CHttpCenter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x06 /* Public */,
       6,    3,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,    3,    7,    8,

       0        // eod
};

void CHttpCenter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CHttpCenter *_t = static_cast<CHttpCenter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->progress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->finish((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CHttpCenter::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CHttpCenter::progress)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CHttpCenter::*_t)(int , int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CHttpCenter::finish)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CHttpCenter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CHttpCenter.data,
      qt_meta_data_CHttpCenter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CHttpCenter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CHttpCenter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CHttpCenter.stringdata0))
        return static_cast<void*>(const_cast< CHttpCenter*>(this));
    if (!strcmp(_clname, "CSingleton<CHttpCenter>"))
        return static_cast< CSingleton<CHttpCenter>*>(const_cast< CHttpCenter*>(this));
    return QObject::qt_metacast(_clname);
}

int CHttpCenter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CHttpCenter::progress(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CHttpCenter::finish(int _t1, int _t2, const QString & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

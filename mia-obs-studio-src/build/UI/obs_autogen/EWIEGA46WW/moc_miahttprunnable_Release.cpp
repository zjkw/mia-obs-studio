/****************************************************************************
** Meta object code from reading C++ file 'miahttprunnable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../UI/miahttprunnable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'miahttprunnable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CHttpRunnable_t {
    QByteArrayData data[12];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CHttpRunnable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CHttpRunnable_t qt_meta_stringdata_CHttpRunnable = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CHttpRunnable"
QT_MOC_LITERAL(1, 14, 8), // "progress"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 3), // "key"
QT_MOC_LITERAL(4, 28, 5), // "total"
QT_MOC_LITERAL(5, 34, 7), // "current"
QT_MOC_LITERAL(6, 42, 6), // "finish"
QT_MOC_LITERAL(7, 49, 4), // "code"
QT_MOC_LITERAL(8, 54, 6), // "extend"
QT_MOC_LITERAL(9, 61, 11), // "replyFinish"
QT_MOC_LITERAL(10, 73, 14), // "QNetworkReply*"
QT_MOC_LITERAL(11, 88, 5) // "reply"

    },
    "CHttpRunnable\0progress\0\0key\0total\0"
    "current\0finish\0code\0extend\0replyFinish\0"
    "QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CHttpRunnable[] = {

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
       1,    3,   29,    2, 0x06 /* Public */,
       6,    3,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   43,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,    3,    7,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void CHttpRunnable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CHttpRunnable *_t = static_cast<CHttpRunnable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->progress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->finish((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: _t->replyFinish((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CHttpRunnable::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CHttpRunnable::progress)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CHttpRunnable::*_t)(int , int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CHttpRunnable::finish)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CHttpRunnable::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CHttpRunnable.data,
      qt_meta_data_CHttpRunnable,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CHttpRunnable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CHttpRunnable::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CHttpRunnable.stringdata0))
        return static_cast<void*>(const_cast< CHttpRunnable*>(this));
    if (!strcmp(_clname, "QRunnable"))
        return static_cast< QRunnable*>(const_cast< CHttpRunnable*>(this));
    return QObject::qt_metacast(_clname);
}

int CHttpRunnable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CHttpRunnable::progress(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CHttpRunnable::finish(int _t1, int _t2, const QString & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_CHttpDownloadRunnable_t {
    QByteArrayData data[4];
    char stringdata0[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CHttpDownloadRunnable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CHttpDownloadRunnable_t qt_meta_stringdata_CHttpDownloadRunnable = {
    {
QT_MOC_LITERAL(0, 0, 21), // "CHttpDownloadRunnable"
QT_MOC_LITERAL(1, 22, 16), // "downloadProgress"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 9) // "readyRead"

    },
    "CHttpDownloadRunnable\0downloadProgress\0"
    "\0readyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CHttpDownloadRunnable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x09 /* Protected */,
       3,    0,   29,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    2,    2,
    QMetaType::Void,

       0        // eod
};

void CHttpDownloadRunnable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CHttpDownloadRunnable *_t = static_cast<CHttpDownloadRunnable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->downloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 1: _t->readyRead(); break;
        default: ;
        }
    }
}

const QMetaObject CHttpDownloadRunnable::staticMetaObject = {
    { &CHttpRunnable::staticMetaObject, qt_meta_stringdata_CHttpDownloadRunnable.data,
      qt_meta_data_CHttpDownloadRunnable,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CHttpDownloadRunnable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CHttpDownloadRunnable::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CHttpDownloadRunnable.stringdata0))
        return static_cast<void*>(const_cast< CHttpDownloadRunnable*>(this));
    return CHttpRunnable::qt_metacast(_clname);
}

int CHttpDownloadRunnable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CHttpRunnable::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_CHttpUploadRunnable_t {
    QByteArrayData data[1];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CHttpUploadRunnable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CHttpUploadRunnable_t qt_meta_stringdata_CHttpUploadRunnable = {
    {
QT_MOC_LITERAL(0, 0, 19) // "CHttpUploadRunnable"

    },
    "CHttpUploadRunnable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CHttpUploadRunnable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void CHttpUploadRunnable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject CHttpUploadRunnable::staticMetaObject = {
    { &CHttpRunnable::staticMetaObject, qt_meta_stringdata_CHttpUploadRunnable.data,
      qt_meta_data_CHttpUploadRunnable,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CHttpUploadRunnable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CHttpUploadRunnable::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CHttpUploadRunnable.stringdata0))
        return static_cast<void*>(const_cast< CHttpUploadRunnable*>(this));
    return CHttpRunnable::qt_metacast(_clname);
}

int CHttpUploadRunnable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CHttpRunnable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_CHttpRequestRunnable_t {
    QByteArrayData data[1];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CHttpRequestRunnable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CHttpRequestRunnable_t qt_meta_stringdata_CHttpRequestRunnable = {
    {
QT_MOC_LITERAL(0, 0, 20) // "CHttpRequestRunnable"

    },
    "CHttpRequestRunnable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CHttpRequestRunnable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void CHttpRequestRunnable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject CHttpRequestRunnable::staticMetaObject = {
    { &CHttpRunnable::staticMetaObject, qt_meta_stringdata_CHttpRequestRunnable.data,
      qt_meta_data_CHttpRequestRunnable,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CHttpRequestRunnable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CHttpRequestRunnable::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CHttpRequestRunnable.stringdata0))
        return static_cast<void*>(const_cast< CHttpRequestRunnable*>(this));
    return CHttpRunnable::qt_metacast(_clname);
}

int CHttpRequestRunnable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CHttpRunnable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

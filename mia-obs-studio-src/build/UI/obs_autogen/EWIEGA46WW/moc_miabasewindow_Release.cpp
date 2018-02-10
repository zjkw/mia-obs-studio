/****************************************************************************
** Meta object code from reading C++ file 'miabasewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../UI/miabasewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'miabasewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CBaseWindow_t {
    QByteArrayData data[8];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CBaseWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CBaseWindow_t qt_meta_stringdata_CBaseWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CBaseWindow"
QT_MOC_LITERAL(1, 12, 6), // "closed"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "onMinimum"
QT_MOC_LITERAL(4, 30, 5), // "bool&"
QT_MOC_LITERAL(5, 36, 3), // "ret"
QT_MOC_LITERAL(6, 40, 9), // "onMaximum"
QT_MOC_LITERAL(7, 50, 7) // "onClose"

    },
    "CBaseWindow\0closed\0\0onMinimum\0bool&\0"
    "ret\0onMaximum\0onClose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CBaseWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   35,    2, 0x09 /* Protected */,
       6,    1,   38,    2, 0x09 /* Protected */,
       7,    1,   41,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void CBaseWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CBaseWindow *_t = static_cast<CBaseWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closed(); break;
        case 1: _t->onMinimum((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onMaximum((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onClose((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CBaseWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CBaseWindow::closed)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CBaseWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CBaseWindow.data,
      qt_meta_data_CBaseWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CBaseWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CBaseWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CBaseWindow.stringdata0))
        return static_cast<void*>(const_cast< CBaseWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int CBaseWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CBaseWindow::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

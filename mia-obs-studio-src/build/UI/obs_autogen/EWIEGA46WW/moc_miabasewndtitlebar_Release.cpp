/****************************************************************************
** Meta object code from reading C++ file 'miabasewndtitlebar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../UI/miabasewndtitlebar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'miabasewndtitlebar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CBaseWndTitleBar_t {
    QByteArrayData data[10];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CBaseWndTitleBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CBaseWndTitleBar_t qt_meta_stringdata_CBaseWndTitleBar = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CBaseWndTitleBar"
QT_MOC_LITERAL(1, 17, 9), // "onMinimum"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "bool&"
QT_MOC_LITERAL(4, 34, 3), // "ret"
QT_MOC_LITERAL(5, 38, 9), // "onMaximum"
QT_MOC_LITERAL(6, 48, 7), // "onClose"
QT_MOC_LITERAL(7, 56, 14), // "onClickMinimum"
QT_MOC_LITERAL(8, 71, 14), // "onClickMaximum"
QT_MOC_LITERAL(9, 86, 12) // "onClickClose"

    },
    "CBaseWndTitleBar\0onMinimum\0\0bool&\0ret\0"
    "onMaximum\0onClose\0onClickMinimum\0"
    "onClickMaximum\0onClickClose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CBaseWndTitleBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   53,    2, 0x09 /* Protected */,
       8,    1,   56,    2, 0x09 /* Protected */,
       9,    1,   59,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void CBaseWndTitleBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CBaseWndTitleBar *_t = static_cast<CBaseWndTitleBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onMinimum((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onMaximum((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onClose((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onClickMinimum((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onClickMaximum((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->onClickClose((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CBaseWndTitleBar::*_t)(bool & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CBaseWndTitleBar::onMinimum)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CBaseWndTitleBar::*_t)(bool & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CBaseWndTitleBar::onMaximum)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CBaseWndTitleBar::*_t)(bool & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CBaseWndTitleBar::onClose)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject CBaseWndTitleBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CBaseWndTitleBar.data,
      qt_meta_data_CBaseWndTitleBar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CBaseWndTitleBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CBaseWndTitleBar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CBaseWndTitleBar.stringdata0))
        return static_cast<void*>(const_cast< CBaseWndTitleBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int CBaseWndTitleBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CBaseWndTitleBar::onMinimum(bool & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CBaseWndTitleBar::onMaximum(bool & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CBaseWndTitleBar::onClose(bool & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'mia-course-list-dlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../UI/mia-course-list-dlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mia-course-list-dlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MiaCourseListDlg_t {
    QByteArrayData data[6];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MiaCourseListDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MiaCourseListDlg_t qt_meta_stringdata_MiaCourseListDlg = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MiaCourseListDlg"
QT_MOC_LITERAL(1, 17, 25), // "miaSelectCourse_destroyed"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 13), // "doubleclicked"
QT_MOC_LITERAL(4, 58, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(5, 75, 4) // "item"

    },
    "MiaCourseListDlg\0miaSelectCourse_destroyed\0"
    "\0doubleclicked\0QListWidgetItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MiaCourseListDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   25,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void MiaCourseListDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MiaCourseListDlg *_t = static_cast<MiaCourseListDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->miaSelectCourse_destroyed(); break;
        case 1: _t->doubleclicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MiaCourseListDlg::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MiaCourseListDlg::miaSelectCourse_destroyed)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MiaCourseListDlg::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MiaCourseListDlg.data,
      qt_meta_data_MiaCourseListDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MiaCourseListDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MiaCourseListDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MiaCourseListDlg.stringdata0))
        return static_cast<void*>(const_cast< MiaCourseListDlg*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MiaCourseListDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void MiaCourseListDlg::miaSelectCourse_destroyed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

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
    QByteArrayData data[14];
    char stringdata0[180];
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
QT_MOC_LITERAL(3, 44, 15), // "onDoubleClicked"
QT_MOC_LITERAL(4, 60, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(5, 77, 4), // "item"
QT_MOC_LITERAL(6, 82, 13), // "onSureClicked"
QT_MOC_LITERAL(7, 96, 15), // "onCancelClicked"
QT_MOC_LITERAL(8, 112, 19), // "slotReplyPixmapLoad"
QT_MOC_LITERAL(9, 132, 14), // "QNetworkReply*"
QT_MOC_LITERAL(10, 147, 5), // "reply"
QT_MOC_LITERAL(11, 153, 10), // "closeEvent"
QT_MOC_LITERAL(12, 164, 12), // "QCloseEvent*"
QT_MOC_LITERAL(13, 177, 2) // "ev"

    },
    "MiaCourseListDlg\0miaSelectCourse_destroyed\0"
    "\0onDoubleClicked\0QListWidgetItem*\0"
    "item\0onSureClicked\0onCancelClicked\0"
    "slotReplyPixmapLoad\0QNetworkReply*\0"
    "reply\0closeEvent\0QCloseEvent*\0ev"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MiaCourseListDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   45,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,
       8,    1,   50,    2, 0x08 /* Private */,
      11,    1,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void MiaCourseListDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MiaCourseListDlg *_t = static_cast<MiaCourseListDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->miaSelectCourse_destroyed(); break;
        case 1: _t->onDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->onSureClicked(); break;
        case 3: _t->onCancelClicked(); break;
        case 4: _t->slotReplyPixmapLoad((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
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

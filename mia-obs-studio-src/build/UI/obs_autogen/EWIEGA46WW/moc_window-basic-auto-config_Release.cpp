/****************************************************************************
** Meta object code from reading C++ file 'window-basic-auto-config.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../UI/window-basic-auto-config.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window-basic-auto-config.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AutoConfig_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AutoConfig_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AutoConfig_t qt_meta_stringdata_AutoConfig = {
    {
QT_MOC_LITERAL(0, 0, 10) // "AutoConfig"

    },
    "AutoConfig"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AutoConfig[] = {

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

void AutoConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject AutoConfig::staticMetaObject = {
    { &QWizard::staticMetaObject, qt_meta_stringdata_AutoConfig.data,
      qt_meta_data_AutoConfig,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AutoConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AutoConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AutoConfig.stringdata0))
        return static_cast<void*>(const_cast< AutoConfig*>(this));
    return QWizard::qt_metacast(_clname);
}

int AutoConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizard::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_AutoConfigStartPage_t {
    QByteArrayData data[4];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AutoConfigStartPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AutoConfigStartPage_t qt_meta_stringdata_AutoConfigStartPage = {
    {
QT_MOC_LITERAL(0, 0, 19), // "AutoConfigStartPage"
QT_MOC_LITERAL(1, 20, 30), // "on_prioritizeStreaming_clicked"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 30) // "on_prioritizeRecording_clicked"

    },
    "AutoConfigStartPage\0on_prioritizeStreaming_clicked\0"
    "\0on_prioritizeRecording_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AutoConfigStartPage[] = {

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
       1,    0,   24,    2, 0x0a /* Public */,
       3,    0,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AutoConfigStartPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AutoConfigStartPage *_t = static_cast<AutoConfigStartPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_prioritizeStreaming_clicked(); break;
        case 1: _t->on_prioritizeRecording_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AutoConfigStartPage::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_AutoConfigStartPage.data,
      qt_meta_data_AutoConfigStartPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AutoConfigStartPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AutoConfigStartPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AutoConfigStartPage.stringdata0))
        return static_cast<void*>(const_cast< AutoConfigStartPage*>(this));
    return QWizardPage::qt_metacast(_clname);
}

int AutoConfigStartPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_AutoConfigVideoPage_t {
    QByteArrayData data[1];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AutoConfigVideoPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AutoConfigVideoPage_t qt_meta_stringdata_AutoConfigVideoPage = {
    {
QT_MOC_LITERAL(0, 0, 19) // "AutoConfigVideoPage"

    },
    "AutoConfigVideoPage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AutoConfigVideoPage[] = {

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

void AutoConfigVideoPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject AutoConfigVideoPage::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_AutoConfigVideoPage.data,
      qt_meta_data_AutoConfigVideoPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AutoConfigVideoPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AutoConfigVideoPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AutoConfigVideoPage.stringdata0))
        return static_cast<void*>(const_cast< AutoConfigVideoPage*>(this));
    return QWizardPage::qt_metacast(_clname);
}

int AutoConfigVideoPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_AutoConfigStreamPage_t {
    QByteArrayData data[7];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AutoConfigStreamPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AutoConfigStreamPage_t qt_meta_stringdata_AutoConfigStreamPage = {
    {
QT_MOC_LITERAL(0, 0, 20), // "AutoConfigStreamPage"
QT_MOC_LITERAL(1, 21, 15), // "on_show_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 14), // "ServiceChanged"
QT_MOC_LITERAL(4, 53, 13), // "UpdateKeyLink"
QT_MOC_LITERAL(5, 67, 16), // "UpdateServerList"
QT_MOC_LITERAL(6, 84, 15) // "UpdateCompleted"

    },
    "AutoConfigStreamPage\0on_show_clicked\0"
    "\0ServiceChanged\0UpdateKeyLink\0"
    "UpdateServerList\0UpdateCompleted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AutoConfigStreamPage[] = {

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
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AutoConfigStreamPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AutoConfigStreamPage *_t = static_cast<AutoConfigStreamPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_show_clicked(); break;
        case 1: _t->ServiceChanged(); break;
        case 2: _t->UpdateKeyLink(); break;
        case 3: _t->UpdateServerList(); break;
        case 4: _t->UpdateCompleted(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AutoConfigStreamPage::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_AutoConfigStreamPage.data,
      qt_meta_data_AutoConfigStreamPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AutoConfigStreamPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AutoConfigStreamPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AutoConfigStreamPage.stringdata0))
        return static_cast<void*>(const_cast< AutoConfigStreamPage*>(this));
    return QWizardPage::qt_metacast(_clname);
}

int AutoConfigStreamPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_AutoConfigTestPage_t {
    QByteArrayData data[8];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AutoConfigTestPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AutoConfigTestPage_t qt_meta_stringdata_AutoConfigTestPage = {
    {
QT_MOC_LITERAL(0, 0, 18), // "AutoConfigTestPage"
QT_MOC_LITERAL(1, 19, 9), // "NextStage"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 13), // "UpdateMessage"
QT_MOC_LITERAL(4, 44, 7), // "message"
QT_MOC_LITERAL(5, 52, 7), // "Failure"
QT_MOC_LITERAL(6, 60, 8), // "Progress"
QT_MOC_LITERAL(7, 69, 10) // "percentage"

    },
    "AutoConfigTestPage\0NextStage\0\0"
    "UpdateMessage\0message\0Failure\0Progress\0"
    "percentage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AutoConfigTestPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       5,    1,   38,    2, 0x0a /* Public */,
       6,    1,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void AutoConfigTestPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AutoConfigTestPage *_t = static_cast<AutoConfigTestPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NextStage(); break;
        case 1: _t->UpdateMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->Failure((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->Progress((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AutoConfigTestPage::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_AutoConfigTestPage.data,
      qt_meta_data_AutoConfigTestPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AutoConfigTestPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AutoConfigTestPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AutoConfigTestPage.stringdata0))
        return static_cast<void*>(const_cast< AutoConfigTestPage*>(this));
    return QWizardPage::qt_metacast(_clname);
}

int AutoConfigTestPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

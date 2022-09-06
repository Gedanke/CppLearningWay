/****************************************************************************
** Meta object code from reading C++ file 'sendemail.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../sendemail.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sendemail.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SendEmail_t {
    QByteArrayData data[16];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SendEmail_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SendEmail_t qt_meta_stringdata_SendEmail = {
    {
QT_MOC_LITERAL(0, 0, 9), // "SendEmail"
QT_MOC_LITERAL(1, 10, 18), // "receiveEmailResult"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "result"
QT_MOC_LITERAL(4, 37, 4), // "stop"
QT_MOC_LITERAL(5, 42, 13), // "setEmailTitle"
QT_MOC_LITERAL(6, 56, 10), // "emailTitle"
QT_MOC_LITERAL(7, 67, 19), // "setSendEmailAddress"
QT_MOC_LITERAL(8, 87, 16), // "sendEmailAddress"
QT_MOC_LITERAL(9, 104, 20), // "setSendEmailPassword"
QT_MOC_LITERAL(10, 125, 17), // "sendEmailPassword"
QT_MOC_LITERAL(11, 143, 24), // "setReceiveEmailAddresses"
QT_MOC_LITERAL(12, 168, 21), // "receiveEmailAddresses"
QT_MOC_LITERAL(13, 190, 6), // "append"
QT_MOC_LITERAL(14, 197, 7), // "content"
QT_MOC_LITERAL(15, 205, 8) // "fileName"

    },
    "SendEmail\0receiveEmailResult\0\0result\0"
    "stop\0setEmailTitle\0emailTitle\0"
    "setSendEmailAddress\0sendEmailAddress\0"
    "setSendEmailPassword\0sendEmailPassword\0"
    "setReceiveEmailAddresses\0receiveEmailAddresses\0"
    "append\0content\0fileName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SendEmail[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   52,    2, 0x0a /* Public */,
       5,    1,   53,    2, 0x0a /* Public */,
       7,    1,   56,    2, 0x0a /* Public */,
       9,    1,   59,    2, 0x0a /* Public */,
      11,    1,   62,    2, 0x0a /* Public */,
      13,    2,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   14,   15,

       0        // eod
};

void SendEmail::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SendEmail *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveEmailResult((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->stop(); break;
        case 2: _t->setEmailTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setSendEmailAddress((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->setSendEmailPassword((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->setReceiveEmailAddresses((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->append((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SendEmail::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SendEmail::receiveEmailResult)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SendEmail::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_SendEmail.data,
    qt_meta_data_SendEmail,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SendEmail::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SendEmail::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SendEmail.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int SendEmail::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void SendEmail::receiveEmailResult(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

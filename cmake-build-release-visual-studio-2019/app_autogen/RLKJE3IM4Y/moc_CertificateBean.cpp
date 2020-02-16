/****************************************************************************
** Meta object code from reading C++ file 'CertificateBean.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/db/CertificateBean.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CertificateBean.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CertificateBean_t {
    QByteArrayData data[11];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CertificateBean_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CertificateBean_t qt_meta_stringdata_CertificateBean = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CertificateBean"
QT_MOC_LITERAL(1, 16, 2), // "id"
QT_MOC_LITERAL(2, 19, 7), // "user_id"
QT_MOC_LITERAL(3, 27, 8), // "username"
QT_MOC_LITERAL(4, 36, 8), // "password"
QT_MOC_LITERAL(5, 45, 12), // "access_token"
QT_MOC_LITERAL(6, 58, 13), // "refresh_token"
QT_MOC_LITERAL(7, 72, 10), // "login_type"
QT_MOC_LITERAL(8, 83, 13), // "save_password"
QT_MOC_LITERAL(9, 97, 10), // "auto_login"
QT_MOC_LITERAL(10, 108, 4) // "time"

    },
    "CertificateBean\0id\0user_id\0username\0"
    "password\0access_token\0refresh_token\0"
    "login_type\0save_password\0auto_login\0"
    "time"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CertificateBean[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      10,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095401,
       2, QMetaType::QString, 0x00095401,
       3, QMetaType::QString, 0x00095401,
       4, QMetaType::QString, 0x00095401,
       5, QMetaType::QString, 0x00095401,
       6, QMetaType::QString, 0x00095401,
       7, QMetaType::QString, 0x00095401,
       8, QMetaType::Bool, 0x00095401,
       9, QMetaType::Bool, 0x00095401,
      10, QMetaType::Int, 0x00095401,

       0        // eod
};

void CertificateBean::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CertificateBean *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getId(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getUserId(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getUsername(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getPassword(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->getAccessToken(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->getRefreshToken(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->getLoginType(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->isSavePassword(); break;
        case 8: *reinterpret_cast< bool*>(_v) = _t->isAutoLogin(); break;
        case 9: *reinterpret_cast< int*>(_v) = _t->getTime(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CertificateBean::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CertificateBean.data,
    qt_meta_data_CertificateBean,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CertificateBean::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CertificateBean::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CertificateBean.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CertificateBean::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

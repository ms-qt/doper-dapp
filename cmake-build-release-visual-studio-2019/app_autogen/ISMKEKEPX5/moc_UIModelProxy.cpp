﻿/****************************************************************************
** Meta object code from reading C++ file 'UIModelProxy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/app/UIModelProxy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UIModelProxy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UIModelProxy_t {
    QByteArrayData data[11];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UIModelProxy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UIModelProxy_t qt_meta_stringdata_UIModelProxy = {
    {
QT_MOC_LITERAL(0, 0, 12), // "UIModelProxy"
QT_MOC_LITERAL(1, 13, 10), // "startLogin"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "loginSuccess"
QT_MOC_LITERAL(4, 38, 9), // "enterRoom"
QT_MOC_LITERAL(5, 48, 6), // "roomId"
QT_MOC_LITERAL(6, 55, 9), // "enterTask"
QT_MOC_LITERAL(7, 65, 6), // "taskId"
QT_MOC_LITERAL(8, 72, 23), // "openMainControllerPanel"
QT_MOC_LITERAL(9, 96, 11), // "sendMessage"
QT_MOC_LITERAL(10, 108, 6) // "userId"

    },
    "UIModelProxy\0startLogin\0\0loginSuccess\0"
    "enterRoom\0roomId\0enterTask\0taskId\0"
    "openMainControllerPanel\0sendMessage\0"
    "userId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UIModelProxy[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    1,   46,    2, 0x06 /* Public */,
       6,    1,   49,    2, 0x06 /* Public */,
       8,    0,   52,    2, 0x06 /* Public */,
       9,    1,   53,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void UIModelProxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UIModelProxy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startLogin(); break;
        case 1: _t->loginSuccess(); break;
        case 2: _t->enterRoom((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->enterTask((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->openMainControllerPanel(); break;
        case 5: _t->sendMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UIModelProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UIModelProxy::startLogin)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UIModelProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UIModelProxy::loginSuccess)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UIModelProxy::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UIModelProxy::enterRoom)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (UIModelProxy::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UIModelProxy::enterTask)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (UIModelProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UIModelProxy::openMainControllerPanel)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (UIModelProxy::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UIModelProxy::sendMessage)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UIModelProxy::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_UIModelProxy.data,
    qt_meta_data_UIModelProxy,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UIModelProxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UIModelProxy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UIModelProxy.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UIModelProxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void UIModelProxy::startLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void UIModelProxy::loginSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void UIModelProxy::enterRoom(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void UIModelProxy::enterTask(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void UIModelProxy::openMainControllerPanel()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void UIModelProxy::sendMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

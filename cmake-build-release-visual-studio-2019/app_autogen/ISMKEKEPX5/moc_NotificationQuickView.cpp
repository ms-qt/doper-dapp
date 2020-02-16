/****************************************************************************
** Meta object code from reading C++ file 'NotificationQuickView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/app/NotificationQuickView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NotificationQuickView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NotificationQuickView_t {
    QByteArrayData data[8];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NotificationQuickView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NotificationQuickView_t qt_meta_stringdata_NotificationQuickView = {
    {
QT_MOC_LITERAL(0, 0, 21), // "NotificationQuickView"
QT_MOC_LITERAL(1, 22, 12), // "loginSuccess"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 9), // "activated"
QT_MOC_LITERAL(4, 46, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(5, 80, 6), // "reason"
QT_MOC_LITERAL(6, 87, 32), // "openMainControllerPaneltriggered"
QT_MOC_LITERAL(7, 120, 7) // "checked"

    },
    "NotificationQuickView\0loginSuccess\0\0"
    "activated\0QSystemTrayIcon::ActivationReason\0"
    "reason\0openMainControllerPaneltriggered\0"
    "checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NotificationQuickView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    1,   30,    2, 0x0a /* Public */,
       6,    1,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void NotificationQuickView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NotificationQuickView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loginSuccess(); break;
        case 1: _t->activated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 2: _t->openMainControllerPaneltriggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NotificationQuickView::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseQQuickView::staticMetaObject>(),
    qt_meta_stringdata_NotificationQuickView.data,
    qt_meta_data_NotificationQuickView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NotificationQuickView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NotificationQuickView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NotificationQuickView.stringdata0))
        return static_cast<void*>(this);
    return BaseQQuickView::qt_metacast(_clname);
}

int NotificationQuickView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseQQuickView::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

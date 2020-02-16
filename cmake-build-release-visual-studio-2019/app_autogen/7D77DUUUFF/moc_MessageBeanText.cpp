/****************************************************************************
** Meta object code from reading C++ file 'MessageBeanText.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/model/db/message/MessageBeanText.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MessageBeanText.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MessageBeanText_t {
    QByteArrayData data[29];
    char stringdata0[304];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MessageBeanText_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MessageBeanText_t qt_meta_stringdata_MessageBeanText = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MessageBeanText"
QT_MOC_LITERAL(1, 16, 12), // "getMessageId"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "setMessageId"
QT_MOC_LITERAL(4, 43, 9), // "messageId"
QT_MOC_LITERAL(5, 53, 11), // "getSenderId"
QT_MOC_LITERAL(6, 65, 11), // "setSenderId"
QT_MOC_LITERAL(7, 77, 8), // "senderId"
QT_MOC_LITERAL(8, 86, 14), // "getTextContent"
QT_MOC_LITERAL(9, 101, 14), // "setTextContent"
QT_MOC_LITERAL(10, 116, 11), // "textContent"
QT_MOC_LITERAL(11, 128, 10), // "getEventId"
QT_MOC_LITERAL(12, 139, 10), // "setEventId"
QT_MOC_LITERAL(13, 150, 7), // "eventId"
QT_MOC_LITERAL(14, 158, 7), // "getTime"
QT_MOC_LITERAL(15, 166, 7), // "setTime"
QT_MOC_LITERAL(16, 174, 4), // "time"
QT_MOC_LITERAL(17, 179, 13), // "getSenderTime"
QT_MOC_LITERAL(18, 193, 13), // "setSenderTime"
QT_MOC_LITERAL(19, 207, 10), // "senderTime"
QT_MOC_LITERAL(20, 218, 14), // "getReceiveTime"
QT_MOC_LITERAL(21, 233, 14), // "setReceiveTime"
QT_MOC_LITERAL(22, 248, 11), // "receiveTime"
QT_MOC_LITERAL(23, 260, 5), // "isMe1"
QT_MOC_LITERAL(24, 266, 7), // "setIsMe"
QT_MOC_LITERAL(25, 274, 4), // "isMe"
QT_MOC_LITERAL(26, 279, 7), // "isRead1"
QT_MOC_LITERAL(27, 287, 9), // "setIsRead"
QT_MOC_LITERAL(28, 297, 6) // "isRead"

    },
    "MessageBeanText\0getMessageId\0\0"
    "setMessageId\0messageId\0getSenderId\0"
    "setSenderId\0senderId\0getTextContent\0"
    "setTextContent\0textContent\0getEventId\0"
    "setEventId\0eventId\0getTime\0setTime\0"
    "time\0getSenderTime\0setSenderTime\0"
    "senderTime\0getReceiveTime\0setReceiveTime\0"
    "receiveTime\0isMe1\0setIsMe\0isMe\0isRead1\0"
    "setIsRead\0isRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MessageBeanText[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       2,  140, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a /* Public */,
       3,    1,  105,    2, 0x0a /* Public */,
       5,    0,  108,    2, 0x0a /* Public */,
       6,    1,  109,    2, 0x0a /* Public */,
       8,    0,  112,    2, 0x0a /* Public */,
       9,    1,  113,    2, 0x0a /* Public */,
      11,    0,  116,    2, 0x0a /* Public */,
      12,    1,  117,    2, 0x0a /* Public */,
      14,    0,  120,    2, 0x0a /* Public */,
      15,    1,  121,    2, 0x0a /* Public */,
      17,    0,  124,    2, 0x0a /* Public */,
      18,    1,  125,    2, 0x0a /* Public */,
      20,    0,  128,    2, 0x0a /* Public */,
      21,    1,  129,    2, 0x0a /* Public */,
      23,    0,  132,    2, 0x0a /* Public */,
      24,    1,  133,    2, 0x0a /* Public */,
      26,    0,  136,    2, 0x0a /* Public */,
      27,    1,  137,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::LongLong,
    QMetaType::Void, QMetaType::LongLong,   16,
    QMetaType::LongLong,
    QMetaType::Void, QMetaType::LongLong,   19,
    QMetaType::LongLong,
    QMetaType::Void, QMetaType::LongLong,   22,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   28,

 // properties: name, type, flags
      10, QMetaType::QString, 0x00095401,
      16, QMetaType::LongLong, 0x00095401,

       0        // eod
};

void MessageBeanText::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MessageBeanText *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getMessageId(); break;
        case 1: _t->setMessageId((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->getSenderId(); break;
        case 3: _t->setSenderId((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->getTextContent(); break;
        case 5: _t->setTextContent((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->getEventId(); break;
        case 7: _t->setEventId((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: { qint64 _r = _t->getTime();
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->setTime((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 10: { qint64 _r = _t->getSenderTime();
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->setSenderTime((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 12: { qint64 _r = _t->getReceiveTime();
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->setReceiveTime((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 14: { bool _r = _t->isMe1();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->setIsMe((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: { bool _r = _t->isRead1();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->setIsRead((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MessageBeanText *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getTextContent(); break;
        case 1: *reinterpret_cast< qint64*>(_v) = _t->getTime(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject MessageBeanText::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MessageBeanText.data,
    qt_meta_data_MessageBeanText,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MessageBeanText::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessageBeanText::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MessageBeanText.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MessageBeanText::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

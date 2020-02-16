/****************************************************************************
** Meta object code from reading C++ file 'emojimodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/emoji/emojimodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'emojimodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Emoji_t {
    QByteArrayData data[3];
    char stringdata0[24];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Emoji_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Emoji_t qt_meta_stringdata_Emoji = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Emoji"
QT_MOC_LITERAL(1, 6, 7), // "unicode"
QT_MOC_LITERAL(2, 14, 9) // "shortname"

    },
    "Emoji\0unicode\0shortname"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Emoji[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       2,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095003,
       2, QMetaType::QString, 0x00095003,

       0        // eod
};

void Emoji::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        auto *_t = reinterpret_cast<Emoji *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->unicode; break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->shortname; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = reinterpret_cast<Emoji *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->unicode != *reinterpret_cast< QString*>(_v)) {
                _t->unicode = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 1:
            if (_t->shortname != *reinterpret_cast< QString*>(_v)) {
                _t->shortname = *reinterpret_cast< QString*>(_v);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Emoji::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_Emoji.data,
    qt_meta_data_Emoji,
    qt_static_metacall,
    nullptr,
    nullptr
} };

struct qt_meta_stringdata_EmojiModel_t {
    QByteArrayData data[16];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EmojiModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EmojiModel_t qt_meta_stringdata_EmojiModel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "EmojiModel"
QT_MOC_LITERAL(1, 11, 14), // "historyChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "emojiUsed"
QT_MOC_LITERAL(4, 37, 9), // "modelData"
QT_MOC_LITERAL(5, 47, 7), // "history"
QT_MOC_LITERAL(6, 55, 11), // "filterModel"
QT_MOC_LITERAL(7, 67, 6), // "filter"
QT_MOC_LITERAL(8, 74, 6), // "people"
QT_MOC_LITERAL(9, 81, 6), // "nature"
QT_MOC_LITERAL(10, 88, 4), // "food"
QT_MOC_LITERAL(11, 93, 8), // "activity"
QT_MOC_LITERAL(12, 102, 6), // "travel"
QT_MOC_LITERAL(13, 109, 7), // "objects"
QT_MOC_LITERAL(14, 117, 7), // "symbols"
QT_MOC_LITERAL(15, 125, 5) // "flags"

    },
    "EmojiModel\0historyChanged\0\0emojiUsed\0"
    "modelData\0history\0filterModel\0filter\0"
    "people\0nature\0food\0activity\0travel\0"
    "objects\0symbols\0flags"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EmojiModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       9,   42, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   35,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    0,   38,    2, 0x02 /* Public */,
       6,    1,   39,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariant,    4,

 // methods: parameters
    QMetaType::QVariantList,
    QMetaType::QVariantList, QMetaType::QString,    7,

 // properties: name, type, flags
       5, QMetaType::QVariantList, 0x00495001,
       8, QMetaType::QVariantList, 0x00095401,
       9, QMetaType::QVariantList, 0x00095401,
      10, QMetaType::QVariantList, 0x00095401,
      11, QMetaType::QVariantList, 0x00095401,
      12, QMetaType::QVariantList, 0x00095401,
      13, QMetaType::QVariantList, 0x00095401,
      14, QMetaType::QVariantList, 0x00095401,
      15, QMetaType::QVariantList, 0x00095401,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,

       0        // eod
};

void EmojiModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EmojiModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->historyChanged(); break;
        case 1: _t->emojiUsed((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 2: { QVariantList _r = _t->history();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 3: { QVariantList _r = _t->filterModel((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EmojiModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EmojiModel::historyChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<EmojiModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariantList*>(_v) = _t->history(); break;
        case 1: *reinterpret_cast< QVariantList*>(_v) = _t->people; break;
        case 2: *reinterpret_cast< QVariantList*>(_v) = _t->nature; break;
        case 3: *reinterpret_cast< QVariantList*>(_v) = _t->food; break;
        case 4: *reinterpret_cast< QVariantList*>(_v) = _t->activity; break;
        case 5: *reinterpret_cast< QVariantList*>(_v) = _t->travel; break;
        case 6: *reinterpret_cast< QVariantList*>(_v) = _t->objects; break;
        case 7: *reinterpret_cast< QVariantList*>(_v) = _t->symbols; break;
        case 8: *reinterpret_cast< QVariantList*>(_v) = _t->flags; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject EmojiModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EmojiModel.data,
    qt_meta_data_EmojiModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EmojiModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EmojiModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EmojiModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EmojiModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void EmojiModel::historyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'Tools.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/TaoJsonModel/Tools.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Tools.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TaoCommon__Tools_t {
    QByteArrayData data[29];
    char stringdata0[304];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TaoCommon__Tools_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TaoCommon__Tools_t qt_meta_stringdata_TaoCommon__Tools = {
    {
QT_MOC_LITERAL(0, 0, 16), // "TaoCommon::Tools"
QT_MOC_LITERAL(1, 17, 11), // "toLocalFile"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "urlStr"
QT_MOC_LITERAL(4, 37, 3), // "url"
QT_MOC_LITERAL(5, 41, 13), // "fromLocalFile"
QT_MOC_LITERAL(6, 55, 4), // "file"
QT_MOC_LITERAL(7, 60, 7), // "isExist"
QT_MOC_LITERAL(8, 68, 8), // "filePath"
QT_MOC_LITERAL(9, 77, 16), // "absoluteFilePath"
QT_MOC_LITERAL(10, 94, 17), // "canonicalFilePath"
QT_MOC_LITERAL(11, 112, 8), // "fileName"
QT_MOC_LITERAL(12, 121, 8), // "baseName"
QT_MOC_LITERAL(13, 130, 16), // "completeBaseName"
QT_MOC_LITERAL(14, 147, 6), // "suffix"
QT_MOC_LITERAL(15, 154, 10), // "bundleName"
QT_MOC_LITERAL(16, 165, 14), // "completeSuffix"
QT_MOC_LITERAL(17, 180, 4), // "path"
QT_MOC_LITERAL(18, 185, 12), // "absolutePath"
QT_MOC_LITERAL(19, 198, 5), // "mkdir"
QT_MOC_LITERAL(20, 204, 6), // "mkpath"
QT_MOC_LITERAL(21, 211, 15), // "toLocalFileList"
QT_MOC_LITERAL(22, 227, 14), // "QList<QString>"
QT_MOC_LITERAL(23, 242, 11), // "QList<QUrl>"
QT_MOC_LITERAL(24, 254, 4), // "urls"
QT_MOC_LITERAL(25, 259, 17), // "checkOrCreatePath"
QT_MOC_LITERAL(26, 277, 8), // "readFile"
QT_MOC_LITERAL(27, 286, 9), // "writeFile"
QT_MOC_LITERAL(28, 296, 7) // "content"

    },
    "TaoCommon::Tools\0toLocalFile\0\0urlStr\0"
    "url\0fromLocalFile\0file\0isExist\0filePath\0"
    "absoluteFilePath\0canonicalFilePath\0"
    "fileName\0baseName\0completeBaseName\0"
    "suffix\0bundleName\0completeSuffix\0path\0"
    "absolutePath\0mkdir\0mkpath\0toLocalFileList\0"
    "QList<QString>\0QList<QUrl>\0urls\0"
    "checkOrCreatePath\0readFile\0writeFile\0"
    "content"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TaoCommon__Tools[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x02 /* Public */,
       1,    1,  122,    2, 0x02 /* Public */,
       5,    1,  125,    2, 0x02 /* Public */,
       7,    1,  128,    2, 0x02 /* Public */,
       8,    1,  131,    2, 0x02 /* Public */,
       9,    1,  134,    2, 0x02 /* Public */,
      10,    1,  137,    2, 0x02 /* Public */,
      11,    1,  140,    2, 0x02 /* Public */,
      12,    1,  143,    2, 0x02 /* Public */,
      13,    1,  146,    2, 0x02 /* Public */,
      14,    1,  149,    2, 0x02 /* Public */,
      15,    1,  152,    2, 0x02 /* Public */,
      16,    1,  155,    2, 0x02 /* Public */,
      17,    1,  158,    2, 0x02 /* Public */,
      18,    1,  161,    2, 0x02 /* Public */,
      19,    1,  164,    2, 0x02 /* Public */,
      20,    1,  167,    2, 0x02 /* Public */,
      21,    1,  170,    2, 0x02 /* Public */,
      25,    1,  173,    2, 0x02 /* Public */,
      26,    1,  176,    2, 0x02 /* Public */,
      27,    2,  179,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::QString, QMetaType::QString,    3,
    QMetaType::QString, QMetaType::QUrl,    4,
    QMetaType::QUrl, QMetaType::QString,    6,
    QMetaType::Bool, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::Bool, QMetaType::QString,    6,
    QMetaType::Bool, QMetaType::QString,    6,
    0x80000000 | 22, 0x80000000 | 23,   24,
    QMetaType::Bool, QMetaType::QString,   17,
    QMetaType::QString, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   17,   28,

       0        // eod
};

void TaoCommon::Tools::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tools *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->toLocalFile((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { QString _r = _t->toLocalFile((*reinterpret_cast< const QUrl(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { QUrl _r = _t->fromLocalFile((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->isExist((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->filePath((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->absoluteFilePath((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->canonicalFilePath((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->fileName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->baseName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->completeBaseName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->suffix((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { QString _r = _t->bundleName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 12: { QString _r = _t->completeSuffix((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 13: { QString _r = _t->path((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 14: { QString _r = _t->absolutePath((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->mkdir((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->mkpath((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { QList<QString> _r = _t->toLocalFileList((*reinterpret_cast< const QList<QUrl>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->checkOrCreatePath((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: { QString _r = _t->readFile((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 20: _t->writeFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QUrl> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TaoCommon::Tools::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TaoCommon__Tools.data,
    qt_meta_data_TaoCommon__Tools,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TaoCommon::Tools::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TaoCommon::Tools::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TaoCommon__Tools.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TaoCommon::Tools::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

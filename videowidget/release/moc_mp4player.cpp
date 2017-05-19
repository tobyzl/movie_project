/****************************************************************************
** Meta object code from reading C++ file 'mp4player.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mp4player.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mp4player.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MP4Player_t {
    QByteArrayData data[15];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MP4Player_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MP4Player_t qt_meta_stringdata_MP4Player = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MP4Player"
QT_MOC_LITERAL(1, 10, 8), // "openFile"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 4), // "play"
QT_MOC_LITERAL(4, 25, 10), // "paintEvent"
QT_MOC_LITERAL(5, 36, 12), // "QPaintEvent*"
QT_MOC_LITERAL(6, 49, 5), // "event"
QT_MOC_LITERAL(7, 55, 17), // "mediaStateChanged"
QT_MOC_LITERAL(8, 73, 15), // "positionChanged"
QT_MOC_LITERAL(9, 89, 8), // "position"
QT_MOC_LITERAL(10, 98, 15), // "durationChanged"
QT_MOC_LITERAL(11, 114, 8), // "duration"
QT_MOC_LITERAL(12, 123, 11), // "setPosition"
QT_MOC_LITERAL(13, 135, 15), // "slotGetOneFrame"
QT_MOC_LITERAL(14, 151, 3) // "img"

    },
    "MP4Player\0openFile\0\0play\0paintEvent\0"
    "QPaintEvent*\0event\0mediaStateChanged\0"
    "positionChanged\0position\0durationChanged\0"
    "duration\0setPosition\0slotGetOneFrame\0"
    "img"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MP4Player[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    1,   56,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    1,   60,    2, 0x08 /* Private */,
      10,    1,   63,    2, 0x08 /* Private */,
      12,    1,   66,    2, 0x08 /* Private */,
      13,    1,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    9,
    QMetaType::Void, QMetaType::LongLong,   11,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::QImage,   14,

       0        // eod
};

void MP4Player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MP4Player *_t = static_cast<MP4Player *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openFile(); break;
        case 1: _t->play(); break;
        case 2: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 3: _t->mediaStateChanged(); break;
        case 4: _t->positionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: _t->durationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 6: _t->setPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->slotGetOneFrame((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MP4Player::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MP4Player.data,
      qt_meta_data_MP4Player,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MP4Player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MP4Player::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MP4Player.stringdata0))
        return static_cast<void*>(const_cast< MP4Player*>(this));
    return QWidget::qt_metacast(_clname);
}

int MP4Player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

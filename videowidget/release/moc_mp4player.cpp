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
    QByteArrayData data[14];
    char stringdata0[151];
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
QT_MOC_LITERAL(4, 25, 17), // "mediaStateChanged"
QT_MOC_LITERAL(5, 43, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(6, 63, 5), // "state"
QT_MOC_LITERAL(7, 69, 15), // "positionChanged"
QT_MOC_LITERAL(8, 85, 8), // "position"
QT_MOC_LITERAL(9, 94, 15), // "durationChanged"
QT_MOC_LITERAL(10, 110, 8), // "duration"
QT_MOC_LITERAL(11, 119, 11), // "setPosition"
QT_MOC_LITERAL(12, 131, 15), // "slotGetOneFrame"
QT_MOC_LITERAL(13, 147, 3) // "img"

    },
    "MP4Player\0openFile\0\0play\0mediaStateChanged\0"
    "QMediaPlayer::State\0state\0positionChanged\0"
    "position\0durationChanged\0duration\0"
    "setPosition\0slotGetOneFrame\0img"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MP4Player[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    1,   51,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
       9,    1,   57,    2, 0x08 /* Private */,
      11,    1,   60,    2, 0x08 /* Private */,
      12,    1,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::LongLong,    8,
    QMetaType::Void, QMetaType::LongLong,   10,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QImage,   13,

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
        case 2: _t->mediaStateChanged((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 3: _t->positionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: _t->durationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: _t->setPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->slotGetOneFrame((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

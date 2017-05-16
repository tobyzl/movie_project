/****************************************************************************
** Meta object code from reading C++ file 'showmovie.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../showmovie.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showmovie.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ShowMovieWidget_t {
    QByteArrayData data[14];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShowMovieWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShowMovieWidget_t qt_meta_stringdata_ShowMovieWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ShowMovieWidget"
QT_MOC_LITERAL(1, 16, 13), // "createWidgets"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 14), // "togglePlayback"
QT_MOC_LITERAL(4, 46, 11), // "updateState"
QT_MOC_LITERAL(5, 58, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(6, 78, 5), // "state"
QT_MOC_LITERAL(7, 84, 14), // "updatePosition"
QT_MOC_LITERAL(8, 99, 8), // "position"
QT_MOC_LITERAL(9, 108, 14), // "updateDuration"
QT_MOC_LITERAL(10, 123, 8), // "duration"
QT_MOC_LITERAL(11, 132, 11), // "seekForward"
QT_MOC_LITERAL(12, 144, 12), // "seekBackward"
QT_MOC_LITERAL(13, 157, 11) // "setPosition"

    },
    "ShowMovieWidget\0createWidgets\0\0"
    "togglePlayback\0updateState\0"
    "QMediaPlayer::State\0state\0updatePosition\0"
    "position\0updateDuration\0duration\0"
    "seekForward\0seekBackward\0setPosition"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShowMovieWidget[] = {

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
       7,    1,   59,    2, 0x0a /* Public */,
       9,    1,   62,    2, 0x0a /* Public */,
      11,    0,   65,    2, 0x0a /* Public */,
      12,    0,   66,    2, 0x0a /* Public */,
      13,    1,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::LongLong,    8,
    QMetaType::Void, QMetaType::LongLong,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void ShowMovieWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ShowMovieWidget *_t = static_cast<ShowMovieWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createWidgets(); break;
        case 1: _t->togglePlayback(); break;
        case 2: _t->updateState((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 3: _t->updatePosition((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: _t->updateDuration((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: _t->seekForward(); break;
        case 6: _t->seekBackward(); break;
        case 7: _t->setPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
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

const QMetaObject ShowMovieWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ShowMovieWidget.data,
      qt_meta_data_ShowMovieWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ShowMovieWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShowMovieWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ShowMovieWidget.stringdata0))
        return static_cast<void*>(const_cast< ShowMovieWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ShowMovieWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'mainwindowtetris.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../TetrisProjekt/mainwindowtetris.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindowtetris.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindowTetris_t {
    uint offsetsAndSizes[12];
    char stringdata0[17];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[23];
    char stringdata5[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindowTetris_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_MainWindowTetris_t qt_meta_stringdata_MainWindowTetris = {
    {
        QT_MOC_LITERAL(0, 16),  // "MainWindowTetris"
        QT_MOC_LITERAL(17, 14),  // "onBoardUpdated"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(55, 22),  // "on_pauseButton_clicked"
        QT_MOC_LITERAL(78, 22)   // "on_clearButton_clicked"
    },
    "MainWindowTetris",
    "onBoardUpdated",
    "",
    "on_pushButton_clicked",
    "on_pauseButton_clicked",
    "on_clearButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindowTetris[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x08,    1 /* Private */,
       3,    0,   39,    2, 0x08,    2 /* Private */,
       4,    0,   40,    2, 0x08,    3 /* Private */,
       5,    0,   41,    2, 0x08,    4 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindowTetris::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindowTetris *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onBoardUpdated(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pauseButton_clicked(); break;
        case 3: _t->on_clearButton_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject MainWindowTetris::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindowTetris.offsetsAndSizes,
    qt_meta_data_MainWindowTetris,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindowTetris_t
, QtPrivate::TypeAndForceComplete<MainWindowTetris, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindowTetris::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindowTetris::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindowTetris.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindowTetris::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

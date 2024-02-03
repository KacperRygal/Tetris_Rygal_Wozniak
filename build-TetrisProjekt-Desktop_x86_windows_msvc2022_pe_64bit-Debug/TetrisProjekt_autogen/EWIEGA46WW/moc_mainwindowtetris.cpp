/****************************************************************************
** Meta object code from reading C++ file 'mainwindowtetris.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../TetrisProjekt/mainwindowtetris.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindowtetris.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowTetrisENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowTetrisENDCLASS = QtMocHelpers::stringData(
    "MainWindowTetris",
    "onBoardUpdated",
    "",
    "on_pushButton_clicked",
    "on_pauseButton_clicked",
    "on_clearButton_clicked",
    "zamknijOkno",
    "on_ZapiszBtn_clicked",
    "zamknijZapisane"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowTetrisENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[17];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[23];
    char stringdata5[23];
    char stringdata6[12];
    char stringdata7[21];
    char stringdata8[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowTetrisENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowTetrisENDCLASS_t qt_meta_stringdata_CLASSMainWindowTetrisENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "MainWindowTetris"
        QT_MOC_LITERAL(17, 14),  // "onBoardUpdated"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(55, 22),  // "on_pauseButton_clicked"
        QT_MOC_LITERAL(78, 22),  // "on_clearButton_clicked"
        QT_MOC_LITERAL(101, 11),  // "zamknijOkno"
        QT_MOC_LITERAL(113, 20),  // "on_ZapiszBtn_clicked"
        QT_MOC_LITERAL(134, 15)   // "zamknijZapisane"
    },
    "MainWindowTetris",
    "onBoardUpdated",
    "",
    "on_pushButton_clicked",
    "on_pauseButton_clicked",
    "on_clearButton_clicked",
    "zamknijOkno",
    "on_ZapiszBtn_clicked",
    "zamknijZapisane"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowTetrisENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindowTetris::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowTetrisENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowTetrisENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowTetrisENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindowTetris, std::true_type>,
        // method 'onBoardUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pauseButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clearButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'zamknijOkno'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ZapiszBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'zamknijZapisane'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

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
        case 4: _t->zamknijOkno(); break;
        case 5: _t->on_ZapiszBtn_clicked(); break;
        case 6: _t->zamknijZapisane(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *MainWindowTetris::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindowTetris::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowTetrisENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindowTetris::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP

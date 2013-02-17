/****************************************************************************
** Meta object code from reading C++ file 'visiut3.h'
**
** Created: Sun Feb 17 23:55:13 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "visiut3.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'visiut3.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Visiut3[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      35,    8,    8,    8, 0x0a,
      67,    8,    8,    8, 0x0a,
      97,    8,    8,    8, 0x0a,
     124,    8,    8,    8, 0x0a,
     152,    8,    8,    8, 0x0a,
     177,    8,    8,    8, 0x0a,
     203,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Visiut3[] = {
    "Visiut3\0\0on_ActionOpen_triggered()\0"
    "on_ActionProperties_triggered()\0"
    "on_ActionNegative_triggered()\0"
    "on_ActionAbout_triggered()\0"
    "on_ActionMirror_triggered()\0"
    "on_ActionNew_triggered()\0"
    "on_ActionSave_triggered()\0"
    "on_ActionCancel_triggered()\0"
};

void Visiut3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Visiut3 *_t = static_cast<Visiut3 *>(_o);
        switch (_id) {
        case 0: _t->on_ActionOpen_triggered(); break;
        case 1: _t->on_ActionProperties_triggered(); break;
        case 2: _t->on_ActionNegative_triggered(); break;
        case 3: _t->on_ActionAbout_triggered(); break;
        case 4: _t->on_ActionMirror_triggered(); break;
        case 5: _t->on_ActionNew_triggered(); break;
        case 6: _t->on_ActionSave_triggered(); break;
        case 7: _t->on_ActionCancel_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Visiut3::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Visiut3::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Visiut3,
      qt_meta_data_Visiut3, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Visiut3::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Visiut3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Visiut3::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Visiut3))
        return static_cast<void*>(const_cast< Visiut3*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Visiut3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

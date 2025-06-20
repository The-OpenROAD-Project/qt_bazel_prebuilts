/****************************************************************************
** Meta object code from reading C++ file 'qmdisubwindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qmdisubwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmdisubwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
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
struct qt_meta_tag_ZN13QMdiSubWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto QMdiSubWindow::qt_create_metaobjectdata<qt_meta_tag_ZN13QMdiSubWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QMdiSubWindow",
        "windowStateChanged",
        "",
        "Qt::WindowStates",
        "oldState",
        "newState",
        "aboutToActivate",
        "showSystemMenu",
        "showShaded",
        "_q_updateStaysOnTopHint",
        "_q_enterInteractiveMode",
        "_q_processFocusChanged",
        "QWidget*",
        "keyboardSingleStep",
        "keyboardPageStep"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'windowStateChanged'
        QtMocHelpers::SignalData<void(Qt::WindowStates, Qt::WindowStates)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 3, 5 },
        }}),
        // Signal 'aboutToActivate'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showSystemMenu'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showShaded'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_updateStaysOnTopHint'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_enterInteractiveMode'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_processFocusChanged'
        QtMocHelpers::SlotData<void(QWidget *, QWidget *)>(11, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 12, 2 }, { 0x80000000 | 12, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'keyboardSingleStep'
        QtMocHelpers::PropertyData<int>(13, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'keyboardPageStep'
        QtMocHelpers::PropertyData<int>(14, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QMdiSubWindow, qt_meta_tag_ZN13QMdiSubWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QMdiSubWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QMdiSubWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QMdiSubWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13QMdiSubWindowE_t>.metaTypes,
    nullptr
} };

void QMdiSubWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QMdiSubWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->windowStateChanged((*reinterpret_cast< std::add_pointer_t<Qt::WindowStates>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::WindowStates>>(_a[2]))); break;
        case 1: _t->aboutToActivate(); break;
        case 2: _t->showSystemMenu(); break;
        case 3: _t->showShaded(); break;
        case 4: _t->d_func()->_q_updateStaysOnTopHint(); break;
        case 5: _t->d_func()->_q_enterInteractiveMode(); break;
        case 6: _t->d_func()->_q_processFocusChanged((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QMdiSubWindow::*)(Qt::WindowStates , Qt::WindowStates )>(_a, &QMdiSubWindow::windowStateChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QMdiSubWindow::*)()>(_a, &QMdiSubWindow::aboutToActivate, 1))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->keyboardSingleStep(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->keyboardPageStep(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setKeyboardSingleStep(*reinterpret_cast<int*>(_v)); break;
        case 1: _t->setKeyboardPageStep(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QMdiSubWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMdiSubWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QMdiSubWindowE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QMdiSubWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QMdiSubWindow::windowStateChanged(Qt::WindowStates _t1, Qt::WindowStates _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void QMdiSubWindow::aboutToActivate()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP

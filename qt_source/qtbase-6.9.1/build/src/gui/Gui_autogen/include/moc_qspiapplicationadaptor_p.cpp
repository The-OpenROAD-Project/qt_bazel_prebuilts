/****************************************************************************
** Meta object code from reading C++ file 'qspiapplicationadaptor_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/accessible/linux/qspiapplicationadaptor_p.h"
#include <QtDBus/QDBusMessage>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qspiapplicationadaptor_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN22QSpiApplicationAdaptorE_t {};
} // unnamed namespace

template <> constexpr inline auto QSpiApplicationAdaptor::qt_create_metaobjectdata<qt_meta_tag_ZN22QSpiApplicationAdaptorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSpiApplicationAdaptor",
        "windowActivated",
        "",
        "window",
        "active",
        "notifyKeyboardListenerCallback",
        "QDBusMessage",
        "message",
        "notifyKeyboardListenerError",
        "QDBusError",
        "error"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'windowActivated'
        QtMocHelpers::SignalData<void(QObject *, bool)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QObjectStar, 3 }, { QMetaType::Bool, 4 },
        }}),
        // Slot 'notifyKeyboardListenerCallback'
        QtMocHelpers::SlotData<void(const QDBusMessage &)>(5, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Slot 'notifyKeyboardListenerError'
        QtMocHelpers::SlotData<void(const QDBusError &, const QDBusMessage &)>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 9, 10 }, { 0x80000000 | 6, 7 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QSpiApplicationAdaptor, qt_meta_tag_ZN22QSpiApplicationAdaptorE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSpiApplicationAdaptor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22QSpiApplicationAdaptorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22QSpiApplicationAdaptorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN22QSpiApplicationAdaptorE_t>.metaTypes,
    nullptr
} };

void QSpiApplicationAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QSpiApplicationAdaptor *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->windowActivated((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 1: _t->notifyKeyboardListenerCallback((*reinterpret_cast< std::add_pointer_t<QDBusMessage>>(_a[1]))); break;
        case 2: _t->notifyKeyboardListenerError((*reinterpret_cast< std::add_pointer_t<QDBusError>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDBusMessage>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QSpiApplicationAdaptor::*)(QObject * , bool )>(_a, &QSpiApplicationAdaptor::windowActivated, 0))
            return;
    }
}

const QMetaObject *QSpiApplicationAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSpiApplicationAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22QSpiApplicationAdaptorE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QSpiApplicationAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QSpiApplicationAdaptor::windowActivated(QObject * _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}
QT_WARNING_POP

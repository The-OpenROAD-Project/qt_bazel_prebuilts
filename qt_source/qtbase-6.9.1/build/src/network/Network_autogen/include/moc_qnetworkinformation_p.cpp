/****************************************************************************
** Meta object code from reading C++ file 'qnetworkinformation_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/kernel/qnetworkinformation_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnetworkinformation_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN26QNetworkInformationBackendE_t {};
} // unnamed namespace

template <> constexpr inline auto QNetworkInformationBackend::qt_create_metaobjectdata<qt_meta_tag_ZN26QNetworkInformationBackendE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QNetworkInformationBackend",
        "reachabilityChanged",
        "",
        "QNetworkInformation::Reachability",
        "reachability",
        "behindCaptivePortalChanged",
        "behindPortal",
        "transportMediumChanged",
        "QNetworkInformation::TransportMedium",
        "medium",
        "isMeteredChanged",
        "isMetered"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'reachabilityChanged'
        QtMocHelpers::SignalData<void(QNetworkInformation::Reachability)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'behindCaptivePortalChanged'
        QtMocHelpers::SignalData<void(bool)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 6 },
        }}),
        // Signal 'transportMediumChanged'
        QtMocHelpers::SignalData<void(QNetworkInformation::TransportMedium)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Signal 'isMeteredChanged'
        QtMocHelpers::SignalData<void(bool)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 11 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QNetworkInformationBackend, qt_meta_tag_ZN26QNetworkInformationBackendE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QNetworkInformationBackend::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN26QNetworkInformationBackendE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN26QNetworkInformationBackendE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN26QNetworkInformationBackendE_t>.metaTypes,
    nullptr
} };

void QNetworkInformationBackend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QNetworkInformationBackend *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->reachabilityChanged((*reinterpret_cast< std::add_pointer_t<QNetworkInformation::Reachability>>(_a[1]))); break;
        case 1: _t->behindCaptivePortalChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->transportMediumChanged((*reinterpret_cast< std::add_pointer_t<QNetworkInformation::TransportMedium>>(_a[1]))); break;
        case 3: _t->isMeteredChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QNetworkInformationBackend::*)(QNetworkInformation::Reachability )>(_a, &QNetworkInformationBackend::reachabilityChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QNetworkInformationBackend::*)(bool )>(_a, &QNetworkInformationBackend::behindCaptivePortalChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QNetworkInformationBackend::*)(QNetworkInformation::TransportMedium )>(_a, &QNetworkInformationBackend::transportMediumChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QNetworkInformationBackend::*)(bool )>(_a, &QNetworkInformationBackend::isMeteredChanged, 3))
            return;
    }
}

const QMetaObject *QNetworkInformationBackend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNetworkInformationBackend::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN26QNetworkInformationBackendE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QNetworkInformationBackend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QNetworkInformationBackend::reachabilityChanged(QNetworkInformation::Reachability _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QNetworkInformationBackend::behindCaptivePortalChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QNetworkInformationBackend::transportMediumChanged(QNetworkInformation::TransportMedium _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QNetworkInformationBackend::isMeteredChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN33QNetworkInformationBackendFactoryE_t {};
} // unnamed namespace

template <> constexpr inline auto QNetworkInformationBackendFactory::qt_create_metaobjectdata<qt_meta_tag_ZN33QNetworkInformationBackendFactoryE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QNetworkInformationBackendFactory"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QNetworkInformationBackendFactory, qt_meta_tag_ZN33QNetworkInformationBackendFactoryE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QNetworkInformationBackendFactory::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN33QNetworkInformationBackendFactoryE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN33QNetworkInformationBackendFactoryE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN33QNetworkInformationBackendFactoryE_t>.metaTypes,
    nullptr
} };

void QNetworkInformationBackendFactory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QNetworkInformationBackendFactory *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QNetworkInformationBackendFactory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNetworkInformationBackendFactory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN33QNetworkInformationBackendFactoryE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QNetworkInformationBackendFactory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP

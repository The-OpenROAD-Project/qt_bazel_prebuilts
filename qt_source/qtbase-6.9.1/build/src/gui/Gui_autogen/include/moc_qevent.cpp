/****************************************************************************
** Meta object code from reading C++ file 'qevent.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qevent.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qevent.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13QPointerEventE_t {};
} // unnamed namespace

template <> constexpr inline auto QPointerEvent::qt_create_metaobjectdata<qt_meta_tag_ZN13QPointerEventE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPointerEvent"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QPointerEvent, qt_meta_tag_ZN13QPointerEventE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPointerEvent::staticMetaObject = { {
    QtPrivate::MetaObjectForType<QInputEvent>::value,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QPointerEventE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QPointerEventE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13QPointerEventE_t>.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN17QSinglePointEventE_t {};
} // unnamed namespace

template <> constexpr inline auto QSinglePointEvent::qt_create_metaobjectdata<qt_meta_tag_ZN17QSinglePointEventE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSinglePointEvent",
        "exclusivePointGrabber"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'exclusivePointGrabber'
        QtMocHelpers::PropertyData<QObject*>(1, QMetaType::QObjectStar, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QSinglePointEvent, qt_meta_tag_ZN17QSinglePointEventE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSinglePointEvent::staticMetaObject = { {
    QtPrivate::MetaObjectForType<QPointerEvent>::value,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QSinglePointEventE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QSinglePointEventE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QSinglePointEventE_t>.metaTypes,
    nullptr
} };

void QSinglePointEvent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<QSinglePointEvent *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QObject**>(_v) = _t->exclusivePointGrabber(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setExclusivePointGrabber(*reinterpret_cast<QObject**>(_v)); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN11QWheelEventE_t {};
} // unnamed namespace

template <> constexpr inline auto QWheelEvent::qt_create_metaobjectdata<qt_meta_tag_ZN11QWheelEventE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QWheelEvent",
        "device",
        "const QPointingDevice*",
        "pixelDelta",
        "angleDelta",
        "phase",
        "Qt::ScrollPhase",
        "inverted"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'device'
        QtMocHelpers::PropertyData<const QPointingDevice*>(1, 0x80000000 | 2, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'pixelDelta'
        QtMocHelpers::PropertyData<QPoint>(3, QMetaType::QPoint, QMC::DefaultPropertyFlags),
        // property 'angleDelta'
        QtMocHelpers::PropertyData<QPoint>(4, QMetaType::QPoint, QMC::DefaultPropertyFlags),
        // property 'phase'
        QtMocHelpers::PropertyData<Qt::ScrollPhase>(5, 0x80000000 | 6, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'inverted'
        QtMocHelpers::PropertyData<bool>(7, QMetaType::Bool, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QWheelEvent, qt_meta_tag_ZN11QWheelEventE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QWheelEvent::staticMetaObject = { {
    QtPrivate::MetaObjectForType<QSinglePointEvent>::value,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QWheelEventE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QWheelEventE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11QWheelEventE_t>.metaTypes,
    nullptr
} };

void QWheelEvent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<QWheelEvent *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<const QPointingDevice**>(_v) = _t->pointingDevice(); break;
        case 1: *reinterpret_cast<QPoint*>(_v) = _t->pixelDelta(); break;
        case 2: *reinterpret_cast<QPoint*>(_v) = _t->angleDelta(); break;
        case 3: *reinterpret_cast<Qt::ScrollPhase*>(_v) = _t->phase(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->inverted(); break;
        default: break;
        }
    }
}
QT_WARNING_POP

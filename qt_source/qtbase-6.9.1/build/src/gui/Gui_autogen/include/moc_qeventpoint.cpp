/****************************************************************************
** Meta object code from reading C++ file 'qeventpoint.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qeventpoint.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qeventpoint.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11QEventPointE_t {};
} // unnamed namespace

template <> constexpr inline auto QEventPoint::qt_create_metaobjectdata<qt_meta_tag_ZN11QEventPointE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QEventPoint",
        "accepted",
        "device",
        "const QPointingDevice*",
        "id",
        "uniqueId",
        "QPointingDeviceUniqueId",
        "state",
        "State",
        "timestamp",
        "pressTimestamp",
        "lastTimestamp",
        "timeHeld",
        "pressure",
        "rotation",
        "ellipseDiameters",
        "velocity",
        "position",
        "pressPosition",
        "grabPosition",
        "lastPosition",
        "scenePosition",
        "scenePressPosition",
        "sceneGrabPosition",
        "sceneLastPosition",
        "globalPosition",
        "globalPressPosition",
        "globalGrabPosition",
        "globalLastPosition",
        "States",
        "Unknown",
        "Stationary",
        "Pressed",
        "Updated",
        "Released"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'accepted'
        QtMocHelpers::PropertyData<bool>(1, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'device'
        QtMocHelpers::PropertyData<const QPointingDevice*>(2, 0x80000000 | 3, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'id'
        QtMocHelpers::PropertyData<int>(4, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'uniqueId'
        QtMocHelpers::PropertyData<QPointingDeviceUniqueId>(5, 0x80000000 | 6, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'state'
        QtMocHelpers::PropertyData<State>(7, 0x80000000 | 8, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'timestamp'
        QtMocHelpers::PropertyData<ulong>(9, QMetaType::ULong, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'pressTimestamp'
        QtMocHelpers::PropertyData<ulong>(10, QMetaType::ULong, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'lastTimestamp'
        QtMocHelpers::PropertyData<ulong>(11, QMetaType::ULong, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'timeHeld'
        QtMocHelpers::PropertyData<qreal>(12, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'pressure'
        QtMocHelpers::PropertyData<qreal>(13, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'rotation'
        QtMocHelpers::PropertyData<qreal>(14, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'ellipseDiameters'
        QtMocHelpers::PropertyData<QSizeF>(15, QMetaType::QSizeF, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'velocity'
        QtMocHelpers::PropertyData<QVector2D>(16, QMetaType::QVector2D, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'position'
        QtMocHelpers::PropertyData<QPointF>(17, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'pressPosition'
        QtMocHelpers::PropertyData<QPointF>(18, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'grabPosition'
        QtMocHelpers::PropertyData<QPointF>(19, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'lastPosition'
        QtMocHelpers::PropertyData<QPointF>(20, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'scenePosition'
        QtMocHelpers::PropertyData<QPointF>(21, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'scenePressPosition'
        QtMocHelpers::PropertyData<QPointF>(22, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'sceneGrabPosition'
        QtMocHelpers::PropertyData<QPointF>(23, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'sceneLastPosition'
        QtMocHelpers::PropertyData<QPointF>(24, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'globalPosition'
        QtMocHelpers::PropertyData<QPointF>(25, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'globalPressPosition'
        QtMocHelpers::PropertyData<QPointF>(26, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'globalGrabPosition'
        QtMocHelpers::PropertyData<QPointF>(27, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'globalLastPosition'
        QtMocHelpers::PropertyData<QPointF>(28, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Constant),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'States'
        QtMocHelpers::EnumData<States>(29, 8, QMC::EnumFlags{}).add({
            {   30, State::Unknown },
            {   31, State::Stationary },
            {   32, State::Pressed },
            {   33, State::Updated },
            {   34, State::Released },
        }),
    };
    return QtMocHelpers::metaObjectData<QEventPoint, qt_meta_tag_ZN11QEventPointE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QEventPoint::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QEventPointE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QEventPointE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11QEventPointE_t>.metaTypes,
    nullptr
} };

void QEventPoint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<QEventPoint *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isAccepted(); break;
        case 1: *reinterpret_cast<const QPointingDevice**>(_v) = _t->device(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->id(); break;
        case 3: *reinterpret_cast<QPointingDeviceUniqueId*>(_v) = _t->uniqueId(); break;
        case 4: *reinterpret_cast<State*>(_v) = _t->state(); break;
        case 5: *reinterpret_cast<ulong*>(_v) = _t->timestamp(); break;
        case 6: *reinterpret_cast<ulong*>(_v) = _t->pressTimestamp(); break;
        case 7: *reinterpret_cast<ulong*>(_v) = _t->lastTimestamp(); break;
        case 8: *reinterpret_cast<qreal*>(_v) = _t->timeHeld(); break;
        case 9: *reinterpret_cast<qreal*>(_v) = _t->pressure(); break;
        case 10: *reinterpret_cast<qreal*>(_v) = _t->rotation(); break;
        case 11: *reinterpret_cast<QSizeF*>(_v) = _t->ellipseDiameters(); break;
        case 12: *reinterpret_cast<QVector2D*>(_v) = _t->velocity(); break;
        case 13: *reinterpret_cast<QPointF*>(_v) = _t->position(); break;
        case 14: *reinterpret_cast<QPointF*>(_v) = _t->pressPosition(); break;
        case 15: *reinterpret_cast<QPointF*>(_v) = _t->grabPosition(); break;
        case 16: *reinterpret_cast<QPointF*>(_v) = _t->lastPosition(); break;
        case 17: *reinterpret_cast<QPointF*>(_v) = _t->scenePosition(); break;
        case 18: *reinterpret_cast<QPointF*>(_v) = _t->scenePressPosition(); break;
        case 19: *reinterpret_cast<QPointF*>(_v) = _t->sceneGrabPosition(); break;
        case 20: *reinterpret_cast<QPointF*>(_v) = _t->sceneLastPosition(); break;
        case 21: *reinterpret_cast<QPointF*>(_v) = _t->globalPosition(); break;
        case 22: *reinterpret_cast<QPointF*>(_v) = _t->globalPressPosition(); break;
        case 23: *reinterpret_cast<QPointF*>(_v) = _t->globalGrabPosition(); break;
        case 24: *reinterpret_cast<QPointF*>(_v) = _t->globalLastPosition(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAccepted(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}
QT_WARNING_POP

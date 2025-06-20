/****************************************************************************
** Meta object code from reading C++ file 'qgesture.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/kernel/qgesture.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgesture.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN8QGestureE_t {};
} // unnamed namespace

template <> constexpr inline auto QGesture::qt_create_metaobjectdata<qt_meta_tag_ZN8QGestureE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QGesture",
        "state",
        "Qt::GestureState",
        "gestureType",
        "Qt::GestureType",
        "gestureCancelPolicy",
        "QGesture::GestureCancelPolicy",
        "hotSpot",
        "hasHotSpot"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'state'
        QtMocHelpers::PropertyData<Qt::GestureState>(1, 0x80000000 | 2, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'gestureType'
        QtMocHelpers::PropertyData<Qt::GestureType>(3, 0x80000000 | 4, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'gestureCancelPolicy'
        QtMocHelpers::PropertyData<QGesture::GestureCancelPolicy>(5, 0x80000000 | 6, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'hotSpot'
        QtMocHelpers::PropertyData<QPointF>(7, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet),
        // property 'hasHotSpot'
        QtMocHelpers::PropertyData<bool>(8, QMetaType::Bool, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QGesture, qt_meta_tag_ZN8QGestureE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QGesture::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QGestureE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QGestureE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8QGestureE_t>.metaTypes,
    nullptr
} };

void QGesture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QGesture *>(_o);
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGesture::GestureCancelPolicy >(); break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Qt::GestureState >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Qt::GestureType >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<Qt::GestureState*>(_v) = _t->state(); break;
        case 1: *reinterpret_cast<Qt::GestureType*>(_v) = _t->gestureType(); break;
        case 2: *reinterpret_cast<QGesture::GestureCancelPolicy*>(_v) = _t->gestureCancelPolicy(); break;
        case 3: *reinterpret_cast<QPointF*>(_v) = _t->hotSpot(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->hasHotSpot(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setGestureCancelPolicy(*reinterpret_cast<QGesture::GestureCancelPolicy*>(_v)); break;
        case 3: _t->setHotSpot(*reinterpret_cast<QPointF*>(_v)); break;
        default: break;
        }
    }
if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 3: _t->unsetHotSpot(); break;
        default: break;
        }
    }
}

const QMetaObject *QGesture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGesture::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QGestureE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGesture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN11QPanGestureE_t {};
} // unnamed namespace

template <> constexpr inline auto QPanGesture::qt_create_metaobjectdata<qt_meta_tag_ZN11QPanGestureE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPanGesture",
        "lastOffset",
        "offset",
        "delta",
        "acceleration",
        "horizontalVelocity",
        "verticalVelocity"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'lastOffset'
        QtMocHelpers::PropertyData<QPointF>(1, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'offset'
        QtMocHelpers::PropertyData<QPointF>(2, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'delta'
        QtMocHelpers::PropertyData<QPointF>(3, QMetaType::QPointF, QMC::Readable | QMC::Designable | QMC::Scriptable),
        // property 'acceleration'
        QtMocHelpers::PropertyData<qreal>(4, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'horizontalVelocity'
        QtMocHelpers::PropertyData<qreal>(5, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'verticalVelocity'
        QtMocHelpers::PropertyData<qreal>(6, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QPanGesture, qt_meta_tag_ZN11QPanGestureE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPanGesture::staticMetaObject = { {
    QMetaObject::SuperData::link<QGesture::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QPanGestureE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QPanGestureE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11QPanGestureE_t>.metaTypes,
    nullptr
} };

void QPanGesture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPanGesture *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QPointF*>(_v) = _t->lastOffset(); break;
        case 1: *reinterpret_cast<QPointF*>(_v) = _t->offset(); break;
        case 2: *reinterpret_cast<QPointF*>(_v) = _t->delta(); break;
        case 3: *reinterpret_cast<qreal*>(_v) = _t->acceleration(); break;
        case 4: *reinterpret_cast<qreal*>(_v) = _t->QPanGesture::d_func()->horizontalVelocity(); break;
        case 5: *reinterpret_cast<qreal*>(_v) = _t->QPanGesture::d_func()->verticalVelocity(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLastOffset(*reinterpret_cast<QPointF*>(_v)); break;
        case 1: _t->setOffset(*reinterpret_cast<QPointF*>(_v)); break;
        case 3: _t->setAcceleration(*reinterpret_cast<qreal*>(_v)); break;
        case 4: _t->QPanGesture::d_func()->setHorizontalVelocity(*reinterpret_cast<qreal*>(_v)); break;
        case 5: _t->QPanGesture::d_func()->setVerticalVelocity(*reinterpret_cast<qreal*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QPanGesture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPanGesture::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QPanGestureE_t>.strings))
        return static_cast<void*>(this);
    return QGesture::qt_metacast(_clname);
}

int QPanGesture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGesture::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN13QPinchGestureE_t {};
} // unnamed namespace

template <> constexpr inline auto QPinchGesture::qt_create_metaobjectdata<qt_meta_tag_ZN13QPinchGestureE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPinchGesture",
        "totalChangeFlags",
        "ChangeFlags",
        "changeFlags",
        "totalScaleFactor",
        "lastScaleFactor",
        "scaleFactor",
        "totalRotationAngle",
        "lastRotationAngle",
        "rotationAngle",
        "startCenterPoint",
        "lastCenterPoint",
        "centerPoint",
        "ChangeFlag",
        "ScaleFactorChanged",
        "RotationAngleChanged",
        "CenterPointChanged"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'totalChangeFlags'
        QtMocHelpers::PropertyData<ChangeFlags>(1, 0x80000000 | 2, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'changeFlags'
        QtMocHelpers::PropertyData<ChangeFlags>(3, 0x80000000 | 2, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'totalScaleFactor'
        QtMocHelpers::PropertyData<qreal>(4, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'lastScaleFactor'
        QtMocHelpers::PropertyData<qreal>(5, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'scaleFactor'
        QtMocHelpers::PropertyData<qreal>(6, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'totalRotationAngle'
        QtMocHelpers::PropertyData<qreal>(7, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'lastRotationAngle'
        QtMocHelpers::PropertyData<qreal>(8, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'rotationAngle'
        QtMocHelpers::PropertyData<qreal>(9, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'startCenterPoint'
        QtMocHelpers::PropertyData<QPointF>(10, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'lastCenterPoint'
        QtMocHelpers::PropertyData<QPointF>(11, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'centerPoint'
        QtMocHelpers::PropertyData<QPointF>(12, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ChangeFlag'
        QtMocHelpers::EnumData<ChangeFlag>(13, 13, QMC::EnumFlags{}).add({
            {   14, ChangeFlag::ScaleFactorChanged },
            {   15, ChangeFlag::RotationAngleChanged },
            {   16, ChangeFlag::CenterPointChanged },
        }),
        // enum 'ChangeFlags'
        QtMocHelpers::EnumData<ChangeFlags>(2, 13, QMC::EnumFlags{}).add({
            {   14, ChangeFlag::ScaleFactorChanged },
            {   15, ChangeFlag::RotationAngleChanged },
            {   16, ChangeFlag::CenterPointChanged },
        }),
    };
    return QtMocHelpers::metaObjectData<QPinchGesture, qt_meta_tag_ZN13QPinchGestureE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPinchGesture::staticMetaObject = { {
    QMetaObject::SuperData::link<QGesture::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QPinchGestureE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QPinchGestureE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13QPinchGestureE_t>.metaTypes,
    nullptr
} };

void QPinchGesture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPinchGesture *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: QtMocHelpers::assignFlags<ChangeFlags>(_v, _t->totalChangeFlags()); break;
        case 1: QtMocHelpers::assignFlags<ChangeFlags>(_v, _t->changeFlags()); break;
        case 2: *reinterpret_cast<qreal*>(_v) = _t->totalScaleFactor(); break;
        case 3: *reinterpret_cast<qreal*>(_v) = _t->lastScaleFactor(); break;
        case 4: *reinterpret_cast<qreal*>(_v) = _t->scaleFactor(); break;
        case 5: *reinterpret_cast<qreal*>(_v) = _t->totalRotationAngle(); break;
        case 6: *reinterpret_cast<qreal*>(_v) = _t->lastRotationAngle(); break;
        case 7: *reinterpret_cast<qreal*>(_v) = _t->rotationAngle(); break;
        case 8: *reinterpret_cast<QPointF*>(_v) = _t->startCenterPoint(); break;
        case 9: *reinterpret_cast<QPointF*>(_v) = _t->lastCenterPoint(); break;
        case 10: *reinterpret_cast<QPointF*>(_v) = _t->centerPoint(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTotalChangeFlags(*reinterpret_cast<ChangeFlags*>(_v)); break;
        case 1: _t->setChangeFlags(*reinterpret_cast<ChangeFlags*>(_v)); break;
        case 2: _t->setTotalScaleFactor(*reinterpret_cast<qreal*>(_v)); break;
        case 3: _t->setLastScaleFactor(*reinterpret_cast<qreal*>(_v)); break;
        case 4: _t->setScaleFactor(*reinterpret_cast<qreal*>(_v)); break;
        case 5: _t->setTotalRotationAngle(*reinterpret_cast<qreal*>(_v)); break;
        case 6: _t->setLastRotationAngle(*reinterpret_cast<qreal*>(_v)); break;
        case 7: _t->setRotationAngle(*reinterpret_cast<qreal*>(_v)); break;
        case 8: _t->setStartCenterPoint(*reinterpret_cast<QPointF*>(_v)); break;
        case 9: _t->setLastCenterPoint(*reinterpret_cast<QPointF*>(_v)); break;
        case 10: _t->setCenterPoint(*reinterpret_cast<QPointF*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QPinchGesture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPinchGesture::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QPinchGestureE_t>.strings))
        return static_cast<void*>(this);
    return QGesture::qt_metacast(_clname);
}

int QPinchGesture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGesture::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN13QSwipeGestureE_t {};
} // unnamed namespace

template <> constexpr inline auto QSwipeGesture::qt_create_metaobjectdata<qt_meta_tag_ZN13QSwipeGestureE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSwipeGesture",
        "horizontalDirection",
        "SwipeDirection",
        "verticalDirection",
        "swipeAngle",
        "velocity",
        "NoDirection",
        "Left",
        "Right",
        "Up",
        "Down"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'horizontalDirection'
        QtMocHelpers::PropertyData<SwipeDirection>(1, 0x80000000 | 2, QMC::Readable | QMC::Designable | QMC::Scriptable | QMC::EnumOrFlag),
        // property 'verticalDirection'
        QtMocHelpers::PropertyData<SwipeDirection>(3, 0x80000000 | 2, QMC::Readable | QMC::Designable | QMC::Scriptable | QMC::EnumOrFlag),
        // property 'swipeAngle'
        QtMocHelpers::PropertyData<qreal>(4, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'velocity'
        QtMocHelpers::PropertyData<qreal>(5, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'SwipeDirection'
        QtMocHelpers::EnumData<SwipeDirection>(2, 2, QMC::EnumFlags{}).add({
            {    6, SwipeDirection::NoDirection },
            {    7, SwipeDirection::Left },
            {    8, SwipeDirection::Right },
            {    9, SwipeDirection::Up },
            {   10, SwipeDirection::Down },
        }),
    };
    return QtMocHelpers::metaObjectData<QSwipeGesture, qt_meta_tag_ZN13QSwipeGestureE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSwipeGesture::staticMetaObject = { {
    QMetaObject::SuperData::link<QGesture::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QSwipeGestureE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QSwipeGestureE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13QSwipeGestureE_t>.metaTypes,
    nullptr
} };

void QSwipeGesture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QSwipeGesture *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<SwipeDirection*>(_v) = _t->horizontalDirection(); break;
        case 1: *reinterpret_cast<SwipeDirection*>(_v) = _t->verticalDirection(); break;
        case 2: *reinterpret_cast<qreal*>(_v) = _t->swipeAngle(); break;
        case 3: *reinterpret_cast<qreal*>(_v) = _t->QSwipeGesture::d_func()->velocity(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setSwipeAngle(*reinterpret_cast<qreal*>(_v)); break;
        case 3: _t->QSwipeGesture::d_func()->setVelocity(*reinterpret_cast<qreal*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QSwipeGesture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSwipeGesture::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QSwipeGestureE_t>.strings))
        return static_cast<void*>(this);
    return QGesture::qt_metacast(_clname);
}

int QSwipeGesture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGesture::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN11QTapGestureE_t {};
} // unnamed namespace

template <> constexpr inline auto QTapGesture::qt_create_metaobjectdata<qt_meta_tag_ZN11QTapGestureE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QTapGesture",
        "position"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'position'
        QtMocHelpers::PropertyData<QPointF>(1, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QTapGesture, qt_meta_tag_ZN11QTapGestureE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QTapGesture::staticMetaObject = { {
    QMetaObject::SuperData::link<QGesture::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QTapGestureE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QTapGestureE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11QTapGestureE_t>.metaTypes,
    nullptr
} };

void QTapGesture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QTapGesture *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QPointF*>(_v) = _t->position(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPosition(*reinterpret_cast<QPointF*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QTapGesture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTapGesture::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QTapGestureE_t>.strings))
        return static_cast<void*>(this);
    return QGesture::qt_metacast(_clname);
}

int QTapGesture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGesture::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN18QTapAndHoldGestureE_t {};
} // unnamed namespace

template <> constexpr inline auto QTapAndHoldGesture::qt_create_metaobjectdata<qt_meta_tag_ZN18QTapAndHoldGestureE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QTapAndHoldGesture",
        "position"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'position'
        QtMocHelpers::PropertyData<QPointF>(1, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QTapAndHoldGesture, qt_meta_tag_ZN18QTapAndHoldGestureE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QTapAndHoldGesture::staticMetaObject = { {
    QMetaObject::SuperData::link<QGesture::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QTapAndHoldGestureE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QTapAndHoldGestureE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18QTapAndHoldGestureE_t>.metaTypes,
    nullptr
} };

void QTapAndHoldGesture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QTapAndHoldGesture *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QPointF*>(_v) = _t->position(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPosition(*reinterpret_cast<QPointF*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QTapAndHoldGesture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTapAndHoldGesture::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QTapAndHoldGestureE_t>.strings))
        return static_cast<void*>(this);
    return QGesture::qt_metacast(_clname);
}

int QTapAndHoldGesture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGesture::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP

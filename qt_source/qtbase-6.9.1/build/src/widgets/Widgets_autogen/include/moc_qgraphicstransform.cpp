/****************************************************************************
** Meta object code from reading C++ file 'qgraphicstransform.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/graphicsview/qgraphicstransform.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgraphicstransform.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN18QGraphicsTransformE_t {};
} // unnamed namespace

template <> constexpr inline auto QGraphicsTransform::qt_create_metaobjectdata<qt_meta_tag_ZN18QGraphicsTransformE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QGraphicsTransform",
        "update",
        ""
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'update'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessProtected, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QGraphicsTransform, qt_meta_tag_ZN18QGraphicsTransformE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QGraphicsTransform::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QGraphicsTransformE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QGraphicsTransformE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18QGraphicsTransformE_t>.metaTypes,
    nullptr
} };

void QGraphicsTransform::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QGraphicsTransform *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->update(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *QGraphicsTransform::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphicsTransform::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QGraphicsTransformE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGraphicsTransform::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN14QGraphicsScaleE_t {};
} // unnamed namespace

template <> constexpr inline auto QGraphicsScale::qt_create_metaobjectdata<qt_meta_tag_ZN14QGraphicsScaleE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QGraphicsScale",
        "originChanged",
        "",
        "xScaleChanged",
        "yScaleChanged",
        "zScaleChanged",
        "scaleChanged",
        "origin",
        "xScale",
        "yScale",
        "zScale"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'originChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'xScaleChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'yScaleChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'zScaleChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'scaleChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'origin'
        QtMocHelpers::PropertyData<QVector3D>(7, QMetaType::QVector3D, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'xScale'
        QtMocHelpers::PropertyData<qreal>(8, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'yScale'
        QtMocHelpers::PropertyData<qreal>(9, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'zScale'
        QtMocHelpers::PropertyData<qreal>(10, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QGraphicsScale, qt_meta_tag_ZN14QGraphicsScaleE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QGraphicsScale::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsTransform::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QGraphicsScaleE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QGraphicsScaleE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14QGraphicsScaleE_t>.metaTypes,
    nullptr
} };

void QGraphicsScale::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QGraphicsScale *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->originChanged(); break;
        case 1: _t->xScaleChanged(); break;
        case 2: _t->yScaleChanged(); break;
        case 3: _t->zScaleChanged(); break;
        case 4: _t->scaleChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QGraphicsScale::*)()>(_a, &QGraphicsScale::originChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsScale::*)()>(_a, &QGraphicsScale::xScaleChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsScale::*)()>(_a, &QGraphicsScale::yScaleChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsScale::*)()>(_a, &QGraphicsScale::zScaleChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsScale::*)()>(_a, &QGraphicsScale::scaleChanged, 4))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QVector3D*>(_v) = _t->origin(); break;
        case 1: *reinterpret_cast<qreal*>(_v) = _t->xScale(); break;
        case 2: *reinterpret_cast<qreal*>(_v) = _t->yScale(); break;
        case 3: *reinterpret_cast<qreal*>(_v) = _t->zScale(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setOrigin(*reinterpret_cast<QVector3D*>(_v)); break;
        case 1: _t->setXScale(*reinterpret_cast<qreal*>(_v)); break;
        case 2: _t->setYScale(*reinterpret_cast<qreal*>(_v)); break;
        case 3: _t->setZScale(*reinterpret_cast<qreal*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QGraphicsScale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphicsScale::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QGraphicsScaleE_t>.strings))
        return static_cast<void*>(this);
    return QGraphicsTransform::qt_metacast(_clname);
}

int QGraphicsScale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsTransform::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QGraphicsScale::originChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QGraphicsScale::xScaleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QGraphicsScale::yScaleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QGraphicsScale::zScaleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QGraphicsScale::scaleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
namespace {
struct qt_meta_tag_ZN17QGraphicsRotationE_t {};
} // unnamed namespace

template <> constexpr inline auto QGraphicsRotation::qt_create_metaobjectdata<qt_meta_tag_ZN17QGraphicsRotationE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QGraphicsRotation",
        "originChanged",
        "",
        "angleChanged",
        "axisChanged",
        "origin",
        "angle",
        "axis"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'originChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'angleChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'axisChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'origin'
        QtMocHelpers::PropertyData<QVector3D>(5, QMetaType::QVector3D, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'angle'
        QtMocHelpers::PropertyData<qreal>(6, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'axis'
        QtMocHelpers::PropertyData<QVector3D>(7, QMetaType::QVector3D, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QGraphicsRotation, qt_meta_tag_ZN17QGraphicsRotationE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QGraphicsRotation::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsTransform::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QGraphicsRotationE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QGraphicsRotationE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QGraphicsRotationE_t>.metaTypes,
    nullptr
} };

void QGraphicsRotation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QGraphicsRotation *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->originChanged(); break;
        case 1: _t->angleChanged(); break;
        case 2: _t->axisChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QGraphicsRotation::*)()>(_a, &QGraphicsRotation::originChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsRotation::*)()>(_a, &QGraphicsRotation::angleChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsRotation::*)()>(_a, &QGraphicsRotation::axisChanged, 2))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QVector3D*>(_v) = _t->origin(); break;
        case 1: *reinterpret_cast<qreal*>(_v) = _t->angle(); break;
        case 2: *reinterpret_cast<QVector3D*>(_v) = _t->axis(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setOrigin(*reinterpret_cast<QVector3D*>(_v)); break;
        case 1: _t->setAngle(*reinterpret_cast<qreal*>(_v)); break;
        case 2: _t->setAxis(*reinterpret_cast<QVector3D*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QGraphicsRotation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphicsRotation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QGraphicsRotationE_t>.strings))
        return static_cast<void*>(this);
    return QGraphicsTransform::qt_metacast(_clname);
}

int QGraphicsRotation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsTransform::qt_metacall(_c, _id, _a);
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QGraphicsRotation::originChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QGraphicsRotation::angleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QGraphicsRotation::axisChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP

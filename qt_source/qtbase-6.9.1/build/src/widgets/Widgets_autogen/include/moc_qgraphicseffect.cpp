/****************************************************************************
** Meta object code from reading C++ file 'qgraphicseffect.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/effects/qgraphicseffect.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgraphicseffect.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15QGraphicsEffectE_t {};
} // unnamed namespace

template <> constexpr inline auto QGraphicsEffect::qt_create_metaobjectdata<qt_meta_tag_ZN15QGraphicsEffectE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QGraphicsEffect",
        "enabledChanged",
        "",
        "enabled",
        "setEnabled",
        "enable",
        "update",
        "ChangeFlags",
        "ChangeFlag",
        "SourceAttached",
        "SourceDetached",
        "SourceBoundingRectChanged",
        "SourceInvalidated"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'enabledChanged'
        QtMocHelpers::SignalData<void(bool)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'setEnabled'
        QtMocHelpers::SlotData<void(bool)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 5 },
        }}),
        // Slot 'update'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'enabled'
        QtMocHelpers::PropertyData<bool>(3, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ChangeFlags'
        QtMocHelpers::EnumData<ChangeFlags>(7, 8, QMC::EnumFlags{}).add({
            {    9, ChangeFlag::SourceAttached },
            {   10, ChangeFlag::SourceDetached },
            {   11, ChangeFlag::SourceBoundingRectChanged },
            {   12, ChangeFlag::SourceInvalidated },
        }),
    };
    return QtMocHelpers::metaObjectData<QGraphicsEffect, qt_meta_tag_ZN15QGraphicsEffectE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QGraphicsEffect::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QGraphicsEffectE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QGraphicsEffectE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15QGraphicsEffectE_t>.metaTypes,
    nullptr
} };

void QGraphicsEffect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QGraphicsEffect *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->enabledChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->setEnabled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->update(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QGraphicsEffect::*)(bool )>(_a, &QGraphicsEffect::enabledChanged, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isEnabled(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setEnabled(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QGraphicsEffect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphicsEffect::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QGraphicsEffectE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGraphicsEffect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QGraphicsEffect::enabledChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN23QGraphicsColorizeEffectE_t {};
} // unnamed namespace

template <> constexpr inline auto QGraphicsColorizeEffect::qt_create_metaobjectdata<qt_meta_tag_ZN23QGraphicsColorizeEffectE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QGraphicsColorizeEffect",
        "colorChanged",
        "",
        "color",
        "strengthChanged",
        "strength",
        "setColor",
        "c",
        "setStrength"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'colorChanged'
        QtMocHelpers::SignalData<void(const QColor &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QColor, 3 },
        }}),
        // Signal 'strengthChanged'
        QtMocHelpers::SignalData<void(qreal)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 5 },
        }}),
        // Slot 'setColor'
        QtMocHelpers::SlotData<void(const QColor &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QColor, 7 },
        }}),
        // Slot 'setStrength'
        QtMocHelpers::SlotData<void(qreal)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 5 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'color'
        QtMocHelpers::PropertyData<QColor>(3, QMetaType::QColor, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'strength'
        QtMocHelpers::PropertyData<qreal>(5, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QGraphicsColorizeEffect, qt_meta_tag_ZN23QGraphicsColorizeEffectE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QGraphicsColorizeEffect::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsEffect::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QGraphicsColorizeEffectE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QGraphicsColorizeEffectE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN23QGraphicsColorizeEffectE_t>.metaTypes,
    nullptr
} };

void QGraphicsColorizeEffect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QGraphicsColorizeEffect *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->colorChanged((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 1: _t->strengthChanged((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 2: _t->setColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 3: _t->setStrength((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QGraphicsColorizeEffect::*)(const QColor & )>(_a, &QGraphicsColorizeEffect::colorChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsColorizeEffect::*)(qreal )>(_a, &QGraphicsColorizeEffect::strengthChanged, 1))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QColor*>(_v) = _t->color(); break;
        case 1: *reinterpret_cast<qreal*>(_v) = _t->strength(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setColor(*reinterpret_cast<QColor*>(_v)); break;
        case 1: _t->setStrength(*reinterpret_cast<qreal*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QGraphicsColorizeEffect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphicsColorizeEffect::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QGraphicsColorizeEffectE_t>.strings))
        return static_cast<void*>(this);
    return QGraphicsEffect::qt_metacast(_clname);
}

int QGraphicsColorizeEffect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsEffect::qt_metacall(_c, _id, _a);
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QGraphicsColorizeEffect::colorChanged(const QColor & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QGraphicsColorizeEffect::strengthChanged(qreal _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN19QGraphicsBlurEffectE_t {};
} // unnamed namespace

template <> constexpr inline auto QGraphicsBlurEffect::qt_create_metaobjectdata<qt_meta_tag_ZN19QGraphicsBlurEffectE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QGraphicsBlurEffect",
        "blurRadiusChanged",
        "",
        "blurRadius",
        "blurHintsChanged",
        "BlurHints",
        "hints",
        "setBlurRadius",
        "setBlurHints",
        "blurHints",
        "BlurHint",
        "PerformanceHint",
        "QualityHint",
        "AnimationHint"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'blurRadiusChanged'
        QtMocHelpers::SignalData<void(qreal)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 3 },
        }}),
        // Signal 'blurHintsChanged'
        QtMocHelpers::SignalData<void(BlurHints)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
        // Slot 'setBlurRadius'
        QtMocHelpers::SlotData<void(qreal)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 3 },
        }}),
        // Slot 'setBlurHints'
        QtMocHelpers::SlotData<void(BlurHints)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'blurRadius'
        QtMocHelpers::PropertyData<qreal>(3, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'blurHints'
        QtMocHelpers::PropertyData<BlurHints>(9, 0x80000000 | 5, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 1),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'BlurHint'
        QtMocHelpers::EnumData<BlurHint>(10, 10, QMC::EnumFlags{}).add({
            {   11, BlurHint::PerformanceHint },
            {   12, BlurHint::QualityHint },
            {   13, BlurHint::AnimationHint },
        }),
        // enum 'BlurHints'
        QtMocHelpers::EnumData<BlurHints>(5, 10, QMC::EnumFlags{}).add({
            {   11, BlurHint::PerformanceHint },
            {   12, BlurHint::QualityHint },
            {   13, BlurHint::AnimationHint },
        }),
    };
    return QtMocHelpers::metaObjectData<QGraphicsBlurEffect, qt_meta_tag_ZN19QGraphicsBlurEffectE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QGraphicsBlurEffect::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsEffect::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QGraphicsBlurEffectE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QGraphicsBlurEffectE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19QGraphicsBlurEffectE_t>.metaTypes,
    nullptr
} };

void QGraphicsBlurEffect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QGraphicsBlurEffect *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->blurRadiusChanged((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 1: _t->blurHintsChanged((*reinterpret_cast< std::add_pointer_t<BlurHints>>(_a[1]))); break;
        case 2: _t->setBlurRadius((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 3: _t->setBlurHints((*reinterpret_cast< std::add_pointer_t<BlurHints>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QGraphicsBlurEffect::*)(qreal )>(_a, &QGraphicsBlurEffect::blurRadiusChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsBlurEffect::*)(BlurHints )>(_a, &QGraphicsBlurEffect::blurHintsChanged, 1))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<qreal*>(_v) = _t->blurRadius(); break;
        case 1: QtMocHelpers::assignFlags<BlurHints>(_v, _t->blurHints()); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBlurRadius(*reinterpret_cast<qreal*>(_v)); break;
        case 1: _t->setBlurHints(*reinterpret_cast<BlurHints*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QGraphicsBlurEffect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphicsBlurEffect::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QGraphicsBlurEffectE_t>.strings))
        return static_cast<void*>(this);
    return QGraphicsEffect::qt_metacast(_clname);
}

int QGraphicsBlurEffect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsEffect::qt_metacall(_c, _id, _a);
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QGraphicsBlurEffect::blurRadiusChanged(qreal _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QGraphicsBlurEffect::blurHintsChanged(BlurHints _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN25QGraphicsDropShadowEffectE_t {};
} // unnamed namespace

template <> constexpr inline auto QGraphicsDropShadowEffect::qt_create_metaobjectdata<qt_meta_tag_ZN25QGraphicsDropShadowEffectE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QGraphicsDropShadowEffect",
        "offsetChanged",
        "",
        "offset",
        "blurRadiusChanged",
        "blurRadius",
        "colorChanged",
        "color",
        "setOffset",
        "ofs",
        "dx",
        "dy",
        "d",
        "setXOffset",
        "setYOffset",
        "setBlurRadius",
        "setColor",
        "xOffset",
        "yOffset"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'offsetChanged'
        QtMocHelpers::SignalData<void(const QPointF &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 3 },
        }}),
        // Signal 'blurRadiusChanged'
        QtMocHelpers::SignalData<void(qreal)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 5 },
        }}),
        // Signal 'colorChanged'
        QtMocHelpers::SignalData<void(const QColor &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QColor, 7 },
        }}),
        // Slot 'setOffset'
        QtMocHelpers::SlotData<void(const QPointF &)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 9 },
        }}),
        // Slot 'setOffset'
        QtMocHelpers::SlotData<void(qreal, qreal)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 10 }, { QMetaType::QReal, 11 },
        }}),
        // Slot 'setOffset'
        QtMocHelpers::SlotData<void(qreal)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 12 },
        }}),
        // Slot 'setXOffset'
        QtMocHelpers::SlotData<void(qreal)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 10 },
        }}),
        // Slot 'setYOffset'
        QtMocHelpers::SlotData<void(qreal)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 11 },
        }}),
        // Slot 'setBlurRadius'
        QtMocHelpers::SlotData<void(qreal)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 5 },
        }}),
        // Slot 'setColor'
        QtMocHelpers::SlotData<void(const QColor &)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QColor, 7 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'offset'
        QtMocHelpers::PropertyData<QPointF>(3, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'xOffset'
        QtMocHelpers::PropertyData<qreal>(17, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'yOffset'
        QtMocHelpers::PropertyData<qreal>(18, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'blurRadius'
        QtMocHelpers::PropertyData<qreal>(5, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'color'
        QtMocHelpers::PropertyData<QColor>(7, QMetaType::QColor, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QGraphicsDropShadowEffect, qt_meta_tag_ZN25QGraphicsDropShadowEffectE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QGraphicsDropShadowEffect::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsEffect::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN25QGraphicsDropShadowEffectE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN25QGraphicsDropShadowEffectE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN25QGraphicsDropShadowEffectE_t>.metaTypes,
    nullptr
} };

void QGraphicsDropShadowEffect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QGraphicsDropShadowEffect *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->offsetChanged((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 1: _t->blurRadiusChanged((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 2: _t->colorChanged((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 3: _t->setOffset((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 4: _t->setOffset((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 5: _t->setOffset((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 6: _t->setXOffset((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 7: _t->setYOffset((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 8: _t->setBlurRadius((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 9: _t->setColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QGraphicsDropShadowEffect::*)(const QPointF & )>(_a, &QGraphicsDropShadowEffect::offsetChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsDropShadowEffect::*)(qreal )>(_a, &QGraphicsDropShadowEffect::blurRadiusChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsDropShadowEffect::*)(const QColor & )>(_a, &QGraphicsDropShadowEffect::colorChanged, 2))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QPointF*>(_v) = _t->offset(); break;
        case 1: *reinterpret_cast<qreal*>(_v) = _t->xOffset(); break;
        case 2: *reinterpret_cast<qreal*>(_v) = _t->yOffset(); break;
        case 3: *reinterpret_cast<qreal*>(_v) = _t->blurRadius(); break;
        case 4: *reinterpret_cast<QColor*>(_v) = _t->color(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setOffset(*reinterpret_cast<QPointF*>(_v)); break;
        case 1: _t->setXOffset(*reinterpret_cast<qreal*>(_v)); break;
        case 2: _t->setYOffset(*reinterpret_cast<qreal*>(_v)); break;
        case 3: _t->setBlurRadius(*reinterpret_cast<qreal*>(_v)); break;
        case 4: _t->setColor(*reinterpret_cast<QColor*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QGraphicsDropShadowEffect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphicsDropShadowEffect::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN25QGraphicsDropShadowEffectE_t>.strings))
        return static_cast<void*>(this);
    return QGraphicsEffect::qt_metacast(_clname);
}

int QGraphicsDropShadowEffect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsEffect::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QGraphicsDropShadowEffect::offsetChanged(const QPointF & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QGraphicsDropShadowEffect::blurRadiusChanged(qreal _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QGraphicsDropShadowEffect::colorChanged(const QColor & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN22QGraphicsOpacityEffectE_t {};
} // unnamed namespace

template <> constexpr inline auto QGraphicsOpacityEffect::qt_create_metaobjectdata<qt_meta_tag_ZN22QGraphicsOpacityEffectE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QGraphicsOpacityEffect",
        "opacityChanged",
        "",
        "opacity",
        "opacityMaskChanged",
        "mask",
        "setOpacity",
        "setOpacityMask",
        "opacityMask"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'opacityChanged'
        QtMocHelpers::SignalData<void(qreal)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 3 },
        }}),
        // Signal 'opacityMaskChanged'
        QtMocHelpers::SignalData<void(const QBrush &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QBrush, 5 },
        }}),
        // Slot 'setOpacity'
        QtMocHelpers::SlotData<void(qreal)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 3 },
        }}),
        // Slot 'setOpacityMask'
        QtMocHelpers::SlotData<void(const QBrush &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QBrush, 5 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'opacity'
        QtMocHelpers::PropertyData<qreal>(3, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'opacityMask'
        QtMocHelpers::PropertyData<QBrush>(8, QMetaType::QBrush, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QGraphicsOpacityEffect, qt_meta_tag_ZN22QGraphicsOpacityEffectE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QGraphicsOpacityEffect::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsEffect::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22QGraphicsOpacityEffectE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22QGraphicsOpacityEffectE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN22QGraphicsOpacityEffectE_t>.metaTypes,
    nullptr
} };

void QGraphicsOpacityEffect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QGraphicsOpacityEffect *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->opacityChanged((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 1: _t->opacityMaskChanged((*reinterpret_cast< std::add_pointer_t<QBrush>>(_a[1]))); break;
        case 2: _t->setOpacity((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 3: _t->setOpacityMask((*reinterpret_cast< std::add_pointer_t<QBrush>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QGraphicsOpacityEffect::*)(qreal )>(_a, &QGraphicsOpacityEffect::opacityChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsOpacityEffect::*)(const QBrush & )>(_a, &QGraphicsOpacityEffect::opacityMaskChanged, 1))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<qreal*>(_v) = _t->opacity(); break;
        case 1: *reinterpret_cast<QBrush*>(_v) = _t->opacityMask(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setOpacity(*reinterpret_cast<qreal*>(_v)); break;
        case 1: _t->setOpacityMask(*reinterpret_cast<QBrush*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QGraphicsOpacityEffect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphicsOpacityEffect::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22QGraphicsOpacityEffectE_t>.strings))
        return static_cast<void*>(this);
    return QGraphicsEffect::qt_metacast(_clname);
}

int QGraphicsOpacityEffect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsEffect::qt_metacall(_c, _id, _a);
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QGraphicsOpacityEffect::opacityChanged(qreal _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QGraphicsOpacityEffect::opacityMaskChanged(const QBrush & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP

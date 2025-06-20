/****************************************************************************
** Meta object code from reading C++ file 'qgraphicsitem.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/graphicsview/qgraphicsitem.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgraphicsitem.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15QGraphicsObjectE_t {};
} // unnamed namespace

template <> constexpr inline auto QGraphicsObject::qt_create_metaobjectdata<qt_meta_tag_ZN15QGraphicsObjectE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QGraphicsObject",
        "parentChanged",
        "",
        "opacityChanged",
        "visibleChanged",
        "enabledChanged",
        "xChanged",
        "yChanged",
        "zChanged",
        "rotationChanged",
        "scaleChanged",
        "childrenChanged",
        "widthChanged",
        "heightChanged",
        "updateMicroFocus",
        "parent",
        "QGraphicsObject*",
        "opacity",
        "enabled",
        "visible",
        "pos",
        "x",
        "y",
        "z",
        "rotation",
        "scale",
        "transformOriginPoint",
        "effect",
        "QGraphicsEffect*",
        "width",
        "height"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'parentChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'opacityChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'visibleChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'enabledChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'xChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'yChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'zChanged'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'rotationChanged'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'scaleChanged'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'childrenChanged'
        QtMocHelpers::SignalData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'widthChanged'
        QtMocHelpers::SignalData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'heightChanged'
        QtMocHelpers::SignalData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'updateMicroFocus'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessProtected, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'parent'
        QtMocHelpers::PropertyData<QGraphicsObject*>(15, 0x80000000 | 16, QMC::Readable | QMC::Writable | QMC::Scriptable | QMC::Stored | QMC::EnumOrFlag, 0),
        // property 'opacity'
        QtMocHelpers::PropertyData<qreal>(17, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 1),
        // property 'enabled'
        QtMocHelpers::PropertyData<bool>(18, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'visible'
        QtMocHelpers::PropertyData<bool>(19, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 2),
        // property 'pos'
        QtMocHelpers::PropertyData<QPointF>(20, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final),
        // property 'x'
        QtMocHelpers::PropertyData<qreal>(21, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 4),
        // property 'y'
        QtMocHelpers::PropertyData<qreal>(22, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 5),
        // property 'z'
        QtMocHelpers::PropertyData<qreal>(23, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Final, 6),
        // property 'rotation'
        QtMocHelpers::PropertyData<qreal>(24, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 7),
        // property 'scale'
        QtMocHelpers::PropertyData<qreal>(25, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 8),
        // property 'transformOriginPoint'
        QtMocHelpers::PropertyData<QPointF>(26, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'effect'
        QtMocHelpers::PropertyData<QGraphicsEffect*>(27, 0x80000000 | 28, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag),
        // property 'width'
        QtMocHelpers::PropertyData<qreal>(29, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet | QMC::Final, 10),
        // property 'height'
        QtMocHelpers::PropertyData<qreal>(30, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet | QMC::Final, 11),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QGraphicsObject, qt_meta_tag_ZN15QGraphicsObjectE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QGraphicsObject::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QGraphicsObjectE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QGraphicsObjectE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15QGraphicsObjectE_t>.metaTypes,
    nullptr
} };

void QGraphicsObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QGraphicsObject *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->parentChanged(); break;
        case 1: _t->opacityChanged(); break;
        case 2: _t->visibleChanged(); break;
        case 3: _t->enabledChanged(); break;
        case 4: _t->xChanged(); break;
        case 5: _t->yChanged(); break;
        case 6: _t->zChanged(); break;
        case 7: _t->rotationChanged(); break;
        case 8: _t->scaleChanged(); break;
        case 9: _t->childrenChanged(); break;
        case 10: _t->widthChanged(); break;
        case 11: _t->heightChanged(); break;
        case 12: _t->updateMicroFocus(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QGraphicsObject::*)()>(_a, &QGraphicsObject::parentChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsObject::*)()>(_a, &QGraphicsObject::opacityChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsObject::*)()>(_a, &QGraphicsObject::visibleChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsObject::*)()>(_a, &QGraphicsObject::enabledChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsObject::*)()>(_a, &QGraphicsObject::xChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsObject::*)()>(_a, &QGraphicsObject::yChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsObject::*)()>(_a, &QGraphicsObject::zChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsObject::*)()>(_a, &QGraphicsObject::rotationChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsObject::*)()>(_a, &QGraphicsObject::scaleChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsObject::*)()>(_a, &QGraphicsObject::childrenChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsObject::*)()>(_a, &QGraphicsObject::widthChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsObject::*)()>(_a, &QGraphicsObject::heightChanged, 11))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsObject* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QGraphicsObject**>(_v) = _t->parentObject(); break;
        case 1: *reinterpret_cast<qreal*>(_v) = _t->opacity(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->isEnabled(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->isVisible(); break;
        case 4: *reinterpret_cast<QPointF*>(_v) = _t->pos(); break;
        case 5: *reinterpret_cast<qreal*>(_v) = _t->x(); break;
        case 6: *reinterpret_cast<qreal*>(_v) = _t->y(); break;
        case 7: *reinterpret_cast<qreal*>(_v) = _t->zValue(); break;
        case 8: *reinterpret_cast<qreal*>(_v) = _t->rotation(); break;
        case 9: *reinterpret_cast<qreal*>(_v) = _t->scale(); break;
        case 10: *reinterpret_cast<QPointF*>(_v) = _t->transformOriginPoint(); break;
        case 11: *reinterpret_cast<QGraphicsEffect**>(_v) = _t->graphicsEffect(); break;
        case 12: *reinterpret_cast<qreal*>(_v) = _t->QGraphicsItem::d_func()->width(); break;
        case 13: *reinterpret_cast<qreal*>(_v) = _t->QGraphicsItem::d_func()->height(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setParentItem(*reinterpret_cast<QGraphicsObject**>(_v)); break;
        case 1: _t->setOpacity(*reinterpret_cast<qreal*>(_v)); break;
        case 2: _t->setEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 3: _t->setVisible(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setPos(*reinterpret_cast<QPointF*>(_v)); break;
        case 5: _t->setX(*reinterpret_cast<qreal*>(_v)); break;
        case 6: _t->setY(*reinterpret_cast<qreal*>(_v)); break;
        case 7: _t->setZValue(*reinterpret_cast<qreal*>(_v)); break;
        case 8: _t->setRotation(*reinterpret_cast<qreal*>(_v)); break;
        case 9: _t->setScale(*reinterpret_cast<qreal*>(_v)); break;
        case 10: _t->setTransformOriginPoint(*reinterpret_cast<QPointF*>(_v)); break;
        case 11: _t->setGraphicsEffect(*reinterpret_cast<QGraphicsEffect**>(_v)); break;
        case 12: _t->QGraphicsItem::d_func()->setWidth(*reinterpret_cast<qreal*>(_v)); break;
        case 13: _t->QGraphicsItem::d_func()->setHeight(*reinterpret_cast<qreal*>(_v)); break;
        default: break;
        }
    }
if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 12: _t->QGraphicsItem::d_func()->resetWidth(); break;
        case 13: _t->QGraphicsItem::d_func()->resetHeight(); break;
        default: break;
        }
    }
}

const QMetaObject *QGraphicsObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphicsObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QGraphicsObjectE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    if (!strcmp(_clname, "org.qt-project.Qt.QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    return QObject::qt_metacast(_clname);
}

int QGraphicsObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void QGraphicsObject::parentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QGraphicsObject::opacityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QGraphicsObject::visibleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QGraphicsObject::enabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QGraphicsObject::xChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QGraphicsObject::yChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QGraphicsObject::zChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QGraphicsObject::rotationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void QGraphicsObject::scaleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void QGraphicsObject::childrenChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void QGraphicsObject::widthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void QGraphicsObject::heightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}
namespace {
struct qt_meta_tag_ZN17QGraphicsTextItemE_t {};
} // unnamed namespace

template <> constexpr inline auto QGraphicsTextItem::qt_create_metaobjectdata<qt_meta_tag_ZN17QGraphicsTextItemE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QGraphicsTextItem",
        "linkActivated",
        "",
        "linkHovered"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'linkActivated'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'linkHovered'
        QtMocHelpers::SignalData<void(const QString &)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QGraphicsTextItem, qt_meta_tag_ZN17QGraphicsTextItemE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QGraphicsTextItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QGraphicsTextItemE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QGraphicsTextItemE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QGraphicsTextItemE_t>.metaTypes,
    nullptr
} };

void QGraphicsTextItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QGraphicsTextItem *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->linkActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->linkHovered((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QGraphicsTextItem::*)(const QString & )>(_a, &QGraphicsTextItem::linkActivated, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsTextItem::*)(const QString & )>(_a, &QGraphicsTextItem::linkHovered, 1))
            return;
    }
}

const QMetaObject *QGraphicsTextItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphicsTextItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QGraphicsTextItemE_t>.strings))
        return static_cast<void*>(this);
    return QGraphicsObject::qt_metacast(_clname);
}

int QGraphicsTextItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QGraphicsTextItem::linkActivated(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QGraphicsTextItem::linkHovered(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP

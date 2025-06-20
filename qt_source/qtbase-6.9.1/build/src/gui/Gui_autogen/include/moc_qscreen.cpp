/****************************************************************************
** Meta object code from reading C++ file 'qscreen.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qscreen.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qscreen.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN7QScreenE_t {};
} // unnamed namespace

template <> constexpr inline auto QScreen::qt_create_metaobjectdata<qt_meta_tag_ZN7QScreenE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QScreen",
        "geometryChanged",
        "",
        "geometry",
        "availableGeometryChanged",
        "physicalSizeChanged",
        "size",
        "physicalDotsPerInchChanged",
        "dpi",
        "logicalDotsPerInchChanged",
        "virtualGeometryChanged",
        "rect",
        "primaryOrientationChanged",
        "Qt::ScreenOrientation",
        "orientation",
        "orientationChanged",
        "refreshRateChanged",
        "refreshRate",
        "name",
        "manufacturer",
        "model",
        "serialNumber",
        "depth",
        "availableSize",
        "virtualSize",
        "availableVirtualSize",
        "availableGeometry",
        "virtualGeometry",
        "availableVirtualGeometry",
        "physicalSize",
        "physicalDotsPerInchX",
        "physicalDotsPerInchY",
        "physicalDotsPerInch",
        "logicalDotsPerInchX",
        "logicalDotsPerInchY",
        "logicalDotsPerInch",
        "devicePixelRatio",
        "primaryOrientation",
        "nativeOrientation"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'geometryChanged'
        QtMocHelpers::SignalData<void(const QRect &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRect, 3 },
        }}),
        // Signal 'availableGeometryChanged'
        QtMocHelpers::SignalData<void(const QRect &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRect, 3 },
        }}),
        // Signal 'physicalSizeChanged'
        QtMocHelpers::SignalData<void(const QSizeF &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QSizeF, 6 },
        }}),
        // Signal 'physicalDotsPerInchChanged'
        QtMocHelpers::SignalData<void(qreal)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 8 },
        }}),
        // Signal 'logicalDotsPerInchChanged'
        QtMocHelpers::SignalData<void(qreal)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 8 },
        }}),
        // Signal 'virtualGeometryChanged'
        QtMocHelpers::SignalData<void(const QRect &)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRect, 11 },
        }}),
        // Signal 'primaryOrientationChanged'
        QtMocHelpers::SignalData<void(Qt::ScreenOrientation)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 13, 14 },
        }}),
        // Signal 'orientationChanged'
        QtMocHelpers::SignalData<void(Qt::ScreenOrientation)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 13, 14 },
        }}),
        // Signal 'refreshRateChanged'
        QtMocHelpers::SignalData<void(qreal)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 17 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'name'
        QtMocHelpers::PropertyData<QString>(18, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'manufacturer'
        QtMocHelpers::PropertyData<QString>(19, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'model'
        QtMocHelpers::PropertyData<QString>(20, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'serialNumber'
        QtMocHelpers::PropertyData<QString>(21, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'depth'
        QtMocHelpers::PropertyData<int>(22, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'size'
        QtMocHelpers::PropertyData<QSize>(6, QMetaType::QSize, QMC::DefaultPropertyFlags, 0),
        // property 'availableSize'
        QtMocHelpers::PropertyData<QSize>(23, QMetaType::QSize, QMC::DefaultPropertyFlags, 1),
        // property 'virtualSize'
        QtMocHelpers::PropertyData<QSize>(24, QMetaType::QSize, QMC::DefaultPropertyFlags, 5),
        // property 'availableVirtualSize'
        QtMocHelpers::PropertyData<QSize>(25, QMetaType::QSize, QMC::DefaultPropertyFlags, 5),
        // property 'geometry'
        QtMocHelpers::PropertyData<QRect>(3, QMetaType::QRect, QMC::DefaultPropertyFlags, 0),
        // property 'availableGeometry'
        QtMocHelpers::PropertyData<QRect>(26, QMetaType::QRect, QMC::DefaultPropertyFlags, 1),
        // property 'virtualGeometry'
        QtMocHelpers::PropertyData<QRect>(27, QMetaType::QRect, QMC::DefaultPropertyFlags, 5),
        // property 'availableVirtualGeometry'
        QtMocHelpers::PropertyData<QRect>(28, QMetaType::QRect, QMC::DefaultPropertyFlags, 5),
        // property 'physicalSize'
        QtMocHelpers::PropertyData<QSizeF>(29, QMetaType::QSizeF, QMC::DefaultPropertyFlags, 2),
        // property 'physicalDotsPerInchX'
        QtMocHelpers::PropertyData<qreal>(30, QMetaType::QReal, QMC::DefaultPropertyFlags, 3),
        // property 'physicalDotsPerInchY'
        QtMocHelpers::PropertyData<qreal>(31, QMetaType::QReal, QMC::DefaultPropertyFlags, 3),
        // property 'physicalDotsPerInch'
        QtMocHelpers::PropertyData<qreal>(32, QMetaType::QReal, QMC::DefaultPropertyFlags, 3),
        // property 'logicalDotsPerInchX'
        QtMocHelpers::PropertyData<qreal>(33, QMetaType::QReal, QMC::DefaultPropertyFlags, 4),
        // property 'logicalDotsPerInchY'
        QtMocHelpers::PropertyData<qreal>(34, QMetaType::QReal, QMC::DefaultPropertyFlags, 4),
        // property 'logicalDotsPerInch'
        QtMocHelpers::PropertyData<qreal>(35, QMetaType::QReal, QMC::DefaultPropertyFlags, 4),
        // property 'devicePixelRatio'
        QtMocHelpers::PropertyData<qreal>(36, QMetaType::QReal, QMC::DefaultPropertyFlags, 3),
        // property 'primaryOrientation'
        QtMocHelpers::PropertyData<Qt::ScreenOrientation>(37, 0x80000000 | 13, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 6),
        // property 'orientation'
        QtMocHelpers::PropertyData<Qt::ScreenOrientation>(14, 0x80000000 | 13, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 7),
        // property 'nativeOrientation'
        QtMocHelpers::PropertyData<Qt::ScreenOrientation>(38, 0x80000000 | 13, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'refreshRate'
        QtMocHelpers::PropertyData<qreal>(17, QMetaType::QReal, QMC::DefaultPropertyFlags, 8),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QScreen, qt_meta_tag_ZN7QScreenE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QScreen::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QScreenE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QScreenE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7QScreenE_t>.metaTypes,
    nullptr
} };

void QScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QScreen *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->geometryChanged((*reinterpret_cast< std::add_pointer_t<QRect>>(_a[1]))); break;
        case 1: _t->availableGeometryChanged((*reinterpret_cast< std::add_pointer_t<QRect>>(_a[1]))); break;
        case 2: _t->physicalSizeChanged((*reinterpret_cast< std::add_pointer_t<QSizeF>>(_a[1]))); break;
        case 3: _t->physicalDotsPerInchChanged((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 4: _t->logicalDotsPerInchChanged((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 5: _t->virtualGeometryChanged((*reinterpret_cast< std::add_pointer_t<QRect>>(_a[1]))); break;
        case 6: _t->primaryOrientationChanged((*reinterpret_cast< std::add_pointer_t<Qt::ScreenOrientation>>(_a[1]))); break;
        case 7: _t->orientationChanged((*reinterpret_cast< std::add_pointer_t<Qt::ScreenOrientation>>(_a[1]))); break;
        case 8: _t->refreshRateChanged((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QScreen::*)(const QRect & )>(_a, &QScreen::geometryChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QScreen::*)(const QRect & )>(_a, &QScreen::availableGeometryChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QScreen::*)(const QSizeF & )>(_a, &QScreen::physicalSizeChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QScreen::*)(qreal )>(_a, &QScreen::physicalDotsPerInchChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QScreen::*)(qreal )>(_a, &QScreen::logicalDotsPerInchChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QScreen::*)(const QRect & )>(_a, &QScreen::virtualGeometryChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QScreen::*)(Qt::ScreenOrientation )>(_a, &QScreen::primaryOrientationChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QScreen::*)(Qt::ScreenOrientation )>(_a, &QScreen::orientationChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QScreen::*)(qreal )>(_a, &QScreen::refreshRateChanged, 8))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->name(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->manufacturer(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->model(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->serialNumber(); break;
        case 4: *reinterpret_cast<int*>(_v) = _t->depth(); break;
        case 5: *reinterpret_cast<QSize*>(_v) = _t->size(); break;
        case 6: *reinterpret_cast<QSize*>(_v) = _t->availableSize(); break;
        case 7: *reinterpret_cast<QSize*>(_v) = _t->virtualSize(); break;
        case 8: *reinterpret_cast<QSize*>(_v) = _t->availableVirtualSize(); break;
        case 9: *reinterpret_cast<QRect*>(_v) = _t->geometry(); break;
        case 10: *reinterpret_cast<QRect*>(_v) = _t->availableGeometry(); break;
        case 11: *reinterpret_cast<QRect*>(_v) = _t->virtualGeometry(); break;
        case 12: *reinterpret_cast<QRect*>(_v) = _t->availableVirtualGeometry(); break;
        case 13: *reinterpret_cast<QSizeF*>(_v) = _t->physicalSize(); break;
        case 14: *reinterpret_cast<qreal*>(_v) = _t->physicalDotsPerInchX(); break;
        case 15: *reinterpret_cast<qreal*>(_v) = _t->physicalDotsPerInchY(); break;
        case 16: *reinterpret_cast<qreal*>(_v) = _t->physicalDotsPerInch(); break;
        case 17: *reinterpret_cast<qreal*>(_v) = _t->logicalDotsPerInchX(); break;
        case 18: *reinterpret_cast<qreal*>(_v) = _t->logicalDotsPerInchY(); break;
        case 19: *reinterpret_cast<qreal*>(_v) = _t->logicalDotsPerInch(); break;
        case 20: *reinterpret_cast<qreal*>(_v) = _t->devicePixelRatio(); break;
        case 21: *reinterpret_cast<Qt::ScreenOrientation*>(_v) = _t->primaryOrientation(); break;
        case 22: *reinterpret_cast<Qt::ScreenOrientation*>(_v) = _t->orientation(); break;
        case 23: *reinterpret_cast<Qt::ScreenOrientation*>(_v) = _t->nativeOrientation(); break;
        case 24: *reinterpret_cast<qreal*>(_v) = _t->refreshRate(); break;
        default: break;
        }
    }
}

const QMetaObject *QScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QScreenE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void QScreen::geometryChanged(const QRect & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QScreen::availableGeometryChanged(const QRect & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QScreen::physicalSizeChanged(const QSizeF & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QScreen::physicalDotsPerInchChanged(qreal _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QScreen::logicalDotsPerInchChanged(qreal _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QScreen::virtualGeometryChanged(const QRect & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void QScreen::primaryOrientationChanged(Qt::ScreenOrientation _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void QScreen::orientationChanged(Qt::ScreenOrientation _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void QScreen::refreshRateChanged(qreal _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}
QT_WARNING_POP

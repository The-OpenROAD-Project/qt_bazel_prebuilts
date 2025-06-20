/****************************************************************************
** Meta object code from reading C++ file 'qgraphicsanchorlayout.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/graphicsview/qgraphicsanchorlayout.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgraphicsanchorlayout.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15QGraphicsAnchorE_t {};
} // unnamed namespace

template <> constexpr inline auto QGraphicsAnchor::qt_create_metaobjectdata<qt_meta_tag_ZN15QGraphicsAnchorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QGraphicsAnchor",
        "spacing",
        "sizePolicy",
        "QSizePolicy::Policy"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'spacing'
        QtMocHelpers::PropertyData<qreal>(1, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet),
        // property 'sizePolicy'
        QtMocHelpers::PropertyData<QSizePolicy::Policy>(2, 0x80000000 | 3, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QGraphicsAnchor, qt_meta_tag_ZN15QGraphicsAnchorE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN15QGraphicsAnchorE[] = {
    QMetaObject::SuperData::link<QSizePolicy::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject QGraphicsAnchor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QGraphicsAnchorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QGraphicsAnchorE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN15QGraphicsAnchorE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15QGraphicsAnchorE_t>.metaTypes,
    nullptr
} };

void QGraphicsAnchor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QGraphicsAnchor *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<qreal*>(_v) = _t->spacing(); break;
        case 1: *reinterpret_cast<QSizePolicy::Policy*>(_v) = _t->sizePolicy(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSpacing(*reinterpret_cast<qreal*>(_v)); break;
        case 1: _t->setSizePolicy(*reinterpret_cast<QSizePolicy::Policy*>(_v)); break;
        default: break;
        }
    }
if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 0: _t->unsetSpacing(); break;
        default: break;
        }
    }
}

const QMetaObject *QGraphicsAnchor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphicsAnchor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QGraphicsAnchorE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGraphicsAnchor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP

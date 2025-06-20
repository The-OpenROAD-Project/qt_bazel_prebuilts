/****************************************************************************
** Meta object code from reading C++ file 'qgraphicsscenebsptreeindex_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/graphicsview/qgraphicsscenebsptreeindex_p.h"
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgraphicsscenebsptreeindex_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN26QGraphicsSceneBspTreeIndexE_t {};
} // unnamed namespace

template <> constexpr inline auto QGraphicsSceneBspTreeIndex::qt_create_metaobjectdata<qt_meta_tag_ZN26QGraphicsSceneBspTreeIndexE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QGraphicsSceneBspTreeIndex",
        "updateSceneRect",
        "",
        "rect",
        "_q_updateSortCache",
        "_q_updateIndex",
        "bspTreeDepth"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'updateSceneRect'
        QtMocHelpers::SlotData<void(const QRectF &)>(1, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::QRectF, 3 },
        }}),
        // Slot '_q_updateSortCache'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_updateIndex'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'bspTreeDepth'
        QtMocHelpers::PropertyData<int>(6, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QGraphicsSceneBspTreeIndex, qt_meta_tag_ZN26QGraphicsSceneBspTreeIndexE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QGraphicsSceneBspTreeIndex::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsSceneIndex::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN26QGraphicsSceneBspTreeIndexE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN26QGraphicsSceneBspTreeIndexE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN26QGraphicsSceneBspTreeIndexE_t>.metaTypes,
    nullptr
} };

void QGraphicsSceneBspTreeIndex::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QGraphicsSceneBspTreeIndex *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->updateSceneRect((*reinterpret_cast< std::add_pointer_t<QRectF>>(_a[1]))); break;
        case 1: _t->d_func()->_q_updateSortCache(); break;
        case 2: _t->d_func()->_q_updateIndex(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->bspTreeDepth(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBspTreeDepth(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QGraphicsSceneBspTreeIndex::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphicsSceneBspTreeIndex::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN26QGraphicsSceneBspTreeIndexE_t>.strings))
        return static_cast<void*>(this);
    return QGraphicsSceneIndex::qt_metacast(_clname);
}

int QGraphicsSceneBspTreeIndex::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsSceneIndex::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP

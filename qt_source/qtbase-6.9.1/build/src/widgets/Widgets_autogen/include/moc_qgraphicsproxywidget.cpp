/****************************************************************************
** Meta object code from reading C++ file 'qgraphicsproxywidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/graphicsview/qgraphicsproxywidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgraphicsproxywidget.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN20QGraphicsProxyWidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto QGraphicsProxyWidget::qt_create_metaobjectdata<qt_meta_tag_ZN20QGraphicsProxyWidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QGraphicsProxyWidget",
        "newProxyWidget",
        "QGraphicsProxyWidget*",
        "",
        "const QWidget*",
        "_q_removeWidgetSlot"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'newProxyWidget'
        QtMocHelpers::SlotData<QGraphicsProxyWidget *(const QWidget *)>(1, 3, QMC::AccessProtected, 0x80000000 | 2, {{
            { 0x80000000 | 4, 3 },
        }}),
        // Slot '_q_removeWidgetSlot'
        QtMocHelpers::SlotData<void()>(5, 3, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QGraphicsProxyWidget, qt_meta_tag_ZN20QGraphicsProxyWidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QGraphicsProxyWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QGraphicsProxyWidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QGraphicsProxyWidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN20QGraphicsProxyWidgetE_t>.metaTypes,
    nullptr
} };

void QGraphicsProxyWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QGraphicsProxyWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QGraphicsProxyWidget* _r = _t->newProxyWidget((*reinterpret_cast< std::add_pointer_t<const QWidget*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QGraphicsProxyWidget**>(_a[0]) = std::move(_r); }  break;
        case 1: _t->d_func()->_q_removeWidgetSlot(); break;
        default: ;
        }
    }
}

const QMetaObject *QGraphicsProxyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphicsProxyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QGraphicsProxyWidgetE_t>.strings))
        return static_cast<void*>(this);
    return QGraphicsWidget::qt_metacast(_clname);
}

int QGraphicsProxyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP

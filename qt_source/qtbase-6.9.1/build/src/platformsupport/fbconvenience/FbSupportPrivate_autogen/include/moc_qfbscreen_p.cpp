/****************************************************************************
** Meta object code from reading C++ file 'qfbscreen_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/platformsupport/fbconvenience/qfbscreen_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qfbscreen_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9QFbScreenE_t {};
} // unnamed namespace

template <> constexpr inline auto QFbScreen::qt_create_metaobjectdata<qt_meta_tag_ZN9QFbScreenE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QFbScreen",
        "setDirty",
        "",
        "rect",
        "setPhysicalSize",
        "size",
        "setGeometry"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'setDirty'
        QtMocHelpers::SlotData<void(const QRect &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRect, 3 },
        }}),
        // Slot 'setPhysicalSize'
        QtMocHelpers::SlotData<void(const QSize &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QSize, 5 },
        }}),
        // Slot 'setGeometry'
        QtMocHelpers::SlotData<void(const QRect &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRect, 3 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QFbScreen, qt_meta_tag_ZN9QFbScreenE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QFbScreen::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QFbScreenE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QFbScreenE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9QFbScreenE_t>.metaTypes,
    nullptr
} };

void QFbScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QFbScreen *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->setDirty((*reinterpret_cast< std::add_pointer_t<QRect>>(_a[1]))); break;
        case 1: _t->setPhysicalSize((*reinterpret_cast< std::add_pointer_t<QSize>>(_a[1]))); break;
        case 2: _t->setGeometry((*reinterpret_cast< std::add_pointer_t<QRect>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *QFbScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QFbScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QFbScreenE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QPlatformScreen"))
        return static_cast< QPlatformScreen*>(this);
    return QObject::qt_metacast(_clname);
}

int QFbScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}
QT_WARNING_POP

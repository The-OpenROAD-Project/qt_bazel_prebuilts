/****************************************************************************
** Meta object code from reading C++ file 'qxcbnativeinterface.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/platforms/xcb/qxcbnativeinterface.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qxcbnativeinterface.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN19QXcbNativeInterfaceE_t {};
} // unnamed namespace

template <> constexpr inline auto QXcbNativeInterface::qt_create_metaobjectdata<qt_meta_tag_ZN19QXcbNativeInterfaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QXcbNativeInterface",
        "systemTrayWindowChanged",
        "",
        "QScreen*",
        "screen",
        "dumpConnectionNativeWindows",
        "const QXcbConnection*",
        "connection",
        "WId",
        "root",
        "dumpNativeWindows"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'systemTrayWindowChanged'
        QtMocHelpers::SignalData<void(QScreen *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Method 'dumpConnectionNativeWindows'
        QtMocHelpers::MethodData<QString(const QXcbConnection *, WId) const>(5, 2, QMC::AccessPublic, QMetaType::QString, {{
            { 0x80000000 | 6, 7 }, { 0x80000000 | 8, 9 },
        }}),
        // Method 'dumpNativeWindows'
        QtMocHelpers::MethodData<QString(WId) const>(10, 2, QMC::AccessPublic, QMetaType::QString, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Method 'dumpNativeWindows'
        QtMocHelpers::MethodData<QString() const>(10, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::QString),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QXcbNativeInterface, qt_meta_tag_ZN19QXcbNativeInterfaceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QXcbNativeInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QPlatformNativeInterface::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QXcbNativeInterfaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QXcbNativeInterfaceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19QXcbNativeInterfaceE_t>.metaTypes,
    nullptr
} };

void QXcbNativeInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QXcbNativeInterface *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->systemTrayWindowChanged((*reinterpret_cast< std::add_pointer_t<QScreen*>>(_a[1]))); break;
        case 1: { QString _r = _t->dumpConnectionNativeWindows((*reinterpret_cast< std::add_pointer_t<const QXcbConnection*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<WId>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->dumpNativeWindows((*reinterpret_cast< std::add_pointer_t<WId>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->dumpNativeWindows();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QScreen* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QXcbNativeInterface::*)(QScreen * )>(_a, &QXcbNativeInterface::systemTrayWindowChanged, 0))
            return;
    }
}

const QMetaObject *QXcbNativeInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXcbNativeInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QXcbNativeInterfaceE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QNativeInterface::QX11Application"))
        return static_cast< QNativeInterface::QX11Application*>(this);
    return QPlatformNativeInterface::qt_metacast(_clname);
}

int QXcbNativeInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlatformNativeInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QXcbNativeInterface::systemTrayWindowChanged(QScreen * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP

/****************************************************************************
** Meta object code from reading C++ file 'qplatformwindow_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qplatformwindow_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qplatformwindow_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN16QNativeInterface7Private14QWaylandWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto QNativeInterface::Private::QWaylandWindow::qt_create_metaobjectdata<qt_meta_tag_ZN16QNativeInterface7Private14QWaylandWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QNativeInterface::Private::QWaylandWindow",
        "surfaceCreated",
        "",
        "surfaceDestroyed",
        "surfaceRoleCreated",
        "surfaceRoleDestroyed",
        "xdgActivationTokenCreated",
        "token"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'surfaceCreated'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'surfaceDestroyed'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'surfaceRoleCreated'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'surfaceRoleDestroyed'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'xdgActivationTokenCreated'
        QtMocHelpers::SignalData<void(const QString &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QWaylandWindow, qt_meta_tag_ZN16QNativeInterface7Private14QWaylandWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QNativeInterface::Private::QWaylandWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QNativeInterface7Private14QWaylandWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QNativeInterface7Private14QWaylandWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16QNativeInterface7Private14QWaylandWindowE_t>.metaTypes,
    nullptr
} };

void QNativeInterface::Private::QWaylandWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QWaylandWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->surfaceCreated(); break;
        case 1: _t->surfaceDestroyed(); break;
        case 2: _t->surfaceRoleCreated(); break;
        case 3: _t->surfaceRoleDestroyed(); break;
        case 4: _t->xdgActivationTokenCreated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QWaylandWindow::*)()>(_a, &QWaylandWindow::surfaceCreated, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWaylandWindow::*)()>(_a, &QWaylandWindow::surfaceDestroyed, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWaylandWindow::*)()>(_a, &QWaylandWindow::surfaceRoleCreated, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWaylandWindow::*)()>(_a, &QWaylandWindow::surfaceRoleDestroyed, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWaylandWindow::*)(const QString & )>(_a, &QWaylandWindow::xdgActivationTokenCreated, 4))
            return;
    }
}

const QMetaObject *QNativeInterface::Private::QWaylandWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNativeInterface::Private::QWaylandWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QNativeInterface7Private14QWaylandWindowE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QNativeInterface::Private::QWaylandWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void QNativeInterface::Private::QWaylandWindow::surfaceCreated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QNativeInterface::Private::QWaylandWindow::surfaceDestroyed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QNativeInterface::Private::QWaylandWindow::surfaceRoleCreated()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QNativeInterface::Private::QWaylandWindow::surfaceRoleDestroyed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QNativeInterface::Private::QWaylandWindow::xdgActivationTokenCreated(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}
QT_WARNING_POP

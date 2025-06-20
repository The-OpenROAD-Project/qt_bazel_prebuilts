/****************************************************************************
** Meta object code from reading C++ file 'qlocalserver.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/socket/qlocalserver.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlocalserver.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12QLocalServerE_t {};
} // unnamed namespace

template <> constexpr inline auto QLocalServer::qt_create_metaobjectdata<qt_meta_tag_ZN12QLocalServerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QLocalServer",
        "newConnection",
        "",
        "_q_onNewConnection",
        "socketOptions",
        "SocketOptions",
        "SocketOption",
        "NoOptions",
        "UserAccessOption",
        "GroupAccessOption",
        "OtherAccessOption",
        "WorldAccessOption",
        "AbstractNamespaceOption"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'newConnection'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_onNewConnection'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'socketOptions'
        QtMocHelpers::PropertyData<SocketOptions>(4, 0x80000000 | 5, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet | QMC::Bindable),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'SocketOption'
        QtMocHelpers::EnumData<SocketOption>(6, 6, QMC::EnumFlags{}).add({
            {    7, SocketOption::NoOptions },
            {    8, SocketOption::UserAccessOption },
            {    9, SocketOption::GroupAccessOption },
            {   10, SocketOption::OtherAccessOption },
            {   11, SocketOption::WorldAccessOption },
            {   12, SocketOption::AbstractNamespaceOption },
        }),
        // enum 'SocketOptions'
        QtMocHelpers::EnumData<SocketOptions>(5, 6, QMC::EnumFlags{}).add({
            {    7, SocketOption::NoOptions },
            {    8, SocketOption::UserAccessOption },
            {    9, SocketOption::GroupAccessOption },
            {   10, SocketOption::OtherAccessOption },
            {   11, SocketOption::WorldAccessOption },
            {   12, SocketOption::AbstractNamespaceOption },
        }),
    };
    return QtMocHelpers::metaObjectData<QLocalServer, qt_meta_tag_ZN12QLocalServerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QLocalServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QLocalServerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QLocalServerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12QLocalServerE_t>.metaTypes,
    nullptr
} };

void QLocalServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QLocalServer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->newConnection(); break;
        case 1: _t->d_func()->_q_onNewConnection(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QLocalServer::*)()>(_a, &QLocalServer::newConnection, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: QtMocHelpers::assignFlags<SocketOptions>(_v, _t->socketOptions()); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSocketOptions(*reinterpret_cast<SocketOptions*>(_v)); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableSocketOptions(); break;
        default: break;
        }
    }
}

const QMetaObject *QLocalServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QLocalServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QLocalServerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QLocalServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QLocalServer::newConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP

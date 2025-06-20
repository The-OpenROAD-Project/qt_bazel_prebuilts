/****************************************************************************
** Meta object code from reading C++ file 'qnetworkmanagerservice.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/networkinformation/networkmanager/qnetworkmanagerservice.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnetworkmanagerservice.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN28QNetworkManagerInterfaceBaseE_t {};
} // unnamed namespace

template <> constexpr inline auto QNetworkManagerInterfaceBase::qt_create_metaobjectdata<qt_meta_tag_ZN28QNetworkManagerInterfaceBaseE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QNetworkManagerInterfaceBase"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QNetworkManagerInterfaceBase, qt_meta_tag_ZN28QNetworkManagerInterfaceBaseE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QNetworkManagerInterfaceBase::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractInterface::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN28QNetworkManagerInterfaceBaseE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN28QNetworkManagerInterfaceBaseE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN28QNetworkManagerInterfaceBaseE_t>.metaTypes,
    nullptr
} };

void QNetworkManagerInterfaceBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QNetworkManagerInterfaceBase *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QNetworkManagerInterfaceBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNetworkManagerInterfaceBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN28QNetworkManagerInterfaceBaseE_t>.strings))
        return static_cast<void*>(this);
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int QNetworkManagerInterfaceBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN24QNetworkManagerInterfaceE_t {};
} // unnamed namespace

template <> constexpr inline auto QNetworkManagerInterface::qt_create_metaobjectdata<qt_meta_tag_ZN24QNetworkManagerInterfaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QNetworkManagerInterface",
        "setProperties",
        "",
        "interfaceName",
        "QMap<QString,QVariant>",
        "map",
        "invalidatedProperties",
        "NMState",
        "NM_STATE_UNKNOWN",
        "NM_STATE_ASLEEP",
        "NM_STATE_DISCONNECTED",
        "NM_STATE_DISCONNECTING",
        "NM_STATE_CONNECTING",
        "NM_STATE_CONNECTED_LOCAL",
        "NM_STATE_CONNECTED_SITE",
        "NM_STATE_CONNECTED_GLOBAL",
        "NMConnectivityState",
        "NM_CONNECTIVITY_UNKNOWN",
        "NM_CONNECTIVITY_NONE",
        "NM_CONNECTIVITY_PORTAL",
        "NM_CONNECTIVITY_LIMITED",
        "NM_CONNECTIVITY_FULL"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'setProperties'
        QtMocHelpers::SlotData<void(const QString &, const QMap<QString,QVariant> &, const QStringList &)>(1, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { 0x80000000 | 4, 5 }, { QMetaType::QStringList, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'NMState'
        QtMocHelpers::EnumData<NMState>(7, 7, QMC::EnumFlags{}).add({
            {    8, NMState::NM_STATE_UNKNOWN },
            {    9, NMState::NM_STATE_ASLEEP },
            {   10, NMState::NM_STATE_DISCONNECTED },
            {   11, NMState::NM_STATE_DISCONNECTING },
            {   12, NMState::NM_STATE_CONNECTING },
            {   13, NMState::NM_STATE_CONNECTED_LOCAL },
            {   14, NMState::NM_STATE_CONNECTED_SITE },
            {   15, NMState::NM_STATE_CONNECTED_GLOBAL },
        }),
        // enum 'NMConnectivityState'
        QtMocHelpers::EnumData<NMConnectivityState>(16, 16, QMC::EnumFlags{}).add({
            {   17, NMConnectivityState::NM_CONNECTIVITY_UNKNOWN },
            {   18, NMConnectivityState::NM_CONNECTIVITY_NONE },
            {   19, NMConnectivityState::NM_CONNECTIVITY_PORTAL },
            {   20, NMConnectivityState::NM_CONNECTIVITY_LIMITED },
            {   21, NMConnectivityState::NM_CONNECTIVITY_FULL },
        }),
    };
    return QtMocHelpers::metaObjectData<QNetworkManagerInterface, qt_meta_tag_ZN24QNetworkManagerInterfaceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QNetworkManagerInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QNetworkManagerInterfaceBase::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QNetworkManagerInterfaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QNetworkManagerInterfaceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN24QNetworkManagerInterfaceE_t>.metaTypes,
    nullptr
} };

void QNetworkManagerInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QNetworkManagerInterface *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->setProperties((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QMap<QString,QVariant>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject *QNetworkManagerInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNetworkManagerInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QNetworkManagerInterfaceE_t>.strings))
        return static_cast<void*>(this);
    return QNetworkManagerInterfaceBase::qt_metacast(_clname);
}

int QNetworkManagerInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QNetworkManagerInterfaceBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP

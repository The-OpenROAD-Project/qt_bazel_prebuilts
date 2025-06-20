/****************************************************************************
** Meta object code from reading C++ file 'qnetworkreplyimpl_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/access/qnetworkreplyimpl_p.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnetworkreplyimpl_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN17QNetworkReplyImplE_t {};
} // unnamed namespace

template <> constexpr inline auto QNetworkReplyImpl::qt_create_metaobjectdata<qt_meta_tag_ZN17QNetworkReplyImplE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QNetworkReplyImpl",
        "_q_startOperation",
        "",
        "_q_copyReadyRead",
        "_q_copyReadChannelFinished",
        "_q_bufferOutgoingData",
        "_q_bufferOutgoingDataFinished"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot '_q_startOperation'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_copyReadyRead'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_copyReadChannelFinished'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_bufferOutgoingData'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_bufferOutgoingDataFinished'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QNetworkReplyImpl, qt_meta_tag_ZN17QNetworkReplyImplE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QNetworkReplyImpl::staticMetaObject = { {
    QMetaObject::SuperData::link<QNetworkReply::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QNetworkReplyImplE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QNetworkReplyImplE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QNetworkReplyImplE_t>.metaTypes,
    nullptr
} };

void QNetworkReplyImpl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QNetworkReplyImpl *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->d_func()->_q_startOperation(); break;
        case 1: _t->d_func()->_q_copyReadyRead(); break;
        case 2: _t->d_func()->_q_copyReadChannelFinished(); break;
        case 3: _t->d_func()->_q_bufferOutgoingData(); break;
        case 4: _t->d_func()->_q_bufferOutgoingDataFinished(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *QNetworkReplyImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNetworkReplyImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QNetworkReplyImplE_t>.strings))
        return static_cast<void*>(this);
    return QNetworkReply::qt_metacast(_clname);
}

int QNetworkReplyImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QNetworkReply::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP

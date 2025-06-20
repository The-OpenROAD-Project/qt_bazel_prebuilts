/****************************************************************************
** Meta object code from reading C++ file 'networkquery.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/assets/downloader/tasking/networkquery.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networkquery.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN7Tasking12NetworkQueryE_t {};
} // unnamed namespace

template <> constexpr inline auto Tasking::NetworkQuery::qt_create_metaobjectdata<qt_meta_tag_ZN7Tasking12NetworkQueryE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Tasking::NetworkQuery",
        "started",
        "",
        "downloadProgress",
        "bytesReceived",
        "bytesTotal",
        "sslErrors",
        "QList<QSslError>",
        "errors",
        "done",
        "DoneResult",
        "result"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'started'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'downloadProgress'
        QtMocHelpers::SignalData<void(qint64, qint64)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 4 }, { QMetaType::LongLong, 5 },
        }}),
        // Signal 'sslErrors'
        QtMocHelpers::SignalData<void(const QList<QSslError> &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 },
        }}),
        // Signal 'done'
        QtMocHelpers::SignalData<void(DoneResult)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 11 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<NetworkQuery, qt_meta_tag_ZN7Tasking12NetworkQueryE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Tasking::NetworkQuery::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7Tasking12NetworkQueryE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7Tasking12NetworkQueryE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7Tasking12NetworkQueryE_t>.metaTypes,
    nullptr
} };

void Tasking::NetworkQuery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<NetworkQuery *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->started(); break;
        case 1: _t->downloadProgress((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 2: _t->sslErrors((*reinterpret_cast< std::add_pointer_t<QList<QSslError>>>(_a[1]))); break;
        case 3: _t->done((*reinterpret_cast< std::add_pointer_t<DoneResult>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QSslError> >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (NetworkQuery::*)()>(_a, &NetworkQuery::started, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (NetworkQuery::*)(qint64 , qint64 )>(_a, &NetworkQuery::downloadProgress, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (NetworkQuery::*)(const QList<QSslError> & )>(_a, &NetworkQuery::sslErrors, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (NetworkQuery::*)(DoneResult )>(_a, &NetworkQuery::done, 3))
            return;
    }
}

const QMetaObject *Tasking::NetworkQuery::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tasking::NetworkQuery::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7Tasking12NetworkQueryE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Tasking::NetworkQuery::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Tasking::NetworkQuery::started()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Tasking::NetworkQuery::downloadProgress(qint64 _t1, qint64 _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void Tasking::NetworkQuery::sslErrors(const QList<QSslError> & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void Tasking::NetworkQuery::done(DoneResult _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
QT_WARNING_POP

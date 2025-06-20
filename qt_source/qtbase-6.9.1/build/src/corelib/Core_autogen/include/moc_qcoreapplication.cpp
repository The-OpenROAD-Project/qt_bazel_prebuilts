/****************************************************************************
** Meta object code from reading C++ file 'qcoreapplication.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/kernel/qcoreapplication.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcoreapplication.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN16QCoreApplicationE_t {};
} // unnamed namespace

template <> constexpr inline auto QCoreApplication::qt_create_metaobjectdata<qt_meta_tag_ZN16QCoreApplicationE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QCoreApplication",
        "aboutToQuit",
        "",
        "organizationNameChanged",
        "organizationDomainChanged",
        "applicationNameChanged",
        "applicationVersionChanged",
        "quit",
        "exit",
        "retcode",
        "applicationName",
        "applicationVersion",
        "organizationName",
        "organizationDomain",
        "quitLockEnabled"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'aboutToQuit'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'organizationNameChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'organizationDomainChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'applicationNameChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'applicationVersionChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'quit'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'exit'
        QtMocHelpers::SlotData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
        // Slot 'exit'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'applicationName'
        QtMocHelpers::PropertyData<QString>(10, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'applicationVersion'
        QtMocHelpers::PropertyData<QString>(11, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'organizationName'
        QtMocHelpers::PropertyData<QString>(12, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'organizationDomain'
        QtMocHelpers::PropertyData<QString>(13, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'quitLockEnabled'
        QtMocHelpers::PropertyData<bool>(14, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QCoreApplication, qt_meta_tag_ZN16QCoreApplicationE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QCoreApplication::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QCoreApplicationE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QCoreApplicationE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16QCoreApplicationE_t>.metaTypes,
    nullptr
} };

void QCoreApplication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QCoreApplication *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->aboutToQuit(QPrivateSignal()); break;
        case 1: _t->organizationNameChanged(); break;
        case 2: _t->organizationDomainChanged(); break;
        case 3: _t->applicationNameChanged(); break;
        case 4: _t->applicationVersionChanged(); break;
        case 5: _t->quit(); break;
        case 6: _t->exit((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->exit(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QCoreApplication::*)(QPrivateSignal)>(_a, &QCoreApplication::aboutToQuit, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QCoreApplication::*)()>(_a, &QCoreApplication::organizationNameChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QCoreApplication::*)()>(_a, &QCoreApplication::organizationDomainChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QCoreApplication::*)()>(_a, &QCoreApplication::applicationNameChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QCoreApplication::*)()>(_a, &QCoreApplication::applicationVersionChanged, 4))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->applicationName(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->applicationVersion(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->organizationName(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->organizationDomain(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->isQuitLockEnabled(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setApplicationName(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setApplicationVersion(*reinterpret_cast<QString*>(_v)); break;
        case 2: _t->setOrganizationName(*reinterpret_cast<QString*>(_v)); break;
        case 3: _t->setOrganizationDomain(*reinterpret_cast<QString*>(_v)); break;
        case 4: _t->setQuitLockEnabled(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QCoreApplication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCoreApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QCoreApplicationE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QCoreApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QCoreApplication::aboutToQuit(QPrivateSignal _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QCoreApplication::organizationNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QCoreApplication::organizationDomainChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QCoreApplication::applicationNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QCoreApplication::applicationVersionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP

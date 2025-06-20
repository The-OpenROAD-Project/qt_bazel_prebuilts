/****************************************************************************
** Meta object code from reading C++ file 'qibusplatforminputcontext.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/platforminputcontexts/ibus/qibusplatforminputcontext.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qibusplatforminputcontext.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN25QIBusPlatformInputContextE_t {};
} // unnamed namespace

template <> constexpr inline auto QIBusPlatformInputContext::qt_create_metaobjectdata<qt_meta_tag_ZN25QIBusPlatformInputContextE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QIBusPlatformInputContext",
        "commitText",
        "",
        "QDBusVariant",
        "text",
        "updatePreeditText",
        "cursor_pos",
        "visible",
        "updatePreeditTextWithMode",
        "mode",
        "forwardKeyEvent",
        "keyval",
        "keycode",
        "state",
        "cursorRectChanged",
        "deleteSurroundingText",
        "offset",
        "n_chars",
        "surroundingTextRequired",
        "hidePreeditText",
        "showPreeditText",
        "filterEventFinished",
        "QDBusPendingCallWatcher*",
        "call",
        "socketChanged",
        "str",
        "busRegistered",
        "busUnregistered",
        "connectToBus",
        "globalEngineChanged",
        "engine_name"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'commitText'
        QtMocHelpers::SlotData<void(const QDBusVariant &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'updatePreeditText'
        QtMocHelpers::SlotData<void(const QDBusVariant &, uint, bool)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::UInt, 6 }, { QMetaType::Bool, 7 },
        }}),
        // Slot 'updatePreeditTextWithMode'
        QtMocHelpers::SlotData<void(const QDBusVariant &, uint, bool, uint)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::UInt, 6 }, { QMetaType::Bool, 7 }, { QMetaType::UInt, 9 },
        }}),
        // Slot 'forwardKeyEvent'
        QtMocHelpers::SlotData<void(uint, uint, uint)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 11 }, { QMetaType::UInt, 12 }, { QMetaType::UInt, 13 },
        }}),
        // Slot 'cursorRectChanged'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'deleteSurroundingText'
        QtMocHelpers::SlotData<void(int, uint)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 16 }, { QMetaType::UInt, 17 },
        }}),
        // Slot 'surroundingTextRequired'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'hidePreeditText'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showPreeditText'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'filterEventFinished'
        QtMocHelpers::SlotData<void(QDBusPendingCallWatcher *)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 22, 23 },
        }}),
        // Slot 'socketChanged'
        QtMocHelpers::SlotData<void(const QString &)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 25 },
        }}),
        // Slot 'busRegistered'
        QtMocHelpers::SlotData<void(const QString &)>(26, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 25 },
        }}),
        // Slot 'busUnregistered'
        QtMocHelpers::SlotData<void(const QString &)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 25 },
        }}),
        // Slot 'connectToBus'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'globalEngineChanged'
        QtMocHelpers::SlotData<void(const QString &)>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QIBusPlatformInputContext, qt_meta_tag_ZN25QIBusPlatformInputContextE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QIBusPlatformInputContext::staticMetaObject = { {
    QMetaObject::SuperData::link<QPlatformInputContext::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN25QIBusPlatformInputContextE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN25QIBusPlatformInputContextE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN25QIBusPlatformInputContextE_t>.metaTypes,
    nullptr
} };

void QIBusPlatformInputContext::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QIBusPlatformInputContext *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->commitText((*reinterpret_cast< std::add_pointer_t<QDBusVariant>>(_a[1]))); break;
        case 1: _t->updatePreeditText((*reinterpret_cast< std::add_pointer_t<QDBusVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 2: _t->updatePreeditTextWithMode((*reinterpret_cast< std::add_pointer_t<QDBusVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[4]))); break;
        case 3: _t->forwardKeyEvent((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[3]))); break;
        case 4: _t->cursorRectChanged(); break;
        case 5: _t->deleteSurroundingText((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2]))); break;
        case 6: _t->surroundingTextRequired(); break;
        case 7: _t->hidePreeditText(); break;
        case 8: _t->showPreeditText(); break;
        case 9: _t->filterEventFinished((*reinterpret_cast< std::add_pointer_t<QDBusPendingCallWatcher*>>(_a[1]))); break;
        case 10: _t->socketChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->busRegistered((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->busUnregistered((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->connectToBus(); break;
        case 14: _t->globalEngineChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusVariant >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusVariant >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusVariant >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusPendingCallWatcher* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *QIBusPlatformInputContext::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QIBusPlatformInputContext::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN25QIBusPlatformInputContextE_t>.strings))
        return static_cast<void*>(this);
    return QPlatformInputContext::qt_metacast(_clname);
}

int QIBusPlatformInputContext::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlatformInputContext::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP

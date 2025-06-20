/****************************************************************************
** Meta object code from reading C++ file 'qibusinputcontextproxy.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/platforminputcontexts/ibus/qibusinputcontextproxy.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qibusinputcontextproxy.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN22QIBusInputContextProxyE_t {};
} // unnamed namespace

template <> constexpr inline auto QIBusInputContextProxy::qt_create_metaobjectdata<qt_meta_tag_ZN22QIBusInputContextProxyE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QIBusInputContextProxy",
        "CommitText",
        "",
        "QDBusVariant",
        "text",
        "CursorDownLookupTable",
        "CursorUpLookupTable",
        "DeleteSurroundingText",
        "offset",
        "n_chars",
        "Disabled",
        "Enabled",
        "ForwardKeyEvent",
        "keyval",
        "keycode",
        "state",
        "HideAuxiliaryText",
        "HideLookupTable",
        "HidePreeditText",
        "PageDownLookupTable",
        "PageUpLookupTable",
        "RegisterProperties",
        "props",
        "RequireSurroundingText",
        "ShowAuxiliaryText",
        "ShowLookupTable",
        "ShowPreeditText",
        "UpdateAuxiliaryText",
        "visible",
        "UpdateLookupTable",
        "table",
        "UpdatePreeditText",
        "cursor_pos",
        "UpdatePreeditTextWithMode",
        "mode",
        "UpdateProperty",
        "prop",
        "Destroy",
        "QDBusPendingReply<>",
        "Disable",
        "Enable",
        "FocusIn",
        "FocusOut",
        "GetEngine",
        "QDBusPendingReply<QDBusVariant>",
        "IsEnabled",
        "QDBusPendingReply<bool>",
        "ProcessKeyEvent",
        "PropertyActivate",
        "name",
        "Reset",
        "SetCapabilities",
        "caps",
        "SetCursorLocation",
        "x",
        "y",
        "w",
        "h",
        "SetCursorLocationRelative",
        "SetEngine",
        "SetSurroundingText",
        "anchor_pos",
        "ClientCommitPreedit",
        "QIBusPropTypeClientCommitPreedit",
        "ContentType",
        "QIBusPropTypeContentType"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'CommitText'
        QtMocHelpers::SignalData<void(const QDBusVariant &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'CursorDownLookupTable'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'CursorUpLookupTable'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'DeleteSurroundingText'
        QtMocHelpers::SignalData<void(int, uint)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 }, { QMetaType::UInt, 9 },
        }}),
        // Signal 'Disabled'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'Enabled'
        QtMocHelpers::SignalData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'ForwardKeyEvent'
        QtMocHelpers::SignalData<void(uint, uint, uint)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 13 }, { QMetaType::UInt, 14 }, { QMetaType::UInt, 15 },
        }}),
        // Signal 'HideAuxiliaryText'
        QtMocHelpers::SignalData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'HideLookupTable'
        QtMocHelpers::SignalData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'HidePreeditText'
        QtMocHelpers::SignalData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'PageDownLookupTable'
        QtMocHelpers::SignalData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'PageUpLookupTable'
        QtMocHelpers::SignalData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'RegisterProperties'
        QtMocHelpers::SignalData<void(const QDBusVariant &)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 22 },
        }}),
        // Signal 'RequireSurroundingText'
        QtMocHelpers::SignalData<void()>(23, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'ShowAuxiliaryText'
        QtMocHelpers::SignalData<void()>(24, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'ShowLookupTable'
        QtMocHelpers::SignalData<void()>(25, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'ShowPreeditText'
        QtMocHelpers::SignalData<void()>(26, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'UpdateAuxiliaryText'
        QtMocHelpers::SignalData<void(const QDBusVariant &, bool)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Bool, 28 },
        }}),
        // Signal 'UpdateLookupTable'
        QtMocHelpers::SignalData<void(const QDBusVariant &, bool)>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 30 }, { QMetaType::Bool, 28 },
        }}),
        // Signal 'UpdatePreeditText'
        QtMocHelpers::SignalData<void(const QDBusVariant &, uint, bool)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::UInt, 32 }, { QMetaType::Bool, 28 },
        }}),
        // Signal 'UpdatePreeditTextWithMode'
        QtMocHelpers::SignalData<void(const QDBusVariant &, uint, bool, uint)>(33, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::UInt, 32 }, { QMetaType::Bool, 28 }, { QMetaType::UInt, 34 },
        }}),
        // Signal 'UpdateProperty'
        QtMocHelpers::SignalData<void(const QDBusVariant &)>(35, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 36 },
        }}),
        // Slot 'Destroy'
        QtMocHelpers::SlotData<QDBusPendingReply<>()>(37, 2, QMC::AccessPublic, 0x80000000 | 38),
        // Slot 'Disable'
        QtMocHelpers::SlotData<QDBusPendingReply<>()>(39, 2, QMC::AccessPublic, 0x80000000 | 38),
        // Slot 'Enable'
        QtMocHelpers::SlotData<QDBusPendingReply<>()>(40, 2, QMC::AccessPublic, 0x80000000 | 38),
        // Slot 'FocusIn'
        QtMocHelpers::SlotData<QDBusPendingReply<>()>(41, 2, QMC::AccessPublic, 0x80000000 | 38),
        // Slot 'FocusOut'
        QtMocHelpers::SlotData<QDBusPendingReply<>()>(42, 2, QMC::AccessPublic, 0x80000000 | 38),
        // Slot 'GetEngine'
        QtMocHelpers::SlotData<QDBusPendingReply<QDBusVariant>()>(43, 2, QMC::AccessPublic, 0x80000000 | 44),
        // Slot 'IsEnabled'
        QtMocHelpers::SlotData<QDBusPendingReply<bool>()>(45, 2, QMC::AccessPublic, 0x80000000 | 46),
        // Slot 'ProcessKeyEvent'
        QtMocHelpers::SlotData<QDBusPendingReply<bool>(uint, uint, uint)>(47, 2, QMC::AccessPublic, 0x80000000 | 46, {{
            { QMetaType::UInt, 13 }, { QMetaType::UInt, 14 }, { QMetaType::UInt, 15 },
        }}),
        // Slot 'PropertyActivate'
        QtMocHelpers::SlotData<QDBusPendingReply<>(const QString &, int)>(48, 2, QMC::AccessPublic, 0x80000000 | 38, {{
            { QMetaType::QString, 49 }, { QMetaType::Int, 15 },
        }}),
        // Slot 'Reset'
        QtMocHelpers::SlotData<QDBusPendingReply<>()>(50, 2, QMC::AccessPublic, 0x80000000 | 38),
        // Slot 'SetCapabilities'
        QtMocHelpers::SlotData<QDBusPendingReply<>(uint)>(51, 2, QMC::AccessPublic, 0x80000000 | 38, {{
            { QMetaType::UInt, 52 },
        }}),
        // Slot 'SetCursorLocation'
        QtMocHelpers::SlotData<QDBusPendingReply<>(int, int, int, int)>(53, 2, QMC::AccessPublic, 0x80000000 | 38, {{
            { QMetaType::Int, 54 }, { QMetaType::Int, 55 }, { QMetaType::Int, 56 }, { QMetaType::Int, 57 },
        }}),
        // Slot 'SetCursorLocationRelative'
        QtMocHelpers::SlotData<QDBusPendingReply<>(int, int, int, int)>(58, 2, QMC::AccessPublic, 0x80000000 | 38, {{
            { QMetaType::Int, 54 }, { QMetaType::Int, 55 }, { QMetaType::Int, 56 }, { QMetaType::Int, 57 },
        }}),
        // Slot 'SetEngine'
        QtMocHelpers::SlotData<QDBusPendingReply<>(const QString &)>(59, 2, QMC::AccessPublic, 0x80000000 | 38, {{
            { QMetaType::QString, 49 },
        }}),
        // Slot 'SetSurroundingText'
        QtMocHelpers::SlotData<QDBusPendingReply<>(const QDBusVariant &, uint, uint)>(60, 2, QMC::AccessPublic, 0x80000000 | 38, {{
            { 0x80000000 | 3, 4 }, { QMetaType::UInt, 32 }, { QMetaType::UInt, 61 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'ClientCommitPreedit'
        QtMocHelpers::PropertyData<QIBusPropTypeClientCommitPreedit>(62, 0x80000000 | 63, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'ContentType'
        QtMocHelpers::PropertyData<QIBusPropTypeContentType>(64, 0x80000000 | 65, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QIBusInputContextProxy, qt_meta_tag_ZN22QIBusInputContextProxyE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QIBusInputContextProxy::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractInterface::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22QIBusInputContextProxyE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22QIBusInputContextProxyE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN22QIBusInputContextProxyE_t>.metaTypes,
    nullptr
} };

void QIBusInputContextProxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QIBusInputContextProxy *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->CommitText((*reinterpret_cast< std::add_pointer_t<QDBusVariant>>(_a[1]))); break;
        case 1: _t->CursorDownLookupTable(); break;
        case 2: _t->CursorUpLookupTable(); break;
        case 3: _t->DeleteSurroundingText((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2]))); break;
        case 4: _t->Disabled(); break;
        case 5: _t->Enabled(); break;
        case 6: _t->ForwardKeyEvent((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[3]))); break;
        case 7: _t->HideAuxiliaryText(); break;
        case 8: _t->HideLookupTable(); break;
        case 9: _t->HidePreeditText(); break;
        case 10: _t->PageDownLookupTable(); break;
        case 11: _t->PageUpLookupTable(); break;
        case 12: _t->RegisterProperties((*reinterpret_cast< std::add_pointer_t<QDBusVariant>>(_a[1]))); break;
        case 13: _t->RequireSurroundingText(); break;
        case 14: _t->ShowAuxiliaryText(); break;
        case 15: _t->ShowLookupTable(); break;
        case 16: _t->ShowPreeditText(); break;
        case 17: _t->UpdateAuxiliaryText((*reinterpret_cast< std::add_pointer_t<QDBusVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 18: _t->UpdateLookupTable((*reinterpret_cast< std::add_pointer_t<QDBusVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 19: _t->UpdatePreeditText((*reinterpret_cast< std::add_pointer_t<QDBusVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 20: _t->UpdatePreeditTextWithMode((*reinterpret_cast< std::add_pointer_t<QDBusVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[4]))); break;
        case 21: _t->UpdateProperty((*reinterpret_cast< std::add_pointer_t<QDBusVariant>>(_a[1]))); break;
        case 22: { QDBusPendingReply<> _r = _t->Destroy();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 23: { QDBusPendingReply<> _r = _t->Disable();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 24: { QDBusPendingReply<> _r = _t->Enable();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 25: { QDBusPendingReply<> _r = _t->FocusIn();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 26: { QDBusPendingReply<> _r = _t->FocusOut();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 27: { QDBusPendingReply<QDBusVariant> _r = _t->GetEngine();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QDBusVariant>*>(_a[0]) = std::move(_r); }  break;
        case 28: { QDBusPendingReply<bool> _r = _t->IsEnabled();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<bool>*>(_a[0]) = std::move(_r); }  break;
        case 29: { QDBusPendingReply<bool> _r = _t->ProcessKeyEvent((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<bool>*>(_a[0]) = std::move(_r); }  break;
        case 30: { QDBusPendingReply<> _r = _t->PropertyActivate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 31: { QDBusPendingReply<> _r = _t->Reset();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 32: { QDBusPendingReply<> _r = _t->SetCapabilities((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 33: { QDBusPendingReply<> _r = _t->SetCursorLocation((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 34: { QDBusPendingReply<> _r = _t->SetCursorLocationRelative((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 35: { QDBusPendingReply<> _r = _t->SetEngine((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 36: { QDBusPendingReply<> _r = _t->SetSurroundingText((*reinterpret_cast< std::add_pointer_t<QDBusVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
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
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusVariant >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusVariant >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusVariant >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusVariant >(); break;
            }
            break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusVariant >(); break;
            }
            break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusVariant >(); break;
            }
            break;
        case 36:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusVariant >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)(const QDBusVariant & )>(_a, &QIBusInputContextProxy::CommitText, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)()>(_a, &QIBusInputContextProxy::CursorDownLookupTable, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)()>(_a, &QIBusInputContextProxy::CursorUpLookupTable, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)(int , uint )>(_a, &QIBusInputContextProxy::DeleteSurroundingText, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)()>(_a, &QIBusInputContextProxy::Disabled, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)()>(_a, &QIBusInputContextProxy::Enabled, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)(uint , uint , uint )>(_a, &QIBusInputContextProxy::ForwardKeyEvent, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)()>(_a, &QIBusInputContextProxy::HideAuxiliaryText, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)()>(_a, &QIBusInputContextProxy::HideLookupTable, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)()>(_a, &QIBusInputContextProxy::HidePreeditText, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)()>(_a, &QIBusInputContextProxy::PageDownLookupTable, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)()>(_a, &QIBusInputContextProxy::PageUpLookupTable, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)(const QDBusVariant & )>(_a, &QIBusInputContextProxy::RegisterProperties, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)()>(_a, &QIBusInputContextProxy::RequireSurroundingText, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)()>(_a, &QIBusInputContextProxy::ShowAuxiliaryText, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)()>(_a, &QIBusInputContextProxy::ShowLookupTable, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)()>(_a, &QIBusInputContextProxy::ShowPreeditText, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)(const QDBusVariant & , bool )>(_a, &QIBusInputContextProxy::UpdateAuxiliaryText, 17))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)(const QDBusVariant & , bool )>(_a, &QIBusInputContextProxy::UpdateLookupTable, 18))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)(const QDBusVariant & , uint , bool )>(_a, &QIBusInputContextProxy::UpdatePreeditText, 19))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)(const QDBusVariant & , uint , bool , uint )>(_a, &QIBusInputContextProxy::UpdatePreeditTextWithMode, 20))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIBusInputContextProxy::*)(const QDBusVariant & )>(_a, &QIBusInputContextProxy::UpdateProperty, 21))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QIBusPropTypeClientCommitPreedit >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QIBusPropTypeContentType >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QIBusPropTypeClientCommitPreedit*>(_v) = _t->clientCommitPreedit(); break;
        case 1: *reinterpret_cast<QIBusPropTypeContentType*>(_v) = _t->contentType(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setClientCommitPreedit(*reinterpret_cast<QIBusPropTypeClientCommitPreedit*>(_v)); break;
        case 1: _t->setContentType(*reinterpret_cast<QIBusPropTypeContentType*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QIBusInputContextProxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QIBusInputContextProxy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22QIBusInputContextProxyE_t>.strings))
        return static_cast<void*>(this);
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int QIBusInputContextProxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QIBusInputContextProxy::CommitText(const QDBusVariant & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QIBusInputContextProxy::CursorDownLookupTable()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QIBusInputContextProxy::CursorUpLookupTable()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QIBusInputContextProxy::DeleteSurroundingText(int _t1, uint _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}

// SIGNAL 4
void QIBusInputContextProxy::Disabled()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QIBusInputContextProxy::Enabled()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QIBusInputContextProxy::ForwardKeyEvent(uint _t1, uint _t2, uint _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2, _t3);
}

// SIGNAL 7
void QIBusInputContextProxy::HideAuxiliaryText()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void QIBusInputContextProxy::HideLookupTable()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void QIBusInputContextProxy::HidePreeditText()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void QIBusInputContextProxy::PageDownLookupTable()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void QIBusInputContextProxy::PageUpLookupTable()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void QIBusInputContextProxy::RegisterProperties(const QDBusVariant & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1);
}

// SIGNAL 13
void QIBusInputContextProxy::RequireSurroundingText()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void QIBusInputContextProxy::ShowAuxiliaryText()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void QIBusInputContextProxy::ShowLookupTable()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void QIBusInputContextProxy::ShowPreeditText()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void QIBusInputContextProxy::UpdateAuxiliaryText(const QDBusVariant & _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 17, nullptr, _t1, _t2);
}

// SIGNAL 18
void QIBusInputContextProxy::UpdateLookupTable(const QDBusVariant & _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 18, nullptr, _t1, _t2);
}

// SIGNAL 19
void QIBusInputContextProxy::UpdatePreeditText(const QDBusVariant & _t1, uint _t2, bool _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 19, nullptr, _t1, _t2, _t3);
}

// SIGNAL 20
void QIBusInputContextProxy::UpdatePreeditTextWithMode(const QDBusVariant & _t1, uint _t2, bool _t3, uint _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 20, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 21
void QIBusInputContextProxy::UpdateProperty(const QDBusVariant & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 21, nullptr, _t1);
}
QT_WARNING_POP

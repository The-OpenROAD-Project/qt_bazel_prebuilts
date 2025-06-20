/****************************************************************************
** Meta object code from reading C++ file 'qstatusnotifieritemadaptor_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/platform/unix/dbustray/qstatusnotifieritemadaptor_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qstatusnotifieritemadaptor_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN26QStatusNotifierItemAdaptorE_t {};
} // unnamed namespace

template <> constexpr inline auto QStatusNotifierItemAdaptor::qt_create_metaobjectdata<qt_meta_tag_ZN26QStatusNotifierItemAdaptorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QStatusNotifierItemAdaptor",
        "D-Bus Interface",
        "org.kde.StatusNotifierItem",
        "D-Bus Introspection",
        "  <interface name=\"org.kde.StatusNotifierItem\">\n    <property a"
        "ccess=\"read\" type=\"s\" name=\"Category\"/>\n    <property acces"
        "s=\"read\" type=\"s\" name=\"Id\"/>\n    <property access=\"read\""
        " type=\"s\" name=\"Title\"/>\n    <property access=\"read\" type=\""
        "s\" name=\"Status\"/>\n    <property access=\"read\" type=\"i\" na"
        "me=\"WindowId\"/>\n    <property access=\"read\" type=\"s\" name=\""
        "IconThemePath\"/>\n    <property access=\"read\" type=\"o\" name=\""
        "Menu\"/>\n    <property access=\"read\" type=\"b\" name=\"ItemIsMe"
        "nu\"/>\n    <property access=\"read\" type=\"s\" name=\"IconName\""
        "/>\n    <property access=\"read\" type=\"a(iiay)\" name=\"IconPixm"
        "ap\">\n      <annotation value=\"QXdgDBusImageVector\" name=\"org."
        "qtproject.QtDBus.QtTypeName\"/>\n    </property>\n    <property ac"
        "cess=\"read\" type=\"s\" name=\"OverlayIconName\"/>\n    <property"
        " access=\"read\" type=\"a(iiay)\" name=\"OverlayIconPixmap\">\n   "
        "   <annotation value=\"QXdgDBusImageVector\" name=\"org.qtproject."
        "QtDBus.QtTypeName\"/>\n    </property>\n    <property access=\"rea"
        "d\" type=\"s\" name=\"AttentionIconName\"/>\n    <property access="
        "\"read\" type=\"a(iiay)\" name=\"AttentionIconPixmap\">\n      <an"
        "notation value=\"QXdgDBusImageVector\" name=\"org.qtproject.QtDBus"
        ".QtTypeName\"/>\n    </property>\n    <property access=\"read\" ty"
        "pe=\"s\" name=\"AttentionMovieName\"/>\n    <property access=\"rea"
        "d\" type=\"(sa(iiay)ss)\" name=\"ToolTip\">\n      <annotation val"
        "ue=\"QXdgDBusToolTipStruct\" name=\"org.qtproject.QtDBus.QtTypeNam"
        "e\"/>\n    </property>\n    <method name=\"ProvideXdgActivationTok"
        "en\">\n        <arg name=\"token\" type=\"s\" direction=\"in\"/>\n"
        "    </method>\n    <method name=\"ContextMenu\">\n      <arg direc"
        "tion=\"in\" type=\"i\" name=\"x\"/>\n      <arg direction=\"in\" t"
        "ype=\"i\" name=\"y\"/>\n    </method>\n    <method name=\"Activate"
        "\">\n      <arg direction=\"in\" type=\"i\" name=\"x\"/>\n      <a"
        "rg direction=\"in\" type=\"i\" name=\"y\"/>\n    </method>\n    <m"
        "ethod name=\"SecondaryActivate\">\n      <arg direction=\"in\" typ"
        "e=\"i\" name=\"x\"/>\n      <arg direction=\"in\" type=\"i\" name="
        "\"y\"/>\n    </method>\n    <method name=\"Scroll\">\n      <arg d"
        "irection=\"in\" type=\"i\" name=\"delta\"/>\n      <arg direction="
        "\"in\" type=\"s\" name=\"orientation\"/>\n    </method>\n    <sign"
        "al name=\"NewTitle\"/>\n    <signal name=\"NewIcon\"/>\n    <signa"
        "l name=\"NewAttentionIcon\"/>\n    <signal name=\"NewOverlayIcon\""
        "/>\n    <signal name=\"NewMenu\"/>\n    <signal name=\"NewToolTip\""
        "/>\n    <signal name=\"NewStatus\">\n      <arg type=\"s\" name=\""
        "status\"/>\n    </signal>\n  </interface>\n",
        "NewAttentionIcon",
        "",
        "NewIcon",
        "NewOverlayIcon",
        "NewMenu",
        "NewStatus",
        "status",
        "NewTitle",
        "NewToolTip",
        "Activate",
        "x",
        "y",
        "ContextMenu",
        "ProvideXdgActivationToken",
        "token",
        "Scroll",
        "delta",
        "orientation",
        "SecondaryActivate",
        "AttentionIconName",
        "AttentionIconPixmap",
        "QXdgDBusImageVector",
        "AttentionMovieName",
        "Category",
        "IconName",
        "IconPixmap",
        "Id",
        "ItemIsMenu",
        "Menu",
        "QDBusObjectPath",
        "OverlayIconName",
        "OverlayIconPixmap",
        "Status",
        "Title",
        "ToolTip",
        "QXdgDBusToolTipStruct"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'NewAttentionIcon'
        QtMocHelpers::SignalData<void()>(5, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'NewIcon'
        QtMocHelpers::SignalData<void()>(7, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'NewOverlayIcon'
        QtMocHelpers::SignalData<void()>(8, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'NewMenu'
        QtMocHelpers::SignalData<void()>(9, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'NewStatus'
        QtMocHelpers::SignalData<void(const QString &)>(10, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 11 },
        }}),
        // Signal 'NewTitle'
        QtMocHelpers::SignalData<void()>(12, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'NewToolTip'
        QtMocHelpers::SignalData<void()>(13, 6, QMC::AccessPublic, QMetaType::Void),
        // Slot 'Activate'
        QtMocHelpers::SlotData<void(int, int)>(14, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 15 }, { QMetaType::Int, 16 },
        }}),
        // Slot 'ContextMenu'
        QtMocHelpers::SlotData<void(int, int)>(17, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 15 }, { QMetaType::Int, 16 },
        }}),
        // Slot 'ProvideXdgActivationToken'
        QtMocHelpers::SlotData<void(const QString &)>(18, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 19 },
        }}),
        // Slot 'Scroll'
        QtMocHelpers::SlotData<void(int, const QString &)>(20, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 21 }, { QMetaType::QString, 22 },
        }}),
        // Slot 'SecondaryActivate'
        QtMocHelpers::SlotData<void(int, int)>(23, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 15 }, { QMetaType::Int, 16 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'AttentionIconName'
        QtMocHelpers::PropertyData<QString>(24, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'AttentionIconPixmap'
        QtMocHelpers::PropertyData<QXdgDBusImageVector>(25, 0x80000000 | 26, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'AttentionMovieName'
        QtMocHelpers::PropertyData<QString>(27, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'Category'
        QtMocHelpers::PropertyData<QString>(28, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'IconName'
        QtMocHelpers::PropertyData<QString>(29, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'IconPixmap'
        QtMocHelpers::PropertyData<QXdgDBusImageVector>(30, 0x80000000 | 26, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'Id'
        QtMocHelpers::PropertyData<QString>(31, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'ItemIsMenu'
        QtMocHelpers::PropertyData<bool>(32, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'Menu'
        QtMocHelpers::PropertyData<QDBusObjectPath>(33, 0x80000000 | 34, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'OverlayIconName'
        QtMocHelpers::PropertyData<QString>(35, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'OverlayIconPixmap'
        QtMocHelpers::PropertyData<QXdgDBusImageVector>(36, 0x80000000 | 26, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'Status'
        QtMocHelpers::PropertyData<QString>(37, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'Title'
        QtMocHelpers::PropertyData<QString>(38, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'ToolTip'
        QtMocHelpers::PropertyData<QXdgDBusToolTipStruct>(39, 0x80000000 | 40, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<QStatusNotifierItemAdaptor, qt_meta_tag_ZN26QStatusNotifierItemAdaptorE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject QStatusNotifierItemAdaptor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractAdaptor::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN26QStatusNotifierItemAdaptorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN26QStatusNotifierItemAdaptorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN26QStatusNotifierItemAdaptorE_t>.metaTypes,
    nullptr
} };

void QStatusNotifierItemAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QStatusNotifierItemAdaptor *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->NewAttentionIcon(); break;
        case 1: _t->NewIcon(); break;
        case 2: _t->NewOverlayIcon(); break;
        case 3: _t->NewMenu(); break;
        case 4: _t->NewStatus((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->NewTitle(); break;
        case 6: _t->NewToolTip(); break;
        case 7: _t->Activate((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 8: _t->ContextMenu((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 9: _t->ProvideXdgActivationToken((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->Scroll((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 11: _t->SecondaryActivate((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QStatusNotifierItemAdaptor::*)()>(_a, &QStatusNotifierItemAdaptor::NewAttentionIcon, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStatusNotifierItemAdaptor::*)()>(_a, &QStatusNotifierItemAdaptor::NewIcon, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStatusNotifierItemAdaptor::*)()>(_a, &QStatusNotifierItemAdaptor::NewOverlayIcon, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStatusNotifierItemAdaptor::*)()>(_a, &QStatusNotifierItemAdaptor::NewMenu, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStatusNotifierItemAdaptor::*)(const QString & )>(_a, &QStatusNotifierItemAdaptor::NewStatus, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStatusNotifierItemAdaptor::*)()>(_a, &QStatusNotifierItemAdaptor::NewTitle, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStatusNotifierItemAdaptor::*)()>(_a, &QStatusNotifierItemAdaptor::NewToolTip, 6))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusObjectPath >(); break;
        case 10:
        case 5:
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QXdgDBusImageVector >(); break;
        case 13:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QXdgDBusToolTipStruct >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->attentionIconName(); break;
        case 1: *reinterpret_cast<QXdgDBusImageVector*>(_v) = _t->attentionIconPixmap(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->attentionMovieName(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->category(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->iconName(); break;
        case 5: *reinterpret_cast<QXdgDBusImageVector*>(_v) = _t->iconPixmap(); break;
        case 6: *reinterpret_cast<QString*>(_v) = _t->id(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->itemIsMenu(); break;
        case 8: *reinterpret_cast<QDBusObjectPath*>(_v) = _t->menu(); break;
        case 9: *reinterpret_cast<QString*>(_v) = _t->overlayIconName(); break;
        case 10: *reinterpret_cast<QXdgDBusImageVector*>(_v) = _t->overlayIconPixmap(); break;
        case 11: *reinterpret_cast<QString*>(_v) = _t->status(); break;
        case 12: *reinterpret_cast<QString*>(_v) = _t->title(); break;
        case 13: *reinterpret_cast<QXdgDBusToolTipStruct*>(_v) = _t->toolTip(); break;
        default: break;
        }
    }
}

const QMetaObject *QStatusNotifierItemAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QStatusNotifierItemAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN26QStatusNotifierItemAdaptorE_t>.strings))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int QStatusNotifierItemAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void QStatusNotifierItemAdaptor::NewAttentionIcon()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QStatusNotifierItemAdaptor::NewIcon()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QStatusNotifierItemAdaptor::NewOverlayIcon()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QStatusNotifierItemAdaptor::NewMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QStatusNotifierItemAdaptor::NewStatus(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QStatusNotifierItemAdaptor::NewTitle()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QStatusNotifierItemAdaptor::NewToolTip()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP

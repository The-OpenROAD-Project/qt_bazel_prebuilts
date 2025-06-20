/****************************************************************************
** Meta object code from reading C++ file 'qdbusmenuadaptor_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/platform/unix/dbusmenu/qdbusmenuadaptor_p.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdbusmenuadaptor_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN16QDBusMenuAdaptorE_t {};
} // unnamed namespace

template <> constexpr inline auto QDBusMenuAdaptor::qt_create_metaobjectdata<qt_meta_tag_ZN16QDBusMenuAdaptorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDBusMenuAdaptor",
        "D-Bus Interface",
        "com.canonical.dbusmenu",
        "D-Bus Introspection",
        "  <interface name=\"com.canonical.dbusmenu\">\n    <property acces"
        "s=\"read\" type=\"u\" name=\"Version\">\n    </property>\n    <pro"
        "perty access=\"read\" type=\"s\" name=\"TextDirection\">\n    </pr"
        "operty>\n    <property access=\"read\" type=\"s\" name=\"Status\">"
        "\n    </property>\n    <property access=\"read\" type=\"as\" name="
        "\"IconThemePath\">\n    </property>\n    <method name=\"GetLayout\""
        ">\n      <annotation value=\"QDBusMenuLayoutItem\" name=\"org.qtpr"
        "oject.QtDBus.QtTypeName.Out1\"/>\n      <arg direction=\"in\" type"
        "=\"i\" name=\"parentId\"/>\n      <arg direction=\"in\" type=\"i\""
        " name=\"recursionDepth\"/>\n      <arg direction=\"in\" type=\"as\""
        " name=\"propertyNames\"/>\n      <arg direction=\"out\" type=\"u\""
        " name=\"revision\"/>\n      <arg direction=\"out\" type=\"(ia{sv}a"
        "v)\" name=\"layout\"/>\n    </method>\n    <method name=\"GetGroup"
        "Properties\">\n      <annotation value=\"QList&lt;int&gt;\" name=\""
        "org.qtproject.QtDBus.QtTypeName.In0\"/>\n      <annotation value=\""
        "QDBusMenuItemList\" name=\"org.qtproject.QtDBus.QtTypeName.Out0\"/"
        ">\n      <arg direction=\"in\" type=\"ai\" name=\"ids\"/>\n      <"
        "arg direction=\"in\" type=\"as\" name=\"propertyNames\"/>\n      <"
        "arg direction=\"out\" type=\"a(ia{sv})\" name=\"properties\"/>\n  "
        "  </method>\n    <method name=\"GetProperty\">\n      <arg directi"
        "on=\"in\" type=\"i\" name=\"id\"/>\n      <arg direction=\"in\" ty"
        "pe=\"s\" name=\"name\"/>\n      <arg direction=\"out\" type=\"v\" "
        "name=\"value\"/>\n    </method>\n    <method name=\"Event\">\n    "
        "  <arg direction=\"in\" type=\"i\" name=\"id\"/>\n      <arg direc"
        "tion=\"in\" type=\"s\" name=\"eventId\"/>\n      <arg direction=\""
        "in\" type=\"v\" name=\"data\"/>\n      <arg direction=\"in\" type="
        "\"u\" name=\"timestamp\"/>\n    </method>\n    <method name=\"Even"
        "tGroup\">\n      <annotation value=\"QList&lt;QDBusMenuEvent&gt;\""
        " name=\"org.qtproject.QtDBus.QtTypeName.In0\"/>\n      <annotation"
        " value=\"QList&lt;int&gt;\" name=\"org.qtproject.QtDBus.QtTypeName"
        ".Out0\"/>\n      <arg direction=\"in\" type=\"a(isvu)\" name=\"eve"
        "nts\"/>\n      <arg direction=\"out\" type=\"ai\" name=\"idErrors\""
        "/>\n    </method>\n    <method name=\"AboutToShow\">\n      <arg d"
        "irection=\"in\" type=\"i\" name=\"id\"/>\n      <arg direction=\"o"
        "ut\" type=\"b\" name=\"needUpdate\"/>\n    </method>\n    <method "
        "name=\"AboutToShowGroup\">\n      <annotation value=\"QList&lt;int"
        "&gt;\" name=\"org.qtproject.QtDBus.QtTypeName.In0\"/>\n      <anno"
        "tation value=\"QList&lt;int&gt;\" name=\"org.qtproject.QtDBus.QtTy"
        "peName.Out0\"/>\n      <annotation value=\"QList&lt;int&gt;\" name"
        "=\"org.qtproject.QtDBus.QtTypeName.Out1\"/>\n      <arg direction="
        "\"in\" type=\"ai\" name=\"ids\"/>\n      <arg direction=\"out\" ty"
        "pe=\"ai\" name=\"updatesNeeded\"/>\n      <arg direction=\"out\" t"
        "ype=\"ai\" name=\"idErrors\"/>\n    </method>\n    <signal name=\""
        "ItemsPropertiesUpdated\">\n      <annotation value=\"QDBusMenuItem"
        "List\" name=\"org.qtproject.QtDBus.QtTypeName.In0\"/>\n      <anno"
        "tation value=\"QDBusMenuItemKeysList\" name=\"org.qtproject.QtDBus"
        ".QtTypeName.In1\"/>\n      <arg direction=\"out\" type=\"a(ia{sv})"
        "\" name=\"updatedProps\"/>\n      <arg direction=\"out\" type=\"a("
        "ias)\" name=\"removedProps\"/>\n    </signal>\n    <signal name=\""
        "LayoutUpdated\">\n      <arg direction=\"out\" type=\"u\" name=\"r"
        "evision\"/>\n      <arg direction=\"out\" type=\"i\" name=\"parent"
        "\"/>\n    </signal>\n    <signal name=\"ItemActivationRequested\">"
        "\n      <arg direction=\"out\" type=\"i\" name=\"id\"/>\n      <ar"
        "g direction=\"out\" type=\"u\" name=\"timestamp\"/>\n    </signal>"
        "\n  </interface>\n",
        "ItemActivationRequested",
        "",
        "id",
        "timestamp",
        "ItemsPropertiesUpdated",
        "QDBusMenuItemList",
        "updatedProps",
        "QDBusMenuItemKeysList",
        "removedProps",
        "LayoutUpdated",
        "revision",
        "parent",
        "AboutToShow",
        "AboutToShowGroup",
        "QList<int>",
        "ids",
        "QList<int>&",
        "idErrors",
        "Event",
        "eventId",
        "QDBusVariant",
        "data",
        "EventGroup",
        "QDBusMenuEventList",
        "events",
        "GetGroupProperties",
        "propertyNames",
        "GetLayout",
        "parentId",
        "recursionDepth",
        "QDBusMenuLayoutItem&",
        "layout",
        "GetProperty",
        "name",
        "Status",
        "TextDirection",
        "Version"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'ItemActivationRequested'
        QtMocHelpers::SignalData<void(int, uint)>(5, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 }, { QMetaType::UInt, 8 },
        }}),
        // Signal 'ItemsPropertiesUpdated'
        QtMocHelpers::SignalData<void(const QDBusMenuItemList &, const QDBusMenuItemKeysList &)>(9, 6, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 11 }, { 0x80000000 | 12, 13 },
        }}),
        // Signal 'LayoutUpdated'
        QtMocHelpers::SignalData<void(uint, int)>(14, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 15 }, { QMetaType::Int, 16 },
        }}),
        // Slot 'AboutToShow'
        QtMocHelpers::SlotData<bool(int)>(17, 6, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'AboutToShowGroup'
        QtMocHelpers::SlotData<QList<int>(const QList<int> &, QList<int> &)>(18, 6, QMC::AccessPublic, 0x80000000 | 19, {{
            { 0x80000000 | 19, 20 }, { 0x80000000 | 21, 22 },
        }}),
        // Slot 'Event'
        QtMocHelpers::SlotData<void(int, const QString &, const QDBusVariant &, uint)>(23, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 }, { QMetaType::QString, 24 }, { 0x80000000 | 25, 26 }, { QMetaType::UInt, 8 },
        }}),
        // Slot 'EventGroup'
        QtMocHelpers::SlotData<QList<int>(const QDBusMenuEventList &)>(27, 6, QMC::AccessPublic, 0x80000000 | 19, {{
            { 0x80000000 | 28, 29 },
        }}),
        // Slot 'GetGroupProperties'
        QtMocHelpers::SlotData<QDBusMenuItemList(const QList<int> &, const QStringList &)>(30, 6, QMC::AccessPublic, 0x80000000 | 10, {{
            { 0x80000000 | 19, 20 }, { QMetaType::QStringList, 31 },
        }}),
        // Slot 'GetLayout'
        QtMocHelpers::SlotData<uint(int, int, const QStringList &, QDBusMenuLayoutItem &)>(32, 6, QMC::AccessPublic, QMetaType::UInt, {{
            { QMetaType::Int, 33 }, { QMetaType::Int, 34 }, { QMetaType::QStringList, 31 }, { 0x80000000 | 35, 36 },
        }}),
        // Slot 'GetProperty'
        QtMocHelpers::SlotData<QDBusVariant(int, const QString &)>(37, 6, QMC::AccessPublic, 0x80000000 | 25, {{
            { QMetaType::Int, 7 }, { QMetaType::QString, 38 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'Status'
        QtMocHelpers::PropertyData<QString>(39, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'TextDirection'
        QtMocHelpers::PropertyData<QString>(40, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'Version'
        QtMocHelpers::PropertyData<uint>(41, QMetaType::UInt, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<QDBusMenuAdaptor, qt_meta_tag_ZN16QDBusMenuAdaptorE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject QDBusMenuAdaptor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractAdaptor::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QDBusMenuAdaptorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QDBusMenuAdaptorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16QDBusMenuAdaptorE_t>.metaTypes,
    nullptr
} };

void QDBusMenuAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDBusMenuAdaptor *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->ItemActivationRequested((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2]))); break;
        case 1: _t->ItemsPropertiesUpdated((*reinterpret_cast< std::add_pointer_t<QDBusMenuItemList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDBusMenuItemKeysList>>(_a[2]))); break;
        case 2: _t->LayoutUpdated((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: { bool _r = _t->AboutToShow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { QList<int> _r = _t->AboutToShowGroup((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<int>&>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->Event((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QDBusVariant>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[4]))); break;
        case 6: { QList<int> _r = _t->EventGroup((*reinterpret_cast< std::add_pointer_t<QDBusMenuEventList>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 7: { QDBusMenuItemList _r = _t->GetGroupProperties((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusMenuItemList*>(_a[0]) = std::move(_r); }  break;
        case 8: { uint _r = _t->GetLayout((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QDBusMenuLayoutItem&>>(_a[4])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 9: { QDBusVariant _r = _t->GetProperty((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusVariant*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusMenuItemKeysList >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusMenuItemList >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 2:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusVariant >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusMenuEventList >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QDBusMenuAdaptor::*)(int , uint )>(_a, &QDBusMenuAdaptor::ItemActivationRequested, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusMenuAdaptor::*)(const QDBusMenuItemList & , const QDBusMenuItemKeysList & )>(_a, &QDBusMenuAdaptor::ItemsPropertiesUpdated, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusMenuAdaptor::*)(uint , int )>(_a, &QDBusMenuAdaptor::LayoutUpdated, 2))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->status(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->textDirection(); break;
        case 2: *reinterpret_cast<uint*>(_v) = _t->version(); break;
        default: break;
        }
    }
}

const QMetaObject *QDBusMenuAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDBusMenuAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QDBusMenuAdaptorE_t>.strings))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int QDBusMenuAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QDBusMenuAdaptor::ItemActivationRequested(int _t1, uint _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void QDBusMenuAdaptor::ItemsPropertiesUpdated(const QDBusMenuItemList & _t1, const QDBusMenuItemKeysList & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void QDBusMenuAdaptor::LayoutUpdated(uint _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}
QT_WARNING_POP

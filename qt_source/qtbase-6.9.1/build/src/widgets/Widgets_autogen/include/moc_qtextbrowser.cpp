/****************************************************************************
** Meta object code from reading C++ file 'qtextbrowser.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qtextbrowser.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtextbrowser.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12QTextBrowserE_t {};
} // unnamed namespace

template <> constexpr inline auto QTextBrowser::qt_create_metaobjectdata<qt_meta_tag_ZN12QTextBrowserE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QTextBrowser",
        "backwardAvailable",
        "",
        "forwardAvailable",
        "historyChanged",
        "sourceChanged",
        "highlighted",
        "anchorClicked",
        "setSource",
        "name",
        "QTextDocument::ResourceType",
        "type",
        "backward",
        "forward",
        "home",
        "reload",
        "source",
        "sourceType",
        "searchPaths",
        "openExternalLinks",
        "openLinks"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'backwardAvailable'
        QtMocHelpers::SignalData<void(bool)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Signal 'forwardAvailable'
        QtMocHelpers::SignalData<void(bool)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Signal 'historyChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'sourceChanged'
        QtMocHelpers::SignalData<void(const QUrl &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QUrl, 2 },
        }}),
        // Signal 'highlighted'
        QtMocHelpers::SignalData<void(const QUrl &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QUrl, 2 },
        }}),
        // Signal 'anchorClicked'
        QtMocHelpers::SignalData<void(const QUrl &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QUrl, 2 },
        }}),
        // Slot 'setSource'
        QtMocHelpers::SlotData<void(const QUrl &, QTextDocument::ResourceType)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QUrl, 9 }, { 0x80000000 | 10, 11 },
        }}),
        // Slot 'setSource'
        QtMocHelpers::SlotData<void(const QUrl &)>(8, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QUrl, 9 },
        }}),
        // Slot 'backward'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'forward'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'home'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'reload'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'source'
        QtMocHelpers::PropertyData<QUrl>(16, QMetaType::QUrl, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'sourceType'
        QtMocHelpers::PropertyData<QTextDocument::ResourceType>(17, 0x80000000 | 10, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'searchPaths'
        QtMocHelpers::PropertyData<QStringList>(18, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'openExternalLinks'
        QtMocHelpers::PropertyData<bool>(19, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'openLinks'
        QtMocHelpers::PropertyData<bool>(20, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QTextBrowser, qt_meta_tag_ZN12QTextBrowserE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN12QTextBrowserE[] = {
    QMetaObject::SuperData::link<QTextDocument::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject QTextBrowser::staticMetaObject = { {
    QMetaObject::SuperData::link<QTextEdit::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QTextBrowserE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QTextBrowserE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN12QTextBrowserE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12QTextBrowserE_t>.metaTypes,
    nullptr
} };

void QTextBrowser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QTextBrowser *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->backwardAvailable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->forwardAvailable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->historyChanged(); break;
        case 3: _t->sourceChanged((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 4: _t->highlighted((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 5: _t->anchorClicked((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 6: _t->setSource((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTextDocument::ResourceType>>(_a[2]))); break;
        case 7: _t->setSource((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 8: _t->backward(); break;
        case 9: _t->forward(); break;
        case 10: _t->home(); break;
        case 11: _t->reload(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QTextBrowser::*)(bool )>(_a, &QTextBrowser::backwardAvailable, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextBrowser::*)(bool )>(_a, &QTextBrowser::forwardAvailable, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextBrowser::*)()>(_a, &QTextBrowser::historyChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextBrowser::*)(const QUrl & )>(_a, &QTextBrowser::sourceChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextBrowser::*)(const QUrl & )>(_a, &QTextBrowser::highlighted, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextBrowser::*)(const QUrl & )>(_a, &QTextBrowser::anchorClicked, 5))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QUrl*>(_v) = _t->source(); break;
        case 1: *reinterpret_cast<QTextDocument::ResourceType*>(_v) = _t->sourceType(); break;
        case 2: *reinterpret_cast<QStringList*>(_v) = _t->searchPaths(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->openExternalLinks(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->openLinks(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSource(*reinterpret_cast<QUrl*>(_v)); break;
        case 2: _t->setSearchPaths(*reinterpret_cast<QStringList*>(_v)); break;
        case 3: _t->setOpenExternalLinks(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setOpenLinks(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QTextBrowser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTextBrowser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QTextBrowserE_t>.strings))
        return static_cast<void*>(this);
    return QTextEdit::qt_metacast(_clname);
}

int QTextBrowser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
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
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QTextBrowser::backwardAvailable(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QTextBrowser::forwardAvailable(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QTextBrowser::historyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QTextBrowser::sourceChanged(const QUrl & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QTextBrowser::highlighted(const QUrl & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QTextBrowser::anchorClicked(const QUrl & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}
QT_WARNING_POP

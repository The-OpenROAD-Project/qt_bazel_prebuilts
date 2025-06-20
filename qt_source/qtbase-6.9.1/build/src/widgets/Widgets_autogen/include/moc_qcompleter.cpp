/****************************************************************************
** Meta object code from reading C++ file 'qcompleter.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/util/qcompleter.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcompleter.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10QCompleterE_t {};
} // unnamed namespace

template <> constexpr inline auto QCompleter::qt_create_metaobjectdata<qt_meta_tag_ZN10QCompleterE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QCompleter",
        "activated",
        "",
        "text",
        "QModelIndex",
        "index",
        "highlighted",
        "setCompletionPrefix",
        "prefix",
        "complete",
        "rect",
        "setWrapAround",
        "wrap",
        "_q_complete",
        "_q_completionSelected",
        "QItemSelection",
        "_q_autoResizePopup",
        "_q_fileSystemModelDirectoryLoaded",
        "completionPrefix",
        "modelSorting",
        "ModelSorting",
        "filterMode",
        "Qt::MatchFlags",
        "completionMode",
        "CompletionMode",
        "completionColumn",
        "completionRole",
        "maxVisibleItems",
        "caseSensitivity",
        "Qt::CaseSensitivity",
        "wrapAround",
        "PopupCompletion",
        "UnfilteredPopupCompletion",
        "InlineCompletion",
        "UnsortedModel",
        "CaseSensitivelySortedModel",
        "CaseInsensitivelySortedModel"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'activated'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'activated'
        QtMocHelpers::SignalData<void(const QModelIndex &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Signal 'highlighted'
        QtMocHelpers::SignalData<void(const QString &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'highlighted'
        QtMocHelpers::SignalData<void(const QModelIndex &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Slot 'setCompletionPrefix'
        QtMocHelpers::SlotData<void(const QString &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 },
        }}),
        // Slot 'complete'
        QtMocHelpers::SlotData<void(const QRect &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRect, 10 },
        }}),
        // Slot 'complete'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'setWrapAround'
        QtMocHelpers::SlotData<void(bool)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 12 },
        }}),
        // Slot '_q_complete'
        QtMocHelpers::SlotData<void(QModelIndex)>(13, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 4, 2 },
        }}),
        // Slot '_q_completionSelected'
        QtMocHelpers::SlotData<void(const QItemSelection &)>(14, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 15, 2 },
        }}),
        // Slot '_q_autoResizePopup'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_fileSystemModelDirectoryLoaded'
        QtMocHelpers::SlotData<void(const QString &)>(17, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'completionPrefix'
        QtMocHelpers::PropertyData<QString>(18, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'modelSorting'
        QtMocHelpers::PropertyData<ModelSorting>(19, 0x80000000 | 20, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'filterMode'
        QtMocHelpers::PropertyData<Qt::MatchFlags>(21, 0x80000000 | 22, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'completionMode'
        QtMocHelpers::PropertyData<CompletionMode>(23, 0x80000000 | 24, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'completionColumn'
        QtMocHelpers::PropertyData<int>(25, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'completionRole'
        QtMocHelpers::PropertyData<int>(26, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'maxVisibleItems'
        QtMocHelpers::PropertyData<int>(27, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'caseSensitivity'
        QtMocHelpers::PropertyData<Qt::CaseSensitivity>(28, 0x80000000 | 29, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'wrapAround'
        QtMocHelpers::PropertyData<bool>(30, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'CompletionMode'
        QtMocHelpers::EnumData<CompletionMode>(24, 24, QMC::EnumFlags{}).add({
            {   31, CompletionMode::PopupCompletion },
            {   32, CompletionMode::UnfilteredPopupCompletion },
            {   33, CompletionMode::InlineCompletion },
        }),
        // enum 'ModelSorting'
        QtMocHelpers::EnumData<ModelSorting>(20, 20, QMC::EnumFlags{}).add({
            {   34, ModelSorting::UnsortedModel },
            {   35, ModelSorting::CaseSensitivelySortedModel },
            {   36, ModelSorting::CaseInsensitivelySortedModel },
        }),
    };
    return QtMocHelpers::metaObjectData<QCompleter, qt_meta_tag_ZN10QCompleterE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QCompleter::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QCompleterE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QCompleterE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10QCompleterE_t>.metaTypes,
    nullptr
} };

void QCompleter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QCompleter *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->activated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->activated((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 2: _t->highlighted((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->highlighted((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 4: _t->setCompletionPrefix((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->complete((*reinterpret_cast< std::add_pointer_t<QRect>>(_a[1]))); break;
        case 6: _t->complete(); break;
        case 7: _t->setWrapAround((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->d_func()->_q_complete((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 9: _t->d_func()->_q_completionSelected((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1]))); break;
        case 10: _t->d_func()->_q_autoResizePopup(); break;
        case 11: _t->d_func()->_q_fileSystemModelDirectoryLoaded((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QCompleter::*)(const QString & )>(_a, &QCompleter::activated, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QCompleter::*)(const QModelIndex & )>(_a, &QCompleter::activated, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QCompleter::*)(const QString & )>(_a, &QCompleter::highlighted, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QCompleter::*)(const QModelIndex & )>(_a, &QCompleter::highlighted, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->completionPrefix(); break;
        case 1: *reinterpret_cast<ModelSorting*>(_v) = _t->modelSorting(); break;
        case 2: *reinterpret_cast<Qt::MatchFlags*>(_v) = _t->filterMode(); break;
        case 3: *reinterpret_cast<CompletionMode*>(_v) = _t->completionMode(); break;
        case 4: *reinterpret_cast<int*>(_v) = _t->completionColumn(); break;
        case 5: *reinterpret_cast<int*>(_v) = _t->completionRole(); break;
        case 6: *reinterpret_cast<int*>(_v) = _t->maxVisibleItems(); break;
        case 7: *reinterpret_cast<Qt::CaseSensitivity*>(_v) = _t->caseSensitivity(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->wrapAround(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCompletionPrefix(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setModelSorting(*reinterpret_cast<ModelSorting*>(_v)); break;
        case 2: _t->setFilterMode(*reinterpret_cast<Qt::MatchFlags*>(_v)); break;
        case 3: _t->setCompletionMode(*reinterpret_cast<CompletionMode*>(_v)); break;
        case 4: _t->setCompletionColumn(*reinterpret_cast<int*>(_v)); break;
        case 5: _t->setCompletionRole(*reinterpret_cast<int*>(_v)); break;
        case 6: _t->setMaxVisibleItems(*reinterpret_cast<int*>(_v)); break;
        case 7: _t->setCaseSensitivity(*reinterpret_cast<Qt::CaseSensitivity*>(_v)); break;
        case 8: _t->setWrapAround(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QCompleter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCompleter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QCompleterE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QCompleter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void QCompleter::activated(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QCompleter::activated(const QModelIndex & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QCompleter::highlighted(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QCompleter::highlighted(const QModelIndex & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
QT_WARNING_POP

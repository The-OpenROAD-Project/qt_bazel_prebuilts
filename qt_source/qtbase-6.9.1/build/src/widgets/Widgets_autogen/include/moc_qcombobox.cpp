/****************************************************************************
** Meta object code from reading C++ file 'qcombobox.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qcombobox.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcombobox.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9QComboBoxE_t {};
} // unnamed namespace

template <> constexpr inline auto QComboBox::qt_create_metaobjectdata<qt_meta_tag_ZN9QComboBoxE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QComboBox",
        "editTextChanged",
        "",
        "activated",
        "index",
        "textActivated",
        "highlighted",
        "textHighlighted",
        "currentIndexChanged",
        "currentTextChanged",
        "clear",
        "clearEditText",
        "setEditText",
        "text",
        "setCurrentIndex",
        "setCurrentText",
        "inputMethodQuery",
        "QVariant",
        "Qt::InputMethodQuery",
        "query",
        "argument",
        "editable",
        "count",
        "currentText",
        "currentIndex",
        "currentData",
        "maxVisibleItems",
        "maxCount",
        "insertPolicy",
        "InsertPolicy",
        "sizeAdjustPolicy",
        "SizeAdjustPolicy",
        "minimumContentsLength",
        "iconSize",
        "placeholderText",
        "duplicatesEnabled",
        "frame",
        "modelColumn",
        "labelDrawingMode",
        "LabelDrawingMode",
        "NoInsert",
        "InsertAtTop",
        "InsertAtCurrent",
        "InsertAtBottom",
        "InsertAfterCurrent",
        "InsertBeforeCurrent",
        "InsertAlphabetically",
        "AdjustToContents",
        "AdjustToContentsOnFirstShow",
        "AdjustToMinimumContentsLengthWithIcon",
        "UseStyle",
        "UseDelegate"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'editTextChanged'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'activated'
        QtMocHelpers::SignalData<void(int)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 4 },
        }}),
        // Signal 'textActivated'
        QtMocHelpers::SignalData<void(const QString &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'highlighted'
        QtMocHelpers::SignalData<void(int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 4 },
        }}),
        // Signal 'textHighlighted'
        QtMocHelpers::SignalData<void(const QString &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'currentIndexChanged'
        QtMocHelpers::SignalData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 4 },
        }}),
        // Signal 'currentTextChanged'
        QtMocHelpers::SignalData<void(const QString &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Slot 'clear'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'clearEditText'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setEditText'
        QtMocHelpers::SlotData<void(const QString &)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 13 },
        }}),
        // Slot 'setCurrentIndex'
        QtMocHelpers::SlotData<void(int)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 4 },
        }}),
        // Slot 'setCurrentText'
        QtMocHelpers::SlotData<void(const QString &)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 13 },
        }}),
        // Method 'inputMethodQuery'
        QtMocHelpers::MethodData<QVariant(Qt::InputMethodQuery, const QVariant &) const>(16, 2, QMC::AccessPublic, 0x80000000 | 17, {{
            { 0x80000000 | 18, 19 }, { 0x80000000 | 17, 20 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'editable'
        QtMocHelpers::PropertyData<bool>(21, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'count'
        QtMocHelpers::PropertyData<int>(22, QMetaType::Int, QMC::DefaultPropertyFlags),
        // property 'currentText'
        QtMocHelpers::PropertyData<QString>(23, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::User, 6),
        // property 'currentIndex'
        QtMocHelpers::PropertyData<int>(24, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
        // property 'currentData'
        QtMocHelpers::PropertyData<QVariant>(25, 0x80000000 | 17, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'maxVisibleItems'
        QtMocHelpers::PropertyData<int>(26, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'maxCount'
        QtMocHelpers::PropertyData<int>(27, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'insertPolicy'
        QtMocHelpers::PropertyData<InsertPolicy>(28, 0x80000000 | 29, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'sizeAdjustPolicy'
        QtMocHelpers::PropertyData<SizeAdjustPolicy>(30, 0x80000000 | 31, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'minimumContentsLength'
        QtMocHelpers::PropertyData<int>(32, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'iconSize'
        QtMocHelpers::PropertyData<QSize>(33, QMetaType::QSize, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'placeholderText'
        QtMocHelpers::PropertyData<QString>(34, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'duplicatesEnabled'
        QtMocHelpers::PropertyData<bool>(35, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'frame'
        QtMocHelpers::PropertyData<bool>(36, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'modelColumn'
        QtMocHelpers::PropertyData<int>(37, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'labelDrawingMode'
        QtMocHelpers::PropertyData<LabelDrawingMode>(38, 0x80000000 | 39, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'InsertPolicy'
        QtMocHelpers::EnumData<InsertPolicy>(29, 29, QMC::EnumFlags{}).add({
            {   40, InsertPolicy::NoInsert },
            {   41, InsertPolicy::InsertAtTop },
            {   42, InsertPolicy::InsertAtCurrent },
            {   43, InsertPolicy::InsertAtBottom },
            {   44, InsertPolicy::InsertAfterCurrent },
            {   45, InsertPolicy::InsertBeforeCurrent },
            {   46, InsertPolicy::InsertAlphabetically },
        }),
        // enum 'SizeAdjustPolicy'
        QtMocHelpers::EnumData<SizeAdjustPolicy>(31, 31, QMC::EnumFlags{}).add({
            {   47, SizeAdjustPolicy::AdjustToContents },
            {   48, SizeAdjustPolicy::AdjustToContentsOnFirstShow },
            {   49, SizeAdjustPolicy::AdjustToMinimumContentsLengthWithIcon },
        }),
        // enum 'LabelDrawingMode'
        QtMocHelpers::EnumData<LabelDrawingMode>(39, 39, QMC::EnumIsScoped).add({
            {   50, LabelDrawingMode::UseStyle },
            {   51, LabelDrawingMode::UseDelegate },
        }),
    };
    return QtMocHelpers::metaObjectData<QComboBox, qt_meta_tag_ZN9QComboBoxE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QComboBox::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QComboBoxE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QComboBoxE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9QComboBoxE_t>.metaTypes,
    nullptr
} };

void QComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QComboBox *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->editTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->textActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->highlighted((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->textHighlighted((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->clear(); break;
        case 8: _t->clearEditText(); break;
        case 9: _t->setEditText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->setCurrentIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->setCurrentText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: { QVariant _r = _t->inputMethodQuery((*reinterpret_cast< std::add_pointer_t<Qt::InputMethodQuery>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QComboBox::*)(const QString & )>(_a, &QComboBox::editTextChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QComboBox::*)(int )>(_a, &QComboBox::activated, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QComboBox::*)(const QString & )>(_a, &QComboBox::textActivated, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QComboBox::*)(int )>(_a, &QComboBox::highlighted, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QComboBox::*)(const QString & )>(_a, &QComboBox::textHighlighted, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QComboBox::*)(int )>(_a, &QComboBox::currentIndexChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QComboBox::*)(const QString & )>(_a, &QComboBox::currentTextChanged, 6))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isEditable(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->count(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->currentText(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->currentIndex(); break;
        case 4: *reinterpret_cast<QVariant*>(_v) = _t->currentData(); break;
        case 5: *reinterpret_cast<int*>(_v) = _t->maxVisibleItems(); break;
        case 6: *reinterpret_cast<int*>(_v) = _t->maxCount(); break;
        case 7: *reinterpret_cast<InsertPolicy*>(_v) = _t->insertPolicy(); break;
        case 8: *reinterpret_cast<SizeAdjustPolicy*>(_v) = _t->sizeAdjustPolicy(); break;
        case 9: *reinterpret_cast<int*>(_v) = _t->minimumContentsLength(); break;
        case 10: *reinterpret_cast<QSize*>(_v) = _t->iconSize(); break;
        case 11: *reinterpret_cast<QString*>(_v) = _t->placeholderText(); break;
        case 12: *reinterpret_cast<bool*>(_v) = _t->duplicatesEnabled(); break;
        case 13: *reinterpret_cast<bool*>(_v) = _t->hasFrame(); break;
        case 14: *reinterpret_cast<int*>(_v) = _t->modelColumn(); break;
        case 15: *reinterpret_cast<LabelDrawingMode*>(_v) = _t->labelDrawingMode(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setEditable(*reinterpret_cast<bool*>(_v)); break;
        case 2: _t->setCurrentText(*reinterpret_cast<QString*>(_v)); break;
        case 3: _t->setCurrentIndex(*reinterpret_cast<int*>(_v)); break;
        case 5: _t->setMaxVisibleItems(*reinterpret_cast<int*>(_v)); break;
        case 6: _t->setMaxCount(*reinterpret_cast<int*>(_v)); break;
        case 7: _t->setInsertPolicy(*reinterpret_cast<InsertPolicy*>(_v)); break;
        case 8: _t->setSizeAdjustPolicy(*reinterpret_cast<SizeAdjustPolicy*>(_v)); break;
        case 9: _t->setMinimumContentsLength(*reinterpret_cast<int*>(_v)); break;
        case 10: _t->setIconSize(*reinterpret_cast<QSize*>(_v)); break;
        case 11: _t->setPlaceholderText(*reinterpret_cast<QString*>(_v)); break;
        case 12: _t->setDuplicatesEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 13: _t->setFrame(*reinterpret_cast<bool*>(_v)); break;
        case 14: _t->setModelColumn(*reinterpret_cast<int*>(_v)); break;
        case 15: _t->setLabelDrawingMode(*reinterpret_cast<LabelDrawingMode*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QComboBoxE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void QComboBox::editTextChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QComboBox::activated(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QComboBox::textActivated(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QComboBox::highlighted(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QComboBox::textHighlighted(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QComboBox::currentIndexChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void QComboBox::currentTextChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}
QT_WARNING_POP

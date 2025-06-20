/****************************************************************************
** Meta object code from reading C++ file 'qabstractspinbox.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qabstractspinbox.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qabstractspinbox.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN16QAbstractSpinBoxE_t {};
} // unnamed namespace

template <> constexpr inline auto QAbstractSpinBox::qt_create_metaobjectdata<qt_meta_tag_ZN16QAbstractSpinBoxE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QAbstractSpinBox",
        "editingFinished",
        "",
        "stepUp",
        "stepDown",
        "selectAll",
        "clear",
        "wrapping",
        "frame",
        "alignment",
        "Qt::Alignment",
        "readOnly",
        "buttonSymbols",
        "ButtonSymbols",
        "specialValueText",
        "text",
        "accelerated",
        "correctionMode",
        "CorrectionMode",
        "acceptableInput",
        "keyboardTracking",
        "showGroupSeparator",
        "UpDownArrows",
        "PlusMinus",
        "NoButtons",
        "CorrectToPreviousValue",
        "CorrectToNearestValue",
        "StepType",
        "DefaultStepType",
        "AdaptiveDecimalStepType"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'editingFinished'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stepUp'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stepDown'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'selectAll'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'clear'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'wrapping'
        QtMocHelpers::PropertyData<bool>(7, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'frame'
        QtMocHelpers::PropertyData<bool>(8, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'alignment'
        QtMocHelpers::PropertyData<Qt::Alignment>(9, 0x80000000 | 10, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'readOnly'
        QtMocHelpers::PropertyData<bool>(11, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'buttonSymbols'
        QtMocHelpers::PropertyData<ButtonSymbols>(12, 0x80000000 | 13, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'specialValueText'
        QtMocHelpers::PropertyData<QString>(14, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'text'
        QtMocHelpers::PropertyData<QString>(15, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'accelerated'
        QtMocHelpers::PropertyData<bool>(16, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'correctionMode'
        QtMocHelpers::PropertyData<CorrectionMode>(17, 0x80000000 | 18, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'acceptableInput'
        QtMocHelpers::PropertyData<bool>(19, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'keyboardTracking'
        QtMocHelpers::PropertyData<bool>(20, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'showGroupSeparator'
        QtMocHelpers::PropertyData<bool>(21, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ButtonSymbols'
        QtMocHelpers::EnumData<ButtonSymbols>(13, 13, QMC::EnumFlags{}).add({
            {   22, ButtonSymbols::UpDownArrows },
            {   23, ButtonSymbols::PlusMinus },
            {   24, ButtonSymbols::NoButtons },
        }),
        // enum 'CorrectionMode'
        QtMocHelpers::EnumData<CorrectionMode>(18, 18, QMC::EnumFlags{}).add({
            {   25, CorrectionMode::CorrectToPreviousValue },
            {   26, CorrectionMode::CorrectToNearestValue },
        }),
        // enum 'StepType'
        QtMocHelpers::EnumData<StepType>(27, 27, QMC::EnumFlags{}).add({
            {   28, StepType::DefaultStepType },
            {   29, StepType::AdaptiveDecimalStepType },
        }),
    };
    return QtMocHelpers::metaObjectData<QAbstractSpinBox, qt_meta_tag_ZN16QAbstractSpinBoxE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QAbstractSpinBox::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QAbstractSpinBoxE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QAbstractSpinBoxE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16QAbstractSpinBoxE_t>.metaTypes,
    nullptr
} };

void QAbstractSpinBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QAbstractSpinBox *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->editingFinished(); break;
        case 1: _t->stepUp(); break;
        case 2: _t->stepDown(); break;
        case 3: _t->selectAll(); break;
        case 4: _t->clear(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QAbstractSpinBox::*)()>(_a, &QAbstractSpinBox::editingFinished, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->wrapping(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->hasFrame(); break;
        case 2: *reinterpret_cast<Qt::Alignment*>(_v) = _t->alignment(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->isReadOnly(); break;
        case 4: *reinterpret_cast<ButtonSymbols*>(_v) = _t->buttonSymbols(); break;
        case 5: *reinterpret_cast<QString*>(_v) = _t->specialValueText(); break;
        case 6: *reinterpret_cast<QString*>(_v) = _t->text(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->isAccelerated(); break;
        case 8: *reinterpret_cast<CorrectionMode*>(_v) = _t->correctionMode(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->hasAcceptableInput(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->keyboardTracking(); break;
        case 11: *reinterpret_cast<bool*>(_v) = _t->isGroupSeparatorShown(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setWrapping(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setFrame(*reinterpret_cast<bool*>(_v)); break;
        case 2: _t->setAlignment(*reinterpret_cast<Qt::Alignment*>(_v)); break;
        case 3: _t->setReadOnly(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setButtonSymbols(*reinterpret_cast<ButtonSymbols*>(_v)); break;
        case 5: _t->setSpecialValueText(*reinterpret_cast<QString*>(_v)); break;
        case 7: _t->setAccelerated(*reinterpret_cast<bool*>(_v)); break;
        case 8: _t->setCorrectionMode(*reinterpret_cast<CorrectionMode*>(_v)); break;
        case 10: _t->setKeyboardTracking(*reinterpret_cast<bool*>(_v)); break;
        case 11: _t->setGroupSeparatorShown(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QAbstractSpinBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAbstractSpinBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QAbstractSpinBoxE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QAbstractSpinBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void QAbstractSpinBox::editingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP

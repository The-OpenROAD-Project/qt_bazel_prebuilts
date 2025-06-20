/****************************************************************************
** Meta object code from reading C++ file 'qkeysequenceedit.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qkeysequenceedit.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qkeysequenceedit.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN16QKeySequenceEditE_t {};
} // unnamed namespace

template <> constexpr inline auto QKeySequenceEdit::qt_create_metaobjectdata<qt_meta_tag_ZN16QKeySequenceEditE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QKeySequenceEdit",
        "editingFinished",
        "",
        "keySequenceChanged",
        "QKeySequence",
        "keySequence",
        "setKeySequence",
        "clear",
        "setMaximumSequenceLength",
        "qsizetype",
        "count",
        "clearButtonEnabled",
        "maximumSequenceLength",
        "finishingKeyCombinations",
        "QList<QKeyCombination>"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'editingFinished'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'keySequenceChanged'
        QtMocHelpers::SignalData<void(const QKeySequence &)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Slot 'setKeySequence'
        QtMocHelpers::SlotData<void(const QKeySequence &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Slot 'clear'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setMaximumSequenceLength'
        QtMocHelpers::SlotData<void(qsizetype)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 9, 10 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'keySequence'
        QtMocHelpers::PropertyData<QKeySequence>(5, 0x80000000 | 4, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet | QMC::User, 1),
        // property 'clearButtonEnabled'
        QtMocHelpers::PropertyData<bool>(11, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'maximumSequenceLength'
        QtMocHelpers::PropertyData<qsizetype>(12, 0x80000000 | 9, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'finishingKeyCombinations'
        QtMocHelpers::PropertyData<QList<QKeyCombination>>(13, 0x80000000 | 14, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QKeySequenceEdit, qt_meta_tag_ZN16QKeySequenceEditE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QKeySequenceEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QKeySequenceEditE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QKeySequenceEditE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16QKeySequenceEditE_t>.metaTypes,
    nullptr
} };

void QKeySequenceEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QKeySequenceEdit *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->editingFinished(); break;
        case 1: _t->keySequenceChanged((*reinterpret_cast< std::add_pointer_t<QKeySequence>>(_a[1]))); break;
        case 2: _t->setKeySequence((*reinterpret_cast< std::add_pointer_t<QKeySequence>>(_a[1]))); break;
        case 3: _t->clear(); break;
        case 4: _t->setMaximumSequenceLength((*reinterpret_cast< std::add_pointer_t<qsizetype>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QKeySequenceEdit::*)()>(_a, &QKeySequenceEdit::editingFinished, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QKeySequenceEdit::*)(const QKeySequence & )>(_a, &QKeySequenceEdit::keySequenceChanged, 1))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QKeySequence*>(_v) = _t->keySequence(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->isClearButtonEnabled(); break;
        case 2: *reinterpret_cast<qsizetype*>(_v) = _t->maximumSequenceLength(); break;
        case 3: *reinterpret_cast<QList<QKeyCombination>*>(_v) = _t->finishingKeyCombinations(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setKeySequence(*reinterpret_cast<QKeySequence*>(_v)); break;
        case 1: _t->setClearButtonEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 2: _t->setMaximumSequenceLength(*reinterpret_cast<qsizetype*>(_v)); break;
        case 3: _t->setFinishingKeyCombinations(*reinterpret_cast<QList<QKeyCombination>*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QKeySequenceEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QKeySequenceEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QKeySequenceEditE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QKeySequenceEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QKeySequenceEdit::editingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QKeySequenceEdit::keySequenceChanged(const QKeySequence & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP

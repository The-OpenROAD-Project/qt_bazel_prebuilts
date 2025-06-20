/****************************************************************************
** Meta object code from reading C++ file 'qformlayout.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/kernel/qformlayout.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qformlayout.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11QFormLayoutE_t {};
} // unnamed namespace

template <> constexpr inline auto QFormLayout::qt_create_metaobjectdata<qt_meta_tag_ZN11QFormLayoutE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QFormLayout",
        "fieldGrowthPolicy",
        "FieldGrowthPolicy",
        "rowWrapPolicy",
        "RowWrapPolicy",
        "labelAlignment",
        "Qt::Alignment",
        "formAlignment",
        "horizontalSpacing",
        "verticalSpacing",
        "FieldsStayAtSizeHint",
        "ExpandingFieldsGrow",
        "AllNonFixedFieldsGrow",
        "DontWrapRows",
        "WrapLongRows",
        "WrapAllRows",
        "ItemRole",
        "LabelRole",
        "FieldRole",
        "SpanningRole"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'fieldGrowthPolicy'
        QtMocHelpers::PropertyData<FieldGrowthPolicy>(1, 0x80000000 | 2, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'rowWrapPolicy'
        QtMocHelpers::PropertyData<RowWrapPolicy>(3, 0x80000000 | 4, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'labelAlignment'
        QtMocHelpers::PropertyData<Qt::Alignment>(5, 0x80000000 | 6, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'formAlignment'
        QtMocHelpers::PropertyData<Qt::Alignment>(7, 0x80000000 | 6, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'horizontalSpacing'
        QtMocHelpers::PropertyData<int>(8, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'verticalSpacing'
        QtMocHelpers::PropertyData<int>(9, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'FieldGrowthPolicy'
        QtMocHelpers::EnumData<FieldGrowthPolicy>(2, 2, QMC::EnumFlags{}).add({
            {   10, FieldGrowthPolicy::FieldsStayAtSizeHint },
            {   11, FieldGrowthPolicy::ExpandingFieldsGrow },
            {   12, FieldGrowthPolicy::AllNonFixedFieldsGrow },
        }),
        // enum 'RowWrapPolicy'
        QtMocHelpers::EnumData<RowWrapPolicy>(4, 4, QMC::EnumFlags{}).add({
            {   13, RowWrapPolicy::DontWrapRows },
            {   14, RowWrapPolicy::WrapLongRows },
            {   15, RowWrapPolicy::WrapAllRows },
        }),
        // enum 'ItemRole'
        QtMocHelpers::EnumData<ItemRole>(16, 16, QMC::EnumFlags{}).add({
            {   17, ItemRole::LabelRole },
            {   18, ItemRole::FieldRole },
            {   19, ItemRole::SpanningRole },
        }),
    };
    return QtMocHelpers::metaObjectData<QFormLayout, qt_meta_tag_ZN11QFormLayoutE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QFormLayout::staticMetaObject = { {
    QMetaObject::SuperData::link<QLayout::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QFormLayoutE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QFormLayoutE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11QFormLayoutE_t>.metaTypes,
    nullptr
} };

void QFormLayout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QFormLayout *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<FieldGrowthPolicy*>(_v) = _t->fieldGrowthPolicy(); break;
        case 1: *reinterpret_cast<RowWrapPolicy*>(_v) = _t->rowWrapPolicy(); break;
        case 2: *reinterpret_cast<Qt::Alignment*>(_v) = _t->labelAlignment(); break;
        case 3: *reinterpret_cast<Qt::Alignment*>(_v) = _t->formAlignment(); break;
        case 4: *reinterpret_cast<int*>(_v) = _t->horizontalSpacing(); break;
        case 5: *reinterpret_cast<int*>(_v) = _t->verticalSpacing(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFieldGrowthPolicy(*reinterpret_cast<FieldGrowthPolicy*>(_v)); break;
        case 1: _t->setRowWrapPolicy(*reinterpret_cast<RowWrapPolicy*>(_v)); break;
        case 2: _t->setLabelAlignment(*reinterpret_cast<Qt::Alignment*>(_v)); break;
        case 3: _t->setFormAlignment(*reinterpret_cast<Qt::Alignment*>(_v)); break;
        case 4: _t->setHorizontalSpacing(*reinterpret_cast<int*>(_v)); break;
        case 5: _t->setVerticalSpacing(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 0: _t->resetFieldGrowthPolicy(); break;
        case 1: _t->resetRowWrapPolicy(); break;
        case 2: _t->resetLabelAlignment(); break;
        case 3: _t->resetFormAlignment(); break;
        default: break;
        }
    }
}

const QMetaObject *QFormLayout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QFormLayout::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QFormLayoutE_t>.strings))
        return static_cast<void*>(this);
    return QLayout::qt_metacast(_clname);
}

int QFormLayout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLayout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP

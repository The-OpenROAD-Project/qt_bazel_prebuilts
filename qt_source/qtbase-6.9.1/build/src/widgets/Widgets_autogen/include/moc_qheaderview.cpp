/****************************************************************************
** Meta object code from reading C++ file 'qheaderview.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/itemviews/qheaderview.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qheaderview.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11QHeaderViewE_t {};
} // unnamed namespace

template <> constexpr inline auto QHeaderView::qt_create_metaobjectdata<qt_meta_tag_ZN11QHeaderViewE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QHeaderView",
        "sectionMoved",
        "",
        "logicalIndex",
        "oldVisualIndex",
        "newVisualIndex",
        "sectionResized",
        "oldSize",
        "newSize",
        "sectionPressed",
        "sectionClicked",
        "sectionEntered",
        "sectionDoubleClicked",
        "sectionCountChanged",
        "oldCount",
        "newCount",
        "sectionHandleDoubleClicked",
        "geometriesChanged",
        "sortIndicatorChanged",
        "Qt::SortOrder",
        "order",
        "sortIndicatorClearableChanged",
        "clearable",
        "setOffset",
        "offset",
        "setOffsetToSectionPosition",
        "visualIndex",
        "setOffsetToLastSection",
        "headerDataChanged",
        "Qt::Orientation",
        "orientation",
        "logicalFirst",
        "logicalLast",
        "updateSection",
        "resizeSections",
        "sectionsInserted",
        "QModelIndex",
        "parent",
        "sectionsAboutToBeRemoved",
        "firstSectionMovable",
        "showSortIndicator",
        "sectionsMovable",
        "sectionsClickable",
        "highlightSections",
        "stretchLastSection",
        "cascadingSectionResizes",
        "defaultSectionSize",
        "minimumSectionSize",
        "maximumSectionSize",
        "defaultAlignment",
        "Qt::Alignment",
        "sortIndicatorClearable",
        "ResizeMode",
        "Interactive",
        "Stretch",
        "Fixed",
        "ResizeToContents",
        "Custom"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'sectionMoved'
        QtMocHelpers::SignalData<void(int, int, int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 }, { QMetaType::Int, 4 }, { QMetaType::Int, 5 },
        }}),
        // Signal 'sectionResized'
        QtMocHelpers::SignalData<void(int, int, int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 }, { QMetaType::Int, 7 }, { QMetaType::Int, 8 },
        }}),
        // Signal 'sectionPressed'
        QtMocHelpers::SignalData<void(int)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'sectionClicked'
        QtMocHelpers::SignalData<void(int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'sectionEntered'
        QtMocHelpers::SignalData<void(int)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'sectionDoubleClicked'
        QtMocHelpers::SignalData<void(int)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'sectionCountChanged'
        QtMocHelpers::SignalData<void(int, int)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 }, { QMetaType::Int, 15 },
        }}),
        // Signal 'sectionHandleDoubleClicked'
        QtMocHelpers::SignalData<void(int)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'geometriesChanged'
        QtMocHelpers::SignalData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'sortIndicatorChanged'
        QtMocHelpers::SignalData<void(int, Qt::SortOrder)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 }, { 0x80000000 | 19, 20 },
        }}),
        // Signal 'sortIndicatorClearableChanged'
        QtMocHelpers::SignalData<void(bool)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 22 },
        }}),
        // Slot 'setOffset'
        QtMocHelpers::SlotData<void(int)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 24 },
        }}),
        // Slot 'setOffsetToSectionPosition'
        QtMocHelpers::SlotData<void(int)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 26 },
        }}),
        // Slot 'setOffsetToLastSection'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'headerDataChanged'
        QtMocHelpers::SlotData<void(Qt::Orientation, int, int)>(28, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 29, 30 }, { QMetaType::Int, 31 }, { QMetaType::Int, 32 },
        }}),
        // Slot 'updateSection'
        QtMocHelpers::SlotData<void(int)>(33, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'resizeSections'
        QtMocHelpers::SlotData<void()>(34, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot 'sectionsInserted'
        QtMocHelpers::SlotData<void(const QModelIndex &, int, int)>(35, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 36, 37 }, { QMetaType::Int, 31 }, { QMetaType::Int, 32 },
        }}),
        // Slot 'sectionsAboutToBeRemoved'
        QtMocHelpers::SlotData<void(const QModelIndex &, int, int)>(38, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 36, 37 }, { QMetaType::Int, 31 }, { QMetaType::Int, 32 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'firstSectionMovable'
        QtMocHelpers::PropertyData<bool>(39, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'showSortIndicator'
        QtMocHelpers::PropertyData<bool>(40, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'sectionsMovable'
        QtMocHelpers::PropertyData<bool>(41, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'sectionsClickable'
        QtMocHelpers::PropertyData<bool>(42, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'highlightSections'
        QtMocHelpers::PropertyData<bool>(43, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'stretchLastSection'
        QtMocHelpers::PropertyData<bool>(44, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'cascadingSectionResizes'
        QtMocHelpers::PropertyData<bool>(45, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'defaultSectionSize'
        QtMocHelpers::PropertyData<int>(46, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet),
        // property 'minimumSectionSize'
        QtMocHelpers::PropertyData<int>(47, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'maximumSectionSize'
        QtMocHelpers::PropertyData<int>(48, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'defaultAlignment'
        QtMocHelpers::PropertyData<Qt::Alignment>(49, 0x80000000 | 50, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'sortIndicatorClearable'
        QtMocHelpers::PropertyData<bool>(51, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 10),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ResizeMode'
        QtMocHelpers::EnumData<ResizeMode>(52, 52, QMC::EnumFlags{}).add({
            {   53, ResizeMode::Interactive },
            {   54, ResizeMode::Stretch },
            {   55, ResizeMode::Fixed },
            {   56, ResizeMode::ResizeToContents },
            {   57, ResizeMode::Custom },
        }),
    };
    return QtMocHelpers::metaObjectData<QHeaderView, qt_meta_tag_ZN11QHeaderViewE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QHeaderView::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractItemView::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QHeaderViewE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QHeaderViewE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11QHeaderViewE_t>.metaTypes,
    nullptr
} };

void QHeaderView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QHeaderView *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->sectionMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 1: _t->sectionResized((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 2: _t->sectionPressed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->sectionClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->sectionEntered((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->sectionDoubleClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->sectionCountChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 7: _t->sectionHandleDoubleClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->geometriesChanged(); break;
        case 9: _t->sortIndicatorChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::SortOrder>>(_a[2]))); break;
        case 10: _t->sortIndicatorClearableChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 11: _t->setOffset((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->setOffsetToSectionPosition((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->setOffsetToLastSection(); break;
        case 14: _t->headerDataChanged((*reinterpret_cast< std::add_pointer_t<Qt::Orientation>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 15: _t->updateSection((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->resizeSections(); break;
        case 17: _t->sectionsInserted((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 18: _t->sectionsAboutToBeRemoved((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QHeaderView::*)(int , int , int )>(_a, &QHeaderView::sectionMoved, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHeaderView::*)(int , int , int )>(_a, &QHeaderView::sectionResized, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHeaderView::*)(int )>(_a, &QHeaderView::sectionPressed, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHeaderView::*)(int )>(_a, &QHeaderView::sectionClicked, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHeaderView::*)(int )>(_a, &QHeaderView::sectionEntered, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHeaderView::*)(int )>(_a, &QHeaderView::sectionDoubleClicked, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHeaderView::*)(int , int )>(_a, &QHeaderView::sectionCountChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHeaderView::*)(int )>(_a, &QHeaderView::sectionHandleDoubleClicked, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHeaderView::*)()>(_a, &QHeaderView::geometriesChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHeaderView::*)(int , Qt::SortOrder )>(_a, &QHeaderView::sortIndicatorChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHeaderView::*)(bool )>(_a, &QHeaderView::sortIndicatorClearableChanged, 10))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isFirstSectionMovable(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->isSortIndicatorShown(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->sectionsMovable(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->sectionsClickable(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->highlightSections(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->stretchLastSection(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->cascadingSectionResizes(); break;
        case 7: *reinterpret_cast<int*>(_v) = _t->defaultSectionSize(); break;
        case 8: *reinterpret_cast<int*>(_v) = _t->minimumSectionSize(); break;
        case 9: *reinterpret_cast<int*>(_v) = _t->maximumSectionSize(); break;
        case 10: *reinterpret_cast<Qt::Alignment*>(_v) = _t->defaultAlignment(); break;
        case 11: *reinterpret_cast<bool*>(_v) = _t->isSortIndicatorClearable(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFirstSectionMovable(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setSortIndicatorShown(*reinterpret_cast<bool*>(_v)); break;
        case 2: _t->setSectionsMovable(*reinterpret_cast<bool*>(_v)); break;
        case 3: _t->setSectionsClickable(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setHighlightSections(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setStretchLastSection(*reinterpret_cast<bool*>(_v)); break;
        case 6: _t->setCascadingSectionResizes(*reinterpret_cast<bool*>(_v)); break;
        case 7: _t->setDefaultSectionSize(*reinterpret_cast<int*>(_v)); break;
        case 8: _t->setMinimumSectionSize(*reinterpret_cast<int*>(_v)); break;
        case 9: _t->setMaximumSectionSize(*reinterpret_cast<int*>(_v)); break;
        case 10: _t->setDefaultAlignment(*reinterpret_cast<Qt::Alignment*>(_v)); break;
        case 11: _t->setSortIndicatorClearable(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 7: _t->resetDefaultSectionSize(); break;
        default: break;
        }
    }
}

const QMetaObject *QHeaderView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QHeaderView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QHeaderViewE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractItemView::qt_metacast(_clname);
}

int QHeaderView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
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
void QHeaderView::sectionMoved(int _t1, int _t2, int _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2, _t3);
}

// SIGNAL 1
void QHeaderView::sectionResized(int _t1, int _t2, int _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2, _t3);
}

// SIGNAL 2
void QHeaderView::sectionPressed(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QHeaderView::sectionClicked(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QHeaderView::sectionEntered(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QHeaderView::sectionDoubleClicked(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void QHeaderView::sectionCountChanged(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2);
}

// SIGNAL 7
void QHeaderView::sectionHandleDoubleClicked(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void QHeaderView::geometriesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void QHeaderView::sortIndicatorChanged(int _t1, Qt::SortOrder _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1, _t2);
}

// SIGNAL 10
void QHeaderView::sortIndicatorClearableChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1);
}
QT_WARNING_POP

/****************************************************************************
** Meta object code from reading C++ file 'qabstracttextdocumentlayout.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/text/qabstracttextdocumentlayout.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qabstracttextdocumentlayout.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN27QAbstractTextDocumentLayoutE_t {};
} // unnamed namespace

template <> constexpr inline auto QAbstractTextDocumentLayout::qt_create_metaobjectdata<qt_meta_tag_ZN27QAbstractTextDocumentLayoutE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QAbstractTextDocumentLayout",
        "update",
        "",
        "updateBlock",
        "QTextBlock",
        "block",
        "documentSizeChanged",
        "newSize",
        "pageCountChanged",
        "newPages",
        "_q_dynamicPageCountSlot",
        "_q_dynamicDocumentSizeSlot"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'update'
        QtMocHelpers::SignalData<void(const QRectF &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRectF, 2 },
        }}),
        // Signal 'update'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Signal 'updateBlock'
        QtMocHelpers::SignalData<void(const QTextBlock &)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Signal 'documentSizeChanged'
        QtMocHelpers::SignalData<void(const QSizeF &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QSizeF, 7 },
        }}),
        // Signal 'pageCountChanged'
        QtMocHelpers::SignalData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
        // Slot '_q_dynamicPageCountSlot'
        QtMocHelpers::SlotData<int()>(10, 2, QMC::AccessPrivate, QMetaType::Int),
        // Slot '_q_dynamicDocumentSizeSlot'
        QtMocHelpers::SlotData<QSizeF()>(11, 2, QMC::AccessPrivate, QMetaType::QSizeF),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QAbstractTextDocumentLayout, qt_meta_tag_ZN27QAbstractTextDocumentLayoutE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QAbstractTextDocumentLayout::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27QAbstractTextDocumentLayoutE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27QAbstractTextDocumentLayoutE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN27QAbstractTextDocumentLayoutE_t>.metaTypes,
    nullptr
} };

void QAbstractTextDocumentLayout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QAbstractTextDocumentLayout *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->update((*reinterpret_cast< std::add_pointer_t<QRectF>>(_a[1]))); break;
        case 1: _t->update(); break;
        case 2: _t->updateBlock((*reinterpret_cast< std::add_pointer_t<QTextBlock>>(_a[1]))); break;
        case 3: _t->documentSizeChanged((*reinterpret_cast< std::add_pointer_t<QSizeF>>(_a[1]))); break;
        case 4: _t->pageCountChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: { int _r = _t->d_func()->_q_dynamicPageCountSlot();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { QSizeF _r = _t->d_func()->_q_dynamicDocumentSizeSlot();
            if (_a[0]) *reinterpret_cast< QSizeF*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QAbstractTextDocumentLayout::*)(const QRectF & )>(_a, &QAbstractTextDocumentLayout::update, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractTextDocumentLayout::*)(const QTextBlock & )>(_a, &QAbstractTextDocumentLayout::updateBlock, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractTextDocumentLayout::*)(const QSizeF & )>(_a, &QAbstractTextDocumentLayout::documentSizeChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractTextDocumentLayout::*)(int )>(_a, &QAbstractTextDocumentLayout::pageCountChanged, 4))
            return;
    }
}

const QMetaObject *QAbstractTextDocumentLayout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAbstractTextDocumentLayout::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27QAbstractTextDocumentLayoutE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QAbstractTextDocumentLayout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QAbstractTextDocumentLayout::update(const QRectF & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 2
void QAbstractTextDocumentLayout::updateBlock(const QTextBlock & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QAbstractTextDocumentLayout::documentSizeChanged(const QSizeF & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QAbstractTextDocumentLayout::pageCountChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}
QT_WARNING_POP

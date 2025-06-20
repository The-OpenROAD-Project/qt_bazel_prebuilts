/****************************************************************************
** Meta object code from reading C++ file 'qlabel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qlabel.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlabel.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN6QLabelE_t {};
} // unnamed namespace

template <> constexpr inline auto QLabel::qt_create_metaobjectdata<qt_meta_tag_ZN6QLabelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QLabel",
        "linkActivated",
        "",
        "link",
        "linkHovered",
        "setText",
        "setPixmap",
        "setPicture",
        "QPicture",
        "setMovie",
        "QMovie*",
        "movie",
        "setNum",
        "clear",
        "text",
        "textFormat",
        "Qt::TextFormat",
        "pixmap",
        "scaledContents",
        "alignment",
        "Qt::Alignment",
        "wordWrap",
        "margin",
        "indent",
        "openExternalLinks",
        "textInteractionFlags",
        "Qt::TextInteractionFlags",
        "hasSelectedText",
        "selectedText"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'linkActivated'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'linkHovered'
        QtMocHelpers::SignalData<void(const QString &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'setText'
        QtMocHelpers::SlotData<void(const QString &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Slot 'setPixmap'
        QtMocHelpers::SlotData<void(const QPixmap &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPixmap, 2 },
        }}),
        // Slot 'setPicture'
        QtMocHelpers::SlotData<void(const QPicture &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 2 },
        }}),
        // Slot 'setMovie'
        QtMocHelpers::SlotData<void(QMovie *)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 11 },
        }}),
        // Slot 'setNum'
        QtMocHelpers::SlotData<void(int)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Slot 'setNum'
        QtMocHelpers::SlotData<void(double)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 2 },
        }}),
        // Slot 'clear'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'text'
        QtMocHelpers::PropertyData<QString>(14, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'textFormat'
        QtMocHelpers::PropertyData<Qt::TextFormat>(15, 0x80000000 | 16, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'pixmap'
        QtMocHelpers::PropertyData<QPixmap>(17, QMetaType::QPixmap, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'scaledContents'
        QtMocHelpers::PropertyData<bool>(18, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'alignment'
        QtMocHelpers::PropertyData<Qt::Alignment>(19, 0x80000000 | 20, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'wordWrap'
        QtMocHelpers::PropertyData<bool>(21, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'margin'
        QtMocHelpers::PropertyData<int>(22, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'indent'
        QtMocHelpers::PropertyData<int>(23, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'openExternalLinks'
        QtMocHelpers::PropertyData<bool>(24, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'textInteractionFlags'
        QtMocHelpers::PropertyData<Qt::TextInteractionFlags>(25, 0x80000000 | 26, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'hasSelectedText'
        QtMocHelpers::PropertyData<bool>(27, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'selectedText'
        QtMocHelpers::PropertyData<QString>(28, QMetaType::QString, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QLabel, qt_meta_tag_ZN6QLabelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QLabel::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6QLabelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6QLabelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN6QLabelE_t>.metaTypes,
    nullptr
} };

void QLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QLabel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->linkActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->linkHovered((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->setText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->setPixmap((*reinterpret_cast< std::add_pointer_t<QPixmap>>(_a[1]))); break;
        case 4: _t->setPicture((*reinterpret_cast< std::add_pointer_t<QPicture>>(_a[1]))); break;
        case 5: _t->setMovie((*reinterpret_cast< std::add_pointer_t<QMovie*>>(_a[1]))); break;
        case 6: _t->setNum((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->setNum((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 8: _t->clear(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QLabel::*)(const QString & )>(_a, &QLabel::linkActivated, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QLabel::*)(const QString & )>(_a, &QLabel::linkHovered, 1))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->text(); break;
        case 1: *reinterpret_cast<Qt::TextFormat*>(_v) = _t->textFormat(); break;
        case 2: *reinterpret_cast<QPixmap*>(_v) = _t->pixmap(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->hasScaledContents(); break;
        case 4: *reinterpret_cast<Qt::Alignment*>(_v) = _t->alignment(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->wordWrap(); break;
        case 6: *reinterpret_cast<int*>(_v) = _t->margin(); break;
        case 7: *reinterpret_cast<int*>(_v) = _t->indent(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->openExternalLinks(); break;
        case 9: *reinterpret_cast<Qt::TextInteractionFlags*>(_v) = _t->textInteractionFlags(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->hasSelectedText(); break;
        case 11: *reinterpret_cast<QString*>(_v) = _t->selectedText(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setText(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setTextFormat(*reinterpret_cast<Qt::TextFormat*>(_v)); break;
        case 2: _t->setPixmap(*reinterpret_cast<QPixmap*>(_v)); break;
        case 3: _t->setScaledContents(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setAlignment(*reinterpret_cast<Qt::Alignment*>(_v)); break;
        case 5: _t->setWordWrap(*reinterpret_cast<bool*>(_v)); break;
        case 6: _t->setMargin(*reinterpret_cast<int*>(_v)); break;
        case 7: _t->setIndent(*reinterpret_cast<int*>(_v)); break;
        case 8: _t->setOpenExternalLinks(*reinterpret_cast<bool*>(_v)); break;
        case 9: _t->setTextInteractionFlags(*reinterpret_cast<Qt::TextInteractionFlags*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6QLabelE_t>.strings))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int QLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
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
void QLabel::linkActivated(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QLabel::linkHovered(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP

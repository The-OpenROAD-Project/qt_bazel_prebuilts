/****************************************************************************
** Meta object code from reading C++ file 'qgraphicswidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/graphicsview/qgraphicswidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgraphicswidget.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15QGraphicsWidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto QGraphicsWidget::qt_create_metaobjectdata<qt_meta_tag_ZN15QGraphicsWidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QGraphicsWidget",
        "geometryChanged",
        "",
        "layoutChanged",
        "close",
        "palette",
        "font",
        "layoutDirection",
        "Qt::LayoutDirection",
        "size",
        "minimumSize",
        "preferredSize",
        "maximumSize",
        "sizePolicy",
        "focusPolicy",
        "Qt::FocusPolicy",
        "windowFlags",
        "Qt::WindowFlags",
        "windowTitle",
        "geometry",
        "autoFillBackground",
        "layout",
        "QGraphicsLayout*"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'geometryChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'layoutChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'close'
        QtMocHelpers::SlotData<bool()>(4, 2, QMC::AccessPublic, QMetaType::Bool),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'palette'
        QtMocHelpers::PropertyData<QPalette>(5, QMetaType::QPalette, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'font'
        QtMocHelpers::PropertyData<QFont>(6, QMetaType::QFont, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'layoutDirection'
        QtMocHelpers::PropertyData<Qt::LayoutDirection>(7, 0x80000000 | 8, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'size'
        QtMocHelpers::PropertyData<QSizeF>(9, QMetaType::QSizeF, QMC::DefaultPropertyFlags | QMC::Writable, 0),
        // property 'minimumSize'
        QtMocHelpers::PropertyData<QSizeF>(10, QMetaType::QSizeF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'preferredSize'
        QtMocHelpers::PropertyData<QSizeF>(11, QMetaType::QSizeF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'maximumSize'
        QtMocHelpers::PropertyData<QSizeF>(12, QMetaType::QSizeF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'sizePolicy'
        QtMocHelpers::PropertyData<QSizePolicy>(13, QMetaType::QSizePolicy, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'focusPolicy'
        QtMocHelpers::PropertyData<Qt::FocusPolicy>(14, 0x80000000 | 15, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'windowFlags'
        QtMocHelpers::PropertyData<Qt::WindowFlags>(16, 0x80000000 | 17, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'windowTitle'
        QtMocHelpers::PropertyData<QString>(18, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'geometry'
        QtMocHelpers::PropertyData<QRectF>(19, QMetaType::QRectF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'autoFillBackground'
        QtMocHelpers::PropertyData<bool>(20, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'layout'
        QtMocHelpers::PropertyData<QGraphicsLayout*>(21, 0x80000000 | 22, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 1),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QGraphicsWidget, qt_meta_tag_ZN15QGraphicsWidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QGraphicsWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QGraphicsWidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QGraphicsWidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15QGraphicsWidgetE_t>.metaTypes,
    nullptr
} };

void QGraphicsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QGraphicsWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->geometryChanged(); break;
        case 1: _t->layoutChanged(); break;
        case 2: { bool _r = _t->close();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QGraphicsWidget::*)()>(_a, &QGraphicsWidget::geometryChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsWidget::*)()>(_a, &QGraphicsWidget::layoutChanged, 1))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QPalette*>(_v) = _t->palette(); break;
        case 1: *reinterpret_cast<QFont*>(_v) = _t->font(); break;
        case 2: *reinterpret_cast<Qt::LayoutDirection*>(_v) = _t->layoutDirection(); break;
        case 3: *reinterpret_cast<QSizeF*>(_v) = _t->size(); break;
        case 4: *reinterpret_cast<QSizeF*>(_v) = _t->minimumSize(); break;
        case 5: *reinterpret_cast<QSizeF*>(_v) = _t->preferredSize(); break;
        case 6: *reinterpret_cast<QSizeF*>(_v) = _t->maximumSize(); break;
        case 7: *reinterpret_cast<QSizePolicy*>(_v) = _t->sizePolicy(); break;
        case 8: *reinterpret_cast<Qt::FocusPolicy*>(_v) = _t->focusPolicy(); break;
        case 9: *reinterpret_cast<Qt::WindowFlags*>(_v) = _t->windowFlags(); break;
        case 10: *reinterpret_cast<QString*>(_v) = _t->windowTitle(); break;
        case 11: *reinterpret_cast<QRectF*>(_v) = _t->geometry(); break;
        case 12: *reinterpret_cast<bool*>(_v) = _t->autoFillBackground(); break;
        case 13: *reinterpret_cast<QGraphicsLayout**>(_v) = _t->layout(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPalette(*reinterpret_cast<QPalette*>(_v)); break;
        case 1: _t->setFont(*reinterpret_cast<QFont*>(_v)); break;
        case 2: _t->setLayoutDirection(*reinterpret_cast<Qt::LayoutDirection*>(_v)); break;
        case 3: _t->resize(*reinterpret_cast<QSizeF*>(_v)); break;
        case 4: _t->setMinimumSize(*reinterpret_cast<QSizeF*>(_v)); break;
        case 5: _t->setPreferredSize(*reinterpret_cast<QSizeF*>(_v)); break;
        case 6: _t->setMaximumSize(*reinterpret_cast<QSizeF*>(_v)); break;
        case 7: _t->setSizePolicy(*reinterpret_cast<QSizePolicy*>(_v)); break;
        case 8: _t->setFocusPolicy(*reinterpret_cast<Qt::FocusPolicy*>(_v)); break;
        case 9: _t->setWindowFlags(*reinterpret_cast<Qt::WindowFlags*>(_v)); break;
        case 10: _t->setWindowTitle(*reinterpret_cast<QString*>(_v)); break;
        case 11: _t->setGeometry(*reinterpret_cast<QRectF*>(_v)); break;
        case 12: _t->setAutoFillBackground(*reinterpret_cast<bool*>(_v)); break;
        case 13: _t->setLayout(*reinterpret_cast<QGraphicsLayout**>(_v)); break;
        default: break;
        }
    }
if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 2: _t->unsetLayoutDirection(); break;
        default: break;
        }
    }
}

const QMetaObject *QGraphicsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphicsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QGraphicsWidgetE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsLayoutItem"))
        return static_cast< QGraphicsLayoutItem*>(this);
    if (!strcmp(_clname, "org.qt-project.Qt.QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    if (!strcmp(_clname, "org.qt-project.Qt.QGraphicsLayoutItem"))
        return static_cast< QGraphicsLayoutItem*>(this);
    return QGraphicsObject::qt_metacast(_clname);
}

int QGraphicsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void QGraphicsWidget::geometryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QGraphicsWidget::layoutChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP

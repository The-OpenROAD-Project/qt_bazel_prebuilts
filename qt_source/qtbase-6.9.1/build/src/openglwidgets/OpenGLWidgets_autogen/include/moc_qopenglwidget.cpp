/****************************************************************************
** Meta object code from reading C++ file 'qopenglwidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/openglwidgets/qopenglwidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qopenglwidget.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13QOpenGLWidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto QOpenGLWidget::qt_create_metaobjectdata<qt_meta_tag_ZN13QOpenGLWidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QOpenGLWidget",
        "aboutToCompose",
        "",
        "frameSwapped",
        "aboutToResize",
        "resized",
        "UpdateBehavior",
        "NoPartialUpdate",
        "PartialUpdate",
        "TargetBuffer",
        "LeftBuffer",
        "RightBuffer"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'aboutToCompose'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'frameSwapped'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'aboutToResize'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'resized'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'UpdateBehavior'
        QtMocHelpers::EnumData<UpdateBehavior>(6, 6, QMC::EnumFlags{}).add({
            {    7, UpdateBehavior::NoPartialUpdate },
            {    8, UpdateBehavior::PartialUpdate },
        }),
        // enum 'TargetBuffer'
        QtMocHelpers::EnumData<TargetBuffer>(9, 9, QMC::EnumFlags{}).add({
            {   10, TargetBuffer::LeftBuffer },
            {   11, TargetBuffer::RightBuffer },
        }),
    };
    return QtMocHelpers::metaObjectData<QOpenGLWidget, qt_meta_tag_ZN13QOpenGLWidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QOpenGLWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QOpenGLWidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QOpenGLWidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13QOpenGLWidgetE_t>.metaTypes,
    nullptr
} };

void QOpenGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QOpenGLWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->aboutToCompose(); break;
        case 1: _t->frameSwapped(); break;
        case 2: _t->aboutToResize(); break;
        case 3: _t->resized(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QOpenGLWidget::*)()>(_a, &QOpenGLWidget::aboutToCompose, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QOpenGLWidget::*)()>(_a, &QOpenGLWidget::frameSwapped, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QOpenGLWidget::*)()>(_a, &QOpenGLWidget::aboutToResize, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QOpenGLWidget::*)()>(_a, &QOpenGLWidget::resized, 3))
            return;
    }
}

const QMetaObject *QOpenGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QOpenGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QOpenGLWidgetE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QOpenGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QOpenGLWidget::aboutToCompose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QOpenGLWidget::frameSwapped()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QOpenGLWidget::aboutToResize()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QOpenGLWidget::resized()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP

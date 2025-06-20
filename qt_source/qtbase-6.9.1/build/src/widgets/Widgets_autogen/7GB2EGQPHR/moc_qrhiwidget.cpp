/****************************************************************************
** Meta object code from reading C++ file 'qrhiwidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/kernel/qrhiwidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qrhiwidget.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10QRhiWidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto QRhiWidget::qt_create_metaobjectdata<qt_meta_tag_ZN10QRhiWidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QRhiWidget",
        "frameSubmitted",
        "",
        "renderFailed",
        "sampleCountChanged",
        "samples",
        "colorBufferFormatChanged",
        "TextureFormat",
        "format",
        "fixedColorBufferSizeChanged",
        "pixelSize",
        "mirrorVerticallyChanged",
        "enabled",
        "sampleCount",
        "colorBufferFormat",
        "fixedColorBufferSize",
        "mirrorVertically",
        "Api",
        "Null",
        "OpenGL",
        "Metal",
        "Vulkan",
        "Direct3D11",
        "Direct3D12",
        "RGBA8",
        "RGBA16F",
        "RGBA32F",
        "RGB10A2"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'frameSubmitted'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'renderFailed'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'sampleCountChanged'
        QtMocHelpers::SignalData<void(int)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 5 },
        }}),
        // Signal 'colorBufferFormatChanged'
        QtMocHelpers::SignalData<void(TextureFormat)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 },
        }}),
        // Signal 'fixedColorBufferSizeChanged'
        QtMocHelpers::SignalData<void(const QSize &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QSize, 10 },
        }}),
        // Signal 'mirrorVerticallyChanged'
        QtMocHelpers::SignalData<void(bool)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 12 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'sampleCount'
        QtMocHelpers::PropertyData<int>(13, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'colorBufferFormat'
        QtMocHelpers::PropertyData<TextureFormat>(14, 0x80000000 | 7, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 3),
        // property 'fixedColorBufferSize'
        QtMocHelpers::PropertyData<QSize>(15, QMetaType::QSize, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'mirrorVertically'
        QtMocHelpers::PropertyData<bool>(16, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Api'
        QtMocHelpers::EnumData<Api>(17, 17, QMC::EnumIsScoped).add({
            {   18, Api::Null },
            {   19, Api::OpenGL },
            {   20, Api::Metal },
            {   21, Api::Vulkan },
            {   22, Api::Direct3D11 },
            {   23, Api::Direct3D12 },
        }),
        // enum 'TextureFormat'
        QtMocHelpers::EnumData<TextureFormat>(7, 7, QMC::EnumIsScoped).add({
            {   24, TextureFormat::RGBA8 },
            {   25, TextureFormat::RGBA16F },
            {   26, TextureFormat::RGBA32F },
            {   27, TextureFormat::RGB10A2 },
        }),
    };
    return QtMocHelpers::metaObjectData<QRhiWidget, qt_meta_tag_ZN10QRhiWidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QRhiWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QRhiWidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QRhiWidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10QRhiWidgetE_t>.metaTypes,
    nullptr
} };

void QRhiWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QRhiWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->frameSubmitted(); break;
        case 1: _t->renderFailed(); break;
        case 2: _t->sampleCountChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->colorBufferFormatChanged((*reinterpret_cast< std::add_pointer_t<TextureFormat>>(_a[1]))); break;
        case 4: _t->fixedColorBufferSizeChanged((*reinterpret_cast< std::add_pointer_t<QSize>>(_a[1]))); break;
        case 5: _t->mirrorVerticallyChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QRhiWidget::*)()>(_a, &QRhiWidget::frameSubmitted, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QRhiWidget::*)()>(_a, &QRhiWidget::renderFailed, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QRhiWidget::*)(int )>(_a, &QRhiWidget::sampleCountChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QRhiWidget::*)(TextureFormat )>(_a, &QRhiWidget::colorBufferFormatChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QRhiWidget::*)(const QSize & )>(_a, &QRhiWidget::fixedColorBufferSizeChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QRhiWidget::*)(bool )>(_a, &QRhiWidget::mirrorVerticallyChanged, 5))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->sampleCount(); break;
        case 1: *reinterpret_cast<TextureFormat*>(_v) = _t->colorBufferFormat(); break;
        case 2: *reinterpret_cast<QSize*>(_v) = _t->fixedColorBufferSize(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->isMirrorVerticallyEnabled(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSampleCount(*reinterpret_cast<int*>(_v)); break;
        case 1: _t->setColorBufferFormat(*reinterpret_cast<TextureFormat*>(_v)); break;
        case 2: _t->setFixedColorBufferSize(*reinterpret_cast<QSize*>(_v)); break;
        case 3: _t->setMirrorVertically(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QRhiWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QRhiWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QRhiWidgetE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QRhiWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
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
void QRhiWidget::frameSubmitted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QRhiWidget::renderFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QRhiWidget::sampleCountChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QRhiWidget::colorBufferFormatChanged(TextureFormat _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QRhiWidget::fixedColorBufferSizeChanged(const QSize & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QRhiWidget::mirrorVerticallyChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}
QT_WARNING_POP

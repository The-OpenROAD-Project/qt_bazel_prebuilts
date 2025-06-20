/****************************************************************************
** Meta object code from reading C++ file 'qsurfaceformat.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qsurfaceformat.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsurfaceformat.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14QSurfaceFormatE_t {};
} // unnamed namespace

template <> constexpr inline auto QSurfaceFormat::qt_create_metaobjectdata<qt_meta_tag_ZN14QSurfaceFormatE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSurfaceFormat",
        "FormatOption",
        "StereoBuffers",
        "DebugContext",
        "DeprecatedFunctions",
        "ResetNotification",
        "ProtectedContent",
        "SwapBehavior",
        "DefaultSwapBehavior",
        "SingleBuffer",
        "DoubleBuffer",
        "TripleBuffer",
        "RenderableType",
        "DefaultRenderableType",
        "OpenGL",
        "OpenGLES",
        "OpenVG",
        "OpenGLContextProfile",
        "NoProfile",
        "CoreProfile",
        "CompatibilityProfile",
        "ColorSpace",
        "DefaultColorSpace",
        "sRGBColorSpace"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'FormatOption'
        QtMocHelpers::EnumData<FormatOption>(1, 1, QMC::EnumFlags{}).add({
            {    2, FormatOption::StereoBuffers },
            {    3, FormatOption::DebugContext },
            {    4, FormatOption::DeprecatedFunctions },
            {    5, FormatOption::ResetNotification },
            {    6, FormatOption::ProtectedContent },
        }),
        // enum 'SwapBehavior'
        QtMocHelpers::EnumData<SwapBehavior>(7, 7, QMC::EnumFlags{}).add({
            {    8, SwapBehavior::DefaultSwapBehavior },
            {    9, SwapBehavior::SingleBuffer },
            {   10, SwapBehavior::DoubleBuffer },
            {   11, SwapBehavior::TripleBuffer },
        }),
        // enum 'RenderableType'
        QtMocHelpers::EnumData<RenderableType>(12, 12, QMC::EnumFlags{}).add({
            {   13, RenderableType::DefaultRenderableType },
            {   14, RenderableType::OpenGL },
            {   15, RenderableType::OpenGLES },
            {   16, RenderableType::OpenVG },
        }),
        // enum 'OpenGLContextProfile'
        QtMocHelpers::EnumData<OpenGLContextProfile>(17, 17, QMC::EnumFlags{}).add({
            {   18, OpenGLContextProfile::NoProfile },
            {   19, OpenGLContextProfile::CoreProfile },
            {   20, OpenGLContextProfile::CompatibilityProfile },
        }),
        // enum 'ColorSpace'
        QtMocHelpers::EnumData<ColorSpace>(21, 21, QMC::EnumFlags{}).add({
            {   22, ColorSpace::DefaultColorSpace },
            {   23, ColorSpace::sRGBColorSpace },
        }),
    };
    return QtMocHelpers::metaObjectData<QSurfaceFormat, qt_meta_tag_ZN14QSurfaceFormatE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSurfaceFormat::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QSurfaceFormatE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QSurfaceFormatE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14QSurfaceFormatE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP

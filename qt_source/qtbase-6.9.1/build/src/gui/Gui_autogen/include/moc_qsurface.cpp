/****************************************************************************
** Meta object code from reading C++ file 'qsurface.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qsurface.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsurface.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN8QSurfaceE_t {};
} // unnamed namespace

template <> constexpr inline auto QSurface::qt_create_metaobjectdata<qt_meta_tag_ZN8QSurfaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSurface",
        "SurfaceClass",
        "Window",
        "Offscreen",
        "SurfaceType",
        "RasterSurface",
        "OpenGLSurface",
        "RasterGLSurface",
        "OpenVGSurface",
        "VulkanSurface",
        "MetalSurface",
        "Direct3DSurface"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'SurfaceClass'
        QtMocHelpers::EnumData<SurfaceClass>(1, 1, QMC::EnumFlags{}).add({
            {    2, SurfaceClass::Window },
            {    3, SurfaceClass::Offscreen },
        }),
        // enum 'SurfaceType'
        QtMocHelpers::EnumData<SurfaceType>(4, 4, QMC::EnumFlags{}).add({
            {    5, SurfaceType::RasterSurface },
            {    6, SurfaceType::OpenGLSurface },
            {    7, SurfaceType::RasterGLSurface },
            {    8, SurfaceType::OpenVGSurface },
            {    9, SurfaceType::VulkanSurface },
            {   10, SurfaceType::MetalSurface },
            {   11, SurfaceType::Direct3DSurface },
        }),
    };
    return QtMocHelpers::metaObjectData<QSurface, qt_meta_tag_ZN8QSurfaceE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSurface::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QSurfaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QSurfaceE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8QSurfaceE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP

/****************************************************************************
** Meta object code from reading C++ file 'qtlsbackend_cert_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/tls/certonly/qtlsbackend_cert_p.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtlsbackend_cert_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN19QTlsBackendCertOnlyE_t {};
} // unnamed namespace

template <> constexpr inline auto QTlsBackendCertOnly::qt_create_metaobjectdata<qt_meta_tag_ZN19QTlsBackendCertOnlyE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QTlsBackendCertOnly"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QTlsBackendCertOnly, qt_meta_tag_ZN19QTlsBackendCertOnlyE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QTlsBackendCertOnly::staticMetaObject = { {
    QMetaObject::SuperData::link<QTlsBackend::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QTlsBackendCertOnlyE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QTlsBackendCertOnlyE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19QTlsBackendCertOnlyE_t>.metaTypes,
    nullptr
} };

void QTlsBackendCertOnly::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QTlsBackendCertOnly *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QTlsBackendCertOnly::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTlsBackendCertOnly::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QTlsBackendCertOnlyE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "org.qt-project.Qt.QTlsBackend"))
        return static_cast< QTlsBackend*>(this);
    return QTlsBackend::qt_metacast(_clname);
}

int QTlsBackendCertOnly::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTlsBackend::qt_metacall(_c, _id, _a);
    return _id;
}

#ifdef QT_MOC_EXPORT_PLUGIN_V2
static constexpr unsigned char qt_pluginMetaDataV2_QTlsBackendCertOnly[] = {
    0xbf, 
    // "IID"
    0x02,  0x78,  0x1d,  'o',  'r',  'g',  '.',  'q', 
    't',  '-',  'p',  'r',  'o',  'j',  'e',  'c', 
    't',  '.',  'Q',  't',  '.',  'Q',  'T',  'l', 
    's',  'B',  'a',  'c',  'k',  'e',  'n',  'd', 
    // "className"
    0x03,  0x73,  'Q',  'T',  'l',  's',  'B',  'a', 
    'c',  'k',  'e',  'n',  'd',  'C',  'e',  'r', 
    't',  'O',  'n',  'l',  'y', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN_V2(QTlsBackendCertOnly, QTlsBackendCertOnly, qt_pluginMetaDataV2_QTlsBackendCertOnly)
#else
QT_PLUGIN_METADATA_SECTION
Q_CONSTINIT static constexpr unsigned char qt_pluginMetaData_QTlsBackendCertOnly[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x1d,  'o',  'r',  'g',  '.',  'q', 
    't',  '-',  'p',  'r',  'o',  'j',  'e',  'c', 
    't',  '.',  'Q',  't',  '.',  'Q',  'T',  'l', 
    's',  'B',  'a',  'c',  'k',  'e',  'n',  'd', 
    // "className"
    0x03,  0x73,  'Q',  'T',  'l',  's',  'B',  'a', 
    'c',  'k',  'e',  'n',  'd',  'C',  'e',  'r', 
    't',  'O',  'n',  'l',  'y', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(QTlsBackendCertOnly, QTlsBackendCertOnly)
#endif  // QT_MOC_EXPORT_PLUGIN_V2

QT_WARNING_POP

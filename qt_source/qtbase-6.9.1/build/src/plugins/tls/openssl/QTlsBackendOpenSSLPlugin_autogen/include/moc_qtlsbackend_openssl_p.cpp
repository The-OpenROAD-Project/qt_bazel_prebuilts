/****************************************************************************
** Meta object code from reading C++ file 'qtlsbackend_openssl_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/tls/openssl/qtlsbackend_openssl_p.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtlsbackend_openssl_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN18QTlsBackendOpenSSLE_t {};
} // unnamed namespace

template <> constexpr inline auto QTlsBackendOpenSSL::qt_create_metaobjectdata<qt_meta_tag_ZN18QTlsBackendOpenSSLE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QTlsBackendOpenSSL"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QTlsBackendOpenSSL, qt_meta_tag_ZN18QTlsBackendOpenSSLE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QTlsBackendOpenSSL::staticMetaObject = { {
    QMetaObject::SuperData::link<QTlsBackend::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QTlsBackendOpenSSLE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QTlsBackendOpenSSLE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18QTlsBackendOpenSSLE_t>.metaTypes,
    nullptr
} };

void QTlsBackendOpenSSL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QTlsBackendOpenSSL *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QTlsBackendOpenSSL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTlsBackendOpenSSL::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QTlsBackendOpenSSLE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "org.qt-project.Qt.QTlsBackend"))
        return static_cast< QTlsBackend*>(this);
    return QTlsBackend::qt_metacast(_clname);
}

int QTlsBackendOpenSSL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTlsBackend::qt_metacall(_c, _id, _a);
    return _id;
}

#ifdef QT_MOC_EXPORT_PLUGIN_V2
static constexpr unsigned char qt_pluginMetaDataV2_QTlsBackendOpenSSL[] = {
    0xbf, 
    // "IID"
    0x02,  0x78,  0x1d,  'o',  'r',  'g',  '.',  'q', 
    't',  '-',  'p',  'r',  'o',  'j',  'e',  'c', 
    't',  '.',  'Q',  't',  '.',  'Q',  'T',  'l', 
    's',  'B',  'a',  'c',  'k',  'e',  'n',  'd', 
    // "className"
    0x03,  0x72,  'Q',  'T',  'l',  's',  'B',  'a', 
    'c',  'k',  'e',  'n',  'd',  'O',  'p',  'e', 
    'n',  'S',  'S',  'L', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN_V2(QTlsBackendOpenSSL, QTlsBackendOpenSSL, qt_pluginMetaDataV2_QTlsBackendOpenSSL)
#else
QT_PLUGIN_METADATA_SECTION
Q_CONSTINIT static constexpr unsigned char qt_pluginMetaData_QTlsBackendOpenSSL[] = {
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
    0x03,  0x72,  'Q',  'T',  'l',  's',  'B',  'a', 
    'c',  'k',  'e',  'n',  'd',  'O',  'p',  'e', 
    'n',  'S',  'S',  'L', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(QTlsBackendOpenSSL, QTlsBackendOpenSSL)
#endif  // QT_MOC_EXPORT_PLUGIN_V2

QT_WARNING_POP

# Install script for directory: /tmp/qtbase-6.9.1/src/network

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/opt/qt6")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./metatypes" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/network/meta_types/qt6network_release_metatypes.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Network" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Network/Qt6NetworkConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Network/Qt6NetworkConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Network/Qt6NetworkConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6NetworkPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6NetworkPrivate/Qt6NetworkPrivateConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6NetworkPrivate/Qt6NetworkPrivateConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6NetworkPrivate/Qt6NetworkPrivateConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Network.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Network.so.6"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "\$ORIGIN")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/tmp/qtbase-6.9.1/build/lib/libQt6Network.so.6.9.1"
    "/tmp/qtbase-6.9.1/build/lib/libQt6Network.so.6"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Network.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Network.so.6"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/tmp/qtbase-6.9.1/build/lib:"
           NEW_RPATH "\$ORIGIN")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/tmp/qtbase-6.9.1/build/libexec/qt-internal-strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Network.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Network.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Network.so"
         RPATH "\$ORIGIN")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/tmp/qtbase-6.9.1/build/lib/libQt6Network.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Network.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Network.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Network.so"
         OLD_RPATH "/tmp/qtbase-6.9.1/build/lib:"
         NEW_RPATH "\$ORIGIN")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/tmp/qtbase-6.9.1/build/libexec/qt-internal-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Network.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Network/Qt6NetworkTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Network/Qt6NetworkTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/network/CMakeFiles/Export/lib/cmake/Qt6Network/Qt6NetworkTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Network/Qt6NetworkTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Network/Qt6NetworkTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Network" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/network/CMakeFiles/Export/lib/cmake/Qt6Network/Qt6NetworkTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Network" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/network/CMakeFiles/Export/lib/cmake/Qt6Network/Qt6NetworkTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Network" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Network/Qt6NetworkVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Network/Qt6NetworkVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Network" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6NetworkPrivate/Qt6NetworkPrivateTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6NetworkPrivate/Qt6NetworkPrivateTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/network/CMakeFiles/Export/lib/cmake/Qt6NetworkPrivate/Qt6NetworkPrivateTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6NetworkPrivate/Qt6NetworkPrivateTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6NetworkPrivate/Qt6NetworkPrivateTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6NetworkPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/network/CMakeFiles/Export/lib/cmake/Qt6NetworkPrivate/Qt6NetworkPrivateTargets.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6NetworkPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6NetworkPrivate/Qt6NetworkPrivateVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6NetworkPrivate/Qt6NetworkPrivateVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6NetworkPrivate" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modules" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/modules/Network.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_html_docs_Networkx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc/qtnetwork" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/doc/qtnetwork/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_qch_docs_Networkx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/doc/qtnetwork.qch")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Network" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Network/Qt6NetworkAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6NetworkPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6NetworkPrivate/Qt6NetworkPrivateAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtNetwork" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/include/QtNetwork/.syncqt_staging/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtNetwork" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/include/QtNetwork/qtnetworkexports.h"
    "/tmp/qtbase-6.9.1/src/network/access/qabstractnetworkcache.h"
    "/tmp/qtbase-6.9.1/src/network/access/qhstspolicy.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkaccessmanager.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkcookie.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkcookiejar.h"
    "/tmp/qtbase-6.9.1/src/network/access/qhttpheaders.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkreply.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkrequest.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qauthenticator.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qhostaddress.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qhostinfo.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qnetworkdatagram.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qnetworkinformation.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qnetworkinterface.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qnetworkproxy.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qtnetworkglobal.h"
    "/tmp/qtbase-6.9.1/src/network/socket/qabstractsocket.h"
    "/tmp/qtbase-6.9.1/src/network/socket/qtcpserver.h"
    "/tmp/qtbase-6.9.1/src/network/socket/qtcpsocket.h"
    "/tmp/qtbase-6.9.1/src/network/socket/qudpsocket.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qpassworddigestor.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qssl.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qsslcertificate.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qsslcertificateextension.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qsslcipher.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qsslconfiguration.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qsslerror.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qsslkey.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qsslsocket.h"
    "/tmp/qtbase-6.9.1/build/src/network/qtnetwork-config.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkdiskcache.h"
    "/tmp/qtbase-6.9.1/src/network/access/qformdatabuilder.h"
    "/tmp/qtbase-6.9.1/src/network/access/qhttp1configuration.h"
    "/tmp/qtbase-6.9.1/src/network/access/qhttp2configuration.h"
    "/tmp/qtbase-6.9.1/src/network/access/qhttpmultipart.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkrequestfactory.h"
    "/tmp/qtbase-6.9.1/src/network/access/qrestaccessmanager.h"
    "/tmp/qtbase-6.9.1/src/network/access/qrestreply.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qdnslookup.h"
    "/tmp/qtbase-6.9.1/src/network/socket/qlocalserver.h"
    "/tmp/qtbase-6.9.1/src/network/socket/qlocalsocket.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qocspresponse.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qssldiffiehellmanparameters.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qsslellipticcurve.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qsslpresharedkeyauthenticator.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qsslserver.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qdtls.h"
    "/tmp/qtbase-6.9.1/build/include/QtNetwork/QtNetworkDepends"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtNetwork/6.9.1/QtNetwork/private" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/src/network/access/qabstractnetworkcache_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qhsts_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkaccessauthenticationmanager_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkaccessbackend_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkaccesscache_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkaccesscachebackend_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkaccessfilebackend_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkaccessmanager_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkcookie_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkcookiejar_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkfile_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qhttpheaderparser_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qhttpheadershelper_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkreply_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkreplydataimpl_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkreplyfileimpl_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkreplyimpl_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkrequest_p.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qauthenticator_p.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qhostaddress_p.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qhostinfo_p.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qnetconmonitor_p.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qnetworkdatagram_p.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qnetworkinformation_p.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qnetworkinterface_p.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qnetworkinterface_unix_p.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qtnetworkglobal_p.h"
    "/tmp/qtbase-6.9.1/src/network/socket/qabstractsocket_p.h"
    "/tmp/qtbase-6.9.1/src/network/socket/qabstractsocketengine_p.h"
    "/tmp/qtbase-6.9.1/src/network/socket/qnativesocketengine_p.h"
    "/tmp/qtbase-6.9.1/src/network/socket/qnativesocketengine_p_p.h"
    "/tmp/qtbase-6.9.1/src/network/socket/qtcpserver_p.h"
    "/tmp/qtbase-6.9.1/src/network/socket/qtcpsocket_p.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qssl_p.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qsslcertificate_p.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qsslcertificateextension_p.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qtlsbackend_p.h"
    "/tmp/qtbase-6.9.1/build/src/network/qtnetwork-config_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkdiskcache_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qhstsstore_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/http2/bitstreams_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/http2/hpack_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/http2/hpacktable_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/http2/http2frames_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/http2/http2protocol_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/http2/http2streams_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/http2/huffman_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qabstractprotocolhandler_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qdecompresshelper_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qhttp2connection_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qhttp2protocolhandler_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qhttpmultipart_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qhttpnetworkconnection_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qhttpnetworkconnectionchannel_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qhttpnetworkheader_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qhttpnetworkreply_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qhttpnetworkrequest_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qhttpprotocolhandler_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qhttpthreaddelegate_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkreplyhttpimpl_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qnetworkrequestfactory_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qrestaccessmanager_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qrestreply_p.h"
    "/tmp/qtbase-6.9.1/src/network/access/qsocketabstraction_p.h"
    "/tmp/qtbase-6.9.1/src/network/socket/qhttpsocketengine_p.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qtldurl_p.h"
    "/tmp/qtbase-6.9.1/src/network/kernel/qdnslookup_p.h"
    "/tmp/qtbase-6.9.1/src/network/socket/qnet_unix_p.h"
    "/tmp/qtbase-6.9.1/src/network/socket/qsocks5socketengine_p.h"
    "/tmp/qtbase-6.9.1/src/network/socket/qlocalserver_p.h"
    "/tmp/qtbase-6.9.1/src/network/socket/qlocalsocket_p.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qocspresponse_p.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qsslcipher_p.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qsslconfiguration_p.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qssldiffiehellmanparameters_p.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qsslkey_p.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qsslpresharedkeyauthenticator_p.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qsslsocket_p.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qsslserver_p.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qdtls_p.h"
    "/tmp/qtbase-6.9.1/src/network/ssl/qocsp_p.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/mkspecs/modules" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_network.pri"
    "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_network_private.pri"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/pkgconfig/Qt6Network.pc")
endif()


# Install script for directory: /tmp/qtbase-6.9.1/src/dbus

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./metatypes" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/dbus/meta_types/qt6dbus_release_metatypes.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBus" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6DBus/Qt6DBusConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6DBus/Qt6DBusConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6DBus/Qt6DBusConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBus" TYPE FILE FILES "/tmp/qtbase-6.9.1/src/dbus/Qt6DBusMacros.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBusPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6DBusPrivate/Qt6DBusPrivateConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6DBusPrivate/Qt6DBusPrivateConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6DBusPrivate/Qt6DBusPrivateConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6DBus.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6DBus.so.6"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "\$ORIGIN")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/tmp/qtbase-6.9.1/build/lib/libQt6DBus.so.6.9.1"
    "/tmp/qtbase-6.9.1/build/lib/libQt6DBus.so.6"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6DBus.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6DBus.so.6"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6DBus.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6DBus.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6DBus.so"
         RPATH "\$ORIGIN")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/tmp/qtbase-6.9.1/build/lib/libQt6DBus.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6DBus.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6DBus.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6DBus.so"
         OLD_RPATH "/tmp/qtbase-6.9.1/build/lib:"
         NEW_RPATH "\$ORIGIN")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/tmp/qtbase-6.9.1/build/libexec/qt-internal-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6DBus.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBus/Qt6DBusTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBus/Qt6DBusTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/dbus/CMakeFiles/Export/lib/cmake/Qt6DBus/Qt6DBusTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBus/Qt6DBusTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBus/Qt6DBusTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBus" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/dbus/CMakeFiles/Export/lib/cmake/Qt6DBus/Qt6DBusTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBus" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/dbus/CMakeFiles/Export/lib/cmake/Qt6DBus/Qt6DBusTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBus" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6DBus/Qt6DBusVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6DBus/Qt6DBusVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBus" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBusPrivate/Qt6DBusPrivateTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBusPrivate/Qt6DBusPrivateTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/dbus/CMakeFiles/Export/lib/cmake/Qt6DBusPrivate/Qt6DBusPrivateTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBusPrivate/Qt6DBusPrivateTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBusPrivate/Qt6DBusPrivateTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBusPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/dbus/CMakeFiles/Export/lib/cmake/Qt6DBusPrivate/Qt6DBusPrivateTargets.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBusPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6DBusPrivate/Qt6DBusPrivateVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6DBusPrivate/Qt6DBusPrivateVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBusPrivate" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modules" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/modules/DBus.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_html_docs_DBusx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc/qtdbus" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/doc/qtdbus/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_qch_docs_DBusx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/doc/qtdbus.qch")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBus" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6DBus/Qt6DBusAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6DBusPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6DBusPrivate/Qt6DBusPrivateAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtDBus" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/include/QtDBus/.syncqt_staging/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtDBus" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/include/QtDBus/qtdbusexports.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusabstractadaptor.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusabstractinterface.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusargument.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusconnection.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusconnectioninterface.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbuscontext.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbuserror.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusextratypes.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusinterface.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusmessage.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusmetatype.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbuspendingcall.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbuspendingreply.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusreply.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusserver.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusservicewatcher.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusunixfiledescriptor.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusvirtualobject.h"
    "/tmp/qtbase-6.9.1/src/dbus/qtdbusglobal.h"
    "/tmp/qtbase-6.9.1/build/include/QtDBus/QtDBusDepends"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtDBus/6.9.1/QtDBus/private" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/src/dbus/dbus_minimal_p.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbus_symbols_p.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusabstractadaptor_p.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusabstractinterface_p.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusargument_p.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusconnection_p.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusconnectionmanager_p.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbuscontext_p.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusintegrator_p.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusinterface_p.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusintrospection_p.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusmessage_p.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusmetaobject_p.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusmetatype_p.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbuspendingcall_p.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusthreaddebug_p.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusutil_p.h"
    "/tmp/qtbase-6.9.1/src/dbus/qdbusxmlparser_p.h"
    "/tmp/qtbase-6.9.1/src/dbus/qtdbusglobal_p.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/mkspecs/modules" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_dbus.pri"
    "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_dbus_private.pri"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/pkgconfig/Qt6DBus.pc")
endif()


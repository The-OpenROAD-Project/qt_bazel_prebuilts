# Install script for directory: /tmp/qtbase-6.9.1/src/plugins/platforms/eglfs/deviceintegration/eglfs_kms

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./metatypes" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/plugins/platforms/eglfs/deviceintegration/eglfs_kms/meta_types/qt6eglfskmsgbmsupportprivate_release_metatypes.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6EglFsKmsGbmSupportPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6EglFsKmsGbmSupportPrivate/Qt6EglFsKmsGbmSupportPrivateConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6EglFsKmsGbmSupportPrivate/Qt6EglFsKmsGbmSupportPrivateConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6EglFsKmsGbmSupportPrivate/Qt6EglFsKmsGbmSupportPrivateConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6EglFsKmsGbmSupport.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6EglFsKmsGbmSupport.so.6"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "\$ORIGIN")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/tmp/qtbase-6.9.1/build/lib/libQt6EglFsKmsGbmSupport.so.6.9.1"
    "/tmp/qtbase-6.9.1/build/lib/libQt6EglFsKmsGbmSupport.so.6"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6EglFsKmsGbmSupport.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6EglFsKmsGbmSupport.so.6"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6EglFsKmsGbmSupport.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6EglFsKmsGbmSupport.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6EglFsKmsGbmSupport.so"
         RPATH "\$ORIGIN")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/tmp/qtbase-6.9.1/build/lib/libQt6EglFsKmsGbmSupport.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6EglFsKmsGbmSupport.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6EglFsKmsGbmSupport.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6EglFsKmsGbmSupport.so"
         OLD_RPATH "/tmp/qtbase-6.9.1/build/lib:"
         NEW_RPATH "\$ORIGIN")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/tmp/qtbase-6.9.1/build/libexec/qt-internal-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6EglFsKmsGbmSupport.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6EglFsKmsGbmSupportPrivate/Qt6EglFsKmsGbmSupportPrivateTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6EglFsKmsGbmSupportPrivate/Qt6EglFsKmsGbmSupportPrivateTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/plugins/platforms/eglfs/deviceintegration/eglfs_kms/CMakeFiles/Export/lib/cmake/Qt6EglFsKmsGbmSupportPrivate/Qt6EglFsKmsGbmSupportPrivateTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6EglFsKmsGbmSupportPrivate/Qt6EglFsKmsGbmSupportPrivateTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6EglFsKmsGbmSupportPrivate/Qt6EglFsKmsGbmSupportPrivateTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6EglFsKmsGbmSupportPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/plugins/platforms/eglfs/deviceintegration/eglfs_kms/CMakeFiles/Export/lib/cmake/Qt6EglFsKmsGbmSupportPrivate/Qt6EglFsKmsGbmSupportPrivateTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6EglFsKmsGbmSupportPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/plugins/platforms/eglfs/deviceintegration/eglfs_kms/CMakeFiles/Export/lib/cmake/Qt6EglFsKmsGbmSupportPrivate/Qt6EglFsKmsGbmSupportPrivateTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6EglFsKmsGbmSupportPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6EglFsKmsGbmSupportPrivate/Qt6EglFsKmsGbmSupportPrivateVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6EglFsKmsGbmSupportPrivate/Qt6EglFsKmsGbmSupportPrivateVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6EglFsKmsGbmSupportPrivate" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modules" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/modules/EglFsKmsGbmSupportPrivate.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Gui/Qt6QEglFSKmsGbmIntegrationPluginConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Gui/Qt6QEglFSKmsGbmIntegrationPluginConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Gui/Qt6QEglFSKmsGbmIntegrationPluginConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/plugins/egldeviceintegrations/libqeglfs-kms-integration.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/plugins/egldeviceintegrations/libqeglfs-kms-integration.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/plugins/egldeviceintegrations/libqeglfs-kms-integration.so"
         RPATH "\$ORIGIN/../../lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/plugins/egldeviceintegrations" TYPE MODULE FILES "/tmp/qtbase-6.9.1/build/plugins/egldeviceintegrations/libqeglfs-kms-integration.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/plugins/egldeviceintegrations/libqeglfs-kms-integration.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/plugins/egldeviceintegrations/libqeglfs-kms-integration.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/plugins/egldeviceintegrations/libqeglfs-kms-integration.so"
         OLD_RPATH "/tmp/qtbase-6.9.1/build/lib:"
         NEW_RPATH "\$ORIGIN/../../lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/tmp/qtbase-6.9.1/build/libexec/qt-internal-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/plugins/egldeviceintegrations/libqeglfs-kms-integration.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui/Qt6QEglFSKmsGbmIntegrationPluginTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui/Qt6QEglFSKmsGbmIntegrationPluginTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/plugins/platforms/eglfs/deviceintegration/eglfs_kms/CMakeFiles/Export/lib/cmake/Qt6Gui/Qt6QEglFSKmsGbmIntegrationPluginTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui/Qt6QEglFSKmsGbmIntegrationPluginTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui/Qt6QEglFSKmsGbmIntegrationPluginTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/plugins/platforms/eglfs/deviceintegration/eglfs_kms/CMakeFiles/Export/lib/cmake/Qt6Gui/Qt6QEglFSKmsGbmIntegrationPluginTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/plugins/platforms/eglfs/deviceintegration/eglfs_kms/CMakeFiles/Export/lib/cmake/Qt6Gui/Qt6QEglFSKmsGbmIntegrationPluginTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6EglFsKmsGbmSupportPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6EglFsKmsGbmSupportPrivate/Qt6EglFsKmsGbmSupportPrivateAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Gui/Qt6QEglFSKmsGbmIntegrationPluginAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtEglFsKmsGbmSupport" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/include/QtEglFsKmsGbmSupport/.syncqt_staging/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtEglFsKmsGbmSupport" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/include/QtEglFsKmsGbmSupport/QtEglFsKmsGbmSupportDepends")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtEglFsKmsGbmSupport/6.9.1/QtEglFsKmsGbmSupport/private" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/src/plugins/platforms/eglfs/deviceintegration/eglfs_kms/qeglfskmsgbmcursor_p.h"
    "/tmp/qtbase-6.9.1/src/plugins/platforms/eglfs/deviceintegration/eglfs_kms/qeglfskmsgbmdevice_p.h"
    "/tmp/qtbase-6.9.1/src/plugins/platforms/eglfs/deviceintegration/eglfs_kms/qeglfskmsgbmintegration_p.h"
    "/tmp/qtbase-6.9.1/src/plugins/platforms/eglfs/deviceintegration/eglfs_kms/qeglfskmsgbmscreen_p.h"
    "/tmp/qtbase-6.9.1/src/plugins/platforms/eglfs/deviceintegration/eglfs_kms/qeglfskmsgbmwindow_p.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/mkspecs/modules" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_eglfs_kms_gbm_support_private.pri")
endif()


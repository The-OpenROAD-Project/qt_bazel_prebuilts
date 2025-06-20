# Install script for directory: /tmp/qtbase-6.9.1/src/printsupport

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./metatypes" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/printsupport/meta_types/qt6printsupport_release_metatypes.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6PrintSupport" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6PrintSupport/Qt6PrintSupportConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6PrintSupport/Qt6PrintSupportConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6PrintSupport/Qt6PrintSupportConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6PrintSupportPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6PrintSupportPrivate/Qt6PrintSupportPrivateConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6PrintSupportPrivate/Qt6PrintSupportPrivateConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6PrintSupportPrivate/Qt6PrintSupportPrivateConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6PrintSupport.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6PrintSupport.so.6"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "\$ORIGIN")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/tmp/qtbase-6.9.1/build/lib/libQt6PrintSupport.so.6.9.1"
    "/tmp/qtbase-6.9.1/build/lib/libQt6PrintSupport.so.6"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6PrintSupport.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6PrintSupport.so.6"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6PrintSupport.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6PrintSupport.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6PrintSupport.so"
         RPATH "\$ORIGIN")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/tmp/qtbase-6.9.1/build/lib/libQt6PrintSupport.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6PrintSupport.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6PrintSupport.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6PrintSupport.so"
         OLD_RPATH "/tmp/qtbase-6.9.1/build/lib:"
         NEW_RPATH "\$ORIGIN")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/tmp/qtbase-6.9.1/build/libexec/qt-internal-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6PrintSupport.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6PrintSupport/Qt6PrintSupportTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6PrintSupport/Qt6PrintSupportTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/printsupport/CMakeFiles/Export/lib/cmake/Qt6PrintSupport/Qt6PrintSupportTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6PrintSupport/Qt6PrintSupportTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6PrintSupport/Qt6PrintSupportTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6PrintSupport" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/printsupport/CMakeFiles/Export/lib/cmake/Qt6PrintSupport/Qt6PrintSupportTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6PrintSupport" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/printsupport/CMakeFiles/Export/lib/cmake/Qt6PrintSupport/Qt6PrintSupportTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6PrintSupport" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6PrintSupport/Qt6PrintSupportVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6PrintSupport/Qt6PrintSupportVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6PrintSupport" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6PrintSupportPrivate/Qt6PrintSupportPrivateTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6PrintSupportPrivate/Qt6PrintSupportPrivateTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/printsupport/CMakeFiles/Export/lib/cmake/Qt6PrintSupportPrivate/Qt6PrintSupportPrivateTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6PrintSupportPrivate/Qt6PrintSupportPrivateTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6PrintSupportPrivate/Qt6PrintSupportPrivateTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6PrintSupportPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/printsupport/CMakeFiles/Export/lib/cmake/Qt6PrintSupportPrivate/Qt6PrintSupportPrivateTargets.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6PrintSupportPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6PrintSupportPrivate/Qt6PrintSupportPrivateVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6PrintSupportPrivate/Qt6PrintSupportPrivateVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6PrintSupportPrivate" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modules" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/modules/PrintSupport.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_html_docs_PrintSupportx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc/qtprintsupport" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/doc/qtprintsupport/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_qch_docs_PrintSupportx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/doc/qtprintsupport.qch")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6PrintSupport" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6PrintSupport/Qt6PrintSupportAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6PrintSupportPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6PrintSupportPrivate/Qt6PrintSupportPrivateAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtPrintSupport" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/include/QtPrintSupport/.syncqt_staging/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtPrintSupport" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/include/QtPrintSupport/qtprintsupportexports.h"
    "/tmp/qtbase-6.9.1/src/printsupport/kernel/qprintengine.h"
    "/tmp/qtbase-6.9.1/src/printsupport/kernel/qprinter.h"
    "/tmp/qtbase-6.9.1/src/printsupport/kernel/qprinterinfo.h"
    "/tmp/qtbase-6.9.1/src/printsupport/kernel/qtprintsupportglobal.h"
    "/tmp/qtbase-6.9.1/build/src/printsupport/qtprintsupport-config.h"
    "/tmp/qtbase-6.9.1/src/printsupport/widgets/qprintpreviewwidget.h"
    "/tmp/qtbase-6.9.1/src/printsupport/dialogs/qabstractprintdialog.h"
    "/tmp/qtbase-6.9.1/src/printsupport/dialogs/qpagesetupdialog.h"
    "/tmp/qtbase-6.9.1/src/printsupport/dialogs/qprintdialog.h"
    "/tmp/qtbase-6.9.1/src/printsupport/dialogs/qprintpreviewdialog.h"
    "/tmp/qtbase-6.9.1/build/include/QtPrintSupport/QtPrintSupportDepends"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtPrintSupport/6.9.1/QtPrintSupport/private" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/src/printsupport/kernel/qpaintengine_alpha_p.h"
    "/tmp/qtbase-6.9.1/src/printsupport/kernel/qprint_p.h"
    "/tmp/qtbase-6.9.1/src/printsupport/kernel/qprintdevice_p.h"
    "/tmp/qtbase-6.9.1/src/printsupport/kernel/qprintengine_pdf_p.h"
    "/tmp/qtbase-6.9.1/src/printsupport/kernel/qprinter_p.h"
    "/tmp/qtbase-6.9.1/src/printsupport/kernel/qprinterinfo_p.h"
    "/tmp/qtbase-6.9.1/src/printsupport/kernel/qtprintsupportglobal_p.h"
    "/tmp/qtbase-6.9.1/build/src/printsupport/qtprintsupport-config_p.h"
    "/tmp/qtbase-6.9.1/src/printsupport/kernel/qpaintengine_preview_p.h"
    "/tmp/qtbase-6.9.1/src/printsupport/dialogs/qabstractprintdialog_p.h"
    "/tmp/qtbase-6.9.1/src/printsupport/dialogs/qpagesetupdialog_p.h"
    "/tmp/qtbase-6.9.1/src/printsupport/dialogs/qpagesetupdialog_unix_p.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtPrintSupport/6.9.1/QtPrintSupport/qpa" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/src/printsupport/kernel/qplatformprintdevice.h"
    "/tmp/qtbase-6.9.1/src/printsupport/kernel/qplatformprintersupport.h"
    "/tmp/qtbase-6.9.1/src/printsupport/kernel/qplatformprintplugin.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/mkspecs/modules" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_printsupport.pri"
    "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_printsupport_private.pri"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/pkgconfig/Qt6PrintSupport.pc")
endif()


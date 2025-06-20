# Install script for directory: /tmp/qtbase-6.9.1/src/platformsupport/input

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./metatypes" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/platformsupport/input/meta_types/qt6inputsupportprivate_release_metatypes.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6InputSupportPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6InputSupportPrivate/Qt6InputSupportPrivateConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6InputSupportPrivate/Qt6InputSupportPrivateConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6InputSupportPrivate/Qt6InputSupportPrivateConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/tmp/qtbase-6.9.1/build/lib/libQt6InputSupport.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6InputSupportPrivate/Qt6InputSupportPrivateTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6InputSupportPrivate/Qt6InputSupportPrivateTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/platformsupport/input/CMakeFiles/Export/lib/cmake/Qt6InputSupportPrivate/Qt6InputSupportPrivateTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6InputSupportPrivate/Qt6InputSupportPrivateTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6InputSupportPrivate/Qt6InputSupportPrivateTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6InputSupportPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/platformsupport/input/CMakeFiles/Export/lib/cmake/Qt6InputSupportPrivate/Qt6InputSupportPrivateTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6InputSupportPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/platformsupport/input/CMakeFiles/Export/lib/cmake/Qt6InputSupportPrivate/Qt6InputSupportPrivateTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6InputSupportPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6InputSupportPrivate/Qt6InputSupportPrivateVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6InputSupportPrivate/Qt6InputSupportPrivateVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6InputSupportPrivate" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modules" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/modules/InputSupportPrivate.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6InputSupportPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6InputSupportPrivate/Qt6InputSupportPrivateAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtInputSupport" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/include/QtInputSupport/.syncqt_staging/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtInputSupport" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/include/QtInputSupport/QtInputSupportDepends")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtInputSupport/6.9.1/QtInputSupport/private" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/src/platformsupport/input/evdevkeyboard/qevdevkeyboard_defaultmap_p.h"
    "/tmp/qtbase-6.9.1/src/platformsupport/input/evdevkeyboard/qevdevkeyboardhandler_p.h"
    "/tmp/qtbase-6.9.1/src/platformsupport/input/evdevkeyboard/qevdevkeyboardmanager_p.h"
    "/tmp/qtbase-6.9.1/src/platformsupport/input/evdevmouse/qevdevmousehandler_p.h"
    "/tmp/qtbase-6.9.1/src/platformsupport/input/evdevmouse/qevdevmousemanager_p.h"
    "/tmp/qtbase-6.9.1/src/platformsupport/input/evdevtouch/qevdevtouchhandler_p.h"
    "/tmp/qtbase-6.9.1/src/platformsupport/input/evdevtouch/qevdevtouchmanager_p.h"
    "/tmp/qtbase-6.9.1/src/platformsupport/input/evdevtablet/qevdevtablethandler_p.h"
    "/tmp/qtbase-6.9.1/src/platformsupport/input/evdevtablet/qevdevtabletmanager_p.h"
    "/tmp/qtbase-6.9.1/src/platformsupport/input/shared/devicehandlerlist_p.h"
    "/tmp/qtbase-6.9.1/src/platformsupport/input/shared/qevdevutil_p.h"
    "/tmp/qtbase-6.9.1/src/platformsupport/input/shared/qfdcontainer_p.h"
    "/tmp/qtbase-6.9.1/src/platformsupport/input/shared/qkeyboardmap_p.h"
    "/tmp/qtbase-6.9.1/src/platformsupport/input/shared/qkeycodeaction_p.h"
    "/tmp/qtbase-6.9.1/src/platformsupport/input/shared/qoutputmapping_p.h"
    "/tmp/qtbase-6.9.1/src/platformsupport/input/shared/qtouchfilter_p.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/mkspecs/modules" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_input_support_private.pri")
endif()


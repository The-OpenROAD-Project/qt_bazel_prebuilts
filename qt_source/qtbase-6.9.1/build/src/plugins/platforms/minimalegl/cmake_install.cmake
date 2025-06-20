# Install script for directory: /tmp/qtbase-6.9.1/src/plugins/platforms/minimalegl

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Gui/Qt6QMinimalEglIntegrationPluginConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Gui/Qt6QMinimalEglIntegrationPluginConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Gui/Qt6QMinimalEglIntegrationPluginConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/plugins/platforms/libqminimalegl.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/plugins/platforms/libqminimalegl.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/plugins/platforms/libqminimalegl.so"
         RPATH "\$ORIGIN/../../lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/plugins/platforms" TYPE MODULE FILES "/tmp/qtbase-6.9.1/build/plugins/platforms/libqminimalegl.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/plugins/platforms/libqminimalegl.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/plugins/platforms/libqminimalegl.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/plugins/platforms/libqminimalegl.so"
         OLD_RPATH "/tmp/qtbase-6.9.1/build/lib:"
         NEW_RPATH "\$ORIGIN/../../lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/tmp/qtbase-6.9.1/build/libexec/qt-internal-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/plugins/platforms/libqminimalegl.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui/Qt6QMinimalEglIntegrationPluginTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui/Qt6QMinimalEglIntegrationPluginTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/plugins/platforms/minimalegl/CMakeFiles/Export/lib/cmake/Qt6Gui/Qt6QMinimalEglIntegrationPluginTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui/Qt6QMinimalEglIntegrationPluginTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui/Qt6QMinimalEglIntegrationPluginTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/plugins/platforms/minimalegl/CMakeFiles/Export/lib/cmake/Qt6Gui/Qt6QMinimalEglIntegrationPluginTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/plugins/platforms/minimalegl/CMakeFiles/Export/lib/cmake/Qt6Gui/Qt6QMinimalEglIntegrationPluginTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Gui/Qt6QMinimalEglIntegrationPluginAdditionalTargetInfo.cmake")
endif()


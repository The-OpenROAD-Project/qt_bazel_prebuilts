# Install script for directory: /tmp/qtbase-6.9.1/src/assets/downloader

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./metatypes" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/assets/downloader/meta_types/qt6examplesassetdownloaderprivate_release_metatypes.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6ExamplesAssetDownloaderPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6ExamplesAssetDownloaderPrivate/Qt6ExamplesAssetDownloaderPrivateConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6ExamplesAssetDownloaderPrivate/Qt6ExamplesAssetDownloaderPrivateConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6ExamplesAssetDownloaderPrivate/Qt6ExamplesAssetDownloaderPrivateConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/tmp/qtbase-6.9.1/build/lib/libQt6ExamplesAssetDownloader.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6ExamplesAssetDownloaderPrivate/Qt6ExamplesAssetDownloaderPrivateTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6ExamplesAssetDownloaderPrivate/Qt6ExamplesAssetDownloaderPrivateTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/assets/downloader/CMakeFiles/Export/lib/cmake/Qt6ExamplesAssetDownloaderPrivate/Qt6ExamplesAssetDownloaderPrivateTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6ExamplesAssetDownloaderPrivate/Qt6ExamplesAssetDownloaderPrivateTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6ExamplesAssetDownloaderPrivate/Qt6ExamplesAssetDownloaderPrivateTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6ExamplesAssetDownloaderPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/assets/downloader/CMakeFiles/Export/lib/cmake/Qt6ExamplesAssetDownloaderPrivate/Qt6ExamplesAssetDownloaderPrivateTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6ExamplesAssetDownloaderPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/assets/downloader/CMakeFiles/Export/lib/cmake/Qt6ExamplesAssetDownloaderPrivate/Qt6ExamplesAssetDownloaderPrivateTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6ExamplesAssetDownloaderPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6ExamplesAssetDownloaderPrivate/Qt6ExamplesAssetDownloaderPrivateVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6ExamplesAssetDownloaderPrivate/Qt6ExamplesAssetDownloaderPrivateVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6ExamplesAssetDownloaderPrivate" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modules" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/modules/ExamplesAssetDownloaderPrivate.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6ExamplesAssetDownloaderPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6ExamplesAssetDownloaderPrivate/Qt6ExamplesAssetDownloaderPrivateAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtExamplesAssetDownloader" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/include/QtExamplesAssetDownloader/.syncqt_staging/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtExamplesAssetDownloader" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/src/assets/downloader/assetdownloader.h"
    "/tmp/qtbase-6.9.1/src/assets/downloader/tasking/barrier.h"
    "/tmp/qtbase-6.9.1/src/assets/downloader/tasking/concurrentcall.h"
    "/tmp/qtbase-6.9.1/src/assets/downloader/tasking/conditional.h"
    "/tmp/qtbase-6.9.1/src/assets/downloader/tasking/networkquery.h"
    "/tmp/qtbase-6.9.1/src/assets/downloader/tasking/qprocesstask.h"
    "/tmp/qtbase-6.9.1/src/assets/downloader/tasking/tasking_global.h"
    "/tmp/qtbase-6.9.1/src/assets/downloader/tasking/tasktree.h"
    "/tmp/qtbase-6.9.1/src/assets/downloader/tasking/tasktreerunner.h"
    "/tmp/qtbase-6.9.1/src/assets/downloader/tasking/tcpsocket.h"
    "/tmp/qtbase-6.9.1/build/include/QtExamplesAssetDownloader/QtExamplesAssetDownloaderDepends"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/mkspecs/modules" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_examples_asset_downloader_private.pri")
endif()


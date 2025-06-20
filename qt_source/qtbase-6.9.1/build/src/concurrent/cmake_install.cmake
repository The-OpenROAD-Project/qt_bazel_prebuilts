# Install script for directory: /tmp/qtbase-6.9.1/src/concurrent

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./metatypes" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/concurrent/meta_types/qt6concurrent_release_metatypes.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Concurrent" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Concurrent/Qt6ConcurrentConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Concurrent/Qt6ConcurrentConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Concurrent/Qt6ConcurrentConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6ConcurrentPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6ConcurrentPrivate/Qt6ConcurrentPrivateConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6ConcurrentPrivate/Qt6ConcurrentPrivateConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6ConcurrentPrivate/Qt6ConcurrentPrivateConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Concurrent.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Concurrent.so.6"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "\$ORIGIN")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/tmp/qtbase-6.9.1/build/lib/libQt6Concurrent.so.6.9.1"
    "/tmp/qtbase-6.9.1/build/lib/libQt6Concurrent.so.6"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Concurrent.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Concurrent.so.6"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Concurrent.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Concurrent.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Concurrent.so"
         RPATH "\$ORIGIN")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/tmp/qtbase-6.9.1/build/lib/libQt6Concurrent.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Concurrent.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Concurrent.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Concurrent.so"
         OLD_RPATH "/tmp/qtbase-6.9.1/build/lib:"
         NEW_RPATH "\$ORIGIN")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/tmp/qtbase-6.9.1/build/libexec/qt-internal-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Concurrent.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Concurrent/Qt6ConcurrentTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Concurrent/Qt6ConcurrentTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/concurrent/CMakeFiles/Export/lib/cmake/Qt6Concurrent/Qt6ConcurrentTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Concurrent/Qt6ConcurrentTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Concurrent/Qt6ConcurrentTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Concurrent" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/concurrent/CMakeFiles/Export/lib/cmake/Qt6Concurrent/Qt6ConcurrentTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Concurrent" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/concurrent/CMakeFiles/Export/lib/cmake/Qt6Concurrent/Qt6ConcurrentTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Concurrent" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Concurrent/Qt6ConcurrentVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Concurrent/Qt6ConcurrentVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Concurrent" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6ConcurrentPrivate/Qt6ConcurrentPrivateTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6ConcurrentPrivate/Qt6ConcurrentPrivateTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/concurrent/CMakeFiles/Export/lib/cmake/Qt6ConcurrentPrivate/Qt6ConcurrentPrivateTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6ConcurrentPrivate/Qt6ConcurrentPrivateTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6ConcurrentPrivate/Qt6ConcurrentPrivateTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6ConcurrentPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/concurrent/CMakeFiles/Export/lib/cmake/Qt6ConcurrentPrivate/Qt6ConcurrentPrivateTargets.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6ConcurrentPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6ConcurrentPrivate/Qt6ConcurrentPrivateVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6ConcurrentPrivate/Qt6ConcurrentPrivateVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6ConcurrentPrivate" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modules" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/modules/Concurrent.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_html_docs_Concurrentx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc/qtconcurrent" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/doc/qtconcurrent/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_qch_docs_Concurrentx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/doc/qtconcurrent.qch")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Concurrent" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Concurrent/Qt6ConcurrentAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6ConcurrentPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6ConcurrentPrivate/Qt6ConcurrentPrivateAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtConcurrent" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/include/QtConcurrent/.syncqt_staging/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtConcurrent" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/include/QtConcurrent/qtconcurrentexports.h"
    "/tmp/qtbase-6.9.1/src/concurrent/qtaskbuilder.h"
    "/tmp/qtbase-6.9.1/src/concurrent/qtconcurrent_global.h"
    "/tmp/qtbase-6.9.1/src/concurrent/qtconcurrentcompilertest.h"
    "/tmp/qtbase-6.9.1/src/concurrent/qtconcurrentfilter.h"
    "/tmp/qtbase-6.9.1/src/concurrent/qtconcurrentfilterkernel.h"
    "/tmp/qtbase-6.9.1/src/concurrent/qtconcurrentfunctionwrappers.h"
    "/tmp/qtbase-6.9.1/src/concurrent/qtconcurrentiteratekernel.h"
    "/tmp/qtbase-6.9.1/src/concurrent/qtconcurrentmap.h"
    "/tmp/qtbase-6.9.1/src/concurrent/qtconcurrentmapkernel.h"
    "/tmp/qtbase-6.9.1/src/concurrent/qtconcurrentmedian.h"
    "/tmp/qtbase-6.9.1/src/concurrent/qtconcurrentreducekernel.h"
    "/tmp/qtbase-6.9.1/src/concurrent/qtconcurrentrun.h"
    "/tmp/qtbase-6.9.1/src/concurrent/qtconcurrentrunbase.h"
    "/tmp/qtbase-6.9.1/src/concurrent/qtconcurrentstoredfunctioncall.h"
    "/tmp/qtbase-6.9.1/src/concurrent/qtconcurrenttask.h"
    "/tmp/qtbase-6.9.1/src/concurrent/qtconcurrentthreadengine.h"
    "/tmp/qtbase-6.9.1/build/include/QtConcurrent/QtConcurrentDepends"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/mkspecs/modules" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_concurrent.pri"
    "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_concurrent_private.pri"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/pkgconfig/Qt6Concurrent.pc")
endif()


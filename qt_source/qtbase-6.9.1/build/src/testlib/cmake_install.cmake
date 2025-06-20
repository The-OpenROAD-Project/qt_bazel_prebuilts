# Install script for directory: /tmp/qtbase-6.9.1/src/testlib

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Test" TYPE FILE FILES "/tmp/qtbase-6.9.1/src/testlib/QtTestProperties.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./metatypes" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/testlib/meta_types/qt6test_release_metatypes.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Test" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Test/Qt6TestConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Test/Qt6TestConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Test/Qt6TestConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6TestPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6TestPrivate/Qt6TestPrivateConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6TestPrivate/Qt6TestPrivateConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6TestPrivate/Qt6TestPrivateConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Test.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Test.so.6"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "\$ORIGIN")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/tmp/qtbase-6.9.1/build/lib/libQt6Test.so.6.9.1"
    "/tmp/qtbase-6.9.1/build/lib/libQt6Test.so.6"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Test.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Test.so.6"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Test.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Test.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Test.so"
         RPATH "\$ORIGIN")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/tmp/qtbase-6.9.1/build/lib/libQt6Test.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Test.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Test.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Test.so"
         OLD_RPATH "/tmp/qtbase-6.9.1/build/lib:"
         NEW_RPATH "\$ORIGIN")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/tmp/qtbase-6.9.1/build/libexec/qt-internal-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Test.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Test/Qt6TestTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Test/Qt6TestTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/testlib/CMakeFiles/Export/lib/cmake/Qt6Test/Qt6TestTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Test/Qt6TestTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Test/Qt6TestTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Test" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/testlib/CMakeFiles/Export/lib/cmake/Qt6Test/Qt6TestTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Test" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/testlib/CMakeFiles/Export/lib/cmake/Qt6Test/Qt6TestTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Test" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Test/Qt6TestVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Test/Qt6TestVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Test" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6TestPrivate/Qt6TestPrivateTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6TestPrivate/Qt6TestPrivateTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/testlib/CMakeFiles/Export/lib/cmake/Qt6TestPrivate/Qt6TestPrivateTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6TestPrivate/Qt6TestPrivateTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6TestPrivate/Qt6TestPrivateTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6TestPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/testlib/CMakeFiles/Export/lib/cmake/Qt6TestPrivate/Qt6TestPrivateTargets.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6TestPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6TestPrivate/Qt6TestPrivateVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6TestPrivate/Qt6TestPrivateVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6TestPrivate" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modules" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/modules/Test.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_html_docs_Testx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc/qttestlib" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/doc/qttestlib/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_qch_docs_Testx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/doc/qttestlib.qch")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Test" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Test/Qt6TestAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6TestPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6TestPrivate/Qt6TestPrivateAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtTest" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/include/QtTest/.syncqt_staging/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtTest" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/include/QtTest/qttestexports.h"
    "/tmp/qtbase-6.9.1/src/testlib/qbenchmark.h"
    "/tmp/qtbase-6.9.1/src/testlib/qbenchmarkmetric.h"
    "/tmp/qtbase-6.9.1/src/testlib/qsignalspy.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtest.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtest_gui.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtest_network.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtest_widgets.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtestaccessible.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtestassert.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtestcase.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtestdata.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtestevent.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtesteventloop.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtestkeyboard.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtestmouse.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtestspontaneevent.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtestsystem.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtesttouch.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtesttostring.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtestwheel.h"
    "/tmp/qtbase-6.9.1/src/testlib/qttestglobal.h"
    "/tmp/qtbase-6.9.1/build/src/testlib/qttestlib-config.h"
    "/tmp/qtbase-6.9.1/src/testlib/qabstractitemmodeltester.h"
    "/tmp/qtbase-6.9.1/build/include/QtTest/QtTestDepends"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtTest/6.9.1/QtTest/private" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/src/testlib/3rdparty/cycle/cycle_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/3rdparty/catch2/catch_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qabstracttestlogger_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qbenchmark_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qbenchmarkevent_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qbenchmarkmeasurement_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qbenchmarkmetric_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qbenchmarkperfevents_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qbenchmarktimemeasurers_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qcomparisontesthelper_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qcsvbenchmarklogger_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qemulationdetector_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qjunittestlogger_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qplaintestlogger_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qpropertytesthelper_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qsignaldumper_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtaptestlogger_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qteamcitylogger_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtestblacklist_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtestcase_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtestcoreelement_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtestcrashhandler_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtestelement_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtestelementattribute_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtesthelpers_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtestjunitstreamer_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtestlog_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtestresult_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qtesttable_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qxmltestlogger_p.h"
    "/tmp/qtbase-6.9.1/build/src/testlib/qttestlib-config_p.h"
    "/tmp/qtbase-6.9.1/src/testlib/qbenchmarkvalgrind_p.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/mkspecs/modules" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_testlib.pri"
    "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_testlib_private.pri"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/pkgconfig/Qt6Test.pc")
endif()


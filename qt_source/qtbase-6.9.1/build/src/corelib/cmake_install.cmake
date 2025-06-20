# Install script for directory: /tmp/qtbase-6.9.1/src/corelib

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Core" TYPE FILE FILES "/tmp/qtbase-6.9.1/src/corelib/Qt6CTestMacros.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Core" TYPE FILE FILES "/tmp/qtbase-6.9.1/src/corelib/Qt6CoreConfigureFileTemplate.in")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Core" TYPE FILE FILES "/tmp/qtbase-6.9.1/src/corelib/Qt6CoreResourceInit.in.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Core" TYPE FILE FILES "/tmp/qtbase-6.9.1/src/corelib/Qt6CoreDeploySupport.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Core" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Core/Qt6CoreConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Core/Qt6CoreConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Core/Qt6CoreConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Core" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/src/corelib/Qt6CoreMacros.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Core/Qt6CoreConfigExtras.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6CorePrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6CorePrivate/Qt6CorePrivateConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6CorePrivate/Qt6CorePrivateConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6CorePrivate/Qt6CorePrivateConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Core.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Core.so.6"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "\$ORIGIN")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/tmp/qtbase-6.9.1/build/lib/libQt6Core.so.6.9.1"
    "/tmp/qtbase-6.9.1/build/lib/libQt6Core.so.6"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Core.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Core.so.6"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH ":::::::"
           NEW_RPATH "\$ORIGIN")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/tmp/qtbase-6.9.1/build/libexec/qt-internal-strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Core.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Core.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Core.so"
         RPATH "\$ORIGIN")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/tmp/qtbase-6.9.1/build/lib/libQt6Core.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Core.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Core.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Core.so"
         OLD_RPATH ":::::::"
         NEW_RPATH "\$ORIGIN")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/tmp/qtbase-6.9.1/build/libexec/qt-internal-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Core.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Core/Qt6CoreTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Core/Qt6CoreTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/corelib/CMakeFiles/Export/lib/cmake/Qt6Core/Qt6CoreTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Core/Qt6CoreTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Core/Qt6CoreTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Core" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/corelib/CMakeFiles/Export/lib/cmake/Qt6Core/Qt6CoreTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Core" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/corelib/CMakeFiles/Export/lib/cmake/Qt6Core/Qt6CoreTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Core" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Core/Qt6CoreVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Core/Qt6CoreVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Core" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6CorePrivate/Qt6CorePrivateTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6CorePrivate/Qt6CorePrivateTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/corelib/CMakeFiles/Export/lib/cmake/Qt6CorePrivate/Qt6CorePrivateTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6CorePrivate/Qt6CorePrivateTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6CorePrivate/Qt6CorePrivateTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6CorePrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/corelib/CMakeFiles/Export/lib/cmake/Qt6CorePrivate/Qt6CorePrivateTargets.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6CorePrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6CorePrivate/Qt6CorePrivateVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6CorePrivate/Qt6CorePrivateVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6CorePrivate" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modules" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/modules/Core.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./metatypes" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/corelib/meta_types/qt6core_release_metatypes.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_html_docs_Corex")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc/qtcore" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/doc/qtcore/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_qch_docs_Corex")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/doc/qtcore.qch")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Core" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Core/Qt6CoreAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6CorePrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6CorePrivate/Qt6CorePrivateAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtCore" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/include/QtCore/.syncqt_staging/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtCore" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/include/QtCore/qtcoreexports.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qsimd.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qhash.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qassert.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qcompare_impl.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qcompare.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qcomparehelpers.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qcompilerdetection.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qconstructormacros.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qcontainerinfo.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qdarwinhelpers.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qendian.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qexceptionhandling.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qflags.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qfloat16.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qforeach.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qfunctionpointer.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qglobal.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qglobalstatic.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qlibraryinfo.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qlogging.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qmalloc.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qminmax.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qnamespace.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qnativeinterface.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qnumeric.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qoperatingsystemversion.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qoverload.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qprocessordetection.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qrandom.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qstdlibdetection.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qswap.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qsysinfo.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qsystemdetection.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qtclasshelpermacros.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qtconfiginclude.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qtconfigmacros.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qtcoreglobal.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qtdeprecationmarkers.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qtenvironmentvariables.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qtnoop.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qtpreprocessorsupport.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qtresource.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qtsymbolmacros.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qttranslation.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qttypetraits.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qtversionchecks.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qtversion.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qtypeinfo.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qtypes.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/q17memory.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/q20algorithm.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/q20chrono.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/q20functional.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/q20iterator.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/q20map.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/q20memory.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/q20type_traits.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/q20utility.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/q20vector.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/q23functional.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/q23type_traits.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/q23utility.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/q26numeric.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qxpfunctional.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qxptype_traits.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qversiontagging.h"
    "/tmp/qtbase-6.9.1/src/corelib/ipc/qsharedmemory.h"
    "/tmp/qtbase-6.9.1/src/corelib/ipc/qsystemsemaphore.h"
    "/tmp/qtbase-6.9.1/src/corelib/ipc/qtipccommon.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qbuffer.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qdebug.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qdir.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qdirlisting.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qdiriterator.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qfile.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qfiledevice.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qfileinfo.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qfileselector.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qiodevice.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qiodevicebase.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qlockfile.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qloggingcategory.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qresource.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qsavefile.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qstandardpaths.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qstorageinfo.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qtemporarydir.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qtemporaryfile.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qurl.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qurlquery.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qabstracteventdispatcher.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qabstractnativeeventfilter.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qapplicationstatic.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qassociativeiterable.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qbasictimer.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qbindingstorage.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qchronotimer.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qcoreapplication.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qcoreapplication_platform.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qcoreevent.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qdeadlinetimer.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qelapsedtimer.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qeventloop.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qiterable.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qmath.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qmetacontainer.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qmetaobject.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qmetatype.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qmimedata.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qtmetamacros.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qtmocconstants.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qtmochelpers.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qobject.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qobject_impl.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qobjectcleanuphandler.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qobjectdefs.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qobjectdefs_impl.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qpointer.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qproperty.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qpropertyprivate.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qsequentialiterable.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qsignalmapper.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qsocketnotifier.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qtestsupport_core.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qtimer.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qtranslator.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qvariant.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qvariantmap.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qvarianthash.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qvariantlist.h"
    "/tmp/qtbase-6.9.1/src/corelib/plugin/qfactoryinterface.h"
    "/tmp/qtbase-6.9.1/src/corelib/plugin/qplugin.h"
    "/tmp/qtbase-6.9.1/src/corelib/plugin/qpluginloader.h"
    "/tmp/qtbase-6.9.1/src/corelib/plugin/quuid.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qcborarray.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qcborcommon.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qcbormap.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qcborstream.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qcborvalue.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qdatastream.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qjsonarray.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qjsondocument.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qjsonobject.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qjsonparseerror.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qjsonvalue.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qtextstream.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qanystringview.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qbytearray.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qbytearrayalgorithms.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qbytearraylist.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qbytearraymatcher.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qbytearrayview.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qchar.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qcollator.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qlatin1stringmatcher.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qlatin1stringview.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qlocale.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qstaticlatin1stringmatcher.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qstring.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qstringalgorithms.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qstringbuilder.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qstringconverter_base.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qstringconverter.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qstringfwd.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qstringlist.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qstringliteral.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qstringmatcher.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qstringtokenizer.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qstringview.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qtextboundaryfinder.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qtformat_impl.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qutf8stringview.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qatomic.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qatomic_cxx11.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qbasicatomic.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qgenericatomic.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qmutex.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qreadwritelock.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qrunnable.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qthread.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qthreadstorage.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qtsan_impl.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qwaitcondition.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qyieldcpu.h"
    "/tmp/qtbase-6.9.1/src/corelib/time/qcalendar.h"
    "/tmp/qtbase-6.9.1/src/corelib/time/qdatetime.h"
    "/tmp/qtbase-6.9.1/src/corelib/time/qtimezone.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qalgorithms.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qarraydata.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qarraydataops.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qarraydatapointer.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qatomicscopedvaluerollback.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qbitarray.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qcache.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qcontainerfwd.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qcontainertools_impl.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qcontiguouscache.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qcryptographichash.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qfunctionaltools_impl.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qhashfunctions.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qiterator.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qline.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qlist.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qmap.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qmargins.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qmessageauthenticationcode.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qpair.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qpoint.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qqueue.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qrect.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qrefcount.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qscopedpointer.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qscopedvaluerollback.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qscopeguard.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qset.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qshareddata.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qshareddata_impl.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qsharedpointer.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qsharedpointer_impl.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qsize.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qspan.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qstack.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qtaggedpointer.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qtyperevision.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qvarlengtharray.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qvector.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qversionnumber.h"
    "/tmp/qtbase-6.9.1/build/src/corelib/qtcore-config.h"
    "/tmp/qtbase-6.9.1/build/src/corelib/global/qconfig.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qxmlstream.h"
    "/tmp/qtbase-6.9.1/src/corelib/animation/qabstractanimation.h"
    "/tmp/qtbase-6.9.1/src/corelib/animation/qanimationgroup.h"
    "/tmp/qtbase-6.9.1/src/corelib/animation/qparallelanimationgroup.h"
    "/tmp/qtbase-6.9.1/src/corelib/animation/qpauseanimation.h"
    "/tmp/qtbase-6.9.1/src/corelib/animation/qpropertyanimation.h"
    "/tmp/qtbase-6.9.1/src/corelib/animation/qsequentialanimationgroup.h"
    "/tmp/qtbase-6.9.1/src/corelib/animation/qvariantanimation.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qwineventnotifier.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qsemaphore.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qthreadpool.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qexception.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qfuture.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qfuture_impl.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qfutureinterface.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qfuturesynchronizer.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qfuturewatcher.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qpromise.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qresultstore.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qcommandlineoption.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qcommandlineparser.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qeasingcurve.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qtimeline.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qregularexpression.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qfilesystemwatcher.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qprocess.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qsettings.h"
    "/tmp/qtbase-6.9.1/src/corelib/itemmodels/qabstractitemmodel.h"
    "/tmp/qtbase-6.9.1/src/corelib/itemmodels/qitemselectionmodel.h"
    "/tmp/qtbase-6.9.1/src/corelib/itemmodels/qabstractproxymodel.h"
    "/tmp/qtbase-6.9.1/src/corelib/itemmodels/qconcatenatetablesproxymodel.h"
    "/tmp/qtbase-6.9.1/src/corelib/itemmodels/qidentityproxymodel.h"
    "/tmp/qtbase-6.9.1/src/corelib/itemmodels/qsortfilterproxymodel.h"
    "/tmp/qtbase-6.9.1/src/corelib/itemmodels/qtransposeproxymodel.h"
    "/tmp/qtbase-6.9.1/src/corelib/itemmodels/qstringlistmodel.h"
    "/tmp/qtbase-6.9.1/src/corelib/plugin/qlibrary.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qcborstreamreader.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qcborstreamwriter.h"
    "/tmp/qtbase-6.9.1/src/corelib/mimetypes/qmimedatabase.h"
    "/tmp/qtbase-6.9.1/src/corelib/mimetypes/qmimetype.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qpermissions.h"
    "/tmp/qtbase-6.9.1/build/src/corelib/global/qtdeprecationdefinitions.h"
    "/tmp/qtbase-6.9.1/build/include/QtCore/QtCoreDepends"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtCore/6.9.1/QtCore/private" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/src/corelib/global/qsimd_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qendian_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qglobal_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qhooks_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qlibraryinfo_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qlogging_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qnativeinterface_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qnumeric_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qoperatingsystemversion_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qrandom_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qtcoreglobal_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qtenvironmentvariables_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qtrace_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qvolatile_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/ipc/qsharedmemory_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/ipc/qsystemsemaphore_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/ipc/qtipccommon_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qabstractfileengine_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qdataurl_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qdebug_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qdir_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qdirentryinfo_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qfile_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qfiledevice_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qfileinfo_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qfileselector_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qfilesystemengine_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qfilesystementry_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qfilesystemiterator_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qfilesystemmetadata_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qfsfileengine_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qfsfileengine_iterator_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qiodevice_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qipaddress_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qlockfile_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qloggingregistry_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qnoncontiguousbytedevice_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qresource_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qresource_iterator_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qsavefile_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qstorageinfo_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qtemporaryfile_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qurl_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qzipreader_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qzipwriter_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/wcharhelpers_win_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qabstracteventdispatcher_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qcoreapplication_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qcoreevent_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qeventloop_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qfunctions_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qiterable_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qmetaobject_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qmetaobject_moc_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qmetaobjectbuilder_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qmetatype_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qobject_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qobject_p_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qproperty_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qsingleshottimer_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qsystemerror_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qtimer_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qtranslator_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qvariant_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/plugin/qfactoryloader_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/plugin/qplugin_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/plugin/quuid_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qcborcommon_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qcborvalue_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qjson_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qjsonparser_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qjsonwriter_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qtextstream_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qxmlutils_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qbytedata_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qcollator_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qdoublescanprint_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qlocale_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qlocale_tools_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qstringalgorithms_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qstringconverter_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qstringiterator_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qunicodetables_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/text/qunicodetools_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qlocking_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qorderedmutexlocker_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qthread_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qwaitcondition_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/time/qcalendarbackend_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/time/qcalendarmath_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/time/qdatetime_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/time/qgregoriancalendar_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/time/qjuliancalendar_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/time/qlocaltime_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/time/qmilankoviccalendar_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/time/qromancalendar_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qduplicatetracker_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qflatmap_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qfreelist_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qmakearray_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qminimalflatset_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qoffsetstringarray_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qringbuffer_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qsmallbytearray_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/qtools_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/quniquehandle_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/tools/quniquehandle_types_p.h"
    "/tmp/qtbase-6.9.1/build/src/corelib/qtcore-config_p.h"
    "/tmp/qtbase-6.9.1/build/src/corelib/global/qconfig_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/qsimd_x86_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qxmlstream_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qxmlstreamgrammar_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/serialization/qxmlstreamparser_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/animation/qabstractanimation_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/animation/qanimationgroup_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/animation/qparallelanimationgroup_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/animation/qpropertyanimation_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/animation/qsequentialanimationgroup_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/animation/qvariantanimation_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/global/minimum-linux_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qcore_unix_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qpoll_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qtimerinfo_unix_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qeventdispatcher_unix_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qfutex_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qmutex_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qreadwritelock_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qthreadpool_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qthreadstorage_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qfutex_linux_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qfutureinterface_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/thread/qfuturewatcher_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/time/qhijricalendar_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/time/qislamiccivilcalendar_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/time/qjalalicalendar_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/time/qtimezoneprivate_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/time/qtimezonelocale_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/time/qdatetimeparser_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qfilesystemwatcher_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qfilesystemwatcher_polling_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qfilesystemwatcher_inotify_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qprocess_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/io/qsettings_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/itemmodels/qabstractitemmodel_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/itemmodels/qitemselectionmodel_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/itemmodels/qabstractproxymodel_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/itemmodels/qidentityproxymodel_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/itemmodels/qtransposeproxymodel_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/plugin/qlibrary_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/plugin/qelfparser_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qeventdispatcher_glib_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/mimetypes/qmimedatabase_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/mimetypes/qmimeglobpattern_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/mimetypes/qmimemagicrule_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/mimetypes/qmimemagicrulematcher_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/mimetypes/qmimeprovider_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/mimetypes/qmimetype_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/mimetypes/qmimetypeparser_p.h"
    "/tmp/qtbase-6.9.1/src/corelib/kernel/qpermissions_p.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/mkspecs/modules" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_core.pri"
    "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_core_private.pri"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/pkgconfig/Qt6Core.pc")
endif()


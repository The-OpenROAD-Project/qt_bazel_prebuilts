# Install script for directory: /tmp/qtbase-6.9.1/src/opengl

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./metatypes" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/opengl/meta_types/qt6opengl_release_metatypes.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6OpenGL" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6OpenGL/Qt6OpenGLConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6OpenGL/Qt6OpenGLConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6OpenGL/Qt6OpenGLConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6OpenGLPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6OpenGLPrivate/Qt6OpenGLPrivateConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6OpenGLPrivate/Qt6OpenGLPrivateConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6OpenGLPrivate/Qt6OpenGLPrivateConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6OpenGL.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6OpenGL.so.6"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "\$ORIGIN")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/tmp/qtbase-6.9.1/build/lib/libQt6OpenGL.so.6.9.1"
    "/tmp/qtbase-6.9.1/build/lib/libQt6OpenGL.so.6"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6OpenGL.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6OpenGL.so.6"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6OpenGL.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6OpenGL.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6OpenGL.so"
         RPATH "\$ORIGIN")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/tmp/qtbase-6.9.1/build/lib/libQt6OpenGL.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6OpenGL.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6OpenGL.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6OpenGL.so"
         OLD_RPATH "/tmp/qtbase-6.9.1/build/lib:"
         NEW_RPATH "\$ORIGIN")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/tmp/qtbase-6.9.1/build/libexec/qt-internal-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6OpenGL.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6OpenGL/Qt6OpenGLTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6OpenGL/Qt6OpenGLTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/opengl/CMakeFiles/Export/lib/cmake/Qt6OpenGL/Qt6OpenGLTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6OpenGL/Qt6OpenGLTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6OpenGL/Qt6OpenGLTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6OpenGL" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/opengl/CMakeFiles/Export/lib/cmake/Qt6OpenGL/Qt6OpenGLTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6OpenGL" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/opengl/CMakeFiles/Export/lib/cmake/Qt6OpenGL/Qt6OpenGLTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6OpenGL" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6OpenGL/Qt6OpenGLVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6OpenGL/Qt6OpenGLVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6OpenGL" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6OpenGLPrivate/Qt6OpenGLPrivateTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6OpenGLPrivate/Qt6OpenGLPrivateTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/opengl/CMakeFiles/Export/lib/cmake/Qt6OpenGLPrivate/Qt6OpenGLPrivateTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6OpenGLPrivate/Qt6OpenGLPrivateTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6OpenGLPrivate/Qt6OpenGLPrivateTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6OpenGLPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/opengl/CMakeFiles/Export/lib/cmake/Qt6OpenGLPrivate/Qt6OpenGLPrivateTargets.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6OpenGLPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6OpenGLPrivate/Qt6OpenGLPrivateVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6OpenGLPrivate/Qt6OpenGLPrivateVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6OpenGLPrivate" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modules" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/modules/OpenGL.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_html_docs_OpenGLx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc/qtopengl" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/doc/qtopengl/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_qch_docs_OpenGLx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/doc/qtopengl.qch")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6OpenGL" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6OpenGL/Qt6OpenGLAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6OpenGLPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6OpenGLPrivate/Qt6OpenGLPrivateAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtOpenGL" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/include/QtOpenGL/.syncqt_staging/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtOpenGL" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/include/QtOpenGL/qtopenglexports.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglbuffer.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopengldebug.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglframebufferobject.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglpaintdevice.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglpixeltransferoptions.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglshaderprogram.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopengltexture.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopengltextureblitter.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopengltimerquery.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglversionfunctions.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglversionfunctionsfactory.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglversionprofile.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglvertexarrayobject.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglwindow.h"
    "/tmp/qtbase-6.9.1/src/opengl/qtopenglglobal.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_1_0.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_1_1.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_1_2.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_1_3.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_1_4.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_1_5.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_2_0.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_2_1.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_3_0.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_3_1.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_3_2_compatibility.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_3_2_core.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_3_3_compatibility.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_3_3_core.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_4_0_compatibility.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_4_0_core.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_4_1_compatibility.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_4_1_core.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_4_2_compatibility.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_4_2_core.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_4_3_compatibility.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_4_3_core.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_4_4_compatibility.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_4_4_core.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_4_5_compatibility.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglfunctions_4_5_core.h"
    "/tmp/qtbase-6.9.1/build/include/QtOpenGL/QtOpenGLDepends"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtOpenGL/6.9.1/QtOpenGL/private" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/src/opengl/qopengl2pexvertexarray_p.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglcustomshaderstage_p.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglengineshadermanager_p.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglengineshadersource_p.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglframebufferobject_p.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglgradientcache_p.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglpaintdevice_p.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglpaintengine_p.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglshadercache_p.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopengltexture_p.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopengltexturecache_p.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopengltextureglyphcache_p.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopengltexturehelper_p.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopengltextureuploader_p.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglversionfunctions_p.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglvertexarrayobject_p.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglqueryhelper_p.h"
    "/tmp/qtbase-6.9.1/src/opengl/qvkconvenience_p.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglcompositor_p.h"
    "/tmp/qtbase-6.9.1/src/opengl/qopenglcompositorbackingstore_p.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/mkspecs/modules" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_opengl.pri"
    "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_opengl_private.pri"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/pkgconfig/Qt6OpenGL.pc")
endif()


# Install script for directory: /tmp/qtbase-6.9.1/src/gui

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./metatypes" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/gui/meta_types/qt6gui_release_metatypes.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Gui/Qt6GuiConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Gui/Qt6GuiConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Gui/Qt6GuiConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6GuiPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6GuiPrivate/Qt6GuiPrivateConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6GuiPrivate/Qt6GuiPrivateConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6GuiPrivate/Qt6GuiPrivateConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Gui.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Gui.so.6"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "\$ORIGIN")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/tmp/qtbase-6.9.1/build/lib/libQt6Gui.so.6.9.1"
    "/tmp/qtbase-6.9.1/build/lib/libQt6Gui.so.6"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Gui.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Gui.so.6"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Gui.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Gui.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Gui.so"
         RPATH "\$ORIGIN")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/tmp/qtbase-6.9.1/build/lib/libQt6Gui.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Gui.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Gui.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Gui.so"
         OLD_RPATH "/tmp/qtbase-6.9.1/build/lib:"
         NEW_RPATH "\$ORIGIN")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/tmp/qtbase-6.9.1/build/libexec/qt-internal-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Gui.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui/Qt6GuiTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui/Qt6GuiTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/gui/CMakeFiles/Export/lib/cmake/Qt6Gui/Qt6GuiTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui/Qt6GuiTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui/Qt6GuiTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/gui/CMakeFiles/Export/lib/cmake/Qt6Gui/Qt6GuiTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/gui/CMakeFiles/Export/lib/cmake/Qt6Gui/Qt6GuiTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Gui/Qt6GuiVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Gui/Qt6GuiVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6GuiPrivate/Qt6GuiPrivateTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6GuiPrivate/Qt6GuiPrivateTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/gui/CMakeFiles/Export/lib/cmake/Qt6GuiPrivate/Qt6GuiPrivateTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6GuiPrivate/Qt6GuiPrivateTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6GuiPrivate/Qt6GuiPrivateTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6GuiPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/gui/CMakeFiles/Export/lib/cmake/Qt6GuiPrivate/Qt6GuiPrivateTargets.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6GuiPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6GuiPrivate/Qt6GuiPrivateVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6GuiPrivate/Qt6GuiPrivateVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6GuiPrivate" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modules" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/modules/Gui.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_html_docs_Guix")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc/qtgui" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/doc/qtgui/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_qch_docs_Guix")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/doc/qtgui.qch")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Gui" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Gui/Qt6GuiAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6GuiPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6GuiPrivate/Qt6GuiPrivateAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtGui" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/include/QtGui/.syncqt_staging/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtGui" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/include/QtGui/qtguiexports.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qabstractfileiconprovider.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qbitmap.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qicon.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qiconengine.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qiconengineplugin.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qimage.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qimageiohandler.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qimagereader.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qimagewriter.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qpicture.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qpixmap.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qpixmapcache.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qclipboard.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qcursor.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qeventpoint.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qevent.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qgenericplugin.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qgenericpluginfactory.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qguiapplication.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qguiapplication_platform.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qinputdevice.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qinputmethod.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qoffscreensurface.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qoffscreensurface_platform.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qopenglcontext.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qpaintdevicewindow.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qpalette.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qpixelformat.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qpointingdevice.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qrasterwindow.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qscreen.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qscreen_platform.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qsessionmanager.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qstylehints.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qsurface.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qsurfaceformat.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qtestsupport_gui.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qtguiglobal.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qwindow.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qwindowdefs.h"
    "/tmp/qtbase-6.9.1/src/gui/math3d/qgenericmatrix.h"
    "/tmp/qtbase-6.9.1/src/gui/math3d/qmatrix4x4.h"
    "/tmp/qtbase-6.9.1/src/gui/math3d/qquaternion.h"
    "/tmp/qtbase-6.9.1/src/gui/math3d/qvector2d.h"
    "/tmp/qtbase-6.9.1/src/gui/math3d/qvector3d.h"
    "/tmp/qtbase-6.9.1/src/gui/math3d/qvector4d.h"
    "/tmp/qtbase-6.9.1/src/gui/math3d/qvectornd.h"
    "/tmp/qtbase-6.9.1/src/gui/opengl/qopengl.h"
    "/tmp/qtbase-6.9.1/src/gui/opengl/qopenglext.h"
    "/tmp/qtbase-6.9.1/src/gui/opengl/qopenglfunctions.h"
    "/tmp/qtbase-6.9.1/src/gui/opengl/qopenglextrafunctions.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qbackingstore.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qbrush.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qcolor.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qcolorspace.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qcolortransform.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpagedpaintdevice.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpagelayout.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpageranges.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpagesize.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpaintdevice.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpaintengine.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpainter.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpainterstateguard.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpainterpath.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpdfoutputintent.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpdfwriter.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpen.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpolygon.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qregion.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qrgb.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qrgba64.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qrgbafloat.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qtransform.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qabstracttextdocumentlayout.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qfont.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qfontdatabase.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qfontinfo.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qfontmetrics.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qfontvariableaxis.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qglyphrun.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qrawfont.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qstatictext.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qsyntaxhighlighter.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextcursor.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextdocument.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextdocumentfragment.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextdocumentwriter.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextformat.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextlayout.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextlist.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextobject.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextoption.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtexttable.h"
    "/tmp/qtbase-6.9.1/src/gui/util/qdesktopservices.h"
    "/tmp/qtbase-6.9.1/src/gui/util/qvalidator.h"
    "/tmp/qtbase-6.9.1/build/src/gui/qtgui-config.h"
    "/tmp/qtbase-6.9.1/src/gui/itemmodels/qstandarditemmodel.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qopenglcontext_platform.h"
    "/tmp/qtbase-6.9.1/src/gui/accessible/qaccessible.h"
    "/tmp/qtbase-6.9.1/src/gui/accessible/qaccessible_base.h"
    "/tmp/qtbase-6.9.1/src/gui/accessible/qaccessiblebridge.h"
    "/tmp/qtbase-6.9.1/src/gui/accessible/qaccessibleobject.h"
    "/tmp/qtbase-6.9.1/src/gui/accessible/qaccessibleplugin.h"
    "/tmp/qtbase-6.9.1/build/src/gui/cache_adaptor.h"
    "/tmp/qtbase-6.9.1/build/src/gui/deviceeventcontroller_adaptor.h"
    "/tmp/qtbase-6.9.1/build/src/gui/bus_interface.h"
    "/tmp/qtbase-6.9.1/build/src/gui/socket_interface.h"
    "/tmp/qtbase-6.9.1/build/src/gui/properties_interface.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qaction.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qactiongroup.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qdrag.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qkeysequence.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qshortcut.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qmovie.h"
    "/tmp/qtbase-6.9.1/src/gui/util/qundostack.h"
    "/tmp/qtbase-6.9.1/src/gui/util/qundogroup.h"
    "/tmp/qtbase-6.9.1/src/gui/itemmodels/qstandarditemmodel.h"
    "/tmp/qtbase-6.9.1/src/gui/itemmodels/qfilesystemmodel.h"
    "/tmp/qtbase-6.9.1/src/gui/vulkan/qvulkaninstance.h"
    "/tmp/qtbase-6.9.1/src/gui/vulkan/qvulkanwindow.h"
    "/tmp/qtbase-6.9.1/build/src/gui/vulkan/qvulkanfunctions.h"
    "/tmp/qtbase-6.9.1/build/include/QtGui/QtGuiDepends"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtGui/6.9.1/QtGui/private" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/src/gui/image/qabstractfileiconengine_p.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qabstractfileiconprovider_p.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qbmphandler_p.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qfonticonengine_p.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qicon_p.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qiconengine_p.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qiconloader_p.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qimage_p.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qimagepixmapcleanuphooks_p.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qimagereaderwriterhelpers_p.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qpaintengine_pic_p.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qpicture_p.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qpixmap_blitter_p.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qpixmap_raster_p.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qpixmapcache_p.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qppmhandler_p.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qxbmhandler_p.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qxpmhandler_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qcursor_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qeventpoint_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qevent_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qguiapplication_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qhighdpiscaling_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qinputdevice_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qinputdevicemanager_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qinputdevicemanager_p_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qinputmethod_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qinternalmimedata_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qkeymapper_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qoffscreensurface_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qpaintdevicewindow_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qpalette_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qpointingdevice_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qscreen_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qsessionmanager_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qstylehints_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qtguiglobal_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qwindow_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qbackingstoredefaultcompositor_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qbackingstorerhisupport_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qbezier_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qblendfunctions_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qblittable_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qcolor_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qcolorclut_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qcolormatrix_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qcolorspace_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qcolortransferfunction_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qcolortransfergeneric_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qcolortransfertable_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qcolortransform_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qcolortrc_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qcolortrclut_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qcosmeticstroker_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qcmyk_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qdatabuffer_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qdrawhelper_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qdrawhelper_x86_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qdrawingprimitive_sse2_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qdrawhelper_loongarch64_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qdrawingprimitive_lsx_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qemulationpaintengine_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qfixed_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qgrayraster_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qicc_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qimagescale_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qmath_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qmemrotate_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qoutlinemapper_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpagedpaintdevice_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpageranges_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpaintengine_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpaintengine_blitter_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpaintengine_raster_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpaintengineex_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpainter_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpainterpath_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpathclipper_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpathsimplifier_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpdf_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpen_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qpixellayout_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qrasterdefs_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qrasterizer_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qrbtree_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qrgba64_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qstroker_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qtextureglyphcache_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qtriangulatingstroker_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qtriangulator_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qvectorpath_p.h"
    "/tmp/qtbase-6.9.1/src/gui/rhi/qrhi_p.h"
    "/tmp/qtbase-6.9.1/src/gui/rhi/qrhinull_p.h"
    "/tmp/qtbase-6.9.1/src/gui/rhi/qshader_p.h"
    "/tmp/qtbase-6.9.1/src/gui/rhi/qshaderdescription_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qabstracttextdocumentlayout_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qcolrpaintgraphrenderer_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qdistancefield_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qfont_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qfontdatabase_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qfontengine_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qfontengineglyphcache_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qfontsubset_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qfragmentmap_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qglyphrun_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qinputcontrol_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qrawfont_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qstatictext_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextcursor_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextdocument_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextdocumentfragment_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextdocumentlayout_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextengine_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextformat_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtexthtmlparser_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextimagehandler_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextobject_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtexttable_p.h"
    "/tmp/qtbase-6.9.1/src/gui/util/qabstractlayoutstyleinfo_p.h"
    "/tmp/qtbase-6.9.1/src/gui/util/qastchandler_p.h"
    "/tmp/qtbase-6.9.1/src/gui/util/qgridlayoutengine_p.h"
    "/tmp/qtbase-6.9.1/src/gui/util/qhexstring_p.h"
    "/tmp/qtbase-6.9.1/src/gui/util/qktxhandler_p.h"
    "/tmp/qtbase-6.9.1/src/gui/util/qlayoutpolicy_p.h"
    "/tmp/qtbase-6.9.1/src/gui/util/qpkmhandler_p.h"
    "/tmp/qtbase-6.9.1/src/gui/util/qtexturefiledata_p.h"
    "/tmp/qtbase-6.9.1/src/gui/util/qtexturefilehandler_p.h"
    "/tmp/qtbase-6.9.1/src/gui/util/qtexturefilereader_p.h"
    "/tmp/qtbase-6.9.1/build/src/gui/qtgui-config_p.h"
    "/tmp/qtbase-6.9.1/src/gui/itemmodels/qstandarditemmodel_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qopenglcontext_p.h"
    "/tmp/qtbase-6.9.1/src/gui/opengl/qopengl_p.h"
    "/tmp/qtbase-6.9.1/src/gui/opengl/qopenglextensions_p.h"
    "/tmp/qtbase-6.9.1/src/gui/opengl/qopenglprogrambinarycache_p.h"
    "/tmp/qtbase-6.9.1/src/gui/rhi/qrhigles2_p.h"
    "/tmp/qtbase-6.9.1/src/gui/opengl/platform/egl/qeglconvenience_p.h"
    "/tmp/qtbase-6.9.1/src/gui/opengl/platform/egl/qeglstreamconvenience_p.h"
    "/tmp/qtbase-6.9.1/src/gui/opengl/platform/egl/qt_egl_p.h"
    "/tmp/qtbase-6.9.1/src/gui/accessible/qaccessiblebridgeutils_p.h"
    "/tmp/qtbase-6.9.1/src/gui/accessible/qaccessiblecache_p.h"
    "/tmp/qtbase-6.9.1/src/gui/accessible/linux/atspiadaptor_p.h"
    "/tmp/qtbase-6.9.1/src/gui/accessible/linux/dbusconnection_p.h"
    "/tmp/qtbase-6.9.1/src/gui/accessible/linux/qspi_constant_mappings_p.h"
    "/tmp/qtbase-6.9.1/src/gui/accessible/linux/qspi_struct_marshallers_p.h"
    "/tmp/qtbase-6.9.1/src/gui/accessible/linux/qspiaccessiblebridge_p.h"
    "/tmp/qtbase-6.9.1/src/gui/accessible/linux/qspiapplicationadaptor_p.h"
    "/tmp/qtbase-6.9.1/src/gui/accessible/linux/qspidbuscache_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qaction_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qactiongroup_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qdnd_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qshapedpixmapdndwindow_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qsimpledrag_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qkeysequence_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qshortcut_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qshortcutmap_p.h"
    "/tmp/qtbase-6.9.1/src/gui/image/qpnghandler_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qharfbuzzng_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextodfwriter_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextmarkdownimporter_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qtextmarkdownwriter_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qcssutil_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qcssparser_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/freetype/qfontengine_ft_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/freetype/qfreetypefontdatabase_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/unix/qgenericunixfontdatabase_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/unix/qfontconfigdatabase_p.h"
    "/tmp/qtbase-6.9.1/src/gui/text/unix/qfontenginemultifontconfig_p.h"
    "/tmp/qtbase-6.9.1/src/gui/util/qundostack_p.h"
    "/tmp/qtbase-6.9.1/src/gui/opengl/platform/unix/qglxconvenience_p.h"
    "/tmp/qtbase-6.9.1/src/gui/opengl/platform/egl/qeglpbuffer_p.h"
    "/tmp/qtbase-6.9.1/src/gui/opengl/platform/egl/qeglplatformcontext_p.h"
    "/tmp/qtbase-6.9.1/src/gui/itemmodels/qstandarditemmodel_p.h"
    "/tmp/qtbase-6.9.1/src/gui/itemmodels/qfileinfogatherer_p.h"
    "/tmp/qtbase-6.9.1/src/gui/itemmodels/qfilesystemmodel_p.h"
    "/tmp/qtbase-6.9.1/src/gui/rhi/qrhivulkan_p.h"
    "/tmp/qtbase-6.9.1/src/gui/vulkan/qbasicvulkanplatforminstance_p.h"
    "/tmp/qtbase-6.9.1/src/gui/vulkan/qvulkandefaultinstance_p.h"
    "/tmp/qtbase-6.9.1/src/gui/vulkan/qvulkaninstance_p.h"
    "/tmp/qtbase-6.9.1/src/gui/vulkan/qvulkanwindow_p.h"
    "/tmp/qtbase-6.9.1/build/src/gui/vulkan/qvulkanfunctions_p.h"
    "/tmp/qtbase-6.9.1/src/gui/platform/unix/qgenericunixeventdispatcher_p.h"
    "/tmp/qtbase-6.9.1/src/gui/platform/unix/qunixeventdispatcher_qpa_p.h"
    "/tmp/qtbase-6.9.1/src/gui/platform/unix/qeventdispatcher_glib_p.h"
    "/tmp/qtbase-6.9.1/src/gui/platform/unix/qdesktopunixservices_p.h"
    "/tmp/qtbase-6.9.1/src/gui/platform/unix/qtx11extras_p.h"
    "/tmp/qtbase-6.9.1/src/gui/platform/unix/qgenericunixthemes_p.h"
    "/tmp/qtbase-6.9.1/src/gui/platform/unix/dbusmenu/qdbusmenuadaptor_p.h"
    "/tmp/qtbase-6.9.1/src/gui/platform/unix/dbusmenu/qdbusmenubar_p.h"
    "/tmp/qtbase-6.9.1/src/gui/platform/unix/dbusmenu/qdbusmenuconnection_p.h"
    "/tmp/qtbase-6.9.1/src/gui/platform/unix/dbusmenu/qdbusmenuregistrarproxy_p.h"
    "/tmp/qtbase-6.9.1/src/gui/platform/unix/dbusmenu/qdbusmenutypes_p.h"
    "/tmp/qtbase-6.9.1/src/gui/platform/unix/dbusmenu/qdbusplatformmenu_p.h"
    "/tmp/qtbase-6.9.1/src/gui/platform/unix/dbustray/qdbustrayicon_p.h"
    "/tmp/qtbase-6.9.1/src/gui/platform/unix/dbustray/qdbustraytypes_p.h"
    "/tmp/qtbase-6.9.1/src/gui/platform/unix/dbustray/qstatusnotifieritemadaptor_p.h"
    "/tmp/qtbase-6.9.1/src/gui/platform/unix/dbustray/qxdgnotificationproxy_p.h"
    "/tmp/qtbase-6.9.1/src/gui/platform/unix/qxkbcommon_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qdrawhelper_neon_p.h"
    "/tmp/qtbase-6.9.1/src/gui/util/qedidparser_p.h"
    "/tmp/qtbase-6.9.1/src/gui/util/qedidvendortable_p.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtGui/6.9.1/QtGui/qpa" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/src/gui/image/qplatformpixmap.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformclipboard.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformcursor.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformdialoghelper.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformgraphicsbuffer.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformgraphicsbufferhelper.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatforminputcontext.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatforminputcontext_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatforminputcontextfactory_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatforminputcontextplugin_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformintegration.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformintegrationfactory_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformintegrationplugin.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformkeymapper.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformmenu.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformmenu_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformnativeinterface.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformoffscreensurface.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformopenglcontext.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformscreen.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformscreen_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformservices.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformsessionmanager.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformsharedgraphicscache.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformsurface.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformsystemtrayicon.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformtheme.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformtheme_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformthemefactory_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformthemeplugin.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformwindow.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformwindow_p.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qwindowsysteminterface.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qwindowsysteminterface_p.h"
    "/tmp/qtbase-6.9.1/src/gui/painting/qplatformbackingstore.h"
    "/tmp/qtbase-6.9.1/src/gui/text/qplatformfontdatabase.h"
    "/tmp/qtbase-6.9.1/src/gui/accessible/qplatformaccessibility.h"
    "/tmp/qtbase-6.9.1/src/gui/kernel/qplatformdrag.h"
    "/tmp/qtbase-6.9.1/src/gui/vulkan/qplatformvulkaninstance.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtGui/6.9.1/QtGui/rhi" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/src/gui/rhi/qrhi.h"
    "/tmp/qtbase-6.9.1/src/gui/rhi/qrhi_platform.h"
    "/tmp/qtbase-6.9.1/src/gui/rhi/qshader.h"
    "/tmp/qtbase-6.9.1/src/gui/rhi/qshaderdescription.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/mkspecs/modules" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_gui.pri"
    "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_gui_private.pri"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/pkgconfig/Qt6Gui.pc")
endif()


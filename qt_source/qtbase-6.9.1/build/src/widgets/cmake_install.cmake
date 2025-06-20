# Install script for directory: /tmp/qtbase-6.9.1/src/widgets

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./metatypes" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/widgets/meta_types/qt6widgets_release_metatypes.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Widgets" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Widgets/Qt6WidgetsConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Widgets/Qt6WidgetsConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Widgets/Qt6WidgetsConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Widgets" TYPE FILE FILES "/tmp/qtbase-6.9.1/src/widgets/Qt6WidgetsMacros.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6WidgetsPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6WidgetsPrivate/Qt6WidgetsPrivateConfig.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6WidgetsPrivate/Qt6WidgetsPrivateConfigVersion.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6WidgetsPrivate/Qt6WidgetsPrivateConfigVersionImpl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Widgets.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Widgets.so.6"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "\$ORIGIN")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/tmp/qtbase-6.9.1/build/lib/libQt6Widgets.so.6.9.1"
    "/tmp/qtbase-6.9.1/build/lib/libQt6Widgets.so.6"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Widgets.so.6.9.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Widgets.so.6"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Widgets.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Widgets.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Widgets.so"
         RPATH "\$ORIGIN")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/tmp/qtbase-6.9.1/build/lib/libQt6Widgets.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Widgets.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Widgets.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Widgets.so"
         OLD_RPATH "/tmp/qtbase-6.9.1/build/lib:"
         NEW_RPATH "\$ORIGIN")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/tmp/qtbase-6.9.1/build/libexec/qt-internal-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQt6Widgets.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Widgets/Qt6WidgetsTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Widgets/Qt6WidgetsTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/widgets/CMakeFiles/Export/lib/cmake/Qt6Widgets/Qt6WidgetsTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Widgets/Qt6WidgetsTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Widgets/Qt6WidgetsTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Widgets" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/widgets/CMakeFiles/Export/lib/cmake/Qt6Widgets/Qt6WidgetsTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Widgets" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/widgets/CMakeFiles/Export/lib/cmake/Qt6Widgets/Qt6WidgetsTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Widgets" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Widgets/Qt6WidgetsVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Widgets/Qt6WidgetsVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Widgets" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6WidgetsPrivate/Qt6WidgetsPrivateTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6WidgetsPrivate/Qt6WidgetsPrivateTargets.cmake"
         "/tmp/qtbase-6.9.1/build/src/widgets/CMakeFiles/Export/lib/cmake/Qt6WidgetsPrivate/Qt6WidgetsPrivateTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6WidgetsPrivate/Qt6WidgetsPrivateTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6WidgetsPrivate/Qt6WidgetsPrivateTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6WidgetsPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/src/widgets/CMakeFiles/Export/lib/cmake/Qt6WidgetsPrivate/Qt6WidgetsPrivateTargets.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6WidgetsPrivate" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6WidgetsPrivate/Qt6WidgetsPrivateVersionlessAliasTargets.cmake"
    "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6WidgetsPrivate/Qt6WidgetsPrivateVersionlessTargets.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6WidgetsPrivate" TYPE FILE FILES
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modules" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/modules/Widgets.json")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_html_docs_Widgetsx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc/qtwidgets" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/doc/qtwidgets/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_qch_docs_Widgetsx")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/doc/qtwidgets.qch")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6Widgets" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6Widgets/Qt6WidgetsAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Qt6WidgetsPrivate" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/cmake/Qt6WidgetsPrivate/Qt6WidgetsPrivateAdditionalTargetInfo.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtWidgets" TYPE DIRECTORY FILES "/tmp/qtbase-6.9.1/build/include/QtWidgets/.syncqt_staging/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtWidgets" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/include/QtWidgets/qtwidgetsexports.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qfileiconprovider.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qapplication.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qboxlayout.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qgesture.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qgesturerecognizer.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qgridlayout.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qlayout.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qlayoutitem.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qrhiwidget.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qsizepolicy.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qstackedlayout.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qtestsupport_widgets.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qtwidgetsglobal.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qwidget.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qcommonstyle.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qdrawutil.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qproxystyle.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qstyle.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qstylefactory.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qstyleoption.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qstylepainter.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qstyleplugin.h"
    "/tmp/qtbase-6.9.1/src/widgets/util/qcolormap.h"
    "/tmp/qtbase-6.9.1/src/widgets/util/qsystemtrayicon.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qabstractscrollarea.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qfocusframe.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qframe.h"
    "/tmp/qtbase-6.9.1/build/src/widgets/qtwidgets-config.h"
    "/tmp/qtbase-6.9.1/src/widgets/effects/qgraphicseffect.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qaction.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qactiongroup.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qwidgetaction.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qformlayout.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qshortcut.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qtooltip.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qwhatsthis.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qabstractbutton.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qabstractslider.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qbuttongroup.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qcalendarwidget.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qcheckbox.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qcombobox.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qcommandlinkbutton.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qdatetimeedit.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qdial.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qdockwidget.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qfontcombobox.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qgroupbox.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qkeysequenceedit.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qlabel.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qlcdnumber.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qlineedit.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qmainwindow.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qmdiarea.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qmdisubwindow.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qmenu.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qmenubar.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qprogressbar.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qpushbutton.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qradiobutton.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qdialogbuttonbox.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qrubberband.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qscrollarea.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qscrollbar.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qsizegrip.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qslider.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qabstractspinbox.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qspinbox.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qsplashscreen.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qsplitter.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qstackedwidget.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qstatusbar.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qtabbar.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qplaintextedit.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qtextedit.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qtextbrowser.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qtabwidget.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qtoolbar.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qtoolbox.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qtoolbutton.h"
    "/tmp/qtbase-6.9.1/src/widgets/dialogs/qcolordialog.h"
    "/tmp/qtbase-6.9.1/src/widgets/dialogs/qdialog.h"
    "/tmp/qtbase-6.9.1/src/widgets/dialogs/qerrormessage.h"
    "/tmp/qtbase-6.9.1/src/widgets/dialogs/qfiledialog.h"
    "/tmp/qtbase-6.9.1/src/widgets/dialogs/qfilesystemmodel.h"
    "/tmp/qtbase-6.9.1/src/widgets/dialogs/qfontdialog.h"
    "/tmp/qtbase-6.9.1/src/widgets/dialogs/qinputdialog.h"
    "/tmp/qtbase-6.9.1/src/widgets/dialogs/qmessagebox.h"
    "/tmp/qtbase-6.9.1/src/widgets/dialogs/qprogressdialog.h"
    "/tmp/qtbase-6.9.1/src/widgets/dialogs/qwizard.h"
    "/tmp/qtbase-6.9.1/src/widgets/accessible/qaccessiblewidget.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qabstractitemdelegate.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qabstractitemview.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qheaderview.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qitemdelegate.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qitemeditorfactory.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qstyleditemdelegate.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qcolumnview.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qdatawidgetmapper.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qlistview.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qlistwidget.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qtableview.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qtablewidget.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qtreeview.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qtreewidget.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qtreewidgetitemiterator.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicsanchorlayout.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicsgridlayout.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicsitem.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicslayout.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicslayoutitem.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicslinearlayout.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicsproxywidget.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicsscene.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicssceneevent.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicstransform.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicsview.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicswidget.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicsitemanimation.h"
    "/tmp/qtbase-6.9.1/src/widgets/util/qcompleter.h"
    "/tmp/qtbase-6.9.1/src/widgets/util/qscroller.h"
    "/tmp/qtbase-6.9.1/src/widgets/util/qscrollerproperties.h"
    "/tmp/qtbase-6.9.1/src/widgets/util/qundostack.h"
    "/tmp/qtbase-6.9.1/src/widgets/util/qundogroup.h"
    "/tmp/qtbase-6.9.1/src/widgets/util/qundoview.h"
    "/tmp/qtbase-6.9.1/build/include/QtWidgets/QtWidgetsDepends"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtWidgets/6.9.1/QtWidgets/private" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qfileiconprovider_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qapplication_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qgesture_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qgesturemanager_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qlayout_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qlayoutengine_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qrhiwidget_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qstandardgestures_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qtwidgetsglobal_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qwidget_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qwidgetrepaintmanager_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qwidgetwindow_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qwindowcontainer_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qcommonstyle_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qcommonstylepixmaps_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qpixmapstyle_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qpixmapstyle_p_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qproxystyle_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qstyle_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qstylehelper_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/util/qsystemtrayicon_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qabstractscrollarea_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qframe_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qwidgetanimator_p.h"
    "/tmp/qtbase-6.9.1/build/src/widgets/qtwidgets-config_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/effects/qgraphicseffect_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/effects/qpixmapfilter_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qaction_widgets_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/kernel/qwidgetaction_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qstyleanimation_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qstylesheetstyle_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qwindowsstyle_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qwindowsstyle_p_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qfusionstyle_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/styles/qfusionstyle_p_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qabstractbutton_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qabstractslider_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qbuttongroup_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qcombobox_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qdatetimeedit_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qdockarealayout_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qdockwidget_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qeffects_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qkeysequenceedit_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qlabel_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qlineedit_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qwidgetlinecontrol_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qmainwindowlayout_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qmdiarea_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qmdisubwindow_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qmenu_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qmenubar_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qpushbutton_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qwidgetresizehandler_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qdialogbuttonbox_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qscrollarea_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qscrollbar_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qabstractspinbox_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qsplitter_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qtabbar_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qplaintextedit_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qtextedit_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qtoolbar_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qtoolbararealayout_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qtoolbarlayout_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qtoolbarseparator_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qtoolbarextension_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qwidgettextcontrol_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/widgets/qwidgettextcontrol_p_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/dialogs/qdialog_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/dialogs/qfiledialog_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/dialogs/qsidebar_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/dialogs/qfontdialog_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/dialogs/qfscompleter_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/accessible/complexwidgets_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/accessible/qaccessiblemenu_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/accessible/qaccessiblewidgetfactory_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/accessible/qaccessiblewidgets_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/accessible/rangecontrols_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/accessible/simplewidgets_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/accessible/itemviews_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qabstractitemdelegate_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qabstractitemview_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qbsptree_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qheaderview_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qitemeditorfactory_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qwidgetitemdata_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qcolumnview_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qcolumnviewgrip_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qlistview_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qlistwidget_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qtableview_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qtablewidget_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qtreeview_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qtreewidget_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/itemviews/qtreewidgetitemiterator_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraph_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicsanchorlayout_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicsgridlayoutengine_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicsitem_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicslayout_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicslayoutitem_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicslayoutstyleinfo_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicsproxywidget_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicsscene_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicsscene_bsp_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicsscenebsptreeindex_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicssceneindex_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicsscenelinearindex_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicstransform_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicsview_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qgraphicswidget_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/graphicsview/qsimplex_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/util/qcompleter_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/util/qflickgesture_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/util/qscroller_p.h"
    "/tmp/qtbase-6.9.1/src/widgets/util/qscrollerproperties_p.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/mkspecs/modules" TYPE FILE FILES
    "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_widgets.pri"
    "/tmp/qtbase-6.9.1/build/mkspecs/modules/qt_lib_widgets_private.pri"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/tmp/qtbase-6.9.1/build/lib/pkgconfig/Qt6Widgets.pc")
endif()


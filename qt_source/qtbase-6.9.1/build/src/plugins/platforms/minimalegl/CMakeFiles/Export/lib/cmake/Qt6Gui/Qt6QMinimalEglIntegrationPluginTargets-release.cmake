#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::QMinimalEglIntegrationPlugin" for configuration "Release"
set_property(TARGET Qt6::QMinimalEglIntegrationPlugin APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::QMinimalEglIntegrationPlugin PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/plugins/platforms/libqminimalegl.so"
  IMPORTED_NO_SONAME_RELEASE "TRUE"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::QMinimalEglIntegrationPlugin )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::QMinimalEglIntegrationPlugin "${_IMPORT_PREFIX}/plugins/platforms/libqminimalegl.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

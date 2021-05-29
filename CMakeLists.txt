cmake_minimum_required(VERSION 3.15)

# Set the project name to your project name, my project isn't very descriptive
project(
  OnKiGenerics
  VERSION 0.1.0
  LANGUAGES CXX)
include(${ONKI_CMAKE_FILES_PATH}/StandardProjectSettings.cmake)
include(${ONKI_CMAKE_FILES_PATH}/PreventInSourceBuilds.cmake)

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
  option(ENABLE_BUILD_WITH_TIME_TRACE
         "Enable -ftime-trace to generate time tracing .json files on clang"
         OFF)
  if(ENABLE_BUILD_WITH_TIME_TRACE)
    add_compile_definitions(project_options INTERFACE -ftime-trace)
  endif()
endif()

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# enable cache system
include(${ONKI_CMAKE_FILES_PATH}/Cache.cmake)

# standard compiler warnings
include(${ONKI_CMAKE_FILES_PATH}/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# sanitizer options if supported by compiler
include(${ONKI_CMAKE_FILES_PATH}/Sanitizers.cmake)
enable_sanitizers(project_options)

option(ENABLE_BENCHMARK "Enable Benchmark Builds" OFF)
option(ENABLE_TESTS "Enable Test Builds" ON)

# enable doxygen
include(${ONKI_CMAKE_FILES_PATH}/Doxygen.cmake)
enable_doxygen()

# allow for static analysis options
include(${ONKI_CMAKE_FILES_PATH}/StaticAnalyzers.cmake)

if(ENABLE_TESTS)
  enable_testing()
  add_subdirectory(test)
endif()
add_library(OnKiGenerics INTERFACE)
add_library(OnKiGenerics::OnKiGenerics ALIAS OnKiGenerics)
target_include_directories(
  OnKiGenerics INTERFACE $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
                     $<INSTALL_INTERFACE:include> # <prefix>/include
)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)
set(OnKiGenerics_CMAKE_DIR
    ${CMAKE_INSTALL_LIBDIR}/cmake/OnKiGenerics
    CACHE
      STRING
      "Installation directory for cmake files, a relative path that will be joined with ${CMAKE_INSTALL_PREFIX} or an absolute path."
)
set(version_config ${CMAKE_CURRENT_BINARY_DIR}/onkigenerics-config-version.cmake)
set(project_config ${CMAKE_CURRENT_BINARY_DIR}/onkigenerics-config.cmake)
set(targets_export_name onkigenerics-targets)

message(STATUS "CMAKE_INSTALL_LIBDIR: ${CMAKE_INSTALL_LIBDIR}")

install(
  TARGETS OnKiGenerics
  EXPORT ${targets_export_name}
  LIBRARY DESTINATION ${OnKiGenerics_LIB_DIR}
  ARCHIVE DESTINATION ${OnKiGenerics_LIB_DIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

write_basic_package_version_file(
  ${version_config}
  VERSION ${OnKiGenerics_VERSION}
  COMPATIBILITY AnyNewerVersion)

configure_package_config_file(
  ${ONKI_CMAKE_FILES_PATH}/project-config.cmake.in ${project_config}
  INSTALL_DESTINATION ${OnKiGenerics_CMAKE_DIR})

export(
  TARGETS OnKiGenerics
  NAMESPACE OnKiGenerics::
  FILE ${CMAKE_CURRENT_BINARY_DIR}/${targets_export_name}.cmake)

# Install version, config and target files.
install(FILES ${project_config} ${version_config}
        DESTINATION ${OnKiGenerics_CMAKE_DIR})

install(
  EXPORT ${targets_export_name}
  DESTINATION ${OnKiGenerics_CMAKE_DIR}
  NAMESPACE OnKiGenerics::)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/OnKiGenerics
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

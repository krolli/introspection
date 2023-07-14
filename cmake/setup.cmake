# file(ARCHIVE_EXTRACT ...) requires 3.18
cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

function(enf_install_package name)
  set(options "")
  set(oneValueArgs URL URL_HASH DOWNLOAD_PATH INSTALL_PATH)
  set(multiValueArgs "")
  cmake_parse_arguments(PARSE_ARGV 0 PKG "${options}" "${oneValueArgs}" "${multiValueArgs}")

  foreach(arg ${oneValueArgs})
    if(NOT DEFINED PKG_${arg})
      message(FATAL_ERROR "${arg} not specified in call to enf_install_package.")
    endif()
  endforeach()

  if(NOT EXISTS "${PKG_INSTALL_PATH}")
    if(NOT EXISTS "${PKG_DOWNLOAD_PATH}")
      message(STATUS "Downloading '${PKG_URL}' to '${PKG_DOWNLOAD_PATH}'")
      file(DOWNLOAD "${PKG_URL}" "${PKG_DOWNLOAD_PATH}" EXPECTED_HASH "${PKG_URL_HASH}")
    endif()
    message(STATUS "Extracting '${PKG_DOWNLOAD_PATH}' to '${PKG_INSTALL_PATH}'")
    file(ARCHIVE_EXTRACT INPUT "${PKG_DOWNLOAD_PATH}" DESTINATION "${PKG_INSTALL_PATH}")
  endif()
  string(TOLOWER ${name} lowercaseName)
  set(${lowercaseName}_SOURCE_DIR "${PKG_INSTALL_PATH}" PARENT_SCOPE)
endfunction()

# Variables must be defined before `-P` parameter.
# `cmake -D ENF_SDK_PATH=<some-path> -P <path-to-this-file>`
if(ENF_SDK_PATH)
  if(IS_ABSOLUTE ENF_SDK_PATH)
    set(sdkPath "${ENF_SDK_PATH}")
  else()
    set(sdkPath "${CMAKE_SOURCE_DIR}/${ENF_SDK_PATH}")
  endif()
else()
  message(FATAL_ERROR "ENF_SDK_PATH is not specified. Specify it using `-D ENF_SDK_PATH=<path>`")
endif()

set(downloadPath "${sdkPath}/download")
set(installPath  "${sdkPath}/install")

# include(FetchContent)
# FetchContent_Populate(
#   qt
#   URL          "file://e:/web-repo/qt-5.15.2-msvc2015_64.zip"
#   URL_HASH     SHA256=88bba57fc2b2ad0d5e0165fd3fec06610453812858a8085ae3ff4e5071b8cdb9
#   SOURCE_DIR   "${installPath}/qt-5.15.2-msvc2015_64"
#   BINARY_DIR   "${installPath}/qt-5.15.2-msvc2015_64-bin"
#   SUBBUILD_DIR "${installPath}/qt-5.15.2-msvc2015_64-subbuild"
# )
enf_install_package(
  qt
  URL           "file://e:/web-repo/qt-5.15.2-msvc2015_64.zip"
  URL_HASH      SHA256=88bba57fc2b2ad0d5e0165fd3fec06610453812858a8085ae3ff4e5071b8cdb9
  DOWNLOAD_PATH "${downloadPath}/qt-5.15.2-msvc2015_64.zip"
  INSTALL_PATH  "${installPath}/qt-5.15.2-msvc2015_64"
)

message(STATUS "qt_SOURCE_DIR = ${qt_SOURCE_DIR}")

if(NOT ${CMAKE_HOST_SYSTEM_NAME} EQUAL "Windows")
    # Setting CMAKE_SYSTEM_NAME will also set CMAKE_CROSSCOMPILING=TRUE, which
    # we only want to do when actually cross-compiling (host and target systems
    # are different).
    set(CMAKE_SYSTEM_NAME Windows)
endif()
set(CMAKE_SYSTEM_PROCESSOR AMD64)
set(CMAKE_SYSTEM_VERSION   10.0.19041.0)

# Use only CMAKE_CURRENT_LIST_DIR for specifying relative paths. It refers
# to directory where toolchain file is located (so toolchains in repository
# will be specified relative to this dir).
set(msvcVer "14.16.27023")
set(msvcDir "C:/Program Files (x86)/Microsoft Visual Studio/2017/Professional/VC/Tools/MSVC")
set(msvcDirTools "${msvcDir}/${msvcVer}/bin/Hostx64/x64")
set(winkitDir "C:/Program Files (x86)/Windows Kits")
set(winkitDirInc "${winkitDir}/10/include/${CMAKE_SYSTEM_VERSION}")
set(winkitDirBin "${winkitDir}/10/bin/${CMAKE_SYSTEM_VERSION}")
set(winkitDirLib "${winkitDir}/10/lib/${CMAKE_SYSTEM_VERSION}")

set(CMAKE_RC_COMPILER "${winkitDirBin}/x64/rc.exe")
set(CMAKE_MT "${winkitDirBin}/x64/mt.exe")

set(CMAKE_C_COMPILER "${msvcDirTools}/cl.exe")
set(CMAKE_C_STANDARD_INCLUDE_DIRECTORIES
    "${msvcDir}/${msvcVer}/ATLMFC/include"
    "${msvcDir}/${msvcVer}/include"
    "${winkitDir}/NETFXSDK/4.6.1/include/um"
    "${winkitDirInc}/ucrt"
    "${winkitDirInc}/shared"
    "${winkitDirInc}/um"
    "${winkitDirInc}/winrt"
    "${winkitDirInc}/cppwinrt"
)
set(CMAKE_C_STANDARD_LIBRARIES
    "${winkitDirLib}/um/x64/advapi32.lib"
    "${winkitDirLib}/um/x64/comdlg32.lib"
    "${winkitDirLib}/um/x64/gdi32.lib"
    "${winkitDirLib}/um/x64/kernel32.lib"
    "${winkitDirLib}/um/x64/ole32.lib"
    "${winkitDirLib}/um/x64/oleaut32.lib"
    "${winkitDirLib}/um/x64/shell32.lib"
    "${winkitDirLib}/um/x64/user32.lib"
    "${winkitDirLib}/um/x64/uuid.lib"
    "${winkitDirLib}/um/x64/winspool.lib"
)

set(CMAKE_CXX_COMPILER ${CMAKE_C_COMPILER})

set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_C_STANDARD_INCLUDE_DIRECTORIES})
set(CMAKE_CXX_STANDARD_LIBRARIES ${CMAKE_C_STANDARD_LIBRARIES})

string(JOIN " " linkerFlagsInit
    \"/LIBPATH:${msvcDir}/${msvcVer}/ATLMFC/lib/x64\"
    \"/LIBPATH:${msvcDir}/${msvcVer}/lib/x64\"
    \"/LIBPATH:${winkitDir}/NETFXSDK/4.6.1/lib/um/x64\"
    \"/LIBPATH:${winkitDirLib}/ucrt/x64\"
    \"/LIBPATH:${winkitDirLib}/um/x64\"
)

set(CMAKE_EXE_LINKER_FLAGS_INIT "${linkerFlagsInit}")
set(CMAKE_MODULE_LINKER_FLAGS_INIT "${linkerFlagsInit}")
set(CMAKE_SHARED_LINKER_FLAGS_INIT "${linkerFlagsInit}")

foreach(config ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${config} configUpper)
    set("CMAKE_EXE_LINKER_FLAGS_${configUpper}_INIT" "${linkerFlagsInit}")
    set("CMAKE_MODULE_LINKER_FLAGS_${configUpper}_INIT" "${linkerFlagsInit}")
    set("CMAKE_SHARED_LINKER_FLAGS_${configUpper}_INIT" "${linkerFlagsInit}")
endforeach()

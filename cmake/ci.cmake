cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

set(rootDir "${CMAKE_CURRENT_LIST_DIR}/..")

# execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
#     COMMAND ${CMAKE_COMMAND} -E rm -rf build
# )

# VS + cl
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} -G "Visual Studio 15 2017" -S src -B build/msvc-x64
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/msvc-x64
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/msvc-x64 --config Debug
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/msvc-x64 --config Release
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/msvc-x64 --config MinSizeRel
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/msvc-x64 --config RelWithDebInfo
)

# Ninja + cl
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} -G "Ninja" -S src -B build/msvc-x64-toolchain
        --toolchain "${CMAKE_CURRENT_LIST_DIR}/toolchain.vs2017-windows.cmake"
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/msvc-x64-toolchain
)

# Ninja(cfg) + cl
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} -G "Ninja Multi-Config" -S src -B build/msvc-x64-toolchain-cfg
        --toolchain "${CMAKE_CURRENT_LIST_DIR}/toolchain.vs2017-windows.cmake"
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/msvc-x64-toolchain-cfg
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/msvc-x64-toolchain-cfg --config Debug
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/msvc-x64-toolchain-cfg --config Release
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/msvc-x64-toolchain-cfg --config RelWithDebInfo
)

# Ninja + clang-cl
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} -G "Ninja" -S src -B build/llvm-msvc-x64-toolchain
        --toolchain "${CMAKE_CURRENT_LIST_DIR}/toolchain.llvm-msvc-windows.cmake"
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/llvm-msvc-x64-toolchain
)

# Ninja(cfg) + clang-cl
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} -G "Ninja Multi-Config" -S src -B build/llvm-msvc-x64-toolchain-cfg
        --toolchain "${CMAKE_CURRENT_LIST_DIR}/toolchain.llvm-msvc-windows.cmake"
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/llvm-msvc-x64-toolchain-cfg
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/llvm-msvc-x64-toolchain-cfg --config Debug
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/llvm-msvc-x64-toolchain-cfg --config Release
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/llvm-msvc-x64-toolchain-cfg --config RelWithDebInfo
)

# Ninja + clang
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} -G "Ninja" -S src -B build/llvm-x64-toolchain
        --toolchain "${CMAKE_CURRENT_LIST_DIR}/toolchain.llvm-windows.cmake"
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/llvm-x64-toolchain
)

# Ninja(cfg) + clang
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} -G "Ninja Multi-Config" -S src -B build/llvm-x64-toolchain-cfg
        --toolchain "${CMAKE_CURRENT_LIST_DIR}/toolchain.llvm-windows.cmake"
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/llvm-x64-toolchain-cfg
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/llvm-x64-toolchain-cfg --config Debug
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/llvm-x64-toolchain-cfg --config Release
)
execute_process(WORKING_DIRECTORY "${rootDir}" COMMAND_ECHO STDOUT
    COMMAND ${CMAKE_COMMAND} --build build/llvm-x64-toolchain-cfg --config RelWithDebInfo
)

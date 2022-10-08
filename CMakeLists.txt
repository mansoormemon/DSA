if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       Create a separate directory for build files.")
endif()

cmake_minimum_required(VERSION 3.16)

if("${CMAKE_VERSION}" VERSION_LESS 3.21)
    cmake_policy(VERSION "${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}")
else()
    cmake_policy(VERSION 3.21)
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RELEASE")
endif()

project(DSA
        DESCRIPTION "Data Structures & Algorithms."
        LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    add_definitions("-Wall -Wextra")
elseif(CMAKE_C_COMPILER_ID MATCHES "MSVC")
    add_definitions("/W4")
endif()

add_subdirectory("src")

message("
--------------------------------
${CMAKE_PROJECT_NAME} BUILD SUMMARY:
--------------------------------
PLATFORM:       ${CMAKE_SYSTEM_NAME}
CMAKE_VERSION:  ${CMAKE_VERSION}
PROJECT:        ${CMAKE_PROJECT_NAME}
LANGUAGE:       C${CMAKE_C_STANDARD}
BUILD_TYPE:     ${CMAKE_BUILD_TYPE}
INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}
COMPILER:       ${CMAKE_C_COMPILER_ID}
MAKE_PROGRAM:   ${CMAKE_MAKE_PROGRAM}
--------------------------------
")

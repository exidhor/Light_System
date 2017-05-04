cmake_minimum_required(VERSION 3.1)

project(DarkAdventure)

# Variables
# The version number.
set(GAME_VERSION_MAJOR 0)
set(GAME_VERSION_MINOR 1)
set(GAME_VERSION_PATCH 0)

# File and directories
set(PROJECT_BIN bin)
set(PROJECT_RES res)
set(PROJECT_CMAKE_CONFIG cmake/Config.cmake)

set(DEBUG_FLAGS "-Wall -g")
set(RELEASE_FLAGS "-O2")
set(COMPILER_FLAGS "-std=c++11")

# CMake build script
# Checking the plateforme
if(WIN32)
    set(PLATEFORME WINDOWS)
elseif(UNIX)
    set(PLATEFORME UNIX)
else()
    set(PLATEFORME NOT_SUPPORTED)
    message(FATAL_ERROR "This plateforme is currently not supported")
endif()

# Checking project structure
if(NOT IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_BIN}/)
    file(MAKE_DIRECTORY ${PROJECT_BIN})
    message(WARNING "Bin directory created")
endif()

if(NOT IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_RES}/)
    file(MAKE_DIRECTORY ${PROJECT_RES})
    message(WARNING "Res directory created")
endif()

# TODO : add the folder Debug and Release (?)
# CMAKE_BUILD_TYPE

# Checking Config.cmake file
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_CMAKE_CONFIG})
    file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_CMAKE_CONFIG} "set(SPECIFIC_SFML_PATH \"C:/../SFML | /home/../SFML\")")
    message(WARNING "Config.cmake file created")
    message(WARNING "SPECIFIC_SFML_PATH in Config.cmake need to be modified to find the SFML")
endif()

include(${PROJECT_CMAKE_CONFIG})

# Writing default messages
message(STATUS "Detected Plateforme : ${PLATEFORME}")
message(STATUS "Game version ${GAME_VERSION_MAJOR}.${GAME_VERSION_MINOR}.${GAME_VERSION_PATCH}")

# Project settings
set(CMAKE_CXX_FLAGS_DEBUG "${COMPILER_FLAGS} ${DEBUG_FLAGS}" CACHE STRING "release flags" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE "${COMPILER_FLAGS} ${RELEASE_FLAGS}" CACHE STRING "debug flags" FORCE)

# Global useful variables
set(EXENAME_RELEASE DarkAdventure_REL)
set(EXENAME_DEBUG   DarkAdventure_DBG)

if(NOT COMPILATION_MODE)
    message(STATUS "(Warning) : No argument is specified, debug by default")
    set(COMPILATION_MODE "DEBUG")
endif()

if(${COMPILATION_MODE} STREQUAL "RELEASE")
    message(STATUS "Compilation mode : RELEASE MODE")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}" CACHE STRING "compile flags" FORCE)

    if(PLATEFORME STREQUAL "WINDOWS")
        set(EXENAME ${EXENAME_RELEASE})

    elseif(PLATEFORME STREQUAL "LINUX")
        set(EXENAME ${EXENAME_RELEASE})

    endif()

    set(SFML_LIB ${SFML_LIB_REL})
    message(STATUS "Executable name : ${EXENAME}")

else()
    message(STATUS "Compilation mode : DEBUG MODE")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}" CACHE STRING "compile flags" FORCE)

    set(SFML_LIB ${SFML_LIB_DBG})

    message(STATUS "Executable name : ${EXENAME}")
endif()

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
message(STATUS "Output  path : ${CMAKE_SOURCE_DIR}/bin")

# include search path
include_directories(
        Project_Source/include
        ${SPECIFIC_SFML_INCLUDE_PATH})

# Adding sub directories
# Sources directories
add_subdirectory(Project_Source/src)
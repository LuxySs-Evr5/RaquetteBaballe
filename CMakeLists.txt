cmake_minimum_required(VERSION 3.10)

project(raquette-baballe VERSION 1.0.1 LANGUAGES CXX)

# Options
option(BUILD_STATIC "Link standard libs statically" OFF)
option(BUILD_TESTS "Build unit tests" ON)

# Export compile_commands.json for LSPs
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# C++ standard (easily modifiable)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# Static linking (cross-platform)
if(BUILD_STATIC)
    message(STATUS "Static linking enabled")
    if(MSVC)
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    else()
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
    endif()
endif()

# Compilation flags
if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -pedantic)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(-g -fsanitize=address,undefined)
        add_link_options(-fsanitize=address,undefined)
    else()
        add_compile_options(-O3 -DNDEBUG)
    endif()
endif()

# Define the minimum Windows version for compatibility
if(WIN32)
    add_compile_definitions(_WIN32_WINNT=0x0600)
endif()

# Source and include directories
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Main executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories 
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Installation
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

# Allegro dependency management
include(FetchContent)
FetchContent_Declare(
    allegro
    GIT_REPOSITORY https://github.com/liballeg/allegro5.git
    GIT_TAG        5.2.10
)

find_package(allegro QUIET)
if (NOT allegro_FOUND)
    message(STATUS "Allegro not found, fetching from repository...")

    set(WANT_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(WANT_DEMO OFF CACHE BOOL "" FORCE)
    set(WANT_TESTS OFF CACHE BOOL "" FORCE)
    set(WANT_TOOLS OFF CACHE BOOL "" FORCE)

    set(WANT_DIALOG OFF CACHE BOOL "" FORCE)

    set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
    FetchContent_MakeAvailable(allegro)
else()
    message(STATUS "Allegro found, using existing installation.")
endif()

# Link Allegro libraries
target_link_libraries(${PROJECT_NAME}
    allegro
    allegro_audio
    allegro_acodec
    allegro_primitives
    allegro_image
    allegro_font
    allegro_ttf
)

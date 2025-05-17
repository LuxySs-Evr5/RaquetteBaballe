cmake_minimum_required(VERSION 3.10)

project(raquette-baballe)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-std=c++20 -O2 -pedantic -Wall -Wextra)

# Locate Allegro libraries
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    find_package(allegro CONFIG REQUIRED)
    set(EXECUTABLE_SUFFIX ".exe")
else()
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(ALLEGRO REQUIRED
        allegro-5
        allegro_primitives-5
        allegro_font-5
        allegro_ttf-5
        allegro_image-5
        allegro_audio-5
        allegro_acodec-5
    )
    set(EXECUTABLE_SUFFIX "")
endif()

file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCES} ressources/resources.rc)
else()
    add_executable(${PROJECT_NAME} ${SOURCES})
endif()

# Include directories and link libraries
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(${PROJECT_NAME} allegro allegro_primitives allegro_font allegro_ttf allegro_image allegro_audio allegro_acodec)
else()
    include_directories(${ALLEGRO_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${ALLEGRO_LIBRARIES})
endif()

# Set runtime output directory to the root of the project
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")

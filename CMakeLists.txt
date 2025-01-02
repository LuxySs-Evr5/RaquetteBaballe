cmake_minimum_required(VERSION 3.10)

project(arkanoid)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Debug build.")
    add_compile_options(-std=c++17 -g -pedantic -Wall -Wextra)
else(CMAKE_BUILD_TYPE STREQUAL "Release")
    message("Release build.")
    add_compile_options(-std=c++17 -O2 -pedantic -Wall -Wextra)
endif()

project(arkanoid)

set(CMAKE_BUILD_TYPE Debug)

# Locate Allegro libraries
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    find_package(allegro CONFIG REQUIRED)
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
endif()

file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories and link libraries
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(${PROJECT_NAME} allegro allegro_primitives allegro_font allegro_ttf allegro_image allegro_audio allegro_acodec)
else()
    include_directories(${ALLEGRO_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${ALLEGRO_LIBRARIES})
endif()

# Set runtime output directory to the root of the project
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Installation paths
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib/static
)

# Messages for compatibility confirmation
message("Building for platform: ${CMAKE_SYSTEM_NAME}")
message("C++ Standard: ${CMAKE_CXX_STANDARD}")
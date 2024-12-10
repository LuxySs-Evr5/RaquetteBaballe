cmake_minimum_required(VERSION 3.10)

project(arkanoid)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable debug symbols
set(CMAKE_BUILD_TYPE Debug)

# Allegro libraries
set(ALLEGRO_LIBS allegro allegro_primitives allegro_font allegro_ttf allegro_image allegro_audio allegro_acodec)

# Add all source files in the model subdirectory
file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

# Create the executable from the source files
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the Allegro libraries
find_package(PkgConfig REQUIRED)
pkg_check_modules(ALLEGRO REQUIRED allegro-5 allegro_primitives-5 allegro_font-5 allegro_ttf-5 allegro_image-5 allegro_audio-5 allegro_acodec-5)

# Include directories for Allegro
include_directories(${ALLEGRO_INCLUDE_DIRS})

# Link directories
link_directories(${ALLEGRO_LIBRARY_DIRS})

# Link libraries
target_link_libraries(${PROJECT_NAME} ${ALLEGRO_LIBS})
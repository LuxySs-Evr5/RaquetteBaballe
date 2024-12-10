cmake_minimum_required(VERSION 3.10)

project(casse-briques)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add all source files in the model subdirectory
file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

# Include directories for headers
include_directories (
    ${CMAKE_SOURCE_DIR}/model
    ${CMAKE_SOURCE_DIR}/controller
)

# Create the executable from the source files
add_executable(casse-briques ${SOURCES} ${HEADERS})

# Optionally, you can add additional target properties, like optimization or debug symbols
target_compile_options(casse-briques PRIVATE -Wall -Wextra -g)

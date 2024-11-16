cmake_minimum_required(VERSION 3.10)

project(casse-brique)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add all source files in the model subdirectory
file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/main.cpp
    ${CMAKE_SOURCE_DIR}/model/*.cpp
)

# Add all header files for IDE autocompletion (optional, useful for some IDEs)
file(GLOB_RECURSE HEADERS
    ${CMAKE_SOURCE_DIR}/model/*.hpp
)

# Include directories for headers
include_directories(${CMAKE_SOURCE_DIR}/model)

# Create the executable from the source files
add_executable(casse-brique ${SOURCES} ${HEADERS})

# Optionally, you can add additional target properties, like optimization or debug symbols
# target_compile_options(casse-brique PRIVATE -Wall -Wextra)

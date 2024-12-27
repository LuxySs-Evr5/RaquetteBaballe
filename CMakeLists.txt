cmake_minimum_required(VERSION 3.10)

project(arkanoid)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Définir le type de build
set(CMAKE_BUILD_TYPE Debug)

# Inclure pkg-config pour trouver Allegro
find_package(PkgConfig REQUIRED)
pkg_check_modules(ALLEGRO REQUIRED allegro-5 allegro_primitives-5 allegro_font-5 allegro_ttf-5 allegro_image-5 allegro_audio-5 allegro_acodec-5)

# Ajouter tous les fichiers sources
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Créer l'exécutable à partir des fichiers sources
add_executable(${PROJECT_NAME} ${SOURCES})

# Ajouter les répertoires d'inclusion d'Allegro
include_directories(${ALLEGRO_INCLUDE_DIRS})

# Lier les bibliothèques Allegro
target_link_libraries(${PROJECT_NAME} ${ALLEGRO_LIBRARIES})

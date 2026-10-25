cmake_minimum_required(VERSION 3.20)
project(AsteroidShooter LANGUAGES C CXX)

include(FetchContent)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build static libraries" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
set(BUILD_TESTING OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
    GIT_SHALLOW TRUE
)
set(ASSET_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/assets/pixelorama/images")
set(GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
file(MAKE_DIRECTORY "${GENERATED_DIR}")
set(EMBEDDED_ASSETS "${GENERATED_DIR}/embedded_assets_data.hpp")
file(WRITE "${EMBEDDED_ASSETS}" "#pragma once\n#include <cstddef>\nnamespace embedded_assets {\n")

set(ASSET_FILES
    bullet.png
    enemy.png
    gameoverscreen.png
    heart.png
    player.png
    titlescreen.png
)

foreach(ASSET IN LISTS ASSET_FILES)
    set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${ASSET_DIR}/${ASSET}")
    string(REPLACE "." "_" ASSET_ID "${ASSET}")
    file(READ "${ASSET_DIR}/${ASSET}" ASSET_HEX HEX)
    string(REGEX REPLACE "(..)" "0x\\1," ASSET_BYTES "${ASSET_HEX}")
    string(TOUPPER "${ASSET_ID}" ASSET_ID)
    file(APPEND "${EMBEDDED_ASSETS}"
        "inline constexpr unsigned char ${ASSET_ID}[] = {${ASSET_BYTES}};\n"
    )
endforeach()

file(APPEND "${EMBEDDED_ASSETS}" "}\n")

FetchContent_MakeAvailable(raylib)

add_executable(AsteroidShooter
    src/code/board.cpp
    src/code/bullet.cpp
    src/code/enemy.cpp
    src/code/gamestates.cpp
    src/code/main.cpp
    src/code/player.cpp
)

target_compile_features(AsteroidShooter PRIVATE cxx_std_20)
target_include_directories(AsteroidShooter PRIVATE "${GENERATED_DIR}")
target_link_libraries(AsteroidShooter PRIVATE raylib)

install(TARGETS AsteroidShooter RUNTIME DESTINATION .)

cmake_minimum_required(VERSION 3.16)

project(AsteroidShooter_Raylib LANGUAGES CXX)

find_package(raylib CONFIG REQUIRED)

add_executable(asteroid_shooter
    src/code/board.cpp
    src/code/bullet.cpp
    src/code/enemy.cpp
    src/code/main.cpp
    src/code/player.cpp
)

target_compile_features(asteroid_shooter PRIVATE cxx_std_20)
target_link_libraries(asteroid_shooter PRIVATE raylib)
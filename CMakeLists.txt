cmake_minimum_required(VERSION 3.29)
project(oopGameRaylib)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib REQUIRED)

set(SOURCES
        main.cpp
        Game.cpp
        GameObject.cpp
        Player.cpp
        Enemy.cpp
        Bullet.cpp
        EnemyTypes.cpp
        EnemyTypes.h
)

add_executable(oopGameRaylib ${SOURCES})

target_link_libraries(oopGameRaylib PRIVATE raylib)
target_link_libraries(oopGameRaylib PRIVATE "-framework OpenGL")
target_link_libraries(oopGameRaylib PRIVATE "-framework Cocoa")
target_link_libraries(oopGameRaylib PRIVATE "-framework IOKit")
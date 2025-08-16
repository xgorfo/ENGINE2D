cmake_minimum_required(VERSION 3.10)
project(2DEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.6 REQUIRED graphics window system)

include_directories(include)

add_executable(2d-engine
    src/Application.cpp
    src/Obstacle.cpp
    src/Vector2D.cpp
    src/Transform.cpp
    main.cpp
    src/Player.cpp
    src/Game.cpp
)

target_link_libraries(2d-engine sfml-graphics sfml-window sfml-system)

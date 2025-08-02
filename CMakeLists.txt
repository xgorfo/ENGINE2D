cmake_minimum_required(VERSION 3.14)
project(MainEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/sfml/3.0.1/lib/cmake/SFML")

find_package(SFML CONFIG REQUIRED COMPONENTS Graphics Window System)

add_executable(MainEngine /Users/xgorfo/Projects/ENGINE2D-C++/main.cpp)

target_link_libraries(MainEngine
    SFML::Graphics
    SFML::Window
    SFML::System
)

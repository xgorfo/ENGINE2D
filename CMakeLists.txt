cmake_minimum_required(VERSION 3.14)
project(MainEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "/opt/homebrew/opt/sfml@2/lib/cmake/SFML")

find_package(SFML REQUIRED COMPONENTS graphics window system)

add_executable(MainEngine
    src/main.cpp
    src/Application.cpp
    src/Runtime.cpp
    src/View.cpp
    src/Renderer.cpp
    src/TriangleEntity.cpp
    src/Vector2D.cpp
    src/Basis.cpp
    src/Camera.cpp
    src/Player.cpp
)

target_include_directories(MainEngine PRIVATE include)

target_link_libraries(MainEngine
    sfml-graphics
    sfml-window
    sfml-system
)

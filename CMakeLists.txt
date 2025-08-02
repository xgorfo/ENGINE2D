cmake_minimum_required(VERSION 3.14)
project(MainEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем путь к SFML 2.6.2 вручную
set(SFML_DIR "/opt/homebrew/opt/sfml@2/lib/cmake/SFML")

find_package(SFML REQUIRED COMPONENTS graphics window system)

# Здесь путь к файлам указывается корректно
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
)

target_include_directories(MainEngine PRIVATE include)

target_link_libraries(MainEngine
    sfml-graphics
    sfml-window
    sfml-system
)

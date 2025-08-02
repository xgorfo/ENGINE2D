cmake_minimum_required(VERSION 3.14)
project(MainEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем путь до SFML вручную
include_directories(/opt/homebrew/Cellar/sfml/3.0.1/include)
link_directories(/opt/homebrew/Cellar/sfml/3.0.1/lib)

# Все исходники проекта
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

add_executable(MainEngine ${SOURCES} ${HEADERS})

target_include_directories(MainEngine PRIVATE include)

# Линкуем вручную SFML 3.0.1 библиотеки
target_link_libraries(MainEngine
    sfml-graphics.3.0.1
    sfml-window.3.0.1
    sfml-system.3.0.1
)

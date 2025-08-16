cmake_minimum_required(VERSION 3.10)
project(2DEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.6 REQUIRED COMPONENTS graphics window system)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

file(GLOB_RECURSE SOURCES 
    "src/*.cpp" 
    "main.cpp"
)

add_executable(2d-engine ${SOURCES})

target_link_libraries(2d-engine 
    sfml-graphics 
    sfml-window 
    sfml-system
)
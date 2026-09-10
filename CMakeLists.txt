cmake_minimum_required(VERSION 3.20)
project(snake-cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(main main.cpp ./core/Game.cpp)
target_link_libraries(main PRIVATE raylib nlohmann_json::nlohmann_json)

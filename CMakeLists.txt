cmake_minimum_required(VERSION 3.0.0)
project(Fast VERSION 0.1.0)

add_library(FastLib simple_lib.cpp simple_lib.hpp)

add_executable(Fast main.cpp)

target_link_libraries(Fast PRIVATE FastLib)

find_package(nlohmann_json 3.11.2 REQUIRED)

target_link_libraries(Fast PRIVATE nlohmann_json::nlohmann_json)

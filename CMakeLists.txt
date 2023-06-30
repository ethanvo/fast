cmake_minimum_required(VERSION 3.10)
project(ESP)

set(CMAKE_CXX_STANDARD 11)

# Specify the include directories
include_directories(include)

# Add the subdirectory containing the source files
add_subdirectory(src)

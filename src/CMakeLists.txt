# Add FastSubLib to the list of libraries to link against
add_library(FastSubLib sub_lib.cpp ../include/sub_lib.hpp)

target_include_directories(FastSubLib PUBLIC ../include)

# Add FastLib to the list of libraries to link against
add_library(FastLib simple_lib.cpp ../include/simple_lib.hpp)

target_include_directories(FastLib PUBLIC ../include)

# Add AtomicMapLib to the list of libraries to link against
add_library(AtomicMapLib atomic_map_lib.cpp ../include/atomic_map_lib.hpp)

target_include_directories(AtomicMapLib PUBLIC ../include)

add_executable(Fast main.cpp)

# Link the executable to libraries
target_link_libraries(Fast PRIVATE FastLib)

target_link_libraries(Fast PRIVATE FastSubLib)

target_link_libraries(Fast PRIVATE AtomicMapLib)

# Add nlohmann_json library
find_package(nlohmann_json 3.11.2 REQUIRED)
find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)

target_link_libraries(Fast PRIVATE nlohmann_json::nlohmann_json)

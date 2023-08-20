cmake_minimum_required(VERSION 3.20)

project(heap_array)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(tests)

target_include_directories(${PROJECT_NAME} PUBLIC includes)

add_compile_options(-Wall -Wextra -Wpedantic)

add_compile_options(-fsanitize=address)

add_link_options(-fsanitize=address)

set(CMAKE_BUILD_TYPE Debug)
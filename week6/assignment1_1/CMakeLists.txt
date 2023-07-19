cmake_minimum_required(VERSION 3.20)

project(status)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(src)

target_include_directories(${PROJECT_NAME} PUBLIC includes)

target_link_libraries(${PROJECT_NAME} PUBLIC ex)

add_compile_options(-Wall -Wextra -Wpedantic)
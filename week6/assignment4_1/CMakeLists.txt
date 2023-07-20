cmake_minimum_required(VERSION 3.20)

project(ass641)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC includes)

add_compile_options(-Wall -Wextra -Wpedantic)
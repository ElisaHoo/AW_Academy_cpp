cmake_minimum_required(VERSION 3.20)

project(cfile)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(src)

target_include_directories(${PROJECT_NAME} PUBLIC includes)

target_link_libraries(${PROJECT_NAME} PUBLIC file)

add_compile_options(-Wall -Wextra -Wpedantic)
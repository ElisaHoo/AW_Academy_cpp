cmake_minimum_required(VERSION 3.15)

project(sensorData)

add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC includes)
target_link_libraries(${PROJECT_NAME} PUBLIC sensor)
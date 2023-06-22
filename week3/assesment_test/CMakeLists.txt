cmake_minimum_required(VERSION 3.20)

project(assesment_test)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(src)

target_include_directories(${PROJECT_NAME} PUBLIC includes)

target_link_libraries(${PROJECT_NAME} PUBLIC transactions)

add_subdirectory(tests)
cmake_minimum_required(VERSION 3.20)

project(Planets)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(src)

# Include directories where header files are located
include_directories(${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}
    PUBLIC position_comparison
)
add_executable(test weather_tests.cpp)

target_include_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/includes)

target_link_libraries(test PUBLIC weather)
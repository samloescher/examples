cmake_minimum_required(VERSION 3.10)
project(testing-example)

add_subdirectory(thirdparty)

add_executable(testing-example
    src/mean.cpp
    src/mean.test.cpp
    test/main.cpp
)

target_link_libraries(testing-example PRIVATE Catch2::Catch2)

add_catch_test(testing-example)

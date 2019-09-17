cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(visitor_pattern)
add_executable(visitor_pattern main.cpp)
target_compile_features(visitor_pattern
  PUBLIC
    cxx_std_17
)

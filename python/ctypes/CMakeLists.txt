cmake_minimum_required(VERSION 3.10)
project(ctypes-example)

add_library(my_lib SHARED my_lib.cpp)

target_compile_features(my_lib
  PUBLIC
    cxx_std_17
)

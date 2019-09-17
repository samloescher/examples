cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(crtp)

add_executable(simple_crtp simple_crtp.cpp)
add_executable(helper_crtp helper_crtp.cpp)

target_compile_features(simple_crtp
  PUBLIC
    cxx_std_17
)
target_compile_features(helper_crtp
  PUBLIC
    cxx_std_17
)

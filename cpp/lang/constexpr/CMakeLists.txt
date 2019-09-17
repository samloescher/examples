cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(constexpr CXX)

add_executable(array array.cpp)
target_compile_features(array
  PUBLIC
    cxx_std_20
)

# Use libc++ which has implemented constexpr transform
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

add_executable(array_python)

 # Always mark this as required to be run (python_preprocess isn't generated)
add_custom_target(_python_preprocess DEPENDS python_preprocess)
add_custom_command(
  OUTPUT python_preprocess
  COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/constants_preprocessor.py -i ${CMAKE_CURRENT_SOURCE_DIR}/array_python.cpp -o ${CMAKE_CURRENT_BINARY_DIR}/array_python.gen.cpp
  BYPRODUCTS ${CMAKE_CURRENT_BINARY_DIR}/array_python.gen.cpp
)
add_dependencies(array_python _python_preprocess)
target_sources(array_python PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/array_python.gen.cpp>)

cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(shared_workspace)

add_library(shared_workspace SHARED shared_workspace.cpp)

target_compile_features(shared_workspace
  PUBLIC
    cxx_std_17
)

set(mex_functions
  mex_create
  mex_release
  mex_get
)

add_custom_target(mex_all ALL)
foreach(mex_function ${mex_functions})
  add_custom_target(mex_${mex_function}
      COMMAND mkoctfile --mex ${CMAKE_CURRENT_SOURCE_DIR}/${mex_function}.cpp -I${CMAKE_CURRENT_SOURCE_DIR}/research -L${CMAKE_CURRENT_BINARY_DIR} -lshared_workspace -Wl,-rpath,.
      VERBATIM
   )
  add_dependencies(mex_all mex_${mex_function})
  add_dependencies(mex_${mex_function} shared_workspace)
endforeach()

add_custom_target(_copy_matlab_files DEPENDS copy_matlab_files) # Always mark this as required to be run (copy_matlab_files isn't generated)
add_custom_command(
  OUTPUT copy_matlab_files
  COMMAND cmake -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/scripts ${CMAKE_CURRENT_BINARY_DIR}
)
add_dependencies(shared_workspace _copy_matlab_files)

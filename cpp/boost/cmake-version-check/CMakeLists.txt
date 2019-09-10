cmake_minimum_required(VERSION 3.8)
set(Boost_DEBUG ON)
find_package(Boost)

message(STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARY_DIRS = ${Boost_LIBRARY_DIRS}")

cmake_minimum_required(VERSION 3.14)
project(zeromq-examples)

find_package(Threads REQUIRED)
add_subdirectory(thirdparty)

add_subdirectory(hello-world)
add_subdirectory(weather-station)

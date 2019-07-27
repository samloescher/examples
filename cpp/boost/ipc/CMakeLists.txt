cmake_minimum_required(VERSION 3.10)
project(ipc)

find_package(Boost 1.69 REQUIRED)
find_package(Threads REQUIRED)

add_executable(publisher "publisher.cpp")
add_executable(receiver "receiver.cpp")

foreach(tgt publisher receiver)
    target_include_directories(${tgt} PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(${tgt} PRIVATE Threads::Threads)
    if (UNIX)
        target_link_libraries(${tgt} PRIVATE rt)
    endif()
    set_target_properties(${tgt} PROPERTIES CXX_STANDARD 17)
endforeach()

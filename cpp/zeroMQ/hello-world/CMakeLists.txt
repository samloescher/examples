add_executable(hello-world-client client.cpp)
add_executable(hello-world-server server.cpp)

target_link_libraries(hello-world-client cppzmq)
target_link_libraries(hello-world-server cppzmq Threads::Threads)

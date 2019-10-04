add_executable(weather-station-client client.cpp)
add_executable(weather-station-server server.cpp)

target_link_libraries(weather-station-client cppzmq)
target_link_libraries(weather-station-server cppzmq Threads::Threads)

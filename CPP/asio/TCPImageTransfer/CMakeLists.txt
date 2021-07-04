cmake_minimum_required(VERSION 3.0.0)
project(TCPImageTransfer)

add_executable(server server.cpp)
target_compile_definitions(server PUBLIC ASIO_STANDALONE)
target_link_libraries(server pthread)

add_executable(client client.cpp)
target_compile_definitions(client PUBLIC ASIO_STANDALONE)
target_link_libraries(client pthread)
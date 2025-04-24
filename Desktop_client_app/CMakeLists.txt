cmake_minimum_required(VERSION 3.10)
project(DistributedSystem CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(client)
add_subdirectory(processor_server)
add_subdirectory(display_server)
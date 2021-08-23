cmake_minimum_required(VERSION 2.8.0)

project(send)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lrt")

add_executable(${PROJECT_NAME} send.cpp send.hpp)

target_link_libraries (send rt)
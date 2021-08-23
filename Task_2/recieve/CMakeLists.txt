cmake_minimum_required(VERSION 2.8.0)

project(recieve)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lrt")

add_executable(${PROJECT_NAME} recieve.cpp recieve.hpp)

target_link_libraries (recieve rt)
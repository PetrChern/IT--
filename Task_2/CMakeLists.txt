cmake_minimum_required(VERSION 2.8.0)
project(shmem)

add_subdirectory("${PROJECT_SOURCE_DIR}/recieve" ./recieve)

add_subdirectory("${PROJECT_SOURCE_DIR}/send" ./send)



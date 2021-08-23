cmake_minimum_required(VERSION 2.8)

project(Task_1)

find_package(OpenSSL REQUIRED)

include_directories(${OPENSSL_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.cpp Fingerprint.cpp Fingerprint.hpp)

target_link_libraries(${PROJECT_NAME} OpenSSL::Crypto)
target_link_libraries(${PROJECT_NAME} OpenSSL::SSL)
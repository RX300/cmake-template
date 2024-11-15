cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(cmake_vcpkg)

list(APPEND SRC_LIST main.cpp)

add_executable(vcpkg_hello ${SRC_LIST})


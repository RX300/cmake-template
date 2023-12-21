cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(cppcmake)
include_directories(include)
set(SRC_LIST main.cpp src/print_hello.cpp)
add_executable(hello ${SRC_LIST})
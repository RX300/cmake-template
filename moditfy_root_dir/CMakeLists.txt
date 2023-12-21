cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(cmake_modify_root)

# 设置一个变量，表示希望的工作目录
set(WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}" CACHE STRING "Working directory")

list(APPEND SRC_LIST main.cpp)

add_executable(modify_root ${SRC_LIST})

# 将工作目录变量传递给C++代码
target_compile_definitions(modify_root PRIVATE WORKING_DIRECTORY="${WORKING_DIRECTORY}")
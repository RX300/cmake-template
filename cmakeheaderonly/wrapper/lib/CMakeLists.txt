cmake_minimum_required(VERSION 3.25)

project(lib)
file(GLOB LIB_FILES "*.cpp" "*.h")

# 设置共享变量放到cmakechche里让其他cmake文件可以使用
set(LIB_FILES ${LIB_FILES} CACHE INTERNAL "lib files")
add_library(
    lib
    lib.cpp
)

target_include_directories(
    lib
    PUBLIC
    .
)

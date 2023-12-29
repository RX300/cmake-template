cmake_minimum_required(VERSION 3.10)
project(mysrc)

# 搜寻当前目录下的所有python文件
file(GLOB_RECURSE PY_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.py) # 保存到变量中并传递到上一层
set(SRC_PYS ${PY_SOURCES} PARENT_SCOPE) # 设置了PARENT_SCOPE属性的变量，SRC_PYS的作用域就会变成上一层，在当前目录下不可见

# 添加cmake模块路径并添加cmake模块
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")
include(printfiles) # 在cmake模块路径下查找名字为modulename.cmake的文件

message(STATUS "==============PYS================")
print_files(${PY_SOURCES})
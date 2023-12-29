cmake_minimum_required(VERSION 3.10)
project(myheader)

# 搜寻当前目录下的所有txt文件但不包括CMakeLists.txt，所以# 移除CMakeLists.txt（如果它存在于列表中）
file(GLOB HEADERTXTS *.txt)
list(REMOVE_ITEM HEADERTXTS "${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt")

# 保存到INCLUDETXTS变量中再传递给上层目录
set(INCLUDETXTS ${HEADERTXTS} PARENT_SCOPE)

# 使用inlude cmake脚本
include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/printfiles.cmake)

message(STATUS "==============TXTS================")
print_files(${HEADERTXTS})
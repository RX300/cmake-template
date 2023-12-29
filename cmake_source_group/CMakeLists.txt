cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(MyProject)

# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 使用inlude cmake脚本
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/printfiles.cmake)

# 或者添加cmake模块路径并添加cmake模块
# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# include(printfiles) # 在cmake模块路径下查找名字为modulename.cmake的文件

# 添加包含目录
include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)

# 自动包含当前源码目录和构建目录
# set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 收集源文件
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SOURCES)
message(STATUS "==============SOURCES================")
print_files(${SOURCES})

# 收集头文件和CMakelists.txt
file(GLOB_RECURSE HEADERS "*.h" "include/CMakeLists.txt")
message(STATUS "==============HEADERS================")
print_files(${HEADERS})

# 使用 source_group 自动分组所有文件
source_group(TREE ${PROJECT_SOURCE_DIR} PREFIX "MyProject" FILES ${SOURCES} ${HEADERS})
source_group("txts" FILES ${INCLUDETXTS})
source_group("pys" FILES ${SRC_PYS})

# 添加可执行文件
add_executable(MyExecutable ${SOURCES} ${HEADERS} ${INCLUDETXTS} ${SRC_PYS})

cmake_minimum_required(VERSION 3.25)

project(headerOnly)

set(libname headerOnly)

file(GLOB HEADER_FILES "*.h")

# 设置共享变量放到cmakechche里让其他cmake文件可以使用
set(HEADER_FILES ${HEADER_FILES} CACHE INTERNAL "header files")
add_library(
    ${libname}
    INTERFACE
    ${HEADER_FILES}
)

target_include_directories(
    ${libname}
    INTERFACE
    .
)

find_package(glm CONFIG REQUIRED)
target_link_libraries(${libname} INTERFACE glm::glm)
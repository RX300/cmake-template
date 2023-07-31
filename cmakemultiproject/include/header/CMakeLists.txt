cmake_minimum_required(VERSION 3.25)
set(CMAKE_TOOLCHAIN_FILE "D:/utils/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_TARGET_TRIPLET "x64-windows")
project(headerOnly)

set(libname headerOnly)

file(GLOB HEADER_FILES "*.h")

# 设置共享变量放到cmakechche里让其他cmake文件可以使用
set(HEADER_FILES ${HEADER_FILES} CACHE INTERNAL "lib files")

add_library(
    ${libname}
    INTERFACE
    ${HEADER_FILES}
)

target_include_directories(
    ${libname}
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(glm CONFIG REQUIRED)
target_link_libraries(${libname} INTERFACE glm::glm)
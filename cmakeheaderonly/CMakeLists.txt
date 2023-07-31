cmake_minimum_required(VERSION 3.25)
set(CMAKE_TOOLCHAIN_FILE "D:/utils/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_TARGET_TRIPLET "x64-windows")
project(camkeheaderonlylib)

add_subdirectory(wrapper)

message(STATUS "HEADER_FILES: ${HEADER_FILES}")
message(STATUS "LIB_FILES: ${LIB_FILES}")

# source_group创建的文件夹名字是取决于相对路径，会显示这些头文件的上一级目录
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${HEADER_FILES} ${LIB_FILES})
add_executable(
    camkeheaderonlylib
    main.cpp

    ${HEADER_FILES}
    ${LIB_FILES}
)

target_link_libraries(camkeheaderonlylib PUBLIC wrapper)

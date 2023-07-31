cmake_minimum_required(VERSION 3.25)
set(CMAKE_TOOLCHAIN_FILE "D:/utils/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_TARGET_TRIPLET "x64-windows")
project(example2)

set(examplename example2)

# 这里使用CMAKE_SOURCE_DIR是因为它是项目的根目录，而不是当前目录，TREE选项要求文件的路径必须以指定的目录为前缀，如果用CMAKE_CURRENT_SOURCE_DIR，那么就会以当前目录为前缀，然而HEADER_FILES中的文件并不在当前目录。
source_group(
    TREE ${CMAKE_SOURCE_DIR}
    FILES ${HEADER_FILES}
)

add_executable(
    ${examplename}
    main.cpp
    ${HEADER_FILES}
)

target_link_libraries(
    ${examplename}
    PRIVATE
    headerOnly
)
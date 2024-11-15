cmake_minimum_required(VERSION 3.10)
set(CMAKE_TOOLCHAIN_FILE "D:/utils/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake")

# 配合clangd生成compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(VCPKG_TARGET_TRIPLET "x64-windows")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(cmake_vcpkg)

# 将include目录下的所有头文件赋值到HEADER_FILES变量
file(GLOB HEADER_FILES "${CMAKE_SOURCE_DIR}/include/*.h")

# 这么做是为了方便在vscode里可以调试到头文件
list(APPEND SRC_LIST main.cpp ${HEADER_FILES})
add_executable(vcpkg_hello ${SRC_LIST})

target_include_directories(vcpkg_hello PUBLIC include)

find_package(fmt CONFIG REQUIRED)
message(STATUS "fmt    config: ${fmt_DIR}")
message(STATUS "fmt    version: ${fmt_VERSION}")
message(STATUS "fmt    include: ${fmt_INCLUDE_DIRS}")
message(STATUS "fmt    libraries: ${fmt_LIBS}")
target_link_libraries(vcpkg_hello PRIVATE fmt::fmt)

find_package(glad CONFIG REQUIRED)
target_link_libraries(vcpkg_hello PRIVATE glad::glad)

# 打印编译器位置
message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
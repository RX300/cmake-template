cmake_minimum_required(VERSION 3.30)
set(CMAKE_TOOLCHAIN_FILE "D:/utils/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake")

# 配合clangd生成compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(VCPKG_TARGET_TRIPLET "x64-windows")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
# 如果使用ninja，需要手动设置编译器路径,并且可以设置是否生成测试
set(CMAKE_CXX_COMPILER "D:/VisualStudio/community/VC/Tools/MSVC/14.38.33130/bin/Hostx64/x64/cl.exe")

project(clangdExample VERSION 0.1 LANGUAGES CXX)
# option(BUILD_TESTING "Enable building of tests" OFF)

# 将include目录下的所有头文件赋值到HEADER_FILES变量
file(GLOB HEADER_FILES "${CMAKE_SOURCE_DIR}/include/*.h")

# 这么做是为了方便在vscode里可以调试到头文件
list(APPEND SRC_LIST main.cpp ${HEADER_FILES})
add_executable(clangdexe ${SRC_LIST})

target_include_directories(clangdexe PUBLIC include)

find_package(fmt CONFIG REQUIRED)
message(STATUS "fmt    config: ${fmt_DIR}")
message(STATUS "fmt    version: ${fmt_VERSION}")
# 添加更详细的fmt库信息
get_target_property(FMT_INCLUDE_DIRS fmt::fmt INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(FMT_LIBRARY_PATH fmt::fmt LOCATION)
message(STATUS "fmt    include dirs: ${FMT_INCLUDE_DIRS}")
message(STATUS "fmt    library path: ${FMT_LIBRARY_PATH}")
target_link_libraries(clangdexe PRIVATE fmt::fmt)

find_package(glad CONFIG REQUIRED)
message(STATUS "glad  config: ${glad_DIR}")
message(STATUS "glad  version: ${glad_VERSION}")
# 添加更详细的glad库信息
get_target_property(GLAD_INCLUDE_DIRS glad::glad INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(GLAD_LIBRARY_PATH glad::glad LOCATION)
message(STATUS "glad  include dirs: ${GLAD_INCLUDE_DIRS}")
message(STATUS "glad  library path: ${GLAD_LIBRARY_PATH}")
target_link_libraries(clangdexe PRIVATE glad::glad)

# 打印编译器位置
message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
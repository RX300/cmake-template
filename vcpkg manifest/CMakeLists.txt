#使用MSBUILD生成工程时，vcpkg需要使用vcpkg integrate install命令集成到MSBUILD中，否则会找不到头文件和库文件
#清单模式相关命令:
#vcpkg new --application
#vcpkg add port "package"
#vcpkg install (清单模式不支持安装单个包)，会在本地vcpkg_installed文件夹下安装
cmake_minimum_required(VERSION 3.10)

Set(CMAKE_TOOLCHAIN_FILE "E:/vcpkg/scripts/buildsystems/vcpkg.cmake")
Set(VCPKG_TARGET_TRIPLET "x64-windows")

project(HelloWorld)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(ProjectName HelloWorld)

add_executable(${ProjectName} main.cpp)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(${ProjectName} PRIVATE fmt::fmt)

find_package(glm CONFIG REQUIRED)
target_link_libraries(${ProjectName} PRIVATE glm::glm)
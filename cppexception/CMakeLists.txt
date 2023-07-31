# 设置cmake最小版本
cmake_minimum_required(VERSION 3.15)
set(CMAKE_TOOLCHAIN_FILE "D:/utils/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_TARGET_TRIPLET "x64-windows")

# 设置项目名称
set(PROJECT_NAME Exception)
project(${PROJECT_NAME} CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# 设置源文件列表
list(APPEND SOURCE_FILES
        main.cpp
)
set(exename Exception_Test)

# 添加可执行文件
add_executable(${exename} ${SOURCE_FILES})

if(MSVC)
        # 设置 Cpp 语言编译 flags,  输入代码编码格式为 utf-8
        set(CMAKE_CXX_FLAGS /source-charset:utf-8)
        set_target_properties(${exename} PROPERTIES COMPILE_FLAGS "/EHsc")
endif()
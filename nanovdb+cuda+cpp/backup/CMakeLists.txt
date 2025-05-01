# cmake_minimum_required(VERSION 3.20)
# project(CUDA_TEMPLATE LANGUAGES CXX CUDA)
# SET(CMAKE_CXX_STANDARD 20)
# SET(CMAKE_CUDA_STANDARD 20)
# set(SRC main.cpp hello.cu)
# add_executable(${PROJECT_NAME} ${SRC})

cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
set(CMAKE_TOOLCHAIN_FILE "D:/utils/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_TARGET_TRIPLET "x64-windows")
project(my_project CUDA CXX)
find_package(CUDAToolkit REQUIRED)
set(SOME_LIST "a" "b")

# 打印SOME——LIST
message(STATUS "SOME_LIST: ${SOME_LIST}")
set(SOME_LIST ${SOME_LIST} "c")

# 打印SOME——LIST
message(STATUS "SOME_LIST: ${SOME_LIST}")

# 设置C++标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_STANDARD 20)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)

# 打印nvcc编译器参数
# message(STATUS "CMAKE_CUDA_FLAGS : ${CMAKE_CUDA_FLAGS}")
# set(CMAKE_CUDA_FLAGS "-std=c++20")
add_library(cuda_lib STATIC hello.cu)
add_executable(my_executable main.cpp cuda_lib)

# 找到第三方包openvdb
find_package(OpenVDB CONFIG REQUIRED)

# 打印
message(STATUS "OpenVDB    config: ${OpenVDB_DIR}")
message(STATUS "OpenVDB    version: ${OpenVDB_VERSION}")
message(STATUS "OpenVDB    include: ${OpenVDB_INCLUDE_DIRS}")
message(STATUS "OpenVDB    libraries: ${OpenVDB_LIBS}")
target_link_libraries(my_executable PRIVATE OpenVDB::openvdb)

# # 获取nvcc编译器参数
get_target_property(CUDA_NVCC_FLAGS cuda_lib INTERFACE_COMPILE_OPTIONS)

# 移除不需要的链接路径
list(REMOVE_ITEM CUDA_NVCC_FLAGS "-L${VCPKG_LIBRARY_LINK_DIR}")

# 修改nvcc编译器参数
set_target_properties(cuda_lib PROPERTIES CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS}")

# 包含nanovdb头文件
target_include_directories(cuda_lib PUBLIC D:/utils/vcpkg/vcpkg/buildtrees/openvdb/src/3ab5951686-1c7a23646f.clean/nanovdb)
message(STATUS "CMAKE_CUDA_FLAGS : ${CMAKE_CUDA_FLAGS}")
set_target_properties(cuda_lib PROPERTIES
    CUDA_SEPARABLE_COMPILATION ON

    # CUDA_ARCHITECTURES 61
)

target_link_libraries(cuda_lib ${CUDAToolkit_LIBRARIES})

# 打印nvcc编译器参数
message(STATUS "CUDA_NVCC_FLAGS: ${CUDA_NVCC_FLAGS}")

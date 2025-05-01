# CMake 最低版本要求
cmake_minimum_required(VERSION 4.0) # 建议使用较新版本以获得更好的 CUDA 支持

# 项目名称和语言设置 (C++ 和 CUDA)
project(cuda_cmake_example LANGUAGES CXX CUDA)

# --- CUDA 配置 ---
# 查找 CUDA Toolkit (推荐方式)
# find_package(CUDAToolkit REQUIRED)的命令参数和设置的变量见如下网页
# https://cmake.com.cn/cmake/help/latest/module/FindCUDAToolkit.html
find_package(CUDAToolkit REQUIRED)

# (可选) 设置 CUDA C++ 标准 (例如 C++11, C++14, C++17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CUDA_STANDARD 20)
# set(CMAKE_CUDA_STANDARD_REQUIRED ON)
# set(CMAKE_CUDA_EXTENSIONS OFF) # 通常建议关闭 MSVC 扩展

# **重要:** 设置目标 GPU 架构 (Compute Capability)
# 你需要根据你的 GPU 型号设置正确的架构代码。
# 示例:
#   - Turing (RTX 20xx): 75
#   - Ampere (RTX 30xx, A100): 80, 86
#   - Ada Lovelace (RTX 40xx): 89
#   - Hopper (H100): 90
# 你可以通过运行 CUDA Toolkit 示例中的 deviceQuery 程序，或在网上搜索你的 GPU 型号来找到架构代码。
# 可以指定多个架构，用分号隔开，例如 "75;86"
# 如果不确定，可以从一个你知道支持的值开始，例如 "75"
set(CMAKE_CUDA_ARCHITECTURES 86) # <--- 修改为你 GPU 的架构代码!

# 打印找到的 CUDA 信息 (调试用)
message(STATUS "Found CUDA Toolkit: ${CUDAToolkit_VERSION}")
message(STATUS "CUDA Compiler: ${CUDAToolkit_NVCC_EXECUTABLE}")
message(STATUS "Targeting CUDA Architectures: ${CMAKE_CUDA_ARCHITECTURES}")
message(STATUS "CUDA Runtime Library Directory: ${CUDAToolkit_LIBRARY_DIR}")
message(STATUS "CUDA Include Directory: ${CUDAToolkit_INCLUDE_DIRS}")
# --- 可执行文件定义 ---
# 添加可执行文件目标，包含所有 C++ 和 CUDA 源文件
add_executable(my_cuda_app main.cpp kernel.cu)

# --- 链接库 ---
# 将 CUDA 运行时库链接到目标
# 使用 find_package(CUDA) 提供的导入目标 CUDA::cudart
target_link_libraries(my_cuda_app PRIVATE CUDA::cudart)

# (可选) 如果你需要其他 CUDA 库 (如 cuBLAS, cuFFT)，你需要找到它们并链接
# find_package(CUDA REQUIRED COMPONENTS cublas cufft)
# target_link_libraries(my_cuda_app PRIVATE CUDA::cublas CUDA::cufft)

# (可选) 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# (可选) 允许在 .cu 文件中使用 C++11 (或更高版本) 的特性
set_target_properties(my_cuda_app PROPERTIES
    CUDA_SEPARABLE_COMPILATION ON # 如果需要设备链接，则开启
)
# 或者直接设置编译器标志 (更底层的方法)
# target_compile_options(my_cuda_app PRIVATE $<$<COMPILE_LANGUAGE:CUDA>:-std=c++11>)


# --- 安装 (可选) ---
# install(TARGETS my_cuda_app DESTINATION bin)
#include <cuda_runtime.h>
#include <iostream>
#include <vector>

// CUDA 错误检查宏 (推荐在实际项目中使用更完善的检查)
#define CHECK_CUDA_ERROR(call) do { \
    cudaError_t err = call; \
    if (err != cudaSuccess) { \
        fprintf(stderr, "CUDA Error in %s at line %d: %s\n", __FILE__, __LINE__, cudaGetErrorString(err)); \
        exit(EXIT_FAILURE); \
    } \
} while (0)

// CUDA 核函数：向量加法
__global__ void vector_add_kernel(const float* d_a, const float* d_b, float* d_c, int n) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < n) {
        d_c[idx] = d_a[idx] + d_b[idx];
    }
}

// 主机端函数，负责内存分配、数据传输和核函数启动
extern "C" void run_vector_add(const std::vector<float>& h_a, const std::vector<float>& h_b, std::vector<float>& h_c) {
    int n = h_a.size();
    size_t bytes = n * sizeof(float);
    
    // 分配设备内存
    float *d_a = nullptr, *d_b = nullptr, *d_c = nullptr;
    CHECK_CUDA_ERROR(cudaMalloc(&d_a, bytes));
    CHECK_CUDA_ERROR(cudaMalloc(&d_b, bytes));
    CHECK_CUDA_ERROR(cudaMalloc(&d_c, bytes));

    // 将数据从主机复制到设备
    CHECK_CUDA_ERROR(cudaMemcpy(d_a, h_a.data(), bytes, cudaMemcpyHostToDevice));
    CHECK_CUDA_ERROR(cudaMemcpy(d_b, h_b.data(), bytes, cudaMemcpyHostToDevice));

    // 设置核函数启动参数
    int threads_per_block = 256;
    // 向上取整计算块数
    int blocks_per_grid = (n + threads_per_block - 1) / threads_per_block;

    std::cout << "Launching kernel with " << blocks_per_grid << " blocks and "
              << threads_per_block << " threads per block." << std::endl;

    // 启动核函数
    vector_add_kernel<<<blocks_per_grid, threads_per_block>>>(d_a, d_b, d_c, n);

    // 检查核函数启动错误 (异步错误需要后续同步才能捕获)
    CHECK_CUDA_ERROR(cudaGetLastError());

    // 等待 GPU 完成计算
    CHECK_CUDA_ERROR(cudaDeviceSynchronize());
    std::cout << "Kernel execution finished." << std::endl;

    // 将结果从设备复制回主机
    CHECK_CUDA_ERROR(cudaMemcpy(h_c.data(), d_c, bytes, cudaMemcpyDeviceToHost));

    // 打印结果
    std::cout << "Result: ";
    for (int i = 0; i < n; ++i) {
        std::cout << h_c[i] << " ";
    }
    std::cout << std::endl;

    // 释放设备内存
    CHECK_CUDA_ERROR(cudaFree(d_a));
    CHECK_CUDA_ERROR(cudaFree(d_b));
    CHECK_CUDA_ERROR(cudaFree(d_c));

    std::cout << "Device memory freed." << std::endl;
}
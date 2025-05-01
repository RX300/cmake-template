#include <iostream>
#include <vector>
// 函数声明 (在 kernel.cu 中定义)
extern "C" void run_vector_add(const std::vector<float>& h_a, const std::vector<float>& h_b, std::vector<float>& h_c);

int main() {
    const int n = 10; // 向量大小
    std::vector<float> h_a(n);
    std::vector<float> h_b(n);
    std::vector<float> h_c(n);
    
    // 初始化主机向量
    for (int i = 0; i < n; ++i) {
        h_a[i] = static_cast<float>(i);
        h_b[i] = static_cast<float>(i * 2);
    }

    std::cout << "Running vector addition on GPU..." << std::endl;
    run_vector_add(h_a, h_b, h_c);

    // 验证结果 (简单检查)
    bool success = true;
    for (int i = 0; i < n; ++i) {
        if (std::abs(h_c[i] - (h_a[i] + h_b[i])) > 1e-5) {
            std::cerr << "Verification failed at index " << i << "! Got " << h_c[i]
                      << ", expected " << (h_a[i] + h_b[i]) << std::endl;
            success = false;
            break; // 只报告第一个错误
        }
    }
    
    if (success) {
        std::cout << "Verification successful!" << std::endl;
    } else {
        std::cout << "Verification failed!" << std::endl;
    }

    std::cout << "Program finished." << std::endl;
    return 0;
}
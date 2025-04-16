#include "fmt/core.h"
#include <iostream>
#include "head1.h"
int main() {
  // 使用 fmt 库输出格式化字符串
  fmt::print("fmt test:Hello, {}!\n", "World");
  std::cout << "输出：Hello, World!" << std::endl;
  auto testvec = test();
  fmt::print("testvec[1]:{}", testvec[1]);
  return 0;
}
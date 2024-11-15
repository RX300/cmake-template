#include "fmt_hello.h"
#include <iostream>

using namespace std;
void printTypeSize();
void useLambda();
// 判断大端小端
// 联合体在内存中的存储方式是所有成员共用同一块内存空间
// 所以给uint32赋值实际上也会给char赋值
void checkEndian() {
  union {
    uint32_t i;
    char c[4];
  } bintest = {0x01020304};

  if (bintest.c[0] == 1) {
    std::cout << "Big-Endian" << std::endl;
  } else if (bintest.c[0] == 4) {
    std::cout << "Little-Endian" << std::endl;
  } else {
    std::cout << "Unknown Endian" << std::endl;
  }
}
// hello world
using namespace std;
int main() {
  checkEndian();
  fmt_hello();
}

void printTypeSize() {
  cout << "Size of char: " << sizeof(char) << " byte(s)" << endl;
  cout << "Size of short: " << sizeof(short) << " byte(s)" << endl;
  cout << "Size of int: " << sizeof(int) << " byte(s)" << endl;
  cout << "Size of long: " << sizeof(long) << " byte(s)" << endl;
  cout << "Size of long long: " << sizeof(long long) << " byte(s)" << endl;
  cout << "Size of float: " << sizeof(float) << " byte(s)" << endl;
  cout << "Size of double: " << sizeof(double) << " byte(s)" << endl;
  cout << "Size of long double: " << sizeof(long double) << " byte(s)" << endl;
  cout << "Size of bool: " << sizeof(bool) << " byte(s)" << endl;
  cout << "Size of wchar_t: " << sizeof(wchar_t) << " byte(s)" << endl;

  int *ip;
  cout << "Size of pointer: " << sizeof(ip) << " byte(s)" << endl;
  // std::cout << std::format("{}", b);
}

void useLambda() {
  int a = 10;
  auto lambda = [&a]() { return a; };
  auto b = lambda();
  cout << b;
}
#include <iostream>
#include <memory>
#define asd 0
class A
{
public:
    A() { std::cout << "A()" << std::endl; }
    ~A() { std::cout << "~A()" << std::endl; }
};

class A_RAii
{
public:
    A_RAii()
    {
        std::cout << "A_RAii()" << std::endl;
        a = std::make_unique<A>();
    }
    ~A_RAii() { std::cout << "~A_RAii()" << std::endl; }
    std::unique_ptr<A> a;
    void Release() { a.reset(); }
};
int main()
{
#if asd
    std::cout << "asd" << std::endl;
#endif
    A_RAii *a_raii_heap = new A_RAii();
    delete a_raii_heap;
    std::cout << ("Hello World\n");
    return 0;
}
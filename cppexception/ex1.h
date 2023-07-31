#include <iostream>
// 自定义异常类
class MyException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "My Exception";
    }
};

inline int divide(int a, int b)
{
    if (b == 0)
    {
        // 抛出标准库中的异常类std::runtime_error
        throw std::runtime_error("Divide by zero exception");
    }
    else if (b == 1)
    {
        // 抛出自定义异常类MyException
        throw MyException();
    }
    else
    {
        return a / b;
    }
}

inline void ex1func(int fin)
{
    try
    {

        if (fin > 100)
        {
            throw std::runtime_error("fin>100");
        }
        divide(0, 0);
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Caught std::runtime_error: " << e.what() << std::endl;
    }
    catch (const MyException &e)
    {
        std::cout << "Caught MyException" << std::endl;
    }
}
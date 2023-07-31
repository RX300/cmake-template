#include <iostream>
#include "ex1.h"

int main()
{
    try
    {
        ex1func(1000);
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Caught std::runtime_error: " << e.what() << std::endl;
    }
    catch (const MyException &e)
    {
        std::cout << "Caught MyException" << std::endl;
    }
    return 0;
}
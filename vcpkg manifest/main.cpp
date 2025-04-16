#include <fmt/core.h>
#include <iostream>
#include "glm/glm.hpp"
int main()
{
    glm::vec3 v(1.0f, 2.0f, 3.0f);
    fmt::print("Hello World!\n");
    std::cout<<("Hello World!\n");
    std::cout << "v: " << v.x << ", " << v.y << ", " << v.z << std::endl;
    return 0;
}
#pragma once
#include <iostream>
#include <glm/glm.hpp>
void header()
{
    std::cout << "Hello from header!" << std::endl;
}
void printglm()
{
    glm::vec3 v(1.0f);
    printf("glm::vec3 v(%f, %f, %f)\n", v.x, v.y, v.z);
}

void example1()
{
    std::cout << "Hello from example1!" << std::endl;
}

void example2()
{
    glm::vec3 v(1.5f);
    printf("Hello from example2!:glm::vec3 v(%f, %f, %f)\n", v.x, v.y, v.z);
}
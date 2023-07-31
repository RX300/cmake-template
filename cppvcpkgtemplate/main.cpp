#pragma once
#include<iostream>
#include"glm/glm.hpp"
#include"fmt_hello.h" 
#include"opencv2/opencv.hpp"
//hello world
using namespace std;
int main(){
    //调用openvdb第三方库
    helloopenvdb();
    //调用fmt第三方库
    fmt_hello();
    glm::vec3 a(1,2,3);
    fmt::print("glm::vec3 {} {} {}",a.x,a.y,a.z);
}
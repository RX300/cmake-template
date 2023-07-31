#include<iostream>
#include<cuda.h>
#include<cuda_runtime.h>
__global__ void helloFromGPU(void)
{
    unsigned int id=blockDim.x*blockIdx.x+threadIdx.x;
    printf("Hello World from GPU in thread %d!\n",id);
}
int main()
{
    helloFromGPU<<<10,10>>>();
    //将显示销毁和清理所有和设备有关的进程和资源，常放在代码结尾部分。
    cudaDeviceReset();
    return 0;
}
#include<format>
#include <nanovdb/util/IO.h> // this is required to read (and write) NanoVDB files on the host
#include <nanovdb/util/CudaDeviceBuffer.h> // required for CUDA memory management
extern "C" void launch_kernels(const nanovdb::NanoGrid<float>*,
                               const nanovdb::NanoGrid<float>*,
                               cudaStream_t stream);
///Read a NanoVDB grid from a file and print out multiple values on both the cpu and gpu.
///
/// @note Note This example does NOT depend on OpenVDB, only NanoVDB and CUDA.
int main()
{
    //打印msvc编译器信息
    std::cout << "MSVC version: " << _MSC_VER << std::endl;
    try {
        // returns a GridHandle using CUDA for memory management.
        auto handle = nanovdb::io::readGrid<nanovdb::CudaDeviceBuffer>("../../sphere.nvdb");
        cudaStream_t stream; // Create a CUDA stream to allow for asynchronous copy of pinned CUDA memory.
        cudaStreamCreate(&stream);
        handle.deviceUpload(stream, false); // Copy the NanoVDB grid to the GPU asynchronously
        auto* cpuGrid = handle.grid<float>(); // get a (raw) pointer to a NanoVDB grid of value type float on the CPU
        auto indexboundingBox = cpuGrid->indexBBox(); // get the bounding box of the grid
        auto ibmin = indexboundingBox.min();
        auto ibmax = indexboundingBox.max();
        std::cout<<std::format("Grid bounding indexbox: min = {},{},{} max = {},{},{}", ibmin[0],ibmin[1],ibmin[2],ibmax[0],ibmax[1],ibmax[2])<<std::endl;
        auto worldboundingBox = cpuGrid->worldBBox(); // get the bounding box of the grid
        auto wbmin = worldboundingBox.min();
        auto wbmax = worldboundingBox.max();
        std::cout<<std::format("Grid bounding worldbox: min = {},{},{} max = {},{},{}", wbmin[0],wbmin[1],wbmin[2],wbmax[0],wbmax[1],wbmax[2])<<std::endl;
        auto* deviceGrid = handle.deviceGrid<float>(); // get a (raw) pointer to a NanoVDB grid of value type float on the GPU
        if (!deviceGrid || !cpuGrid)
            throw std::runtime_error("GridHandle did not contain a grid with value type float");
        launch_kernels(deviceGrid, cpuGrid, stream); // Call a host method to print a grid values on both the CPU and GPU
        cudaStreamDestroy(stream); // Destroy the CUDA stream
    }
    catch (const std::exception& e) {
        std::cerr << "An exception occurred: \"" << e.what() << "\"" << std::endl;
    }
    return 0;
}
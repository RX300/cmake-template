// 打印当前目录下的所有文件和目录
// c++17以后的文件系统库
#include <filesystem>
#include <iostream>
#include <vector>
#include <string>

int main()
{
// 从CMake传入的工作目录
#ifdef WORKING_DIRECTORY
    std::filesystem::path workingDir = WORKING_DIRECTORY;
    std::filesystem::current_path(workingDir);
#endif

    std::filesystem::path currentPath = std::filesystem::current_path();
    std::cout << "Current path is: " << currentPath << std::endl;

    std::cout << "Files and directories in current path: " << std::endl;

    std::vector<std::string> v;
    for (const auto &entry : std::filesystem::directory_iterator("."))
    {
        v.push_back(entry.path().string());
    }
    for (const auto &s : v)
    {
        std::cout << s << std::endl;
    }

    system("pause");
    return 0;
}
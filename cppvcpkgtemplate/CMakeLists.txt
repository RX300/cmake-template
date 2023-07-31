cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(cmake_vcpkg)

list(APPEND SRC_LIST main.cpp)

add_executable(vcpkg_hello ${SRC_LIST})

target_include_directories(vcpkg_hello PUBLIC include)

find_package(fmt CONFIG REQUIRED)
message(STATUS "fmt    config: ${fmt_DIR}")
message(STATUS "fmt    version: ${fmt_VERSION}")
message(STATUS "fmt    include: ${fmt_INCLUDE_DIRS}")
message(STATUS "fmt    libraries: ${fmt_LIBS}")
target_link_libraries(vcpkg_hello PRIVATE fmt::fmt)

find_package(glm CONFIG REQUIRED)
message(STATUS "glm    config: ${glm_DIR}")
message(STATUS "glm    version: ${glm_VERSION}")
message(STATUS "glm    include: ${glm_INCLUDE_DIRS}")
message(STATUS "glm    libraries: ${glm_LIBS}")
target_link_libraries(vcpkg_hello PRIVATE glm::glm)

find_package(OpenCV REQUIRED)

# 打印
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    include: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "    libraries: ${OpenCV_LIBS}")

# Link your application with Opencv libraries
target_link_libraries(vcpkg_hello PRIVATE ${OpenCV_LIBS})

# 找到第三方包openvdb
find_package(OpenVDB CONFIG REQUIRED)

# 打印
message(STATUS "OpenVDB    config: ${OpenVDB_DIR}")
message(STATUS "OpenVDB    version: ${OpenVDB_VERSION}")
message(STATUS "OpenVDB    include: ${OpenVDB_INCLUDE_DIRS}")
message(STATUS "OpenVDB    libraries: ${OpenVDB_LIBS}")

# 链接openvdb库
target_link_libraries(vcpkg_hello PRIVATE OpenVDB::openvdb)

find_package(glad CONFIG REQUIRED)
target_link_libraries(vcpkg_hello PRIVATE glad::glad)
cmake_minimum_required(VERSION 3.25)
project(
    wrapper
)

add_subdirectory(headeronly)
add_subdirectory(lib)

add_library(
    wrapper
    INTERFACE
)

# target_include_directories(
# wrapper
# INTERFACE
# .
# )
target_link_libraries(
    wrapper
    INTERFACE
    headerOnly
    lib
)

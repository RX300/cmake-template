# 定义一个函数 print_files，它接受一个名为 FILE_LIST 的参数
function(print_files FILE_LIST)
    # 遍历列表中的每个文件
    # ARGC 传入参数的个数
    # ARGV 传入的参数列表
    # ARGV0 第一个参数...
    # ARGN 除了第一个参数以外的参数列表
    foreach(FILE_PATH IN LISTS ARGV)
        # 打印文件路径
        message(STATUS "File: ${FILE_PATH}")
    endforeach()
endfunction()
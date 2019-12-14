# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(05.20 Array.h Array.c 05.20.c)
# 链接公共库
target_link_libraries(05.20 Scanf_lib)
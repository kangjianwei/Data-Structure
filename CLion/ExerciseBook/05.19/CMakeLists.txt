# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(05.19 Array.h Array.c 05.19.c)
# 链接公共库
target_link_libraries(05.19 Scanf_lib)
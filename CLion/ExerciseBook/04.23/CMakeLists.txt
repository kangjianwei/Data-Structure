# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(04.23 LString.h LString.c 04.23.c)
# 链接公共库
target_link_libraries(04.23 Scanf_lib)
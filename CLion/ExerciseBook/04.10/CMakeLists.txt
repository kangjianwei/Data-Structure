# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(04.10 String.h String.c 04.10.c)
# 链接公共库
target_link_libraries(04.10 Scanf_lib)
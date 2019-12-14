# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(04.13 String.h String.c 04.13.c)
# 链接公共库
target_link_libraries(04.13 Scanf_lib)
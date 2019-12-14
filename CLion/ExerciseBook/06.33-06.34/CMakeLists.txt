# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(06.33-06.34 06.33-06.34.c)
# 链接公共库
target_link_libraries(06.33-06.34 Scanf_lib)
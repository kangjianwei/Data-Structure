# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(06.35 06.35.c)
# 链接公共库
target_link_libraries(06.35 Scanf_lib)
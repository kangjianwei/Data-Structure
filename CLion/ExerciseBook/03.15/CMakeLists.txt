# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件，并链接公共库
add_executable(03.15 03.15.c)
target_link_libraries(03.15 Scanf_lib)

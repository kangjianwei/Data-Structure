# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件，并链接公共库
add_executable(02.22 LinkList.h LinkList.c 02.22.c)
target_link_libraries(02.22 Scanf_lib)

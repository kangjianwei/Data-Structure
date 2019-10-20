# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件，并链接公共库
add_executable(02.13 LinkList.h LinkList.c 02.13.c)
target_link_libraries(02.13 Scanf_lib)

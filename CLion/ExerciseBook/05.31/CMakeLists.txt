# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(05.31 SString.h SString.c GList-E.h GList-E.c 05.31.c)
# 链接公共库
target_link_libraries(05.31 Scanf_lib)
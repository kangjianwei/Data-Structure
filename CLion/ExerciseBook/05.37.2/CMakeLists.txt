# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(05.37.2 SString.h SString.c GList-E.h GList-E.c 05.37.2.c)
# 链接公共库
target_link_libraries(05.37.2 Scanf_lib)
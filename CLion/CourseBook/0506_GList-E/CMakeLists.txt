# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(GList-E SString.h SString.c GList-E.h GList-E.c GList-E-main.c)
# 链接公共库
target_link_libraries(GList-E Scanf_lib)
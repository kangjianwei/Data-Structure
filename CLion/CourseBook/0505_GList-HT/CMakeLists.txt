# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(GList-HT SString.h SString.c GList-HT.h GList-HT.c GList-HT-main.c)
# 链接公共库
target_link_libraries(GList-HT Scanf_lib)
# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(05.37.1 SString.h SString.c GList-HT.h GList-HT.c 05.37.1.c)
# 链接公共库
target_link_libraries(05.37.1 Scanf_lib)
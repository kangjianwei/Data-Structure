# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(05.35-05.36 SString.h SString.c GList.h GList.c 05.35-05.36.c)
# 链接公共库
target_link_libraries(05.35-05.36 Scanf_lib)
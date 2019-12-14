# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(MPList StringUtil.h StringUtil.c MPList.h MPList.c MPList-main.c)
# 链接公共库
target_link_libraries(MPList Scanf_lib)
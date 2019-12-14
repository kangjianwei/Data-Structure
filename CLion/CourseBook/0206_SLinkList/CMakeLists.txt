# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(SLinkList SLinkList.h SLinkList.c SLinkList-main.c)
# 链接公共库
target_link_libraries(SLinkList Scanf_lib)
# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(MergeSqList SqList.h SqList.c MergeSqList.h MergeSqList.c MergeSqList-main.c)
# 链接公共库
target_link_libraries(MergeSqList Scanf_lib)
# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(SqStack SqStack.h SqStack.c SqStack-main.c)
# 链接公共库
target_link_libraries(SqStack Scanf_lib)
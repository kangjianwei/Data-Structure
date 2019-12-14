# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(Expression SqStack.h SqStack.c Expression.h Expression.c Expression-main.c)
# 链接公共库
target_link_libraries(Expression Scanf_lib)
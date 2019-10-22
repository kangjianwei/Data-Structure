# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(Conversion SqStack.h SqStack.c Conversion.h Conversion.c Conversion-main.c)
# 链接公共库
target_link_libraries(Conversion Scanf_lib)
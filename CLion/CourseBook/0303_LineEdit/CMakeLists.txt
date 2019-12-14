# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(LineEdit SqStack.h SqStack.c LineEdit.h LineEdit.c LineEdit-main.c)
# 链接公共库
target_link_libraries(LineEdit Scanf_lib)
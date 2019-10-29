# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(KMP SString.h SString.c KMP.h KMP.c KMP-main.c)
# 链接公共库
target_link_libraries(KMP Scanf_lib)
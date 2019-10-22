# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(BankQueuing LinkList.h LinkList.c LinkQueue.h LinkQueue.c BankQueuing.h BankQueuing.c BankQueuing-main.c)
# 链接公共库
target_link_libraries(BankQueuing Scanf_lib)
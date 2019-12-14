# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(06.51 LinkQueue.h LinkQueue.c BiTree.h BiTree.c 06.51.c)
# 链接公共库
target_link_libraries(06.51 Scanf_lib)

# 记录要拷贝到*.exe目录下的资源文件
file(GLOB TestData TestData*.txt)
# 将资源文件拷贝到*.exe目录下，不然无法加载
file(COPY ${TestData} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

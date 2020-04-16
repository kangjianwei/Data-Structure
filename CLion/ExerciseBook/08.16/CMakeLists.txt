# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(08.16 SqList.h SqList.c MemoryManager.h MemoryManager.c 08.16.c)
# 链接公共库
target_link_libraries(08.16 Scanf_lib)

# 记录要拷贝到*.exe目录下的资源文件（这里拷贝了TestData.md文件）
file(GLOB TestData TestData*)
# 将资源文件拷贝到*.exe目录下，不然无法加载
file(COPY ${TestData} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

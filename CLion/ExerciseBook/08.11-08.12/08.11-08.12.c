#include <stdio.h>
#include "Status.h"
#include "SqStack.h"

/* 宏定义 */
#define MAXSIZE 200 // 内存总大小


/* 空闲空间类型定义 */
typedef struct {
    void* base;     // 可用空间内存的起始地址
    int size;       // 空闲空间大小(按字节计数)
    SqStack block;  // 已经使用的内存块大小，先申请的内存信息先入栈
} Space;


// 初始化内存空间及内存信息栈
void InitSpace(Space* space);

// 打印内存布局，查看当前内存的使用情况
void PrintMemoryLayout(Space space);

// 申请大小为n的内存块，返回申请到的内存起始地址
void* Algo_8_11(Space* space, int n);

// 回收内存，遵循"最后分配者最先释放"的原则
Status Algo_8_12(Space* space);


int main(int argc, char* argv[]) {
    Space space;
    int s[5] = {50, 50, 150, 100, 50}; // 定义内存申请数量
    int i;
    
    // 初始化内存
    InitSpace(&space);
    PrintMemoryLayout(space);
    printf("\n");
    
    // 申请/释放内存
    for(i = 0; i < 5; i++) {
        printf("申请 %d 个内存后...\n", s[i]);
        Algo_8_11(&space, s[i]);
        PrintMemoryLayout(space);
        printf("\n");
    }
    
    return 0;
}


// 初始化一块空闲空间
void InitSpace(Space* space) {
    // 申请MAX字节的空间(假设总能初始化成功)
    space->base = malloc(MAXSIZE);
    space->size = MAXSIZE;
    
    // 初始化内存信息栈
    InitStack(&(space->block));
}

// 打印内存布局，查看当前内存的使用情况
void PrintMemoryLayout(Space space) {
    int i;
    
    for(i = 1; i <= MAXSIZE; i++) {
        if(i <= space.size) {
            printf("□");
        } else {
            printf("■");
        }
        
        // 预定每隔20个换一下行
        if(i % 20 == 0) {
            printf("\n");
        }
    }
    
    if(MAXSIZE % 20 != 0) {
        printf("\n");
    }
}

// 申请大小为n的内存块，返回申请到的内存起始地址
void* Algo_8_11(Space* space, int n) {
    
    /*
     * 如果可用的内存数量少于申请的内存数量，
     * 则需要释放最近申请使用的内存以腾出空间。
     */
    while(space->size < n && Algo_8_12(space) == OK) {
        // 直到空闲内存满足申请要求，或者全部占用内存已经释放，才会退出循环
    }
    
    // 如果没有足够的内存可用，则返回空指针
    if(space->size < n) {
        return NULL;
    }
    
    // 可用空间减小
    space->size -= n;
    
    // 记下成功申请到的内存
    Push(&(space->block), n);
    
    // 返回申请到的内存起始地址
    return space->base + space->size;
}

// 回收内存，遵循"最后分配者最先释放"的原则
Status Algo_8_12(Space* space) {
    int e;
    
    // 已经没有可释放内存时，返回ERROR
    if(StackEmpty(space->block)) {
        return ERROR;
    }
    
    // 将最后申请的内存释放掉
    Pop(&(space->block), &e);
    
    // 可用空间增大
    space->size += e;
    
    return OK;
}

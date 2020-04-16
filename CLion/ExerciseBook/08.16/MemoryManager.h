/*=======================
 * 存储管理，适用于习题8.16
 ========================*/

#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqList.h"


#define MAXSIZE 100     // 最大内存量
#define e 0             // 容差

#define BYTE sizeof(char)   // 1个字节


// 内存记录类型定义
typedef struct {
    int addr;   // 新地址域，存储内存块的当前最新地址，初始值是空间首地址
    int size;   // 块大小
    int tag;    // 标志域，指示内存是正在使用(1)还是空闲状态(0)
    
    /* 存储块之间的链接关系，这与用户在虚拟地址层看到的链接关系可能并不一致 */
    int pre;    // 前驱
    int next;   // 后继
    
    int oldAddr; // 进行存储紧缩后的旧地址
} Record;

// 可用空间类型定义
typedef struct {
    void* base;          // 内存起始地址
    SqList recordList;   // 内存使用记录
    int cur;             // 记录空闲块的内存记录的位置，初值为1
    
    /*
     * 记录虚拟地址。
     * 这其实是在模拟操作系统的行为：
     * 用户使用的地址跟硬件的实际地址可能并不一致，所以需要操作系统构造一个虚拟地址集。
     */
    SqList ptrList;
} Space;


// 初始化一片可用的存储
void InitSpace(Space* space);

// 分配大小为n的内存，并返回指向该内存的虚拟地址
int* AllocMemory(Space* space, int n);

// 释放虚拟地址p处的内存
void FreeMemory(Space* space, int* p);

// 将虚拟地址addr转换为底层的真实地址
void* getPtr(Space space, const int* addr);

// 打印内存布局，显示格式为：首地址 块大小 标志域 | 前驱 后继 | 数据
void PrintMemoryLayout(Space space);

#endif

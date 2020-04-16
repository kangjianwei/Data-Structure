/*=======================
 * 存储管理，适用于习题8.15
 ========================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H


/* 宏定义 */
#define MAXSIZE 100 // 内存总容量
#define e 5         // 分配空间时用到的容差


/*
 * 内存"字"的类型定义
 *
 * 所谓"字"是指空间分配的最小单位，它不是字节。
 * 一个"字"有多大，取决于对"字"结构是如何定义的。
 */
typedef struct WORD {
    int tag;            // 块标志，0空闲，1占用
    int cellsize;       // 当前块的大小
    struct WORD* next;  // 指向下一个空闲块
    
    
    /*
     * 使用标记，0代表空闲，1代表占用，-1代表虽然空闲，但是不在空闲链表中。
     * 这个标记仅用来测试打印功能，并没有其它实质性的用处。
     */
    int flag;
} WORD;

// "堆"空间
typedef struct {
    struct WORD* lowbound;  // 空间下界
    struct WORD* highbound; // 空间上界
    struct WORD* avail; // 指向可用空间链表
} Space;


// 初始化一片可用的存储
void InitSpace(Space* space);

// 分配大小为n的内存，并返回指向该内存的虚拟地址
WORD* AllocMemory(Space* space, int n);

// 释放指针p处的内存
void FreeMemory(Space* space, WORD* p);

// 打印内存布局
void PrintMemoryLayout(Space space);

#endif

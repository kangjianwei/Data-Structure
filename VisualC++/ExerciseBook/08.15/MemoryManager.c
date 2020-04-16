/*=======================
 * 存储管理，适用于习题8.15
 ========================*/

#include "MemoryManager.h"

// 初始化一片可用的存储
void InitSpace(Space* space) {
    space->avail = (WORD*) malloc(MAXSIZE * sizeof(WORD));
    space->avail->tag = 0;
    space->avail->cellsize = MAXSIZE;
    space->avail->next = NULL;
    
    space->lowbound = space->avail;
    space->highbound = space->avail + MAXSIZE;
}

// 分配大小为n的内存，并返回指向该内存的虚拟地址
WORD* AllocMemory(Space* space, int n) {
    WORD* p, * q;
    
    if(space->avail == NULL) {
        return NULL;
    }
    
    p = space->avail;
    q = NULL;
    
    // 如果第一个空闲块不满足条件
    if(p->cellsize < n) {
        // 查找满足条件的空闲内存
        while(p != NULL && p->cellsize < n) {
            q = p;
            p = p->next;
        }
    }
    
    // 没有符合条件的空闲内存
    if(p == NULL) {
        return NULL;
    }
    
    // 在容差范围内，则整块分配
    if(p->cellsize - e <= n) {
        if(q == NULL) {
            space->avail = p->next;
        } else {
            q->next = p->next;
        }
        
        // 分割空闲块
    } else {
        
        if(q == NULL) {
            space->avail += n;
            space->avail->tag = 0;
            space->avail->cellsize = p->cellsize - n;
            space->avail->next = p->next;
        } else {
            q->next = p + n;
            q->next->tag = 0;
            q->next->cellsize = p->cellsize - n;
        }
        
        p->cellsize = n;
    }
    
    // 标记为占用
    p->tag = 1;
    
    return p;
}

// 释放指针p处的内存
void FreeMemory(Space* space, WORD* p) {
    p->tag = 0; // 简单地标记为空闲，以待后续整理
}

// 打印内存布局
void PrintMemoryLayout(Space space) {
    int i, count;
    WORD* p;
    
    // 遍历所有块
    for(p = space.lowbound; p < space.highbound; p += p->cellsize) {
        if(p->tag == 0) {
            p->flag = -1;  // 暂时标记为"不可用"的空闲块
        } else {
            p->flag = 1;   // 标记为占用
        }
    }
    
    // 遍历空闲块链表
    for(p = space.avail; p != NULL; p = p->next) {
        p->flag = 0;       // 更新为"可用"的空闲块
    }
    
    count = 0;
    
    for(p = space.lowbound; p < space.highbound; p += p->cellsize) {
        for(i = 0; i < p->cellsize; i++) {
            switch(p->flag) {
                case -1:
                    printf("△");
                    break;
                case 0:
                    printf("□");
                    break;
                case 1:
                    printf("■");
                    break;
                default:
                    printf("错误的标记！\n");
                    return;
            }
            
            count++;
            // 每隔20个字换一下行
            if(count % 20 == 0) {
                printf("\n");
            }
        }
        
    }
    
    if(count % 20 != 0) {
        printf("\n");
    }
    
    printf("\n");
}

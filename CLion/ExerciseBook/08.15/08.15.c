#include <stdio.h>
#include "MemoryManager.h"

/*
 * 内存整理
 *
 * 将空闲块收集起来，链接成一条空闲块链表。
 */
void Algo_8_15(Space* space);


int main(int argc, char** argv) {
    Space space;
    int i;
    int a[11] = {10, 20, 30, 15, 20, 5, -1, -3, 0, 15, 10};
    WORD* p[11];
    
    InitSpace(&space);
    printf("初始内存布局：\n");
    PrintMemoryLayout(space);
    
    /*
     * 注：
     * 申请a[4]时，仅剩25个"字"，当前容差是5，因此本次会直接分配20+5=25个"字"
     * 申请a[5]时，已经没有可用的字，所以申请失败
     * 申请a[10]时，处在容差范围内，会整块分配
     */
    for(i = 0; i < 11; i++) {
        if(a[i] > 0) {
            printf("+ 申请 %d 个字的存储\n", a[i]);
            p[i] = AllocMemory(&space, a[i]);
        } else {
            printf("- 释放 %d 个字的存储\n", a[-a[i]]);
            FreeMemory(&space, p[-a[i]]);
        }
        
        PrintMemoryLayout(space);
        
        if(i == 8) {
            printf("内存整理...\n");
            Algo_8_15(&space);
            PrintMemoryLayout(space);
        }
    }
}


/*
 * 内存整理
 *
 * 将空闲块收集起来，链接成一条空闲块链表。
 */
void Algo_8_15(Space* space) {
    WORD* p, * q;
    
    space->avail = NULL;
    
    q = NULL;
    
    // 遍历整个堆
    for(p = space->lowbound; p < space->highbound; p += p->cellsize) {
        if(p->tag == 1) {
            continue;
        }
        
        // 先把后继置空
        p->next = NULL;
        
        // 遇到了第一个空闲块
        if(space->avail == NULL) {
            space->avail = p;
            q = p;
            continue;
        }
        
        // 如果两个空闲块地址不相邻，则进行链接
        if(q + q->cellsize != p) {
            q->next = p;
            
            // 对于地址相邻的空闲块，要合并
        } else {
            q->cellsize += p->cellsize;
        }
    }
}

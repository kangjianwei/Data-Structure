#include <stdio.h>
#include "BuddySystem.h"    //**▲08 动态存储管理**//

/*
 * 伙伴系统的内存回收算法
 *
 * 对指针p处的内存进行释放(这类似于free()，只是对内存进行释放操作，至于置空指针p的操作，应交给调用方完成)
 *
 * 注：这里没有验证p的取值，调用方应当确保p在合规的范围
 */
void Algo_8_14(FreeList avail, WORD* p);


int main(int argc, char* argv[]) {
    FreeList avail;
    WORD* p[8];     // 记录申请到的内存的指针
    int s[8] = {4, 5, 6, 7, 1, 5, 3, 9};    // 申请的空间大小
    int i;
    
    printf("████████ InitSpace \n");
    {
        printf("初始化一个内存块...\n");
        InitSpace(avail);
        PrintMemoryLayout();
        printf("\n");
    }
    PressEnterToContinue(debug);
    
    printf("████████ AllocBuddy \n");
    {
        for(i = 0; i < 8; i++) {
            printf("申请大小为 %d 个字的内存块...\n", s[i]);
            p[i] = AllocBuddy(avail, s[i]);
            PrintMemoryLayout();
            printf("\n");
        }
    }
    PressEnterToContinue(debug);
    
    printf("████████ FreeBuddy \n");
    {
        // 定义一个指针回收顺序
        int a[8] = {2, 0, 5, 7, 1, 4, 3, 6};
        
        for(i = 0; i < 8; i++) {
            Algo_8_14(avail, p[a[i]]);
            PrintMemoryLayout();
            printf("\n");
        }
    }
    PressEnterToContinue(debug);
    
    return 0;
}


/*
 * 伙伴系统的内存回收算法
 *
 * 对指针p处的内存进行释放(这类似于free()，只是对内存进行释放操作，至于置空指针p的操作，应交给调用方完成)
 *
 * 注：这里没有验证p的取值，调用方应当确保p在合规的范围
 */
void Algo_8_14(FreeList avail, WORD* p) {
    FreeBuddy(avail, p);
}

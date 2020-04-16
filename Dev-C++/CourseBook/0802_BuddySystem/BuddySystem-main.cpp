#include <stdio.h>
#include "BuddySystem.h"    //**▲08 动态存储管理**//

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
            FreeBuddy(avail, p[a[i]]);
            PrintMemoryLayout();
            printf("\n");
        }
    }
    PressEnterToContinue(debug);

    return 0;
}


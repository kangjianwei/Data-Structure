#include <stdio.h>
#include "BoundaryTagMethod.h"      //**▲08 动态存储管理**//

/*
 * 边界标识法的内存回收算法
 *
 * 对指针p处的内存进行释放
 */
void Algo_8_13(Space* pav, Space p);


int main(int argc, char* argv[]) {
    Space pav;
    Space p[12];    // 记录申请到的内存的指针
    int s[12] = {10, 20, 30, 50, 5, 15, 10, 5, 15, 15, 2, 20};  // 申请的空间大小
    int i = 0;
    
    printf("████████ InitSpace \n");
    {
        int max = 200;  // 初值建议为20的倍数，目的是打印出来可以对齐
        
        printf("初始化包含 %d 个\"字\"的内存块后，当前内存布局为：\n", max);
        pav = InitSpace(max);
        PrintMemoryLayout();
        printf("\n");
    }
    PressEnterToContinue(debug);
    
    printf("████████ AllocBoundTag \n");
    {
        for(i = 0; i < 12; i++) {
            printf("████ %2d> 申请 %d 个\"字\"的内存后，当前内存布局为：\n", i + 1, s[i]);
            p[i] = AllocBoundTag(&pav, s[i]);
            PrintMemoryLayout();
            printf("\n");
        }
    }
    PressEnterToContinue(debug);
    
    printf("████████ FreeBoundTag \n");
    {
        // 定义一个指针回收顺序
        int a[10] = {7, 3, 10, 6, 8, 5, 11, 1, 0, 4};
        
        for(i = 0; i < 10; i++) {
            printf("回收 p%d 指向的内存...\n", a[i] + 1);
            Algo_8_13(&pav, p[a[i]]);
            PrintMemoryLayout();
            printf("\n");
        }
    }
    PressEnterToContinue(debug);
    
    return 0;
}


/*
 * 边界标识法的内存回收算法
 *
 * 对指针p处的内存进行释放
 */
void Algo_8_13(Space* pav, Space p) {
    FreeBoundTag(pav, p);
}

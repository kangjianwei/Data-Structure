#include <stdio.h>
#include "SqList.h"
#include "MergeSqList.h"                //**▲02 线性表**//

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    ElemType a[4] = {3, 5, 8, 11};
    ElemType b[7] = {2, 6, 8, 9, 11, 15, 20};
    
    SqList La, Lb, Lc1, Lc2;
    int i;
    
    // 初始化La
    InitList(&La);
    for(i = 1; i <= 4; i++) {
        ListInsert(&La, i, a[i - 1]);
    }
    
    // 初始化Lb
    InitList(&Lb);
    for(i = 1; i <= 7; i++) {
        ListInsert(&Lb, i, b[i - 1]);
    }
    
    // 输出La
    printf("La = ");
    ListTraverse(La, PrintElem);
    
    // 输出Lb
    printf("Lb = ");
    ListTraverse(Lb, PrintElem);
    
    // 归并顺序表La和Lb，算法2.2
    MergeSqList_1(La, Lb, &Lc1);
    printf("归并La和Lb为Lc1 = ");
    ListTraverse(Lc1, PrintElem);
    
    // 归并顺序表La和Lb，算法2.7
    MergeSqList_2(La, Lb, &Lc2);
    printf("归并La和Lb为Lc2 = ");
    ListTraverse(Lc2, PrintElem);
    
    return 0;
}

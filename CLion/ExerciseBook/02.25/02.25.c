#include <stdio.h>
#include "Status.h"    //**▲01 绪论**//
#include "SqList.h"    //**▲02 线性表**//

/*
 * 题2.25
 *
 * 求交集：C=A∩B。
 */
Status Algo_2_25(SqList La, SqList Lb, SqList* Lc);

// 测试函数，打印元素
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    SqList La, Lb, Lc;
    int i;
    
    int a[10] = {1, 2, 2, 3, 4, 4, 9, 9, 10, 12};
    int b[10] = {1, 1, 2, 2, 3, 3, 4, 5, 12, 13};
    
    // 准备测试数据
    InitList(&La);
    InitList(&Lb);
    for(i = 1; i <= 10; i++) {
        ListInsert(&La, i, a[i - 1]);
        ListInsert(&Lb, i, b[i - 1]);
    }
    
    printf("La = ");
    ListTraverse(La, PrintElem);
    
    printf("Lb = ");
    ListTraverse(Lb, PrintElem);
    
    // 求交集
    Algo_2_25(La, Lb, &Lc);
    
    printf("Lc = ");
    ListTraverse(Lc, PrintElem);
    
    return 0;
}

// 求交集：C=A∩B
Status Algo_2_25(SqList La, SqList Lb, SqList* Lc) {
    int i, j, k;
    
    // 确保La和Lb存在
    if(La.elem == NULL || Lb.elem == NULL) {
        return ERROR;
    }
    
    InitList(Lc);
    
    i = j = 0;  // 遍历La和Lb
    k = 0;      // 遍历Lc
    
    // 只遍历La和Lb的共同部分就行
    while(i < La.length && j < Lb.length) {
        if(La.elem[i] < Lb.elem[j]) {
            i++;
        } else if(La.elem[i] > Lb.elem[j]) {
            j++;
            // 如果La和Lb中的元素相等
        } else {
            // Lc中元素可能重复
            ListInsert(Lc, k+1, La.elem[i]);
            k++;
            i++;
            j++;
        }
    }
    
    return OK;
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}

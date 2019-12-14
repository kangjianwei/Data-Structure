#include <stdio.h>
#include "Status.h"    //**▲01 绪论**//
#include "SqList.h"    //**▲02 线性表**//

/*
 * 题2.29
 *
 * A=A-B∩C。
 */
Status Algo_2_29(SqList* La, SqList Lb, SqList Lc);

// 测试函数，打印元素
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    SqList La, Lb, Lc;
    int i;
    
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {1, 2, 2, 3, 4, 4, 9, 9, 10, 12};
    int c[10] = {1, 1, 2, 2, 3, 3, 4, 5, 12, 13};
    
    // 准备测试数据
    InitList(&La);
    InitList(&Lb);
    InitList(&Lc);
    for(i = 1; i <= 10; i++) {
        ListInsert(&La, i, a[i - 1]);
        ListInsert(&Lb, i, b[i - 1]);
        ListInsert(&Lc, i, c[i - 1]);
    }
    
    printf("La = ");
    ListTraverse(La, PrintElem);
    printf("Lb = ");
    ListTraverse(Lb, PrintElem);
    printf("Lc = ");
    ListTraverse(Lc, PrintElem);
    
    
    // 处理后
    Algo_2_29(&La, Lb, Lc);
    
    printf("La = La-Lb∩Lc = ");
    ListTraverse(La, PrintElem);
    
    return 0;
}

// A=A-B∩C
Status Algo_2_29(SqList* La, SqList Lb, SqList Lc) {
    int i, j, k, count;
    
    if(La==NULL || (*La).elem==NULL || Lb.elem==NULL || Lc.elem==NULL) {
        return ERROR;
    }
    
    i = j = k = 0;
    count = 0;
    
    // 获取B和C的交集，然后将其从A中删除
    while(i < (*La).length && j < Lb.length && k < Lc.length) {
        if(Lb.elem[j] < Lc.elem[k]) {
            j++;
        } else if(Lb.elem[j] > Lc.elem[k]) {
            k++;
        } else {
            // 在A中查找交集元素
            while(i < (*La).length && (*La).elem[i] < Lb.elem[j]) {
                (*La).elem[count] = (*La).elem[i];
                count++;
                i++;
            }
            
            // 跳过交集元素
            while(i < (*La).length && (*La).elem[i] == Lb.elem[j]) {
                i++;
            }
            
            // A还没有遍历完
            if(i < (*La).length) {
                j++;
                k++;
            }
        }
    }
    
    // 将剩余的元素放到合适的位置
    while(i < (*La).length) {
        (*La).elem[count] = (*La).elem[i];
        count++;
        i++;
    }
    
    (*La).length = count;
    
    return OK;
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%2d ", e);
}

#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "SqList.h"     //**▲02 线性表**//

/*
 * 题2.21
 *
 * 顺序表逆置。
 */
Status Algo_2_21(SqList L);

// 测试函数，打印元素
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    SqList L;
    int i;
    
    // 准备测试数据
    InitList(&L);
    for(i = 1; i <= 10; i++) {
        ListInsert(&L, i, i);
    }
    
    printf("顺序：L = ");
    ListTraverse(L, PrintElem);
    
    Algo_2_21(L);
    
    printf("逆置：L = ");
    ListTraverse(L, PrintElem);
    
    return 0;
}


// 顺序表逆置
Status Algo_2_21(SqList L) {
    int i, mid;
    ElemType tmp;
    
    // 确保顺序表存在
    if(L.elem == NULL) {
        return ERROR;
    }
    
    // 只需要遍历前一半的元素即可
    mid = L.length / 2;
    
    for(i = 1; i <= mid; i++) {
        tmp = L.elem[i - 1];
        L.elem[i - 1] = L.elem[L.length - i];
        L.elem[L.length - i] = tmp;
    }
    
    return OK;
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%2d ", e);
}

#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "SqList.h"     //**▲02 线性表**//

/*
 * 题2.10
 *
 * 删除顺序表中从第i个元素起的k个元素
 * 如果i和k的值不合规，则顺序表不会有变化
 */
Status Algo_2_10(SqList* a, int i, int k);

// 测试函数，打印元素
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    SqList L;
    int i;
    
    // 初始化顺序表
    InitList(&L);
    
    // 填充值
    for(i = 1; i <= 15; i++) {
        ListInsert(&L, i, i);
    }
    
    printf("删除前：L = ");
    ListTraverse(L, PrintElem);
    
    printf("删除第 6 个元素起的 5 个元素...\n");
    Algo_2_10(&L, 6, 5);
    
    printf("删除后：L = ");
    ListTraverse(L, PrintElem);
    
    return 0;
}


// 删除顺序表中从第i个元素起的k个元素
Status Algo_2_10(SqList* a, int i, int k) {
    int j;
    
    // 确保顺序表存在
    if(a == NULL || a->elem == NULL) {
        return ERROR;
    }
    
    // 下标越界
    if(i < 1 || i > (*a).length || k < 0 || i + k - 1 > (*a).length) {
        return ERROR;
    }
    
    for(j = i; j <= i + k - 1; j++) {
        (*a).elem[j - 1] = (*a).elem[j + k - 1];
    }
    
    (*a).length -= k;
    
    return OK;
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}

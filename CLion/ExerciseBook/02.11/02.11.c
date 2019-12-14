#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//
#include "SqList.h"     //**▲02 线性表**//

/*
 * 题2.11
 *
 * 将x插入到递增序列va中
 */
Status Algo_2_11(SqList* va, ElemType x);

// 判断data>e是否成立
Status CmpGreater(ElemType data, ElemType e);

// 测试函数，打印元素
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    SqList L;
    int i;
    
    // 初始化顺序表
    InitList(&L);
    
    // 填充值
    for(i = 1; i <= 5; i++) {
        ListInsert(&L, i, 2 * i);
    }
    
    printf("插入前：L = ");
    ListTraverse(L, PrintElem);
    
    printf("将元素\"5\"插入到顺序表中...\n");
    Algo_2_11(&L, 5);
    
    printf("插入后：L = ");
    ListTraverse(L, PrintElem);
    
    return 0;
}


// 将x插入到递增序列va中
Status Algo_2_11(SqList* va, ElemType x) {
    int i, j;
    ElemType* newbase;
    
    // 确保顺序表存在
    if(va == NULL || va->elem == NULL) {
        return ERROR;
    }
    
    // 若存储空间已满，需开辟新空间
    if((*va).length == (*va).listsize) {
        newbase = (ElemType*) realloc((*va).elem, ((*va).listsize + LISTINCREMENT) * sizeof(ElemType));
        if(newbase == NULL) {
            exit(OVERFLOW);
        }
        
        (*va).elem = newbase;
        (*va).listsize += LISTINCREMENT;
    }
    
    // 查找顺序表中首个大于元素x的元素位序，这个位序就是x需要插入的位置
    i = LocateElem(*va, x, CmpGreater);
    if(i == 0) {
        // 需要插入到顺序表最后
        i = (*va).length + 1;
    }
    
    // 元素后移，腾出位置。注意j是位序，减1之后才是索引
    for(j=(*va).length + 1; j>i; j--){
        (*va).elem[j-1] = (*va).elem[j-2];
    }
    
    (*va).elem[j-1] = x;
    (*va).length++;
    
    return OK;
}

// 判断data>e是否成立
Status CmpGreater(ElemType data, ElemType e) {
    return data > e ? TRUE : FALSE;
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}

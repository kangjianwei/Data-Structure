#include <stdio.h>
#include "LinkList.h"   //**▲02 线性表**//

/*
 * 题2.14
 *
 * 获取顺序表L的长度。
 */
int Algo_2_14(LinkList L);

// 测试函数，打印元素
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    LinkList L;
    int i;
    
    // 初始化顺序表
    InitList(&L);
    
    // 填充值
    for(i = 1; i <= 15; i++) {
        ListInsert(L, i, 2 * i);
    }
    
    // 输出顺序表
    printf("L = ");
    ListTraverse(L, PrintElem);
    
    printf("链表L的长度为 %d \n", Algo_2_14(L));
    
    return 0;
}


// 获取顺序表L的长度
int Algo_2_14(LinkList L) {
    // 直接调用链表的计数函数
    return ListLength(L);
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}

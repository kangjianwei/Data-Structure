#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "LinkList.h"   //**▲02 线性表**//

/*
 * 题2.13
 *
 * 寻找元素x在L中的位置。
 * 如果返回0，则说明x不存在。
 */
int Algo_2_13(LinkList L, ElemType x);

// 判断data==e是否成立
Status Equals(ElemType data, ElemType e);

// 测试函数，打印元素
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    LinkList L;
    int i;
    
    // 初始化顺序表
    InitList(&L);
    
    // 填充值
    for(i = 1; i <= 10; i++) {
        ListInsert(L, i, 2 * i);
    }
    
    // 输出顺序表
    printf("L = ");
    ListTraverse(L, PrintElem);
    
    printf("元素 \"12\" 在链表L中的位置为 %d \n", Algo_2_13(L, 12));
    
    return 0;
}


// 寻找元素x在L中的位置
int Algo_2_13(LinkList L, ElemType x) {
    // 直接调用链表的查找函数
    return LocateElem(L, x, Equals);
}

// 判断data==e是否成立
Status Equals(ElemType data, ElemType e) {
    if(data == e) {
        return TRUE;
    } else {
        return FALSE;
    }
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}

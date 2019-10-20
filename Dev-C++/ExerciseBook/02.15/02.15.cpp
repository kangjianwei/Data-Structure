#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "LinkList.h"   //**▲02 线性表**//

/*
 * 题2.15
 *
 * 连接ha和hb，存储到hc中。
 */
Status Algo_2_15(LinkList* ha, LinkList* hb, LinkList* hc);

// 测试函数，打印元素
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    LinkList ha, hb, hc = NULL;
    int i;
    
    // 初始化
    InitList(&ha);
    InitList(&hb);
    
    // 赋值
    for(i = 1; i <= 5; i++) {
        ListInsert(ha, i, 2 * i - 1);
        ListInsert(hb, i, 2 * i);
    }
    
    printf("ha = ");
    ListTraverse(ha, PrintElem);
    
    printf("hb = ");
    ListTraverse(hb, PrintElem);
    
    // 连接ha和hb
    Algo_2_15(&ha, &hb, &hc);
    
    printf("hc = ");
    ListTraverse(hc, PrintElem);
    
    return 0;
}


// 连接ha和hb，存储到hc中
Status Algo_2_15(LinkList* ha, LinkList* hb, LinkList* hc) {
    LinkList pa, pb;
    
    *hc = NULL;
    
    // 确保ha和hb都存在
    if(ha == NULL || *ha == NULL || hb == NULL || *hb == NULL) {
        return ERROR;
    }
    
    pa = *ha;
    pb = *hb;
    
    // 为了提高效率，需要先遍历共同的部分
    while(pa->next != NULL && pb->next != NULL) {
        pa = pa->next;
        pb = pb->next;
    }
    
    // 如果ha已经遍历到头了，且hb有剩余
    if(pa->next == NULL && pb->next != NULL) {
        *hc = *ha;
        pa->next = (*hb)->next;
        free(*hb);
    }
    
    // 如果hb已经遍历到头了，ha可能有剩余，也可能没有
    if(pb->next == NULL) {
        *hc = *hb;
        pb->next = (*ha)->next;
        free(*ha);
    }
    
    // 销毁了ha/hb的头结点
    *ha = NULL;
    *hb = NULL;
    
    return OK;
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}

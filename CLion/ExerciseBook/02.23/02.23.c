#include <stdio.h>
#include "Status.h"      //**▲01 绪论**//
#include "LinkList.h"    //**▲02 线性表**//

/*
 * 题2.23——方法一：将La插入到Lb中
 *
 * 合并两个单链表。
 * 合并完成后，将La和Lb置空，但不销毁。
 */
Status Algo_2_23_1(LinkList La, LinkList Lb, LinkList* Lc);

/*
 * 题2.23——方法二：将La和Lb中的元素交替插入到Lc中
 *
 * 合并两个单链表。
 * 合并完成后，将La和Lb置空，但不销毁。
 */
Status Algo_2_23_2(LinkList La, LinkList Lb, LinkList* Lc);

// 测试函数，打印元素
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    LinkList La, Lb, Lc;
    int i;
    
    // 准备测试数据
    InitList(&La);
    InitList(&Lb);
    for(i = 1; i <= 5; i++) {
        ListInsert(La, i, 2 * i - 1);
        ListInsert(Lb, i, 2 * i);
    }
    printf("La = ");
    ListTraverse(La, PrintElem);
    printf("Lb = ");
    ListTraverse(Lb, PrintElem);
    
    // 合并方法测试
//    Algo_2_23_1(La, Lb, &Lc);
    Algo_2_23_2(La, Lb, &Lc);
    
    printf("Lc = ");
    ListTraverse(Lc, PrintElem);
    
    return 0;
}


// 合并两个单链表
Status Algo_2_23_1(LinkList La, LinkList Lb, LinkList* Lc) {
    LinkList p, pb;
    
    // 确保La和Lb存在
    if(La == NULL || Lb == NULL || Lc == NULL) {
        return ERROR;
    }
    
    pb = Lb;
    
    while(La->next != NULL && pb->next != NULL) {
        // 从La中摘下结点
        p = La->next;
        La->next = p->next;
        
        // 将La中摘下的结点插入到Lb中
        p->next = pb->next;
        pb->next = p;
        
        // 前进到原Lb中下一个结点的位置
        pb = pb->next->next;
    }
    
    // 如果La有剩余，需要将其全部链接到Lb的尾部
    if(pb->next == NULL && La->next != NULL) {
        pb->next = La->next;
        La->next = NULL;
    }
    
    InitList(Lc);
    
    (*Lc)->next = Lb->next;
    Lb->next = NULL;
    
    return OK;
}

// 合并两个单链表
Status Algo_2_23_2(LinkList La, LinkList Lb, LinkList* Lc) {
    LinkList p, pc;
    int flag;   // 指挥插入La中的元素还是插入Lb中的元素
    
    // 确保La和Lb存在
    if(La == NULL || Lb == NULL || Lc == NULL) {
        return ERROR;
    }
    
    InitList(Lc);
    
    flag = 0;
    pc = *Lc;
    
    while(La->next!=NULL && Lb->next!=NULL){
        // 需要插入La中的元素
        if(flag==0) {
            // 摘下La中的元素
            p = La->next;
            La->next = p->next;
            
            flag = 1;
        } else {
            // 摘下La中的元素
            p = Lb->next;
            Lb->next = p->next;
    
            flag = 0;
        }
    
        // 将摘下的元素插入到Lc
        pc->next = p;
        pc = pc->next;
    }
    
    // 如果Lb可能有剩余
    if(La->next==NULL) {
        // 摘下Lb中的元素
        p = Lb->next;
        Lb->next = NULL;
        pc->next = p;
    
        // 如果La有剩余
    } else {
        // 摘下La中的元素
        p = La->next;
        La->next = NULL;
        pc->next = p;
    }
    
    return OK;
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}

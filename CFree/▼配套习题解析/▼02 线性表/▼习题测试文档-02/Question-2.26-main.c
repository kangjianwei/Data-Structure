#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  									//**▲01 绪论**//
#include "../../../▲课本算法实现/▲02 线性表/04 SinglyLinkedList/SinglyLinkedList.c"	//**▲02 线性表**//

/*
 * 题2.26
 *
 * 求交集：C=A∩B，要求新链表另辟空间。
 */
Status Algo_2_26(LinkList La, LinkList Lb, LinkList* Lc);

// 测试函数，打印元素
void PrintElem(LElemType_L e);


int main(int argc, char* argv[]) {
    LinkList La, Lb, Lc;
    int i;
    
    // 0号单元存储的是数组长度
    int a[] = {10, 1, 3, 5, 7,  9, 11, 13, 15, 17, 19};
    int b[] = {8,  1, 5, 7, 8, 10, 15, 17, 20};
    
    // 准备测试数据，同一表中的元素值各不相同
    InitList_L(&La);
    InitList_L(&Lb);
    for(i = 1; i <= a[0]; i++) {
        ListInsert_L(La, i, a[i]);
    }
    for(i = 1; i <= b[0]; i++) {
        ListInsert_L(Lb, i, b[i]);
    }
    printf("La = ");
    ListTraverse_L(La, PrintElem);
    printf("\n");
    printf("Lb = ");
    ListTraverse_L(Lb, PrintElem);
    printf("\n");
    
    // 求交集
    Algo_2_26(La, Lb, &Lc);
    
    printf("Lc = ");
    ListTraverse_L(Lc, PrintElem);
    printf("\n");
    
    return 0;
}


// 求交集：C=A∩B，要求新链表另辟空间。
Status Algo_2_26(LinkList La, LinkList Lb, LinkList* Lc) {
    LinkList pa, pb, pc, s;
    
    // 初始化Lc
    InitList_L(Lc);
    
    // 确保La和Lb存在
    if(La == NULL || Lb == NULL) {
        return ERROR;
    }
    
    pa = La->next;
    pb = Lb->next;
    pc = *Lc;
    
    // 只遍历La和Lb的共同部分就行
    while(pa != NULL && pb != NULL) {
        if(pa->data < pb->data) {
            pa = pa->next;
        } else if(pa->data > pb->data) {
            pb = pb->next;
        } else {
            // 创建新结点存放交集元素
            s = (LinkList) malloc(sizeof(LNode));
            if(s == NULL) {
                exit(OVERFLOW);
            }
            s->data = pa->data;
            s->next = NULL;
    
            // 将交集元素插入到Lc
            pc->next = s;
            pc = pc->next;
            
            pa = pa->next;
            pb = pb->next;
        }
    }
    
    return OK;
}

// 测试函数，打印元素
void PrintElem(LElemType_L e) {
    printf("%2d ", e);
}

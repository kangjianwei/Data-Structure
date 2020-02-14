#include <stdio.h>
#include "ELinkList.h"                            //**▲02 线性表**//

// 判断data>e是否成立
Status CmpGreater(ElemType data, ElemType e) {
    return data > e ? TRUE : FALSE;
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    ELinkList L;
    Link p, q, s;
    Position r;
    int i;
    ElemType e;
    
    printf("████████ InitList \n");
    {
        printf("█ 初始化扩展的线性链表 L ...\n");
        InitList(&L);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ ListEmpty \n");
    {
        ListEmpty(L) ? printf("█ L 为空！！\n") : printf("█ L 不为空！\n");
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ ListInsert \n");
    {
        for(i = 1; i <= 8; i++) {
            printf("█ 在 L 第 %d 个位置插入 \"%d\" ...\n", i, 2 * i);
            ListInsert(&L, i, 2 * i);
        }
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ ListTraverse \n");
    {
        printf("█ L 中的元素为：L = ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ ListLength \n");
    {
        printf("█ L 的长度为 %d \n", ListLength(L));
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ ListDelete \n");
    {
        printf("█ 删除前的元素：L = ");
        ListTraverse(L, PrintElem);
    
        printf("█ 尝试删除 L 中第 6 个元素...\n");
    
        if(ListDelete(&L, 6, &e) == OK) {
            printf("█ 删除成功，被删除元素是：\"%d\"\n", e);
        } else {
            printf("█ 删除失败，第 6 个元素不存在！\n");
        }
    
        printf("█ 删除后的元素：L = ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ LocateElem \n");
    {
        r = LocateElem(L, 7, CmpGreater);
        printf("█ L 中第一个元素值大于 \"7\" 的元素是 \"%d\" \n", r->data);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ PriorElem \n");
    {
        Position pre = PriorPos(L, r);
        
        if(pre !=NULL) {
            printf("█ 元素 \"%d\" 的前驱为 \"%d\" \n", r->data, pre->data);
        } else {
            printf("█ 元素 \"%d\" 的前驱不存在！\n", r->data);
        }
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ NextElem \n");
    {
        Position next = NextPos(L, r);
        
        if(next !=NULL) {
            printf("█ 元素 \"%d\" 的后继为 \"%d\" \n", r->data, next->data);
        } else {
            printf("█ 元素 \"%d\" 的后继不存在！\n", r->data);
        }
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ MakeNode \n");
    {
        printf("█ 创建结点 \"100\" ...\n");
        MakeNode(&p, 100);
        printf("█ 创建结点 \"200\" ...\n");
        MakeNode(&q, 200);
        printf("█ 创建结点 \"300\" ...\n");
        MakeNode(&s, 300);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ InsFirst \n");
    {
        printf("█ 将元素 \"%d\" 插入到元素 \"%d\" 之后...\n", s->data, r->data);
        InsFirst(&L, r, s);
        printf("█ L 中的元素为：L = ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ DelFirst \n");
    {
        printf("█ 删除元素 \"%d\" 之后的元素...\n", r->data);
        DelFirst(&L, r, &s);
        printf("█ 被删除的元素为：\"%d\"\n", s->data);
        printf("█ L 中的元素为：L = ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue(debug);


    printf("████████ InsBefore \n");
    {
        Link t = r;
        
        printf("█ 将元素 \"%d\" 插入到元素 \"%d\" 之前...\n", p->data, t->data);
        InsBefore(&L, &t, p);
        printf("█ L 中的元素为：L = ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue(debug);


    printf("████████ InsAfter \n");
    {
        Link t = r;
        
        printf("█ 将元素 \"%d\" 插入到元素 \"%d\" 之后...\n", q->data, t->data);
        InsAfter(&L, &t, q);
        printf("█ L 中的元素为：L = ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ Append \n");
    {
        printf("█ 创建结点 \"400\" ...\n");
        MakeNode(&s, 400);
        
        printf("█ 将元素 %d 插入到链表最后...\n", s->data);
        Append(&L, s);
        printf("█ L 中的元素为：L = ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue(debug);


    printf("████████ Remove \n");
    {
        printf("█ 从链表最后删除元素...\n");
        Remove(&L, &s);
        printf("█ 被删除的元素为：\"%d\"\n", s->data);
        printf("█ L 中的元素为：L = ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue(debug);

    
    printf("████████ ClearList \n");
    {
        printf("清空 L 前：");
        ListEmpty(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");

        ClearList(&L);

        printf("清空 L 后：");
        ListEmpty(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ DestroyList \n");
    {
        printf("销毁 L 前：");
        L.head != NULL && L.tail != NULL ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
        
        DestroyList(&L);
        
        printf("销毁 L 后：");
        L.head != NULL && L.tail != NULL ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
        
    }
    PressEnterToContinue(debug);
    
    return 0;
}


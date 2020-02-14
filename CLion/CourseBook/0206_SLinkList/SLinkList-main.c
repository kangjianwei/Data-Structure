#include <stdio.h>
#include "Status.h"
#include "SLinkList.h"                        //**▲02 线性表**//

// 判断data>e是否成立
Status CmpGreater(ElemType data, ElemType e) {
    return data > e ? TRUE : FALSE;
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    SLinkList space;    // 备用空间
    int S;              // 静态链表头结点索引
    
    int i;
    ElemType e;
    
    printf("████████ InitList \n");
    {
        printf("█ 初始化单链表 S ...\n");
        InitList(space, &S);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ ListEmpty \n");
    {
        ListEmpty(space, S) ? printf("█ S 为空！！\n") : printf("█ S 不为空！\n");
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ ListInsert \n");
    {
        for(i = 1; i <= 8; i++) {
            printf("█ 在 S 第 %d 个位置插入 \"%d\" ...\n", i, 2 * i);
            ListInsert(space, S, i, 2 * i);
        }
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ ListTraverse \n");
    {
        printf("█ S 中的元素为：S = ");
        ListTraverse(space, S, PrintElem);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ ListLength \n");
    {
        printf("█ S 的长度为 %d \n", ListLength(space, S));
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ ListDelete \n");
    {
        printf("█ 删除前的元素：S = ");
        ListTraverse(space, S, PrintElem);
        
        printf("█ 尝试删除 S 中第 6 个元素...\n");
        
        if(ListDelete(space, S, 6, &e) == OK) {
            printf("█ 删除成功，被删除元素是：\"%d\"\n", e);
        } else {
            printf("█ 删除失败，第 6 个元素不存在！\n");
        }
        
        printf("█ 删除后的元素：S = ");
        ListTraverse(space, S, PrintElem);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ GetElem \n");
    {
        GetElem(space, S, 4, &e);
        printf("█ S 中第 4 个位置的元素为 \"%d\" \n", e);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ LocateElem \n");
    {
        i = LocateElem(space, S, 7, CmpGreater);
        GetElem(space, S, i, &e);
        printf("█ S 中第一个元素值大于 \"7\" 的元素是 \"%d\" \n", e);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ PriorElem \n");
    {
        ElemType cur_e = 6;
        
        if(PriorElem(space, S, cur_e, &e) == OK) {
            printf("█ 元素 \"%d\" 的前驱为 \"%d\" \n", cur_e, e);
        } else {
            printf("█ 元素 \"%d\" 的前驱不存在！\n", cur_e);
        }
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ NextElem \n");
    {
        ElemType cur_e = 6;
        
        if(NextElem(space, S, cur_e, &e) == OK) {
            printf("█ 元素 \"%d\" 的后继为 \"%d\" \n", cur_e, e);
        } else {
            printf("█ 元素 \"%d\" 的后继不存在！\n", cur_e);
        }
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ ClearList \n");
    {
        printf("█ 清空 S 前：");
        ListEmpty(space, S) ? printf(" S 为空！！\n") : printf(" S 不为空！\n");
        
        ClearList(space, S);
        
        printf("█ 清空 S 后：");
        ListEmpty(space, S) ? printf(" S 为空！！\n") : printf(" S 不为空！\n");
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ DestroyList \n");
    {
        printf("█ 销毁 S 前：");
        S!=0 ? printf(" S 存在！\n") : printf(" S 不存在！！\n");
        
        DestroyList(space, &S);
        
        printf("█ 销毁 S 后：");
        S!=0 ? printf(" S 存在！\n") : printf(" S 不存在！！\n");
    }
    PressEnterToContinue(debug);
    
    return 0;
}


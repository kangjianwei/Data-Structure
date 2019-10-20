#include <stdio.h>
#include "MergeEList.h"                    //**▲02 线性表**//

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}

/*
 * 比较
 *
 * 比较e1和e2的大小，返回值含义如下：
 *  < 0：e1 < e2
 *  = 0：e1 = e2
 *  > 0：e1 > e2
 */
int Cmp(ElemType e1, ElemType e2) {
    return e1 - e2;
}

/*
 * 尾插法创建链表
 *
 *【备注】
 * 这里为了方便测试，避免每次运行都手动输入数据，
 * 因而选择了从预设的文件fp中读取测试数据。
 */
void CreateList_Tail(char path[], ELinkList* L) {
    FILE* fp;
    int i, n;
    ElemType e;
    
    fp = fopen(path, "r");
    if(fp == NULL) {
        printf("文件打开失败...\n");
        exit(ERROR);
    }
    
    // 读取指定集合中元素的数量
    ReadData(fp, "%d", &n);
    
    InitList(L);
    
    for(i = 1; i <= n; i++) {
        ReadData(fp, "%d", &e);
        ListInsert(L, i, e);
    }
    
    fclose(fp);
}


int main(int argc, char** argv) {
    ELinkList La, Lb, Lc;
    
    printf("创建La和Lb以待测试...\n");
    
    CreateList_Tail("TestData_La.txt", &La);
    printf("La= ");
    ListTraverse(La, PrintElem);
    
    CreateList_Tail("TestData_Lb.txt", &Lb);
    printf("Lb= ");
    ListTraverse(Lb, PrintElem);
    
    MergeEList(&La, &Lb, &Lc, Cmp);
    printf("合并La和Lb为 Lc = ");
    ListTraverse(Lc, PrintElem);
    
    return 0;
}

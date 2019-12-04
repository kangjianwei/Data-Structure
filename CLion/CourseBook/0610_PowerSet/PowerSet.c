/*===================
 * 冪集
 *
 * 包含算法: 6.14/6.15
 ====================*/

#include "PowerSet.h"

/*
 * 创建集合A，集合元素类型与线性表元素类型一致。
 */
Status CreatePowerSet(List* A, char* path) {
    FILE* fp;
    int readFromConsole;    // 是否从控制台读取数据
    
    // 如果没有文件路径信息，则从控制台读取输入
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("请输入集合的元素信息...\n");
        Create(A, NULL);
    } else {
        // 打开文件，准备读取测试数据
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }
        Create(A, fp);
        fclose(fp);
    }
    
    return OK;
}

/*
 * ████████ 6.14/6.15 ████████
 *
 * 求取集合A的幂集，集合B用来暂存每一次求出的幂集子集。
 */
void GetPowerSet(int i, List A, List B) {
    int k;
    ElemType e;
    
    // i用来追踪当前深入的层级
    if(i > ListLength(A)) {
        PrintPowerSet(B);
    } else {
        GetElem(A, i, &e);
        k = ListLength(B);
        
        ListInsert(B, k + 1, e);    //+第i个元素
        GetPowerSet(i + 1, A, B);
        
        ListDelete(B, k + 1, &e);   //-第i个元素
        GetPowerSet(i + 1, A, B);
    }
}

/*
 * 输出当前集合。
 */
void PrintPowerSet(List A) {
    LinkList p;
    int len;
    
    if(A == NULL) {
        printf("\n");
        return;
    }
    
    len = ListLength(A);
    
    // 输出空集
    if(len == 0) {
        printf("⊙");
    } else {
        // 输出集合中的元素
        for(p = A->next; p; p = p->next) {
            printf("%-2d ", p->data);
        }
    }
    
    printf("\n");
}


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 创建集合的内部函数
static void Create(List* A, FILE* fp) {
    int n, i, e;
    
    InitList(A);
    
    if(fp == NULL) {
        printf("请输入集合元素数量：");
        scanf("%d", &n);
    
        for(i=1; i<=n; i++) {
            printf("请输入第 %2d 个元素：", i);
            scanf("%d", &e);
            ListInsert(*A, i, e);
        }
    } else {
        // 录入元素数量
        ReadData(fp, "%d", &n);
        
        // 录入元素
        for(i=1; i<=n; i++) {
            ReadData(fp, "%d", &e);
            ListInsert(*A, i, e);
        }
    }
}

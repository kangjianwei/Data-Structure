/*===============================
 * 线性表的链式存储结构（链表）
 *
 * 包含算法: 2.8、2.9、2.10、2.11
 ================================*/

#include "LinkList.h"   //**▲02 线性表**//

/*
 * 遍历
 *
 * 用visit函数访问链表L
 */
void ListTraverse(LinkList L, void(Visit)(ElemType)) {
    LinkList p;
    
    // 确保链表存在
    if(L == NULL || L->next == NULL) {
        return;
    }
    
    p = L->next;
    
    while(p != NULL) {
        Visit(p->data);
        p = p->next;
    }
    
    printf("\n");
}

/*
 * ████████ 算法2.11 ████████
 *
 * 头插法创建链表
 *
 *
 *【备注】
 *
 * 教材中默认从控制台读取数据。
 * 这里为了方便测试，避免每次运行都手动输入数据，
 * 因而允许选择从预设的文件path中读取测试数据。
 *
 * 如果需要从控制台读取数据，则不需要填写可变参数，
 * 如果需要从文件中读取数据，则需要在可变参数中填写文件名信息(文件名中需要包含子串"TestData")。
 */
Status CreateList_Head(LinkList* L, int n, ...) {
    int i;
    LinkList p;
    va_list ap;
    FILE* fp;
    char* path = NULL;
    int readFromConsole;    // 是否从控制台读取数据
    
    va_start(ap, n);
    path = va_arg(ap, char*);
    va_end(ap);
    
    // 如果没有文件路径信息，则从控制台读取输入
    readFromConsole = path == NULL || strstr(path, "TestData") == NULL;
    
    if(readFromConsole) {
        // 建立头结点
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;
    
        printf("请输入%d个降序元素：", n);
        
        for(i = 1; i <= n; ++i) {
            // 生成新结点
            p = (LinkList) malloc(sizeof(LNode));
            
            // 填充数据，并插入到链表中
            scanf("%d", &(p->data));
            
            p->next = (*L)->next;
            (*L)->next = p;
        }
    } else {
        // 打开文件，准备读取测试数据
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }
        
        // 建立头结点
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;
        
        for(i = 1; i <= n; ++i) {
            // 生成新结点
            p = (LinkList) malloc(sizeof(LNode));
            
            // 填充数据，并插入到链表中
            ReadData(fp, "%d", &(p->data));
            
            p->next = (*L)->next;
            (*L)->next = p;
        }
        
        fclose(fp);
    }
    
    return OK;
}

/*
 * 尾插法创建链表
 *
 *
 *【备注】
 *
 * 教材中默认从控制台读取数据。
 * 这里为了方便测试，避免每次运行都手动输入数据，
 * 因而允许选择从预设的文件path中读取测试数据。
 *
 * 如果需要从控制台读取数据，则不需要填写可变参数，
 * 如果需要从文件中读取数据，则需要在可变参数中填写文件名信息(文件名中需要包含子串"TestData")。
 */
Status CreateList_Tail(LinkList* L, int n, ...) {
    int i;
    LinkList p, q;
    va_list ap;
    FILE* fp;
    char* path = NULL;
    int readFromConsole;    // 是否从控制台读取数据
    
    va_start(ap, n);
    path = va_arg(ap, char*);
    va_end(ap);
    
    // 如果没有文件路径信息，则从控制台读取输入
    readFromConsole = path == NULL || strstr(path, "TestData") == NULL;
    
    if(readFromConsole) {
        // 建立头结点
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;
    
        printf("请输入%d个升序元素：", n);
        
        for(i = 1, q = *L; i <= n; ++i) {
            // 生成新结点
            p = (LinkList) malloc(sizeof(LNode));
            
            // 填充数据，并插入到链表中
            scanf("%d", &(p->data));
            
            q->next = p;
            q = q->next;
        }
        
        q->next = NULL;
    } else {
        // 打开文件，准备读取测试数据
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }
        
        // 建立头结点
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;
        
        for(i = 1, q = *L; i <= n; ++i) {
            // 生成新结点
            p = (LinkList) malloc(sizeof(LNode));
            
            // 填充数据，并插入到链表中
            ReadData(fp, "%d", &(p->data));
            
            q->next = p;
            q = q->next;
        }
        
        q->next = NULL;
        
        fclose(fp);
    }
    
    return OK;
}

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
 *【备注】
 * 教材中默认从控制台读取数据。
 * 这里为了方便测试，避免每次运行都手动输入数据，
 * 因而选择了从预设的文件path中读取测试数据。
 * 另教材中的算法采用的是头插法，所以此处的实现加了后缀_Head。
 */
Status CreateList_Head(char path[], LinkList* L, int n) {
    FILE* fp;
    int i;
    LinkList p;
    ElemType e;
    
    // 建立头结点
    *L = (LinkList) malloc(sizeof(LNode));
    if(*L == NULL) {
        exit(OVERFLOW);
    }
    (*L)->next = NULL;
    
    // 打开文件，准备读取测试数据
    fp = fopen(path, "r");
    if(fp == NULL) {
        return ERROR;
    }
    
    for(i = 1; i <= n; ++i) {
        // 如果成功读取到输入数据
        if(ReadData(fp, "%d", &e) == 1) {
            // 生成新结点
            p = (LinkList) malloc(sizeof(LNode));
            if(p == NULL) {
                fclose(fp);
                exit(OVERFLOW);
            }
            
            // 填充数据，并插入到链表中
            p->data = e;
            p->next = (*L)->next;
            (*L)->next = p;
        } else {
            fclose(fp);
            return ERROR;
        }
    }
    
    fclose(fp);
    
    return OK;
}

/*
 * 尾插法创建链表
 *
 *【备注】
 * 教材中默认从控制台读取数据。
 * 这里为了方便测试，避免每次运行都手动输入数据，
 * 因而选择了从预设的文件path中读取测试数据。
 */
Status CreateList_Tail(char path[], LinkList* L, int n) {
    FILE* fp;
    int i;
    LinkList p, q;
    ElemType e;
    
    // 建立头结点
    *L = (LinkList) malloc(sizeof(LNode));
    if(*L==NULL) {
        exit(OVERFLOW);
    }
    (*L)->next = NULL;
    
    // 打开文件，准备读取测试数据
    fp = fopen(path, "r");
    if(fp == NULL) {
        return ERROR;
    }
    
    for(i = 1, q = *L; i <= n; ++i) {
        // 如果成功读取到输入数据
        if(ReadData(fp, "%d", &e) == 1) {
            p = (LinkList) malloc(sizeof(LNode));
            if(p==NULL) {
                fclose(fp);
                exit(OVERFLOW);
            }
            
            // 填充数据，并插入到链表中
            p->data = e;
            q->next = p;
            q = q->next;
        } else {
            fclose(fp);
            return ERROR;
        }
    }
    
    q->next = NULL;
    
    fclose(fp);
    
    return OK;
}

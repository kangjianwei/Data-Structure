/*=====================
 * 双向循环链表
 *
 * 包含算法: 2.18、2.19
 ======================*/

#ifndef DULINKLIST_H
#define DULINKLIST_H

#include <stdio.h>
#include <stdlib.h>     //提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//

/* 双向循环链表元素类型定义 */
typedef int ElemType;

/*
 * 双向循环链表结构
 *
 * 注：这里的双向循环链表存在头结点
 */
typedef struct DuLNode {
    ElemType data;
    struct DuLNode* prior;  // 前驱
    struct DuLNode* next;   // 后继
} DuLNode;

// 指向双向循环链表结点的指针
typedef DuLNode* DuLinkList;


/*
 * 初始化
 *
 * 初始化成功则返回OK，否则返回ERROR。
 */
Status InitList(DuLinkList* L);

/*
 * ████████ 算法2.18 ████████
 *
 * 插入
 *
 * 向双向循环链表第i个位置上插入e，插入成功则返回OK，否则返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数
 */
Status ListInsert(DuLinkList L, int i, ElemType e);

/*
 * 遍历
 *
 * 用visit函数访问双向循环链表L
 */
void ListTraverse(DuLinkList L, void(Visit)(ElemType));

/*
 * 获取循环链表L上第i个元素的引用
 *
 * ▓▓▓▓ 注意 ▓▓▓▓
 * 1.加static的含义是当前函数只在DuLinkList中使用，不会被别的文件引用
 * 2.假设链表长度为len，且需要获取第len+1个元素的引用时，由于这里是循环链表，所以返回的是头结点
 */
static DuLinkList GetElemP(DuLinkList L, int i);

#endif

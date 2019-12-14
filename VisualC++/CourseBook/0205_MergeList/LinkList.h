/*===============================
 * 线性表的链式存储结构（链表）
 *
 * 包含算法: 2.8、2.9、2.10、2.11
 ================================*/

#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include <string.h>     // 提供 strstr 原型
#include "Status.h"     //**▲01 绪论**//

/* 单链表元素类型定义 */
typedef int ElemType;

/*
 * 单链表结构
 *
 * 注：这里的单链表存在头结点
 */
typedef struct LNode {
    ElemType data;      // 数据结点
    struct LNode* next; // 指向下一个结点的指针
} LNode;

// 指向单链表结点的指针
typedef LNode* LinkList;


/*
 * 遍历
 *
 * 用visit函数访问链表L
 */
void ListTraverse(LinkList L, void(Visit)(ElemType));

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
 * 如果需要从控制台读取数据，则path为NULL或者为空串，
 * 如果需要从文件中读取数据，则需要在path中填写文件名信息。
 */
Status CreateList_Head(LinkList* L, int n, char* path);

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
 * 如果需要从控制台读取数据，则path为NULL或者为空串，
 * 如果需要从文件中读取数据，则需要在path中填写文件名信息。
 */
Status CreateList_Tail(LinkList* L, int n, char* path);

#endif

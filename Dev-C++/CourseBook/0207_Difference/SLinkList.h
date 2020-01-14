/*=================================
 * 静态链表
 *
 * 包含算法: 2.13、2.14、2.15、2.16
 ==================================*/

#ifndef SLINKLIST_H
#define SLINKLIST_H

#include <stdio.h>
#include <stdlib.h>     //提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//

/* 宏定义 */
#define MAXSIZE 1000            // 备用空间最大容量，近似于静态链表的最大长度

/* 静态链表元素类型定义 */
typedef int ElemType;

/*
 * 静态链表结构
 *
 * 注：静态链表依托于一个数组，该数组包含了已占用空间和空闲空间
 */
typedef struct SLinkLNode {
    ElemType data;
    int cur;            // cur是游标，做指针用，用来链接下一个结点（区别于数组下标）
} SLinkList[MAXSIZE];   // 链表空间类型


/*
 * ████ 提示 ████
 *
 * 以下所有函数的形参中：
 * space：指示备用空间
 * S    ：指示静态链表头结点索引
 */


/*━━━━━━━━━━━━━━━━━━━━━━ 备用空间操作 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * ████████ 算法2.14 ████████
 *
 * 初始化备用空间
 *
 * 备用空间为静态链表提供可用的内存。
 */
void InitSpace(SLinkList space);

/*
 * ████████ 算法2.15 ████████
 *
 * 申请空间
 *
 * 为静态链表从备用空间申请结点空间，
 * 如果申请成功，返回可用空间的索引，
 * 申请失败时，返回0。
 */
int Malloc(SLinkList space);

/*
 * ████████ 算法2.16 ████████
 *
 * 回收空间
 *
 * 回收索引k处的结点空间以供静态链表后续复用，
 * 回收方式就是将该结点空间从静态链表上移除，
 * 并将其添加到备用空间的列表当中。
 */
void Free(SLinkList space, int k);


/*━━━━━━━━━━━━━━━━━━━━━━ 静态链表操作 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * 遍历
 *
 * 用visit函数访问静态链表S
 */
void ListTraverse(SLinkList space, int S, void(Visit)(ElemType));


/*━━━━━━━━━━━━━━━━━━━━━━ 图形化输出 ━━━━━━━━━━━━━━━━━━━━━━*/

// 以图形化形式输出当前结构，仅限内部测试使用
void PrintList(SLinkList space, int S);

#endif

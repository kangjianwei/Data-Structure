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
typedef struct SLinkNode {
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

/*
 * ████ 注意 ████
 *
 * 教材中算法2.13和算法2.14~2.17中都是涉及静态链表的操作，
 * 但这两处算法预设的数据结构却不同。
 *
 * 算法2.13假设整个预设数组都是静态链表(操作简单)，
 * 算法2.14~2.17只是将预设的数组作为备用空间，
 * 静态链表所需空间是基于备用空间进行申请和释放的(操作稍难)。
 *
 * 这里实现的代码中，以算法2.14~2.17处预设的数据结构为准，
 * 所以，对于算法2.13，其实现会有教材有所不同。
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
 * 初始化
 *
 * 先初始化备用空间，而后从备用空间中申请头结点的空间，进而完成静态链表的初始化。
 * 初始化成功则使用S存储头结点索引，且返回OK，否则返回ERROR。
 */
Status InitList(SLinkList space, int* S);

/*
 * 销毁(结构)
 *
 * 释放静态链表所占内存，即将静态链表所有结点空间移入备用空间列表中。
 */
Status DestroyList(SLinkList space, int* S);

/*
 * 置空(内容)
 *
 * 这里需要释放静态链表中非头结点处的空间。
 */
Status ClearList(SLinkList space, int S);

/*
 * 判空
 *
 * 判断静态链表中是否包含有效数据。
 *
 * 返回值：
 * TRUE : 静态链表为空
 * FALSE: 静态链表不为空
 */
Status ListEmpty(SLinkList space, int S);

/*
 * 计数
 *
 * 返回静态链表包含的有效元素的数量。
 */
int ListLength(SLinkList space, int S);

/*
 * 取值
 *
 * 获取静态链表中第i个元素，将其存储到e中。
 * 如果可以找到，返回OK，否则，返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数，但这不符合编码的通用约定。
 * 通常，i的含义应该指索引，即从0开始计数。
 */
Status GetElem(SLinkList space, int S, int i, ElemType* e);

/*
 * ████████ 算法2.13 ████████
 *
 * 查找
 *
 * 返回静态链表中首个与e满足Compare关系的元素位序。
 * 如果不存在这样的元素，则返回0。
 *
 *【备注】
 * 1.元素e是Compare函数第二个形参
 * 2.这里的实现与教材上的算法2.13不相同，原因参见顶部的“注意”信息
 */
int LocateElem(SLinkList space, int S, ElemType e, Status(Compare)(ElemType, ElemType));

/*
 * 前驱
 *
 * 获取元素cur_e的前驱，
 * 如果存在，将其存储到pre_e中，返回OK，
 * 如果不存在，则返回ERROR。
 */
Status PriorElem(SLinkList space, int S, ElemType cur_e, ElemType* pre_e);

/*
 * 后继
 *
 * 获取元素cur_e的后继，
 * 如果存在，将其存储到next_e中，返回OK，
 * 如果不存在，则返回ERROR。
 */
Status NextElem(SLinkList space, int S, ElemType cur_e, ElemType* next_e);

/*
 * 插入
 *
 * 向静态链表第i个位置上插入e，插入成功则返回OK，否则返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数
 */
Status ListInsert(SLinkList space, int S, int i, ElemType e);

/*
 * 删除
 *
 * 删除静态链表第i个位置上的元素，并将被删除元素存储到e中。
 * 删除成功则返回OK，否则返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数
 */
Status ListDelete(SLinkList space, int S, int i, ElemType* e);

/*
 * 遍历
 *
 * 用visit函数访问静态链表S
 */
void ListTraverse(SLinkList space, int S, void(Visit)(ElemType));


/*━━━━━━━━━━━━━━━━━━━━━━ 图形化输出 ━━━━━━━━━━━━━━━━━━━━━━*/

// 以图形化形式输出当前结构
void PrintList(SLinkList space, int S);

#endif

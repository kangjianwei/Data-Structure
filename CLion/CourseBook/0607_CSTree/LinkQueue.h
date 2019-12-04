/*=========================
 * 队列的链式存储结构（链队）
 ==========================*/

#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//
#include "CSTree.h"     //**▲06 树和二叉树**//

/*
 * 链队元素类型定义
 *
 *【注】
 * 此处元素的含义是指向树中结点的指针
 */
typedef CSTree QElemType;

// 队列元素结构
typedef struct QNode {
    QElemType data;
    struct QNode* next;
} QNode, * QueuePtr;

// 队列结构
typedef struct {
    QueuePtr front;     // 队头指针
    QueuePtr rear;      // 队尾指针
} LinkQueue;            // 队列的链式存储表示


/*
 * 初始化
 *
 * 构造一个空的链队。
 * 初始化成功则返回OK，否则返回ERROR。
 *
 *【注】
 * 这里的队列带有头结点
 */
Status InitQueue(LinkQueue* Q);

/*
 * 判空
 *
 * 判断链队中是否包含有效数据。
 *
 * 返回值：
 * TRUE : 链队为空
 * FALSE: 链队不为空
 */
Status QueueEmpty(LinkQueue Q);

/*
 * 入队
 *
 * 将元素e添加到队列尾部。
 */
Status EnQueue(LinkQueue* Q, QElemType e);

/*
 * 出队
 *
 * 移除队列头部的元素，将其存储到e中。
 */
Status DeQueue(LinkQueue* Q, QElemType* e);

#endif

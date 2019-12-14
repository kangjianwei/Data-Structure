/*=========================
 * 队列的链式存储结构（链队）
 ==========================*/

#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//

/* 链队元素类型定义，这里记录客户信息 */
typedef struct {
    int ArrivedTime;    // 客户到达时间
    int Duration;       // 办理业务所需的时间
    int Count;          // 此变量记录来到每个队列的客户是第几个【教材中无此变量，增加此变量的目的是观察排队状况。】
} QElemType;            //队列的数据元素类型

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
 * 计数
 *
 * 返回链队包含的有效元素的数量。
 */
int QueueLength(LinkQueue Q);

/*
 * 取值
 *
 * 获取队头元素，将其存储到e中。
 * 如果可以找到，返回OK，否则，返回ERROR。
 */
Status GetHead(LinkQueue Q, QElemType* e);

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

/*=============================
 * 队列的顺序存储结构（顺序队列）
 ==============================*/

#ifndef SQQUEUE_H
#define SQQUEUE_H

#include <stdio.h>
#include <stdlib.h>        // 提供malloc、realloc、free、exit原型
#include "Status.h"        //**▲01 绪论**//

/*
 * ████ 注意 ████
 *
 * 这里的循环队列是输出受限的双端队列
 * 即：元素可以从队头或队尾入队，但只能从队头出队
 */

/* 宏定义 */
#define MAXQSIZE 1000   //最大队列长度

/* 循环队列元素类型定义 */
typedef int QElemType;

// 循环队列的顺序存储结构
typedef struct {
    QElemType* base;    // 动态分配存储空间
    int front;          // 头指针，若队列不空，指向队头元素
    int rear;           // 尾指针，若队列不空，指向队列尾元素的下一个位置
} SqQueue;


/*
 * 初始化
 *
 * 构造一个空的顺序队列。
 * 初始化成功则返回OK，否则返回ERROR。
 *
 *【注】
 * 这里的队列是循环队列
 */
Status InitQueue(SqQueue* Q);

/*
 * 入队
 *
 * di代表入队方向，0指示从队头入队，1指示从队尾入队
 */
Status EnQueue_3_34(SqQueue* Q, QElemType e, int di);

/*
 * 出队
 *
 * 移除队列头部的元素，将其存储到e中。
 */
Status DeQueue(SqQueue* Q, QElemType* e);

/*
 * 遍历
 *
 * 用visit函数访问队列Q
 */
Status QueueTraverse(SqQueue Q, void(Visit)(QElemType));

#endif

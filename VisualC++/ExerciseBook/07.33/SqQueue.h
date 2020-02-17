/*=============================
 * 队列的顺序存储结构（顺序队列）
 ==============================*/

#ifndef SQQUEUE_H
#define SQQUEUE_H

#include <stdio.h>
#include <stdlib.h>        // 提供malloc、realloc、free、exit原型
#include "Status.h"        //**▲01 绪论**//

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
 * 判空
 *
 * 判断循环顺序队列中是否包含有效数据。
 *
 * 返回值：
 * TRUE : 循环顺序队列为空
 * FALSE: 循环顺序队列不为空
 */
Status QueueEmpty(SqQueue Q);

/*
 * 计数
 *
 * 返回循环顺序队列包含的有效元素的数量。
 */
int QueueLength(SqQueue Q);

/*
 * 取值
 *
 * 获取队头元素，将其存储到e中。
 * 如果可以找到，返回OK，否则，返回ERROR。
 */
Status GetHead(SqQueue Q, QElemType* e);

/*
 * 入队
 *
 * 将元素e添加到队列尾部。
 */
Status EnQueue(SqQueue* Q, QElemType e);

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

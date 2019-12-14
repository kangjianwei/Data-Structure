/*=============================
 * 队列的顺序存储结构（顺序队列）
 ==============================*/

#include "SqQueue.h"                //**▲03 栈和队列**//

/*
 * 初始化
 *
 * 构造一个空的顺序队列。
 * 初始化成功则返回OK，否则返回ERROR。
 *
 *【注】
 * 这里的队列是循环队列
 */
Status InitQueue(SqQueue* Q) {
    if(Q == NULL) {
        return ERROR;
    }
    
    (*Q).base = (QElemType*) malloc(MAXQSIZE * sizeof(QElemType));
    if(!(*Q).base) {
        exit(OVERFLOW);
    }
    
    (*Q).front = (*Q).rear = 0;
    
    return OK;
}

/*
 * 入队（双端队列，输出受限）
 */
Status EnQueue_3_33(SqQueue* Q, QElemType e) {
    int head, tail;
    
    if(Q == NULL) {
        return ERROR;
    }
    
    // 如果队列满，直接返回
    if(((*Q).rear + 1) % MAXQSIZE == (*Q).front) {
        return ERROR;
    }
    
    // 如果队列为空，直接插入到队尾
    if((*Q).front == (*Q).rear) {
        (*Q).base[(*Q).rear] = e;
        (*Q).rear = ((*Q).rear + 1) % MAXQSIZE;
        return OK;
    }
    
    head = (*Q).base[(*Q).front];                               // 队头元素值
    tail = (*Q).base[((*Q).rear - 1 + MAXQSIZE) % MAXQSIZE];    // 队尾元素值
    
    // 如果待插入元素的作业时间不小于队列首尾元素作业的平均时间，则将元素插在队尾
    if(e >= (head + tail) / 2) {
        (*Q).base[(*Q).rear] = e;
        (*Q).rear = ((*Q).rear + 1) % MAXQSIZE;
        
        // 否则，插在队头
    } else {
        (*Q).front = ((*Q).front - 1 + MAXQSIZE) % MAXQSIZE;
        (*Q).base[(*Q).front] = e;
    }
    
    return OK;
}

/*
 * 出队
 *
 * 移除队列头部的元素，将其存储到e中。
 */
Status DeQueue(SqQueue* Q, QElemType* e) {
    if(Q == NULL || (*Q).base == NULL) {
        return ERROR;
    }
    
    // 队列空的标志
    if((*Q).front == (*Q).rear) {
        return ERROR;
    }
    
    // 出队
    *e = (*Q).base[(*Q).front];
    
    // 头指针前进
    (*Q).front = ((*Q).front + 1) % MAXQSIZE;
    
    return OK;
}

/*
 * 遍历
 *
 * 用visit函数访问队列Q
 */
Status QueueTraverse(SqQueue Q, void(Visit)(QElemType)) {
    int i;
    
    if(Q.base == NULL) {
        return ERROR;
    }
    
    for(i = Q.front; i != Q.rear; i = (i + 1) % MAXQSIZE) {
        Visit(Q.base[i]);
    }
    
    printf("\n");
    
    return OK;
}

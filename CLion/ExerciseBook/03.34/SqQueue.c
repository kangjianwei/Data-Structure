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
 * 入队
 *
 * di代表入队方向，0指示从队头入队，1指示从队尾入队
 */
Status EnQueue_3_34(SqQueue* Q, QElemType e, int di) {
    
    // 从队头入队
    if(di == 0) {
        (*Q).front = ((*Q).front - 1 + MAXQSIZE) % MAXQSIZE;
        (*Q).base[(*Q).front] = e;
        return OK;
    }
    
    // 从队尾入队
    if(di == 1) {
        (*Q).base[(*Q).rear] = e;
        (*Q).rear = ((*Q).rear + 1) % MAXQSIZE;
        return OK;
    }
    
    return ERROR;
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

/*=========================
 * 队列的链式存储结构（链队）
 ==========================*/

#ifndef LINKQUEUE_C
#define LINKQUEUE_C

#include "LinkQueue.h"                    //**▲03 栈和队列**//

/*
 * 初始化
 *
 * 构造一个空的链队。
 * 初始化成功则返回OK，否则返回ERROR。
 *
 *【注】
 * 这里的队列带有头结点
 */
Status InitQueue(LinkQueue* Q) {
    if(Q == NULL) {
        return ERROR;
    }
    
    (*Q).front = (*Q).rear = (QueuePtr) malloc(sizeof(QNode));
    if(!(*Q).front) {
        exit(OVERFLOW);
    }
    
    (*Q).front->next = NULL;
    
    return OK;
}

/*
 * 判空
 *
 * 判断链队中是否包含有效数据。
 *
 * 返回值：
 * TRUE : 链队为空
 * FALSE: 链队不为空
 */
Status QueueEmpty(LinkQueue Q) {
    if(Q.front == Q.rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/*
 * 入队
 *
 * 将元素e添加到队列尾部。
 */
Status EnQueue(LinkQueue* Q, QElemType e) {
    QueuePtr p;
    
    if(Q == NULL || (*Q).front == NULL) {
        return ERROR;
    }
    
    p = (QueuePtr) malloc(sizeof(QNode));
    if(!p) {
        exit(OVERFLOW);
    }
    
    p->data = e;
    p->next = NULL;
    
    (*Q).rear->next = p;
    (*Q).rear = p;
    
    return OK;
}

/*
 * 出队
 *
 * 移除队列头部的元素，将其存储到e中。
 */
Status DeQueue(LinkQueue* Q, QElemType* e) {
    QueuePtr p;
    
    if(Q == NULL || (*Q).front == NULL || (*Q).front == (*Q).rear) {
        return ERROR;
    }
    
    p = (*Q).front->next;
    *e = p->data;
    
    (*Q).front->next = p->next;
    if((*Q).rear == p) {
        (*Q).rear = (*Q).front;
    }
    
    free(p);
    
    return OK;
}

#endif

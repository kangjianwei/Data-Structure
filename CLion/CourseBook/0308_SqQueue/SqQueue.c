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
 * 销毁(结构)
 *
 * 释放循环顺序队列所占内存。
 */
Status DestroyQueue(SqQueue* Q) {
    if(Q == NULL) {
        return ERROR;
    }
    
    if((*Q).base) {
        free((*Q).base);
    }
    
    (*Q).base = NULL;
    (*Q).front = (*Q).rear = 0;
    
    return ERROR;
}

/*
 * 置空(内容)
 *
 * 只是清理循环顺序队列中存储的数据，不释放顺序队列所占内存。
 */
Status ClearQueue(SqQueue* Q) {
    if(Q == NULL || (*Q).base == NULL) {
        return ERROR;
    }
    
    (*Q).front = (*Q).rear = 0;
    
    return OK;
}

/*
 * 判空
 *
 * 判断循环顺序队列中是否包含有效数据。
 *
 * 返回值：
 * TRUE : 循环顺序队列为空
 * FALSE: 循环顺序队列不为空
 */
Status QueueEmpty(SqQueue Q) {
    // 队列空的标志
    if(Q.front == Q.rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/*
 * 计数
 *
 * 返回循环顺序队列包含的有效元素的数量。
 */
int QueueLength(SqQueue Q) {
    if(Q.base == NULL) {
        return 0;
    }
    
    // 队列长度
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

/*
 * 取值
 *
 * 获取队头元素，将其存储到e中。
 * 如果可以找到，返回OK，否则，返回ERROR。
 */
Status GetHead(SqQueue Q, QElemType* e) {
    // 队列空的标志
    if(Q.base == NULL || Q.front == Q.rear) {
        return ERROR;
    }
    
    *e = Q.base[Q.front];
    
    return OK;
}

/*
 * 入队
 *
 * 将元素e添加到队列尾部。
 */
Status EnQueue(SqQueue* Q, QElemType e) {
    if(Q == NULL || (*Q).base == NULL) {
        return ERROR;
    }
    
    // 队列满的标志（会浪费一个空间来区分队列空和队列满）
    if(((*Q).rear + 1) % MAXQSIZE == (*Q).front) {
        return ERROR;
    }
    
    // 入队
    (*Q).base[(*Q).rear] = e;
    
    // 尾指针前进
    (*Q).rear = ((*Q).rear + 1) % MAXQSIZE;
    
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

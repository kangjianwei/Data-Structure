#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include <limits.h>     // 提供一些数值常量
#include "Status.h"     //**▲01 绪论**//

/*
 * ████ 注意 ████
 *
 * 这里使用带头结点的循环链表表示队列
 */

/* 队列元素类型 */
typedef int QElemType;

/* 队列结点类型 */
typedef struct QNode {
    QElemType data;
    struct QNode* next;
} QNode, * QueuePtr;

/* 队列结构 */
typedef struct {
    QueuePtr rear;      // 队尾指针
} LinkQueue;            // 队列的链式存储表示

// 队列初始化
Status InitQueue_3_28(LinkQueue* Q);

// 入队
Status EnQueue_3_28(LinkQueue* Q, QElemType e);

// 出队
Status DeQueue_3_28(LinkQueue* Q, QElemType* e);

// 输出队列元素
void Output(LinkQueue Q);


int main(int argc, char* argv[]) {
    LinkQueue Q;
    int i;
    QElemType e;
    
    printf("████ 初始化队列...\n");
    InitQueue_3_28(&Q);
    
    printf("████ 进行 5 次连续入队操作...\n");
    for(i = 1; i <= 5; i++) {
        EnQueue_3_28(&Q, i);
    
        printf("█ 元素 \"%d\" 入队后，队列中的元素为：", i);
        Output(Q);
    }
    
    printf("████ 进行 5 次连续出队操作...\n");
    for(i = 1; i <= 5; i++) {
        DeQueue_3_28(&Q, &e);
        
        printf("█ 元素 \"%d\" 出队后，队列中的元素为：", e);
        Output(Q);
    }
    
    return 0;
}


// 队列初始化
Status InitQueue_3_28(LinkQueue* Q) {
    if(Q == NULL) {
        return ERROR;
    }
    
    // 创建头结点
    (*Q).rear = (QueuePtr) malloc(sizeof(QNode));
    if((*Q).rear == NULL) {
        exit(OVERFLOW);
    }
    
    // 头结点数据
    (*Q).rear->data = INT_MAX;
    
    // 循环队列，首尾相接
    (*Q).rear->next = (*Q).rear;
    
    return OK;
}

// 入队
Status EnQueue_3_28(LinkQueue* Q, QElemType e) {
    QueuePtr p;
    
    if(Q == NULL || (*Q).rear == NULL) {
        return ERROR;
    }
    
    // 创建新结点，链式队列被认为不存在队满的问题
    p = (QueuePtr) malloc(sizeof(QNode));
    if(p == NULL) {
        exit(OVERFLOW);
    }
    p->data = e;
    
    p->next = (*Q).rear->next;
    (*Q).rear->next = p;
    (*Q).rear = p;
    
    return OK;
}

// 出队
Status DeQueue_3_28(LinkQueue* Q, QElemType* e) {
    QueuePtr h, p;
    
    if(Q == NULL || (*Q).rear == NULL) {
        return ERROR;
    }
    
    // 获取头结点
    h = (*Q).rear->next;
    
    // 如果只有一个头结点，说明没有元素，无法队列
    if(h == (*Q).rear) {
        return ERROR;
    }
    
    // 指向待移除元素
    p = h->next;
    *e = p->data;
    
    h->next = p->next;
    
    // 如果只有一个元素
    if(p == (*Q).rear) {
        // 更新队尾游标
        (*Q).rear = h;
    }
    
    free(p);
    
    return OK;
}

// 输出队列元素
void Output(LinkQueue Q) {
    QueuePtr p;
    
    if(Q.rear == NULL) {
        printf("\n");
        return;
    }
    
    for(p = Q.rear->next->next; p != Q.rear->next; p = p->next) {
        printf("%d ", p->data);
    }
    
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//

/* 宏定义 */
#define MAXQSIZE 100    // 最大队列长度

/* 队列元素类型 */
typedef int QElemType;

/* 顺序循环队列 */
typedef struct {
    QElemType* base;    // 指向队列存储空间
    int front, rear;    // 队头和队尾游标
    int tag;            // 0表示未满，1表示满
} SqQueue;

// 队列初始化
Status InitQueue_3_29(SqQueue* Q);

// 入队
Status EnQueue_3_29(SqQueue* Q, QElemType e);

// 出队
Status DeQueue_3_29(SqQueue* Q, QElemType* e);

// 输出队列元素
void Output(SqQueue Q);


int main(int argc, char* argv[]) {
    SqQueue Q;
    int i;
    QElemType e;
    
    printf("████ 初始化队列...\n");
    InitQueue_3_29(&Q);
    
    printf("████ 进行 5 次连续入队操作...\n");
    for(i = 1; i <= 5; i++) {
        EnQueue_3_29(&Q, i);
        
        printf("█ 元素 \"%d\" 入队后，队列中的元素为：", i);
        Output(Q);
    }
    
    printf("████ 进行 5 次连续出队操作...\n");
    for(i = 1; i <= 5; i++) {
        DeQueue_3_29(&Q, &e);
        
        printf("█ 元素 \"%d\" 出队后，队列中的元素为：", e);
        Output(Q);
    }
    
    return 0;
}


// 队列初始化
Status InitQueue_3_29(SqQueue* Q) {
    if(Q == NULL) {
        return ERROR;
    }
    
    (*Q).base = (QElemType*) malloc(MAXQSIZE * sizeof(QElemType));
    if((*Q).base == NULL) {
        exit(OVERFLOW);
    }
    
    (*Q).front = (*Q).rear = 0;
    (*Q).tag = 0;
    
    return OK;
}

// 入队
Status EnQueue_3_29(SqQueue* Q, QElemType e) {
    // 队列满
    if((*Q).tag == 1) {
        return ERROR;
    }
    
    (*Q).base[(*Q).rear] = e;
    (*Q).rear = ((*Q).rear + 1) % MAXQSIZE;
    
    // 如果发现队满，则更新标记
    if((*Q).rear == (*Q).front) {
        (*Q).tag = 1;
    }
    
    return OK;
}

// 出队
Status DeQueue_3_29(SqQueue* Q, QElemType* e) {
    // 队列空
    if((*Q).front == (*Q).rear && (*Q).tag == 0) {
        return ERROR;
    }
    
    *e = (*Q).base[(*Q).front];
    (*Q).front = ((*Q).front + 1) % MAXQSIZE;
    
    // 如果发现队空，则更新标记
    if((*Q).rear == (*Q).front) {
        (*Q).tag = 0;
    }
    
    return OK;
}

// 输出队列元素
void Output(SqQueue Q) {
    int i;
    
    // 队列空
    if(Q.front == Q.rear && Q.tag == 0) {
        printf("\n");
        return;
    }
    
    i = Q.front;
    
    do {
        printf("%d ", Q.base[i]);
        i = (i + 1) % MAXQSIZE;
    } while(i != Q.rear);
    
    printf("\n");
}

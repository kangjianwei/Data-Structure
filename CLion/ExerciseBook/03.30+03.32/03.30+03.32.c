#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//
#include "SqList.h"     //**▲02 线性表**//

/* 宏定义 */
#define MAXQSIZE 5      // 队列长度，同时也是后续斐波那契数列数列的维度
#define MAX 100000

/* 队列元素类型 */
typedef int QElemType;

/* 顺序循环队列 */
typedef struct {
    QElemType* base;    // 指向队列存储空间
    int rear;           // 队尾游标
    int length;         // 队列元素个数
} SqQueue;

// 队列初始化
Status InitQueue_3_30(SqQueue* Q);

// 入队
Status EnQueue_3_30(SqQueue* Q, QElemType e);

// 出队
Status DeQueue_3_30(SqQueue* Q, QElemType* e);

/*
 * 求k阶斐波那契数列满足特定条件的前n+1项
 */
Status Algo_3_32(int k, SqList* fib);


// 输出队列元素
void Output(SqQueue Q) {
    int head;
    
    if(Q.length == 0) {
        printf("\n");
        return;
    }
    
    // 队头游标
    head = (Q.rear - Q.length + MAXQSIZE) % MAXQSIZE;
    
    do {
        printf("%d ", Q.base[head]);
        head = (head + 1) % MAXQSIZE;
    } while(head != Q.rear);
    
    printf("\n");
}


int main(int argc, char* argv[]) {
    int i;
    
    printf("████████ 题 3.30 验证...\n");
    {
        SqQueue Q;
        QElemType e;
        printf("████ 初始化队列...\n");
        InitQueue_3_30(&Q);\

        printf("████ 进行 5 次连续入队操作...\n");
        for(i = 1; i <= 5; i++) {
            EnQueue_3_30(&Q, i);
            printf("█ 元素 \"%d\" 入队后，队列中的元素为：", i);
            Output(Q);
        }
        
        printf("████ 进行 5 次连续出队操作...\n");
        for(i = 1; i <= 5; i++) {
            DeQueue_3_30(&Q, &e);
            printf("█ 元素 \"%d\" 出队后，队列中的元素为：", e);
            Output(Q);
        }
    }
    
    printf("████████ 题 3.32 验证...\n");
    {
        SqList fib;
        
        Algo_3_32(MAXQSIZE, &fib);
        printf("█ %d 阶斐波那契数列的前 %d 项为：\n", MAXQSIZE, fib.length);
        for(i = 0; i < fib.length; i++) {
            printf("%d ", fib.elem[i]);
        }
        printf("\n");
    }
    
    return 0;
}


// 队列初始化
Status InitQueue_3_30(SqQueue* Q) {
    if(Q == NULL) {
        return ERROR;
    }
    
    (*Q).base = (QElemType*) malloc(MAXQSIZE * sizeof(QElemType));
    if((*Q).base == NULL) {
        exit(OVERFLOW);
    }
    
    (*Q).rear = 0;
    (*Q).length = 0;
    
    return OK;
}

// 入队
Status EnQueue_3_30(SqQueue* Q, QElemType e) {
    
    if(Q == NULL) {
        return ERROR;
    }
    
    // 注意队列满的条件
    if((*Q).length == MAXQSIZE) {
        return ERROR;
    }
    
    (*Q).base[(*Q).rear] = e;
    (*Q).rear = ((*Q).rear + 1) % MAXQSIZE;
    
    (*Q).length++;
    
    return OK;
}

// 出队
Status DeQueue_3_30(SqQueue* Q, QElemType* e) {
    int head;
    
    if(Q == NULL) {
        return ERROR;
    }
    
    // 队列空
    if((*Q).length == 0) {
        return ERROR;
    }
    
    // 队头游标
    head = ((*Q).rear - (*Q).length + MAXQSIZE) % MAXQSIZE;
    
    *e = (*Q).base[head];
    
    (*Q).length--;
    
    return OK;
}

/*
 * 求k阶斐波那契数列满足特定条件的前n+1项
 *
 *【注】
 * 个人感觉这个题出的有些牵强。
 * 因为既然要求计算前n+1项，但队列只保留后k项，这说明那个前n+1项必定需要保存到别的地方。
 * 可是，既然保存了前n+1项，就没必要用到循环队列中的后k项了，多余...
 * 如果本题改为计算满足条件的【第】n+1项的值，那么循环队列是有应用价值的
 */
Status Algo_3_32(int k, SqList* fib) {
    int flag;
    int i, j, sum;
    SqQueue Q;
    ElemType e;
    
    if(k < 2 || MAX < 0) {
        return ERROR;
    }
    
    InitQueue_3_30(&Q);
    InitList(fib);
    
    // 前k-1项为0
    for(i = 1; i <= k - 1; i++) {
        EnQueue_3_30(&Q, 0);
        ListInsert(fib, i, 0);
    }
    
    // 第k项为1
    EnQueue_3_30(&Q, 1);
    ListInsert(fib, i, 1);
    
    while((flag = GetElem(*fib, i, &e))==OK && e<=MAX){
        /*
         * 计算循环队列中现有元素的和
         * 其实这一步可以改为计算顺序表中后k项的和，这样一来就没循环队列啥事了
         */
        for(j = 0, sum = 0; j < Q.length; j++) {
            sum += Q.base[j];
        }
        
        // 此处的e只是用作临时变量
        DeQueue_3_30(&Q, &e);
        
        // 将新计算出的元素入队
        EnQueue_3_30(&Q, sum);
        
        // 顺便往顺序表中缓存一份
        ListInsert(fib, ++i, sum);
    }
    
    return flag;
}

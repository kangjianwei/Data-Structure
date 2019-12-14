#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//
#include "SqList.h"     //**��02 ���Ա�**//

/* �궨�� */
#define MAXQSIZE 5      // ���г��ȣ�ͬʱҲ�Ǻ���쳲������������е�ά��
#define MAX 100000

/* ����Ԫ������ */
typedef int QElemType;

/* ˳��ѭ������ */
typedef struct {
    QElemType* base;    // ָ����д洢�ռ�
    int rear;           // ��β�α�
    int length;         // ����Ԫ�ظ���
} SqQueue;

// ���г�ʼ��
Status InitQueue_3_30(SqQueue* Q);

// ���
Status EnQueue_3_30(SqQueue* Q, QElemType e);

// ����
Status DeQueue_3_30(SqQueue* Q, QElemType* e);

/*
 * ��k��쳲��������������ض�������ǰn+1��
 */
Status Algo_3_32(int k, SqList* fib);


// �������Ԫ��
void Output(SqQueue Q) {
    int head;
    
    if(Q.length == 0) {
        printf("\n");
        return;
    }
    
    // ��ͷ�α�
    head = (Q.rear - Q.length + MAXQSIZE) % MAXQSIZE;
    
    do {
        printf("%d ", Q.base[head]);
        head = (head + 1) % MAXQSIZE;
    } while(head != Q.rear);
    
    printf("\n");
}


int main(int argc, char* argv[]) {
    int i;
    
    printf("���������������� �� 3.30 ��֤...\n");
    {
        SqQueue Q;
        QElemType e;
        printf("�������� ��ʼ������...\n");
        InitQueue_3_30(&Q);\

        printf("�������� ���� 5 ��������Ӳ���...\n");
        for(i = 1; i <= 5; i++) {
            EnQueue_3_30(&Q, i);
            printf("�� Ԫ�� \"%d\" ��Ӻ󣬶����е�Ԫ��Ϊ��", i);
            Output(Q);
        }
        
        printf("�������� ���� 5 ���������Ӳ���...\n");
        for(i = 1; i <= 5; i++) {
            DeQueue_3_30(&Q, &e);
            printf("�� Ԫ�� \"%d\" ���Ӻ󣬶����е�Ԫ��Ϊ��", e);
            Output(Q);
        }
    }
    
    printf("���������������� �� 3.32 ��֤...\n");
    {
        SqList fib;
        
        Algo_3_32(MAXQSIZE, &fib);
        printf("�� %d ��쳲��������е�ǰ %d ��Ϊ��\n", MAXQSIZE, fib.length);
        for(i = 0; i < fib.length; i++) {
            printf("%d ", fib.elem[i]);
        }
        printf("\n");
    }
    
    return 0;
}


// ���г�ʼ��
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

// ���
Status EnQueue_3_30(SqQueue* Q, QElemType e) {
    
    if(Q == NULL) {
        return ERROR;
    }
    
    // ע�������������
    if((*Q).length == MAXQSIZE) {
        return ERROR;
    }
    
    (*Q).base[(*Q).rear] = e;
    (*Q).rear = ((*Q).rear + 1) % MAXQSIZE;
    
    (*Q).length++;
    
    return OK;
}

// ����
Status DeQueue_3_30(SqQueue* Q, QElemType* e) {
    int head;
    
    if(Q == NULL) {
        return ERROR;
    }
    
    // ���п�
    if((*Q).length == 0) {
        return ERROR;
    }
    
    // ��ͷ�α�
    head = ((*Q).rear - (*Q).length + MAXQSIZE) % MAXQSIZE;
    
    *e = (*Q).base[head];
    
    (*Q).length--;
    
    return OK;
}

/*
 * ��k��쳲��������������ض�������ǰn+1��
 *
 *��ע��
 * ���˸о�����������Щǣǿ��
 * ��Ϊ��ȻҪ�����ǰn+1�������ֻ������k���˵���Ǹ�ǰn+1��ض���Ҫ���浽��ĵط���
 * ���ǣ���Ȼ������ǰn+1���û��Ҫ�õ�ѭ�������еĺ�k���ˣ�����...
 * ��������Ϊ�������������ġ��ڡ�n+1���ֵ����ôѭ����������Ӧ�ü�ֵ��
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
    
    // ǰk-1��Ϊ0
    for(i = 1; i <= k - 1; i++) {
        EnQueue_3_30(&Q, 0);
        ListInsert(fib, i, 0);
    }
    
    // ��k��Ϊ1
    EnQueue_3_30(&Q, 1);
    ListInsert(fib, i, 1);
    
    while((flag = GetElem(*fib, i, &e))==OK && e<=MAX){
        /*
         * ����ѭ������������Ԫ�صĺ�
         * ��ʵ��һ�����Ը�Ϊ����˳����к�k��ĺͣ�����һ����ûѭ������ɶ����
         */
        for(j = 0, sum = 0; j < Q.length; j++) {
            sum += Q.base[j];
        }
        
        // �˴���eֻ��������ʱ����
        DeQueue_3_30(&Q, &e);
        
        // ���¼������Ԫ�����
        EnQueue_3_30(&Q, sum);
        
        // ˳����˳����л���һ��
        ListInsert(fib, ++i, sum);
    }
    
    return flag;
}

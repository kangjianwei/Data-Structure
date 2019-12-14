#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//

/* �궨�� */
#define MAXQSIZE 100    // �����г���

/* ����Ԫ������ */
typedef int QElemType;

/* ˳��ѭ������ */
typedef struct {
    QElemType* base;    // ָ����д洢�ռ�
    int front, rear;    // ��ͷ�Ͷ�β�α�
    int tag;            // 0��ʾδ����1��ʾ��
} SqQueue;

// ���г�ʼ��
Status InitQueue_3_29(SqQueue* Q);

// ���
Status EnQueue_3_29(SqQueue* Q, QElemType e);

// ����
Status DeQueue_3_29(SqQueue* Q, QElemType* e);

// �������Ԫ��
void Output(SqQueue Q);


int main(int argc, char* argv[]) {
    SqQueue Q;
    int i;
    QElemType e;
    
    printf("�������� ��ʼ������...\n");
    InitQueue_3_29(&Q);
    
    printf("�������� ���� 5 ��������Ӳ���...\n");
    for(i = 1; i <= 5; i++) {
        EnQueue_3_29(&Q, i);
        
        printf("�� Ԫ�� \"%d\" ��Ӻ󣬶����е�Ԫ��Ϊ��", i);
        Output(Q);
    }
    
    printf("�������� ���� 5 ���������Ӳ���...\n");
    for(i = 1; i <= 5; i++) {
        DeQueue_3_29(&Q, &e);
        
        printf("�� Ԫ�� \"%d\" ���Ӻ󣬶����е�Ԫ��Ϊ��", e);
        Output(Q);
    }
    
    return 0;
}


// ���г�ʼ��
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

// ���
Status EnQueue_3_29(SqQueue* Q, QElemType e) {
    // ������
    if((*Q).tag == 1) {
        return ERROR;
    }
    
    (*Q).base[(*Q).rear] = e;
    (*Q).rear = ((*Q).rear + 1) % MAXQSIZE;
    
    // ������ֶ���������±��
    if((*Q).rear == (*Q).front) {
        (*Q).tag = 1;
    }
    
    return OK;
}

// ����
Status DeQueue_3_29(SqQueue* Q, QElemType* e) {
    // ���п�
    if((*Q).front == (*Q).rear && (*Q).tag == 0) {
        return ERROR;
    }
    
    *e = (*Q).base[(*Q).front];
    (*Q).front = ((*Q).front + 1) % MAXQSIZE;
    
    // ������ֶӿգ�����±��
    if((*Q).rear == (*Q).front) {
        (*Q).tag = 0;
    }
    
    return OK;
}

// �������Ԫ��
void Output(SqQueue Q) {
    int i;
    
    // ���п�
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

#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include <limits.h>     // �ṩһЩ��ֵ����
#include "Status.h"     //**��01 ����**//

/*
 * �������� ע�� ��������
 *
 * ����ʹ�ô�ͷ����ѭ�������ʾ����
 */

/* ����Ԫ������ */
typedef int QElemType;

/* ���н������ */
typedef struct QNode {
    QElemType data;
    struct QNode* next;
} QNode, * QueuePtr;

/* ���нṹ */
typedef struct {
    QueuePtr rear;      // ��βָ��
} LinkQueue;            // ���е���ʽ�洢��ʾ

// ���г�ʼ��
Status InitQueue_3_28(LinkQueue* Q);

// ���
Status EnQueue_3_28(LinkQueue* Q, QElemType e);

// ����
Status DeQueue_3_28(LinkQueue* Q, QElemType* e);

// �������Ԫ��
void Output(LinkQueue Q);


int main(int argc, char* argv[]) {
    LinkQueue Q;
    int i;
    QElemType e;
    
    printf("�������� ��ʼ������...\n");
    InitQueue_3_28(&Q);
    
    printf("�������� ���� 5 ��������Ӳ���...\n");
    for(i = 1; i <= 5; i++) {
        EnQueue_3_28(&Q, i);
    
        printf("�� Ԫ�� \"%d\" ��Ӻ󣬶����е�Ԫ��Ϊ��", i);
        Output(Q);
    }
    
    printf("�������� ���� 5 ���������Ӳ���...\n");
    for(i = 1; i <= 5; i++) {
        DeQueue_3_28(&Q, &e);
        
        printf("�� Ԫ�� \"%d\" ���Ӻ󣬶����е�Ԫ��Ϊ��", e);
        Output(Q);
    }
    
    return 0;
}


// ���г�ʼ��
Status InitQueue_3_28(LinkQueue* Q) {
    if(Q == NULL) {
        return ERROR;
    }
    
    // ����ͷ���
    (*Q).rear = (QueuePtr) malloc(sizeof(QNode));
    if((*Q).rear == NULL) {
        exit(OVERFLOW);
    }
    
    // ͷ�������
    (*Q).rear->data = INT_MAX;
    
    // ѭ�����У���β���
    (*Q).rear->next = (*Q).rear;
    
    return OK;
}

// ���
Status EnQueue_3_28(LinkQueue* Q, QElemType e) {
    QueuePtr p;
    
    if(Q == NULL || (*Q).rear == NULL) {
        return ERROR;
    }
    
    // �����½�㣬��ʽ���б���Ϊ�����ڶ���������
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

// ����
Status DeQueue_3_28(LinkQueue* Q, QElemType* e) {
    QueuePtr h, p;
    
    if(Q == NULL || (*Q).rear == NULL) {
        return ERROR;
    }
    
    // ��ȡͷ���
    h = (*Q).rear->next;
    
    // ���ֻ��һ��ͷ��㣬˵��û��Ԫ�أ��޷�����
    if(h == (*Q).rear) {
        return ERROR;
    }
    
    // ָ����Ƴ�Ԫ��
    p = h->next;
    *e = p->data;
    
    h->next = p->next;
    
    // ���ֻ��һ��Ԫ��
    if(p == (*Q).rear) {
        // ���¶�β�α�
        (*Q).rear = h;
    }
    
    free(p);
    
    return OK;
}

// �������Ԫ��
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

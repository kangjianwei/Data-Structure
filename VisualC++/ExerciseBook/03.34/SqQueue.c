/*=============================
 * ���е�˳��洢�ṹ��˳����У�
 ==============================*/

#include "SqQueue.h"                //**��03 ջ�Ͷ���**//

/*
 * ��ʼ��
 *
 * ����һ���յ�˳����С�
 * ��ʼ���ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *��ע��
 * ����Ķ�����ѭ������
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
 * ���
 *
 * di������ӷ���0ָʾ�Ӷ�ͷ��ӣ�1ָʾ�Ӷ�β���
 */
Status EnQueue_3_34(SqQueue* Q, QElemType e, int di) {
    
    // �Ӷ�ͷ���
    if(di == 0) {
        (*Q).front = ((*Q).front - 1 + MAXQSIZE) % MAXQSIZE;
        (*Q).base[(*Q).front] = e;
        return OK;
    }
    
    // �Ӷ�β���
    if(di == 1) {
        (*Q).base[(*Q).rear] = e;
        (*Q).rear = ((*Q).rear + 1) % MAXQSIZE;
        return OK;
    }
    
    return ERROR;
}

/*
 * ����
 *
 * �Ƴ�����ͷ����Ԫ�أ�����洢��e�С�
 */
Status DeQueue(SqQueue* Q, QElemType* e) {
    if(Q == NULL || (*Q).base == NULL) {
        return ERROR;
    }
    
    // ���пյı�־
    if((*Q).front == (*Q).rear) {
        return ERROR;
    }
    
    // ����
    *e = (*Q).base[(*Q).front];
    
    // ͷָ��ǰ��
    (*Q).front = ((*Q).front + 1) % MAXQSIZE;
    
    return OK;
}

/*
 * ����
 *
 * ��visit�������ʶ���Q
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

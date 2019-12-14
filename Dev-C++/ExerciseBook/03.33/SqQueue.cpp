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
 * ��ӣ�˫�˶��У�������ޣ�
 */
Status EnQueue_3_33(SqQueue* Q, QElemType e) {
    int head, tail;
    
    if(Q == NULL) {
        return ERROR;
    }
    
    // �����������ֱ�ӷ���
    if(((*Q).rear + 1) % MAXQSIZE == (*Q).front) {
        return ERROR;
    }
    
    // �������Ϊ�գ�ֱ�Ӳ��뵽��β
    if((*Q).front == (*Q).rear) {
        (*Q).base[(*Q).rear] = e;
        (*Q).rear = ((*Q).rear + 1) % MAXQSIZE;
        return OK;
    }
    
    head = (*Q).base[(*Q).front];                               // ��ͷԪ��ֵ
    tail = (*Q).base[((*Q).rear - 1 + MAXQSIZE) % MAXQSIZE];    // ��βԪ��ֵ
    
    // ���������Ԫ�ص���ҵʱ�䲻С�ڶ�����βԪ����ҵ��ƽ��ʱ�䣬��Ԫ�ز��ڶ�β
    if(e >= (head + tail) / 2) {
        (*Q).base[(*Q).rear] = e;
        (*Q).rear = ((*Q).rear + 1) % MAXQSIZE;
        
        // ���򣬲��ڶ�ͷ
    } else {
        (*Q).front = ((*Q).front - 1 + MAXQSIZE) % MAXQSIZE;
        (*Q).base[(*Q).front] = e;
    }
    
    return OK;
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

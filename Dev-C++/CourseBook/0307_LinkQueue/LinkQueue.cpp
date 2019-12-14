/*=========================
 * ���е���ʽ�洢�ṹ�����ӣ�
 ==========================*/

#ifndef LINKQUEUE_C
#define LINKQUEUE_C

#include "LinkQueue.h"                    //**��03 ջ�Ͷ���**//

/*
 * ��ʼ��
 *
 * ����һ���յ����ӡ�
 * ��ʼ���ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *��ע��
 * ����Ķ��д���ͷ���
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
 * ����(�ṹ)
 *
 * �ͷ�������ռ�ڴ档
 */
Status DestroyQueue(LinkQueue* Q) {
    if(Q == NULL) {
        return ERROR;
    }
    
    while((*Q).front) {
        (*Q).rear = (*Q).front->next;
        free((*Q).front);
        (*Q).front = (*Q).rear;
    }
    
    return OK;
}

/*
 * �ÿ�(����)
 *
 * ������Ҫ�ͷ������з�ͷ��㴦�Ŀռ䡣
 */
Status ClearQueue(LinkQueue* Q) {
    if(Q == NULL) {
        return ERROR;
    }
    
    (*Q).rear = (*Q).front->next;
    
    while((*Q).rear) {
        (*Q).front->next = (*Q).rear->next;
        free((*Q).rear);
        (*Q).rear = (*Q).front->next;
    }
    
    (*Q).rear = (*Q).front;
    
    return OK;
}

/*
 * �п�
 *
 * �ж��������Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ����Ϊ��
 * FALSE: ���Ӳ�Ϊ��
 */
Status QueueEmpty(LinkQueue Q) {
    if(Q.front == Q.rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/*
 * ����
 *
 * �������Ӱ�������ЧԪ�ص�������
 */
int QueueLength(LinkQueue Q) {
    int count = 0;
    QueuePtr p = Q.front;
    
    while(p != Q.rear) {
        count++;
        p = p->next;
    }
    
    return count;
}

/*
 * ȡֵ
 *
 * ��ȡ��ͷԪ�أ�����洢��e�С�
 * ��������ҵ�������OK�����򣬷���ERROR��
 */
Status GetHead(LinkQueue Q, QElemType* e) {
    QueuePtr p;
    
    if(Q.front == NULL || Q.front == Q.rear) {
        return ERROR;
    }
    
    p = Q.front->next;
    *e = p->data;
    
    return OK;
}

/*
 * ���
 *
 * ��Ԫ��e��ӵ�����β����
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
 * ����
 *
 * �Ƴ�����ͷ����Ԫ�أ�����洢��e�С�
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

/*
 * ����
 *
 * ��visit�������ʶ���Q
 */
Status QueueTraverse(LinkQueue Q, void (Visit)(QElemType)) {
    QueuePtr p;
    
    if(Q.front == NULL) {
        return ERROR;
    }
    
    p = Q.front->next;
    
    while(p != NULL) {
        Visit(p->data);
        p = p->next;
    }
    
    printf("\n");
    
    return OK;
}

#endif

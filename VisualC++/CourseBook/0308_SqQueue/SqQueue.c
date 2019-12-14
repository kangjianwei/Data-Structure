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
 * ����(�ṹ)
 *
 * �ͷ�ѭ��˳�������ռ�ڴ档
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
 * �ÿ�(����)
 *
 * ֻ������ѭ��˳������д洢�����ݣ����ͷ�˳�������ռ�ڴ档
 */
Status ClearQueue(SqQueue* Q) {
    if(Q == NULL || (*Q).base == NULL) {
        return ERROR;
    }
    
    (*Q).front = (*Q).rear = 0;
    
    return OK;
}

/*
 * �п�
 *
 * �ж�ѭ��˳��������Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ѭ��˳�����Ϊ��
 * FALSE: ѭ��˳����в�Ϊ��
 */
Status QueueEmpty(SqQueue Q) {
    // ���пյı�־
    if(Q.front == Q.rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/*
 * ����
 *
 * ����ѭ��˳����а�������ЧԪ�ص�������
 */
int QueueLength(SqQueue Q) {
    if(Q.base == NULL) {
        return 0;
    }
    
    // ���г���
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

/*
 * ȡֵ
 *
 * ��ȡ��ͷԪ�أ�����洢��e�С�
 * ��������ҵ�������OK�����򣬷���ERROR��
 */
Status GetHead(SqQueue Q, QElemType* e) {
    // ���пյı�־
    if(Q.base == NULL || Q.front == Q.rear) {
        return ERROR;
    }
    
    *e = Q.base[Q.front];
    
    return OK;
}

/*
 * ���
 *
 * ��Ԫ��e��ӵ�����β����
 */
Status EnQueue(SqQueue* Q, QElemType e) {
    if(Q == NULL || (*Q).base == NULL) {
        return ERROR;
    }
    
    // �������ı�־�����˷�һ���ռ������ֶ��пպͶ�������
    if(((*Q).rear + 1) % MAXQSIZE == (*Q).front) {
        return ERROR;
    }
    
    // ���
    (*Q).base[(*Q).rear] = e;
    
    // βָ��ǰ��
    (*Q).rear = ((*Q).rear + 1) % MAXQSIZE;
    
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

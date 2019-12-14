/*=============================
 * ���е�˳��洢�ṹ��˳����У�
 ==============================*/

#ifndef SQQUEUE_H
#define SQQUEUE_H

#include <stdio.h>
#include <stdlib.h>        // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"        //**��01 ����**//

/* �궨�� */
#define MAXQSIZE 1000   //�����г���

/* ѭ������Ԫ�����Ͷ��� */
typedef int QElemType;

// ѭ�����е�˳��洢�ṹ
typedef struct {
    QElemType* base;    // ��̬����洢�ռ�
    int front;          // ͷָ�룬�����в��գ�ָ���ͷԪ��
    int rear;           // βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
} SqQueue;


/*
 * ��ʼ��
 *
 * ����һ���յ�˳����С�
 * ��ʼ���ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *��ע��
 * ����Ķ�����ѭ������
 */
Status InitQueue(SqQueue* Q);

/*
 * ����(�ṹ)
 *
 * �ͷ�ѭ��˳�������ռ�ڴ档
 */
Status DestroyQueue(SqQueue* Q);

/*
 * �ÿ�(����)
 *
 * ֻ������ѭ��˳������д洢�����ݣ����ͷ�˳�������ռ�ڴ档
 */
Status ClearQueue(SqQueue* Q);

/*
 * �п�
 *
 * �ж�ѭ��˳��������Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ѭ��˳�����Ϊ��
 * FALSE: ѭ��˳����в�Ϊ��
 */
Status QueueEmpty(SqQueue Q);

/*
 * ����
 *
 * ����ѭ��˳����а�������ЧԪ�ص�������
 */
int QueueLength(SqQueue Q);

/*
 * ȡֵ
 *
 * ��ȡ��ͷԪ�أ�����洢��e�С�
 * ��������ҵ�������OK�����򣬷���ERROR��
 */
Status GetHead(SqQueue Q, QElemType* e);

/*
 * ���
 *
 * ��Ԫ��e��ӵ�����β����
 */
Status EnQueue(SqQueue* Q, QElemType e);

/*
 * ����
 *
 * �Ƴ�����ͷ����Ԫ�أ�����洢��e�С�
 */
Status DeQueue(SqQueue* Q, QElemType* e);

/*
 * ����
 *
 * ��visit�������ʶ���Q
 */
Status QueueTraverse(SqQueue Q, void(Visit)(QElemType));

#endif

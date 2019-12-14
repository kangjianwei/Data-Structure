/*=============================
 * ���е�˳��洢�ṹ��˳����У�
 ==============================*/

#ifndef SQQUEUE_H
#define SQQUEUE_H

#include <stdio.h>
#include <stdlib.h>        // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"        //**��01 ����**//

/*
 * �������� ע�� ��������
 *
 * �����ѭ��������������޵�˫�˶���
 * ����Ԫ�ؿ��ԴӶ�ͷ���β��ӣ���ֻ�ܴӶ�ͷ����
 */

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
 * ���
 *
 * di������ӷ���0ָʾ�Ӷ�ͷ��ӣ�1ָʾ�Ӷ�β���
 */
Status EnQueue_3_34(SqQueue* Q, QElemType e, int di);

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

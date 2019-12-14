/*=========================
 * ���е���ʽ�洢�ṹ�����ӣ�
 ==========================*/

#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//

/* ����Ԫ�����Ͷ��壬�����¼�ͻ���Ϣ */
typedef struct {
    int ArrivedTime;    // �ͻ�����ʱ��
    int Duration;       // ����ҵ�������ʱ��
    int Count;          // �˱�����¼����ÿ�����еĿͻ��ǵڼ������̲����޴˱��������Ӵ˱�����Ŀ���ǹ۲��Ŷ�״������
} QElemType;            //���е�����Ԫ������

// ����Ԫ�ؽṹ
typedef struct QNode {
    QElemType data;
    struct QNode* next;
} QNode, * QueuePtr;

// ���нṹ
typedef struct {
    QueuePtr front;     // ��ͷָ��
    QueuePtr rear;      // ��βָ��
} LinkQueue;            // ���е���ʽ�洢��ʾ


/*
 * ��ʼ��
 *
 * ����һ���յ����ӡ�
 * ��ʼ���ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *��ע��
 * ����Ķ��д���ͷ���
 */
Status InitQueue(LinkQueue* Q);

/*
 * �п�
 *
 * �ж��������Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ����Ϊ��
 * FALSE: ���Ӳ�Ϊ��
 */
Status QueueEmpty(LinkQueue Q);

/*
 * ����
 *
 * �������Ӱ�������ЧԪ�ص�������
 */
int QueueLength(LinkQueue Q);

/*
 * ȡֵ
 *
 * ��ȡ��ͷԪ�أ�����洢��e�С�
 * ��������ҵ�������OK�����򣬷���ERROR��
 */
Status GetHead(LinkQueue Q, QElemType* e);

/*
 * ���
 *
 * ��Ԫ��e��ӵ�����β����
 */
Status EnQueue(LinkQueue* Q, QElemType e);

/*
 * ����
 *
 * �Ƴ�����ͷ����Ԫ�أ�����洢��e�С�
 */
Status DeQueue(LinkQueue* Q, QElemType* e);

#endif

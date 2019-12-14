/*===============================
 * ���Ա����ʽ�洢�ṹ������
 *
 * �����㷨: 2.8��2.9��2.10��2.11
 ================================*/

#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//

// �¼�����ö�ٳ�����0�������¼���1��4��ʾ�ĸ����ڵ��뿪�¼�
typedef enum {
    Arrive, Leave_1, Leave_2, Leave_3, Leave_4
} EventType;

/* �¼�����Ԫ�����Ͷ��� */
typedef struct
{
    int OccurTime;      // �¼�����ʱ��
    EventType NType;    // �¼�����
} Event, ElemType;      // �¼�����Ԫ��

/*
 * ������ṹ
 *
 * ע������ĵ��������ͷ���
 */
typedef struct LNode {
    ElemType data;      // ���ݽ��
    struct LNode* next; // ָ����һ������ָ��
} LNode;

// ָ���������ָ��
typedef LNode* LinkList;


/*
 * ��ʼ��
 *
 * ��ʼ���ɹ��򷵻�OK�����򷵻�ERROR��
 */
Status InitList(LinkList* L);

/*
 * �п�
 *
 * �ж��������Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ����Ϊ��
 * FALSE: ����Ϊ��
 */
Status ListEmpty(LinkList L);

/*
 * ���������������� �㷨2.9 ����������������
 *
 * ����
 *
 * �������i��λ���ϲ���e������ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ����
 */
Status ListInsert(LinkList L, int i, ElemType e);

/*
 * ���������������� �㷨2.10 ����������������
 *
 * ɾ��
 *
 * ɾ�������i��λ���ϵ�Ԫ�أ�������ɾ��Ԫ�ش洢��e�С�
 * ɾ���ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ����
 */
Status ListDelete(LinkList L, int i, ElemType* e);

#endif

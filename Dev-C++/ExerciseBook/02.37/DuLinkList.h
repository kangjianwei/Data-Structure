/*=====================
 * ˫��ѭ������
 *
 * �����㷨: 2.18��2.19
 ======================*/

#ifndef DULINKLIST_H
#define DULINKLIST_H

#include <stdio.h>
#include <stdlib.h>     //�ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//

/* ˫��ѭ������Ԫ�����Ͷ��� */
typedef int ElemType;

/*
 * ˫��ѭ������ṹ
 *
 * ע�������˫��ѭ���������ͷ���
 */
typedef struct DuLNode {
    ElemType data;
    struct DuLNode* prior;  // ǰ��
    struct DuLNode* next;   // ���
} DuLNode;

// ָ��˫��ѭ���������ָ��
typedef DuLNode* DuLinkList;


/*
 * ��ʼ��
 *
 * ��ʼ���ɹ��򷵻�OK�����򷵻�ERROR��
 */
Status InitList(DuLinkList* L);

/*
 * ���������������� �㷨2.18 ����������������
 *
 * ����
 *
 * ��˫��ѭ�������i��λ���ϲ���e������ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ����
 */
Status ListInsert(DuLinkList L, int i, ElemType e);

/*
 * ����
 *
 * ��visit��������˫��ѭ������L
 */
void ListTraverse(DuLinkList L, void(Visit)(ElemType));

/*
 * ��ȡѭ������L�ϵ�i��Ԫ�ص�����
 *
 * �������� ע�� ��������
 * 1.��static�ĺ����ǵ�ǰ����ֻ��DuLinkList��ʹ�ã����ᱻ����ļ�����
 * 2.����������Ϊlen������Ҫ��ȡ��len+1��Ԫ�ص�����ʱ������������ѭ���������Է��ص���ͷ���
 */
static DuLinkList GetElemP(DuLinkList L, int i);

#endif

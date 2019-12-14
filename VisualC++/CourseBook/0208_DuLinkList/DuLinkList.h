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
 * ����(�ṹ)
 *
 * �ͷ�˫��ѭ��������ռ�ڴ档
 */
Status DestroyList(DuLinkList* L);

/*
 * �ÿ�(����)
 *
 * ������Ҫ�ͷ�˫��ѭ�������з�ͷ��㴦�Ŀռ䡣
 */
Status ClearList(DuLinkList L);

/*
 * �п�
 *
 * �ж�˫��ѭ���������Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ˫��ѭ������Ϊ��
 * FALSE: ˫��ѭ������Ϊ��
 */
Status ListEmpty(DuLinkList L);

/*
 * ����
 *
 * ����˫��ѭ�������������ЧԪ�ص�������
 */
int ListLength(DuLinkList L);

/*
 * ȡֵ
 *
 * ��ȡ˫��ѭ�������е�i��Ԫ�أ�����洢��e�С�
 * ��������ҵ�������OK�����򣬷���ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ���������ⲻ���ϱ����ͨ��Լ����
 * ͨ����i�ĺ���Ӧ��ָ����������0��ʼ������
 */
Status GetElem(DuLinkList L, int i, ElemType* e);

/*
 * ����
 *
 * ����˫��ѭ���������׸���e����Compare��ϵ��Ԫ��λ��
 * ���������������Ԫ�أ��򷵻�0��
 *
 *����ע��
 * Ԫ��e��Compare�����ڶ����β�
 */
int LocateElem(DuLinkList L, ElemType e, Status(Compare)(ElemType, ElemType));

/*
 * ǰ��
 *
 * ��ȡԪ��cur_e��ǰ����
 * ������ڣ�����洢��pre_e�У�����OK��
 * ��������ڣ��򷵻�ERROR��
 */
Status PriorElem(DuLinkList L, ElemType cur_e, ElemType* pre_e);

/*
 * ���
 *
 * ��ȡԪ��cur_e�ĺ�̣�
 * ������ڣ�����洢��next_e�У�����OK��
 * ��������ڣ��򷵻�ERROR��
 */
Status NextElem(DuLinkList L, ElemType cur_e, ElemType* next_e);

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
 * ���������������� �㷨2.19 ����������������
 *
 * ɾ��
 *
 * ɾ��˫��ѭ�������i��λ���ϵ�Ԫ�أ�������ɾ��Ԫ�ش洢��e�С�
 * ɾ���ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ����
 */
Status ListDelete(DuLinkList L, int i, ElemType* e);

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

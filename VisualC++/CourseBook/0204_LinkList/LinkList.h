/*===============================
 * ���Ա����ʽ�洢�ṹ������
 *
 * �����㷨: 2.8��2.9��2.10��2.11
 ================================*/

#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>     // �ṩ malloc��realloc��free��exit ԭ��
#include <string.h>     // �ṩ strstr ԭ��
#include "Status.h"     //**��01 ����**//

/* ������Ԫ�����Ͷ��� */
typedef int ElemType;

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
 * ����(�ṹ)
 *
 * �ͷ�������ռ�ڴ档
 */
Status DestroyList(LinkList* L);

/*
 * �ÿ�(����)
 *
 * ������Ҫ�ͷ������з�ͷ��㴦�Ŀռ䡣
 */
Status ClearList(LinkList L);

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
 * ����
 *
 * ���������������ЧԪ�ص�������
 */
int ListLength(LinkList L);

/*
 * ���������������� �㷨2.8 ����������������
 *
 * ȡֵ
 *
 * ��ȡ�����е�i��Ԫ�أ�����洢��e�С�
 * ��������ҵ�������OK�����򣬷���ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ���������ⲻ���ϱ����ͨ��Լ����
 * ͨ����i�ĺ���Ӧ��ָ����������0��ʼ������
 */
Status GetElem(LinkList L, int i, ElemType* e);

/*
 * ����
 *
 * �����������׸���e����Compare��ϵ��Ԫ��λ��
 * ���������������Ԫ�أ��򷵻�0��
 *
 *����ע��
 * Ԫ��e��Compare�����ڶ����β�
 */
int LocateElem(LinkList L, ElemType e, Status(Compare)(ElemType, ElemType));

/*
 * ǰ��
 *
 * ��ȡԪ��cur_e��ǰ����
 * ������ڣ�����洢��pre_e�У�����OK��
 * ��������ڣ��򷵻�ERROR��
 */
Status PriorElem(LinkList L, ElemType cur_e, ElemType* pre_e);

/*
 * ���
 *
 * ��ȡԪ��cur_e�ĺ�̣�
 * ������ڣ�����洢��next_e�У�����OK��
 * ��������ڣ��򷵻�ERROR��
 */
Status NextElem(LinkList L, ElemType cur_e, ElemType* next_e);

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

/*
 * ����
 *
 * ��visit������������L
 */
void ListTraverse(LinkList L, void(Visit)(ElemType));

/*
 * ���������������� �㷨2.11 ����������������
 *
 * ͷ�巨��������
 *
 *
 *����ע��
 *
 * �̲���Ĭ�ϴӿ���̨��ȡ���ݡ�
 * ����Ϊ�˷�����ԣ�����ÿ�����ж��ֶ��������ݣ�
 * �������ѡ���Ԥ����ļ�path�ж�ȡ�������ݡ�
 *
 * �����Ҫ�ӿ���̨��ȡ���ݣ���pathΪNULL����Ϊ�մ���
 * �����Ҫ���ļ��ж�ȡ���ݣ�����Ҫ��path����д�ļ�����Ϣ��
 */
Status CreateList_Head(LinkList* L, int n, char* path);

/*
 * β�巨��������
 *
 *
 *����ע��
 *
 * �̲���Ĭ�ϴӿ���̨��ȡ���ݡ�
 * ����Ϊ�˷�����ԣ�����ÿ�����ж��ֶ��������ݣ�
 * �������ѡ���Ԥ����ļ�path�ж�ȡ�������ݡ�
 *
 * �����Ҫ�ӿ���̨��ȡ���ݣ���pathΪNULL����Ϊ�մ���
 * �����Ҫ���ļ��ж�ȡ���ݣ�����Ҫ��path����д�ļ�����Ϣ��
 */
Status CreateList_Tail(LinkList* L, int n, char* path);

#endif

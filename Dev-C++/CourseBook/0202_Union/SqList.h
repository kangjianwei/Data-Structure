/*=============================
 * ���Ա��˳��洢�ṹ��˳���
 *
 * �����㷨: 2.3��2.4��2.5��2.6
 =============================*/

#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//

/* �궨�� */
#define LIST_INIT_SIZE 100  // ˳���洢�ռ�ĳ�ʼ������
#define LISTINCREMENT  10   // ˳���洢�ռ�ķ�������

/* ˳���Ԫ�����Ͷ��� */
typedef int ElemType;

/*
 * ˳���ṹ
 *
 * ע��elem��ʹ��ǰ��Ҫ��Ϊ������ڴ棬��Ԫ�ش�elem[0]����ʼ�洢
 */
typedef struct {
    ElemType* elem;     // ˳���洢�ռ�Ļ�ַ��ָ��˳�����ռ�ڴ����ʼλ�ã�
    int length;   // ��ǰ˳����ȣ���������Ԫ�أ�
    int listsize; // ��ǰ����Ĵ洢���������Դ洢����Ԫ�أ�
} SqList;


/*
 * ���������������� �㷨2.3 ����������������
 *
 * ��ʼ��
 *
 * ��ʼ���ɹ��򷵻�OK�����򷵻�ERROR��
 */
Status InitList(SqList* L);

/*
 * ����
 *
 * ����˳����������ЧԪ�ص�������
 */
int ListLength(SqList L);

/*
 * ȡֵ
 *
 * ��ȡ˳����е�i��Ԫ�أ�����洢��e�С�
 * ��������ҵ�������OK�����򣬷���ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ���������ⲻ���ϱ����ͨ��Լ����
 * ͨ����i�ĺ���Ӧ��ָ����������0��ʼ������
 */
Status GetElem(SqList L, int i, ElemType* e);

/*
 * ���������������� �㷨2.6 ����������������
 *
 * ����
 *
 * ����˳������׸���e����Compare��ϵ��Ԫ��λ��
 * ���������������Ԫ�أ��򷵻�0��
 *
 *����ע��
 * Ԫ��e��Compare�����ڶ����β�
 */
int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType));

/*
 * ���������������� �㷨2.4 ����������������
 *
 * ����
 *
 * ��˳����i��λ���ϲ���e������ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ����
 */
Status ListInsert(SqList* L, int i, ElemType e);

/*
 * ����
 *
 * ��visit��������˳���L
 */
void ListTraverse(SqList L, void (Visit)(ElemType));

#endif


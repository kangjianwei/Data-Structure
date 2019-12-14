/*=======================
 * ��չ�ĵ�������������
 *
 * �����㷨: 2.20
 ========================*/

#ifndef ELINKLIST_H
#define ELINKLIST_H

#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include <limits.h>     // �ṩһЩ���޳���
#include "Status.h"     //**��01 ����**//

/*
 * �������� ע�� ��������
 *
 * �̲��е�������������ΪLinkList��
 * ����Ϊ���뵥�������֣��ʽ�������ΪELinkList��
 * ��������������ɶ���ͨ�����һ����չ��
 */

/* ��������Ԫ�����Ͷ��� */
typedef int ElemType;

/*
 * ��������ṹ
 *
 * ע������������������ͷ���
 */
typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, * Link, * Position;

/* ά����������ͷβָ�뼰������Ϣ */
typedef struct {
    Link head, tail;    // �ֱ�ָ�����������е�ͷ����β���
    int len;            // ָʾ��������������Ԫ�صĸ���
} ELinkList;


/*�������������������������������������������� �ڴ���� ��������������������������������������������*/

/*
 * �ڴ����
 *
 * Ϊ������������һ����㣬������ָ��������e��
 *
 *����ע��
 * static���εĺ����Ǹú������޵�ǰ�ļ���ʹ��
 */
Status MakeNode(Link* p, ElemType e);

/*
 * �ڴ����
 *
 * �ͷ�����������ָ���Ľ�㡣
 *
 *����ע��
 * static���εĺ����Ǹú������޵�ǰ�ļ���ʹ��
 */
void FreeNode(Link* p);


/*�������������������������������������������� ��������� ��������������������������������������������*/

/*
 * ��ʼ��
 *
 * ��ʼ���ɹ��򷵻�OK�����򷵻�ERROR��
 */
Status InitList(ELinkList* L);

/*
 * ����(�ṹ)
 *
 * �ͷ�������ռ�ڴ档
 */
Status DestroyList(ELinkList* L);

/*
 * �ÿ�(����)
 *
 * ������Ҫ�ͷ������з�ͷ��㴦�Ŀռ䡣
 */
Status ClearList(ELinkList* L);

/*
 * �п�
 *
 * �ж��������Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ����Ϊ��
 * FALSE: ����Ϊ��
 */
Status ListEmpty(ELinkList L);

/*
 * ����
 *
 * ���������������ЧԪ�ص�������
 */
int ListLength(ELinkList L);

/*
 * ����
 *
 * �����������׸���e����Compare��ϵ��Ԫ�����á�
 * ���������������Ԫ�أ��򷵻�NULL��
 *
 *����ע��
 * 1.Ԫ��e��Compare�����ڶ����β�
 * 2.����ķ���ֵ��Ŀ��Ԫ�ص����ã���������λ��
 */
Position LocateElem(ELinkList L, ElemType e, Status(Compare)(ElemType, ElemType));

/*
 * ���������������� �㷨2.20 ����������������
 *
 * ����
 *
 * �������i��λ���ϲ���e������ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ����
 * ���Կ������㷨2.9�ĸ�д
 */
Status ListInsert(ELinkList* L, int i, ElemType e);

/*
 * ɾ��
 *
 * ɾ�������i��λ���ϵ�Ԫ�أ�������ɾ��Ԫ�ش洢��e�С�
 * ɾ���ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *����ע��
 * �̲���i�ĺ�����Ԫ��λ�ã���1��ʼ����
 * ���Կ������㷨2.10�ĸ�д
 */
Status ListDelete(ELinkList* L, int i, ElemType* e);

/*
 * ����
 *
 * ��visit������������L
 */
void ListTraverse(ELinkList L, void(Visit)(ElemType));


/*�������������������������������������������� ������չ���� ��������������������������������������������*/

/*
 * ȡֵ
 *
 * ��ȡ���p��Ԫ��ֵ��
 */
ElemType GetCurElem(Link p);

/*
 * ��ֵ
 *
 * Ϊ���p����Ԫ��ֵ��
 */
Status SetCurElem(Link p, ElemType e);

/*
 * ͷ���
 *
 * ��ȡͷ������á�
 */
Position GetHead(ELinkList L);

/*
 * β���
 *
 * ��ȡβ������á�
 */
Position GetLast(ELinkList L);

/*
 * ǰ��
 *
 * ��ȡ���p��ǰ������������ڣ��򷵻�NULL��
 */
Position PriorPos(ELinkList L, Link p);

/*
 * ���
 *
 * ��ȡ���p�ĺ�̣���������ڣ���NULL��
 */
Position NextPos(ELinkList L, Link p);

/*
 * ����
 *
 * ��������L�е�i(����Ϊ0)����㣬���������ô���p���ҷ���OK
 * ���iֵ���Ϲ棬�򷵻�ERROR
 * �ر�ע�⣬��iΪ0ʱ��p�洢����ͷ��������
 */
Status LocatePos(ELinkList L, int i, Link* p);

/*
 * ����
 *
 * ��s�����뵽h�����棬��Ϊh����ĵ�һ�����
 *
 *����ע��
 * �̲��ж��ڸ÷�����������Щ���⣬�������������İ汾
 */
Status InsFirst(ELinkList* L, Link h, Link s);

/*
 * ɾ��
 *
 * ɾ��h����ĵ�һ����㣬����q�洢��ɾ����������
 *
 *����ע��
 * �̲��ж��ڸ÷����Ķ������Դֲڣ��������������İ汾
 */
Status DelFirst(ELinkList* L, Link h, Link* q);

/*
 * ǰ�����
 *
 * ��s�����뵽p���֮ǰ������pָ���½��
 */
Status InsBefore(ELinkList* L, Link* p, Link s);

/*
 * �������
 *
 * ��s�����뵽p���֮ǰ������pָ���½��
 */
Status InsAfter(ELinkList* L, Link* p, Link s);

/*
 * ��β�����
 *
 * ��s��ָ��һ���������������L����
 */
Status Append(ELinkList* L, Link s);

/*
 * ��β���Ƴ�
 *
 * �������β����Ƴ����������Ƴ��Ľ�����ô洢��q��
 */
Status Remove(ELinkList* L, Link* q);

#endif

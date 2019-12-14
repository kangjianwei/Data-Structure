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

/*
 * ��������Ԫ�����Ͷ���
 * �������ڶ���ʽ�У��õ��˽ṹ�����͵�Ԫ��
 */
typedef struct {
    float coef;     // ����ʽϵ��
    int expn;       // ����ʽָ��
} ElemType;         // ���¶�����չ�����Ա���Ԫ������

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
 * ����
 *
 * ���������������ЧԪ�ص�������
 */
int ListLength(ELinkList L);

/*
 * ����
 *
 * ������Һ����봫ͳ�İ汾��һ����
 * �������Ȼ������Ԫ��e����Compare()==0��Ԫ�أ�����ҵ���ʹ��q�洢�����ã�������True��
 * ����������������ã�������׸���Ԫ��e����Compare()>0��Ԫ�ص�ǰ����������FALSE��
 * ��������е�Ԫ�ؾ�����e��q�洢ͷ������á�
 * ��������е�Ԫ�ؾ�С��e��q�洢β������á�
 * ���������£��Ὣq�ÿա�
 *
 *����ע��
 * 1.Ԫ��e��Compare�����ڶ����β�
 */
Status LocateElem(ELinkList L, ElemType e, Position* q, Status(Compare)(ElemType, ElemType));


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
 * ���
 *
 * ��ȡ���p�ĺ�̣���������ڣ���NULL��
 */
Position NextPos(ELinkList L, Link p);

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
 * ��β�����
 *
 * ��s��ָ��һ���������������L����
 */
Status Append(ELinkList* L, Link s);

#endif

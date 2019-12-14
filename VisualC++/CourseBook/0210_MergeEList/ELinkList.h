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
 * ��β�����
 *
 * ��s��ָ��һ���������������L����
 */
Status Append(ELinkList* L, Link s);

#endif

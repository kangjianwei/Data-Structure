/*******************************************
 *                                         *
 * �ļ���: ��02 ���Ա�\04 SinglyLinkedList *
 *                                         *
 * �ļ���: SinglyLinkedList.h              *
 *                                         *
 * ��  ��: ��������ز����б�              *
 *                                         *
 *******************************************/

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>						//�ṩmalloc��realloc��free��exitԭ��
#include "../../��01 ����/Status.h"		//**��01 ����**//
#include "../../��01 ����/Scanf.c"		//**��01 ����**//

/* ���������Ͷ��� */
#ifndef BANKQUEUING_H			/*������ģ�������Ŷ��㷨�У���������Ҫ���¶���*/
typedef int LElemType_L;

/* ������ṹ�� */
typedef struct LNode
{
	LElemType_L data;
	struct LNode* next;
}LNode;
typedef LNode* LinkList;		//ָ���������ָ�� 
#endif

/* ��������ͷ��㣩�����б� */ 
Status InitList_L(LinkList *L);
/*����������������������
��(01)��ʼ��������L�� ��
����������������������*/

Status ClearList_L(LinkList L);
/*��������������������������������
��(02)�ÿյ�����L��ͷ��㱣���� �� 
��������������������������������*/ 

void DestroyList_L(LinkList *L);
/*����������������������������������������
��(03)���ٵ�����L����ͬͨ���һ�����١� ��
����������������������������������������*/

Status ListEmpty_L(LinkList L);
/*��������������������������������
��(04)�жϵ�����L�Ƿ�Ϊ�ա�     ��
��������������������������������*/

int ListLength_L(LinkList L);
/*��������������������������
��(05)���ص�����LԪ�ظ��� ��
��������������������������*/ 

Status GetElem_L(LinkList L, int i, LElemType_L *e);
/*����������������������������������������
��(06)�㷨2.8����e���յ�����L�е�i��Ԫ�ة�
����������������������������������������*/ 

int LocateElem_L(LinkList L, LElemType_L e, Status(Compare)(LElemType_L, LElemType_L));
/*��������������������������������������������������������
��(07)���ص�����L�е�һ����e����Compare��ϵ��Ԫ��λ�� ��
��������������������������������������������������������*/ 

Status PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e);
/*������������������������������
��(08)��pre_e����cur_e��ǰ������
������������������������������*/ 

Status NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e);
/*��������������������������������
��(09)��next_e����cur_e�ĺ�̡� ��
��������������������������������*/

Status ListInsert_L(LinkList L, int i, LElemType_L e);
/*��������������������������������������������
��(10)�㷨2.9���ڵ�����L��i��λ��֮ǰ����e����
��������������������������������������������*/

Status ListDelete_L(LinkList L, int i, LElemType_L *e);
/*������������������������������������������������������
��(11)�㷨2.10��ɾ��������L��i��λ�õ�ֵ������e���ա� ��
������������������������������������������������������*/ 

Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L));
/*������������������������������
��(12)��Visit�������ʵ�����L����
������������������������������*/  

Status CreateList_HL(FILE *fp, LinkList *L, int n);
/*����������������������������������������������
��(13)�㷨2.11��ͷ�巨����������L(��������)�� ��
����������������������������������������������*/  

Status CreateList_TL(FILE *fp, LinkList *L, int n);
/*������������������������������������
��(14)β�巨����������L(˳������)�� ��
������������������������������������*/  

#endif

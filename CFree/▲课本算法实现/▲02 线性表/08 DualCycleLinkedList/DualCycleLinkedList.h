/**********************************************
 *						                      *
 * �ļ���: ��02 ���Ա�\08 DualCycleLinkedList *
 * 							                  *
 * �ļ���: DualCycleLinkedList.h              *
 * 							                  *
 * ��  ��: ˫��ѭ��������ز����б�           *
 *                                            *
 **********************************************/

#ifndef DUALCYCLELINKEDLIST_H
#define DUALCYCLELINKEDLIST_H

#include <stdlib.h>						//�ṩmalloc��realloc��free��exitԭ��
#include "../../��01 ����/Status.h"		//**��01 ����**//

/* ˫ѭ���������Ͷ��� */
typedef int LElemType_DC;
typedef struct DuLNode
{
	LElemType_DC data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode;
typedef DuLNode* DuLinkList;		 	//ָ��˫ѭ������ṹ��ָ�� 

/*	˫ѭ���������б�	*/ 
Status InitList_DuL(DuLinkList *L);
/*����������������������
��(01)��ʼ��˫����L�� ��
����������������������*/

Status ClearList_DuL(DuLinkList L);
/*��������������
��(02)�ÿ�L�� ��
��������������*/ 

void DestroyList_DuL(DuLinkList *L);
/*��������������
��(03)����L�� ��
��������������*/

Status ListEmpty_DuL(DuLinkList L);
/*����������������������
��(04)�ж�L�Ƿ�Ϊ�ա� ��
����������������������*/ 

int ListLength_DuL(DuLinkList L);
/*����������������������
��(05)����LԪ�ظ����� ��
����������������������*/ 

Status GetElem_DuL(DuLinkList L, int i, LElemType_DC *e);
/*������������������������������������
��(06)��e����L�е�i������Ԫ��ֵ�� ��
������������������������������������*/ 

int LocateElem_DuL(DuLinkList L, LElemType_DC e, Status (Compare)(LElemType_DC, LElemType_DC));
/*��������������������������������������������������
��(07)����L�е�һ����e����Compare��ϵ��Ԫ��λ�� ��
��������������������������������������������������*/ 

Status PriorElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *pre_e);
/*������������������������������
��(08)��pre_e����cur_e��ǰ������
������������������������������*/ 

Status NextElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *next_e);
/*��������������������������������
��(09)��next_e����cur_e�ĺ�̡� ��
��������������������������������*/

DuLinkList GetElemPtr_DuL(DuLinkList L, int i);
/*����������������������������������
��(10)����L��ָ���i������ָ�롣��
����������������������������������*/

Status ListInsert_DuL(DuLinkList L, int i, LElemType_DC e);
/*����������������������������������������
��(11)�㷨2.18����L��i��λ��֮ǰ����e�� ��
����������������������������������������*/

Status ListDelete_DuL(DuLinkList L, int i, LElemType_DC *e);
/*������������������������������������������������
��(12)�㷨2.19��ɾ��L��i��λ�õ�ֵ������e���ա� ��
������������������������������������������������*/ 

void ListTraverse_DuL(DuLinkList L, void(Visit)(LElemType_DC));
/*������������������������
��(13)��Visit��������L����
������������������������*/ 
 
#endif

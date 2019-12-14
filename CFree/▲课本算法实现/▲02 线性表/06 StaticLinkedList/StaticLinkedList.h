/********************************
 *						        *
 * �ļ���: ��02 ���Ա�          *
 * 							    *
 * �ļ���: StaticLinkedList.h   *
 * 							    *
 * ��  ��: ��̬������ز����б� *
 *                              *
 ********************************/

/*��������������������������������������������������
�ﱸע��                                          ��
��1.Ϊ�������㣬��Ϊ���뵽�Ŀռ����һ��ͷ��㡱����
��2.ģ��ϵͳ��̬����ռ���̡�                    ��
��3.�������������ε�����ݽṹ�α��������졣      ��       
��������������������������������������������������*/ 
 
#ifndef STATICLINKEDLIST_H
#define STATICLINKEDLIST_H

#include <stdlib.h>						////�ṩmalloc��realloc��free��exitԭ��
#include "../../��01 ����/Status.h"		//**��01 ����**//

/* �궨�� */ 
#define MAXSIZE 1000					//��̬�������󳤶�

/* ��̬�������Ͷ��� */
typedef int SLinkList;					//��̬��������
typedef int LElemType_S;
typedef struct 
{
	LElemType_S data;
	int cur;							//cur���α꣬��ָ���ã������������±� 
}Component[MAXSIZE];					//����ռ����� 

/* ȫ�ֱ��� */
Component SPACE;						//��̬����ռ� 

/*	��̬�������б� */
void InitSpace_SL();
/*��������������������������������������������������������������
��(01)�㷨2.14����һά����SPACE�и���������һ����ı��ÿռ䡣 ��
��������������������������������������������������������������*/

int Malloc_SL();
/*������������������������������������
��(02)�㷨2.15��Ϊ������������ռ䡣��
������������������������������������*/

void Free_SL(int k);
/*������������������������������������������
��(03)�㷨2.16�����±�Ϊk�Ŀ��н����ա� ��
������������������������������������������*/

int InitList_SL(SLinkList *H);
/*����������������������������������
��(04)��ʼ����̬��������ͷ��㡣��
����������������������������������*/

Status ClearList_SL(SLinkList H);
/*������������
��(05)�ÿա���
������������*/ 

void DestroyList_SL(SLinkList *H);
/*������������
��(06)���١���
������������*/

Status ListEmpty_SL(SLinkList H);
/*������������
��(07)�пա���
������������*/

int ListLength_SL(SLinkList H);
/*������������
��(08)�󳤡���
������������*/ 

Status GetElem_SL(SLinkList H, int i, LElemType_S *e);
/*������������
��(09)ȡֵ����
������������*/

int LocateElem_SL(SLinkList H, LElemType_S e);
/*����������������������������������
��(10)�㷨2.13������Ԫ��e��λ�� ��
����������������������������������*/

Status PriorElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *pre_e);
/*������������
��(11)ǰ������
������������*/

Status NextElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *next_e);
/*������������
��(12)��̡���
������������*/ 

Status ListInsert_SL(SLinkList H, int i, LElemType_S e);
/*������������
��(13)���롣��
������������*/

Status ListDelete_SL(SLinkList H, int i, LElemType_S *e);
/*������������
��(14)ɾ������
������������*/

Status ListTraverse_SL(SLinkList H, void(Visit)(LElemType_S));
/*������������
��(15)���ʡ���
������������*/ 

#endif

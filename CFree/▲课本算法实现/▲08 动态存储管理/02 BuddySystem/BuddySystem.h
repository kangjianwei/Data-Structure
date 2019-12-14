/*****************************
 *                           *
 * �ļ���: ��08 ��̬�洢���� *
 *                           *
 * �ļ���: BuddySystem.h     *
 *                           *
 * ��  ��: ���ϵͳ          *
 *                           *
 *****************************/

#ifndef BUDDYSYSTEM_H
#define BUDDYSYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../��01 ����/Status.h"							//**��01 ����**//

/* �궨�� */
#define M 3						//�����ÿռ�������64k�ֵ�2���ݴΣ��ӱ�ĸ���ΪM+1 

/* ���Ͷ��� */
typedef struct WORD_b
{ 
	struct WORD_b *llink;		//ָ��ǰ����� 
	int tag;					//���־��0���У�1ռ�� 
	int kval;					//���С��ֵΪ2���ݴ�k 
	struct WORD_b *rlink;		//ͷ����ָ���̽�� 
}WORD_b;						//WORD_b���ڴ������ͣ����ĵ�һ����Ҳ��Ϊhead 
typedef struct HeadNode
{
	int nodesize;				//������Ŀ��п�Ĵ�С 
	WORD_b *first;				//������ı�ͷָ�� 
}FreeList[M+1];					//��ͷ�������� 

/* ȫ�ֱ��� */
WORD_b *start, *end;			//�ڴ������յ� 
 
/* ���ϵͳ�����б� */
void InitSpace_b(FreeList avail);
/*����������������������������
��(01)��ʼ��һ������ڴ�顣��
����������������������������*/

WORD_b* AllocBuddy(FreeList avail, int n);
/*��������������������������
��(02)�㷨8.2�������㷨�� ��
��������������������������*/

WORD_b* Buddy(WORD_b* p); 
/*��������������������������������������
��(03)����p���ڴ��Ļ���ڴ���ַ�� ��
��������������������������������������*/

void Reclaim_b(FreeList avail, WORD_b** p);
/*����������������
��(04)�����㷨����
����������������*/

void PrintLayout_b(FreeList avail);
/*����������������������������������
��(05)�����ǰ�����ڴ����ֹ��ַ����
����������������������������������*/

#endif 

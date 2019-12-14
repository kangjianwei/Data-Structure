/*******************************
 *                             *
 * �ļ���: ��08 ��̬�洢����   *
 *                             *
 * �ļ���: BoundaryTagMethod.h *
 *                             *
 * ��  ��: �߽��ʶ��          *
 *                             *
 *******************************/

#ifndef BOUNDARYTAGMETHOD_H
#define BOUNDARYTAGMETHOD_H

#include <stdio.h>
#include "../../��01 ����/Status.h"							//**��01 ����**//

/* �궨�� */
#define MAX 1000
#define E 10						//����ռ�ʱ������������ռ���������ռ��E���֣� 
#define FootLoc(p) p+(p)->size-1	//ָ��p��ָ���ĵײ� 

/* ���Ͷ��� */
typedef struct WORD_a				//WORD_a���ڴ������� 
{
	union
	{
		struct WORD_a *llink;		//ͷ����ָ��ǰ����� 
		struct WORD_a *uplink;		//�ײ���ָ�򱾽��ͷ�� 
	}Ptr;
	
	int tag;						//���־��0���У�1ռ�ã�ͷ����β������ 
	int size;						//ͷ���򣬿��С 
	struct WORD_a *rlink;			//ͷ����ָ���̽�� 
}WORD_a;
typedef WORD_a* Space;				//Space�������ÿռ�ָ������ 

/* ȫ�ֱ��� */
Space av;							//�����ڴ�����ʼ��ַ 

/* �߽��ʶ�������б� */
void InitSpace_a(WORD_a memory[MAX+2]);
/*����������������������������
��(01)��ʼ��һ������ڴ�顣��
����������������������������*/

Space AllocBoundTag(Space *pav, int n);
/*����������������������������������������
��(02)�㷨8.1�������㷨���״���Ϸ����� ��
����������������������������������������*/

void Reclaim_a(Space *pav, Space *p);
/*����������������
��(03)�����㷨����
����������������*/

void PrintLayout_a(Space av, Space pav);
/*����������������������������������
��(04)�����ǰ�����ڴ����ֹ��ַ����
����������������������������������*/

#endif 

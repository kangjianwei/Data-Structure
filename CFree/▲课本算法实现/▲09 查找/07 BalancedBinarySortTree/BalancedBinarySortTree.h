/**************************************
 *                                    *
 * �ļ���: ��09 ����                  *
 *                                    *
 * �ļ���: BalancedBinarySortTree.h   *
 *                                    *
 * ��  ��: ƽ�������������ز����б� *
 *                                    *
 **************************************/

#ifndef BALANCEDBINARYSORTTREE_H
#define BALANCEDBINARYSORTTREE_H

#include <stdlib.h>
#include <math.h>
#include "../00 Base/Base.c" 			//**��09 ����**//

/* �궨�� */
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a) < (b))
#define RT(a,b) ((a) > (b))
#define LH  1							//�������� 
#define EH  0							//�ȸ� 
#define RH -1							//�������� 

/* ���Ͷ��� */
typedef int Boolean;					//����ֵ 
typedef ElemType_Search BBSTElemType;	//ƽ�����������Ԫ������ 
typedef struct BBSTNode					//ƽ���������AVL�����洢��ʾ
{
	BBSTElemType data;
	int bf;								//����ƽ������ 
	struct BBSTNode* lchild;
	struct BBSTNode* rchild;
	
	union								//ֻ��ϰ�����ʱ��ʹ�� 
	{
		int lsize;						//��ֵΪ�������н������1 
	};//���������� 
}BBSTNode;								//ƽ�������������� 
typedef BBSTNode* BBSTree;				//ָ��ƽ���������������ָ��
 
/* ƽ���������AVL���������б� */
Status CreateAVL(BBSTree *BBST, Table T);
/*������������������
��(01)����AVL���� ��
������������������*/

BBSTree SearchAVL(BBSTree BBST, KeyType key);
/*��������������������������������������������������
��(02)���ң�����ָ��key��ָ�룬�������ڷ���MULL�� ��
��������������������������������������������������*/

Status InsertAVL(BBSTree *BBST, ElemType_Search e, Boolean *taller);
/*����������������������
��(03)�㷨9.11�����롣��
����������������������*/

Status DeleteAVL(BBSTree *BBST, ElemType_Search e, BBSTree f, BBSTree p, Boolean *taller, int mark);
/*������������
��(04)ɾ������
������������*/

void RightBalance(BBSTree *BBST);
/*������������������
��(05)��ƽ�⴦����
������������������*/

void LeftBalance(BBSTree *BBST);
/*����������������������������
��(06)�㷨9.12����ƽ�⴦����
����������������������������*/

void R_Rotate(BBSTree *p);
/*����������������������
��(07)�㷨9.9�������� ��
����������������������*/

void L_Rotate(BBSTree *p);
/*����������������������
��(08)�㷨9.10����������
����������������������*/

void InOrderTraverse_AVL(BBSTree BBST, void(Visit)(ElemType_Search));
/*����������������
��(09)�����������
����������������*/

int AVLDepth(BBSTree BBST);
/*������������������
��(10)��������ȡ���
������������������*/

void PrintAVLTree(BBSTree BBST);
/*��������������
��(11)��ӡ������
��������������*/

#endif 

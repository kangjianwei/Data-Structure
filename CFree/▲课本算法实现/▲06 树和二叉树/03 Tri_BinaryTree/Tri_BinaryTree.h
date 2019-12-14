/**********************************************
 *											  *
 * �ļ���: ��06 ���Ͷ�����\03 Tri_BinaryTree  *
 * 									    	  *
 * �ļ���: Tri_BinaryTree.h                   *
 * 											  *
 * ��  ��: ��������������洢�ṹ��ز����б� *
 *                                            *
 **********************************************/

#ifndef TRI_BINARYTREE_H
#define TRI_BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>								//�ṩmalloc��realloc��free��exitԭ��
#include <math.h>								//�ṩpow��logԭ�� 
#include "../../��01 ����/Status.h"				//**��01 ����**//
#include "../../��01 ����/Scanf.c"				//**��01 ����**//

/* ����������������洢��������Ͷ��� */
typedef char TElemType_Tri;						//���������Ԫ�ؾ�Ϊ�ַ�
typedef struct TBiTNode
{
	TElemType_Tri data;							//���Ԫ��
	struct TBiTNode* parent;					//˫�׽��ָ�� 
	struct TBiTNode* lchild;					//����ָ�� 
	struct TBiTNode* rchild;					//�Һ���ָ�� 
}TBiTNode;										//��������� 
typedef TBiTNode* TBiTree;						//ָ�����������ָ��

/* ����Ԫ������ */
typedef TBiTree QElemType_L;						
#include "../../��03 ջ�Ͷ���/07 LinkQueue/LinkQueue.c" //**��03 ջ�Ͷ���**//

/* ��������������洢�ṹ�����б� */
void InitBiTree_Tri(TBiTree *T);
/*������������������������������������
��(01)����ն�����T (��ʼ��������)����
������������������������������������*/

void ClearBiTree_Tri(TBiTree *T);
/*��������������������
��(02)��ն�����T�� ��
��������������������*/

void DestroyBiTree_Tri(TBiTree *T);
/*��������������������
��(03)���ٶ�����T�� ��
��������������������*/

Status BiTreeEmpty_Tri(TBiTree T);
/*����������������������������
��(04)�ж϶�����T�Ƿ�Ϊ�ա� ��
����������������������������*/

void Create_Tri(TBiTree *T, FILE *fp);
/*��������������������������
��(05)���������캯�����á���
��������������������������*/

Status CreateBiTree_Tri(FILE *fp, TBiTree *T);
/*����������������������������
��(06)���������й������������
����������������������������*/

int BiTreeLength_Tri(TBiTree T);
/*������������������������������������������
��(07)���ض��������ȣ�����ȫ���������㣩����
������������������������������������������*/

int BiTreeDepth_Tri(TBiTree T);
/*������������������������������
��(08)���ض�������ȣ�����������
������������������������������*/

Status Root_Tri(TBiTree T, TElemType_Tri *e);
/*��������������������������������
��(09)��e���ض������ĸ����ֵ�� ��
��������������������������������*/

TElemType_Tri Value_Tri(TBiTree p);
/*������������������������������������
��(10)����ĳ����ֵ��pΪ���ָ�롣 ��
������������������������������������*/

void Assign_Tri(TBiTree p, TElemType_Tri value);
/*����������������������������������
��(11)Ϊĳ��㸳ֵ��pΪ���ָ�롣 ��
����������������������������������*/            

TBiTree Point(TBiTree T, TElemType_Tri e);
/*����������������������������
��(12)����ָ��ĳ����ָ�롣��
����������������������������*/

TElemType_Tri Parent_Tri(TBiTree T, TElemType_Tri e);
/*������������������������������
��(13)����ĳ����˫�׽��ֵ����
������������������������������*/

TElemType_Tri LeftChild_Tri(TBiTree T, TElemType_Tri e);
/*��������������������������������
��(14)����ĳ�������ӽ��ֵ����
��������������������������������*/

TElemType_Tri RightChild_Tri(TBiTree T, TElemType_Tri e);
/*��������������������������������
��(15)����ĳ�����Һ��ӽ��ֵ����
��������������������������������*/

TElemType_Tri LeftSibling_Tri(TBiTree T, TElemType_Tri e);
/*��������������������������������
��(16)����ĳ�������ֵܽ��ֵ����
��������������������������������*/

TElemType_Tri RightSibling_Tri(TBiTree T, TElemType_Tri e);
/*��������������������������������
��(17)����ĳ�������ֵܽ��ֵ����
��������������������������������*/

Status InsertBiTree_Tri(TBiTree T, TElemType_Tri e, TBiTree *T0, int LR);
/*��������������������������������������������������������������������
��(18)����T0���뵽��T�г�Ϊ���e��������LRΪ�����ǡ���
��������������������������������������������������������������������*/

Status DeleteBiTree_Tri(TBiTree T, TElemType_Tri e, int LR);
/*������������������������������������������������
��(19)ɾ��e��������������������LRΪɾ����ǡ� ��
������������������������������������������������*/

void LevelOrderTraverse_Tri(TBiTree T, void(Visit)(TElemType_Tri));
/*����������������������
��(20)�����������������
����������������������*/

void PreOrderTraverse_Tri(TBiTree T, void(Visit)(TElemType_Tri));
/*����������������������
��(21)ǰ���������������
����������������������*/

void InOrderTraverse_Tri(TBiTree T, void(Visit)(TElemType_Tri));
/*����������������������
��(22)�����������������
����������������������*/

void PostOrderTraverse_Tri(TBiTree T, void(Visit)(TElemType_Tri));
/*����������������������
��(23)�����������������
����������������������*/

void Print_Tri(TBiTree T);
/*����������������������������
��(24)���������Ľṹ��ӡ������
����������������������������*/

#endif

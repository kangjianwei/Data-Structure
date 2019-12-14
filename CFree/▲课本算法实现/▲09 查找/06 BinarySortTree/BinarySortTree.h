/**********************************
 *                                *
 * �ļ���: ��09 ����              *
 *                                *
 * �ļ���: BinarySortTree.h       *
 *                                *
 * ��  ��: ������������ز����б� *
 *                                *
 **********************************/

#ifndef BINARYSORTTREE_H
#define BINARYSORTTREE_H

#include <stdlib.h>
#include "../00 Base/Base.c" 				//**��09 ����**//

/* �꺯�� */
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a) < (b))

/* ���Ͷ��� */
typedef ElemType_Search BSTElemType;		//����������Ԫ������ 
typedef struct BSTNode						//�����������洢��ʾ
{
	BSTElemType data;
	struct BSTNode* lchild;
	struct BSTNode* rchild;
	
	union									//���������壬���ڵ�9��ϰ�����ʱʹ�� 
	{
		int RTag;							//������־ 
	};
}BSTNode;									//������������� 
typedef BSTNode* BSTree;					//ָ���������������ָ��
 
/* ���������������б� */
Status CreateBSTree(BSTree *BST, Table T);
/*����������������������
��(01)������������������
����������������������*/

BSTree SearchBST_1(BSTree BST, KeyType key);
/*��������������������������������������������������������������
��(02)�㷨9.5(a)�����ң�����ָ��key��ָ�룬�������ڷ���MULL�� ��
��������������������������������������������������������������*/

Status SearchBST_2(BSTree BST, KeyType key, BSTree f, BSTree *p);
/*����������������������������������������������������������
��(03)�㷨9.5(b)�����ң���������key������뵽��ȷ��λ�á� ��
����������������������������������������������������������*/

Status InsertBST(BSTree *BST, BSTElemType e);
/*����������������������������������
��(04)�㷨9.6������e����������������
����������������������������������*/

void InOrderTraverse_BST(BSTree BST, void(Visit)(ElemType_Search));
/*������������������������������������������
��(05)����������������������ɹؼ������С���
������������������������������������������*/

Status DeleteBST(BSTree *BST, KeyType key);
/*����������������������
��(06)�㷨9.7��ɾ���� ��
����������������������*/
 
Status Delete(BSTree *p);
/*��������������������������������
��(07)�㷨9.8��ɾ��pָ��Ľ�㡣��
��������������������������������*/

#endif 

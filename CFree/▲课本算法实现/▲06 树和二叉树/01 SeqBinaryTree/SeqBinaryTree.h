/********************************************
 *										    *
 * �ļ���: ��06 ���Ͷ�����\01 SeqBinaryTree *
 * 									        *
 * �ļ���: SeqBinaryTree.h                  *
 * 										    *
 * ��  ��: ������˳��洢�ṹ��ز����б�   *
 *                                          *
 ********************************************/

#ifndef SEQBINARYTREE_H
#define SEQBINARYTREE_H

#include <stdio.h>
#include <math.h>								//�ṩpowԭ�� 
#include "../../��01 ����/Status.h"				//**��01 ����**//
#include "../../��01 ����/Scanf.c"				//**��01 ����**//

/* �궨�� */
#define MAX_TREE_SIZE 100						//���������������

/* ��������˳��洢�ṹ��������Ͷ��� */
typedef char TElemType_Sq;						//����˳�������Ԫ�ؾ�Ϊ�ַ� 
typedef TElemType_Sq SqBiTree[MAX_TREE_SIZE];	//0�ŵ�Ԫ�洢�����	

/* ��㡰���ꡱ���� */
typedef struct 
{
	int level;			//������ڲ� 
	int order;			//����ڱ�����ţ�����ȫ���������㣩 
}Position;

/* ������˳��洢�ṹ�����б� */
void InitBiTree_Sq(SqBiTree T);
/*����������������������
��(01)����ն�����T�� ��
����������������������*/

void ClearBiTree_Sq(SqBiTree T);
/*��������������������
��(02)��ն�����T�� ��
��������������������*/

void DestroyBiTree_Sq(SqBiTree T);
/*��������������������
��(03)���ٶ�����T�� ��
��������������������*/

Status BiTreeEmpty_Sq(SqBiTree T);
/*����������������������������
��(04)�ж϶�����T�Ƿ�Ϊ�ա� ��
����������������������������*/

Status CreateBiTree_Le_Sq(FILE *fp, SqBiTree T);
/*����������������������������
��(05)���������й������������
����������������������������*/

Status CreateBiTree_Pre_Sq(FILE *fp, SqBiTree T, int i);
/*����������������������������
��(06)���������й������������
����������������������������*/

int BiTreeLength_Sq(SqBiTree T);
/*������������������������������������������
��(07)���ض��������ȣ�����ȫ���������㣩����
������������������������������������������*/

int BiTreeDepth_Sq(SqBiTree T);
/*������������������������������
��(08)���ض�������ȣ�����������
������������������������������*/

Status Root_Sq(SqBiTree T, TElemType_Sq *e);
/*��������������������������
��(09)��e���ض������ĸ��� ��
��������������������������*/

TElemType_Sq Value_Sq(SqBiTree T, Position s);
/*������������������������������
��(10)��������ĳλ�õĽ��ֵ����
������������������������������*/

Status Assign_Sq(SqBiTree T, Position s, TElemType_Sq value);
/*������������������������������
��(11)Ϊ����ĳλ�õĽ�㸳ֵ����
������������������������������*/

TElemType_Sq Parent_Sq(SqBiTree T, TElemType_Sq e);
/*������������������������������
��(12)����ĳ����˫�׽��ֵ����
������������������������������*/

TElemType_Sq LeftChild_Sq(SqBiTree T, TElemType_Sq e);
/*��������������������������������
��(13)����ĳ�������ӽ��ֵ����
��������������������������������*/

TElemType_Sq RightChild_Sq(SqBiTree T, TElemType_Sq e);
/*��������������������������������
��(14)����ĳ�����Һ��ӽ��ֵ����
��������������������������������*/

TElemType_Sq LeftSibling_Sq(SqBiTree T, TElemType_Sq e);
/*��������������������������������
��(15)����ĳ�������ֵܽ��ֵ����
��������������������������������*/

TElemType_Sq RightSibling_Sq(SqBiTree T, TElemType_Sq e);
/*��������������������������������
��(16)����ĳ�������ֵܽ��ֵ����
��������������������������������*/

void LevelOrderTraverse_Sq(SqBiTree T, void(Visit)(TElemType_Sq));
/*����������������������
��(17)�����������������
����������������������*/

void PreOrderTraverse_Sq(SqBiTree T, void(Visit)(TElemType_Sq), int i);
/*����������������������
��(18)ǰ���������������
����������������������*/

void InOrderTraverse_Sq(SqBiTree T, void(Visit)(TElemType_Sq), int i);
/*����������������������
��(19)�����������������
����������������������*/

void PostOrderTraverse_Sq(SqBiTree T, void(Visit)(TElemType_Sq), int i);
/*����������������������
��(20)�����������������
����������������������*/

void Print_Sq(SqBiTree T);
/*����������������������������
��(21)���������Ľṹ��ӡ������
����������������������������*/

#endif

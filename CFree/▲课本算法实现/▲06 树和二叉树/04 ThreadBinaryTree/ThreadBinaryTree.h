/***********************************************
 *							                   *
 * �ļ���: ��06 ���Ͷ�����\04 ThreadBinaryTree *
 *							                   *
 * �ļ���: ThreadBinaryTree.h                  *
 *							                   *
 * ��  ��: ������������ز����б�              *
 *                                             *
 ***********************************************/

#ifndef THREADBINARYTREE_H
#define THREADBINARYTREE_H

#include <stdio.h>
#include <stdlib.h>								//�ṩmalloc��realloc��free��exitԭ��
#include "../../��01 ����/Status.h"				//**��01 ����**// 
#include "../../��01 ����/Scanf.c"				//**��01 ����**//

/* �������������Ͷ��� */
typedef char TElemType_Thr;						//���������Ԫ�ؾ�Ϊ�ַ�
typedef enum {Link, Thread} PointerTag;			//Link==0�����ӣ�Thread==1������ 
typedef struct ThrBiNode
{
	TElemType_Thr data;
	struct ThrBiNode *lchild;					//���Һ���ָ�� 
	struct ThrBiNode *rchild; 			
	PointerTag LTag;							//���ұ�־
	PointerTag RTag;
	
	struct ThrBiNode *parent;					//˫�׽��ָ�룬���ڷǵݹ��������������������ʱʹ��
}ThrBiNode;
typedef ThrBiNode* ThrBiTree;

/*ȫ�ֱ���*/
ThrBiTree pre;									//ָ��ǰ���ʽ�����һ����� 

/* ���������������б� */
Status CreateBiTree_Thr(FILE *fp, ThrBiTree *T);
/*������������������������������������������������������
��(01)���������й�������������������ӱ�־(��������)����
������������������������������������������������������*/

void InTheading_Thr(ThrBiTree p);
/*������������������������������
��(02)�㷨6.7������ȫ�������� ��
������������������������������*/

Status InOrderThreading_Thr(ThrBiTree *Thrt, ThrBiTree T);
/*������������������������������������������������
��(03)�㷨6.6���������������T��������ȫ����������
������������������������������������������������*/

Status InOrderTraverse_Thr(ThrBiTree Thrt, void(Visit)(TElemType_Thr));
/*��������������������������������������������������������
��(04)�㷨6.5�������������ȫ�������������ǵݹ��㷨���� ��
��������������������������������������������������������*/

void PreTheading_Thr(ThrBiTree p);
/*����������������������
��(05)����������������
����������������������*/

Status PreOrderThreading_Thr(ThrBiTree *Thrt, ThrBiTree T);
/*������������������������������������������
��(06)�������������T������������������ ��
������������������������������������������*/

Status PreOrderTraverse_Thr(ThrBiTree Thrt, void(Visit)(TElemType_Thr));
/*������������������������������������������������
��(07)�������ǰ�����������������ǵݹ��㷨������
������������������������������������������������*/

void PosTheading_Thr(ThrBiTree p);
/*����������������������
��(08)����������������
����������������������*/

Status PosOrderThreading_Thr(ThrBiTree *Thrt, ThrBiTree T);
/*������������������������������������������
��(09)�������������T������������������ ��
������������������������������������������*/

Status PosOrderTraverse_Thr(ThrBiTree Thrt, void(Visit)(TElemType_Thr));
/*������������������������������������������������
��(10)��������������������������ǵݹ��㷨������
������������������������������������������������*/

void ParentPtr_Thr(ThrBiTree Thrt);
/*����������������������������������������������
��(11)�����������������������˫�׽��ָ�롣��
����������������������������������������������*/

ThrBiTree Pos_NextPtr_Thr(ThrBiTree Thrt, ThrBiTree p);
/*��������������������������������������������������������
��(12)�ں����������������������ʱ��Ѱ�ҽ��p�ĺ�̡� ��
��������������������������������������������������������*/

#endif 

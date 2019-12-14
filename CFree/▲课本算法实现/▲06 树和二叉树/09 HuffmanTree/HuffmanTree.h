/******************************************
 *								          *
 * �ļ���: ��06 ���Ͷ�����\09 HuffmanTree *
 * 								          *
 * �ļ���: HuffmanTree.h                  *
 * 								          *
 * ��  ��: ����������ز����б�           *
 *                                        *
 ******************************************/

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <stdio.h>
#include <stdlib.h>						//�ṩmalloc��realloc��free��exitԭ��
#include <string.h>						//�ṩstrcpyԭ�� 
#include "../../��01 ����/Status.h"		//**��01 ����**//
#include "../../��01 ����/Scanf.c"		//**��01 ����**//

/* �궨�� */
#define MAX_TREE_SIZE 100			//�����������

/* ���������͹������������Ͷ��� */
typedef struct
{
	unsigned int weight;			//Ȩֵ 
	unsigned int parent;						
	unsigned int lchild;
	unsigned int rchild;
}HTNode;
typedef HTNode* HuffmanTree;		//��̬��������洢�������� 
typedef char* HCNode;
typedef HCNode* HuffmanCode;		//��̬��������洢����������� 

/* �������������б� */
void InitTree_HT(HuffmanTree *HT);
/*����������������������������
��(01)�������HT(��ʼ����)����
����������������������������*/

Status CreateHuffmanTree_HT(FILE *fp, HuffmanTree *HT);
/*��������������������
��(02)����������������
��������������������*/

Status Select_HT(HuffmanTree HT, int end, int *order_1, int *order_2);
/*��������������������������������������������������������������������������������������������
��(03)�ڹ����������[1...end]������ѡ��Ȩֵ��С��δ�������������������order_1��order_2�� ��
��������������������������������������������������������������������������������������������*/

Status HuffmanCodeing_HT_1(HuffmanTree HT, HuffmanCode *HC); 
/*����������������������������������������
��(04-1)�㷨6.12������������������ֵ����
����������������������������������������*/

Status HuffmanCodeing_HT_2(HuffmanTree HT, HuffmanCode *HC);
/*��������������������������������������������
��(04-2)�㷨6.13����������������������ֵ����
��������������������������������������������*/

void ShowHuffmanTree_HT(HuffmanTree HT);
/*��������������������
��(05)չʾ������������
��������������������*/

void ShowHuffmanCode_HT(HuffmanTree HT, HuffmanCode HC);
/*����������������������
��(06)��ӡ���������롣��
����������������������*/

#endif

/*************************************
 *                                   *
 * �ļ���: ��09 ����                 *
 *                                   *
 * �ļ���: NearlyOptimalSearchTree.h *
 *                                   *
 * ��  ��: ���Ų�������ز����б�    *
 *                                   *
 *************************************/

#ifndef NEARLYOPTIMALSEARCHTREE_H
#define NEARLYOPTIMALSEARCHTREE_H

#include <stdlib.h>
#include <math.h>
#include "../00 Base/Base.c" 				//**��09 ����**//
#include "../../��06 ���Ͷ�����/02 BinaryTree/BinaryTree.c"//**��06 ���Ͷ�����**//

/* ���Ͷ��� */
typedef BiTree SOSTree;

/*ȫ�ֱ���*/
char ch[] = "\0ABCDEFGHI";
 
/* ��̬������Һ����б� */
void FindSW(float sw[], Table T); 
/*����������������������
��(01)�����ۼ�Ȩֵ����
����������������������*/

int MinSW(float sw[], int low, int high);
/*��������������������������������������
��(02)�ҳ������ۼ�Ȩֵ����С�ķֽ�㡣��
��������������������������������������*/

void SecondOptimal(BiTree *BT, ElemType_Search R[], float sw[], int low, int high);
/*������������������������������������
��(03)�㷨9.3�����Ų��������캯���� ��
������������������������������������*/

Status CreateSOSTree(SOSTree *BT, Table T);
/*����������������������������������������
��(04)�㷨9.4���������T������Ų���������
����������������������������������������*/

Status Search_SOST(SOSTree BT, KeyType key);
/*����������������������������������������
��(5)�жϹؼ���key�Ƿ��ڴ��Ų�����BT�С���
����������������������������������������*/

#endif 

/*************************************
 *						             *
 * �ļ���: ��02 ���Ա�\11 Polynomial *
 * 							         *
 * �ļ���: Polynomial.h              *
 * 							         *
 * ��  ��: һԪ����ʽ��ز����б�    *
 *                                   *
 *************************************/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <stdio.h>
#include <stdlib.h>						//�ṩmalloc��realloc��free��exitԭ��

/* ����ʽ���Ͷ��� */
typedef struct							//������ʾ����ʽ���� 
{
	float	coef;						//ϵ�� 
	int		expn;						//ָ�� 
}LElemType_E;							//���¶�����չ�����Ա���Ԫ������ 
#include "../09 ExtenLinkedList/ExtenLinkedList.c"//**��02 ���Ա�**//
typedef LElemType_E  ElemType_P;		//һԪ����ʽ������� 
typedef ELinkList  Polynomial;			//һԪ����ʽ		

/* һԪ����ʽ�����б� */
void CreatPolyn_P(FILE *fp, Polynomial *P, int m); 
/*������������������������������������������
��(01)�㷨2.22����������Ϊm��һԪ����ʽ�� ��
������������������������������������������*/

void DestroyPolyn_P(Polynomial *P);
/*����������������������
��(02)����һԪ����ʽ����
����������������������*/

int PolynLength_P(Polynomial P);
/*����������������������������
��(03)����һԪ����ʽ����������
����������������������������*/

void AddPolyn_P(Polynomial *Pa, Polynomial *Pb);
/*������������������������������������������������
��(04)�㷨2.23��һԪ����ʽ�ӷ�Pa=Pa+Pb������Pb����
������������������������������������������������*/

void SubtractPolyn_P(Polynomial *Pa, Polynomial *Pb);
/*��������������������������������������
��(05)һԪ����ʽ����Pa=Pa-Pb������Pb����
��������������������������������������*/

void MultiplyPolyn_P(Polynomial *Pa, Polynomial *Pb);
/*��������������������������������������
��(06)һԪ����ʽ�˷�Pa=Pa*Pb������Pb����
��������������������������������������*/

int Cmp_exp(ElemType_P c1, ElemType_P c2);
/*������������������������������
��(07)�Ƚ�c1���c2��ָ����С����
������������������������������*/

void PrintPolyn_P(Polynomial P);
/*��������������������������
��(08)��ӡ���һԪ����ʽ����
��������������������������*/

#endif

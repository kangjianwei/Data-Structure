 /*************************************
 *                                    *
 * �ļ���: ��09 ����                  *
 *                                    *
 * �ļ���: Base.h                     *
 *                                    *
 * ��  ��: ���ұ�ṹ�������³������ *
 *                                    *
 **************************************/

#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <stdlib.h>
#include "../../��01 ����/Status.h"				//**��01 ����**//
#include "../../��01 ����/Scanf.c"				//**��01 ����**//

/* ���ұ����Ͷ��� */
typedef int KeyType;			//�ؼ������� 
typedef struct
{
	int key;					//�ؼ�����	
	float weight;				//�����򣨴˴�����ΪȨ�أ� 
}ElemType_Search;				//�����Ԫ������ 

//0�ŵ�Ԫ���� 
typedef struct
{
	ElemType_Search *elem;		//����Ԫ�ش洢�ռ��ַ��0�ŵ�ԪΪ��
	int length;					//���� 
}Table;							//���ұ�

/* �����б� */
Status Create(FILE *fp, Table *T, int n);
/*����������������
��(01)�������ұ�
����������������*/

void Destory(Table *T);
/*����������������
��(02)���ٲ��ұ�
����������������*/

void Traverse(Table T, void(Visit)(ElemType_Search));
/*����������������
��(03)�������ұ�
����������������*/

void PrintKey(ElemType_Search e);
/*������������������������������������������
��(04)������ұ��еĹؼ��֣�ֻ���key�� ��
������������������������������������������*/

#endif 

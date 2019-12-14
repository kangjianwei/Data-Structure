/******************************************
 *                                        *
 * �ļ���: ��10 �ڲ�����                  *
 *                                        *
 * �ļ���: SequenceListType.h             *
 *                                        *
 * ��  ��: ˳���洢�ṹ���������㷨���� *
 *                                        *
 ******************************************/

#ifndef SEQUENCELISTTYPE_H
#define SEQUENCELISTTYPE_H

#include <stdio.h>
#include "../../��01 ����/Status.h"		//**��01 ����**//
#include "../../��01 ����/Scanf.c"		//**��01 ����**//

/* �궨�� */
#ifndef MAXSIZE
#define MAXSIZE 20						//һ������ʾ����С˳������󳤶�
#endif 
#define LT(a,b) ((a)<(b))					
#define LQ(a,b) ((a)<=(b))

/* ���Ͷ��� */
typedef int KeyType;					//����ؼ�������Ϊ��������
typedef struct							//˳���ṹ 
{
	KeyType key;						//�ؼ����� 
	//ʹ�ýṹ�����ʹ������չ 
}RcdType;								//��¼����
typedef struct
{
	RcdType r[MAXSIZE+1];				//r[0]���û������ڱ���Ԫ
	int length;							//˳����� 
}SqList_sort;							//˳������� 

/* ˳���洢�ṹ�����б� */
Status CreateSortList(FILE *fp, SqList_sort *L);
/*������������������������������
��(01)����һ������˳������С���
������������������������������*/

void Traverse(SqList_sort L, void(Visit)(KeyType));
/*������������������
��(02)�������L�� ��
������������������*/

#endif 

/********************************************
 *                                          *
 * �ļ���: ��10 �ڲ�����                    *
 *                                          *
 * �ļ���: StaticLinkedListType.h           *
 *                                          *
 * ��  ��: ��̬����洢�ṹ���������㷨���� *
 *                                          *
 ********************************************/

#ifndef STATICLINKEDLISTTYPE_H
#define STATICLINKEDLISTTYPE_H

#include <stdio.h>
#include <limits.h>
#include "../../��01 ����/Status.h"			//**��01 ����**//
#include "../../��01 ����/Scanf.c"			//**��01 ����**//

/* �궨�� */
#define MAXSIZE 100							//��̬��������  
#define MAXINT INT_MAX
#define LT(a,b) ((a)<(b))					

/* ���Ͷ��� */
typedef int KeyType;						//����ؼ�������Ϊ��������
typedef struct								//��̬����
{
	KeyType key;							//�ؼ�����
	//ʹ�ýṹ�����ʹ������չ
}RcdType;									//��¼����
typedef struct
{
	RcdType rc;								//��¼�� 
	int next;								//ָ���� 
}SLNode;									//�������� 
typedef struct
{
	SLNode r[MAXSIZE];						//0�ŵ�ԪΪ��ͷ��� 
	int length;								//����ǰ���� 
}SLinkList_sort;							//��̬�������� 

/* ��̬����洢�ṹ�����б� */
Status CreateSortList(FILE *fp, SLinkList_sort *L);
/*������������������������������
��(01)����һ������˳������С���
������������������������������*/

void Traverse(SLinkList_sort L, void(Visit)(KeyType));
/*������������������
��(02)�������L�� ��
������������������*/

#endif 

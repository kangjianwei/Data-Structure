/**************************************
 *                                    *
 * �ļ���: ��02 ���Ա�\03 MergeSqList *
 *                                    *
 * �ļ���: MergeSqList.h              *
 *                                    *
 * ��  ��: ˳���鲢��ز����б�     *
 *                                    *
 **************************************/

#ifndef MERGESQLIST_H
#define MERGESQLIST_H

#include <stdlib.h>
#include "../01 SequenceList/SequenceList.c"		//**��02 ���Ա�**//

/* ˳���鲢�����б� */
void MergeSqList_1(SqList La, SqList Lb, SqList *Lc);
/*��������������������������������������������
��(01)�㷨2.2����C=A+B��A,B,C��Ϊ�ǵݼ����� ��
��������������������������������������������*/

void MergeSqList_2(SqList La, SqList Lb, SqList *Lc);
/*��������������������������������������������
��(02)�㷨2.7����C=A+B��A,B,C��Ϊ�ǵݼ����� ��
��������������������������������������������*/

#endif

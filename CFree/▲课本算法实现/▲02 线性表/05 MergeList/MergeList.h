/************************************
 *							        *
 * �ļ���: ��02 ���Ա�\05 MergeList *
 * 							        *
 * �ļ���: MergeList.h              *
 * 							        *
 * ��  ��: ������鲢��ز����б�   *
 *                                  *
 ************************************/

#ifndef MERGELIST_H
#define MERGELIST_H

#include <stdlib.h>										//�ṩmalloc��realloc��free��exitԭ��
#include "../04 SinglyLinkedList/SinglyLinkedList.c"	//**��02 ���Ա�**//

/* ������鲢�����б� */
void MergeList_L(LinkList La, LinkList *Lb, LinkList *Lc);
/*��������������������������������������������������
��(01)�㷨2.12��C=A+B���ұ���Ԫ�����λ�ò��䡣   ��
��    Lc����La��ͷ��㣬Lb�н�������������Lc�С���    
��������������������������������������������������*/

#endif

/*==================
 * �鲢�ǽ���˳���
 *
 * �����㷨: 2.2��2.7
 ===================*/

#ifndef MERGESQLIST_H
#define MERGESQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"        //**��02 ���Ա�**//


/*
 * ���������������� �㷨2.2 ����������������
 *
 * �ǵݼ�����鲢��C=A+B
 *
 * �鲢˳���La��Lb�������µ�˳���Lc��
 * ���У�La��Lb��Lc��Ϊ�ǵݼ����С�
 */
void MergeSqList_1(SqList La, SqList Lb, SqList* Lc);

/*
 * ���������������� �㷨2.7 ����������������
 *
 * �ǵݼ�����鲢��C=A+B
 *
 * �鲢˳���La��Lb�������µ�˳���Lc��
 * ���У�La��Lb��Lc��Ϊ�ǵݼ����С�
 */
void MergeSqList_2(SqList La, SqList Lb, SqList* Lc);

#endif

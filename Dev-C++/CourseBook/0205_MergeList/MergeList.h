/*===============
 * �鲢�ǽ�������
 *
 * �����㷨: 2.12
 ================*/

#ifndef MERGELIST_H
#define MERGELIST_H

#include <stdio.h>
#include <stdlib.h>      //�ṩmalloc��realloc��free��exitԭ��
#include "LinkList.h"    //**��02 ���Ա�**//

/*
 * ���������������� �㷨2.12 ����������������
 *
 * �ǵݼ�����鲢��C=A+B
 *
 * ������A��B�鲢ΪC���ұ���Ԫ�����λ�ò��䡣
 * Lc����La��ͷ��㣬Lb�н�������������Lc�С�
 */
void MergeList(LinkList* La, LinkList* Lb, LinkList* Lc);

#endif

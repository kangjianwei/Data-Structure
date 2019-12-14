/*==============
 * �󲢼�
 *
 * �����㷨: 2.1
 ===============*/

#ifndef UNION_H
#define UNION_H

#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "SqList.h"   //**��02 ���Ա�**//


/*
 * ���������������� �㷨2.1 ����������������
 *
 * A=A��B
 *
 * ����La��Lb�Ĳ��������ء�
 * �������ɵĲ�����ƴ����La�ϣ�����La�����Ϊָ�����͡�
 */
void Union(SqList* La, SqList Lb);

/*
 * �е�
 *
 * �ж���Ԫ���Ƿ���ȡ�
 * �����ȣ��򷵻�TRUE�����򣬷���FALSE��
 */
Status equal(ElemType e1, ElemType e2);

#endif

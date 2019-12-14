/*===================
 * �缯
 *
 * �����㷨: 6.14/6.15
 ====================*/

#ifndef POWERSET_H
#define POWERSET_H

#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "LinkList.h"   //**��02 ���Ա�**//

/*
 * �缯�еļ��϶��壬����ʹ�������Ա�
 * �缯Ԫ������Ҳ�����Ա�Ԫ������һ�¡�
 */
typedef LinkList List;

/*
 * ��������A������Ԫ�����������Ա�Ԫ������һ�¡�
 */
Status CreatePowerSet(List* A, char* path);

/*
 * ���������������� 6.14/6.15 ����������������
 *
 * ��ȡ����A���ݼ�������B�����ݴ�ÿһ��������ݼ��Ӽ���
 */
void GetPowerSet(int i, List A, List B);

/*
 * �����ǰ���ϡ�
 */
void PrintPowerSet(List A);


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// �������ϵ��ڲ�����
static void Create(List* A, FILE* fp);

#endif

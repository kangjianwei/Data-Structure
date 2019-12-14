/*=========================
 * ���Ķѷ���洢��ʾ���Ѵ���
 *
 * �����㷨: 4.4
 ==========================*/

#ifndef HSTRING
#define HSTRING

#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include <string.h>     // �ṩstrlenԭ��
#include "Status.h"     //**��01 ����**//

/*
 * ���ĶѴ洢��ʾ
 *
 * ע����ЧԪ�ش�ch��0�ŵ�Ԫ��ʼ�洢
 */
typedef struct {
    char* ch;           // ���Ƿǿմ����򰴴�������洢��������chΪNULL
    int length;
} HString;


/*
 * ��ʼ��
 *
 * ����һ��ֵΪchars�Ĵ�T��
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status StrAssign(HString* T, const char* chars);

/*
 * �Ƚ�
 *
 * �Ƚϴ�S�ʹ�T�����رȽϽ����
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status StrCompare(HString S, HString T);

/*
 * ����
 *
 * ����S���Ƶ���T��
 */
Status StrCopy(HString* T, HString S);

#endif

/*=============================
 * ���Ķ���˳��洢��ʾ��˳�򴮣�
 *
 * �����㷨: 4.1��4.2��4.3��4.5
 ==============================*/

#ifndef SSTRING_H
#define SSTRING_H

#include <stdio.h>
#include <string.h>     // �ṩstrlenԭ��
#include "Status.h"     //**��01 ����**//

/* �궨�� */
#define MAXSTRLEN 255       // ˳�򴮵���󴮳�

/*
 * ����˳��洢���Ͷ���
 *
 * ע����ЧԪ�ش�SString��1�ŵ�Ԫ��ʼ�洢
 *     SString��0�ŵ�Ԫ�����洢�䳤��
 */
typedef unsigned char SString[MAXSTRLEN + 1];       // 0�ŵ�Ԫ��Ŵ��ĳ���


/*
 * ��ʼ��
 *
 * ����һ��ֵΪchars�Ĵ�T��
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status StrAssign(SString T, const char* chars);

#endif

/*================
 * �ַ�������������
 =================*/

#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include <stdio.h>
#include <stdlib.h>     // �ṩ malloc ԭ��
#include <string.h>     // �ṩ strlen��strncpy ԭ��
#include <ctype.h>      // �ṩ isprint ԭ��
#include "Status.h"     //**��01 ����**//

/*
 * ɾ��
 *
 * ɾ��s[pos, pos+len-1]��pos��1��ʼ������
 */
Status StrDelete(char** S, int pos, int n);

/*
 * ���Ӵ�
 *
 * ��sub����s[pos, pos+len-1]��pos��1��ʼ������
 */
Status SubString(char** sub, char* s, int pos, int len);

/*
 * �п�
 *
 * �жϴ�s���Ƿ������Ч���ݡ�
 */
Status StrEmpty(char* s);

/*
 * ����
 *
 * �����ַ���s�еĿհף����������ɴ�ӡ�ַ�������ո�
 */
Status ClearBlank(char** s);

/*
 * ����
 *
 * ͳ���ַ���s�е�Ԫ�ظ�����
 * ���������֮�����ڣ��������֣��Ὣ�䵱��һ��Ԫ�ء�
 */
int ElemCount(const char* s);

/*
 * ȡֵ
 *
 * ��ȡ�ַ���s�е�pos��Ԫ��(pos��1��ʼ����)������f���ա�
 * ���������֮�����ڣ��������֣��Ὣ�䵱��һ��Ԫ�ء�
 */
Status GetElem(char* s, int pos, float *f);

#endif

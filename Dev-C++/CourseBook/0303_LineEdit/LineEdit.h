/*==============
 * �б༭����
 *
 * �����㷨: 3.2
 ===============*/

#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <stdio.h>
#include "SqStack.h"    //**��03 ջ�Ͷ���**//
#include "LineEdit.h"

// ģ���ļ��е��ı�������ǣ���Ҫ�������еĶ���
#ifdef  EOF
#undef  EOF
#define EOF '\0'
#endif

/*
 * ���������������� �㷨3.2 ����������������
 *
 * �б༭����ģ��༭�ı�ʱ���˸�������еĲ�����
 *
 *��ע��
 * �̲�ʹ�õ��ǿ���̨���룬����Ϊ�˱��ڲ��ԣ�ֱ�Ӹ�Ϊ���βν��ղ���
 */
void LineEdit(const char buffer[]);

// ���Ժ�������ӡԪ��
void Print(SElemType e);

#endif

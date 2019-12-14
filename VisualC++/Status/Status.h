/*
 * ע��
 * �����޶���Ŀ�İ���������ϣ���ȡÿ��ģ�鶼���Ե�������
 * ����Status���ģ��ᱻ��������ģ�����ã����ô����ܶࡣ
 * ���ֱ�ӽ�Statusģ�鸴�Ƶ�����ģ���У���ᵼ��̫���ظ����룬
 * �����������һ��������̬��������ģ�鹲��Ƚϻ���
 */

#ifndef STATUS_H
#define STATUS_H

#include <stdio.h>

/* ״̬�� */
#define TRUE        1   // ��/��
#define FALSE       0   // ��/��
#define OK          1   // ͨ��/�ɹ�
#define ERROR       0   // ����/ʧ��

//ϵͳ�����д�״̬�붨�壬Ҫ��ֹ��ͻ
#ifndef OVERFLOW
#define OVERFLOW    -2  //��ջ����
#endif

//ϵͳ�����д�״̬�붨�壬Ҫ��ֹ��ͻ
#ifndef NULL
#define NULL ((void*)0)
#endif

/* ״̬������ */
typedef int Status;


// ��ȡ����
int ReadData(FILE* fp, char* format, ...);

// ���»س����Լ�������
void PressEnterToContinue();

// ������ͣһ��ʱ�䣬time����������ʱ��
void Wait(long time);

#endif

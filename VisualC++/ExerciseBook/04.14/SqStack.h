/*=========================
 * ջ��˳��洢�ṹ��˳��ջ��
 ==========================*/

#ifndef SQSTACK_H
#define SQSTACK_H

#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//
#include "String.h"    //**��04 ��**//

/* �궨�� */
#define STACK_INIT_SIZE 100     // ˳��ջ�洢�ռ�ĳ�ʼ������
#define STACKINCREMENT  10      // ˳��ջ�洢�ռ�ķ�������

/*
 * ˳��ջԪ�����Ͷ���
 *
 *��ע��
 * �����Ԫ������Ϊ�ַ���
 */
typedef StringType SElemType;

// ˳��ջԪ�ؽṹ
typedef struct {
    SElemType* base;               // ջ��ָ��
    SElemType* top;                // ջ��ָ��
    int stacksize;                 // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
} SqStack;


/*
 * ��ʼ��
 *
 * ����һ����ջ����ʼ���ɹ��򷵻�OK�����򷵻�ERROR��
 */
Status InitStack(SqStack* S);

/*
 * ȡֵ
 *
 * ����ջ��Ԫ�أ�����e���ա�
 */
Status GetTop(SqStack S, SElemType* e);

/*
 * ��ջ
 *
 * ��Ԫ��eѹ�뵽ջ����
 */
Status Push(SqStack* S, SElemType e);

/*
 * ��ջ
 *
 * ��ջ��Ԫ�ص���������e���ա�
 */
Status Pop(SqStack* S, SElemType* e);

#endif

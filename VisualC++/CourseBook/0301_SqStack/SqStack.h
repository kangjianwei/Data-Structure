/*=========================
 * ջ��˳��洢�ṹ��˳��ջ��
 ==========================*/

#ifndef SQSTACK_H
#define SQSTACK_H

#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//

/* �궨�� */
#define STACK_INIT_SIZE 100     // ˳��ջ�洢�ռ�ĳ�ʼ������
#define STACKINCREMENT  10      // ˳��ջ�洢�ռ�ķ�������

/* ˳��ջԪ�����Ͷ��� */
typedef int SElemType;

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
 * ����(�ṹ)
 *
 * �ͷ�˳��ջ��ռ�ڴ档
 */
Status DestroyStack(SqStack* S);

/*
 * �ÿ�(����)
 *
 * ֻ������˳��ջ�д洢�����ݣ����ͷ�˳��ջ��ռ�ڴ档
 */
Status ClearStack(SqStack* S);

/*
 * �п�
 *
 * �ж�˳��ջ���Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ˳��ջΪ��
 * FALSE: ˳��ջ��Ϊ��
 */
Status StackEmpty(SqStack S);

/*
 * ����
 *
 * ����˳��ջ��������ЧԪ�ص�������
 */
int StackLength(SqStack S);

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

/*
 * ����
 *
 * ��visit��������˳��ջS
 */
Status StackTraverse(SqStack S, void(Visit)(SElemType));

#endif

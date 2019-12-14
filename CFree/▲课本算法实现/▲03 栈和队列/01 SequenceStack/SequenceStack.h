/******************************************
 *						      			  *
 * �ļ���: ��03 ջ�Ͷ���\01 SequenceStack *
 * 							    		  *
 * �ļ���: SequenceStack.h    			  *
 * 							  			  *
 * ��  ��: ˳��ջ��ز����б� 			  *
 *                            			  *
 ******************************************/

#ifndef SEQUENCESTACK_H
#define SEQUENCESTACK_H

#include <stdio.h>
#include <stdlib.h>						//�ṩmalloc��realloc��free��exitԭ��
#include "../../��01 ����/Status.h"		//**��01 ����**//

/* �궨�� */
#define STACK_INIT_SIZE	100				//˳��ջ�洢�ռ�ĳ�ʼ������
#define STACKINCREMENT	10 				//˳��ջ�洢�ռ�ķ�������

/* ˳��ջ���Ͷ��� */
/*���Թ������ʽ���������������������ֵ������㷨�У���������Ҫ���¶���*/
#if !defined MAZE_H				&&  \
    !defined EXPRESSION_H		&&  \
    !defined BINARYTREE_H		&&  \
    !defined CHILDSIBLINGTREE_H	&&  \
    !defined Question_8
typedef int SElemType_Sq;
#endif
typedef struct
{
	SElemType_Sq *base;				//��ջ����֮ǰ������֮��base��ֵΪNULL 
	SElemType_Sq *top;				//ջ��ָ�� 
	int stacksize;					//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ 
}SqStack;

/* ˳��ջ�����б� */
Status InitStack_Sq(SqStack *S);
/*������������������
��(01)�����ջS�� ��
������������������*/

Status DestroyStack_Sq(SqStack *S);
/*��������������
��(02)����S�� ��
��������������*/ 
 
Status ClearStack_Sq(SqStack *S);
/*��������������
��(03)�ÿ�S�� ��
��������������*/

Status StackEmpty_Sq(SqStack S);
/*����������������������
��(04)�ж�S�Ƿ�Ϊ�ա� ��
����������������������*/

int StackLength_Sq(SqStack S);
/*����������������������
��(05)����SԪ�ظ����� ��
����������������������*/
 
Status GetTop_Sq(SqStack S, SElemType_Sq *e);
/*������������������������
��(06)��e��ȡջ��Ԫ�ء� ��
������������������������*/

Status Push_Sq(SqStack *S, SElemType_Sq e);
/*������������������
��(07)Ԫ��e��ջ�� ��
������������������*/

Status Pop_Sq(SqStack *S, SElemType_Sq *e);
/*������������������
��(08)Ԫ��e��ջ�� ��
������������������*/

Status StackTraverse_Sq(SqStack S, void(Visit)(SElemType_Sq));
/*��������������
��(09)����ջ����
��������������*/

#endif

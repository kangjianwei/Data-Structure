#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	                     	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��02 ���Ա�/01 SequenceList/SequenceList.c"	//**��02 ���Ա�**//
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c"	//**��04 ��**//

/* �궨�� */
#define STACK_INIT_SIZE	100				//˳��ջ�洢�ռ�ĳ�ʼ������
#define STACKINCREMENT	10 				//˳��ջ�洢�ռ�ķ�������	

/* ���Ͷ��� */
typedef SString SElemType;				//ջԪ������Ϊ�ַ�������
typedef struct							//ջ�ṹ����
{
	SElemType	*base;					//��ջ����֮ǰ������֮��base��ֵΪNULL 
	SElemType	*top;					//ջ��ָ�� 
	int			stacksize;				//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ 
}SqStack;

/* ����ԭ�� */
Status InitStack_4_14(SqStack *S);					//�ַ���ջ�ĳ�ʼ��
Status Push_4_14(SqStack *S, SElemType e); 			//��ջ
Status Pop_4_14(SqStack *S, SElemType *e);			//��ջ 
Status Algo_4_14(SqList P, SString Str);

int main(int argc, char *argv[])
{
	char *p = "-+a*bc/de";			//��׺��abc*+de/-
	int i;
	SqList P;
	SString Str;
	
	InitList_Sq(&P);
	for(i=1; i<=strlen(p); i++)
		ListInsert_Sq(&P, i, p[i-1]);
	printf("ǰ׺���ʽ��P   = ");
	for(i=0; i<P.length; i++)
		printf("%c", P.elem[i]);
	printf("\n\n");
	
	Algo_4_14(P, Str);	
	printf("��׺���ʽ��Str = ");	
	StrPrint_Sq(Str);
	printf("\n\n");	
	
	return 0;
}

/*������������������������
����4.14��ǰ׺ʽ���׺ʽ��
������������������������*/
/* ������ʽ������Ϊ���ַ� */
Status Algo_4_14(SqList P, SString Str)
{
	int i;
	SElemType e1, e2, tmp;
	SqStack S;
	
	InitStack_4_14(&S);
	
	for(i=P.length-1; i>=0; i--)		//�Ӻ���ǰ��ȡ 
	{
		tmp[0] = 1;
		tmp[1] = P.elem[i];
		
		if(isalpha(P.elem[i]))			//����������ջ 
			Push_4_14(&S, tmp);
		else
		{
			Pop_4_14(&S, &e1);			//����������������ջ 
			Pop_4_14(&S, &e2);

			Concat_Sq(e1, e1, e2);		//����ջ�������������������ȷ����	
			Concat_Sq(e1, e1, tmp);

			Push_4_14(&S, e1);			//���Ӻõ��ַ�����ջ 
		}	
	}
	
	Pop_4_14(&S, &tmp);					//����ת����ɺ���ַ��� 
	StrCopy_Sq(Str, tmp);	
	
	if(S.base==S.top)					//���ջӦ��Ϊ�� 
		return OK;
	else
		return ERROR;
}

Status InitStack_4_14(SqStack *S)
{
 	(*S).base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!(*S).base)
		exit(OVERFLOW);
		
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	
	return OK;
}

Status Push_4_14(SqStack *S, SElemType e)
{
	int i;
	
	if((*S).top-(*S).base>=(*S).stacksize)		//ջ����׷�Ӵ洢�ռ�
	{
		(*S).base = (SElemType *)realloc((*S).base, ((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!(*S).base)
			exit(OVERFLOW);						//�洢����ʧ��
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	
	for(i=0; i<=e[0]; i++)
		(*(S->top))[i] = e[i];					//��ջ�ȸ�ֵ��ջ��ָ�������� 

	(S->top)++;

	return OK;
} 

Status Pop_4_14(SqStack *S, SElemType *e)
{
	int i;
	
	if((*S).top==(*S).base)
		return ERROR;
	
	(*S).top--;									//��ջջ��ָ���ȵݼ����ٸ�ֵ
	
	for(i=0; i<=(*((*S).top))[0]; i++)
		(*e)[i] = (*((*S).top))[i];
	
	return OK;
}

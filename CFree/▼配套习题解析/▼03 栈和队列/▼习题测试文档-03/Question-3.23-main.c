#include <stdio.h>
#include <stdlib.h>							//�ṩmalloc��realloc��free��exitԭ��
#include <string.h>
#include <ctype.h>												//�ṩisalphaԭ�� 
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  			//**��01 ����**//

/* �궨�� */
#define STACK_INIT_SIZE	100				//˳��ջ�洢�ռ�ĳ�ʼ������
#define STACKINCREMENT	10 				//˳��ջ�洢�ռ�ķ�������

/* ���Ͷ��� */
typedef char* SElemType_Sq;
typedef struct
{
	SElemType_Sq	*base;				//��ջ����֮ǰ������֮��base��ֵΪNULL 
	SElemType_Sq	*top;				//ջ��ָ�� 
	int			stacksize;				//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ 
}SqStack;

/* ����ԭ�� */
char* Algo_3_23(char *c);
Status InitStack(SqStack *S);			//��ʼ��ջ
Status StackEmpty(SqStack S);			//�ж�ջ�Ƿ�Ϊ�� 
Status Push(SqStack *S, SElemType_Sq e);//��ջ
Status Pop(SqStack *S, SElemType_Sq *e);//��ջ 
char* CharToStr(char c);				//�ַ�ת��Ϊ�ַ��� 
char* StrCohere(char *a, char* b);		//ƴ���ַ���a��b

int main(int argc, char *argv[])
{
	char *s = "abc*+de/-";
	
	printf("��׺���ʽΪ��");
	printf("%s\n", s);
	printf("ǰ׺���ʽΪ��");
	printf("%s\n", Algo_3_23(s));
	printf("\n");
	
	return 0;
}

/*������������������������
����3.23����׺ʽ��ǰ׺ʽ��
������������������������*/
char* Algo_3_23(char *c)
{
	int len, i, j;
	char *s, *e1, *e2;
	SqStack S;
	
	InitStack(&S);
	
	for(i=0; c[i]; i++)
	{
		s = CharToStr(c[i]);
		
		if(!isalpha(c[i]))		//��c[i]Ϊ����������ջ���������������ַ���			
		{
			if(Pop(&S, &e2) && Pop(&S, &e1)) 	
				s = StrCohere(s, StrCohere(e1, e2));
			else
				return NULL;
		}
		
		Push(&S, s);
	}
	
	Pop(&S, &s);
	
	if(StackEmpty(S))	
		return s;
	else
		return NULL;
}

Status InitStack(SqStack *S)
{
 	(*S).base = (SElemType_Sq *)malloc(STACK_INIT_SIZE*sizeof(SElemType_Sq));
	if(!(*S).base)
		exit(OVERFLOW);
		
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	
	return OK;
}

Status StackEmpty(SqStack S)
{
	if(S.top==S.base)
		return TRUE;
	else
		return FALSE;
}

Status Push(SqStack *S, SElemType_Sq e)
{
	if((*S).top-(*S).base>=(*S).stacksize)		//ջ����׷�Ӵ洢�ռ�
	{
		(*S).base = (SElemType_Sq *)realloc((*S).base, ((*S).stacksize+STACKINCREMENT)*sizeof(SElemType_Sq));
		if(!(*S).base)
			exit(OVERFLOW);						//�洢����ʧ��
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	
	*(S->top) = e;								//��ջ�ȸ�ֵ��ջ��ָ�������� 
	(S->top)++;

	return OK;
} 

Status Pop(SqStack *S, SElemType_Sq *e)
{
	if((*S).top==(*S).base)
		return ERROR;

	(*S).top--;									//��ջջ��ָ���ȵݼ����ٸ�ֵ 
	*e = *((*S).top);

	return OK;
}

char* CharToStr(char c)							//�ַ�ת��Ϊ�ַ��� 
{
	char *s;
	
	s = (char*)malloc(2*sizeof(char));
	if(!s)
		exit(OVERFLOW);
			
	s[0] = c;
	s[1] = '\0';
	
	return s;
}

char* StrCohere(char *a, char* b)				//ƴ���ַ���a��b 
{
	char *s;
	int i, j, alen, blen;
	
	alen = strlen(a);
	blen = strlen(b);
	
	s = (char*)malloc((alen+blen+1)*sizeof(char));
	if(!s)
		exit(OVERFLOW);
	
	j = 0;
	for(i=0; i<alen; i++)
		s[j++] = a[i];
	
	for(i=0; i<blen; i++)
		s[j++] = b[i];
	
	s[j] = '\0';
	
	return s;	
}

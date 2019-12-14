#include <stdio.h>
#include <string.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	                     			//**��01 ����**//
#include "../../../���α��㷨ʵ��/��02 ���Ա�/04 SinglyLinkedList/SinglyLinkedList.c"	//**��02 ���Ա�**//

/* ���Ͷ��� */
typedef LElemType_L strElem;
typedef LNode strNode;
typedef LinkList String;

/* ����ԭ�� */
Status StrAssign_4_21(String *S, char *chars);
Status StrCopy_4_21(String *S, String T);
int StrCompare_4_21(String S, String T);
int StrLength_4_21(String S);
Status Concat_4_21(String *R, String S, String T);
Status SubString_4_21(String *Sub, String S, int pos, int len);
void StrPrint_4_21(String S);

int main(int argc, char *argv[])
{
	char *chars = "@@***#*%%%****(((((*****)))";
	String S, T, R, Sub;
	int i;
	
	StrAssign_4_21(&T, chars);
	printf("T = ");
	StrPrint_4_21(T);
	printf("\n\n");
	
	StrCopy_4_21(&S, T);
	printf("S = ");
	StrPrint_4_21(S);
	printf("\n\n");	
	
	i = StrCompare_4_21(S, T);
	if(i>0)
		printf("S > T\n");
	else if (i<0)
		printf("S < T\n");
	else
		printf("S = T\n");
	printf("\n");
	
	i = StrLength_4_21(S);
	printf("S_len = %d\n", i);
	printf("\n");
	
	Concat_4_21(&R, S, T);
	printf("R = ");
	StrPrint_4_21(R);
	printf("\n\n");	
	
	SubString_4_21(&Sub, S, 11, 4);
	printf("Sub = ");
	StrPrint_4_21(Sub);
	printf("\n\n");	
		
	return 0;
}

/*��������������������
����4.21���ַ�����ֵ��
��������������������*/
/* (1) */
Status StrAssign_4_21(String *S, char *chars)
{
	int i, len;
	String s, p;
	
	len = strlen(chars);
	
	InitList_L(S);
	
	for(i=1,p=*S; i<=len; i++)
	{
		s = (String)malloc(sizeof(strNode));
		if(!s)
			exit(OVERFLOW);
		s->data = chars[i-1];
		
		s->next = p->next;
		p->next = s;
		p = p->next;	
	}
	
	return OK;
}

/*��������������������
����4.21���ַ������Ʃ�
��������������������*/
/* (2) */
Status StrCopy_4_21(String *S, String T)
{
	String r, p, s;
	
	if(!T)
		return ERROR;
	
	InitList_L(S);
	
	for(r=*S,p=T->next; p; p=p->next)
	{
		s = (String)malloc(sizeof(strNode));
		if(!s)
			exit(OVERFLOW);
		s->data = p->data;
		
		s->next = r->next;
		r->next = s;
		r = r->next;
	}
	
	return OK;
}

/*��������������������
����4.21���ַ����Ƚϩ�
��������������������*/
/* (3) */
int StrCompare_4_21(String S, String T)
{
	String p, q;
	
	if(S && T)
	{
		p = S->next;
		q = T->next;
		
		while(p && q)
		{
			if(p->data!=q->data)
				return p->data - q->data;
			
			p = p->next;
			q = q->next;
		}
		
		return ListLength_L(S)-ListLength_L(T);
	}
}

/*��������������������
����4.21���ַ����󳤩�
��������������������*/
/* (4) */
int StrLength_4_21(String S)
{
	return ListLength_L(S);
}

/*��������������������
����4.21���ַ���ƴ�ө�
��������������������*/
/* (5) */
Status Concat_4_21(String *R, String S, String T)
{
	String r, p, s;
	
	if(!S || !T)
		return ERROR;
	
	InitList_L(R);
	
	for(r=*R,p=S->next; p; p=p->next)
	{
		s = (String)malloc(sizeof(strNode));
		if(!s)
			exit(OVERFLOW);
		s->data = p->data;
		
		s->next = r->next;
		r->next = s;
		r = r->next;
	}
	
	for(p=T->next; p; p=p->next)
	{
		s = (String)malloc(sizeof(strNode));
		if(!s)
			exit(OVERFLOW);
		s->data = p->data;
		
		s->next = r->next;
		r->next = s;
		r = r->next;
	}		
	
}

/*��������������������
����4.21���ַ�����ȡ��
��������������������*/
/* (6) */
Status SubString_4_21(String *Sub, String S, int pos, int len)
{
	int i, sl;
	String r, p, s;
	
	sl = StrLength_4_21(S);
	
	if(!S || pos<1 || pos>sl || len<0 || pos+len-1>sl)
		return ERROR;
	
	InitList_L(Sub);
	
	for(i=1,p=S->next; i<pos; i++,p=p->next)
		;				//Ѱ�ҵ�pos�����
	
	for(i=1,r=*Sub; i<=len; i++,p=p->next)
	{
		s = (String)malloc(sizeof(strNode));
		if(!s)
			exit(OVERFLOW);
		s->data = p->data;
		
		s->next = r->next;
		r->next = s;
		r = r->next;		
	}
	
	return OK;
} 

/* �ַ������ */
void StrPrint_4_21(String S)
{
	String p;
	
	for(p=S->next; p; p=p->next)
		printf("%c", p->data);
}

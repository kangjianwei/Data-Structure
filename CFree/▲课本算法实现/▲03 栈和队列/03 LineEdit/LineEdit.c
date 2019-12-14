/*************************************
 *					     			 *
 * �ļ���: ��03 ջ�Ͷ���\03 LineEdit *
 * 					     			 *
 * �ļ���: LineEdit.c    			 *
 * 				         			 *
 * ��  ��: 3.2           			 *
 *                       			 *
 *************************************/

#ifndef LINEEDIT_C
#define LINEEDIT_C

#include "LineEdit.h"				//**��03 ջ�Ͷ���**//

/*�T�T�T�T�[
�U �㷨3.2�U 
�^�T�T�T�T*/
/* ����ε���α������㷨���в�𣬵��㷨˼��һ�� */
void LineEdit(char Buffer[])
{
	SqStack S;						//����������ַ�
	SElemType_Sq e;
	int i;
	char ch;
	
	InitStack_Sq(&S);
	
	i = 0;
	ch = Buffer[i++];
	while(ch!='\0')
	{
		while(ch!='\0' && ch!='\n')
		{
			switch(ch)
			{
				case '#': Pop_Sq(&S, &e);
					break;
				case '@': ClearStack_Sq(&S);
					break;
				default : Push_Sq(&S, ch);
			}
			ch = Buffer[i++];
		}
		
		if(ch=='\n')
		{
			Push_Sq(&S, ch);			
			StackTraverse_Sq(S, Print);
			ClearStack_Sq(&S);
			ch = Buffer[i++];
		}
	}
	
	if(ch=='\0')
	{
		StackTraverse_Sq(S, Print);
		DestroyStack_Sq(&S);
	}
}

void Print(SElemType_Sq e)
{
	printf("%c", e);
}

#endif

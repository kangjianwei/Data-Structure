/*************************************
 *					     			 *
 * 文件夹: ▲03 栈和队列\03 LineEdit *
 * 					     			 *
 * 文件名: LineEdit.c    			 *
 * 				         			 *
 * 算  法: 3.2           			 *
 *                       			 *
 *************************************/

#ifndef LINEEDIT_C
#define LINEEDIT_C

#include "LineEdit.h"				//**▲03 栈和队列**//

/*════╗
║ 算法3.2║ 
╚════*/
/* 与严蔚敏课本所述算法略有差别，但算法思想一致 */
void LineEdit(char Buffer[])
{
	SqStack S;						//接收输入的字符
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

#include <stdio.h>
#include <stdlib.h>											//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  							//**▲01 绪论**//
#include "../../../▲课本算法实现/▲02 线性表/01 SequenceList/SequenceList.c"	//**▲02 线性表**//

/* 函数原型 */
Status Algo_2_11(SqList *va, LElemType_Sq x);
	
void PrintElem(LElemType_Sq e);
	//测试函数，打印整型 

int main(int argc, char *argv[])
{
	SqList L;
	int i;
	
	if(InitList_Sq(&L))					//链表L创建成功
	{
		for(i=1; i<=10; i++)			//链表L中元素1~20 
			ListInsert_Sq(&L, i, 2*i);	
	}
	
	printf("L = ");
	ListTraverse_Sq(L, PrintElem); 			//输出L
	printf("\n\n");	
	
	printf("将元素 \"5\" 插入到链表L中...\n"); 
	Algo_2_11(&L, 5);
	printf("此时L = ");
	ListTraverse_Sq(L, PrintElem); 			//输出L
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━━┓
┃题2.11：将x插入到递增序列va中 ┃
┗━━━━━━━━━━━━━━━*/
Status Algo_2_11(SqList *va, LElemType_Sq x)
{
	int i;
	LElemType_Sq *newbase;
	
	if(!(*va).length)
		return ERROR;
	
	if((*va).length==(*va).listsize)	//若存储空间已满，需开辟新空间 
	{
		newbase = (LElemType_Sq*)realloc((*va).elem, ((*va).listsize+LISTINCREMENT)*sizeof(LElemType_Sq));
		if(!newbase)
			exit(OVERFLOW);

		(*va).elem = newbase;
		(*va).listsize += LISTINCREMENT;
	}
	
	for(i=(*va).length; i>=1; i--)
	{
		if((*va).elem[i-1]>x)
			(*va).elem[i] = (*va).elem[i-1];
		else	
			break;
	}
	
	(*va).elem[i] = x;
	(*va).length++;
	
	return OK;
}

void PrintElem(LElemType_Sq e)
{
	printf("%d ", e);
}

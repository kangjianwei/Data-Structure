#include <stdio.h>	
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  							//**▲01 绪论**//
#include "../../../▲课本算法实现/▲02 线性表/01 SequenceList/SequenceList.c"	//**▲02 线性表**//

/* 函数原型 */
Status Algo_2_10(SqList *a, int i, int k);
	
void PrintElem(LElemType_Sq e);
	//测试函数，打印整型 

int main(int argc, char *argv[])
{
	SqList L;
	int i;
	
	if(InitList_Sq(&L))					//链表L创建成功
	{
		for(i=1; i<=20; i++)			//链表L中元素1~20 
			ListInsert_Sq(&L, i, i);	
	}
	
	printf("L = ");
	ListTraverse_Sq(L, PrintElem); 		//输出L
	printf("\n\n");	
	
	printf("删除第 5 个元素起的 10 个元素...\n"); 
	Algo_2_10(&L, 5, 10);
	printf("此时L = ");
	ListTraverse_Sq(L, PrintElem); 		//输出L
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━┓
┃题2.10：删除顺序表中从第i个元素起的k个元素┃
┗━━━━━━━━━━━━━━━━━━━━━*/
Status Algo_2_10(SqList *a, int i, int k)
{
	int j;
	
	if(i<1 || i>(*a).length || k<0 || i+k-1>(*a).length)
		return ERROR;
	
	for(j=i+k; j<=(*a).length; j++)
		(*a).elem[j-k-1] = (*a).elem[j-1];
	
	(*a).length -= k;
	
	return OK;
}

void PrintElem(LElemType_Sq e)
{
	printf("%d ", e);
}

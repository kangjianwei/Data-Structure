/********************************
 *						        *
 * 文件夹: ▲02 线性表          *
 * 						        *
 * 内  容: 静态链表相关函数测试 *
 *                              *
 ********************************/

#include <stdio.h>
#include "StaticLinkedList.c" 								//**▲02 线性表**//
	
void PrintElem(LElemType_S e);		//测试函数，打印整型
	
int main(int argc, char **argv)
{
	SLinkList H;
	LElemType_S e;
	int i;
	
	printf("▼1\n▲函数InitSpace_SL测试...\n");				//1.函数InitSpace_SL测试
	{
		printf("初始化静态链表的备用空间 SPACE ...\n");					 
		InitSpace_SL();
		printf("\n");	
	} 
	PressEnter;
	
	printf("▼2、4\n▲函数Malloc_SL、InitList_SL测试...\n");//4.函数Malloc_SL、InitList_SL测试
	{
		printf("初始化静态链表 H ，用Malloc_SL申请空间...\n");
		InitList_SL(&H);
		printf("\n");
	} 
	PressEnter;
		
	printf("▼7\n▲函数ListEmpty_SL测试...\n");				//7.函数ListEmpty_SL测试
	ListEmpty_SL(H) ? printf(" H 为空！！\n") : printf(" H 不为空！\n");
	printf("\n");
	PressEnter;
	
	printf("▼13\n▲函数ListInsert_SL测试...\n");			//13.函数ListInsert_SL测试
	{
		for(i=1; i<=6; i++)									
		{
			printf("在 H 第 %d 个位置插入\"%d\" ...\n", i, 2*i);
			ListInsert_SL(H, i, 2*i);
		}
		printf("\n");
	} 
	PressEnter;
	
	printf("▼15\n▲函数ListTraverse_SL测试...\n");			//15.函数ListTraverse_SL测试
	{
		printf(" H 中的元素为：H = ");						 
		ListTraverse_SL(H, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("▼8\n▲函数ListLength_SL测试...\n");			//8.函数ListLength_SL测试
	{
		printf(" H 的长度为 %d \n", ListLength_SL(H));
		printf("\n");
	} 
	PressEnter;
		
	printf("▼3、14\n▲函数Free_SL、ListDelete_SL测试...\n");//3、14.函数Free_SL、ListDelete_SL测试
	{
		ListDelete_SL(H, 6, &e);
		printf("删除 H 中第 6 个元素 \"%d\" ，用Free_SL释放空间...\n", e);	
		printf(" H 的元素为：H = ");						 
		ListTraverse_SL(H, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("▼9\n▲函数GetElem_SL测试...\n");				//9.函数GetElem_SL测试
	{
		GetElem_SL(H, 4, &e);
		printf(" H 中第 4 个位置的元素为 \"%d\" \n", e);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼10\n▲函数LocateElem_SL测试...\n");			//10.函数LocateElem_SL测试
	{
		printf("元素 \"8\" 在 H 中的位序为 %d \n", LocateElem_SL(H, 8)); 
		printf("\n");
	} 
	PressEnter;
	
	printf("▼11\n▲函数PriorElem_SL测试...\n");			//11.函数PriorElem_SL测试
	{
		PriorElem_SL(H, 6, &e);
		printf("元素 \"6\" 的前驱为 \"%d\" \n", e);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼12\n▲函数NextElem_SL测试...\n");				//12.函数NextElem_SL测试
	{
		NextElem_SL(H, 6, &e);
		printf("元素 \"6\" 的后继为 \"%d\" \n", e);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼5\n▲函数ClearList_SL测试...\n");				//5.函数ClearList_SL测试
	{
		printf("清空 H 前：");
		ListEmpty_SL(H) ? printf(" H 为空！！\n") : printf(" H 不为空！\n");
		ClearList_SL(H);
		printf("清空 H 后：");
		ListEmpty_SL(H) ? printf(" H 为空！！\n") : printf(" H 不为空！\n");
		printf("\n");
	} 
	PressEnter;
	
	printf("▼6\n▲函数DestroyList_SL测试...\n");			//6.函数DestroyList_SL测试
	{
		printf("销毁 H 前：");
		H ? printf(" H 存在！\n") : printf(" H 不存在！！\n");
		DestroyList_SL(&H);
		printf("销毁 H 后：");
		H ? printf(" H 存在！\n") : printf(" H 不存在！！\n");
		printf("\n");
	} 
	PressEnter;
	
	return 0;
}

void PrintElem(LElemType_S e)
{
	printf("%d ", e);
}

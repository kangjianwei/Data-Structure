/***********************************
 *						           *
 * 文件夹: ▲10 内部排序           *
 * 						           *
 * 文件名: SequenceListType-main.c *
 * 							       *
 * 内  容: 顺序表相关函数测试      *
 *                                 *
 ***********************************/

#include <stdio.h>
#include "SequenceListType.c" 	//**▲10 内部排序**//

void PrintKey(KeyType e);

int main(int argc, char *argv[])
{		
	SqList_sort L;
	
	printf("▼1、2\n▲函数 CreateSortList等 测试...\n");	//1、2.函数CreateSortList等测试		
	{
		FILE *fp;
		
		printf("创建并输出一个任意序列...\n");
		fp = fopen("TestData.txt", "r");
		CreateSortList(fp, &L);
		Traverse(L, PrintKey);
		printf("\n");
	}	
	PressEnter;
	
	return 0;
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

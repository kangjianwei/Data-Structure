/********************************
 *						        *
 * 文件夹: ▲10 内部排序        *
 * 						        *
 * 文件名: MergingSort-main.c   *
 * 							    *
 * 内  容: 归并排序相关函数测试 *
 *                              *
 ********************************/

#include <stdio.h>
#include "MergingSort.c"	//**▲10 内部排序**//

void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	SqList_sort L;
			
	printf("创建并输出一个任意序列...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData.txt", "r");
		CreateSortList(fp, &L);
		Traverse(L, PrintKey);
		printf("\n");
	}	
	PressEnter;
	
	printf("▼1、2、3\n▲函数 MergingSort等 测试...\n");	//1、2、3.函数MergingSort等测试
	{
		printf("将关键字按递增顺序排列...\n");
		MergeSort(&L); 
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

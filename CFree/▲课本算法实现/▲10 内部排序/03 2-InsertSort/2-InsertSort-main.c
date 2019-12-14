/************************************
 *						            *
 * 文件夹: ▲10 内部排序            *
 * 						            *
 * 文件名: 2-InsertSort-main.c      *
 * 							        *
 * 内  容: 2-路插入排序相关函数测试 *
 *                                  *
 ************************************/

#include <stdio.h>
#include "2-InsertSort.c" 		//**▲10 内部排序**//

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
	
	printf("▼1\n▲函数 TwoTayInsertSort 测试...\n");	//1.函数TwoTayInsertSort测试
	{
		printf("将关键字按递增顺序排列...\n");
		TwoTayInsertSort(&L); 
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

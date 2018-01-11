/******************************
 *						      *
 * 文件夹: ▲10 内部排序      *
 * 						      *
 * 文件名: HeapSort-main.c    *
 * 							  *
 * 内  容: 堆排序相关函数测试 *
 *                            *
 ******************************/

#include <stdio.h>
#include "HeapSort.c" 									//**▲10 内部排序**//

void PrintKey(KeyType e);

int main(int argc, char *argv[])
{		
	HeapType H;
			
	printf("创建并输出一个任意序列...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData.txt", "r");
		CreateSortList(fp, &H);
		Traverse(H, PrintKey);
		printf("\n");
	}	
	PressEnter;
	
	printf("▼1、2\n▲函数 HeapSort等 测试...\n");			//1、2.函数HeapSort等测试
	{
		printf("将关键字按递增顺序排列...\n");
		HeapSort(&H); 
		Traverse(H, PrintKey);
		printf("\n");
	}	
	PressEnter;
		
	return 0;
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

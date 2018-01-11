/********************************
 *						        *
 * 文件夹: ▲10 内部排序        *
 * 						        *
 * 文件名: RadixSort-main.c     *
 * 							    *
 * 内  容: 基数排序相关函数测试 *
 *                              *
 ********************************/

#include <stdio.h>
#include "RadixSort.c" 									//**▲10 内部排序**//

int main(int argc, char *argv[])
{	
	SLList L;
			
	printf("创建并输出一个任意序列...\n");
	printf("▼1、2\n▲函数 CreateSLList等 测试...\n");	//1、2.函数CreateSLList等测试
	{
		FILE *fp;
		fp = fopen("TestData.txt", "r");
		CreateSLList(fp, &L);
		Traverse(L);
		printf("\n");
	}	
	PressEnter; 
	
	printf("▼3、4、5\n▲函数 RadixSort等 测试...\n");	//3、4、5.函数RadixSort等测试
	{
		printf("将各关键字按递增顺序排列...\n");
		RadixSort(&L); 
		Traverse(L);
		printf("\n");
	}	
	PressEnter; 
		
	return 0;
}

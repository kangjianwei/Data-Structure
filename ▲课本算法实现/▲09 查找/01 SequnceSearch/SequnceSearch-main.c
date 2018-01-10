/******************************************
 *						                  *
 * 文件夹: ▲09 查找                      *
 * 						                  *
 * 文件名: SequnceSearch-main.c           *
 * 							              *
 * 内  容: 顺序查找（无序表）相关函数测试 *
 *                                        *
 ******************************************/

#include <stdio.h>
#include "SequnceSearch.c" 						//**▲09 查找**//

#define Max 100									//查找表中元素个数

int main(int argc, char *argv[])
{	
	Table T;
		
	printf("创建并输出一个查找表...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_Table.txt", "r");	
		Create(fp, &T, Max);	
		Traverse(T, PrintKey);	
		printf("\n");
	}	
	PressEnter; 
	
	printf("▼1\n▲函数 Search_Seq 测试...\n");	//1.函数Search_Seq测试		
	{
		printf("关键字 39 在有序查找表中的位序为：");
		printf("%d\n", Search_Seq(T, 39));
		printf("\n");
	}	
	PressEnter; 

	return 0;
}

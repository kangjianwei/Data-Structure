/****************************
 *						    *
 * 文件夹: ▲09 查找        *
 * 						    *
 * 文件名: B+Tree-main.c    *
 * 						    *
 * 内  容: B+树相关函数测试 *
 *                          *
 ****************************/

#include <stdio.h>
#include "B+Tree.c" 						//**▲09 查找**//

/* 宏定义 */ 
#define Max 15								//查找表中元素个数

int main(int argc, char *argv[])
{	
	Table T;
	B_Tree B_T;
	
	printf("创建并输出一个查找表...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_Table.txt", "r");	
		Create(fp, &T, Max);	
		Traverse(T, PrintKey);	
		printf("\n");	
	}
	PressEnter; 

	printf("▼1——8\n▲函数 CreateB_Tree等 测试...\n");		//1——8.函数CreateB_Tree等测试		
	{
		printf("构造B+树...\n");
		CreateB_Tree(&B_T, T);
		printf("\n");
	}	
	PressEnter; 

	printf("▼9\n▲函数 PrintB_Tree 测试...\n");				//9.函数PrintB_Tree测试	 
	{
		printf("输出B+树的关键字...\n");
		PrintB_Tree(B_T); 
		printf("\n");
	}
	PressEnter;
	
	printf("▼\n▲查找测试...\n");								//查找测试	 
	{
		Result r;
		KeyType key = 30;
		
		printf("查找关键字%d...\n", key);
		r = SearchB_Tree(B_T, key);
		if(r.tag==1)
			printf("查找成功，%d 在所属结点的第 %d 个位置。\n", key, Search(r.pt,key));
		else
			printf("查找失败！\n");
		printf("\n");
	}
	PressEnter; 
}

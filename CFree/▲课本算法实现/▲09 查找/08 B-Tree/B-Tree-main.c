/***************************
 *						   *
 * 文件夹: ▲09 查找       *
 * 						   *
 * 文件名: B-Tree-main.c   *
 * 						   *
 * 内  容: B树相关函数测试 *
 *                         *
 ***************************/

#include <stdio.h>
#include "B-Tree.c" 							//**▲09 查找**//

/* 宏定义 */
#define Max 15									//查找表中元素个数

int main(int argc, char *argv[])
{	
	Table T;
	BTree BT;

	printf("创建并输出一个查找表...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_Table.txt", "r");	
		Create(fp, &T, Max);	
		Traverse(T, PrintKey);	
		printf("\n");
	}	
	PressEnter; 
	
	printf("▼1——8\n▲函数 CreateBTree等 测试...\n");		//1——8.函数CreateBTree等测试		
	{
		printf("构造B树...\n");
		CreateBTree(&BT, T);
		printf("\n");
	}	
	PressEnter; 
	
	printf("▼16\n▲函数 PrintBT_InOreder 测试...\n");		//16.函数PrintBT_InOreder测试	 
	{
		printf("★中序输出B树关键字：");
		PrintBT_InOreder(BT); 
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼17\n▲函数 PrintBT_InOreder等 测试...\n");	//17.函数PrintBT_Level测试
	{
		printf("★层序输出B树关键字：\n");
		PrintBT_Level(BT);
		printf("\n");
	}	
	PressEnter; 
	
	printf("▼9——15\n▲函数 DeleteKey等 测试...\n");		//9——15.函数DeleteKey等测试
	{
		int K = 45;
			
		printf("删除关键字 %d ...\n", K);
		DeleteKey(&BT, K);
		printf("★中序输出B树关键字：");
		PrintBT_InOreder(BT); 
		printf("\n");
		printf("★层序输出B树关键字：\n");
		PrintBT_Level(BT);
		printf("\n");
	}	
	PressEnter;
		
	return 0;
}

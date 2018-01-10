/******************************
 *						      *
 * 文件夹: ▲09 查找          *
 * 						      *
 * 文件名: DLTree-main.c      *
 * 						      *
 * 内  容: 双链树相关函数测试 *
 *                            *
 ******************************/

#include <stdio.h>
#include "DLTree.c" 						//**▲09 查找**//

int main(int argc, char *argv[])
{		
	DLTree DLT;

	printf("▼1、3、4\n▲函数 CreateDLTree等 测试...\n");		//1、3、4.函数CreateDLTree等测试		
	{
		FILE *fp;
		
		printf("创建一棵双链树，并输出其中的关键字：\n");
		fp = fopen("TestData_Table.txt", "r");	
		CreateDLTree(fp, &DLT);	
		PrintKeys(DLT);	
		printf("\n\n");
	}	
	PressEnter; 
	
	printf("▼2\n▲函数 SearchDLTree 测试...\n");				//2.函数SearchDLTree测试		
	{
		KeysType K = {"LONG", 4}; 
		
		printf("查找：关键字 %s ", K.ch);
		SearchDLTree(DLT, K) ? printf("在") : printf("不在");
		printf("双链树中！\n");
		printf("\n");
	}	
	PressEnter; 

	return 0;
}

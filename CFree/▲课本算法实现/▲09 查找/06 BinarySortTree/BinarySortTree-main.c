/**********************************
 *						          *
 * 文件夹: ▲09 查找              *
 * 						          *
 * 文件名: BinarySortTree-main.c  *
 * 							      *
 * 内  容: 二叉排序树相关函数测试 *
 *                                *
 **********************************/

#include <stdio.h>
#include "BinarySortTree.c" 								//**▲09 查找**//

#define Max 7												//查找表中元素个数

int main(int argc, char *argv[])
{		
	Table T;
	BSTree BST;
		
	printf("创建并输出一个查找表...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_Table.txt", "r");	
		Create(fp, &T, Max);	
		Traverse(T, PrintKey);	
		printf("\n");
	}	
	PressEnter; 
	
	printf("▼1、3、4、5\n▲函数 CreateBSTree等 测试...\n");	//1、3、4、5.函数CreateBSTree等测试		
	{
		printf("构造二叉排序树，并输出其关键字：");
		CreateBSTree(&BST, T);
		InOrderTraverse_BST(BST, PrintKey);
		printf("\n\n");	
	}
	PressEnter; 
	
	printf("▼2\n▲函数 SearchBST_1 测试...\n");				//2.函数SearchBST_1测试		
	{
		printf("关键字 24 ");
		SearchBST_1(BST, 24)==NULL ? printf("不在") : printf("在");
		printf("二叉排序树中！"); 
		printf("\n\n");	
	}
	PressEnter; 	

	printf("▼6、7\n▲函数 DeleteBST等 测试...\n");			//6、7.函数DeleteBST等测试		
	{
		printf("删除关键字 24 后的关键字序列为：");	
		DeleteBST(&BST, 24);
		InOrderTraverse_BST(BST, PrintKey);	
		printf("\n\n");	
	}
	PressEnter; 

	return 0;
}

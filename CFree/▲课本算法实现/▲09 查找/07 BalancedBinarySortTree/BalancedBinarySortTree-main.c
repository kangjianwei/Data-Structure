/*****************************************
 *						                 *
 * 文件夹: ▲09 查找                     *
 * 						                 *
 * 文件名: BalancedBinarySortTree-main.c *
 * 							             *
 * 内  容: 平衡二叉排序树相关函数测试    *
 *                                       *
 *****************************************/

#include <stdio.h>
#include "BalancedBinarySortTree.c" 		//**▲09 查找**//

/* 宏定义 */
#define Max 7								//查找表中元素个数

int main(int argc, char *argv[])
{
	Table T;
	BBSTree BBST; 
		
	printf("创建并输出一个查找表...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_Table.txt", "r");	
		Create(fp, &T, Max);	
		Traverse(T, PrintKey);	
		printf("\n");
	}	
	PressEnter; 
	
	printf("▼1、3、5、6、7、8、9\n▲函数 CreateAVL等 测试...\n");		//1、3、5、6、7、8、9.函数CreateAVL等测试		
	{
		printf("构造二叉排序树，并输出其关键字：");
		CreateAVL(&BBST, T);
		InOrderTraverse_AVL(BBST, PrintKey);
		printf("\n\n");
	}	
	PressEnter;

	printf("▼10、11\n▲函数 PrintAVLTree等 测试...\n");				//10、11.函数PrintAVLTree等测试		
	{
		printf("打印平衡二叉树：\n");
		PrintAVLTree(BBST);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼2\n▲函数 SearchAVL 测试...\n");							//2.函数SearchAVL测试		
	{
		printf("关键字 %2d ", T.elem[1].key);
		SearchAVL(BBST, T.elem[1].key)==NULL ? printf("不在") : printf("在");
		printf("平衡二叉树中！\n");
		printf("\n");
	}	
	PressEnter;

	printf("▼4\n▲函数 DeleteAVL 测试...\n");							//4.函数DeleteAVL测试		
	{
		BBSTree f, p;
		Boolean taller;
	
		f = NULL;
		p = BBST;
		taller = FALSE;
		DeleteAVL(&BBST, T.elem[1], f, p, &taller, 0);	
		printf("删除关键字 %2d 后的平衡二叉树为：\n", T.elem[1].key);
		PrintAVLTree(BBST);
		printf("\n");
	} 
	PressEnter;
	
	return 0;
}

/******************************
 *						      *
 * 文件夹: ▲11 外部排序      *
 * 						      *
 * 文件名: LoserTree-main.c   *
 * 							  *
 * 内  容: 败者树相关函数测试 *
 *                            *
 ******************************/

#include <stdio.h>
#include "LoserTree.c"		//**▲11 外部排序**//

int main(int argc, char *argv[])
{	
	FILE *fp;
	LoserTree ls;
	External b;
	
	printf("▼6\n▲函数 RandomNum 测试...\n");						//6.函数RandomNum测试		
	{
		printf("创建随机数表作为示例文件...\n");
		fp = fopen("TestData.txt", "w+");							//将随机数写入文件
		RandomNum(fp);
		printf("\n");
	}	
	PressEnter; 
	
	printf("▼7\n▲函数 Cut_Sort 测试...\n");						//7.函数Cut_Sort测试
	{
		printf("分割随机数表，并分别排序后存入[0..k-1].txt...\n");
		fp = fopen("TestData.txt", "r");							//读取随机数文件
		Cut_Sort(fp);												//分割fp为k个文件，并分别排序 
		printf("\n");
	}	
	PressEnter; 	
	
	printf("▼1、2、3、4、5\n▲函数 K_Merge等 测试...\n");			//1、2、3、4、5.函数K_Merge等测试
	{
		printf("将k个归并段[0..k-1].txt排序后写入文件Order.txt");
		fp = fopen("Order.txt", "w+");								//向输出归并段中写入排序后的关键字
		K_Merge(fp, ls, b);
		system("start Order.txt");									//排序后的关键字 
		printf("\n\n");	
	}
	PressEnter;
	
	system("rd/s/q tmpfile");										//删除临时文件夹 
	
	return 0;
}

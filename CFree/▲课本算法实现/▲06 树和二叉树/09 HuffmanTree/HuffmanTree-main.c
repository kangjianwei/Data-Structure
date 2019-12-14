/******************************************
 *								          *
 * 文件夹: ▲06 树和二叉树\09 HuffmanTree *
 * 								          *
 * 文件名: HuffmanTree-main.c             *
 * 							              *
 * 内  容: 哈夫曼树相关函数测试           *
 *                                        *
 ******************************************/

#include <stdio.h>
#include "HuffmanTree.c" 										//**▲06 树和二叉树**//

int main(int argc, char *argv[])
{
	HuffmanTree HT;
	HuffmanCode HC;
	
	printf("▼1\n▲函数 InitTree_HT 测试...\n");				//1.函数InitTree_HT测试
	{
		printf("初始化哈夫曼树 HT ...\n");	
		InitTree_HT(&HT);
		printf("\n");
	}
	PressEnter;

	printf("▼2、3\n▲函数 CreateHuffmanTree_HT等 测试...\n");	//2、3.函数CreateHuffmanTree_HT、Select_HT测试
	{
		FILE *fp;
		
		printf("创建哈夫曼树 HT ...\n");
		printf("作为示范，输入 8 个结点的权值（5, 29, 7, 8, 14, 23, 3, 11）...\n");		
		fp = fopen("TestData_HT.txt", "r");
		CreateHuffmanTree_HT(fp, &HT);
		fclose(fp);
		printf("\n");
	}
	PressEnter;

	printf("▼5\n▲函数 ShowHuffmanTree_HT 测试...\n");			//5.函数ShowHuffmanTree_HT测试
	{
		printf("展示哈夫曼树 HT = \n");
		ShowHuffmanTree_HT(HT);
		printf("\n");
	}
	PressEnter;
/*
	//另一种算法 
	printf("▼4-1\n▲函数 HuffmanCodeing_HT_1 测试...\n");		//4-1.函数HuffmanCodeing_HT_1测试
	{
		printf("计算哈夫曼编码 HC ...\n");		
		HuffmanCodeing_HT_1(HT, &HC);
		printf("\n");
	}
	PressEnter;
*/

	printf("▼4-2\n▲函数 HuffmanCodeing_HT_1 测试...\n");		//4-2.函数HuffmanCodeing_HT_1测试
	printf("计算哈夫曼编码 HC ...\n");		
	HuffmanCodeing_HT_2(HT, &HC);
	printf("\n");
	PressEnter;

		
	printf("▼6\n▲函数 ShowHuffmanCode_HT 测试...\n");			//6.函数ShowHuffmanCode_HT测试
	printf("展示哈夫曼编码 HC = \n");	
	ShowHuffmanCode_HT(HT, HC);
	printf("\n");
	PressEnter;
}

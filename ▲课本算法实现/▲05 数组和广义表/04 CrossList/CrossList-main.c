/********************************************
 * 							                *
 * 文件夹: ▲05 数组和广义表\04 CrossList   *
 * 							                *
 * 内  容: 十字链表（稀疏矩阵）相关函数测试 *
 *                                          *
 ********************************************/

#include <stdio.h>
#include "CrossList.c" 			//**▲05 数组和广义表**//

int main(int argc, char **argv)
{
	CrossList M, N;
	
	printf("▼1\n▲函数 CreateSMatrix_OL 测试...\n");		//1.函数CreateSMatrix_OL测试
	{
		FILE *fp;											//作为输入源
		
		printf("创建两个稀疏矩阵 M、N ...\n");
		fp = fopen("TestData_CrossList.txt", "r");
		CreateSMatrix_OL(fp, 2, &M, &N);
		fclose(fp);
		printf("\n");
	}
	PressEnter;
	
	printf("▼3\n▲函数 PrintSMatrix_OL 测试...\n");		//3.函数PrintSMatrix_OL测试
	{
		printf(" M = \n");
		PrintSMatrix_OL(M);
		printf(" N = \n");
		PrintSMatrix_OL(N);
		printf("\n");
	}
	PressEnter;
	
	printf("▼4\n▲函数 CopySMatrix_OL 测试...\n");			//4.函数CopySMatrix_OL测试
	{
		CrossList Tmp;
		
		CopySMatrix_OL(M, &Tmp);
		printf("Tmp = \n");
		PrintSMatrix_OL(Tmp);
		printf("\n");
	}
	PressEnter;
	
	printf("▼5\n▲函数 AddSMatri_OL 测试...\n");			//5.函数AddSMatri_OL测试
	{
		CrossList Q1;
		
		AddSMatri_OL(M, N, &Q1);
		printf(" Q1 = M + N = \n");
		PrintSMatrix_OL(Q1);
		printf("\n");
	}
	PressEnter;
	
	printf("▼6\n▲函数 SubtSMatrix_OL 测试...\n");			//6.函数SubtSMatrix_OL测试
	{
		CrossList Q2;
		
		SubSMatrix_OL(M, N, &Q2);
		printf(" Q2 = M - N = \n");
		PrintSMatrix_OL(Q2);
		printf("\n");
	}
	PressEnter;

	printf("▼7\n▲函数 MultSMatrix_OL 测试...\n");			//7.函数MultSMatrix_OL测试
	{
		CrossList Q3;
		
		MultSMatrix_OL(M, N, &Q3);
		printf(" Q3 = M * N = \n");
		PrintSMatrix_OL(Q3);
		printf("\n");
	}
	PressEnter;
	
	printf("▼8\n▲函数 TransposeSMatrix_OL 测试...\n");	//8.函数TransposeSMatrix_OL测试
	{
		CrossList T;
		
		TransposeSMatrix_OL(M, &T);
		printf(" T = M(T) = \n");
		PrintSMatrix_OL(T);
		printf("\n");
	}
	PressEnter;
		
	printf("▼2\n▲函数 DestroySMatrix_OL 测试...\n");		//2.函数DestroySMatrix_OL测试
	{
		printf("销毁 M 前：");
		!M.mu && !M.nu && !M.tu ? printf(" M 不存在！！\n") : printf(" M 存在！\n");
		DestroySMatrix_OL(&M);
		printf("销毁 M 后：");
		!M.mu && !M.nu && !M.tu ? printf(" M 不存在！！\n") : printf(" M 存在！\n");
		printf("\n");
	}
	PressEnter;
	
	return 0;
}

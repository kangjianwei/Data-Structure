/******************************************************
 *							                          *
 * 文件夹: ▲05 数组和广义表\03 RowLinkSparseMatrix   *
 *							                          *
 * 内  容: 行逻辑链接的顺序表（稀疏矩阵）相关函数测试 *
 *                                                    *
 ******************************************************/

#include <stdio.h> 
#include "RowLinkSparseMatrix.c" 								//**05 数组和广义表**//

int main(int argc, char **argv)
{
	RLSMatrix M, N;
	 
	printf("▼1\n▲函数 CreateSMatrix_RL 测试...\n");			//1.函数CreateSMatrix_RL测试
	{
		FILE *fp;												//作为输入源
		
		printf("创建两个稀疏矩阵 M、N ...\n");
		fp = fopen("TestData_RLSMatrix.txt", "r");
		CreateSMatrix_RL(fp, 2, &M, &N);
		fclose(fp);
		printf("\n");
	}
	PressEnter;
	
	printf("▼3\n▲函数 PrintSMatrix_RL 测试...\n");			//3.函数PrintSMatrix_RL测试
	{
		printf(" M = \n");
		PrintSMatrix_RL(M);
		printf("\n");
		printf(" N = \n");
		PrintSMatrix_RL(N);
		printf("\n");
	}
	PressEnter;

	printf("▼4\n▲函数 CopySMatrix_RL 测试...\n");				//4.函数CopySMatrix_RL测试
	{
		RLSMatrix Tmp;
		
		printf("复制 M 到 Tmp...\n");
		CopySMatrix_RL(M, &Tmp);
		printf(" Tmp = \n");
		PrintSMatrix_RL(Tmp);
		printf("\n");
	}
	PressEnter;
	
	printf("▼5\n▲函数 AddSMatri_RL 测试...\n");				//5.函数AddSMatri_RL测试
	{
		RLSMatrix Q1;
		
		AddSMatri_RL(M, N, &Q1);
		printf(" Q1 = M + N = \n");
		PrintSMatrix_RL(Q1);
		printf("\n");
	}
	PressEnter;
	
	printf("▼6\n▲函数 SubtSMatrix_RL 测试...\n");				//6.函数SubtSMatrix_RL测试
	{
		RLSMatrix Q2;
		
		SubSMatrix_RL(M, N, &Q2);
		printf(" Q2 = M - N = \n");
		PrintSMatrix_RL(Q2);
		printf("\n");
	}
	PressEnter;	

	printf("▼7\n▲函数 MultSMatrix_RL 测试...\n");				//7.函数MultSMatrix_RL测试
	{
		RLSMatrix Q3;
		
		MultSMatrix_RL(M, N, &Q3);
		printf(" Q3 = M * N = \n");
		PrintSMatrix_RL(Q3);
		printf("\n");
	}
	PressEnter;
	
	printf("▼8\n▲函数 TransposeSMatrix_RL 测试...\n");		//8.函数TransposeSMatrix_RL测试
	{
		RLSMatrix T1;
		
		TransposeSMatrix_RL(M, &T1);
		printf(" T1 = M(T) = \n");
		PrintSMatrix_RL(T1);
		printf("\n");
	}
	PressEnter;
	
	printf("▼9\n▲函数 FastTransposeSMatrix_RL 测试...\n");	//9.函数FastTransposeSMatrix_RL测试
	{
		RLSMatrix T2;
		
		FastTransposeSMatrix_RL(M, &T2);
		printf(" T2 = M(T) = \n");
		PrintSMatrix_RL(T2);
		printf("\n");
	}
	PressEnter;
		
	printf("▼2\n▲函数 DestroySMatrix_RL 测试...\n");			//2.函数DestroySMatrix_RL测试
	{
		printf("销毁 M 前：");
		!M.mu && !M.nu && !M.tu ? printf(" M 不存在！！\n") : printf(" M 存在！\n");
		DestroySMatrix_RL(&M);
		printf("销毁 M 后：");
		!M.mu && !M.nu && !M.tu ? printf(" M 不存在！！\n") : printf(" M 存在！\n");
		printf("\n");
	}
	PressEnter;
		
	return 0;
}

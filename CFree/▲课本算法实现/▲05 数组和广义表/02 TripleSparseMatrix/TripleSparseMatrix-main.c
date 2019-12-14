/***************************************************
 *                                                 *
 * 文件夹: ▲05 数组和广义表\02 TripleSparseMatrix *
 * 						                           *
 * 内  容: 三元组顺序表（稀疏矩阵）相关函数测试    *
 *                                                 *
 ***************************************************/

#include <stdio.h>
#include "TripleSparseMatrix.c" 			//**▲05 数组和广义表**//

int main(int argc, char **argv)
{
	TSMatrix M, N; 
	
	printf("▼1\n▲函数 CreateSMatrix_T 测试...\n");	//1.函数CreateSMatrix_T测试
	{
		FILE *fp;										//作为输入源
		
		printf("创建两个稀疏矩阵 M、N ...\n");
		fp = fopen("TestData_TSMatrix.txt", "r");
		CreateSMatrix_T(fp, 2, &M, &N);
		fclose(fp);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼3\n▲函数 PrintSMatrix_T 测试...\n");		//3.函数PrintSMatrix_T测试
	{
		printf(" M = \n");
		PrintSMatrix_T(M);
		printf(" N = \n");
		PrintSMatrix_T(N);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼4\n▲函数 CopySMatrix_T 测试...\n");		//4.函数CopySMatrix_T测试
	{
		TSMatrix Tmp;
		
		printf("复制 M 到 Tmp...\n");
		CopySMatrix_T(M, &Tmp);
		printf(" Tmp = \n");
		PrintSMatrix_T(Tmp);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼5\n▲函数 AddSMatri_T 测试...\n");		//5.函数AddSMatri_T测试
	{
		TSMatrix Q1;
		
		AddSMatri_T(M, N, &Q1);
		printf(" Q1 = M + N = \n");
		PrintSMatrix_T(Q1);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼6\n▲函数 SubSMatrix_T 测试...\n");		//6.函数SubSMatrix_T测试
	{
		TSMatrix Q2;
		
		SubSMatrix_T(M, N, &Q2);
		printf(" Q2 = M - N = \n");
		PrintSMatrix_T(Q2);
		printf("\n");
	} 
	PressEnter;	

	printf("▼7\n▲函数 MultSMatrix_T 测试...\n");		//7.函数MultSMatrix_T测试
	{
		TSMatrix Q3;
		
		MultSMatrix_T(M, N, &Q3);
		printf(" Q3 = M * N = \n");
		PrintSMatrix_T(Q3);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼8\n▲函数 TransposeSMatrix_T 测试...\n");	//8.函数TransposeSMatrix_T测试
	{
		TSMatrix T1;
		
		TransposeSMatrix_T(M, &T1);
		printf(" T1 = M(T) = \n");
		PrintSMatrix_T(T1);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼9\n▲函数 FastTransposeSMatrix_T 测试...\n");	//9.函数FastTransposeSMatrix_T测试
	{
		TSMatrix T2;
		
		FastTransposeSMatrix_T(M, &T2);
		printf(" T2 = M(T) = \n");
		PrintSMatrix_T(T2);
		printf("\n");
	} 
	PressEnter;
		
	printf("▼2\n▲函数 DestroySMatrix_T 测试...\n");	//2.函数DestroySMatrix_T测试
	{
		printf("销毁 M 前：");
		!M.mu && !M.nu && !M.tu ? printf(" M 不存在！！\n") : printf(" M 存在！\n");
		DestroySMatrix_T(&M);
		printf("销毁 M 后：");
		!M.mu && !M.nu && !M.tu ? printf(" M 不存在！！\n") : printf(" M 存在！\n");
		printf("\n");
	} 
	PressEnter;

	return 0;
}

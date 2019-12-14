/***************************************************
 *                                                 *
 * �ļ���: ��05 ����͹����\02 TripleSparseMatrix *
 * 						                           *
 * ��  ��: ��Ԫ��˳���ϡ�������غ�������    *
 *                                                 *
 ***************************************************/

#include <stdio.h>
#include "TripleSparseMatrix.c" 			//**��05 ����͹����**//

int main(int argc, char **argv)
{
	TSMatrix M, N; 
	
	printf("��1\n������ CreateSMatrix_T ����...\n");	//1.����CreateSMatrix_T����
	{
		FILE *fp;										//��Ϊ����Դ
		
		printf("��������ϡ����� M��N ...\n");
		fp = fopen("TestData_TSMatrix.txt", "r");
		CreateSMatrix_T(fp, 2, &M, &N);
		fclose(fp);
		printf("\n");
	} 
	PressEnter;
	
	printf("��3\n������ PrintSMatrix_T ����...\n");		//3.����PrintSMatrix_T����
	{
		printf(" M = \n");
		PrintSMatrix_T(M);
		printf(" N = \n");
		PrintSMatrix_T(N);
		printf("\n");
	} 
	PressEnter;
	
	printf("��4\n������ CopySMatrix_T ����...\n");		//4.����CopySMatrix_T����
	{
		TSMatrix Tmp;
		
		printf("���� M �� Tmp...\n");
		CopySMatrix_T(M, &Tmp);
		printf(" Tmp = \n");
		PrintSMatrix_T(Tmp);
		printf("\n");
	} 
	PressEnter;
	
	printf("��5\n������ AddSMatri_T ����...\n");		//5.����AddSMatri_T����
	{
		TSMatrix Q1;
		
		AddSMatri_T(M, N, &Q1);
		printf(" Q1 = M + N = \n");
		PrintSMatrix_T(Q1);
		printf("\n");
	} 
	PressEnter;
	
	printf("��6\n������ SubSMatrix_T ����...\n");		//6.����SubSMatrix_T����
	{
		TSMatrix Q2;
		
		SubSMatrix_T(M, N, &Q2);
		printf(" Q2 = M - N = \n");
		PrintSMatrix_T(Q2);
		printf("\n");
	} 
	PressEnter;	

	printf("��7\n������ MultSMatrix_T ����...\n");		//7.����MultSMatrix_T����
	{
		TSMatrix Q3;
		
		MultSMatrix_T(M, N, &Q3);
		printf(" Q3 = M * N = \n");
		PrintSMatrix_T(Q3);
		printf("\n");
	} 
	PressEnter;
	
	printf("��8\n������ TransposeSMatrix_T ����...\n");	//8.����TransposeSMatrix_T����
	{
		TSMatrix T1;
		
		TransposeSMatrix_T(M, &T1);
		printf(" T1 = M(T) = \n");
		PrintSMatrix_T(T1);
		printf("\n");
	} 
	PressEnter;
	
	printf("��9\n������ FastTransposeSMatrix_T ����...\n");	//9.����FastTransposeSMatrix_T����
	{
		TSMatrix T2;
		
		FastTransposeSMatrix_T(M, &T2);
		printf(" T2 = M(T) = \n");
		PrintSMatrix_T(T2);
		printf("\n");
	} 
	PressEnter;
		
	printf("��2\n������ DestroySMatrix_T ����...\n");	//2.����DestroySMatrix_T����
	{
		printf("���� M ǰ��");
		!M.mu && !M.nu && !M.tu ? printf(" M �����ڣ���\n") : printf(" M ���ڣ�\n");
		DestroySMatrix_T(&M);
		printf("���� M ��");
		!M.mu && !M.nu && !M.tu ? printf(" M �����ڣ���\n") : printf(" M ���ڣ�\n");
		printf("\n");
	} 
	PressEnter;

	return 0;
}

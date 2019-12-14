/******************************************************
 *							                          *
 * �ļ���: ��05 ����͹����\03 RowLinkSparseMatrix   *
 *							                          *
 * ��  ��: ���߼����ӵ�˳���ϡ�������غ������� *
 *                                                    *
 ******************************************************/

#include <stdio.h> 
#include "RowLinkSparseMatrix.c" 								//**05 ����͹����**//

int main(int argc, char **argv)
{
	RLSMatrix M, N;
	 
	printf("��1\n������ CreateSMatrix_RL ����...\n");			//1.����CreateSMatrix_RL����
	{
		FILE *fp;												//��Ϊ����Դ
		
		printf("��������ϡ����� M��N ...\n");
		fp = fopen("TestData_RLSMatrix.txt", "r");
		CreateSMatrix_RL(fp, 2, &M, &N);
		fclose(fp);
		printf("\n");
	}
	PressEnter;
	
	printf("��3\n������ PrintSMatrix_RL ����...\n");			//3.����PrintSMatrix_RL����
	{
		printf(" M = \n");
		PrintSMatrix_RL(M);
		printf("\n");
		printf(" N = \n");
		PrintSMatrix_RL(N);
		printf("\n");
	}
	PressEnter;

	printf("��4\n������ CopySMatrix_RL ����...\n");				//4.����CopySMatrix_RL����
	{
		RLSMatrix Tmp;
		
		printf("���� M �� Tmp...\n");
		CopySMatrix_RL(M, &Tmp);
		printf(" Tmp = \n");
		PrintSMatrix_RL(Tmp);
		printf("\n");
	}
	PressEnter;
	
	printf("��5\n������ AddSMatri_RL ����...\n");				//5.����AddSMatri_RL����
	{
		RLSMatrix Q1;
		
		AddSMatri_RL(M, N, &Q1);
		printf(" Q1 = M + N = \n");
		PrintSMatrix_RL(Q1);
		printf("\n");
	}
	PressEnter;
	
	printf("��6\n������ SubtSMatrix_RL ����...\n");				//6.����SubtSMatrix_RL����
	{
		RLSMatrix Q2;
		
		SubSMatrix_RL(M, N, &Q2);
		printf(" Q2 = M - N = \n");
		PrintSMatrix_RL(Q2);
		printf("\n");
	}
	PressEnter;	

	printf("��7\n������ MultSMatrix_RL ����...\n");				//7.����MultSMatrix_RL����
	{
		RLSMatrix Q3;
		
		MultSMatrix_RL(M, N, &Q3);
		printf(" Q3 = M * N = \n");
		PrintSMatrix_RL(Q3);
		printf("\n");
	}
	PressEnter;
	
	printf("��8\n������ TransposeSMatrix_RL ����...\n");		//8.����TransposeSMatrix_RL����
	{
		RLSMatrix T1;
		
		TransposeSMatrix_RL(M, &T1);
		printf(" T1 = M(T) = \n");
		PrintSMatrix_RL(T1);
		printf("\n");
	}
	PressEnter;
	
	printf("��9\n������ FastTransposeSMatrix_RL ����...\n");	//9.����FastTransposeSMatrix_RL����
	{
		RLSMatrix T2;
		
		FastTransposeSMatrix_RL(M, &T2);
		printf(" T2 = M(T) = \n");
		PrintSMatrix_RL(T2);
		printf("\n");
	}
	PressEnter;
		
	printf("��2\n������ DestroySMatrix_RL ����...\n");			//2.����DestroySMatrix_RL����
	{
		printf("���� M ǰ��");
		!M.mu && !M.nu && !M.tu ? printf(" M �����ڣ���\n") : printf(" M ���ڣ�\n");
		DestroySMatrix_RL(&M);
		printf("���� M ��");
		!M.mu && !M.nu && !M.tu ? printf(" M �����ڣ���\n") : printf(" M ���ڣ�\n");
		printf("\n");
	}
	PressEnter;
		
	return 0;
}

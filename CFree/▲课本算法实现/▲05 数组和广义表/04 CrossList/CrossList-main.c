/********************************************
 * 							                *
 * �ļ���: ��05 ����͹����\04 CrossList   *
 * 							                *
 * ��  ��: ʮ������ϡ�������غ������� *
 *                                          *
 ********************************************/

#include <stdio.h>
#include "CrossList.c" 			//**��05 ����͹����**//

int main(int argc, char **argv)
{
	CrossList M, N;
	
	printf("��1\n������ CreateSMatrix_OL ����...\n");		//1.����CreateSMatrix_OL����
	{
		FILE *fp;											//��Ϊ����Դ
		
		printf("��������ϡ����� M��N ...\n");
		fp = fopen("TestData_CrossList.txt", "r");
		CreateSMatrix_OL(fp, 2, &M, &N);
		fclose(fp);
		printf("\n");
	}
	PressEnter;
	
	printf("��3\n������ PrintSMatrix_OL ����...\n");		//3.����PrintSMatrix_OL����
	{
		printf(" M = \n");
		PrintSMatrix_OL(M);
		printf(" N = \n");
		PrintSMatrix_OL(N);
		printf("\n");
	}
	PressEnter;
	
	printf("��4\n������ CopySMatrix_OL ����...\n");			//4.����CopySMatrix_OL����
	{
		CrossList Tmp;
		
		CopySMatrix_OL(M, &Tmp);
		printf("Tmp = \n");
		PrintSMatrix_OL(Tmp);
		printf("\n");
	}
	PressEnter;
	
	printf("��5\n������ AddSMatri_OL ����...\n");			//5.����AddSMatri_OL����
	{
		CrossList Q1;
		
		AddSMatri_OL(M, N, &Q1);
		printf(" Q1 = M + N = \n");
		PrintSMatrix_OL(Q1);
		printf("\n");
	}
	PressEnter;
	
	printf("��6\n������ SubtSMatrix_OL ����...\n");			//6.����SubtSMatrix_OL����
	{
		CrossList Q2;
		
		SubSMatrix_OL(M, N, &Q2);
		printf(" Q2 = M - N = \n");
		PrintSMatrix_OL(Q2);
		printf("\n");
	}
	PressEnter;

	printf("��7\n������ MultSMatrix_OL ����...\n");			//7.����MultSMatrix_OL����
	{
		CrossList Q3;
		
		MultSMatrix_OL(M, N, &Q3);
		printf(" Q3 = M * N = \n");
		PrintSMatrix_OL(Q3);
		printf("\n");
	}
	PressEnter;
	
	printf("��8\n������ TransposeSMatrix_OL ����...\n");	//8.����TransposeSMatrix_OL����
	{
		CrossList T;
		
		TransposeSMatrix_OL(M, &T);
		printf(" T = M(T) = \n");
		PrintSMatrix_OL(T);
		printf("\n");
	}
	PressEnter;
		
	printf("��2\n������ DestroySMatrix_OL ����...\n");		//2.����DestroySMatrix_OL����
	{
		printf("���� M ǰ��");
		!M.mu && !M.nu && !M.tu ? printf(" M �����ڣ���\n") : printf(" M ���ڣ�\n");
		DestroySMatrix_OL(&M);
		printf("���� M ��");
		!M.mu && !M.nu && !M.tu ? printf(" M �����ڣ���\n") : printf(" M ���ڣ�\n");
		printf("\n");
	}
	PressEnter;
	
	return 0;
}

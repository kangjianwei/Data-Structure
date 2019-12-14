#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	                     	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��05 ����͹����/02 TripleSparseMatrix/TripleSparseMatrix.c"  //**��05 ����͹����**//

/* ����ԭ�� */
Status Algo_5_21(TSMatrix A, TSMatrix B, TSMatrix *C);

int main(int argc, char *argv[])
{
	TSMatrix A, B, C;
	FILE *fp;													//��Ϊ����Դ 
		 
	printf("��������ϡ����� A��B...\n");
	fp = fopen("Data/Algo_5_21.txt", "r");
	CreateSMatrix_T(fp, 2, &A, &B);
	fclose(fp);
	printf("A = \n");
	PrintSMatrix_T(A);
	printf("B = \n");
	PrintSMatrix_T(B);
	printf("\n");	

	Algo_5_21(A, B, &C);
	printf("C = A + B = \n");
	PrintSMatrix_T(C);
	printf("\n");	
	
	return 0;
}

/*������������������������
����5.21����Ԫ�����ӷ���
������������������������*/
Status Algo_5_21(TSMatrix A, TSMatrix B, TSMatrix *C)
{
	if(AddSMatri_T(A, B, C))							//�Ѷ��� 
		return OK;
	else
		return ERROR;
}

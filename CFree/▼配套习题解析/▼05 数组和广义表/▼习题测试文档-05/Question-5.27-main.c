#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	                     	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��05 ����͹����/04 CrossList/CrossList.c"   //**��05 ����͹����**//

/* ����ԭ�� */
Status Algo_5_27(CrossList M, CrossList N, CrossList *Q);

int main(int argc, char *argv[])
{
	CrossList M, N, Q;
	FILE *fp;
		
	printf("����ʮ������ M��N...\n");
	fp = fopen("Data/Algo_5_27.txt", "r");
	CreateSMatrix_OL(fp, 2, &M, &N);
	fclose(fp);
	printf("M = \n");
	PrintSMatrix_OL(M);
	printf("N = \n");
	PrintSMatrix_OL(N);
	printf("\n");

	Algo_5_27(M, N, &Q);
	printf("Q = M + N = \n");
	PrintSMatrix_OL(Q);
	printf("\n");
		
	return 0;
}

/*��������������������
����5.27��Q = M + N ��
��������������������*/ 
Status Algo_5_27(CrossList M, CrossList N, CrossList *Q)
{
	if(AddSMatri_OL(M, N, Q))				//�Ѷ��� 
		return OK;
	else
		return ERROR;
}

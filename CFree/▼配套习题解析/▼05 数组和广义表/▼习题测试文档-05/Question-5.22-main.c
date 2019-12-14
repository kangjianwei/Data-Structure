#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	                     	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��05 ����͹����/02 TripleSparseMatrix/TripleSparseMatrix.c"  //**��05 ����͹����**//

/* ����ԭ�� */
Status Algo_5_22(TSMatrix *A, TSMatrix B);

int main(int argc, char *argv[])
{
	TSMatrix A, B, C;
	FILE *fp;													//��Ϊ����Դ
		 
	printf("��������ϡ����� A��B...\n");
	fp = fopen("Data/Algo_5_22.txt", "r");
	CreateSMatrix_T(fp, 2, &A, &B);
	fclose(fp);
	printf("A = \n");
	PrintSMatrix_T(A);
	printf("B = \n");
	PrintSMatrix_T(B);
	printf("\n");	

	Algo_5_22(&A, B);
	printf("A = A + B = \n");
	PrintSMatrix_T(A);
	printf("\n");	
	
	return 0;
}

/*��������������������������������������
����5.22����Ԫ�����ӷ�(�������ռ�)��
��������������������������������������*/
Status Algo_5_22(TSMatrix *A, TSMatrix B)
{
	int m, n, k;
	
	if((*A).mu!=B.mu || (*A).nu!=B.nu)
	{
		printf("����������ӣ���\n");
		return ERROR;	
	}
	
	for(k=(*A).tu; k>0; k--)					//A��Ԫ������ƶ����ƶ�����ΪB��Ԫ�ظ��� 
		(*A).data[k+B.tu] = (*A).data[k];
	
	m = B.tu+1;
	n = 1;
	k = 0;
	while(m<=(*A).tu+B.tu && n<=B.tu)			//���α���A��B����Ԫ�� 
	{
		if((*A).data[m].i<B.data[n].i)
			(*A).data[++k] = (*A).data[m++];
		else if((*A).data[m].i>B.data[n].i)
			(*A).data[++k] = B.data[n++];
		else									//λ��ͬһ�� 
		{
			if((*A).data[m].j<B.data[n].j)
				(*A).data[++k] = (*A).data[m++];
			else if((*A).data[m].j>B.data[n].j)
				(*A).data[++k] = B.data[n++];
			else								//λ��ͬһ���λ�� 
			{
				if((*A).data[m].e+B.data[n].e)
				{
					k++;
					(*A).data[k].i = (*A).data[m].i;
					(*A).data[k].j = (*A).data[m].j;
					(*A).data[k].e = (*A).data[m].e + B.data[n].e;
				}
				m++;
				n++;	
			}
		}	
	}
	
	while(m<=(*A).tu+B.tu)
		(*A).data[++k] = (*A).data[m++];
	
	while(n<=B.tu)
		(*A).data[++k] = B.data[n++];
		
	(*A).tu = k;
	
	return OK;	
}

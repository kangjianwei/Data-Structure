#include <stdio.h>
#include <stdarg.h>										//�ṩ��va_list��va_start��va_arg��va_end
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��01 ����/Scanf.c"  	//**��01 ����**//

/* �궨�� */
#define MAXSIZE 400							//�������Ԫ���������ֵΪ400

/* ���Ͷ��� */
typedef struct
{
	int seq;								//�÷���Ԫ�ھ����е���ţ�������Ϊ���� 
	int e;
}SElem;
typedef struct
{
	SElem data[MAXSIZE+1];					//�洢������Ԫ�أ�data[0]δ��
	int mu, nu, tu;							//����������������ͷ���Ԫ����
}SMatrix;

/* ����ԭ�� */
Status Algo_5_24(SMatrix M, int i, int j, int *e);
Status CreateSMatrix_5_24(FILE *fp, int n, ...);//��������
void PrintSMatrix_5_24(SMatrix M);				//������� 

int main(int argc, char *argv[])
{
	SMatrix M;
	int e;
	FILE *fp;													//��Ϊ����Դ
		
	printf("����ϡ����� M...\n");
	fp = fopen("Data/Algo_5_24.txt", "r");
	CreateSMatrix_5_24(fp, 1, &M);
	fclose(fp);
	printf("M = \n");
	PrintSMatrix_5_24(M);
	printf("\n");
	
	Algo_5_24(M, 2, 3, &e);
	printf("�� %d �� %d �е�Ԫ��Ϊ %d\n", 2, 3, e);
	
	printf("\n");	

	return 0;
}
 
/*������������������������������������
����5.24����ȡ�����е�i�е�j�е�Ԫ�ة�
������������������������������������*/
Status Algo_5_24(SMatrix M, int i, int j, int *e)
{
	int s, p;
	
	if(i<0 || i>M.mu || j<0 || j>M.nu)
		return ERROR;	
	
	for(p=1,s=(i-1)*M.nu+j; M.data[p].seq<s; p++)
		;
		
	*e = 0;
	if(M.data[p].seq==s)
		*e = M.data[p].e;
	
	return OK;
}

Status CreateSMatrix_5_24(FILE *fp, int n, ...)
{
	int count, k, i, j;
	SMatrix *M;
	
	if(n<1)
		return ERROR;
	
	va_list ap;	
	va_start(ap, n);
	
	for(count=1; count<=n; count++)
	{
		M = va_arg(ap, SMatrix *);	
		Scanf(fp, "%d%d%d", &((*M).mu), &((*M).nu), &((*M).tu));

		for(k=1; k<=(*M).tu; k++)
		{
			Scanf(fp, "%d%d%d", &i, &j, &((*M).data[k].e));
			(*M).data[k].seq = (i-1) * (*M).nu + j;	
		}
	}
	
	va_end(ap);
	
	return OK;	
}

void PrintSMatrix_5_24(SMatrix M)
{
	int r, c;
	int k = 1;
	
	for(r=1; r<=M.mu; r++)
	{
		for(c=1; c<=M.nu; c++)
		{
			if(r==(M.data[k].seq-1)/M.nu+1 && c==(M.data[k].seq-1)%M.nu+1)
			{

				printf("%3d ", M.data[k].e);
				k++;
			}
			else
				printf("  0 ");
		}
		printf("\n");
	}	
}

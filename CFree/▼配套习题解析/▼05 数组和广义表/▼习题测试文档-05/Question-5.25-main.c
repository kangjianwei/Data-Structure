#include <stdio.h>
#include <stdarg.h>										//�ṩ��va_list��va_start��va_arg��va_end
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��01 ����/Scanf.c"  	//**��01 ����**//

/* �궨�� */
#define Mu 20								//��������������ֵΪ20 
#define Nu 20								//��������������ֵΪ20
#define MAXSIZE 400							//�������Ԫ���������ֵΪ400

/* ���Ͷ��� */
typedef struct
{
	int mu, nu, tu;							//��������������������Ԫ���� 
	int V[MAXSIZE+1];						//�洢�����Ԫ��
	int B[Mu+1][Nu+1];						//��Ǿ����и�λ��Ԫ���Ƿ�Ϊ����Ԫ 
}Matrix;

/* ����ԭ�� */
Status Algo_5_25(Matrix P, Matrix Q, Matrix *R);
Status CreateMatrix_5_25(FILE *fp, int n, ...);
	//�������� 
void PrintMatrix_5_25(Matrix M);
	//������� 

int main(int argc, char *argv[])
{
	Matrix M, N, Q;
	int i, j;
	FILE *fp;
			
	printf("����ϡ����� M...\n");
	fp = fopen("Data/Algo_5_25.txt", "r");
	CreateMatrix_5_25(fp, 2, &M, &N);
	fclose(fp);
	printf("M = \n");	
	PrintMatrix_5_25(M);
	printf("N = \n");	
	PrintMatrix_5_25(N);
	printf("\n");
	
	Algo_5_25(M, N, &Q);
	printf("Q = M + N = \n");	
	PrintMatrix_5_25(Q);	
	printf("\n");	

	return 0;
}

/*��������������������
����5.25��R = P + Q ��
��������������������*/
Status Algo_5_25(Matrix P, Matrix Q, Matrix *R)		//����0�ŵ�Ԫ 
{
	int i, j;
	int p, q, r;
	
	if(P.mu!=Q.mu || P.nu!=Q.nu)
	{
		printf("����������ӣ�");
		return ERROR;
	}
	
	(*R).mu = P.mu;
	(*R).nu = P.nu;
	(*R).tu = 0;
	
	p = q = r = 1;
	
	for(i=1; i<=P.mu; ++i)
	{
		for(j=1; j<=P.nu; ++j)
		{
			if(P.B[i][j]==0 && Q.B[i][j]==0)		
				(*R).B[i][j] = 0;
			else if(P.B[i][j]==0 && Q.B[i][j]==1)
			{
				(*R).V[r++] = Q.V[q++];
				(*R).B[i][j] = 1;
				(*R).tu++;
			}
			else if(P.B[i][j]==1 && Q.B[i][j]==0)
			{
				(*R).V[r++] = P.V[p++];
				(*R).B[i][j] = 1;
				(*R).tu++;
			}
			else			//P.B[i][j]==1 && Q.B[i][j]==1
			{
				if(P.V[p]+Q.V[q])
				{
					(*R).V[r++] = P.V[p++] + Q.V[q++];
					(*R).B[i][j] = 1;
					(*R).tu++;
				}
				else
				{
					p++;
					q++;
					(*R).B[i][j] = 0;
				}
			}		
		}
	}
	
	return OK;
}

Status CreateMatrix_5_25(FILE *fp, int n, ...)
{
	int count, k, i, j, r, c;
	Matrix *M;
	
	if(n<1)
		return ERROR;
	
	va_list ap;	
	va_start(ap, n);
	
	for(count=1; count<=n; count++)
	{
		M = va_arg(ap, Matrix*);	
		Scanf(fp, "%d%d%d", &((*M).mu), &((*M).nu), &((*M).tu));

		for(k=1,r=c=1; k<=(*M).tu; k++)
		{
			Scanf(fp, "%d%d%d", &i, &j, &((*M).V[k]));

				for( ; r<i; r++)
				{
					for( ; c<=(*M).nu; c++)
						(*M).B[r][c] = 0;
					c = 1;
				}	

			for( ; c<j; c++)
				(*M).B[r][c] = 0;
			
			(*M).B[r][c] = 1;
			if(++c==(*M).nu+1)
			{
				c = 1;
				r++;
			}							
		}
		
		for( ; r<=(*M).mu; r++)
		{
			for( ; c<=(*M).nu; c++)
				(*M).B[r][c] = 0;
			
			c = 1;
		}
	}
	
	va_end(ap);
	
	return OK;	
}

void PrintMatrix_5_25(Matrix M)
{
	int i, j, k;
	
	k = 1;
	
	for(i=1; i<=M.mu; i++)
	{
		for(j=1; j<=M.nu; j++)
		{
			if(M.B[i][j]==1)
				printf("%3d ", M.V[k++]);
			else
				printf("  0 ");
		}
		
		printf("\n");
	}
}

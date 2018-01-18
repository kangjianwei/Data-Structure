#include <stdio.h>
#include <stdarg.h>										//提供宏va_list、va_start、va_arg、va_end
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲01 绪论/Scanf.c"  	//**▲01 绪论**//

/* 宏定义 */
#define Mu 20								//假设矩阵行数最大值为20 
#define Nu 20								//假设矩阵列数最大值为20
#define MAXSIZE 400							//假设非零元个数的最大值为400

/* 类型定义 */
typedef struct
{
	int mu, nu, tu;							//矩阵行数，列数，非零元个数 
	int V[MAXSIZE+1];						//存储矩阵的元素
	int B[Mu+1][Nu+1];						//标记矩阵中各位置元素是否为非零元 
}Matrix;

/* 函数原型 */
Status Algo_5_25(Matrix P, Matrix Q, Matrix *R);
Status CreateMatrix_5_25(FILE *fp, int n, ...);
	//创建矩阵 
void PrintMatrix_5_25(Matrix M);
	//输出矩阵 

int main(int argc, char *argv[])
{
	Matrix M, N, Q;
	int i, j;
	FILE *fp;
			
	printf("创建稀疏矩阵 M...\n");
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

/*━━━━━━━━━┓
┃题5.25：R = P + Q ┃
┗━━━━━━━━━*/
Status Algo_5_25(Matrix P, Matrix Q, Matrix *R)		//舍弃0号单元 
{
	int i, j;
	int p, q, r;
	
	if(P.mu!=Q.mu || P.nu!=Q.nu)
	{
		printf("两矩阵不能相加！");
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

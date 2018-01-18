#include <stdio.h>
#include <stdarg.h>										//提供宏va_list、va_start、va_arg、va_end
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲01 绪论/Scanf.c"  	//**▲01 绪论**//

/* 宏定义 */
#define MAXSIZE 400							//假设非零元个数的最大值为400

/* 类型定义 */
typedef struct
{
	int seq;								//该非零元在矩阵中的序号（以行序为主序） 
	int e;
}SElem;
typedef struct
{
	SElem data[MAXSIZE+1];					//存储各非零元素，data[0]未用
	int mu, nu, tu;							//矩阵的行数、列数和非零元个数
}SMatrix;

/* 函数原型 */
Status Algo_5_24(SMatrix M, int i, int j, int *e);
Status CreateSMatrix_5_24(FILE *fp, int n, ...);//创建矩阵
void PrintSMatrix_5_24(SMatrix M);				//输出矩阵 

int main(int argc, char *argv[])
{
	SMatrix M;
	int e;
	FILE *fp;													//作为输入源
		
	printf("创建稀疏矩阵 M...\n");
	fp = fopen("Data/Algo_5_24.txt", "r");
	CreateSMatrix_5_24(fp, 1, &M);
	fclose(fp);
	printf("M = \n");
	PrintSMatrix_5_24(M);
	printf("\n");
	
	Algo_5_24(M, 2, 3, &e);
	printf("第 %d 行 %d 列的元素为 %d\n", 2, 3, e);
	
	printf("\n");	

	return 0;
}
 
/*━━━━━━━━━━━━━━━━━┓
┃题5.24：获取矩阵中第i行第j列的元素┃
┗━━━━━━━━━━━━━━━━━*/
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

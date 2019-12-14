#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	                     	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲05 数组和广义表/03 RowLinkSparseMatrix/RowLinkSparseMatrix.c"  //**▲05 数组和广义表**//

/* 函数原型 */
Status Algo_5_23(RLSMatrix M, int i, int j, int *e);

int main(int argc, char *argv[])
{
	RLSMatrix M;
	int e;
	FILE *fp;													//作为输入源
		
	printf("创建稀疏矩阵 M...\n");
	fp = fopen("Data/Algo_5_23.txt", "r");
	CreateSMatrix_RL(fp, 1, &M);
	fclose(fp);
	printf("M = \n");
	PrintSMatrix_RL(M);
	printf("\n");
	
	Algo_5_23(M, 2, 3, &e);
	printf("第 %d 行 %d 列的元素为 %d\n", 2, 3, e);
	
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━┓
┃题5.23：获取矩阵中第i行第j列的元素┃
┗━━━━━━━━━━━━━━━━━*/ 
Status Algo_5_23(RLSMatrix M, int i, int j, int *e)
{
	int m, n, k;
	
	if(i<0 || i>M.mu || j<0 || j>M.nu)
		return ERROR;
	
	m = M.rpos[i];
	n = (i==M.mu ? M.tu : M.rpos[i+1]-1);
	*e = 0;
	
	for(k=m; k<=n; k++)
	{
		if(M.data[k].j==j)				//行下标i不存在
			*e = M.data[k].e;			
	}
	
	return OK;
}

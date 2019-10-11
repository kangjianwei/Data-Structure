#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	                     	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲05 数组和广义表/02 TripleSparseMatrix/TripleSparseMatrix.c"  //**▲05 数组和广义表**//

/* 函数原型 */
Status Algo_5_21(TSMatrix A, TSMatrix B, TSMatrix *C);

int main(int argc, char *argv[])
{
	TSMatrix A, B, C;
	FILE *fp;													//作为输入源 
		 
	printf("创建两个稀疏矩阵 A、B...\n");
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

/*━━━━━━━━━━━┓
┃题5.21：三元组矩阵加法┃
┗━━━━━━━━━━━*/
Status Algo_5_21(TSMatrix A, TSMatrix B, TSMatrix *C)
{
	if(AddSMatri_T(A, B, C))							//已定义 
		return OK;
	else
		return ERROR;
}

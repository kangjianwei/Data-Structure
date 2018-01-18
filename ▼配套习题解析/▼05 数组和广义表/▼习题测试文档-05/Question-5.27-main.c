#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	                     	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲05 数组和广义表/04 CrossList/CrossList.c"   //**▲05 数组和广义表**//

/* 函数原型 */
Status Algo_5_27(CrossList M, CrossList N, CrossList *Q);

int main(int argc, char *argv[])
{
	CrossList M, N, Q;
	FILE *fp;
		
	printf("创建十字链表 M、N...\n");
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

/*━━━━━━━━━┓
┃题5.27：Q = M + N ┃
┗━━━━━━━━━*/ 
Status Algo_5_27(CrossList M, CrossList N, CrossList *Q)
{
	if(AddSMatri_OL(M, N, Q))				//已定义 
		return OK;
	else
		return ERROR;
}

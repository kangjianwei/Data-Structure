#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	                     	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲05 数组和广义表/02 TripleSparseMatrix/TripleSparseMatrix.c"  //**▲05 数组和广义表**//

/* 函数原型 */
Status Algo_5_22(TSMatrix *A, TSMatrix B);

int main(int argc, char *argv[])
{
	TSMatrix A, B, C;
	FILE *fp;													//作为输入源
		 
	printf("创建两个稀疏矩阵 A、B...\n");
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

/*━━━━━━━━━━━━━━━━━━┓
┃题5.22：三元组矩阵加法(不设额外空间)┃
┗━━━━━━━━━━━━━━━━━━*/
Status Algo_5_22(TSMatrix *A, TSMatrix B)
{
	int m, n, k;
	
	if((*A).mu!=B.mu || (*A).nu!=B.nu)
	{
		printf("两矩阵不能相加！！\n");
		return ERROR;	
	}
	
	for(k=(*A).tu; k>0; k--)					//A中元素向后移动，移动长度为B的元素个数 
		(*A).data[k+B.tu] = (*A).data[k];
	
	m = B.tu+1;
	n = 1;
	k = 0;
	while(m<=(*A).tu+B.tu && n<=B.tu)			//依次遍历A与B的三元组 
	{
		if((*A).data[m].i<B.data[n].i)
			(*A).data[++k] = (*A).data[m++];
		else if((*A).data[m].i>B.data[n].i)
			(*A).data[++k] = B.data[n++];
		else									//位于同一行 
		{
			if((*A).data[m].j<B.data[n].j)
				(*A).data[++k] = (*A).data[m++];
			else if((*A).data[m].j>B.data[n].j)
				(*A).data[++k] = B.data[n++];
			else								//位于同一相对位置 
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

#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  							//**▲01 绪论**//

/* 函数原型 */
void Algo_5_18(int a[], int n, int k);
Status Reversal_5_18(int a[], int n, int start, int end);

int main(int argc, char *argv[])
{
	int A[10] = {1,2,3,4,5,6,7,8,9,10}; 
	int i;
	int k = 5;										//右移位数 
	
	printf("数组A包含的元素为：\n→");
	for(i=0; i<10; i++) 
		printf("%2d ", A[i]);
	printf("\n");
	
	printf("将元素A[0]至A[9]循环右移 %d 个位置后，数组变为：\n→", k);
	Algo_5_18(A, 10, k);
	for(i=0; i<10; i++) 
		printf("%2d ", A[i]);
	printf("\n\n");	
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━┓
┃题5.18：将数组a[n]中的元素循环右移k个位置 ┃
┗━━━━━━━━━━━━━━━━━━━━━*/
void Algo_5_18(int a[], int n, int k)
{
	int p = k%n;									//实际循环右移的位数
	
	if(p)											//右移位数不为0的情况 
	{
		Reversal_5_18(a, n, 1, n);
		Reversal_5_18(a, n, 1, p);
		Reversal_5_18(a, n, p+1, n);	
	}
}

/* 逆置数组a[n]中第start个与第end个之间的元素*/
Status Reversal_5_18(int a[], int n, int start, int end)
{
	int e, i;									//只用e一个空间临时存储数组的内容 
	
	if(start<1 || end>n || start>end)
		return ERROR;
	
	for(i=0; i<(end-start+1)/2; ++i)			//用"交换法"逆置
	{
		e = a[end-i-1];
		a[end-i-1] = a[start+i-1];
		a[start+i-1] = e;
	}
	
	return OK;
}

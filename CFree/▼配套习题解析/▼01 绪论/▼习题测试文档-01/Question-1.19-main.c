#include <stdio.h>
#include <limits.h>										//提供宏INT_MAX 
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	//**▲01 绪论**//

/* 宏定义 */
#define arrsize 20										//数组长度 
#define maxint INT_MAX									//最大的整数 

/* 函数原型 */
Status Algo_1_19(int i, int a[]);

int main(int argc, char *argv[])
{
	int i, a[arrsize];
	
	i = 5;
	
	printf("计算i!*2^i...\n");
	
	if(Algo_1_19(i, a)==OK)
		printf("作为示例，计算当i = %d 时，a[i-1] = %d\n", i, a[i-1]);
	printf("\n");
	
	return 0;
}
 
/*━━━━━━━━━━━━━━━━━━━┓
┃题1.19：计算i!*2^i存入a[i-1]，i起点为1┃
┗━━━━━━━━━━━━━━━━━━━*/
Status Algo_1_19(int i, int a[])
{
	int j;
	
	if(i<1 || i>arrsize)
		return ERROR;
	
	for(j=1; j<=i; j++)
	{
		if(j==1)
			a[j-1] = 2;
		else
		{
			if(maxint/(2*j)<a[j-2])
				return OVERFLOW;
				
			a[j-1] = 2 * j * a[j-2];		
		}	
	}
	
	return OK;
}

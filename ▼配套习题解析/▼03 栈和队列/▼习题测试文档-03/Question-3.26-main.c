#include <stdio.h>
#include <stdlib.h>							//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  			//**▲01 绪论**//

/* 函数原型 */
float Algo_3_26_1(float A, float p, float e);
float Algo_3_26_2(float A, float p, float e);

int main(int argc, char *argv[])
{
	printf("√10 = %f\n", Algo_3_26_1(10, 1, 0.000001));
	printf("\n");
	printf("√50 = %f\n", Algo_3_26_2(50, 1, 0.000001));
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━┓
┃题3.26：递归计算平方根┃
┗━━━━━━━━━━━*/
/* 方法1：递归法 */ 
float Algo_3_26_1(float A, float p, float e)
{
	if(A<0.0)
		exit(ERROR);
		
	if((p*p-A)>-e && (p*p-A)<e)
		return p;
	else
		return Algo_3_26_1(A, (p+A/p)/2, e);
}

/*━━━━━━━━━━━┓
┃题3.26：迭代计算平方根┃
┗━━━━━━━━━━━*/
/* 方法2：迭代法 */
float Algo_3_26_2(float A, float p, float e)
{
	if(A<0.0)
		exit(ERROR);
		
	while((p*p-A)>=e || (p*p-A)<=-e)
		p = (p + A/p) / 2;
		
	if((p*p-A)>-e && (p*p-A)<e)
		return p;
}

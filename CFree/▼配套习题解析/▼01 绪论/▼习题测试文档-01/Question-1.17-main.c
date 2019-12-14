#include <stdio.h>
#include <stdlib.h>										//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	//**▲01 绪论**//

/* 函数原型 */
int Algo_1_17_1(int k, int m);
int Algo_1_17_2(int k, int m);

int main(int argc, char *argv[])
{
	int k, m;
	
	k = 3;
	m = 10;
	
	printf("作为示范，求得 %d 阶斐波那契数列第 %d 项的值为：%d \n", k, m, Algo_1_17_1(k, m));
	
	printf("作为示范，求得 %d 阶斐波那契数列第 %u 项的值为：%d \n", k, 2*m, Algo_1_17_2(k, 2*m));
	
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━┓
┃题1.17：计算k阶斐波那契数列第m项的值┃
┗━━━━━━━━━━━━━━━━━━*/
/* 方法1：递归算法 */
int Algo_1_17_1(int k, int m)			//当m变大时，计算速度会递减 
{
	int i, value;
	
	if(k<2 || m<0)
		exit(OVERFLOW);
	
	if(m<k-1)
		return 0;
	else if(m==k-1)
		return 1;
	else
	{
		for(i=1,value=0; i<=k; i++)
			value += Algo_1_17_1(k, m-i);
		
		return value;
	}
}

/*━━━━━━━━━━━━━━━━━━┓
┃题1.17：计算k阶斐波那契数列第m项的值┃
┗━━━━━━━━━━━━━━━━━━*/
/* 方法2：递推（迭代）算法 */
int Algo_1_17_2(int k, int m)
{
	int i, j;
	int fib[m+1];
	
	if(k<1 || m<0)
		exit(OVERFLOW);
	
	i = 0;
	while(i<k-1)
	{
		fib[i] = 0;
		i++;		
	}
		
	fib[i] = 1;							//i = k-1
	i++;
			
	while(i<=m)							//i = k
	{	
		for(j=i-1,fib[i]=0; j>=i-k; j--)
			fib[i] += fib[j];
		i++;
	}
	
	return fib[m];	
}

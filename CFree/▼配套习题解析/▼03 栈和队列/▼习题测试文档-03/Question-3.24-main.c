#include <stdio.h>
#include <stdlib.h>							//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  			//**▲01 绪论**//

/* 函数原型 */
int Algo_3_24(int m, int n);

int main(int argc, char *argv[])
{
	int m, n;
	
	m = 5;
	n = 2;
	
	printf("g(%d,%d) = %d\n", m, n, Algo_3_24(m, n));
	printf("\n");

	return 0;
}

/*━━━━━━━━━━━┓
┃题3.24：递归计算g(m,n)┃
┗━━━━━━━━━━━*/
int Algo_3_24(int m, int n)
{
	if(m<0 || n<0)
		exit(ERROR);
		
	if(m==0)
		return 0;
	else
		return Algo_3_24(m-1, 2*n) + n;
}

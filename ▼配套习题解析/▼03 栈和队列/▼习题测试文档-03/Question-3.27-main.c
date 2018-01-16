#include <stdio.h>
#include <stdlib.h>							//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  			//**▲01 绪论**//

/* 类型定义 */
typedef struct
{
	int mval;
	int nval;
}Stack;

/* 函数原型 */
int Algo_3_27_1(int m, int n);
int Algo_3_27_2(int m, int n);

int main(int argc, char *argv[])
{
	printf("akm(2,3) = %d\n", Algo_3_27_1(2, 3));
	printf("\n");
	printf("akm(3,4) = %d\n", Algo_3_27_2(3, 4));
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━┓
┃题3.27：递归计算阿克曼函数┃
┗━━━━━━━━━━━━━*/
/* (1)：递归法 */ 
int Algo_3_27_1(int m, int n)
{
	int akm, tmp;
	
	if(m<0 || n<0)
		exit(ERROR);
	
	if(m==0)
		akm = n + 1;
	else if (n==0)
		akm = Algo_3_27_1(m-1, 1);
	else
		akm = Algo_3_27_1(m-1, Algo_3_27_1(m, n-1));

	return akm;
}

/*━━━━━━━━━━━━━━┓
┃题3.27：模拟栈计算阿克曼函数┃
┗━━━━━━━━━━━━━━*/
/* (2)：利用栈模拟递归 */
int Algo_3_27_2(int m, int n)
{
	Stack S[1000];
	int top = 0;

	if(m<0 || n<0)
		exit(ERROR);

	S[top].mval = m;
	S[top].nval = n;

	do
	{
		while(S[top].mval)
		{
			while(S[top].nval)
			{
				top++;
				S[top].mval = S[top-1].mval;
				S[top].nval = S[top-1].nval - 1;
			}	
			S[top].mval--;
			S[top].nval = 1;	
		}
		
		if(top>0)
		{		
			top--;
			S[top].mval--;
			S[top].nval = S[top+1].nval + 1;
		}
	}while(top!=0 || S[top].mval!=0);
	
	return S[top].nval+1;
}

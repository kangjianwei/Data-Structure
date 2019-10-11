#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"					//**▲01 绪论**//

/* 宏定义 */
#define MAX 100						//最大元素个数 

/* 函数原型 */
Status Algo_6_33(int L[MAX+1], int R[MAX+1], int v, int u);
Status Algo_6_34(int T[MAX+1], int v, int u);

int main(int argc, char *argv[])
{
	int T[MAX+1] = {0, 0, 1, 1, 2, 2, 3, 5, 5, 6};				//0号单元弃用 
	int L[MAX+1] = {0, 2, 4, 6, 0, 7, 0, 0, 0, 0};
	int R[MAX+1] = {0, 3, 5, 0, 0, 8, 9, 0, 0, 0};
	int u, v;
	
	printf("作为示例，建立树：序号→ 1 2 3 4 5 6 7 8 9\n");
	printf("                  L[n]→ 2 4 6 0 7 0 0 0 0\n");
	printf("                  R[n]→ 3 5 0 0 8 9 0 0 0\n");
	printf("                  T[n]→ 0 1 1 2 2 3 5 5 6\n");
	printf("\n");
		
	printf("请输入需要验证的子孙及祖先...\n\n");	

	printf("子孙(1~9) u = ");
	fflush(stdin);
	scanf("%d", &u);
	printf("祖先(1~9) v = ");
	fflush(stdin);
	scanf("%d", &v);
	printf("\n");
	
	printf("███ 题 6.33 验证... ███\n");
	{
		if(Algo_6_33(L, R, v, u))
			printf("u=%d 是 v=%d 的子孙！\n", u, v);
		else
			printf("u=%d 不是 v=%d 的子孙！！\n", u, v);	
		
		printf("\n");
	}
		

	printf("███ 题 6.34 验证... ███\n");
	{
		if(Algo_6_34(T, v, u))
			printf("u=%d 是 v=%d 的子孙！\n", u, v);
		else
			printf("u=%d 不是 v=%d 的子孙！！\n", u, v);
	
		printf("\n");
	}

	return 0;
}

/*━━━━━━━━━━━━━┓
┃题6.33：判断u是否为v的子孙┃
┗━━━━━━━━━━━━━*/
Status Algo_6_33(int L[MAX+1], int R[MAX+1], int v, int u)
{
	if(L[v]==u || R[v]==u)
		return TRUE;
	else
	{
		if(L[v] && Algo_6_33(L, R, L[v], u))
			return TRUE;
		if(R[v] && Algo_6_33(L, R, R[v], u))
			return TRUE;
	}
	
	return FALSE;
}

/*━━━━━━━━━━━━━┓
┃题6.34：判断u是否为v的子孙┃
┗━━━━━━━━━━━━━*/
Status Algo_6_34(int T[MAX+1], int v, int u)
{
	if(T[u]==v)
		return TRUE;
	else
	{
		if(T[u] && Algo_6_34(T, v, T[u]))
			return TRUE;
	}
	
	return FALSE;
}

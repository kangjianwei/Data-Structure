/**************************************
 *							          *
 * 文件夹: ▲06 树和二叉树\11 NQueens *
 * 							          *
 * 文件名: NQueens.c                  *
 * 							          *
 * 算  法: 6.16                       * 
 *                                    *
 *************************************/

#ifndef NQUEENS_C
#define NQUEENS_C

#include "NQueens.h" 									//**06 树和二叉树**//

void InitChessBoard_CB(ChessBoard c[N][N])
{
	int i, j;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			c[i][j] = 0;								//0表示棋盘无棋子 
} 

/*═════╗
║ 算法6.16 ║ 
╚═════*/
void Trial_CB(int i, ChessBoard c[N][N])
{
	int j;
	
	if(N<=3)
	{
		printf("此N值下无解！！\n");
		return;	
	} 

	if(i>N)
	{
		printf(" %d 皇后问题的第 %d 种解法...\n", N, ++order);
		Output_CB(c);
		printf("\n");
		//PressEnter;									//可设置此语句逐步运行	
	}
	else
	{
		for(j=1; j<=N; j++)
		{
			c[i-1][j-1] = 1;							//在第i行第j列放置一个棋子
		
			if(Layout_CB(i, j, c))						//判断此时布局是否合理 
				Trial_CB(i+1, c);
			
			c[i-1][j-1] = 0;							//移去第i行第j列的棋子 		
		}
	}
}

Status Layout_CB(int x, int y, ChessBoard c[N][N])		//x、y为新加入结点的行和列 
{
	int k, count;
	int m, n;
	
	count = 0;
	for(k=1; k<=N; k++)
	{
		if(c[x-1][k-1]==1)
			count++;
		if(count>1)
			return ERROR;
	}
	
	count = 0;
	for(k=1; k<=N; k++)
	{
		if(c[k-1][y-1]==1)
			count++;
		if(count>1)
			return ERROR;
	}
	
	m = x - 1;
	n = y - 1;
	while(m>=1 && n>=1)
	{
		if(c[m-1][n-1])
			return ERROR;
		m = m - 1;
		n = n - 1;
	}
	
	m = x + 1;
	n = y + 1;
	while(m<=N && n<=N)
	{
		if(c[m-1][n-1])
			return ERROR;
		m = m + 1;
		n = n + 1;
	}
	
	m = x + 1;
	n = y - 1;
	while(m<=N && n>=1)
	{
		if(c[m-1][n-1])
			return ERROR;
		m = m + 1;
		n = n - 1;
	}
	
	m = x - 1;
	n = y + 1;
	while(m>=1 && n<=N)
	{
		if(c[m-1][n-1])
			return ERROR;
		m = m - 1;
		n = n + 1;
	}
	
	return OK;	
}

void Output_CB(ChessBoard c[N][N])
{
	int i, j;
	
	printf("┏");
	for(i=1; i<=N-1; i++)
		printf("━┳");
	printf("━┓\n");
	
	for(i=1; i<=N; i++)
	{
		printf("┃");
		for(j=1; j<=N; j++)
		{
			if(c[i-1][j-1]==1)
				printf("●┃");
			else
				printf("  ┃");
		}
		printf("\n");
		
		if(i<N)
		{
			printf("┣");
			for(j=1; j<=N-1; j++)
				printf("━╋");
			printf("━┫");
			printf("\n");		
		}
	}
	
	printf("┗");
	for(i=1; i<=N-1; i++)
		printf("━┻");
	printf("━┛\n");
}

#endif 

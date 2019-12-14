/**************************************
 *							          *
 * �ļ���: ��06 ���Ͷ�����\11 NQueens *
 * 							          *
 * �ļ���: NQueens.c                  *
 * 							          *
 * ��  ��: 6.16                       * 
 *                                    *
 *************************************/

#ifndef NQUEENS_C
#define NQUEENS_C

#include "NQueens.h" 									//**06 ���Ͷ�����**//

void InitChessBoard_CB(ChessBoard c[N][N])
{
	int i, j;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			c[i][j] = 0;								//0��ʾ���������� 
} 

/*�T�T�T�T�T�[
�U �㷨6.16 �U 
�^�T�T�T�T�T*/
void Trial_CB(int i, ChessBoard c[N][N])
{
	int j;
	
	if(N<=3)
	{
		printf("��Nֵ���޽⣡��\n");
		return;	
	} 

	if(i>N)
	{
		printf(" %d �ʺ�����ĵ� %d �ֽⷨ...\n", N, ++order);
		Output_CB(c);
		printf("\n");
		//PressEnter;									//�����ô����������	
	}
	else
	{
		for(j=1; j<=N; j++)
		{
			c[i-1][j-1] = 1;							//�ڵ�i�е�j�з���һ������
		
			if(Layout_CB(i, j, c))						//�жϴ�ʱ�����Ƿ���� 
				Trial_CB(i+1, c);
			
			c[i-1][j-1] = 0;							//��ȥ��i�е�j�е����� 		
		}
	}
}

Status Layout_CB(int x, int y, ChessBoard c[N][N])		//x��yΪ�¼�������к��� 
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
	
	printf("��");
	for(i=1; i<=N-1; i++)
		printf("����");
	printf("����\n");
	
	for(i=1; i<=N; i++)
	{
		printf("��");
		for(j=1; j<=N; j++)
		{
			if(c[i-1][j-1]==1)
				printf("��");
			else
				printf("  ��");
		}
		printf("\n");
		
		if(i<N)
		{
			printf("��");
			for(j=1; j<=N-1; j++)
				printf("����");
			printf("����");
			printf("\n");		
		}
	}
	
	printf("��");
	for(i=1; i<=N-1; i++)
		printf("����");
	printf("����\n");
}

#endif 

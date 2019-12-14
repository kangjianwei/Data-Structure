/****************************************************
 *							                        *
 * 文件夹: ▲05 数组和广义表\03 RowLinkSparseMatrix *
 *							                        *
 * 文件名: RowLinkSparseMatrix.c                    *
 *							                        *
 * 算  法: 5.3                                      * 
 *							                        *
 ***************************************************/

#ifndef ROWLINKSPARSEMATRIX_C
#define ROWLINKSPARSEMATRIX_C

#include "RowLinkSparseMatrix.h" 				//**▲05 数组和广义表**//

Status CreateSMatrix_RL(FILE *fp, int n, ...)
{
	int count, k;
	RLSMatrix *M;
		
	if(n<1)
		return ERROR;

	va_list ap;	
	va_start(ap, n);
	
	for(count=1; count<=n; count++)
	{
		M = va_arg(ap, RLSMatrix *);
		
		for(k=0; k<=MAXRC; ++k)					//初始化数组rpos 
			(*M).rpos[k] = 0;
			
		Scanf(fp, "%d%d%d", &((*M).mu), &((*M).nu), &((*M).tu));

		for(k=1; k<=(*M).tu; k++)
		{
			Scanf(fp, "%d%d%d", &((*M).data[k].i), &((*M).data[k].j), &((*M).data[k].e));
			
			if((*M).rpos[(*M).data[k].i]==0)	//记录每行第一个非零元的位置
				(*M).rpos[(*M).data[k].i] = k;	//（只会在当前行有非零元的情况下记录）
		}
	
		for(k=(*M).mu; k>=1; --k)				//处理那些没有非零元的行 
		{
			if((*M).rpos[k]==0)
			{
				if(k==(*M).mu)					//若最后一行无非零元，需特殊处理
					(*M).rpos[k] = (*M).tu + 1;
				else
					(*M).rpos[k] = (*M).rpos[k+1];
			}
		}	
	}
	
	va_end(ap);
	
	return OK;
}

void DestroySMatrix_RL(RLSMatrix *M)
{
	int i;
	
	M->mu = 0;
	M->nu = 0;
	M->tu = 0;
	
	for(i=0; i<=MAXRC; ++i)
		M->rpos[i] = 0;
}

void PrintSMatrix_RL(RLSMatrix M)
{
	int r, c;
	int k = 1;
	
	for(r=1; r<=M.mu; ++r)
	{
		for(c=1; c<=M.nu; ++c)
		{
			if(r==M.data[k].i && c==M.data[k].j)
			{
				printf("%3d ", M.data[k].e);
				k++;
			}
			else
				printf("  0 ");
		}
		printf("\n");
	}
	
	printf("rpos = ");
	for(k=1; k<=M.mu; ++k)
		printf("%d ", M.rpos[k]);
	printf("\n");
}

void CopySMatrix_RL(RLSMatrix M, RLSMatrix *T)
{
	(*T) = M;											//结构可以直接复制
}

Status AddSMatri_RL(RLSMatrix M, RLSMatrix N, RLSMatrix *Q)
{
	int m, n, k;
	int i;
	
	if(M.mu!=N.mu || M.nu!=N.nu)
	{
		printf("两矩阵不能相加！！\n");
		return ERROR;	
	}
	
	Q->mu = M.mu;
	Q->nu = M.nu;
	Q->tu = 0;
	m = n = k = 1;
	
	while(m<=M.tu && n<=N.tu)							//依次遍历M与N的三元组 
	{
		if(M.data[m].i<N.data[n].i)
		{
			Q->data[k] = M.data[m];
			m++;
		}
		else if(M.data[m].i>N.data[n].i)
		{
			Q->data[k] = N.data[n];
			n++;
		}
		else											//M.data[m].i==N.data[n].i
		{
			if(M.data[m].j<N.data[n].j)
			{
				Q->data[k] = M.data[m];
				m++;
			}
			else if(M.data[m].j>N.data[n].j)
			{
				Q->data[k] = N.data[n];
				n++;
			}
			else										//M.data[m].j==N.data[n].j
			{
				if(M.data[m].e+N.data[n].e)
				{
					Q->data[k].i = M.data[m].i;
					Q->data[k].j = M.data[m].j;
					Q->data[k].e = M.data[m].e+N.data[n].e;
					m++;
					n++;
				}
				else
				{
					m++;
					n++;
					continue;
				}		
			}
		}
		
		k++;
		Q->tu++;
	}
	
	while(m<=M.tu)
	{
		Q->data[k] = M.data[m];
		m++;
		k++;
		Q->tu++;
	}
	
	while(n<=N.tu)
	{
		Q->data[k] = N.data[n];
		n++;
		k++;
		Q->tu++;
	}
	
	for(i=0; i<=MAXRC; ++i)								//初始化数组rpos
		Q->rpos[i] = 0;
	
	for(i=1; i<=Q->tu; ++i)		
	{
		m = Q->data[i].i;								//当前三元组中元素所在的行
		if(Q->rpos[m]==0)								//记录每行第一个非零元的位置
			Q->rpos[m] = i;								//（只会在当前行有非零元的情况下记录）
	}
	
	for(i=Q->mu; i>=1; --i)								//处理那些没有非零元的行 
	{
		if(Q->rpos[i]==0)
		{
			if(i==Q->mu)								//若最后一行无非零元，需特殊处理
				Q->rpos[i] = Q->tu + 1;
			else
				Q->rpos[i] = Q->rpos[i+1];
		}
	}
	
	return OK;
}

Status SubSMatrix_RL(RLSMatrix M, RLSMatrix N, RLSMatrix *Q)
{
	int m, n, k;
	int i;
	
	if(M.mu!=N.mu || M.nu!=N.nu)
	{
		printf("两矩阵不能相减！！\n");
		return ERROR;	
	}
	
	Q->mu = M.mu;
	Q->nu = M.nu;
	Q->tu = 0;
	m = n = k = 1;
	
	while(m<=M.tu && n<=N.tu)
	{
		if(M.data[m].i<N.data[n].i)
		{
			Q->data[k] = M.data[m];
			m++;
		}		
		else if(M.data[m].i>N.data[n].i)
		{
			Q->data[k].i =  N.data[n].i;
			Q->data[k].j =  N.data[n].j;
			Q->data[k].e = -N.data[n].e;
			n++;
		}
		else											//M.data[m].i==N.data[n].i
		{
			if(M.data[m].j<N.data[n].j)
			{
				Q->data[k] = M.data[m];
				m++;
			}
			else if(M.data[m].j>N.data[n].j)
			{
				Q->data[k].i =  N.data[n].i;
				Q->data[k].j =  N.data[n].j;
				Q->data[k].e = -N.data[n].e;
				n++;
			}
			else										//M.data[m].j==N.data[n].j
			{
				if(M.data[m].e-N.data[n].e)
				{
					Q->data[k].i = M.data[m].i;
					Q->data[k].j = M.data[m].j;
					Q->data[k].e = M.data[m].e-N.data[n].e;
					m++;
					n++;
				}
				else
				{
					m++;
					n++;
					continue;
				}		
			}
		}
		
		k++;
		Q->tu++;
	}
	
	while(m<=M.tu)
	{
		Q->data[k] = M.data[m];
		m++;
		k++;
		Q->tu++;
	}
	
	while(n<=N.tu)
	{
		Q->data[k].i =  N.data[n].i;
		Q->data[k].j =  N.data[n].j;
		Q->data[k].e = -N.data[n].e;;
		n++;
		k++;
		Q->tu++;
	}
	
	for(i=0; i<=MAXRC; ++i)								//初始化数组rpos
		Q->rpos[i] = 0;
	
	for(i=1; i<=Q->tu; ++i)		
	{
		m = Q->data[i].i;								//当前三元组中元素所在的行
		if(Q->rpos[m]==0)								//记录每行第一个非零元的位置
			Q->rpos[m] = i;								//（只会在当前行有非零元的情况下记录）
	}
	
	for(i=Q->mu; i>=1; --i)								//处理那些没有非零元的行 
	{
		if(Q->rpos[i]==0)
		{
			if(i==Q->mu)								//若最后一行无非零元，需特殊处理
				Q->rpos[i] = Q->tu + 1;
			else
				Q->rpos[i] = Q->rpos[i+1];
		}
	}
	
	return OK;
}

/*════╗
║ 算法5.3║ 
╚════*/
Status MultSMatrix_RL(RLSMatrix M, RLSMatrix N, RLSMatrix *Q)
{
	int arow, brow, p, q, tp, tq, ccol;
	int ctemp[N.nu+1];									//Q中各行元素值累加器，ctemp[0]不用 
	int i, m;
	
	if(M.nu!=N.mu)										//M列数等于N行数 
	{
		printf("两矩阵不能相乘！！\n");
		return ERROR;	
	}
	
	Q->mu = M.mu;										//Q初始化 
	Q->nu = N.nu;
	Q->tu = 0;
	
	if(M.tu*N.tu)										//Q是非零矩阵
	{
		for(arow=1; arow<=M.mu; ++arow)					//处理M的每一行
		{												//arow为乘积元素在Q中的行号 
			for(i=0; i<=N.nu; ++i)						//初始化Q中行元素值计数器
				ctemp[i] = 0;
			
			if(arow<M.mu)
				tp = M.rpos[arow+1];					//tp指向M当前行的下一行第一个非零元位置
			else
				tp = M.tu + 1;
	
			for(p=M.rpos[arow]; p<tp; ++p)				//p从M当前行第一个非零元位置开始累加
			{
				brow = M.data[p].j;						//对M当前行中每一个非零元，找到对应元在N中的行号
				
				if(brow<N.mu)
					tq = N.rpos[brow+1];				//tq指向N当前行的下一行第一个非零元位置
				else
					tq = N.tu + 1;
					
				for(q=N.rpos[brow]; q<tq; ++q)			//q从N当前行第一个非零元位置开始累加
				{
					ccol = N.data[q].j;					//乘积元素在Q中的列号
					ctemp[ccol] += M.data[p].e * N.data[q].e;
				}
			}//Q中第arow行元素已求出 
			
			for(ccol=1; ccol<=Q->nu; ++ccol)
			{
				if(ctemp[ccol])							//若Q中第arow行ccol列元素不为0 
				{
					++Q->tu;
 					if(Q->tu>MAXSIZE)					//非零元个数超出限制 
						return ERROR;
					Q->data[Q->tu].i = arow;
					Q->data[Q->tu].j = ccol;
					Q->data[Q->tu].e = ctemp[ccol];
				}
			}//for(ccol)
		}//for(arow)
	}//if
		
	for(i=0; i<=MAXRC; ++i)								//初始化数组rpos
		Q->rpos[i] = 0;
	
	for(i=1; i<=Q->tu; ++i)		
	{
		m = Q->data[i].i;								//当前三元组中元素所在的行
		if(Q->rpos[m]==0)								//记录每行第一个非零元的位置
			Q->rpos[m] = i;								//（只会在当前行有非零元的情况下记录）
	}
	
	for(i=Q->mu; i>=1; --i)								//处理那些没有非零元的行 
	{
		if(Q->rpos[i]==0)
		{
			if(i==Q->mu)								//若最后一行无非零元，需特殊处理
				Q->rpos[i] = Q->tu + 1;
			else
				Q->rpos[i] = Q->rpos[i+1];
		}
	}
	
	return OK;
}

void TransposeSMatrix_RL(RLSMatrix M, RLSMatrix *T)
{
	int p, q, col;
	int i, m;
	
	T->mu = M.nu;
	T->nu = M.mu;
	T->tu = M.tu;
	
	for(i=0; i<=MAXRC; ++i)								//初始化数组rpos
		T->rpos[i] = 0;
	
	if(T->tu)
	{
		q = 1;											//q用于T中非零元计数 
		for(col=1; col<=M.nu; ++col)					//col代表M的列，T的行 
		{
			for(p=1; p<=M.tu; ++p)						//p用于M中非零元计数
			{
				if(M.data[p].j==col)
				{
					T->data[q].i = M.data[p].j;			//M的列变为T的行 
					T->data[q].j = M.data[p].i;			//M的行变为T的列
					T->data[q].e = M.data[p].e;			//每个三元组值不变 
				
					if(T->rpos[col]==0)					//记录每行第一个非零元的位置
						T->rpos[col] = q;				//（只会在当前行有非零元的情况下记录）
					
					++q;
				}				
			}
		}
	}
	
	for(i=T->mu; i>=1; --i)								//处理那些没有非零元的行 
	{
		if(T->rpos[i]==0)
		{
			if(i==T->mu)								//若最后一行无非零元，需特殊处理
				T->rpos[i] = T->tu + 1;
			else
				T->rpos[i] = T->rpos[i+1];
		}
	}
}

void FastTransposeSMatrix_RL(RLSMatrix M, RLSMatrix *T)
{
	int col, t, p, q;
	int num[M.nu];										//num[col]表示M第col列中非零元的个数 
	int copt[M.nu];										//copt[col]表示M第col列第一个非零元在T->data中恰当的位置 
	int i, m;
	
	T->mu = M.nu;
	T->nu = M.mu;
	T->tu = M.tu;
	
	if(T->tu)
	{
		for(col=1; col<=M.nu; ++col)
			num[col] = 0;								//初始化数组num
		
		for(t=1; t<=M.tu; ++t)							//t遍历M中三元组
			++num[M.data[t].j];							//统计M中每列非零元个数
		
		copt[1] = 1;
		for(col=2; col<=M.nu; ++col)
			copt[col] = copt[col-1] + num[col-1];
		
		for(p=1; p<=M.tu; ++p)							//依次扫描M中的三元组 
		{
			col = M.data[p].j;							//col为M中第p个三元组中元素的列 
			q = copt[col];								//q为当前三元组元素在T中应放置的位置 
			T->data[q].i = M.data[p].j;
			T->data[q].j = M.data[p].i;
			T->data[q].e = M.data[p].e;
			++copt[col];								//再遇到此列元素时位置增一 
		}
	}
	
	for(i=0; i<=MAXRC; ++i)								//初始化数组rpos
		T->rpos[i] = 0;
	
	for(i=1; i<=T->tu; ++i)		
	{
		m = T->data[i].i;								//当前三元组中元素所在的行
		if(T->rpos[m]==0)								//记录每行第一个非零元的位置
			T->rpos[m] = i;								//（只会在当前行有非零元的情况下记录）
	}
	
	for(i=T->mu; i>=1; --i)								//处理那些没有非零元的行 
	{
		if(T->rpos[i]==0)
		{
			if(i==T->mu)								//若最后一行无非零元，需特殊处理
				T->rpos[i] = T->tu + 1;
			else
				T->rpos[i] = T->rpos[i+1];
		}
	}
}

#endif

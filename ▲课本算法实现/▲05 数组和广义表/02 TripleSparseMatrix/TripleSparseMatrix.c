/***************************************************
 *                                                 *
 * 文件夹: ▲05 数组和广义表\02 TripleSparseMatrix *
 *                                                 *
 * 文件名: TripleSparseMatrix.c                    *
 *                                                 *
 * 算  法: 5.1、5.2                                * 
 *                                                 *
 ***************************************************/

#ifndef TRIPLESPARSEMATRIX_C
#define TRIPLESPARSEMATRIX_C

#include "TripleSparseMatrix.h" 			//**▲05 数组和广义表**//

Status CreateSMatrix_T(FILE *fp, int n, ...)
{
	int count, k;
	TSMatrix *M;
	
	if(n<1)
		return ERROR;

	va_list ap;	
	va_start(ap, n);
	
	for(count=1; count<=n; count++)
	{
		M = va_arg(ap, TSMatrix*);
		
		Scanf(fp, "%d%d%d", &((*M).mu), &((*M).nu), &((*M).tu));

		for(k=1; k<=(*M).tu; k++)
			Scanf(fp, "%d%d%d", &((*M).data[k].i), &((*M).data[k].j), &((*M).data[k].e));
	}
	
	va_end(ap);
	
	return OK;	
}

void DestroySMatrix_T(TSMatrix *M)
{
	(*M).mu = 0;
	(*M).nu = 0;
	(*M).tu = 0;
}

void PrintSMatrix_T(TSMatrix M)
{
	int r, c;
	int k = 1;
	
	for(r=1; r<=M.mu; r++)
	{
		for(c=1; c<=M.nu; c++)
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
}

void CopySMatrix_T(TSMatrix M, TSMatrix *T)
{
	(*T) = M;								//结构可以直接复制 
}

Status AddSMatri_T(TSMatrix M, TSMatrix N, TSMatrix *Q)
{
	int m, n, k;
	
	if(M.mu!=N.mu || M.nu!=N.nu)
	{
		printf("两矩阵不能相加！！\n");
		return ERROR;	
	}
	
	Q->mu = M.mu;
	Q->nu = M.nu;
	Q->tu = 0;
	m = n = k = 1;
	
	while(m<=M.tu && n<=N.tu)				//依次遍历M与N的三元组 
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
		else								//M.data[m].i==N.data[n].i
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
			else							//M.data[m].j==N.data[n].j
			{
				if(M.data[m].e+N.data[n].e)
				{
					Q->data[k].i = M.data[m].i;
					Q->data[k].j = M.data[m].j;
					Q->data[k].e = M.data[m].e + N.data[n].e;
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
	
	return OK;
}

Status SubSMatrix_T(TSMatrix M, TSMatrix N, TSMatrix *Q)
{
	int m, n, k;
	
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
		else								//M.data[m].i==N.data[n].i
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
			else							//M.data[m].j==N.data[n].j
			{
				if(M.data[m].e-N.data[n].e)
				{
					Q->data[k].i = M.data[m].i;
					Q->data[k].j = M.data[m].j;
					Q->data[k].e = M.data[m].e - N.data[n].e;
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
	
	return OK;	
}

Status MultSMatrix_T(TSMatrix M, TSMatrix N, TSMatrix *Q)
{
	int m, n, i, j, k;
	MElemType_TSq c, c1, c2;
	
	if(M.nu!=N.mu)							//M列数等于N行数 
	{
		printf("两矩阵不能相乘！！\n");
		return ERROR;	
	}
	
	Q->mu = M.mu;							//Q初始化 
	Q->nu = N.nu;
	Q->tu = 0;
	
	if(M.tu*N.tu)							//Q是非零矩阵
	{
		for(i=1; i<=M.mu; i++)				//传统矩阵乘法 
		{
			for(j=1; j<=N.nu; j++)
			{
				c = 0;
				for(k=1; k<=M.nu; k++)
				{
					c1 = 0;
					for(m=1; m<=M.tu; m++)	//依次寻找位于指定位置的M三元组 
					{
						if(M.data[m].i==i && M.data[m].j==k)
						{
							c1 = M.data[m].e;
							break;
						}
					}
					
					c2 = 0;
					for(n=1; n<=N.tu; n++)	//依次寻找位于指定位置的N三元组
					{
						if(N.data[n].i==k && N.data[n].j==j)
						{
							c2 = N.data[n].e;
							break;
						}
					}
					
					if(c1 && c2)
						c += c1 * c2;	
				}
				
				if(c)
				{
					Q->tu++;
					Q->data[Q->tu].i = i;
					Q->data[Q->tu].j = j;
					Q->data[Q->tu].e = c;
				}			
			}
		}
	} 
	
	return OK;
}

/*════╗
║ 算法5.1║ 
╚════*/
void TransposeSMatrix_T(TSMatrix M, TSMatrix *T)
{
	int p, q, col;
	
	T->mu = M.nu;
	T->nu = M.mu;
	T->tu = M.tu;
	
	if(T->tu)
	{
		q = 1;									//q用于T中非零元计数 
		for(col=1; col<=M.nu; ++col)			//col代表M的列，T的行 
		{
			for(p=1; p<=M.tu; ++p)				//p用于M中非零元计数
			{
				if(M.data[p].j==col)
				{
					T->data[q].i = M.data[p].j;	//M的列变为T的行 
					T->data[q].j = M.data[p].i;	//M的行变为T的列
					T->data[q].e = M.data[p].e;	//每个三元组值不变
					++q; 
				}
			}
		}
	}
}

/*════╗
║ 算法5.2║ 
╚════*/
void FastTransposeSMatrix_T(TSMatrix M, TSMatrix *T)
{
	int col, t, p, q;
	int num[M.nu];							//num[col]表示M第col列中非零元的个数 
	int copt[M.nu];							//copt[col]表示M第col列第一个非零元在T->data中恰当的位置 
	
	T->mu = M.nu;
	T->nu = M.mu;
	T->tu = M.tu;
	
	if(T->tu)
	{
		for(col=1; col<=M.nu; ++col)
			num[col] = 0;					//初始化数组num
		
		for(t=1; t<=M.tu; ++t)				//t遍历M中三元组
			num[M.data[t].j]++;				//统计M中每列非零元个数
		
		copt[1] = 1;
		for(col=2; col<=M.nu; ++col)
			copt[col] = copt[col-1] + num[col-1];
		
		for(p=1; p<=M.tu; ++p)				//依次扫描M中的三元组 
		{
			col = M.data[p].j;				//col为M中第p个三元组中元素的列 
			q = copt[col];					//q为当前三元组元素在T中应放置的位置 
			T->data[q].i = M.data[p].j;
			T->data[q].j = M.data[p].i;
			T->data[q].e = M.data[p].e;
			++copt[col];					//再遇到此列元素时位置增一 
		}
	}
}

#endif

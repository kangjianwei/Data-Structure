/******************************************
 * 							              *
 * 文件夹: ▲05 数组和广义表\04 CrossList *
 * 							              *
 * 文件名: CrossList.c                    *
 * 							              *
 * 算  法: 5.4                            * 
 * 							              *
 ******************************************/

#ifndef CROSSLIST_C
#define CROSSLIST_C

#include "CrossList.h" 						//**▲05 数组和广义表**//

/*════╗
║ 算法5.4║ 
╚════*/
Status CreateSMatrix_OL(FILE *fp, int n, ...)
{
	int count, k;
	OLNode *p, *q;
	CrossList *M;
	
	if(n<1)
		return ERROR;
	
	va_list ap;	
	va_start(ap, n);
	
	for(count=1; count<=n; count++)
	{
		M = va_arg(ap, CrossList *);	
		Scanf(fp, "%d%d%d", &((*M).mu), &((*M).nu), &((*M).tu));

		(*M).rhead = (OLink *)malloc(((*M).mu+1)*sizeof(OLink));
		if(!(*M).rhead)
			exit(OVERFLOW);

		(*M).chead = (OLink *)malloc(((*M).nu+1)*sizeof(OLink));
		if(!(*M).chead)
			exit(OVERFLOW);

		for(k=0; k<=(*M).mu; ++k)					//初始化行列头指针向量为空 
			(*M).rhead[k] = NULL;
		for(k=0; k<=(*M).nu; ++k)
			(*M).chead[k] = NULL;		

		for(k=1; k<=(*M).tu; ++k)					//依次输入非零元 
		{
			p = (OLNode *)malloc(sizeof(OLNode));	//创建结点 
			if(!p)
				exit(OVERFLOW);
				
			Scanf(fp, "%d%d%d", &(p->i), &(p->j), &(p->e));
			p->right = p->down = NULL;
			
			if((*M).rhead[p->i]==NULL || (*M).rhead[p->i]->j>p->j)
			{										//定位行表中的插入位置
				p->right = (*M).rhead[p->i];
				(*M).rhead[p->i] = p;
			}	
			else									
			{
				for(q=(*M).rhead[p->i]; (q->right)&&(q->right->j<p->j); q=q->right)
					;								//寻找插入位置的前一个位置
				
				if(q->j==p->j || ((q->right)&&q->right->j==p->j))
				{
					printf("此位置已被占用！！\n");
					exit(ERROR);
				}
				
				p->right = q->right;
				q->right = p;
			}										//完成行插入
			
			if((*M).chead[p->j]==NULL || (*M).chead[p->j]->i>p->i)
			{										//定位列表中的插入位置
				p->down = (*M).chead[p->j];
				(*M).chead[p->j] = p;
			}	
			else
			{
				for(q=(*M).chead[p->j]; (q->down)&&(q->down->i<p->i); q=q->down)
					;								//寻找插入位置的前一个位置
				
				if(q->i==p->i || ((q->down)&&q->down->i==p->i))
				{
					printf("此位置已被占用！！\n");
					exit(ERROR);
				}
				
				p->down = q->down;
				q->down = p;
			}										//完成列插入		
		}
	}
	
	va_end(ap);	
	
	return OK;
}

void DestroySMatrix_OL(CrossList *M)
{
	int i;
	OLNode *p, *q;
	
	for(i=1; i<=(*M).mu; ++i)
	{
		p = (*M).rhead[i];
		while(p)
		{
			q = p;
			p = p->right;
			free(q);
		}
	}
	
	free((*M).rhead);
	free((*M).chead);
	
	(*M).rhead = (*M).chead = NULL; 
	(*M).mu = (*M).nu = (*M).tu = 0;
}

void PrintSMatrix_OL(CrossList M)
{
	int i, j;
	OLNode *p;
	
	for(i=1; i<=M.mu; ++i)
	{
		p = M.rhead[i];
		for(j=1; j<=M.nu; ++j)
		{
			if(p && p->j==j)
			{
				printf("%3d ", p->e);
				p = p->right;
			}
			else
				printf("  0 ");			
		}
		printf("\n");
	}
}

void CopySMatrix_OL(CrossList M, CrossList *T)
{
	int i;
	OLNode *p, *q, *r, *l;
	
	T->mu = M.mu;
	T->nu = M.nu;
	T->tu = M.tu;
	
	T->rhead = (OLink *) malloc ((T->mu+1) * sizeof(OLink));
	if(!T->rhead)
		exit(OVERFLOW);
		
	T->chead = (OLink *) malloc ((T->nu+1) * sizeof(OLink));
	if(!T->chead)
		exit(OVERFLOW);
		
	for(i=0; i<=T->mu; ++i)								//初始化行列头指针向量为空 
		T->rhead[i] = NULL;
	for(i=0; i<=T->nu; ++i)
		T->chead[i] = NULL;
	
	for(i=1; i<=M.mu; ++i)
	{
		q = M.rhead[i];									//q指向M的当前结点 
		if(!q)
			continue;
		
		while(q)
		{		
			p = (OLNode *) malloc (sizeof(OLNode));		//创建结点 
			if(!p)
				exit(OVERFLOW);
			p->i = q->i;								//为结点赋值 
			p->j = q->j;
			p->e = q->e;
			p->right = p->down = NULL;
				
			if(T->rhead[q->i]==NULL)					//是函数(1)的相应算法处的简化版 
				T->rhead[q->i] = p;					
			else
				r->right = p;
			r = p;										//r指向T的当前结点									
			
			if(T->chead[q->j]==NULL || T->chead[q->j]->i>q->i)
			{
				r->down = T->chead[q->j];				//类似在无头结点的链表中插入元素 
				T->chead[q->j] = r;
			}	
			else										//寻查在列表中的插入位置
			{
				for(l=T->chead[q->j]; (l->down)&&(l->down->i<q->i); l=l->down)
					;									//寻找插入位置的前一个位置
				r->down = l->down;
				l->down = r;
			}//完成列插入
			
			q = q->right;		
		}//while		
	}//for	
}

Status AddSMatri_OL(CrossList M, CrossList N, CrossList *Q)
{
	int i;
	OLNode *pm, *pn, *p, *r, *l;
	
	if(M.mu!=N.mu || M.nu!=N.nu)
	{
		printf("两矩阵不能相加！！\n");
		return ERROR;	
	}
	
	Q->mu = M.mu;
	Q->nu = M.nu;
	Q->tu = 0;
	
	Q->rhead = (OLink *) malloc ((Q->mu+1) * sizeof(OLink));
	if(!Q->rhead)
		exit(OVERFLOW);
		
	Q->chead = (OLink *) malloc ((Q->nu+1) * sizeof(OLink));
	if(!Q->chead)
		exit(OVERFLOW);
		
	for(i=0; i<=Q->mu; ++i)								//初始化行列头指针向量为空 
		Q->rhead[i] = NULL;
	for(i=0; i<=Q->nu; ++i)
		Q->chead[i] = NULL;
	
	for(i=1; i<=M.mu; ++i)								//从第一行往下遍历 
	{
		pm = M.rhead[i];
		pn = N.rhead[i];
		
		while(pm && pn)									//当前行中M与N均有未扫描的非零元
		{
			if(pm->j==pn->j && pm->e+pn->e==0)
			{
				pm = pm->right;
				pn = pn->right;
				continue;
			}
			
			p = (OLNode *) malloc (sizeof(OLNode));		//创建结点 
			if(!p)
				exit(OVERFLOW);
					
			if(pm->j < pn->j)
			{
				p->i = pm->i;							//为结点赋值 
				p->j = pm->j;
				p->e = pm->e;
				pm = pm->right;			
			}
			else if(pm->j > pn->j)
			{
				p->i = pn->i;							//为结点赋值 
				p->j = pn->j;
				p->e = pn->e;
				pn = pn->right;
			}
			else										//pm->j == pn->j
			{											//隐含条件为pm->e + pn->e!=0
				p->i = pm->i;	
				p->j = pm->j;
				p->e = pm->e + pn->e;				
				pm = pm->right;
				pn = pn->right;
			}
			
			p->right = p->down = NULL;
			
			Q->tu++;									//Q中非零元个数增一 
			
			if(Q->rhead[p->i]==NULL)					//是函数(1)的相应算法处的简化版 
				Q->rhead[p->i] = p;					
			else
				r->right = p;
			r = p;										//r指向Q的当前结点									
				
			if(Q->chead[p->j]==NULL || Q->chead[p->j]->i>p->i)
			{
				r->down = Q->chead[p->j];				//类似在无头结点的链表中插入元素 
				Q->chead[p->j] = r;
			}	
			else										//寻查在列表中的插入位置
			{
				for(l=Q->chead[p->j]; (l->down)&&(l->down->i<p->i); l=l->down)
					;									//寻找插入位置的前一个位置
				r->down = l->down;
				l->down = r;
			}//完成列插入
		}
		
		while(pm)										//当前行中M仍有未扫描的非零元
		{
			p = (OLNode *) malloc (sizeof(OLNode));		//创建结点 
			if(!p)
				exit(OVERFLOW);
			p->i = pm->i;								//为结点赋值 
			p->j = pm->j;
			p->e = pm->e;
			p->right = p->down = NULL;
			
			Q->tu++;									//Q中非零元个数增一
				
			if(Q->rhead[p->i]==NULL)					//是函数(1)的相应算法处的简化版 
				Q->rhead[p->i] = p;					
			else
				r->right = p;
			r = p;										//r指向Q的当前结点									
				
			if(Q->chead[p->j]==NULL || Q->chead[p->j]->i>p->i)
			{
				r->down = Q->chead[p->j];				//类似在无头结点的链表中插入元素 
				Q->chead[p->j] = r;
			}	
			else										//寻查在列表中的插入位置
			{
				for(l=Q->chead[p->j]; (l->down)&&(l->down->i<p->i); l=l->down)
					;									//寻找插入位置的前一个位置
				r->down = l->down;
				l->down = r;
			}//完成列插入
				
			pm = pm->right;	
		}		
		
		while(pn)										//当前行中N仍有未扫描的非零元 
		{
			p = (OLNode *) malloc (sizeof(OLNode));		//创建结点 
			if(!p)
				exit(OVERFLOW);
			p->i = pn->i;								//为结点赋值 
			p->j = pn->j;
			p->e = pn->e;
			p->right = p->down = NULL;
			
			Q->tu++;									//Q中非零元个数增一
				
			if(Q->rhead[p->i]==NULL)					//是函数(1)的相应算法处的简化版 
				Q->rhead[p->i] = p;					
			else
				r->right = p;
			r = p;										//r指向Q的当前结点									
				
			if(Q->chead[p->j]==NULL || Q->chead[p->j]->i>p->i)
			{
				r->down = Q->chead[p->j];				//类似在无头结点的链表中插入元素 
				Q->chead[p->j] = r;
			}	
			else										//寻查在列表中的插入位置
			{
				for(l=Q->chead[p->j]; (l->down)&&(l->down->i<p->i); l=l->down);
				//寻找插入位置的前一个位置
				r->down = l->down;
				l->down = r;
			}//完成列插入
				
			pn = pn->right;	
		}
	}	
}

Status SubSMatrix_OL(CrossList M, CrossList N, CrossList *Q)
{
	int i;
	OLNode *pm, *pn, *p, *r, *l;
	
	if(M.mu!=N.mu || M.nu!=N.nu)
	{
		printf("两矩阵不能相减！！\n");
		return ERROR;	
	}
	
	Q->mu = M.mu;
	Q->nu = M.nu;
	Q->tu = 0;
	
	Q->rhead = (OLink *) malloc ((Q->mu+1) * sizeof(OLink));
	if(!Q->rhead)
		exit(OVERFLOW);
	Q->chead = (OLink *) malloc ((Q->nu+1) * sizeof(OLink));
	if(!Q->chead)
		exit(OVERFLOW);
	for(i=0; i<=Q->mu; ++i)								//初始化行列头指针向量为空 
		Q->rhead[i] = NULL;
	for(i=0; i<=Q->nu; ++i)
		Q->chead[i] = NULL;
	
	for(i=1; i<=M.mu; ++i)								//从第一行往下遍历 
	{
		pm = M.rhead[i];
		pn = N.rhead[i];
		
		while(pm && pn)									//当前行中M与N均有未扫描的非零元
		{
			if(pm->j==pn->j && pm->e-pn->e==0)
			{
				pm = pm->right;
				pn = pn->right;
				continue;
			}
			
			p = (OLNode *) malloc (sizeof(OLNode));		//创建结点 
			if(!p)
				exit(OVERFLOW);
					
			if(pm->j < pn->j)
			{
				p->i = pm->i;							//为结点赋值 
				p->j = pm->j;
				p->e = pm->e;
				pm = pm->right;			
			}
			else if(pm->j > pn->j)
			{
				p->i =  pn->i;							//为结点赋值 
				p->j =  pn->j;
				p->e = -pn->e;							//加负号 
				pn = pn->right;
			}
			else										//pm->j == pn->j
			{											//隐含条件为pm->e - pn->e!=0
				p->i = pm->i;	
				p->j = pm->j;
				p->e = pm->e - pn->e;				
				pm = pm->right;
				pn = pn->right;
			}
			
			p->right = p->down = NULL;
			
			Q->tu++;									//Q中非零元个数增一 
			
			if(Q->rhead[p->i]==NULL)					//是函数(1)的相应算法处的简化版 
				Q->rhead[p->i] = p;					
			else
				r->right = p;
			r = p;										//r指向Q的当前结点									
				
			if(Q->chead[p->j]==NULL || Q->chead[p->j]->i>p->i)
			{
				r->down = Q->chead[p->j];				//类似在无头结点的链表中插入元素 
				Q->chead[p->j] = r;
			}	
			else										//寻查在列表中的插入位置
			{
				for(l=Q->chead[p->j]; (l->down)&&(l->down->i<p->i); l=l->down)
					;									//寻找插入位置的前一个位置
				r->down = l->down;
				l->down = r;
			}//完成列插入
		}
		
		while(pm)										//当前行中M仍有未扫描的非零元
		{
			p = (OLNode *) malloc (sizeof(OLNode));		//创建结点 
			if(!p)
				exit(OVERFLOW);
			p->i = pm->i;								//为结点赋值 
			p->j = pm->j;
			p->e = pm->e;
			p->right = p->down = NULL;
			
			Q->tu++;									//Q中非零元个数增一
				
			if(Q->rhead[p->i]==NULL)					//是函数(1)的相应算法处的简化版 
				Q->rhead[p->i] = p;					
			else
				r->right = p;
			r = p;										//r指向Q的当前结点									
				
			if(Q->chead[p->j]==NULL || Q->chead[p->j]->i>p->i)
			{
				r->down = Q->chead[p->j];				//类似在无头结点的链表中插入元素 
				Q->chead[p->j] = r;
			}	
			else										//寻查在列表中的插入位置
			{
				for(l=Q->chead[p->j]; (l->down)&&(l->down->i<p->i); l=l->down)
					;									//寻找插入位置的前一个位置
				r->down = l->down;
				l->down = r;
			}//完成列插入
				
			pm = pm->right;	
		}		
		
		while(pn)										//当前行中N仍有未扫描的非零元 
		{
			p = (OLNode *) malloc (sizeof(OLNode));		//创建结点 
			if(!p)
				exit(OVERFLOW);
			p->i =  pn->i;								//为结点赋值 
			p->j =  pn->j;
			p->e = -pn->e;								//加负号 
			p->right = p->down = NULL;
			
			Q->tu++;									//Q中非零元个数增一
				
			if(Q->rhead[p->i]==NULL)					//是函数(1)的相应算法处的简化版 
				Q->rhead[p->i] = p;					
			else
				r->right = p;
			r = p;										//r指向Q的当前结点									
				
			if(Q->chead[p->j]==NULL || Q->chead[p->j]->i>p->i)
			{
				r->down = Q->chead[p->j];				//类似在无头结点的链表中插入元素 
				Q->chead[p->j] = r;
			}	
			else										//寻查在列表中的插入位置
			{
				for(l=Q->chead[p->j]; (l->down)&&(l->down->i<p->i); l=l->down)
					;									//寻找插入位置的前一个位置
				r->down = l->down;
				l->down = r;
			}//完成列插入
				
			pn = pn->right;	
		}
	}
}

Status MultSMatrix_OL(CrossList M, CrossList N, CrossList *Q)
{
	int m_row, n_col, i;
	CElemType e;
	OLNode *pm, *pn, *p, *r, *l;
	
	if(M.nu!=N.mu)										//M列数等于N行数 
	{
		printf("两矩阵不能相乘！！\n");
		return ERROR;	
	}
	
	Q->mu = M.mu;										//Q初始化 
	Q->nu = N.nu;
	Q->tu = 0;
	
	Q->rhead = (OLink *) malloc ((Q->mu+1) * sizeof(OLink));
	if(!Q->rhead)
		exit(OVERFLOW);
		
	Q->chead = (OLink *) malloc ((Q->nu+1) * sizeof(OLink));
	if(!Q->chead)
		exit(OVERFLOW);
		
	for(i=0; i<=Q->mu; ++i)								//初始化行列头指针向量为空 
		Q->rhead[i] = NULL;
	for(i=0; i<=Q->nu; ++i)
		Q->chead[i] = NULL;

	if(M.tu*N.tu)										//Q是非零矩阵
	{
		for(m_row=1; m_row<=M.mu; ++m_row)
		{
			for(n_col=1; n_col<=N.nu; ++n_col)
			{
				pm = M.rhead[m_row];
				pn = N.chead[n_col];
				e = 0;
				
				while(pm && pn)
				{
					if(pm->j < pn->i)
						pm = pm->right;
					else if(pm->j > pn->i)
						pn = pn->down;
					else
					{
						e += pm->e * pn->e;
						pm = pm->right;
						pn = pn->down;
					}
				}

				if(e)
				{
					p = (OLNode *) malloc (sizeof(OLNode));	//创建结点 
					if(!p)
						exit(OVERFLOW);

					p->i = M.rhead[m_row]->i;			//为结点赋值 
					p->j = N.chead[n_col]->j;
					p->e = e;
					p->right = p->down = NULL;
					
					Q->tu++;							//Q中非零元个数增一
						
					if(Q->rhead[p->i]==NULL)			//是函数(1)的相应算法处的简化版 
						Q->rhead[p->i] = p;					
					else
						r->right = p;
					r = p;								//r指向Q的当前结点									
						
					if(Q->chead[p->j]==NULL || Q->chead[p->j]->i>p->i)
					{
						r->down = Q->chead[p->j];		//类似在无头结点的链表中插入元素 
						Q->chead[p->j] = r;
					}	
					else								//寻查在列表中的插入位置
					{
						for(l=Q->chead[p->j]; (l->down)&&(l->down->i<p->i); l=l->down)
							;							//寻找插入位置的前一个位置

						r->down = l->down;
						l->down = r;
					}									//完成列插入					
				}
			}
		}
	}
	
	return OK;
}

void TransposeSMatrix_OL(CrossList M, CrossList *T)
{
	int i;
	OLNode *p, *q, *r, *l;
	
	T->mu = M.nu;
	T->nu = M.mu;
	T->tu = M.tu;
	
	T->rhead = (OLink *) malloc ((T->mu+1) * sizeof(OLink));
	if(!T->rhead)
		exit(OVERFLOW);
		
	T->chead = (OLink *) malloc ((T->nu+1) * sizeof(OLink));
	if(!T->chead)
		exit(OVERFLOW);
		
	for(i=0; i<=T->mu; ++i)								//初始化行列头指针向量为空 
		T->rhead[i] = NULL;
	for(i=0; i<=T->nu; ++i)
		T->chead[i] = NULL;
	
	if(T->tu)
	{
		for(i=1; i<=M.nu; ++i)							//按列扫描 
		{
			q = M.chead[i];								//q指向M的当前结点 
			if(!q)
				continue;
				
			while(q)
			{
				p = (OLNode *) malloc (sizeof(OLNode));	//创建结点 
				if(!p)
					exit(OVERFLOW);
				p->i = q->j;							//为结点赋值 
				p->j = q->i;
				p->e = q->e;
				p->right = p->down = NULL;
				
				if(T->rhead[p->i]==NULL)				//是函数(1)的相应算法处的简化版 
					T->rhead[p->i] = p;					
				else
					r->right = p;
				r = p;									//r指向T的当前结点									
				
				if(T->chead[p->j]==NULL || T->chead[p->j]->i>p->i)
				{
					r->down = T->chead[p->j];			//类似在无头结点的链表中插入元素 
					T->chead[p->j] = r;
				}	
				else									//寻查在列表中的插入位置
				{
					for(l=T->chead[p->j]; (l->down)&&(l->down->i<p->i); l=l->down)
						;								//寻找插入位置的前一个位置
					r->down = l->down;
					l->down = r;
				}//完成列插入
				
				q = q->down;
			}//while
		}//for		
	}//if
}

#endif

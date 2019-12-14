/****************************************
 *						                *
 * 文件夹: ▲06 树和二叉树\06 ChildTree *
 * 						                *
 * 文件名: ChildTree.c                  *
 *    	    			                *
 ****************************************/
 
#ifndef CHILDTREE_C
#define CHILDTREE_C

#include "ChildTree.h" 								//**06 树和二叉树**//

void InitTree_C(FILE *fp, CTree *T)
{
	int i;
	char tmp;
	
	Scanf(fp, "%d", &i);
	printf("录入●根结点●位置（非负数）：%d\n", i);	
	Scanf(fp, "%c", &tmp);							//跳过此行最后的换行符 

	if(i<0 || i>MAX_TREE_SIZE-1)
	{
		printf(" i 值错误！\n");
		exit(ERROR);
	}
	
	(*T).r = i;										//根结点设置在第4个位置
	(*T).n = 0; 
}

void FreeChild_C(ChildPtr *p)						//清除孩子链表结点
{
	ChildPtr q;
	
	while(*p)
	{
		q = (*p)->next;
		free(*p);
		*p = q;
	}
}

void ClearTree_C(CTree *T)
{
	int i;												 
	
	if((*T).n)
	{
		for(i=0; i<T->n-1; i++)
		{
			if(T->nodes[i].firstchild)
				FreeChild_C(&(T->nodes[i].firstchild));
		}
		
		if(T->r<=T->n-1)								//根结点与其它结点聚在一起
		{				 
			if(T->nodes[i].firstchild)					//此时i=T.n-1
				FreeChild_C(&(T->nodes[i].firstchild));								
		}
		else
		{				
			if(T->nodes[T->r].firstchild)				//找到根结点比较
				FreeChild_C(&(T->nodes[T->r].firstchild));			
		}		
	
		(*T).n = 0;		
	}
}

void DestroyTree_C(CTree *T)
{
	//此存储结构下的树无法销毁
}

Status TreeEmpty_C(CTree T)
{
	return (T.n ? FALSE : TRUE); 
}

Status CreateTree_C(FILE *fp, CTree *T)
{
	TElemType_C ch, tmp;
	int i;				//i标记当前结点的父结点位置 
	int j;				//j标记当前结点位置 
	int k;				//k标记i结点第一个孩子位置 
	ChildPtr p, q;

	Scanf(fp, "%c", &ch);	
	printf("录入树的★根结点★──→%c\n", ch);
	Scanf(fp, "%c", &tmp);								//跳过换行符 	

	if(ch!='^')
	{	
		i = (*T).r; 
		(*T).nodes[i].parent = -1;						//注意根结点的设置 
		(*T).nodes[i].data = ch;
		(*T).nodes[i].firstchild = NULL;
		(*T).n++;
		
		if(i!=0)										//第二个结点 
			j = 0;
		else
			j = 1;
		
		k = j;
		
		while(!feof(fp))
		{	
			Scanf(fp, "%c", &ch);
			printf("依次录入 %c 的孩子结点 →", ch);
			
			p = q = NULL;

			while(1)
			{
				Scanf(fp, "%c", &ch);
				if(ch=='^' || ch=='\n')
				{
					if(ch=='^')
					{
						printf("%c", ch);
						Scanf(fp, "%c", &tmp);			//跳过换行符 
					}
						
					break;
				}
				else
				{
					printf("%c", ch);
					(*T).nodes[j].parent = i;			//层序建立树			
					(*T).nodes[j].data = ch;				
					(*T).nodes[j].firstchild = NULL;
					(*T).n++;
					
					p = (ChildPtr)malloc(sizeof(CTNode));
					if(!p)
						exit(OVERFLOW);
						
					p->child = j;						//建立孩子链表 
					p->next = NULL;
				
					if((*T).nodes[i].firstchild==NULL)
						(*T).nodes[i].firstchild = p;
					else
						q->next = p;
					
					q = p;
				}
				
				if(j+1==(*T).r)
					j = j + 2;
				else
					j++;
			}
			
			printf("\n");
			
			i = k;
			if(k+1==(*T).r)
				k = k + 2;
			else
				k++;						
		}
	}

	return OK;	
}

int TreeDegree_C(CTree T)
{
	int max, tmp;
	ChildPtr p;
	LinkQueue Q;
	QElemType_L e;
	
	max = 0;
	
	if(T.n)
	{
		InitQueue_L(&Q);
		EnQueue_L(&Q, T.r);
		
		while(!QueueEmpty_L(Q))
		{
			DeQueue_L(&Q, &e);
			
			p = T.nodes[e].firstchild;
			tmp = 0;
			
			while(p)
			{
				tmp++;
				EnQueue_L(&Q, p->child);
				p = p->next;
			}
			
			if(tmp>max)
				max = tmp;
		}		
	}
	
	return max;
}

int TreeDepth_C_1(CTree T)
{
	int level, i, tmp;
	int end;							//最后一个结点的位置
	
	level = 0;
	
	if(T.n)
	{
		if(T.n==1)
			end = T.r;
		else
		{
			if(T.r<T.n-1)
				end = T.n - 1;
			else
				end = T.n - 2;
		}	

		level = 1;
		i = end;
		while(T.nodes[i].parent!=-1)	//最后存储的结点必定位于最大层次上 
		{
			level++;
			i = T.nodes[i].parent;
		}
	}
	
	return level; 
}

int Depth_C(CTree T, int i)
{
	ChildPtr p = T.nodes[i].firstchild;
	int d, tmp;
	
	if(!p)
		d = 1;
	else
	{
		while(p)
		{
			tmp = 1 + Depth_C(T, p->child);
			if(d<tmp)
				d = tmp;
			p = p->next;
		}
	}
	
	return d;
}

int TreeDepth_C_2(CTree T)
{
	int d = 0;
	
	if(T.n)
		d = Depth_C(T, T.r);

	return d;
}

TElemType_C Root_C(CTree T)
{
	if(T.n)
		return T.nodes[T.r].data;
	
	return '\0';
}

TElemType_C Value_C(CTree T, int i)
{
	if(T.n && i>0 && i<=T.n)
	{
		if(i==1)
			return T.nodes[T.r].data;
		else
		{
			if(i-1>T.r)
				return T.nodes[i-1].data;
			else
				return T.nodes[i-2].data;
		}
	}
	
	return '\0';
}

int Order_C(CTree T, TElemType_C e)
{
	int i;
	int k = -1;
	
	if(T.n)
	{
		for(i=0; i<T.n-1; i++)
		{
			if(T.nodes[i].data==e)
			{
				k = i;
				return k;
			}
		}
		
		if(T.r<=T.n-1)							//根结点与其它结点聚在一起
		{
			if(T.nodes[i].data==e)				//此时i=T.n-1 
				k = i;								
		}
		else
		{
			if(T.nodes[T.r].data==e)			//与根结点比较	
				k = T.r;			
		}
	}	
	
	return k;
} 

Status Assign_C(CTree *T, TElemType_C e, TElemType_C value)
{
	int i;
	
	if((*T).n)
	{
		i = Order_C(*T, e);
		
		if(i>=0)							//找到了e
		{
			(*T).nodes[i].data = value;
			return OK;
		}
	}
	
	return ERROR;
}

TElemType_C ChildValue_C(CTree T, TElemType_C e, int order)
{
	int i;
	int count;
	ChildPtr p;
	
	if(T.n)
	{
		i = Order_C(T, e);		
	
		if(i>=0)										//找到了e
		{
			count = 0;
			p = T.nodes[i].firstchild;
			
			while(p)
			{
				count++;
				if(count==order)
					break;
				else
					p = p->next;
			}
			
			if(p)
				return T.nodes[p->child].data;
		}
	}
	
	return '\0';
}

TElemType_C Sibling_C_1(CTree T, TElemType_C e, int mark)
{
	int i, k;
	ChildPtr p;
	
	if(T.n)
	{
		i = Order_C(T, e);								//i为结点e的位置	
		
		if(i>=0 && i!=T.r)								//找到了e，且e不为根结点 
		{
			k = T.nodes[i].parent;						//找到e的双亲
			p = T.nodes[k].firstchild;
			
			while(p)
			{
				if(mark==0)								//寻找左兄弟
				{
					if(p && p->next && p->next->child==i)
						return T.nodes[p->child].data;
				}
				
				if(mark==1)								//寻找右兄弟
				{
					if(p->child==i && p->next)
						return T.nodes[p->next->child].data;
				}
				
				p = p->next; 
			}
		}
	}
	
	return '\0';
}

int Sibling_C_2(CTree T, int order, int mark)			//不借助双亲序号 
{
	int i;												 //除根结点外，标记最后一个结点位置
	ChildPtr p, q;
	
	if(order==T.r)
		return -1;										//根结点无兄弟
	
	for(i=0; i<=T.n-2; i++)
	{
		p = T.nodes[i].firstchild;
		
		if(p)
		{
			if(mark==0)
			{
				if(p->child==order)
					return -1;
				else
				{
					q = p;
					p = p->next;
				}
				
				while(p && p->child!=order)
				{
					q = p;
					p = p->next;					
				}
				
				if(p)
					return q->child;
			}
			
			if(mark==1)
			{
				while(p && p->child!=order)
					p = p->next;
				
				if(p)
				{
					if(p->next)
						return p->next->child;
					else
						return -1;				
				}
			}
		}
	}
	
	if(T.r>T.n-1)			//访问根结点 
	{
		p = T.nodes[T.r].firstchild;
		
		if(p)
		{
			if(mark==0)
			{
				if(p->child==order)
					return -1;
				else
				{
					q = p;
					p = p->next;
				}
				
				while(p && p->child!=order)
				{
					q = p;
					p = p->next;					
				}
				
				if(!p)
					return -1;
				else
					return q->child;
			}
			
			if(mark==1)
			{
				while(p && p->child!=order)
					p = p->next;
				
				if(p)
				{
					if(p->next)
						return p->next->child;
					else
						return -1;				
				}
				else
					return -1;
			}
		}	
	}
	else					//访问最后一个结点 
	{
		p = T.nodes[i].firstchild;
		
		if(p)
		{
			if(mark==0)
			{
				if(p->child==order)
					return -1;
				else
				{
					q = p;
					p = p->next;
				}
				
				while(p && p->child!=order)
				{
					q = p;
					p = p->next;					
				}
				
				if(!p)
					return -1;
				else
					return q->child;
			}
			
			if(mark==1)
			{
				while(p && p->child!=order)
					p = p->next;
				
				if(p)
				{
					if(p->next)
						return p->next->child;
					else
						return -1;				
				}
				else
					return -1;
			}
		}	
	}
	
}

int ChildCount_C(CTree T, TElemType_C p)
{
	int k, count;
	ChildPtr q;
	
	k = Order_C(T, p);
	
	if(k>=0)
	{
		count = 0;
		q = T.nodes[k].firstchild;
		while(q)
		{
			count++;
			q = q->next;
		}
		
		return count;
	}
	
	return k;
}

int ChildSeat_C(CTree T, TElemType_C p, int i)
{
	int k0, k1, k2, j, m;
	int count;
	
	k0 = ChildCount_C(T, p);				//k0为p结点孩子数 
	
	if(k0<0 || i<0 || i>k0+1)				//判断是否可以插入 
		return -2;

	if(i==0)								//j为实际插入序列 
		j = k0 + 1;
	else
		j = i;
	
	k1 = Order_C(T, p);						//p在数组中的位置 
	
	if(k1==T.r)				//p为根结点 
	{
		k2 = count = 0;
		while(1)
		{
			if(k2==T.r)
				k2++;
			count++;
			if(count==j)
				break;
			k2++;                             
		} 
	}
	else
	{
		m = 0;
		while(1)
		{
			if(m==T.r)
				m++;
			if(T.nodes[m].parent==T.r)
				m++;
			else
				break;		
		}
		
		k2 = m;
		count = 0;
		while(k2<T.n-1)
		{
			if(k2==T.r)
				k2++;
			else
			{
				if(T.nodes[k2].parent>=k1)
					count++;
				if(count==j)
					break;
				k2++;  			
			}				
		}
		
		if(k2==T.n-1)			//自然退出 
		{
			if(T.r==T.n-1)
				k2 = T.n;

			if(T.r<T.n-1)		//此时count必定小于j 
			{
				if(T.nodes[k2].parent>=k1)
					count++;				
				if(count!=j)
					k2 = T.n;
			}
		}		
	}
	
	return k2;
}

ChildPtr SiblingSeat_C(CTree T, TElemType_C p)
{
	ChildPtr q;
	int k;
	
	if(T.n && p!=T.nodes[T.r].data)				//不为空树且p不为根结点
	{
		k = T.nodes[Order_C(T, p)].parent;		//p结点双亲结点的位置
		q = T.nodes[k].firstchild;
		while(q->child!=Order_C(T, p)) 
			q = q->next;
		
		return q;
	}
	
	return NULL; 
} 

Status InsertChild_C(CTree *T, TElemType_C p, int i, TElemType_C e)
{
	int k, j; 
	int x, y;
	int m;
	ChildPtr q, h;
	
	k = ChildSeat_C(*T, p, i);					//k为插入位置
	if(k<0)										//插入位置有误
		return ERROR;				
	
	if(T->r<=T->n-1)								//根结点与其它结点聚在一起
	{
		x = T->n;	
		y = T->n - 1;
	}
	else
	{
		x = T->n - 1;
		y = T->n - 2;
	}
	
	while(y>=k)
	{
		if(y==T->r)
			y--;
			
		if(T->nodes[y].parent<k)
			T->nodes[x].parent = T->nodes[y].parent;
		else
		{
			if(T->nodes[y].parent==T->r-1)
				T->nodes[x].parent = T->nodes[y].parent + 2;	
			else
				T->nodes[x].parent = T->nodes[y].parent + 1;

		}	
		T->nodes[x].data = T->nodes[y].data;
		T->nodes[x].firstchild = T->nodes[y].firstchild;
		
		x--;
		if(x==T->r)
			x--;
			
		y--;
	}

	T->nodes[k].parent = Order_C(*T, p);
	T->nodes[k].data = e;
	T->nodes[k].firstchild = NULL;
	T->n++;
	
	m = 0;
	while(m<T->n-1 || (m==T->n-1 && T->r<=T->n))			//遍历，处理树的双亲 
	{
		q = T->nodes[m].firstchild;
		while(q)
		{
			if(q->child>=k)
			{
				if(q->child==T->r-1)
					q->child = q->child + 2;			
				else
					q->child = q->child + 1;
			}
			
			q = q->next;
		}
		m++;
	}
	
	if(T->r>T->n)
	{
		q = T->nodes[T->r].firstchild;
		while(q)
		{
			if(q->child>=k)
			{
				if(q->child==T->r-1)
					q->child = q->child + 2;			
				else
					q->child = q->child + 1;
			}
			
			q = q->next;
		}	
	}

	h = (ChildPtr)malloc(sizeof(CTNode));					//将插入的结点放入孩子链表中 
	h->child = k;

	if(i==0)												//j为实际插入序列 
		j = ChildCount_C(*T, p) + 1;
	else
		j = i;

	if(j==1)
	{
		h->next = T->nodes[Order_C(*T, p)].firstchild;
		T->nodes[Order_C(*T, p)].firstchild = h;
	}
	else
	{
		q = SiblingSeat_C(*T, ChildValue_C(*T, p, j-1));
		h->next = q->next;
		q->next = h;
	}
		
	return OK;	
}

Status InsertTree_C(CTree *T, TElemType_C p, int i, CTree t)
{
	int k, count, end;
	ChildPtr h, q, l;
	
	if(TreeEmpty_C(*T) || TreeEmpty_C(t))
		return ERROR;

	if(t.r>=t.n-1)
		end = t.n-2;
	else
		end = t.n-1;
			
	InsertChild_C(T, p, i, t.nodes[t.r].data);			//先将t的父结点插入到T中 
	
	for(k=0; k<=end; k++)
	{
		if(k==t.r)
			k++;
		InsertChild_C(T, t.nodes[t.nodes[k].parent].data, 0, t.nodes[k].data);
	}
	
	return OK;
}

Status DeleteTree_C(CTree *T, TElemType_C p, int i)
{
	int k0, k1, count;
	ChildPtr h, q, t;
	LinkQueue Q;
	QElemType_L e;
	int order[MAX_TREE_SIZE];							//存储当前结点的实际位置 
	int x, y, new_n, tmp;
	
	k0 = Order_C(*T, p);								//寻找p的位置
	if(k0>=0)	 
	{
		count = 0;
		h = (*T).nodes[k0].firstchild;
		while(h)
		{
			count++;
			if(count==i)
				break;
			h = h->next;
		}
		
		if(h)
		{
			k1 = h->child;								//找到p的第i个结点的位置，即删除起点 		
			
			q = T->nodes[T->nodes[k1].parent].firstchild;
			if(q->child==k1)
			{
				t = q;
				T->nodes[T->nodes[k1].parent].firstchild = t->next;
			}
			else
			{				 
				while(q->next->child!=k1)				//一定可以找到符合条件的q 
					q = q->next;
				t = q->next;
				q->next = t->next;
			}	
			free(t);
			t = NULL;
			
			InitQueue_L(&Q);
			EnQueue_L(&Q, k1);
			while(!QueueEmpty_L(Q))
			{
				DeQueue_L(&Q, &e);
				T->nodes[e].data = '\0';					//抹掉此处结点 
				if(T->nodes[e].firstchild)					//若此结点有孩子结点
				{
					q = T->nodes[e].firstchild;
					while(q)
					{
						EnQueue_L(&Q, q->child);
						q = q->next;
					}
					FreeChild_C(&(T->nodes[e].firstchild));	//释放此结点的孩子链表 
				}
			}
			
			order[T->r] = T->r;
			count = 1;						//记录访问过的元素个数 
			new_n = 1;						//记录实际元素个数 
			
			x = -1;
			y = 0;
			while(count<T->n)
			{
				if(y==T->r)
					y++;
				if(T->nodes[y].data)
				{
					x++;
					if(x==T->r)
						x++;
					T->nodes[x].parent = T->nodes[y].parent;
					T->nodes[x].data = T->nodes[y].data;
					T->nodes[x].firstchild = T->nodes[y].firstchild;
					order[y] = x;
					new_n++;					
				}					
				y++;				
				
				count++;
			}
			
			T->nodes[y-1].firstchild = NULL;
						
			T->n = new_n;
			count=1;
			x = 0;
			
			while(count<T->n)				//纠正双亲结点及孩子结点位置 
			{
				if(x==T->r)
					x++;
				
				T->nodes[x].parent = order[T->nodes[x].parent];
				if(T->nodes[x].firstchild)
				{
					t = T->nodes[x].firstchild;
					while(t)
					{
						t->child = order[t->child];
						t = t->next;
					}
				}
				
				x++;
				count++;
			}

			return OK;
		}
	}
	
	return ERROR;
}

void LevelOrderTraverse_C(CTree T, void(Visit)(TElemType_C))
{
	int i, count;
	
	count = 0;
	if(T.n)
	{
		count++;
		Visit(T.nodes[T.r].data);
				
		if(T.r)
			i = 0;
		else
			i = 1;
		
		while(count<T.n)
		{
			if(i!=T.r)
			{
				count++;
				Visit(T.nodes[i].data);
			}
			
			i++;
		}
	}

}

void Print_C_1(CTree T)
{
	int row[MAX_TREE_SIZE];						//各结点实际所处行 
	int col[MAX_TREE_SIZE];						//各结点在其兄弟中的次序 
	int i, j;					
	int x[MAX_TREE_SIZE], y[MAX_TREE_SIZE];		//存放各结点打印时所处行和列（从0开始计数） 
	int count_c, count_x;
	char a[MAX_TREE_SIZE][MAX_TREE_SIZE]={};	//按树的形状存放结点 
	SqStack S;
	SElemType_Sq e;
	ChildPtr p, q;
	
	if(T.n)
	{
		InitStack_Sq(&S);
		Push_Sq(&S, T.r);
		count_c = 1;
		count_x = 0;
		
		while(!StackEmpty_Sq(S))
		{
			GetTop_Sq(S, &e);
				
			if(e!=T.r)
				row[e] = row[T.nodes[e].parent] + 1;
			else
				row[e] = 1;
				
			col[e] = count_c;
	
			if(col[e]!=1)
				count_x++;
			x[e] = count_x;
	
			y[e] = row[e] - 1;
			
			a[x[e]][3*y[e]] = T.nodes[e].data;
			
			if(T.nodes[e].firstchild)								//访问孩子 
			{
				Push_Sq(&S, T.nodes[e].firstchild->child);
				count_c = 1;
			}			
			else													//访问兄弟 
			{				
				while(!StackEmpty_Sq(S))
				{
					Pop_Sq(&S, &e);
					
					if(e!=T.r)
					{
						p = NULL;
						q = T.nodes[T.nodes[e].parent].firstchild;
						i = 1;
						while(i<col[e]+1)
						{
							if(p)
								q = p;
							p = q->next;
							i++;
						}
												
						if(p)
						{
							Push_Sq(&S, p->child);
							count_c = col[q->child] + 1;
							break;
						}
					}
				}							
			}
		}
		
		for(i=0; i<=count_x; i++)
		{
			for(j=0; j<=3*(TreeDepth_C_2(T)-1); j++)
			{
				if(a[i][j])
					printf("%c", a[i][j]);
				else
					printf(".");
			}
				
			printf("\n");		
		}				
	}
	else
		printf("空树无法打印！！\n");	
}

void Print_C_2(CTree T, int start, int step)	//打印入口为根结点 
{
	int j;
	ChildPtr p;
	
	if(T.n)
	{
		for(j=1; j<=2*step; j++)				//step初始置为0 
			printf(" ");
		printf(" %c\n", T.nodes[start].data);
	
		if(T.nodes[start].firstchild)			//若有孩子结点，依次打印各孩子 
		{
			for(p=T.nodes[start].firstchild; p; p=p->next)
				Print_C_2(T, p->child, step+1);					
		}
	}
}

void ShowTree_C(CTree T)
{
	int i;
	ChildPtr p;
	
	printf("┏━━━┳━━━┳━━┳━━━━━━━━┓\n");
	printf("┃ order┃parent┃data┃       child    ┃\n");
	printf("┣━━━╋━━━╋━━╋━━━━━━━━…\n");
	for(i=0; i<T.n-1; i++)
	{	
		printf("┃  %2d  ┃  %2d  ", i, T.nodes[i].parent);
		if(T.nodes[i].data)
			printf("┃  %c ", T.nodes[i].data);
		else
			printf("┃  ^ ");
		p = T.nodes[i].firstchild;
		if(p)
			printf("┃─→");
		else
			printf("┃");
		while(p)
		{
			printf(" %2d ", p->child);
			p = p->next;
		}
		printf("\n");
	}
	
	if(T.r>T.n-1)
	{		
		printf("    ┇      ┇     ┇            ┇       \n");
		printf("┃  %2d  ┃  %2d  ", T.r, T.nodes[T.r].parent);
		if(T.nodes[T.r].data)
			printf("┃  %c ", T.nodes[T.r].data);
		else
			printf("┃  ^ ");
		p = T.nodes[T.r].firstchild;
		if(p)
			printf("┃─→");
		else
			printf("┃");
		while(p)
		{
			printf(" %2d ", p->child);
			p = p->next;
		}
		printf("\n");	
	}
	else
	{
		printf("┃  %2d  ┃  %2d  ", i, T.nodes[i].parent);
		if(T.nodes[i].data)
			printf("┃  %c ", T.nodes[i].data);
		else
			printf("┃  ^ ");
		p = T.nodes[i].firstchild;
		if(p)
			printf("┃─→");
		else
			printf("┃");
		while(p)
		{
			printf(" %2d ", p->child);
			p = p->next;
		}
		printf("\n");	
	}
	
	printf("┗━━━┻━━━┻━━┻━━━━━━━━…");
	printf("\n");	
}

#endif

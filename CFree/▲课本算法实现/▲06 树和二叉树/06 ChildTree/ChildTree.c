/****************************************
 *						                *
 * �ļ���: ��06 ���Ͷ�����\06 ChildTree *
 * 						                *
 * �ļ���: ChildTree.c                  *
 *    	    			                *
 ****************************************/
 
#ifndef CHILDTREE_C
#define CHILDTREE_C

#include "ChildTree.h" 								//**06 ���Ͷ�����**//

void InitTree_C(FILE *fp, CTree *T)
{
	int i;
	char tmp;
	
	Scanf(fp, "%d", &i);
	printf("¼��������λ�ã��Ǹ�������%d\n", i);	
	Scanf(fp, "%c", &tmp);							//�����������Ļ��з� 

	if(i<0 || i>MAX_TREE_SIZE-1)
	{
		printf(" i ֵ����\n");
		exit(ERROR);
	}
	
	(*T).r = i;										//����������ڵ�4��λ��
	(*T).n = 0; 
}

void FreeChild_C(ChildPtr *p)						//�������������
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
		
		if(T->r<=T->n-1)								//�����������������һ��
		{				 
			if(T->nodes[i].firstchild)					//��ʱi=T.n-1
				FreeChild_C(&(T->nodes[i].firstchild));								
		}
		else
		{				
			if(T->nodes[T->r].firstchild)				//�ҵ������Ƚ�
				FreeChild_C(&(T->nodes[T->r].firstchild));			
		}		
	
		(*T).n = 0;		
	}
}

void DestroyTree_C(CTree *T)
{
	//�˴洢�ṹ�µ����޷�����
}

Status TreeEmpty_C(CTree T)
{
	return (T.n ? FALSE : TRUE); 
}

Status CreateTree_C(FILE *fp, CTree *T)
{
	TElemType_C ch, tmp;
	int i;				//i��ǵ�ǰ���ĸ����λ�� 
	int j;				//j��ǵ�ǰ���λ�� 
	int k;				//k���i����һ������λ�� 
	ChildPtr p, q;

	Scanf(fp, "%c", &ch);	
	printf("¼�����ġ�����賓����%c\n", ch);
	Scanf(fp, "%c", &tmp);								//�������з� 	

	if(ch!='^')
	{	
		i = (*T).r; 
		(*T).nodes[i].parent = -1;						//ע����������� 
		(*T).nodes[i].data = ch;
		(*T).nodes[i].firstchild = NULL;
		(*T).n++;
		
		if(i!=0)										//�ڶ������ 
			j = 0;
		else
			j = 1;
		
		k = j;
		
		while(!feof(fp))
		{	
			Scanf(fp, "%c", &ch);
			printf("����¼�� %c �ĺ��ӽ�� ��", ch);
			
			p = q = NULL;

			while(1)
			{
				Scanf(fp, "%c", &ch);
				if(ch=='^' || ch=='\n')
				{
					if(ch=='^')
					{
						printf("%c", ch);
						Scanf(fp, "%c", &tmp);			//�������з� 
					}
						
					break;
				}
				else
				{
					printf("%c", ch);
					(*T).nodes[j].parent = i;			//��������			
					(*T).nodes[j].data = ch;				
					(*T).nodes[j].firstchild = NULL;
					(*T).n++;
					
					p = (ChildPtr)malloc(sizeof(CTNode));
					if(!p)
						exit(OVERFLOW);
						
					p->child = j;						//������������ 
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
	int end;							//���һ������λ��
	
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
		while(T.nodes[i].parent!=-1)	//���洢�Ľ��ض�λ��������� 
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
		
		if(T.r<=T.n-1)							//�����������������һ��
		{
			if(T.nodes[i].data==e)				//��ʱi=T.n-1 
				k = i;								
		}
		else
		{
			if(T.nodes[T.r].data==e)			//������Ƚ�	
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
		
		if(i>=0)							//�ҵ���e
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
	
		if(i>=0)										//�ҵ���e
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
		i = Order_C(T, e);								//iΪ���e��λ��	
		
		if(i>=0 && i!=T.r)								//�ҵ���e����e��Ϊ����� 
		{
			k = T.nodes[i].parent;						//�ҵ�e��˫��
			p = T.nodes[k].firstchild;
			
			while(p)
			{
				if(mark==0)								//Ѱ�����ֵ�
				{
					if(p && p->next && p->next->child==i)
						return T.nodes[p->child].data;
				}
				
				if(mark==1)								//Ѱ�����ֵ�
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

int Sibling_C_2(CTree T, int order, int mark)			//������˫����� 
{
	int i;												 //��������⣬������һ�����λ��
	ChildPtr p, q;
	
	if(order==T.r)
		return -1;										//��������ֵ�
	
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
	
	if(T.r>T.n-1)			//���ʸ���� 
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
	else					//�������һ����� 
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
	
	k0 = ChildCount_C(T, p);				//k0Ϊp��㺢���� 
	
	if(k0<0 || i<0 || i>k0+1)				//�ж��Ƿ���Բ��� 
		return -2;

	if(i==0)								//jΪʵ�ʲ������� 
		j = k0 + 1;
	else
		j = i;
	
	k1 = Order_C(T, p);						//p�������е�λ�� 
	
	if(k1==T.r)				//pΪ����� 
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
		
		if(k2==T.n-1)			//��Ȼ�˳� 
		{
			if(T.r==T.n-1)
				k2 = T.n;

			if(T.r<T.n-1)		//��ʱcount�ض�С��j 
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
	
	if(T.n && p!=T.nodes[T.r].data)				//��Ϊ������p��Ϊ�����
	{
		k = T.nodes[Order_C(T, p)].parent;		//p���˫�׽���λ��
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
	
	k = ChildSeat_C(*T, p, i);					//kΪ����λ��
	if(k<0)										//����λ������
		return ERROR;				
	
	if(T->r<=T->n-1)								//�����������������һ��
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
	while(m<T->n-1 || (m==T->n-1 && T->r<=T->n))			//��������������˫�� 
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

	h = (ChildPtr)malloc(sizeof(CTNode));					//������Ľ����뺢�������� 
	h->child = k;

	if(i==0)												//jΪʵ�ʲ������� 
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
			
	InsertChild_C(T, p, i, t.nodes[t.r].data);			//�Ƚ�t�ĸ������뵽T�� 
	
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
	int order[MAX_TREE_SIZE];							//�洢��ǰ����ʵ��λ�� 
	int x, y, new_n, tmp;
	
	k0 = Order_C(*T, p);								//Ѱ��p��λ��
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
			k1 = h->child;								//�ҵ�p�ĵ�i������λ�ã���ɾ����� 		
			
			q = T->nodes[T->nodes[k1].parent].firstchild;
			if(q->child==k1)
			{
				t = q;
				T->nodes[T->nodes[k1].parent].firstchild = t->next;
			}
			else
			{				 
				while(q->next->child!=k1)				//һ�������ҵ�����������q 
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
				T->nodes[e].data = '\0';					//Ĩ���˴���� 
				if(T->nodes[e].firstchild)					//���˽���к��ӽ��
				{
					q = T->nodes[e].firstchild;
					while(q)
					{
						EnQueue_L(&Q, q->child);
						q = q->next;
					}
					FreeChild_C(&(T->nodes[e].firstchild));	//�ͷŴ˽��ĺ������� 
				}
			}
			
			order[T->r] = T->r;
			count = 1;						//��¼���ʹ���Ԫ�ظ��� 
			new_n = 1;						//��¼ʵ��Ԫ�ظ��� 
			
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
			
			while(count<T->n)				//����˫�׽�㼰���ӽ��λ�� 
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
	int row[MAX_TREE_SIZE];						//�����ʵ�������� 
	int col[MAX_TREE_SIZE];						//����������ֵ��еĴ��� 
	int i, j;					
	int x[MAX_TREE_SIZE], y[MAX_TREE_SIZE];		//��Ÿ�����ӡʱ�����к��У���0��ʼ������ 
	int count_c, count_x;
	char a[MAX_TREE_SIZE][MAX_TREE_SIZE]={};	//��������״��Ž�� 
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
			
			if(T.nodes[e].firstchild)								//���ʺ��� 
			{
				Push_Sq(&S, T.nodes[e].firstchild->child);
				count_c = 1;
			}			
			else													//�����ֵ� 
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
		printf("�����޷���ӡ����\n");	
}

void Print_C_2(CTree T, int start, int step)	//��ӡ���Ϊ����� 
{
	int j;
	ChildPtr p;
	
	if(T.n)
	{
		for(j=1; j<=2*step; j++)				//step��ʼ��Ϊ0 
			printf(" ");
		printf(" %c\n", T.nodes[start].data);
	
		if(T.nodes[start].firstchild)			//���к��ӽ�㣬���δ�ӡ������ 
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
	
	printf("���������ש������ש����ש�����������������\n");
	printf("�� order��parent��data��       child    ��\n");
	printf("�ǩ������贈�����贈���贈����������������\n");
	for(i=0; i<T.n-1; i++)
	{	
		printf("��  %2d  ��  %2d  ", i, T.nodes[i].parent);
		if(T.nodes[i].data)
			printf("��  %c ", T.nodes[i].data);
		else
			printf("��  ^ ");
		p = T.nodes[i].firstchild;
		if(p)
			printf("������");
		else
			printf("��");
		while(p)
		{
			printf(" %2d ", p->child);
			p = p->next;
		}
		printf("\n");
	}
	
	if(T.r>T.n-1)
	{		
		printf("    ��      ��     ��            ��       \n");
		printf("��  %2d  ��  %2d  ", T.r, T.nodes[T.r].parent);
		if(T.nodes[T.r].data)
			printf("��  %c ", T.nodes[T.r].data);
		else
			printf("��  ^ ");
		p = T.nodes[T.r].firstchild;
		if(p)
			printf("������");
		else
			printf("��");
		while(p)
		{
			printf(" %2d ", p->child);
			p = p->next;
		}
		printf("\n");	
	}
	else
	{
		printf("��  %2d  ��  %2d  ", i, T.nodes[i].parent);
		if(T.nodes[i].data)
			printf("��  %c ", T.nodes[i].data);
		else
			printf("��  ^ ");
		p = T.nodes[i].firstchild;
		if(p)
			printf("������");
		else
			printf("��");
		while(p)
		{
			printf(" %2d ", p->child);
			p = p->next;
		}
		printf("\n");	
	}
	
	printf("���������ߩ������ߩ����ߩ�����������������");
	printf("\n");	
}

#endif

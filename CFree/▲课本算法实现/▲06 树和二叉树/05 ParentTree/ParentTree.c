/*****************************************
 *						                 *
 * �ļ���: ��06 ���Ͷ�����\05 ParentTree *
 *						                 *
 * �ļ���: ParentTree.c                  *
 *						                 *
 *****************************************/

#ifndef PARENTTREE_C
#define PARENTTREE_C

#include "ParentTree.h" 							//**��06 ���Ͷ�����**//

void InitTree_P(PTree *T)
{
	(*T).n = 0;										//������� 
}

void ClearTree_P(PTree *T)
{
	(*T).n = 0;
}

void DestroyTree_P(PTree *T)
{
	//�˴洢�ṹ�µ����޷����� 
} 

Status TreeEmpty_P(PTree T)
{
	return (T.n ? FALSE : TRUE); 
} 

Status CreateTree_P(FILE *fp, PTree *T)
{
	TElemType_P ch, p, tmp;
	int i, j;
	
	Scanf(fp, "%c", &ch);
	printf("¼�����ĸ���� %c \n", ch);
	Scanf(fp, "%c", &tmp);							//�������з� 
	
	if(ch!='^')
	{
		i = 0;										//����������Ϊ0
		(*T).nodes[i].data = ch;
		(*T).nodes[i].parent = -1;
		
		j = -1;
		while(!feof(fp))
		{
			Scanf(fp, "%c", &p);
			printf("����¼�� %c �ĺ��ӽ�㣺", p);
			j++;
			while(1)
			{
				Scanf(fp, "%c", &ch);
				if(ch=='^' || ch=='\n')
				{
					if(ch=='^')
					{
						printf("%c", ch);
						Scanf(fp, "%c", &tmp);		//�������з� 
					}
						
					break;
				}
				else
				{
					printf("%c", ch);
					i++;
					(*T).nodes[i].data = ch;
					(*T).nodes[i].parent = j;
				}
			}
			
			printf("\n");
		}
		
		(*T).n = i+1;		
	}
		
	return OK;
}

int TreeDegree_P(PTree T)
{
	int i, tmp, count;
	int max;
	
	max = count = 0;
	
	if(T.n)
	{
		tmp = T.nodes[0].parent;
		
		for(i=0; i<T.n; i++)
		{
			if(T.nodes[i].parent!=tmp)
			{
				tmp = T.nodes[i].parent;
				count = 1;			
			}
			else
				count++;
			
			if(count>max)
				max = count;
		}		
	}
	
	return max;
}

int TreeDepth_P(PTree T)										//���ڰ��������д洢�������洢�Ľ��������� 
{
	int k, level;
	
	k = T.n-1;
	level = 0;
	
	if(T.n!=0)
	{
		level++;
		k = T.nodes[k].parent;
		
		while(k!=-1)
		{
			level++;
			k = T.nodes[k].parent;
		}
		
	}
	
	return level; 
}

TElemType_P Root_P(PTree T)
{
	if(T.n)
		return T.nodes[0].data;

	return '\0';
}

TElemType_P Value_P(PTree T, int i)
{
	if(T.n && i>0 && i<=T.n)
		return T.nodes[i-1].data;
	else
		return '\0';
}

int Order_P(PTree T, TElemType_P e)
{
	int i;
	int k = -1;
	
	for(i=0; i<T.n; i++)
	{
		if(T.nodes[i].data==e)
		{
			k = i;
			break;
		}
	}
	
	return k;
} 

Status Assign_P(PTree *T, TElemType_P e, TElemType_P value)
{
	int i;
	
	for(i=0; i<(*T).n; i++)
	{
		if((*T).nodes[i].data==e)
		{
			(*T).nodes[i].data = value;
			return OK;
		}
	}
	
	return ERROR;
}

TElemType_P ChildValue_P(PTree T, TElemType_P e, int order)
{
	int i, p, count;
	
	count = 0;
	for(i=1; i<T.n; i++)
	{
		p = T.nodes[i].parent;
		if(T.nodes[p].data==e)
		{
			count++;
			if(count==order)
				return T.nodes[i].data;
		}
	}
	
	return '\0';
}

TElemType_P Sibling_P(PTree T, TElemType_P e, int mark)
{
	int i;
	
	if(!TreeEmpty_P(T) && e!=T.nodes[0].data)
	{
		for(i=1; i<T.n; i++)
		{
			if(mark==0)										//���ֵ�
			{
				if(T.nodes[i].data==e)
					break;

				if(T.nodes[i].data!=e && i+1<T.n && T.nodes[i+1].parent==T.nodes[i].parent && T.nodes[i+1].data==e)
					return T.nodes[i].data;
			}
			
			if(mark==1)										//���ֵ� 
			{
				if(T.nodes[i].data==e && i+1<T.n && T.nodes[i].parent==T.nodes[i+1].parent)
					return T.nodes[i+1].data;	
			} 
		}	
	}

	
	return '\0';
}

int ChildCount_P(PTree T, TElemType_P p)
{
	int k1, k2, count;
	
	if(TreeEmpty_P(T))						//���� 
		return -1;

	k1 = Order_P(T, p);
	
	if(k1<0)								//p��㲻���� 
		return -2;
	
	k2 = k1 + 1;
	count = 0;
	while(k2<T.n)							//ͳ�ƺ��Ӹ��� 
	{
		if(T.nodes[k2].parent==k1)
			count++;
		if(T.nodes[k2].parent>k1)
			break;
		k2++;
	}

	return count;
}

int ChildSeat_P(PTree T, TElemType_P p, int i)
{
	int k0, k1, k2, count;
	
	if(TreeEmpty_P(T))							//���� 
		return -1;
	
	k0 = ChildCount_P(T, p);		//k0��Ǻ��Ӹ��� 
	
	if(i<0 || k0<0 || i>k0+1)		//����λ�ò���ȷ 
		return -2;
	
	k1 = Order_P(T, p);

	k2 = k1 + 1;	
	if(i==0)						//��ʱiΪp���һ��������һ��λ��
	{
		while(k2<T.n)
		{
			if(T.nodes[k2].parent>k1)
				break;
			k2++;
		}
	} 
	else
	{
		count = 0;
		
		while(k2<T.n)
		{
			if(T.nodes[k2].parent>=k1)
			{
				count++;
				if(count==i)
					break;
			}
			
			k2++;
		}
	}

	return k2;	
}

Status InsertChild_P(PTree *T, TElemType_P p, int i, TElemType_P e)
{
	int k0, start, end;
	
	if(TreeEmpty_P((*T)) || !e)				//������eΪ���ַ� 
		return ERROR;

	k0 = 0;									//k0���p��λ�� 
	while(k0<(*T).n)
	{
		if((*T).nodes[k0].data==p)
			break;
		k0++;
	}	
	
	if(k0==(*T).n)							//p������ 
		return ERROR;
	
	start = ChildSeat_P(*T, p, i);			//e���Ĳ���λ�� 
	if(start<=0)							//����λ�ò���ȷ 
		return ERROR;
	
	end = (*T).n;
	while(end>start)
	{
		(*T).nodes[end].data = (*T).nodes[end-1].data;
		if((*T).nodes[end-1].parent<start)
			(*T).nodes[end].parent = (*T).nodes[end-1].parent;
		else
			(*T).nodes[end].parent = (*T).nodes[end-1].parent+1;
		end--;
	}
	
	(*T).nodes[start].data = e;
	(*T).nodes[start].parent = k0;
	(*T).n++;
	
	return OK;
}

Status InsertTree_P(PTree *T, TElemType_P p, int i, PTree t)
{
	int k;
	
	if(TreeEmpty_P((*T)) || TreeEmpty_P(t))				//���� 
		return ERROR;

	for(k=0; k<t.n; k++)
	{
		if(k==0)
			InsertChild_P(T, p, i, t.nodes[k].data);
		else
			InsertChild_P(T, t.nodes[t.nodes[k].parent].data, 0, t.nodes[k].data);
	}

	return OK; 
}

Status DeleteTree_P(PTree *T, TElemType_P p, int i)
{
	int k1;											//k1���p��λ�� 
	int k2 , count;									//k2��ǵ�i��������� 
	int k3;
	int stack[MAX_TREE_SIZE], m, n;
	int k4, k5, order[MAX_TREE_SIZE] = {};
	
	for(k1=0; k1<(*T).n; k1++)
	{
		if((*T).nodes[k1].data==p)
			break;
		if(k1==(*T).n-1)
			return ERROR;		
	}
	
	count = 0;		
	for(k2=k1+1; k2<(*T).n; k2++)
	{
		if((*T).nodes[k2].parent==k1)
		{
			count++;
			if(count==i)
				break;
		}
		if(k2==(*T).n-1)
			return ERROR;		
	}
	
	m = n = 0;
	stack[n] = k2;
	n++; 
	(*T).nodes[k2].data = '\0';					//Ĩ���˴���ֵ
	
	k3=k2+1;
	while(k3<(*T).n && m<n)
	{		
		if((*T).nodes[k3].parent<stack[m])
			k3++;
		else if((*T).nodes[k3].parent>stack[m])
			m++;
		else		//(*T).nodes[k3].parent==stack[m]
		{
			(*T).nodes[k3].data = '\0';					//Ĩ���˴���ֵ
			stack[n] = k3;
			n++;
			k3++;
		}		
	}
	
	k5 = 0;
	for(k4=0; k4<(*T).n; k4++)							//���������ҳ���������ڵ�ʵ��λ�� 
	{
		if((*T).nodes[k4].data)
		{
			order[k4] = k5;
			k5++;
			
			if(k4)										//��Ϊͷ��� 
				(*T).nodes[k4].parent = order[(*T).nodes[k4].parent];	//��ǰ���˫�׽��λ�÷����仯 
		}
	}
	
	k4 = -1;
	k5 = 0;
	while(k5<(*T).n)										//������ȥ��ɾ���Ľ�� 
	{
		if((*T).nodes[k5].data)
		{
			k4++;
			(*T).nodes[k4].data = (*T).nodes[k5].data;
			(*T).nodes[k4].parent = (*T).nodes[k5].parent;
		}
		
		k5++;
	}
		
	(*T).n = k4+1;
	
	return OK; 
}

void LevelOrderTraverse_P(PTree T, void(Visit)(TElemType_P))
{
	int i;
	
	for(i=0; i<T.n; i++)
		Visit(T.nodes[i].data);
}

void Print_P(PTree T)
{
	int row[MAX_TREE_SIZE];						//�����ʵ�������� 
	int col[MAX_TREE_SIZE];						//����������ֵ��еĴ��� 
	int i, j, tmp;								//tmp��ŵ�ǰ���ĸ����λ�� 
	int x[MAX_TREE_SIZE], y[MAX_TREE_SIZE];		//��Ÿ�����ӡʱ�����к��У���0��ʼ������ 
	int count;
	int t[MAX_TREE_SIZE][MAX_TREE_SIZE]={};		//��������洢�ṹ 
	char a[MAX_TREE_SIZE][MAX_TREE_SIZE]={};	//��������״��Ž�� 
	SqStack S;
	SElemType_Sq e;

	if(T.n)
	{	
		j = 1;								//jͳ��ĳ���Ӵ��� 
		row[0] = 1;
		col[0] = j;
		tmp = T.nodes[0].parent;
				
		for(i=1; i<T.n; i++) 
		{
			if(T.nodes[i].parent!=tmp)
			{
				j = 1;							//������һ����㲻����ͬһ˫�׽�㣬�����¿�ʼ���� 
				tmp = T.nodes[i].parent;
			}
			else
				j++;
			
			col[i] = j;	
			row[i] = row[T.nodes[i].parent]+1;				
		}	
		
		for(i=1; i<T.n; i++)									//���캢������ 
		{
			tmp = T.nodes[i].parent;
			t[tmp][col[i]-1] = i;
		}
		
		count = 0;												//׷���� 
		InitStack_Sq(&S);
		Push_Sq(&S, 0);
		while(!StackEmpty_Sq(S))									//ȷ��ÿ�����������������				
		{
			GetTop_Sq(S, &e);
			if(col[e]!=1)
				count++;
			x[e] = count;

			if(t[e][0])
				Push_Sq(&S, t[e][0]);			
			else
			{
				while(!StackEmpty_Sq(S))
				{
					Pop_Sq(&S, &e);
					if(t[T.nodes[e].parent][col[e]])
					{
						Push_Sq(&S, t[T.nodes[e].parent][col[e]]);
						break;
					}
				}
			}
			
		}

		for(i=0; i<T.n; i++)										//ȷ��ÿ����������������� 
			y[i] = row[i]-1;

		for(i=0; i<T.n; i++)										//����������a���ʵ�λ�� 
			a[x[i]][2*y[i]] = T.nodes[i].data;
					
		for(i=0; i<=count; i++)
		{
			for(j=0; j<=2*y[T.n-1]; j++)
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

#endif

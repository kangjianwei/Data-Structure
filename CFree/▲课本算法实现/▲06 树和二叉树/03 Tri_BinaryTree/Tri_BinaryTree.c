/*********************************************
 * 							                 *
 * 文件夹: ▲06 树和二叉树\03 Tri_BinaryTree *
 * 							                 *
 * 文件名: Tri_BinaryTree.c                  *
 * 							                 *
 *********************************************/

#ifndef TRI_BINARYTREE_C
#define TRI_BINARYTREE_C

#include "Tri_BinaryTree.h" 						//**▲06 树和二叉树**//

void InitBiTree_Tri(TBiTree *T)
{
	*T = NULL;
}

void ClearBiTree_Tri(TBiTree *T)
{
	if(*T)
	{
		if((*T)->lchild)										//清空左树 
			ClearBiTree_Tri(&((*T)->lchild));							
		if((*T)->rchild)										//清空右树 
			ClearBiTree_Tri(&((*T)->rchild));
	
		free(*T);
		
		*T = NULL;
	}
}

void DestroyBiTree_Tri(TBiTree *T)
{
	//二叉树无法销毁
}

Status BiTreeEmpty_Tri(TBiTree T)
{
	return T==NULL ? TRUE : ERROR;
}

void Create_Tri(TBiTree *T, FILE *fp)
{
	TElemType_Tri ch;

	Scanf(fp, "%c", &ch);
	
	if(ch=='^')
		*T = NULL;
	else
	{
		*T = (TBiTree)malloc(sizeof(TBiTNode));
		if(!(*T))
			exit(OVERFLOW);
		(*T)->data = ch;
		Create_Tri(&(*T)->lchild, fp);
		Create_Tri(&(*T)->rchild, fp);
	}
} 

Status CreateBiTree_Tri(FILE *fp, TBiTree *T)					//先建树，后设置双亲结点信息 
{
	LinkQueue Q;
	QElemType_L e;
	
	Create_Tri(T, fp);
	
	if(*T)
	{
		(*T)->parent = NULL;		
		InitQueue_L(&Q);
		EnQueue_L(&Q, *T);
		
		while(!QueueEmpty_L(Q))
		{
			DeQueue_L(&Q, &e);
			
			if(e->lchild)
			{
				e->lchild->parent = e;
         		EnQueue_L(&Q, e->lchild);
			}
			
			if(e->rchild)
			{
				e->rchild->parent = e;
         		EnQueue_L(&Q, e->rchild);
			}
		}
	}
	
	return OK;
}

int BiTreeLength_Tri(TBiTree T)
{
	LinkQueue Q;
	QElemType_L e;
	int a[100] = {};
	int i, j;
	
	i = -1;
	j = 0;
	
	if(T)
	{
		InitQueue_L(&Q);
		EnQueue_L(&Q, T);
		a[j++] = 1;
		
		while(!QueueEmpty_L(Q))
		{
			DeQueue_L(&Q, &e);
			i++;
					
			if(e->lchild)
			{
				EnQueue_L(&Q, e->lchild);
				a[j++] = 2*a[i];
			}
			
			if(e->rchild)
			{
				EnQueue_L(&Q, e->rchild);
				a[j++] = 2*a[i]+1;
			}	
		}
	}
	
	if(j)
		return a[j-1];
	else
		return 0;
}

int BiTreeDepth_Tri(TBiTree T)
{
	int i = 0;
	double j;
	
	if(BiTreeLength_Tri(T))
	{
		j = log(BiTreeLength_Tri(T))/log(2);

		i = j + 1;	
	}
	
	return i;
}

Status Root_Tri(TBiTree T, TElemType_Tri *e)
{
	if(!T)
		return ERROR;
	else
	{
		*e = T->data;
		return OK;
	}
}

TElemType_Tri Value_Tri(TBiTree p)
{
	return p->data;
}

void Assign_Tri(TBiTree p, TElemType_Tri value)
{
	p->data = value;
}

TBiTree Point(TBiTree T, TElemType_Tri e)
{
	LinkQueue Q;
	QElemType_L x;
	
	if(T)
	{
		InitQueue_L(&Q);
		EnQueue_L(&Q, T);
		
		while(!QueueEmpty_L(Q))
		{
			DeQueue_L(&Q, &x);
			
			if(x->data==e)
				return x;
							
			if(x->lchild)
				EnQueue_L(&Q, x->lchild);
			
			if(x->rchild)
				EnQueue_L(&Q, x->rchild);
		}
	}
	
	return NULL;
} 

TElemType_Tri Parent_Tri(TBiTree T, TElemType_Tri e)
{
	TBiTree p;
	
	p = Point(T, e);
	
	if(p && p!=T)
		return p->parent->data;
	else
		return '\0';
}

TElemType_Tri LeftChild_Tri(TBiTree T, TElemType_Tri e)
{
	TBiTree p;
	
	p = Point(T, e);
	
	if(p && p->lchild)
		return p->lchild->data;
	else
		return '\0';
}

TElemType_Tri RightChild_Tri(TBiTree T, TElemType_Tri e)
{
	TBiTree p;
	
	p = Point(T, e);
	
	if(p && p->rchild)
		return p->rchild->data;
	else
		return '\0';	
}

TElemType_Tri LeftSibling_Tri(TBiTree T, TElemType_Tri e)
{
	TBiTree p;
	
	p = Point(T, e);
	
	if(p && p->parent->lchild && p->parent->lchild->data!=e)
		return p->parent->lchild->data;
	else
		return '\0';	
}

TElemType_Tri RightSibling_Tri(TBiTree T, TElemType_Tri e)
{
	TBiTree p;
	
	p = Point(T, e);
	
	if(p && p->parent->rchild && p->parent->rchild->data!=e)
		return p->parent->rchild->data;
	else
		return '\0';	
}

Status InsertBiTree_Tri(TBiTree T, TElemType_Tri e, TBiTree *T0, int LR)
{
	TBiTree p = Point(T, e);
	
	if(p)
	{
		if(LR==0)											//插入为左子树
		{
			(*T0)->rchild = p->lchild;
			p->lchild->parent = *T0;
			(*T0)->parent = p;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
			p->lchild = *T0;		
		} 
		else												//插入为右子树 
		{
			(*T0)->rchild = p->rchild;
			p->rchild->parent = *T0;
			(*T0)->parent = p;
			p->rchild = *T0;
		}
		
		return OK;
	}
	
	return ERROR;
}

Status DeleteBiTree_Tri(TBiTree T, TElemType_Tri e, int LR)
{
	TBiTree p = Point(T, e);
	
	if(p)
	{
		LR ? ClearBiTree_Tri(&(p->rchild)) : ClearBiTree_Tri(&(p->lchild));
		
		return OK;
	}
	
	return ERROR;
}

void LevelOrderTraverse_Tri(TBiTree T, void(Visit)(TElemType_Tri))
{
	LinkQueue Q;
	QElemType_L e;
	
	if(T)
	{
		InitQueue_L(&Q);
		EnQueue_L(&Q, T);
		
		while(!QueueEmpty_L(Q))
		{
			DeQueue_L(&Q, &e);
			Visit(e->data);
			
			if(e->lchild)
				EnQueue_L(&Q, e->lchild);
			
			if(e->rchild)
				EnQueue_L(&Q, e->rchild);
		}
	}	
}

void PreOrderTraverse_Tri(TBiTree T, void(Visit)(TElemType_Tri))
{
	if(T)
	{
		Visit(T->data);
		PreOrderTraverse_Tri(T->lchild, Visit);
		PreOrderTraverse_Tri(T->rchild, Visit);
	}
}

void InOrderTraverse_Tri(TBiTree T, void(Visit)(TElemType_Tri))
{
	if(T)
	{
		InOrderTraverse_Tri(T->lchild, Visit);
		Visit(T->data);
		InOrderTraverse_Tri(T->rchild, Visit);
	}
}

void PostOrderTraverse_Tri(TBiTree T, void(Visit)(TElemType_Tri))
{
	if(T)
	{
		PostOrderTraverse_Tri(T->lchild, Visit);
		PostOrderTraverse_Tri(T->rchild, Visit);
		Visit(T->data);
	}
}


void Print_Tri(TBiTree T)
{
	struct
	{
		TElemType_Tri c;
		int t;
	}node[100] = {};
	LinkQueue Q;
	QElemType_L e;	
	int i, j, m, n, row, col, max, x, y;
	double tmp;
	TElemType_Tri a[100][100] = {};

	i = -1;
	j = 0;
	
	if(T)
	{
		InitQueue_L(&Q);
		EnQueue_L(&Q, T);
		node[j].c = T->data;
		node[j].t = 1;
		j++;
		
		while(!QueueEmpty_L(Q))
		{
			DeQueue_L(&Q, &e);
			i++;
					
			if(e->lchild)
			{
				EnQueue_L(&Q, e->lchild);
				node[j].c = e->lchild->data;
				node[j].t = 2*node[i].t;
				j++;
			}
			
			if(e->rchild)
			{
				EnQueue_L(&Q, e->rchild);
				node[j].c = e->rchild->data;
				node[j].t = 2*node[i].t+1;
				j++;
			}	
		}
	}
	
	if(j)
	{
		tmp = log(node[j-1].t)/log(2) + 1;
		row = (int)tmp;							//二叉树层数（放入二维数组后占的行数） 
		max = (int)pow(2, row-1);				//二叉树最后一层最大元素个数
		col = 2*max-1;							//放入二维数组后占的列数
		
		for(i=0; i<j; i++)						//遍历结构node 
		{
			tmp = log(node[i].t)/log(2)+1;		
			x = (int)tmp;							//当前结点所在层
			y = node[i].t-(int)pow(2, x-1)+1;		//当前结点所在列（按完全二叉树计算） 
			
			if(x==1)
				a[x-1][max/(int)pow(2, x-1)-1] = node[i].c;
			else
				a[x-1][max/(int)pow(2, x-1)+(y-1)*(max/(int)pow(2, x-2))-1] = node[i].c;
		}
		
		for(m=0; m<row; m++)
		{
			for(n=0; n<col; n++)
			{
				if(a[m][n]!='\0')
					printf("%c", a[m][n]);
				else
					printf(" ");
			}
		
			printf("\n");
		}	
	}

}

#endif

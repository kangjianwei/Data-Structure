#include <stdio.h>
#include <stdlib.h>										//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/02 BinaryTree/BinaryTree.c" //**▲06 数和二叉树**//

/* 函数原型 */
Status Algo_6_41(BiTree T, TElemType *e, int *order, int k);
int Algo_6_42(BiTree T);
void Algo_6_43(BiTree T);
int Algo_6_44(BiTree T, TElemType x);
void Algo_6_45(BiTree *T, TElemType x);
void Algo_6_46(BiTree T, BiTree *Tx);
void Algo_6_47(BiTree T);
BiTree Algo_6_48(BiTree T, TElemType p, TElemType q);
Status FindPath_6_48(BiTree T, TElemType p, BiTree path[100]);
Status Algo_6_49(BiTree T);

int main(int argc, char *argv[])
{ 
	BiTree T, Tx, Tmp;
	TElemType e;
	int k, order;								//order为计数起点									 
	char x;
	FILE *fp;
	int mark;									//验证标记
		
	printf("创建二叉树（先序序列）T→ ABDG^^^EH^^I^^CF^J^^^...\n");
	InitBiTree(&T); 
	fp = fopen("Data/Algo_6_41-6_49.txt", "r");
	CreateBiTree(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("二叉树T为：\n");
	PrintTree(T);
	printf("\n");

	printf("验证题 6.41 - 6.49 分别输入 1 - 9：");
	fflush(stdin);
	scanf("%d", &mark);
	printf("\n");
	
	if(mark==1)
	{
		printf("███ 题 6.41 验证... ███\n");
		while(1)
		{
			printf("请输入k值（0退出验证）： ");
			fflush(stdin);
			scanf("%d", &k);
	
			order = 0;									//从0开始计数 
			
			if(k==0)
				break;
			else
			{
				if(Algo_6_41(T, &e, &order, k))
					printf("先序序列中第 %d 个元素为 %c \n", k, e);		
				else
					printf("此处元素不存在！\n");
				printf("\n");		
			}
		}
	}
	
	if(mark==2)
	{
		printf("███ 题 6.42 验证... ███\n");
		printf("二叉树的叶子结点个数为： %d。\n", Algo_6_42(T));	
	}	
	
	if(mark==3)
	{
		printf("███ 题 6.43 验证... ███\n");
		printf("交换二叉树左右子树后二叉树变为：\n");
		Algo_6_43(T); 
		PrintTree(T);
	}
	
	if(mark==4)
	{
		printf("███ 题 6.44 验证... ███\n");
		while(1)
		{
			printf("请输入某子树的根结点 'x'（0退出验证）：");
			fflush(stdin);
			scanf("%c", &x);
			
			if(x=='0')
				break;
			
			printf("子树 %c 的深度为： %d\n", x, Algo_6_44(T, x));
			printf("\n");	
		}
	}
	
	if(mark==5)
	{
		printf("███ 题 6.45 验证... ███\n");
		printf("请输入树中某个结点 'x'：");
		fflush(stdin);
		scanf("%c", &x);
		printf("\n");
		
		printf("删除子树 %c 后，二叉树为：\n", x);
		Algo_6_45(&T, x); 
		PrintTree(T);			
	}
	
	if(mark==6)
	{
		printf("███ 题 6.46 验证... ███\n");
		printf("复制 T 到 Tx 后，二叉树Tx为：\n");
		Algo_6_46(T, &Tx); 
		PrintTree(Tx);			
	}
	
	if(mark==7)
	{
		printf("███ 题 6.47 验证... ███\n");
		printf("二叉树层序遍历序列为：");  
		Algo_6_47(T);
		printf("\n");			
	}
	
	if(mark==8)
	{
		printf("███ 题 6.48 验证... ███\n");
		Tmp = Algo_6_48(T, 'G', 'H');
		printf("'%c' 和 '%c' 的最近共同祖先为：'%c'\n", 'G', 'H', Tmp->data);	
	}
	
	if(mark==9)
	{
		printf("███ 题 6.49 验证... ███\n");
		printf("此二叉树");
		Algo_6_49(T) ? printf("是") : printf("不是");
		printf("完全二叉树！\n");	
	}
			
	printf("\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━━━━┓
┃题6.41：求先序序列中第k个结点的值 ┃
┗━━━━━━━━━━━━━━━━━*/
Status Algo_6_41(BiTree T, TElemType *e, int *order, int k)	//order用来计数 
{
	if(T)
	{
		(*order)++;
		
		if(*order==k)
		{
			*e = T->data;		
			return OK;					
		}
		else
		{		
			if(Algo_6_41(T->lchild, e, order, k))
				return OK;
			if(Algo_6_41(T->rchild, e, order, k))
				return OK;
		}
	}
	
	return ERROR;
}

/*━━━━━━━━━━━━━━━━┓
┃题6.42：计算二叉树中叶子结点数目┃
┗━━━━━━━━━━━━━━━━*/
int Algo_6_42(BiTree T)
{
	int count = 0;
	
	if(T)
	{
		if(T->lchild==NULL && T->rchild==NULL)
			count++;
		else
		{
			count += Algo_6_42(T->lchild);
			count += Algo_6_42(T->rchild);
		}	
	}
	
	return count;	 
}

/*━━━━━━━━━━━━━━┓
┃题6.43：交换二叉树的左右子树┃
┗━━━━━━━━━━━━━━*/
void Algo_6_43(BiTree T)
{
	BiTree p;
	
	if(T)
	{
		p = T->lchild;
		T->lchild = T->rchild;
		T->rchild = p;

		Algo_6_43(T->lchild);
		Algo_6_43(T->rchild);
	}
}

/*━━━━━━━━━━━━━━━━━━━━━━┓
┃题6.44：求二叉树中以结点'x'为根的子树的深度 ┃
┗━━━━━━━━━━━━━━━━━━━━━━*/
int Algo_6_44(BiTree T, TElemType x)
{
	 BiTree p;
	 
	 p = LocationBiTree_2(T, x);			//第一个递归求出x的位置，以指针形式返回
	 
	 return BiTreeDepth(p);				//第二个递归求出子树x的深度 
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题6.45：删除元素值为'x'的结点（可能不止一个）及其子树 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
void Algo_6_45(BiTree *T, TElemType x)
{
	if(*T)
	{
		if((*T)->data==x)
			ClearBiTree(T);						//递归清空子树 
		else
		{
			Algo_6_45(&((*T)->lchild), x);		//递归向左右子树寻找 
			Algo_6_45(&((*T)->rchild), x);
		}
	}
}

/*━━━━━━━━━━━━━━━┓
┃题6.46：复制二叉树的非递归算法┃
┗━━━━━━━━━━━━━━━*/
void Algo_6_46(BiTree T, BiTree *Tx)
{
	SqStack ST, STx;
	SElemType_Sq e;
	BiTree p, q;
	 
	if(!BiTreeEmpty(T))
	{
		InitStack_Sq(&ST);
		InitStack_Sq(&STx);
		
		Push_Sq(&ST, T);
		p = (BiTree)malloc(sizeof(BiTNode));
		if(!p)
			exit(OVERFLOW);
		p->data = T->data;
		*Tx = p;
		Push_Sq(&STx, *Tx);
		
		while(!StackEmpty_Sq(ST))
		{
			GetTop_Sq(ST, &e);
			GetTop_Sq(STx, &q);
			
			if(e->lchild)								//向左访问 
			{
				Push_Sq(&ST, e->lchild);
				p = (BiTree)malloc(sizeof(BiTNode));
				if(!p)
					exit(OVERFLOW);
				p->data = e->lchild->data;
				q->lchild = p;
				Push_Sq(&STx, q->lchild);			
			}
			else										//向右访问并回退 
			{
				q->lchild = NULL;
				while(!StackEmpty_Sq(ST))
				{
					Pop_Sq(&ST, &e);
					Pop_Sq(&STx, &q);
										
					if(e->rchild)
					{	
						Push_Sq(&ST, e->rchild);
						p = (BiTree)malloc(sizeof(BiTNode));
						if(!p)
							exit(OVERFLOW);
						p->data = e->rchild->data;
						q->rchild = p;
						Push_Sq(&STx, q->rchild);						
						break;					
					}
					else
						q->rchild = NULL;				
				}
			}
		}
	}
}

/*━━━━━━━━━━━┓
┃题6.47：层序遍历二叉树┃
┗━━━━━━━━━━━*/
void Algo_6_47(BiTree T)
{
	int i, j;
	BiTree p[100];					//树指针数组，用来模拟队列 
	
	i = j = 0;
	
	if(T)
		p[j++] = T;
		
	while(i<j)
	{
		printf("%c ", p[i]->data);
		if(p[i]->lchild)
			p[j++] = p[i]->lchild;
		if(p[i]->rchild)
			p[j++] = p[i]->rchild;
		i++;		
	}
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃遍历树寻找根结点到p结点的路径，path存储路径上各结点指针 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
Status FindPath_6_48(BiTree T, TElemType p, BiTree path[100])
{
	BiTNode node[100];
	int i = 0;
	
	if(T==NULL)
		return ERROR;
	
	path[i] = T;
	node[i] = *T;
		
	while(i>=0)
	{
		while(node[i].lchild || path[i]->data==p)
		{
			if(path[i]->data==p)						//寻路成功 
				return OK;
			else
			{
				path[i+1] = node[i].lchild;
				node[i+1] = *(node[i].lchild);
				node[i].lchild = NULL;
				i++;			
			}
		}
		
		if(node[i].rchild)
		{
			path[i+1] = node[i].rchild;
			node[i+1] = *(node[i].rchild);
			node[i].rchild = NULL;
			i++;
		}
		else
		{
			path[i] = NULL;
			i--;
		}		
	}
	
	if(i<0)												//寻路失败 
		return ERROR;
}

/*━━━━━━━━━━━━━┓
┃题6.48：求两结点的共同祖先┃
┗━━━━━━━━━━━━━*/
BiTree Algo_6_48(BiTree T, TElemType p, TElemType q)		//p、q设为具体的元素，原理不变 
{
	BiTree path_1[100] = {};
	BiTree path_2[100] = {}; 
	int k, x;
	
	if(FindPath_6_48(T, p, path_1) && FindPath_6_48(T, q, path_2))	//借助于路径寻找函数 
	{	
		k = 0;
		if(path_1[k]->data!=p && path_2[k]->data!=q)
		{
			while(path_1[k]->data==path_2[k]->data)
				k++;
			
			return path_1[k-1];		
		}
	}

	return NULL;
}

/*━━━━━━━━━━━━━━━━━┓
┃题6.49：判断二叉树是否为完全二叉树┃
┗━━━━━━━━━━━━━━━━━*/
Status Algo_6_49(BiTree T)
{
	int i, j;
	BiTree p[100] = {};					//树指针数组，模拟队列 
	int order[100] = {}; 
	
	i = j = 0;
	
	if(T)								//遍历的同时为各结点编号 
	{
		p[j] = T;	
		order[j] = 1;
		j++;
		
		while(i<j)
		{
			if(i>0 && order[i]>order[i-1]+1)
				return ERROR;			//若结点序号不连续，则非完全二叉树 
				
			if(p[i]->lchild)
			{
				p[j] = p[i]->lchild;
				order[j] = 2*order[i];
				j++;			
			}

			if(p[i]->rchild)
			{
				p[j] = p[i]->rchild;
				order[j] = 2*order[i]+1;
				j++;
			}
			
			i++;		
		}
	}
	
	return OK;
} 

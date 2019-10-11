#include <stdio.h>
#include <stdlib.h>
#include "../../../▲课本算法实现/▲09 查找/06 BinarySortTree/BinarySortTree.c" //**▲09 查找**// 

/*宏定义*/
#define Max 15							//查找表中元素个数

/* 类型定义 */
enum {Link, Thread};					//线索标记，Link：孩子；Thread：线索 
typedef BSTree ThrBSTree;				//线索二叉排序树

/*全局变量*/
ThrBSTree pre;							//指向当前结点前驱 
ThrBSTree parent;						//指向当前结点的双亲结点 

/* 函数原型 */
void Algo_9_35(ThrBSTree Thrt, int a, int b);
Status Algo_9_36(ThrBSTree Thrt, BSTElemType e);
Status Algo_9_37(ThrBSTree Thrt, KeyType key);
void Create_Thr(ThrBSTree *Thrt, ThrBSTree TBST);
void InOrder_Sub_Thr(ThrBSTree p);
void Print_InOrder(ThrBSTree Thrt);
Status SearchThr_9_36(ThrBSTree TBST, KeyType key, ThrBSTree f, ThrBSTree *p);
	//p指向关键字key在树中的位置，f指向p的双亲结点，若查找失败，p指向插入位置 
Status DeleteThr_9_37(ThrBSTree *TBST, KeyType key);
	//从线索二叉排序树中删除关键字key 
void DeleteNode_9_37(ThrBSTree *p);
	//删除线索二叉树中p指向的结点						

int main(int argc, char *argv[])
{
	FILE *fp;
	Table T;
	ThrBSTree TBST, Thrt;

	printf("创建并输出一个查找表...\n");
	fp = fopen("Data/Algo_9_35-9_37.txt", "r");	
	Create(fp, &T, Max);	
	Traverse(T, PrintKey);	
	printf("\n");

	printf("创建中序后继线索二叉排序树，并中序输出其关键字...\n");
	CreateBSTree(&TBST, T);		//创建二叉排序树 
	Create_Thr(&Thrt, TBST);	//中序后继线索化二叉排序树 
	Print_InOrder(Thrt);
	printf("\n\n");	
	
	printf("███ 题 9.35 验证... ███\n");
	{
		int a, b;
		a = 10;
		b = 90;
		printf("大于 %d 且小于 %d 的关键字：", a, b);
		Algo_9_35(Thrt, a, b);
		printf("\n\n");	
	}


	printf("███ 题 9.36 验证... ███\n");
	{
		BSTElemType e;
		e.key=28, e.weight=0.0;
		printf("插入关键字 %d 后，中序输出其关键字...\n", e.key);
		Algo_9_36(Thrt, e);
		Print_InOrder(Thrt);
		printf("\n\n");
	}
	
	printf("███ 题 9.37 验证... ███\n");
	{
		KeyType key = 26;
		printf("删除关键字 %d 后，中序输出其关键字...\n", key);
		Algo_9_37(Thrt, key);
		Print_InOrder(Thrt);
		printf("\n\n");	
	}
		
	return 0;
}

void Algo_9_35(ThrBSTree Thrt, int a, int b)	//本质是中序遍历（无递归） 
{
	ThrBSTree p = Thrt->lchild;					//p指向二叉排序树根结点
	
	while(p!=Thrt)
	{
		while(p->lchild)
			p = p->lchild;
		
		if(a<p->data.key&&p->data.key<b)
			PrintKey(p->data);
		else
		{
			if(p->data.key>=b)
				return;
		}
			
		while(p->RTag==Thread && p->rchild!=Thrt)
		{
			p = p->rchild;
			
			if(a<p->data.key&&p->data.key<b)
				PrintKey(p->data);
			else
			{
				if(p->data.key>=b)
					return;
			}
		}
		
		p = p->rchild;
	}	
}

Status Algo_9_36(ThrBSTree Thrt, BSTElemType e)
{
	ThrBSTree p, s;
		
	if(!SearchThr_9_36(Thrt->lchild, e.key, NULL, &p))	//查找不成功 
	{
		s = (ThrBSTree)malloc(sizeof(BSTNode));	
		s->data = e;
		s->lchild = NULL;
		s->RTag = Thread;
		
		if(!p)									//原树为空
		{
			Thrt->lchild = s;			
			s->rchild = Thrt;		
		} 
		else if(e.key<p->data.key)
		{
			p->lchild = s;		
			s->rchild = p;
		}
		else
		{
			s->rchild = p->rchild;
			p->RTag = Link;
			p->rchild = s;	
		}
			
		return TRUE;							//插入e.key 
	}
	else										//查找成功 
		return FALSE;		
}

Status Algo_9_37(ThrBSTree Thrt, KeyType key)
{
	int tag;
	
	if(Thrt->lchild==Thrt)
		return FALSE;
	else
	{
		parent = Thrt;								//parent指向当前访问结点的双亲结点 
		tag = DeleteThr_9_37(&Thrt->lchild, key);
		if(Thrt->lchild==NULL)						//线索二叉树已为空 
			Thrt->lchild = Thrt;
		return tag;
	}

}

Status SearchThr_9_36(ThrBSTree TBST, KeyType key, ThrBSTree f, ThrBSTree *p)
{	//p指向查找路径上最后一个“能”被访问结点，f指向Thrt的双亲，初始值为NULL 		
	if(TBST->lchild==TBST)
	{
		*p = f;
		return FALSE;
	}
	
	if(key==TBST->data.key)
	{
		*p = TBST;
		return TRUE;
	}
	else if(key<TBST->data.key)
	{
		if(!TBST->lchild)
		{
			*p = TBST;
			return FALSE;
		}
		else
			return SearchThr_9_36(TBST->lchild, key, TBST, p);
	}		
	else
	{
		if(TBST->RTag==Link)
			return SearchThr_9_36(TBST->rchild, key, TBST, p);	
		else
		{
			*p = TBST;
			return FALSE;
		}
	}

}

Status DeleteThr_9_37(ThrBSTree *TBST, KeyType key)
{
	if(key==(*TBST)->data.key)
	{
		DeleteNode_9_37(TBST);		//找到了要删除的结点 
		return OK;
	}
	else if(key<(*TBST)->data.key)
	{
		if((*TBST)->lchild)
		{
			parent = *TBST;
			return DeleteThr_9_37(&(*TBST)->lchild, key);		
		}
		else
			return FALSE;	
	}
	else
	{
		if((*TBST)->RTag==Link)
		{
			parent = *TBST;
			return DeleteThr_9_37(&(*TBST)->rchild, key);		
		}
		else
			return FALSE;		
	}
}

void DeleteNode_9_37(ThrBSTree *p)
{
	ThrBSTree q, s;
	
	if((*p)->lchild&&(*p)->RTag==Thread)		//右子树为空(没有子树) 
	{
		q = *p;
		*p = (*p)->lchild;
		if(*p)
		{
			s = *p;
			while(s->RTag==Link)				//往最右边寻找 
				s = s->rchild;	
			s->rchild = q->rchild;		
		}
		free(q);
	}
	else if(!(*p)->lchild && (*p)->RTag==Link)	//左子树为空(没有子树) 
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);		
	}
	else if(!(*p)->lchild && (*p)->RTag==Thread)//左右子树均为空(没有子树) 
	{
		q = *p;
		
		if(parent->lchild==q)
			parent->lchild = NULL;
		else
		{
			parent->RTag = Thread;
			parent->rchild = q->rchild;
		}
		
		free(q);
	} 
	else							//左右子树均不为空(前驱替换)
	{
		q = *p;
		s = (*p)->lchild;
		
		while(s->RTag==Link)		//寻找p的直接前驱 
		{
			q = s;
			s = s->rchild;
		}
		
		(*p)->data = s->data;		//用p的直接前驱取代p 
		
		if(q!=*p)
			q->rchild = s->lchild;
		else
		{
			q->lchild = s->lchild;			
			if(s->lchild)
			{
				q = s->lchild;
				while(q->RTag==Link)
					q = q->rchild;
				q->rchild = *p; 
			}	
		}

		free(s);
	}
}

void Create_Thr(ThrBSTree *Thrt, ThrBSTree TBST)
{
	*Thrt = (ThrBSTree)malloc(sizeof(BSTNode));	
	if(!TBST)
		(*Thrt)->lchild = *Thrt;
	else
		(*Thrt)->lchild = TBST;
	(*Thrt)->RTag = Thread;
	(*Thrt)->rchild = *Thrt;
		
	pre = *Thrt;
	InOrder_Sub_Thr(TBST);					//中序后继线索化 
	pre->RTag = Thread;						//最后一个结点线索化
	pre->rchild = *Thrt;					//最后一个结点指回头结点
}

void InOrder_Sub_Thr(ThrBSTree p)
{
	if(p)
	{
		InOrder_Sub_Thr(p->lchild);			//线索化左子树 
	
		if(!pre->rchild)					//为上一个结点右子树建立后继线索 
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		else
			pre->RTag = Link;
		
		pre = p;							//pre向前挪一步 
		
		InOrder_Sub_Thr(p->rchild);			//线索化右子树 
	}
}

void Print_InOrder(ThrBSTree Thrt)
{
	ThrBSTree p = Thrt->lchild;				//p指向二叉排序树根结点
	
	while(p!=Thrt)
	{
		while(p->lchild)
			p = p->lchild;
		
		PrintKey(p->data);
		
		while(p->RTag==Thread && p->rchild!=Thrt)
		{
			p = p->rchild;
			PrintKey(p->data);
		}
		
		p = p->rchild;
	}
}

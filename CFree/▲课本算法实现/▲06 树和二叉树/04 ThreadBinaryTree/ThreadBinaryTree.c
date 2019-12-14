/***********************************************
 *							                   *
 * 文件夹: ▲06 树和二叉树\04 ThreadBinaryTree *
 *							                   *
 * 文件名: ThreadBinaryTree.c                  *
 *							                   *
 * 算  法: 6.5、6.6、6.7                       * 
 *    	    			                       *
 ***********************************************/

#ifndef THREADBINARYTREE_C
#define THREADBINARYTREE_C

#include "ThreadBinaryTree.h" 								//**▲06 树和二叉树**//

Status CreateBiTree_Thr(FILE *fp, ThrBiTree *T)
{
	TElemType_Thr ch;
	
	Scanf(fp, "%c", &ch);
	
	if(ch=='^')
		*T = NULL;
	else
	{
		*T=(ThrBiTree)malloc(sizeof(ThrBiNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data = ch;
		
		CreateBiTree_Thr(fp, &(*T)->lchild);				//递归构造左子树
		if((*T)->lchild)
			(*T)->LTag = Link;								//有左孩子 
		else
			(*T)->LTag = Thread;
				
		CreateBiTree_Thr(fp, &(*T)->rchild); 				//递归构造右子树
		if((*T)->rchild)
			(*T)->RTag = Link;								//有右孩子
		else
			(*T)->RTag = Thread;
	}
	
	return OK;
} 

/*════╗
║ 算法6.7║ 
╚════*/
void InTheading_Thr(ThrBiTree p)
{
	if(p)
	{
		InTheading_Thr(p->lchild);				//线索化左子树 
	
		if(!p->lchild)							//为当前结点左子树建立前驱线索 
		{
			p->LTag = Thread;
			p->lchild = pre;
		}
	
		if(!pre->rchild)						//为上一个结点右子树建立后继线索 
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		
		pre = p;								//pre向前挪一步 
		
		InTheading_Thr(p->rchild);				//线索化右子树 
	}
} 

/*════╗
║ 算法6.6║ 
╚════*/
Status InOrderThreading_Thr(ThrBiTree *Thrt, ThrBiTree T)	//头结点后继回指 
{
	*Thrt=(ThrBiTree)malloc(sizeof(ThrBiNode));
	if(!*Thrt)
		exit(OVERFLOW);
		
	(*Thrt)->data = '\0';
	(*Thrt)->LTag = Link;
	(*Thrt)->RTag = Thread;
	(*Thrt)->rchild = *Thrt;
	
	if(!T)
		(*Thrt)->lchild = *Thrt;
	else
	{
		(*Thrt)->lchild = T;
		pre = *Thrt;							//指向头结点 
		
		InTheading_Thr(T);						//开始线索化
		 
		pre->rchild = *Thrt;					//最后一个结点指回头结点
		pre->RTag = Thread;						//最后一个结点线索化
		(*Thrt)->rchild = pre;					//头结点指向最后一个结点，建立双向联系 
	}
	
	return OK;	
} 

/*════╗
║ 算法6.5║ 
╚════*/
Status InOrderTraverse_Thr(ThrBiTree Thrt, void(Visit)(TElemType_Thr))
{
	ThrBiTree p = Thrt->lchild;					//p指向二叉树根结点
	
	while(p!=Thrt)
	{
		while(p->LTag==Link)
			p = p->lchild;
			
		Visit(p->data);
		
		while(p->RTag==Thread && p->rchild!=Thrt)
		{
			p = p->rchild;
			Visit(p->data);
		}
		
		p = p->rchild;
	}
	
	return OK;
} 

void PreTheading_Thr(ThrBiTree p)
{
	if(p)
	{
		if(!pre->rchild)						//为上一个结点右子树建立后继线索 
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		
		pre = p;								//pre向前挪一步		
		
		PreTheading_Thr(p->lchild);				//线索化左子树 
		
		if(p->rchild && p->RTag==Link)		
			PreTheading_Thr(p->rchild);			//线索化右子树 
	}
}

Status PreOrderThreading_Thr(ThrBiTree *Thrt, ThrBiTree T)		//头结点后继指向根结点 
{
	*Thrt=(ThrBiTree)malloc(sizeof(ThrBiNode));
	if(!*Thrt)
		exit(OVERFLOW);
		
	(*Thrt)->data = '\0';
	(*Thrt)->LTag = Link;
	(*Thrt)->RTag = Thread;
	(*Thrt)->rchild = NULL;

	if(!T)										//空树只有线索头结点 
		(*Thrt)->lchild = (*Thrt)->rchild = *Thrt;
	else
	{
		(*Thrt)->lchild = T;
		pre = *Thrt;							//指向头结点
		
		PreTheading_Thr(T);						//开始线索化 

		pre->RTag = Thread;						//最后一个结点线索化		
		pre->rchild = *Thrt;					//最后一个结点指回头结点 
	}
	
	return OK;	
} 

Status PreOrderTraverse_Thr(ThrBiTree Thrt, void(Visit)(TElemType_Thr))
{
	ThrBiTree p = Thrt;					//p指向二叉树线索结点 

	while(p->rchild!=Thrt)
	{	
		while(p->lchild)
		{
			p = p->lchild;
			Visit(p->data);			
		}
		
		if(p->rchild!=Thrt)
		{
			p = p->rchild;
			Visit(p->data);
		}		
	}
	
	return OK;
}

void PosTheading_Thr(ThrBiTree p)			//后序线索化特殊，先线索化右子树 
{
	if(p)
	{
		if(!p->rchild)						//为当前结点右子树建立后继线索 
		{
			p->RTag = Thread;
			p->rchild = pre;
		}
		
		pre = p;							//pre在正常顺序中为后一个结点 
		
		if(p->RTag!=Thread)
			PosTheading_Thr(p->rchild);		//线索化右子树 
		
		PosTheading_Thr(p->lchild);			//线索化左子树 
	}	
} 

Status PosOrderThreading_Thr(ThrBiTree *Thrt, ThrBiTree T)		//头结点后继回指 
{
	*Thrt=(ThrBiTree)malloc(sizeof(ThrBiNode));
	if(!*Thrt)
		exit(OVERFLOW);
		
	(*Thrt)->data = '\0';
	(*Thrt)->LTag = Link;
	(*Thrt)->RTag = Thread;
	(*Thrt)->rchild = *Thrt;
	
	if(!T)
		(*Thrt)->lchild = *Thrt;
	else
	{
		(*Thrt)->lchild = T;
		pre = *Thrt;							//指向头结点 
		
		PosTheading_Thr(T);						//开始线索化

		(*Thrt)->rchild = T;					//头结点回指 
	}
	
	return OK;	
} 

Status PosOrderTraverse_Thr(ThrBiTree Thrt, void(Visit)(TElemType_Thr))
{
	ThrBiTree p = Thrt->lchild;					//p指向二叉树根结点
	
	if(p!=Thrt)									//树不为空 
	{
		while(1)								//寻找遍历起点 
		{
			while(p->lchild)					 
				p = p->lchild;		

			if(p->rchild && p->RTag!=Thread)
				p = p->rchild;
			else
				break;
		}
		
		while(p)
		{
			Visit(p->data);
			p = Pos_NextPtr_Thr(Thrt, p);		
		}		
	}
	
	return OK;
} 

void ParentPtr_Thr(ThrBiTree T)
{
	ThrBiTree node[100];
	int i, j;
	
	i = j = 0;
	
	if(T)
		node[j++] = T;
	node[i]->parent = NULL;
	
	while(i<j)
	{		
		if(node[i]->lchild)
		{
			node[j++] = node[i]->lchild;
			node[i]->lchild->parent = node[i];		
		}

		if(node[i]->rchild)
		{
			node[j++] = node[i]->rchild;
			node[i]->rchild->parent = node[i];		
		}
		
		i++;
	}
}

ThrBiTree Pos_NextPtr_Thr(ThrBiTree Thrt, ThrBiTree p)	//寻找p的后继(注意线索二叉树的特殊性) 
{
	if(p==Thrt->lchild)									//根结点是最后一个结点 
		return NULL;
	else
	{
		if(p->RTag==Thread)								//右孩子为线索 
			return p->rchild;
		else
		{												
			if(p==p->parent->rchild)					//当前结点是左孩子 
				return p->parent;
			else
			{		
				if(p->parent->RTag!=Link)				//双亲结点没有右孩子 
					p = p->parent;
				else
				{
					p = p->parent->rchild;
					while(1)							//寻找右兄弟遍历起点 
					{
						while(p->lchild)					 
							p = p->lchild;		
			
						if(p->rchild && p->RTag!=Thread)
							p = p->rchild;
						else
							break;
					}
				}
				
				return p;				
			}
		}
	}
}

#endif 

/************************************
 *                                  *
 * 文件夹: ▲09 查找                *
 *                                  *
 * 文件名: BalancedBinarySortTree.c *
 *                                  *
 * 算  法: 9.9、9.10、9.11、9.12    *
 *                                  *
 ************************************/

#ifndef BALANCEDBINARYSORTTREE_C
#define BALANCEDBINARYSORTTREE_C

#include "BalancedBinarySortTree.h" 		//**▲09 查找**//

Status CreateAVL(BBSTree *BBST, Table T)
{
	int i, t;
	
	*BBST = NULL;
	t = FALSE;
	
	if(T.length)
	{
		for(i=1; i<=T.length; i++)
			InsertAVL(BBST, T.elem[i], &t);	
	}
	
	return OK;
}

BBSTree SearchAVL(BBSTree BBST, KeyType key)
{
	if(!BBST || EQ(key, BBST->data.key))
		return BBST;
	else if(LT(key, BBST->data.key))
		return SearchAVL(BBST->lchild, key);
	else
		return SearchAVL(BBST->rchild, key);
}

/*════╗
║算法9.11║ 
╚════*/
Status InsertAVL(BBSTree *BBST, ElemType_Search e, Boolean *taller)
{												//进行了插入操作，则返回1，否则返回0 
	if(!(*BBST))								//插入新结点，树“长高”，置taller为TRUE
	{
		*BBST = (BBSTree)malloc(sizeof(BBSTNode));
		(*BBST)->data = e;
		(*BBST)->lchild = (*BBST)->rchild = NULL;
		(*BBST)->bf = EH;
		*taller = TRUE;
	}
	else
	{
		if(EQ(e.key, (*BBST)->data.key))		//若树中已存在和e有相同关键字的结点，则不再插入 
		{
			*taller = FALSE;
			return 0;
		}
		else if(LT(e.key, (*BBST)->data.key))	//搜寻左子树 
		{
			if(!InsertAVL(&(*BBST)->lchild, e, taller))
				return 0;						//未插入

			if(*taller)							//已插入到*BBST的左子树中且左子树“长高”
			{
				switch((*BBST)->bf)
				{
					case LH:					//插入前左子树高于右子树，需做左平衡处理 
						LeftBalance(BBST);
						*taller = FALSE;
						break;
					case EH:					//插入前左子树等高于右子树，现左子树“增高” 
						(*BBST)->bf = LH;
						*taller = TRUE;
						break; 
					case RH:					//插入前右子树高于左子树，现左右子树等高 
						(*BBST)->bf = EH;
						*taller = FALSE;
						break;
				}
			} 
		}
		else									//搜寻右子树 
		{
			if(!InsertAVL(&(*BBST)->rchild, e, taller))
				return 0;						//未插入 		

			if(*taller)							//已插入到*BBST的左子树中且左子树“长高”
			{
				switch((*BBST)->bf)
				{
					case LH:					//插入前左子树高于右子树，现左右子树等高 
						(*BBST)->bf = EH;
						*taller = FALSE;
						break;
					case EH:					//插入前左右子树等高，现右子树“增高” 
						(*BBST)->bf = RH;
						*taller = TRUE;
						break; 
					case RH:					//插入前右子树高于左子树，需做右平衡处理 
						RightBalance(BBST);
						*taller = FALSE;
						break;
				}
			}
		}
	}
	
	return 1;
}

Status DeleteAVL(BBSTree *BBST, ElemType_Search e, BBSTree f, BBSTree p, Boolean *taller, int mark)
{//p指向当前结点，f指向p的父结点，初始化为空，*taller初始化为FALSE，mark代表f与p的关系，初始化为0 
	BBSTree r;
	ElemType_Search tmp;
	 
	if(!p)
		return ERROR;
	else
	{		
		if(LT(e.key, p->data.key))				//关键字较小，搜寻左子树
		{			
			if(!DeleteAVL(BBST, e, p, p->lchild, taller, 0))
				return ERROR;
			
			if(*taller)
			{
				switch(p->bf)
				{
					case LH:
						p->bf = EH;
						*taller = TRUE;
						break;
					case EH:
						p->bf = RH;
						*taller = FALSE;
						break;
					case RH:
						if(!f)
							RightBalance(BBST);
						else
							RightBalance(&(f->lchild));
						*taller = TRUE;
						break;				
				}			
			}
		}			
		else if(RT(e.key, p->data.key))			//关键字较大，搜寻右子树
		{	
			if(!DeleteAVL(BBST, e, p, p->rchild, taller, 1))
				return ERROR;	
						
			if(*taller)
			{
				switch(p->bf)
				{
					case LH:
						if(!f)
							LeftBalance(BBST);
						else
							LeftBalance(&(f->rchild));
						*taller = TRUE;
						break;
					case EH:
						p->bf = LH;
						*taller = FALSE;
						break;
					case RH:
						p->bf = EH;
						*taller = TRUE;
						break;				
				}
			}
		}
		else												//找到关键字 
		{			
			if(p->lchild!=NULL && p->rchild==NULL)			//只有左子树
			{
				if(!f)										//根结点 
					*BBST = p->lchild;			
				else
				{
					if(mark==0)
						f->lchild = p->lchild;
					else
						f->rchild = p->lchild;
				}	
				
				free(p);
				p = NULL;
				
				*taller = TRUE;	
			}
			else if(p->lchild==NULL && p->rchild!=NULL)		//只有右子树
			{
				if(!f)										//根结点 
					*BBST = p->rchild;			
				else
				{
					if(mark==0)
						f->lchild = p->rchild;
					else
						f->rchild = p->rchild;
				}	
				
				free(p);
				p = NULL;
				
				*taller = TRUE;			
			}
			else if(p->lchild==NULL && p->rchild==NULL)		//左右子树均为空
			{
				if(!f)										//根结点 
					*BBST = NULL;			
				else
				{
					if(mark==0)
						f->lchild = NULL;
					else
						f->rchild = NULL;
				}	
				
				free(p);
				p = NULL;
				
				*taller = TRUE;
			} 
			else											//左右子树均不空
			{
				r = p->lchild;
			
				while(r->rchild)
					r = r->rchild;
				
				tmp = r->data;
				
				*taller = FALSE;
				if(!f)
					DeleteAVL(BBST, tmp, NULL, p, taller, mark);
				else
				{
					if(mark==0)
						DeleteAVL(&(f->lchild), tmp, NULL, p, taller, mark);
					else								
						DeleteAVL(&(f->rchild), tmp, NULL, p, taller, mark);				
				}			
				p->data = tmp;
			} 
		}
	
		return OK;
	}
} 

void RightBalance(BBSTree *BBST)
{
	BBSTree rc, ld;
	
	rc = (*BBST)->rchild;
	
	switch(rc->bf)
	{
		case RH:					//新结点插入在*BBST右孩子的右子树上
			(*BBST)->bf = rc->bf = EH;
			L_Rotate(BBST);			
			break;

		case LH: 					//新结点插入在*BBST右孩子的左子树上
			ld = rc->lchild;			
			switch(ld->bf)
			{
				case LH:
					(*BBST)->bf = EH;
					rc->bf = RH;
					break;
				case EH:
					(*BBST)->bf = rc->bf = EH;
					break;
				case RH:
					(*BBST)->bf = LH;
					rc->bf = EH;
					break;
			}			
			ld->bf = EH;
			R_Rotate(&(*BBST)->rchild);
			L_Rotate(BBST);
			break;
	}
}

/*════╗
║算法9.12║ 
╚════*/
void LeftBalance(BBSTree *BBST)
{
	BBSTree lc, rd;
	
	lc = (*BBST)->lchild;
	
	switch(lc->bf)
	{
		case LH:					//新结点插入在*BBST左孩子的左子树上 
			(*BBST)->bf = lc->bf = EH;
			R_Rotate(BBST);
			break;
		
		case RH:					//新结点插入在*BBST左孩子的右子树上
			rd = lc->rchild;			
			switch(rd->bf)
			{
				case LH:
					(*BBST)->bf = RH;
					lc->bf = EH;
					break;
				case EH:
					(*BBST)->bf = lc->bf = EH;
					break;
				case RH:
					(*BBST)->bf = EH;
					lc->bf = LH;
					break;
			}			
			rd->bf = EH;
			L_Rotate(&(*BBST)->lchild);
			R_Rotate(BBST);
			break;
	}
}

/*════╗
║ 算法9.9║ 
╚════*/
void R_Rotate(BBSTree *p)
{
	BBSTree lc;
	
	lc = (*p)->lchild;
	(*p)->lchild = lc->rchild;
	lc->rchild = *p;
	*p = lc;	
}

/*════╗
║算法9.10║ 
╚════*/
void L_Rotate(BBSTree *p)
{
	BBSTree rc;
	
	rc = (*p)->rchild;
	(*p)->rchild = rc->lchild;
	rc->lchild = *p;
	*p = rc;	
}

void InOrderTraverse_AVL(BBSTree BBST, void(Visit)(ElemType_Search))
{
	if(BBST)
	{
		InOrderTraverse_AVL(BBST->lchild, Visit);
		Visit(BBST->data);	
		InOrderTraverse_AVL(BBST->rchild, Visit);	
	}
}

int AVLDepth(BBSTree BBST)
{
	int LD, RD;
	
	if(BBST==NULL)
		return 0;								//空树深度为0 
	else
	{
		LD = AVLDepth(BBST->lchild);			//求左子树深度 
		RD = AVLDepth(BBST->rchild);			//求右子树深度 
	
		return (LD>=RD?LD:RD)+1;
	}
}

void PrintAVLTree(BBSTree BBST)
{
	int row, col;
	int i, j, m, l, r;
	BBSTNode a[100][100] = {};
	
	if(BBST)
	{
		row = AVLDepth(BBST);					//总行数 
		col = pow(2, row) - 1;					//总列数 
		
		for(i=1; i<=row-1; i++)
		{
			for(j=1; j<=pow(2, i-1); j++)
			{
				m = (2*j-1)*pow(2, row-i);		//当前行结点相对位序 
				l = (4*j-3)*pow(2, row-i-1);	//下一行结点相对位序 
				r = (4*j-1)*pow(2, row-i-1);
				
				if(i==1)						//初始化 
					a[i][m] = *BBST;
				
				if(a[i][m].lchild)				//下一行 
					a[i+1][l] = *(a[i][m].lchild);
					
				if(a[i][m].rchild)				//下一行 
					a[i+1][r] = *(a[i][m].rchild);
			} 
		}
		
		for(i=1; i<=row; i++)
		{
			for(j=1; j<=col; j++)
			{
				if(a[i][j].data.key)
					printf("%2d", a[i][j].data.key);
				else
					printf("  ");
			}
			printf("\n");
		}	
	}
}

#endif

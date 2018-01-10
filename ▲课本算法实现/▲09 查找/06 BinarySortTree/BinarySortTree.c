/******************************
 *                            *
 * 文件夹: ▲09 查找          *
 *                            *
 * 文件名: BinarySortTree.c   *
 *                            *
 * 算  法: 9.5、9.6、9.7、9.8 *
 *                            *
 ******************************/

#ifndef BINARYSORTTREE_C
#define BINARYSORTTREE_C

#include "BinarySortTree.h" 			//**▲09 查找**//

Status CreateBSTree(BSTree *BST, Table T)
{
	int i;
	
	*BST = NULL;
	
	if(T.length)
	{
		for(i=1; i<=T.length; i++)
			InsertBST(BST, T.elem[i]);	
	}
	
	return OK;
}

/*═════╗
║算法9.5(a)║ 
╚═════*/
BSTree SearchBST_1(BSTree BST, KeyType key)
{
	if(!BST || EQ(key, BST->data.key))
		return BST;
	else if(LT(key, BST->data.key))
		return SearchBST_1(BST->lchild, key);
	else
		return SearchBST_1(BST->rchild, key);
}

/*═════╗
║算法9.5(b)║ 
╚═════*/
Status SearchBST_2(BSTree BST, KeyType key, BSTree f, BSTree *p)
{//p指向查找路径上最后一个“能”被访问结点，f指向BST的双亲，初始值为NULL 
	if(!BST)
	{
		*p = f;
		return FALSE;
	}
	else if(EQ(key, BST->data.key))
	{
		*p = BST;
		return TRUE;
	}
	else if(LT(key, BST->data.key))
		return SearchBST_2(BST->lchild, key, BST, p);
	else
		return SearchBST_2(BST->rchild, key, BST, p);
}

/*════╗
║ 算法9.6║ 
╚════*/
Status InsertBST(BSTree *BST, BSTElemType e)
{
	BSTree p, s;
	 
	if(!SearchBST_2(*BST, e.key, NULL, &p))		//查找不成功 
	{
		s = (BSTree)malloc(sizeof(BSTNode));
		s->data = e;
		s->lchild = s->rchild = NULL;
		
		if(!p)									//原树为空 
			*BST = s;
		else if(LT(e.key, p->data.key))
			p->lchild = s;
		else
			p->rchild = s;
	
		return TRUE;							//插入e.key 
	}
	else										//查找成功 
		return FALSE;
}

void InOrderTraverse_BST(BSTree BST, void(Visit)(ElemType_Search))
{
	if(BST)
	{
		InOrderTraverse_BST(BST->lchild, Visit);
		Visit(BST->data);	
		InOrderTraverse_BST(BST->rchild, Visit);	
	}

}

/*════╗
║ 算法9.7║ 
╚════*/
Status DeleteBST(BSTree *BST, KeyType key)
{
	if(!(*BST))						//不存在与关键字相等的数据元素 
		return FALSE;
	else
	{
		if(EQ(key, (*BST)->data.key))
			return Delete(BST);
		else if(LT(key, (*BST)->data.key))
			return DeleteBST(&(*BST)->lchild, key);
		else
			return DeleteBST(&(*BST)->rchild, key);
	}
}

/*════╗
║ 算法9.8║ 
╚════*/
Status Delete(BSTree *p)
{
	BSTree q, s;
	
	if(!(*p)->rchild)
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if(!(*p)->lchild)
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);		
	}
	else
	{
		q = *p;
		s = (*p)->lchild;
		
		while(s->rchild)		//寻找p的直接前驱 
		{
			q = s;
			s = s->rchild;
		}
		
		(*p)->data = s->data;	//用p的直接前驱取代p 
		
		if(q!=*p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
			
		free(s);
	}
	
	return TRUE;
}

#endif

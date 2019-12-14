/******************************
 *                            *
 * �ļ���: ��09 ����          *
 *                            *
 * �ļ���: BinarySortTree.c   *
 *                            *
 * ��  ��: 9.5��9.6��9.7��9.8 *
 *                            *
 ******************************/

#ifndef BINARYSORTTREE_C
#define BINARYSORTTREE_C

#include "BinarySortTree.h" 			//**��09 ����**//

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

/*�T�T�T�T�T�[
�U�㷨9.5(a)�U 
�^�T�T�T�T�T*/
BSTree SearchBST_1(BSTree BST, KeyType key)
{
	if(!BST || EQ(key, BST->data.key))
		return BST;
	else if(LT(key, BST->data.key))
		return SearchBST_1(BST->lchild, key);
	else
		return SearchBST_1(BST->rchild, key);
}

/*�T�T�T�T�T�[
�U�㷨9.5(b)�U 
�^�T�T�T�T�T*/
Status SearchBST_2(BSTree BST, KeyType key, BSTree f, BSTree *p)
{//pָ�����·�������һ�����ܡ������ʽ�㣬fָ��BST��˫�ף���ʼֵΪNULL 
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

/*�T�T�T�T�[
�U �㷨9.6�U 
�^�T�T�T�T*/
Status InsertBST(BSTree *BST, BSTElemType e)
{
	BSTree p, s;
	 
	if(!SearchBST_2(*BST, e.key, NULL, &p))		//���Ҳ��ɹ� 
	{
		s = (BSTree)malloc(sizeof(BSTNode));
		s->data = e;
		s->lchild = s->rchild = NULL;
		
		if(!p)									//ԭ��Ϊ�� 
			*BST = s;
		else if(LT(e.key, p->data.key))
			p->lchild = s;
		else
			p->rchild = s;
	
		return TRUE;							//����e.key 
	}
	else										//���ҳɹ� 
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

/*�T�T�T�T�[
�U �㷨9.7�U 
�^�T�T�T�T*/
Status DeleteBST(BSTree *BST, KeyType key)
{
	if(!(*BST))						//��������ؼ�����ȵ�����Ԫ�� 
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

/*�T�T�T�T�[
�U �㷨9.8�U 
�^�T�T�T�T*/
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
		
		while(s->rchild)		//Ѱ��p��ֱ��ǰ�� 
		{
			q = s;
			s = s->rchild;
		}
		
		(*p)->data = s->data;	//��p��ֱ��ǰ��ȡ��p 
		
		if(q!=*p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
			
		free(s);
	}
	
	return TRUE;
}

#endif

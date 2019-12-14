/***********************************************
 *							                   *
 * �ļ���: ��06 ���Ͷ�����\04 ThreadBinaryTree *
 *							                   *
 * �ļ���: ThreadBinaryTree.c                  *
 *							                   *
 * ��  ��: 6.5��6.6��6.7                       * 
 *    	    			                       *
 ***********************************************/

#ifndef THREADBINARYTREE_C
#define THREADBINARYTREE_C

#include "ThreadBinaryTree.h" 								//**��06 ���Ͷ�����**//

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
		
		CreateBiTree_Thr(fp, &(*T)->lchild);				//�ݹ鹹��������
		if((*T)->lchild)
			(*T)->LTag = Link;								//������ 
		else
			(*T)->LTag = Thread;
				
		CreateBiTree_Thr(fp, &(*T)->rchild); 				//�ݹ鹹��������
		if((*T)->rchild)
			(*T)->RTag = Link;								//���Һ���
		else
			(*T)->RTag = Thread;
	}
	
	return OK;
} 

/*�T�T�T�T�[
�U �㷨6.7�U 
�^�T�T�T�T*/
void InTheading_Thr(ThrBiTree p)
{
	if(p)
	{
		InTheading_Thr(p->lchild);				//������������ 
	
		if(!p->lchild)							//Ϊ��ǰ�������������ǰ������ 
		{
			p->LTag = Thread;
			p->lchild = pre;
		}
	
		if(!pre->rchild)						//Ϊ��һ���������������������� 
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		
		pre = p;								//pre��ǰŲһ�� 
		
		InTheading_Thr(p->rchild);				//������������ 
	}
} 

/*�T�T�T�T�[
�U �㷨6.6�U 
�^�T�T�T�T*/
Status InOrderThreading_Thr(ThrBiTree *Thrt, ThrBiTree T)	//ͷ����̻�ָ 
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
		pre = *Thrt;							//ָ��ͷ��� 
		
		InTheading_Thr(T);						//��ʼ������
		 
		pre->rchild = *Thrt;					//���һ�����ָ��ͷ���
		pre->RTag = Thread;						//���һ�����������
		(*Thrt)->rchild = pre;					//ͷ���ָ�����һ����㣬����˫����ϵ 
	}
	
	return OK;	
} 

/*�T�T�T�T�[
�U �㷨6.5�U 
�^�T�T�T�T*/
Status InOrderTraverse_Thr(ThrBiTree Thrt, void(Visit)(TElemType_Thr))
{
	ThrBiTree p = Thrt->lchild;					//pָ������������
	
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
		if(!pre->rchild)						//Ϊ��һ���������������������� 
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		
		pre = p;								//pre��ǰŲһ��		
		
		PreTheading_Thr(p->lchild);				//������������ 
		
		if(p->rchild && p->RTag==Link)		
			PreTheading_Thr(p->rchild);			//������������ 
	}
}

Status PreOrderThreading_Thr(ThrBiTree *Thrt, ThrBiTree T)		//ͷ�����ָ������ 
{
	*Thrt=(ThrBiTree)malloc(sizeof(ThrBiNode));
	if(!*Thrt)
		exit(OVERFLOW);
		
	(*Thrt)->data = '\0';
	(*Thrt)->LTag = Link;
	(*Thrt)->RTag = Thread;
	(*Thrt)->rchild = NULL;

	if(!T)										//����ֻ������ͷ��� 
		(*Thrt)->lchild = (*Thrt)->rchild = *Thrt;
	else
	{
		(*Thrt)->lchild = T;
		pre = *Thrt;							//ָ��ͷ���
		
		PreTheading_Thr(T);						//��ʼ������ 

		pre->RTag = Thread;						//���һ�����������		
		pre->rchild = *Thrt;					//���һ�����ָ��ͷ��� 
	}
	
	return OK;	
} 

Status PreOrderTraverse_Thr(ThrBiTree Thrt, void(Visit)(TElemType_Thr))
{
	ThrBiTree p = Thrt;					//pָ�������������� 

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

void PosTheading_Thr(ThrBiTree p)			//�������������⣬�������������� 
{
	if(p)
	{
		if(!p->rchild)						//Ϊ��ǰ�������������������� 
		{
			p->RTag = Thread;
			p->rchild = pre;
		}
		
		pre = p;							//pre������˳����Ϊ��һ����� 
		
		if(p->RTag!=Thread)
			PosTheading_Thr(p->rchild);		//������������ 
		
		PosTheading_Thr(p->lchild);			//������������ 
	}	
} 

Status PosOrderThreading_Thr(ThrBiTree *Thrt, ThrBiTree T)		//ͷ����̻�ָ 
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
		pre = *Thrt;							//ָ��ͷ��� 
		
		PosTheading_Thr(T);						//��ʼ������

		(*Thrt)->rchild = T;					//ͷ����ָ 
	}
	
	return OK;	
} 

Status PosOrderTraverse_Thr(ThrBiTree Thrt, void(Visit)(TElemType_Thr))
{
	ThrBiTree p = Thrt->lchild;					//pָ������������
	
	if(p!=Thrt)									//����Ϊ�� 
	{
		while(1)								//Ѱ�ұ������ 
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

ThrBiTree Pos_NextPtr_Thr(ThrBiTree Thrt, ThrBiTree p)	//Ѱ��p�ĺ��(ע��������������������) 
{
	if(p==Thrt->lchild)									//����������һ����� 
		return NULL;
	else
	{
		if(p->RTag==Thread)								//�Һ���Ϊ���� 
			return p->rchild;
		else
		{												
			if(p==p->parent->rchild)					//��ǰ��������� 
				return p->parent;
			else
			{		
				if(p->parent->RTag!=Link)				//˫�׽��û���Һ��� 
					p = p->parent;
				else
				{
					p = p->parent->rchild;
					while(1)							//Ѱ�����ֵܱ������ 
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

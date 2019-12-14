/************************************
 *                                  *
 * �ļ���: ��09 ����                *
 *                                  *
 * �ļ���: BalancedBinarySortTree.c *
 *                                  *
 * ��  ��: 9.9��9.10��9.11��9.12    *
 *                                  *
 ************************************/

#ifndef BALANCEDBINARYSORTTREE_C
#define BALANCEDBINARYSORTTREE_C

#include "BalancedBinarySortTree.h" 		//**��09 ����**//

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

/*�T�T�T�T�[
�U�㷨9.11�U 
�^�T�T�T�T*/
Status InsertAVL(BBSTree *BBST, ElemType_Search e, Boolean *taller)
{												//�����˲���������򷵻�1�����򷵻�0 
	if(!(*BBST))								//�����½�㣬�������ߡ�����tallerΪTRUE
	{
		*BBST = (BBSTree)malloc(sizeof(BBSTNode));
		(*BBST)->data = e;
		(*BBST)->lchild = (*BBST)->rchild = NULL;
		(*BBST)->bf = EH;
		*taller = TRUE;
	}
	else
	{
		if(EQ(e.key, (*BBST)->data.key))		//�������Ѵ��ں�e����ͬ�ؼ��ֵĽ�㣬���ٲ��� 
		{
			*taller = FALSE;
			return 0;
		}
		else if(LT(e.key, (*BBST)->data.key))	//��Ѱ������ 
		{
			if(!InsertAVL(&(*BBST)->lchild, e, taller))
				return 0;						//δ����

			if(*taller)							//�Ѳ��뵽*BBST�����������������������ߡ�
			{
				switch((*BBST)->bf)
				{
					case LH:					//����ǰ������������������������ƽ�⴦�� 
						LeftBalance(BBST);
						*taller = FALSE;
						break;
					case EH:					//����ǰ�������ȸ������������������������ߡ� 
						(*BBST)->bf = LH;
						*taller = TRUE;
						break; 
					case RH:					//����ǰ�����������������������������ȸ� 
						(*BBST)->bf = EH;
						*taller = FALSE;
						break;
				}
			} 
		}
		else									//��Ѱ������ 
		{
			if(!InsertAVL(&(*BBST)->rchild, e, taller))
				return 0;						//δ���� 		

			if(*taller)							//�Ѳ��뵽*BBST�����������������������ߡ�
			{
				switch((*BBST)->bf)
				{
					case LH:					//����ǰ�����������������������������ȸ� 
						(*BBST)->bf = EH;
						*taller = FALSE;
						break;
					case EH:					//����ǰ���������ȸߣ��������������ߡ� 
						(*BBST)->bf = RH;
						*taller = TRUE;
						break; 
					case RH:					//����ǰ������������������������ƽ�⴦�� 
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
{//pָ��ǰ��㣬fָ��p�ĸ���㣬��ʼ��Ϊ�գ�*taller��ʼ��ΪFALSE��mark����f��p�Ĺ�ϵ����ʼ��Ϊ0 
	BBSTree r;
	ElemType_Search tmp;
	 
	if(!p)
		return ERROR;
	else
	{		
		if(LT(e.key, p->data.key))				//�ؼ��ֽ�С����Ѱ������
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
		else if(RT(e.key, p->data.key))			//�ؼ��ֽϴ���Ѱ������
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
		else												//�ҵ��ؼ��� 
		{			
			if(p->lchild!=NULL && p->rchild==NULL)			//ֻ��������
			{
				if(!f)										//����� 
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
			else if(p->lchild==NULL && p->rchild!=NULL)		//ֻ��������
			{
				if(!f)										//����� 
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
			else if(p->lchild==NULL && p->rchild==NULL)		//����������Ϊ��
			{
				if(!f)										//����� 
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
			else											//��������������
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
		case RH:					//�½�������*BBST�Һ��ӵ���������
			(*BBST)->bf = rc->bf = EH;
			L_Rotate(BBST);			
			break;

		case LH: 					//�½�������*BBST�Һ��ӵ���������
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

/*�T�T�T�T�[
�U�㷨9.12�U 
�^�T�T�T�T*/
void LeftBalance(BBSTree *BBST)
{
	BBSTree lc, rd;
	
	lc = (*BBST)->lchild;
	
	switch(lc->bf)
	{
		case LH:					//�½�������*BBST���ӵ��������� 
			(*BBST)->bf = lc->bf = EH;
			R_Rotate(BBST);
			break;
		
		case RH:					//�½�������*BBST���ӵ���������
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

/*�T�T�T�T�[
�U �㷨9.9�U 
�^�T�T�T�T*/
void R_Rotate(BBSTree *p)
{
	BBSTree lc;
	
	lc = (*p)->lchild;
	(*p)->lchild = lc->rchild;
	lc->rchild = *p;
	*p = lc;	
}

/*�T�T�T�T�[
�U�㷨9.10�U 
�^�T�T�T�T*/
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
		return 0;								//�������Ϊ0 
	else
	{
		LD = AVLDepth(BBST->lchild);			//����������� 
		RD = AVLDepth(BBST->rchild);			//����������� 
	
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
		row = AVLDepth(BBST);					//������ 
		col = pow(2, row) - 1;					//������ 
		
		for(i=1; i<=row-1; i++)
		{
			for(j=1; j<=pow(2, i-1); j++)
			{
				m = (2*j-1)*pow(2, row-i);		//��ǰ�н�����λ�� 
				l = (4*j-3)*pow(2, row-i-1);	//��һ�н�����λ�� 
				r = (4*j-1)*pow(2, row-i-1);
				
				if(i==1)						//��ʼ�� 
					a[i][m] = *BBST;
				
				if(a[i][m].lchild)				//��һ�� 
					a[i+1][l] = *(a[i][m].lchild);
					
				if(a[i][m].rchild)				//��һ�� 
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

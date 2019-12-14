#include <stdio.h>
#include <stdlib.h>
#include "../../../���α��㷨ʵ��/��09 ����/06 BinarySortTree/BinarySortTree.c" //**��09 ����**// 

/*�궨��*/
#define Max 15							//���ұ���Ԫ�ظ���

/* ���Ͷ��� */
enum {Link, Thread};					//������ǣ�Link�����ӣ�Thread������ 
typedef BSTree ThrBSTree;				//��������������

/*ȫ�ֱ���*/
ThrBSTree pre;							//ָ��ǰ���ǰ�� 
ThrBSTree parent;						//ָ��ǰ����˫�׽�� 

/* ����ԭ�� */
void Algo_9_35(ThrBSTree Thrt, int a, int b);
Status Algo_9_36(ThrBSTree Thrt, BSTElemType e);
Status Algo_9_37(ThrBSTree Thrt, KeyType key);
void Create_Thr(ThrBSTree *Thrt, ThrBSTree TBST);
void InOrder_Sub_Thr(ThrBSTree p);
void Print_InOrder(ThrBSTree Thrt);
Status SearchThr_9_36(ThrBSTree TBST, KeyType key, ThrBSTree f, ThrBSTree *p);
	//pָ��ؼ���key�����е�λ�ã�fָ��p��˫�׽�㣬������ʧ�ܣ�pָ�����λ�� 
Status DeleteThr_9_37(ThrBSTree *TBST, KeyType key);
	//������������������ɾ���ؼ���key 
void DeleteNode_9_37(ThrBSTree *p);
	//ɾ��������������pָ��Ľ��						

int main(int argc, char *argv[])
{
	FILE *fp;
	Table T;
	ThrBSTree TBST, Thrt;

	printf("���������һ�����ұ�...\n");
	fp = fopen("Data/Algo_9_35-9_37.txt", "r");	
	Create(fp, &T, Max);	
	Traverse(T, PrintKey);	
	printf("\n");

	printf("�������������������������������������ؼ���...\n");
	CreateBSTree(&TBST, T);		//�������������� 
	Create_Thr(&Thrt, TBST);	//���������������������� 
	Print_InOrder(Thrt);
	printf("\n\n");	
	
	printf("������ �� 9.35 ��֤... ������\n");
	{
		int a, b;
		a = 10;
		b = 90;
		printf("���� %d ��С�� %d �Ĺؼ��֣�", a, b);
		Algo_9_35(Thrt, a, b);
		printf("\n\n");	
	}


	printf("������ �� 9.36 ��֤... ������\n");
	{
		BSTElemType e;
		e.key=28, e.weight=0.0;
		printf("����ؼ��� %d �����������ؼ���...\n", e.key);
		Algo_9_36(Thrt, e);
		Print_InOrder(Thrt);
		printf("\n\n");
	}
	
	printf("������ �� 9.37 ��֤... ������\n");
	{
		KeyType key = 26;
		printf("ɾ���ؼ��� %d �����������ؼ���...\n", key);
		Algo_9_37(Thrt, key);
		Print_InOrder(Thrt);
		printf("\n\n");	
	}
		
	return 0;
}

void Algo_9_35(ThrBSTree Thrt, int a, int b)	//����������������޵ݹ飩 
{
	ThrBSTree p = Thrt->lchild;					//pָ����������������
	
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
		
	if(!SearchThr_9_36(Thrt->lchild, e.key, NULL, &p))	//���Ҳ��ɹ� 
	{
		s = (ThrBSTree)malloc(sizeof(BSTNode));	
		s->data = e;
		s->lchild = NULL;
		s->RTag = Thread;
		
		if(!p)									//ԭ��Ϊ��
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
			
		return TRUE;							//����e.key 
	}
	else										//���ҳɹ� 
		return FALSE;		
}

Status Algo_9_37(ThrBSTree Thrt, KeyType key)
{
	int tag;
	
	if(Thrt->lchild==Thrt)
		return FALSE;
	else
	{
		parent = Thrt;								//parentָ��ǰ���ʽ���˫�׽�� 
		tag = DeleteThr_9_37(&Thrt->lchild, key);
		if(Thrt->lchild==NULL)						//������������Ϊ�� 
			Thrt->lchild = Thrt;
		return tag;
	}

}

Status SearchThr_9_36(ThrBSTree TBST, KeyType key, ThrBSTree f, ThrBSTree *p)
{	//pָ�����·�������һ�����ܡ������ʽ�㣬fָ��Thrt��˫�ף���ʼֵΪNULL 		
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
		DeleteNode_9_37(TBST);		//�ҵ���Ҫɾ���Ľ�� 
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
	
	if((*p)->lchild&&(*p)->RTag==Thread)		//������Ϊ��(û������) 
	{
		q = *p;
		*p = (*p)->lchild;
		if(*p)
		{
			s = *p;
			while(s->RTag==Link)				//�����ұ�Ѱ�� 
				s = s->rchild;	
			s->rchild = q->rchild;		
		}
		free(q);
	}
	else if(!(*p)->lchild && (*p)->RTag==Link)	//������Ϊ��(û������) 
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);		
	}
	else if(!(*p)->lchild && (*p)->RTag==Thread)//����������Ϊ��(û������) 
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
	else							//������������Ϊ��(ǰ���滻)
	{
		q = *p;
		s = (*p)->lchild;
		
		while(s->RTag==Link)		//Ѱ��p��ֱ��ǰ�� 
		{
			q = s;
			s = s->rchild;
		}
		
		(*p)->data = s->data;		//��p��ֱ��ǰ��ȡ��p 
		
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
	InOrder_Sub_Thr(TBST);					//������������ 
	pre->RTag = Thread;						//���һ�����������
	pre->rchild = *Thrt;					//���һ�����ָ��ͷ���
}

void InOrder_Sub_Thr(ThrBSTree p)
{
	if(p)
	{
		InOrder_Sub_Thr(p->lchild);			//������������ 
	
		if(!pre->rchild)					//Ϊ��һ���������������������� 
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		else
			pre->RTag = Link;
		
		pre = p;							//pre��ǰŲһ�� 
		
		InOrder_Sub_Thr(p->rchild);			//������������ 
	}
}

void Print_InOrder(ThrBSTree Thrt)
{
	ThrBSTree p = Thrt->lchild;				//pָ����������������
	
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

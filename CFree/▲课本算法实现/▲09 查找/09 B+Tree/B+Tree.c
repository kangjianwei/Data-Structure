/*********************
 *                   *
 * �ļ���: ��09 ���� *
 *                   *
 * �ļ���: B+Tree.c  *
 *                   *
 *********************/

#ifndef B__TREE_C
#define B__TREE_C

#include "B+Tree.h" 				//**��09 ����**//

Status CreateB_Tree(B_Tree *B_T, Table T)
{
	int i;
	
	(*B_T).root = (*B_T).data = NULL;

	if(T.length)
	{
		for(i=1; i<=T.length; i++)
		{
			if(!InsertKey(B_T, T.elem[i].key))	//����ʧ��������ѭ�� 
				break;
		}				
	}
	
	if(i>T.length) 
		return OK;
	else
		return ERROR;
}

Result SearchB_Tree(B_Tree B_T, KeyType K)
{
	Result R = {NULL, 0, 0};
	B_TNode *p;
	int found, i;
	
	p = B_T.root;
	found = FALSE;
	i = 0;						//p->key[i]<=K<p->key[i+1] 
	
	while(p && !found)
	{
		i = Search(p, K);		//��p->key[1...keynum]�в��� 
		
		if(p->leaf==1)
		{
			if(i>0 && p->key[i-1]==K)
			{
				found = TRUE;
				i--;
			}
			else
				break;
		}
		else
		{
			if(i>0)
				i--;
				
			p = p->ptr[i];		
		}
	}
	
	R.i = i;
	R.pt = p;
	
	if(found)
		R.tag = 1;
	else
		R.tag = 0;
		
	return R;
}

int Search(B_TNode *p, KeyType K)
{
	int i;
	
	for(i=0; i<p->keynum&&p->key[i]<=K; i++)
		;
	
	return i;
}

Status InsertKey(B_Tree *B_T, KeyType K)
{
	Result R;
	
	R = SearchB_Tree(*B_T, K);
	
	if(R.tag==0)							//B+���в����ڴ˹ؼ��� 
	{
		InsertB_Tree(B_T, K, R.pt, R.i);
		return OK;	
	}
	else
		return ERROR;	
}

Status InsertB_Tree(B_Tree *B_T, KeyType K, B_TNode *q, int i)
{
	KeyType x;
	B_TNode *ap;
	int finished;
	int s;
	
	x = K;
	ap = NULL;
	finished = FALSE;
	
	while(q && !finished)
	{
		Insert(q, i, x, ap);		//��x��ap�ֱ���뵽q->key[i]��q->ptr[i]
		q->ptr[i] = ap;
		
		if(q->keynum<=M)			//����B������ 
			finished = TRUE;		//�������
		else						//�ؼ�����Ŀ��������	
		{
			s = (double)M/2;		//B+������йؼ��ָ�������>=ceil(M/2)
			split(q, s, &ap);		//���ѽ��*q 
			x = q->key[s+1];		//��q->key[s+1...M],q->ptr[s...M]�����½��*ap;			
			q = q->parent;
			
			if(q)					//��˫�׽��*q�в���x�Ĳ���λ�� 
				i = Search(q, x); 
		}
	}
	
	if(!finished)					//B_T�ǿ���������q��ֵΪNULL�����߸�����ѷ���Ϊ���*q��*ap 
		NewRoot(B_T, q, x, ap); 	//���ɺ���Ϣ(B_T,x,ap)���µĸ����*B_T��ԭB_T��apΪ����ָ�� 
	
	return OK;
}

void Insert(B_TNode *q, int i, KeyType x, B_TNode *ap)
{
	int j;
	B_TNode *p;
	
	for(j=q->keynum; j>i; j--)
	{
		q->key[j] = q->key[j-1];
		q->ptr[j] = q->ptr[j-1];
	}
	
	q->key[i] = x;
	q->ptr[i] = ap;
	q->keynum++;
	
	p = q->parent;							//��Сֵ�����˱䶯 
	while(!i && p)
	{
		i = Search(p, q->key[1]);
		--i;
		p->key[i] = x;
		p = p->parent;
	}
}

void split(B_TNode *q, int s, B_TNode **ap)		//s��ֵΪ��M/2��
{	
	int i;
	
	*ap = (B_TNode *)malloc(sizeof(B_TNode));
	
	if(q->leaf==1)								//���ѵ���Ҷ�ӽ�� 
	{
		(*ap)->leaf = 1;
		(*ap)->lf.next = q->lf.next;
		q->lf.next = *ap;
	}
	else
		(*ap)->leaf = 0;
	
	for(i=s+1; i<=M; i++)
	{
		(*ap)->key[i-s-1] = q->key[i];
		(*ap)->ptr[i-s-1] = q->ptr[i];
	}
	
	(*ap)->keynum = M - s;
	q->keynum = s + 1;
	
	(*ap)->parent = q->parent;
	
	for(i=0; i<(*ap)->keynum; i++)
	{
		if((*ap)->ptr[i])
			(*ap)->ptr[i]->parent = *ap;
	}
}

void NewRoot(B_Tree *B_T, B_TNode *q, int x, B_TNode *ap)	//q��ʼֵΪ��
{ 
	B_TNode *p;

	p = (B_TNode *)malloc(sizeof(B_TNode));
	p->keynum = 1;
	p->parent = NULL;
	p->key[0] = x;
	p->ptr[0] = ap;
	if(p->ptr[0])
		p->ptr[0]->parent = p;
		
	if(!q && B_T->root)
	{
		Insert(p, 0, B_T->root->key[0], B_T->root);	
		if(p->ptr[0])
			p->ptr[0]->parent = p;	
	}
	
	B_T->root = p;	
	
	if(B_T->data==NULL)
	{
		p->leaf = 1;
		p->lf.next = NULL;
		B_T->data = p;	
	}
	else
		p->leaf = 0;
}

void PrintB_Tree(B_Tree B_T)
{
	B_TNode *p;
	int i;
	
	for(p=B_T.data; p; p=p->lf.next)
	{
		printf("(");
		for(i=0; i<p->keynum; i++)
			printf("%d ", p->key[i]);
		printf(") ");
	}
	
	printf("\n");
}

#endif

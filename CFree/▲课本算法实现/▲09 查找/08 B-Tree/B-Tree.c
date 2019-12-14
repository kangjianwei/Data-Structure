/**********************
 *                    *
 * �ļ���: ��09 ����  *
 *                    *
 * �ļ���: B-Tree.c   *
 *                    *
 * ��  ��: 9.13��9.14 *
 *                    *
 **********************/

#ifndef B_TREE_C
#define B_TREE_C

#include "B-Tree.h" 				//**��09 ����**//

Status CreateBTree(BTree *BT, Table T)
{
	int i;
	
	*BT = NULL;

	if(T.length)
	{
		for(i=1; i<=T.length; i++)
		{
			if(!InsertKey(BT, T.elem[i].key))	//����ʧ��������ѭ�� 
				break;
		}				
	}
	
	if(i>T.length) 
		return OK;
	else
		return ERROR;
}

/*�T�T�T�T�[
�U�㷨9.13�U 
�^�T�T�T�T*/
Result SearchBTree(BTree BT, KeyType K)
{
	Result R = {NULL, 0, 0};
	BTree p, q;
	int found, i;
	
	p = BT;
	q = NULL;
	found = FALSE;
	i = 0;						//p->key[i]<=K<p->key[i+1] 
	
	while(p && !found)
	{
		i = Search(p, K);		//��p->key[1...keynum]�в��� 
		
		if(i>0 && p->key[i]==K)
			found = TRUE;		//�ҵ��ؼ���
		else
		{
			q = p;
			p = p->ptr[i];
		} 
	}
	
	R.i = i;
	
	if(found)
	{
		R.pt = p;
		R.tag = 1;
	}
	else
	{
		R.pt = q;
		R.tag = 0;
	}
	
	return R;
}

int Search(BTree p, KeyType K)
{
	int i, j;

	for(i=0,j=1; j<=p->keynum; j++)
	{
		if(p->key[j]<=K)
			i = j;
		else
			break;
	}
	
	return i;
}

Status InsertKey(BTree *BT, KeyType K)
{
	Result R;
	
	R = SearchBTree(*BT, K);
	
	if(R.tag==0)							//B���в����ڴ˹ؼ��� 
	{
		InsertBTree(BT, K, R.pt, R.i);
		return OK;	
	}
	else
		return ERROR;	
}

/*�T�T�T�T�[
�U�㷨9.14�U 
�^�T�T�T�T*/
Status InsertBTree(BTree *BT, KeyType K, BTree q, int i)
{
	KeyType x;
	BTree ap;
	int finished;
	int s;
	
	x = K;
	ap = NULL;
	finished = FALSE;
	
	while(q && !finished)
	{
		Insert(q, i, x, ap);	//��x��ap�ֱ���뵽q->key[i+1]��q->ptr[i+1]
		
		if(q->keynum<M)
			finished = TRUE;	//�������
		else					//�ؼ�����Ŀ��������	
		{
			s = ceil((double)M/2);	//B������йؼ��ָ�������>=ceil(M/2)-1
			split(q, s, &ap);	//���ѽ��*q 
			x = q->key[s];		//��q->key[s+1...M],q->ptr[s...M]�����½��*ap;			
			q = q->parent;
			
			if(q)				//��˫�׽��*q�в���x�Ĳ���λ�� 
				i = Search(q, x); 
		}
	}
	
	if(!finished)				//BT�ǿ���������q��ֵΪNULL�����߸�����ѷ���Ϊ���*q��*ap 
		NewRoot(BT, q, x, ap); 	//���ɺ���Ϣ(BT,x,ap)���µĸ����*BT��ԭBT��apΪ����ָ�� 
	
	return OK;
}

void Insert(BTree q, int i, KeyType x, BTree ap)
{
	int j;
	
	for(j=q->keynum; j>i; j--)
	{
		q->key[j+1] = q->key[j];
		q->ptr[j+1] = q->ptr[j];
	}
	
	q->key[i+1] = x;
	q->ptr[i+1] = ap;
	q->keynum++;
}

void split(BTree q, int s, BTree *ap)				//s��ֵΪ��M/2��
{	
	int i;
	
	(*ap) = (BTree)malloc(sizeof(BTNode));
	(*ap)->ptr[0] = q->ptr[s];
	
	for(i=s+1; i<=M; i++)
	{
		(*ap)->key[i-s] = q->key[i];
		(*ap)->ptr[i-s] = q->ptr[i];
		
/*
		if((*ap)->ptr[i-s])
			(*ap)->ptr[i-s]->parent = *ap;*/
	}
	
	(*ap)->keynum = M-s;
	q->keynum = s - 1;
	
	(*ap)->parent = q->parent;
	
	for(i=0; i<=(*ap)->keynum; i++)
	{
		if((*ap)->ptr[i])
			(*ap)->ptr[i]->parent = *ap;
	}
}

void NewRoot(BTree *BT, BTree q, int x, BTree ap)	//q��ʼֵΪ��
{ 
	BTree p;

	p = (BTree)malloc(sizeof(BTNode));
	p->keynum = 1;
	p->parent = NULL;
	p->key[1] = x;
	p->ptr[0] = *BT;
	p->ptr[1] = ap;
	
	if(p->ptr[0])
		p->ptr[0]->parent = p;
	if(p->ptr[1])
		p->ptr[1]->parent = p;
	
	*BT = p;	
}

Status DeleteKey(BTree *BT, KeyType K)
{
	Result R;
	
	R = SearchBTree(*BT, K);
	
	if(R.tag==1)							//B���д��ڴ˹ؼ��� 
	{
		DeleteBTree(BT, R.pt, R.i);
		return OK;	
	}
	else
		return ERROR;
}

Status DeleteBTree(BTree *BT, BTree q, int i)
{
	Result R = {q, i, 1};
	
	if(i<1||i>q->keynum)					//��i���ؼ�������� 
		return ERROR;
	
	if(q->ptr[i])
		SearchMinKey(q->ptr[i], &R);
		
	q->key[i] = R.pt->key[R.i];				//������������С����滻��ǰ���		 
		
	Delete(BT, R.pt, R.i);					//��ʼɾ��R.pt�е�R.i���ն˽��
	
	return OK;
}

void Delete(BTree *BT, BTree q, int i)
{
	int s, tag, order, count;
	BTree p, lc, rc;
	
	s = ceil((double)M/2);
	p = NULL;									//ָ��p�ĸ���� 
	order = -1;									//qΪp�ĵ�j���ؼ��� 
	
	tag = 0;									//��ʼ��Ϊ0 
	
	if(!FoundParent(q, &p, &order))				//ֻ��һ�������
		tag = 1;
	else
	{
		if(q->keynum>=s)						//q->keynum>=��M/2��
			tag = 2;							//ֱ��ɾ����� 
		else									//q->keynum==��M/2��-1 
		{			
			if(tag==0 && order<p->keynum && p->ptr[order+1]->keynum>=s)
				tag = 3;						//���ֵܹؼ��ָ���>=��M/2��
			
			if(tag==0 && order>0 && p->ptr[order-1]->keynum>=s)
				tag = 4; 						//���ֵܹؼ��ָ���>=��M/2��
										
			if(tag==0 && order<p->keynum && p->ptr[order+1]->keynum==s-1)
				tag = 5;						//���ֵܹؼ��ָ���==��M/2��-1
			
			if(tag==0 && order>0 && p->ptr[order-1]->keynum==s-1 )
				tag = 6;						//���ֵܹؼ��ָ���==��M/2��-1
		}	
	}
	
	switch(tag)
	{
		case 1:
			if(q->keynum==1&&i==1)
			{
				*BT = q->ptr[0];
				free(q);
			}
			else
			{
				LeftMove(q, i+1, q, i, q->keynum-i);
				q->keynum--;			
			}
			break;
		case 2:
			LeftMove(q, i+1, q, i, q->keynum-i);
			q->keynum--;
			break;
		case 3:
			rc = p->ptr[order+1];
			LeftMove(q, i+1, q, i, q->keynum-i);
			q->key[q->keynum] = p->key[order+1];
			q->ptr[q->keynum] = rc->ptr[0];
			p->key[order+1] = rc->key[1];
			rc->ptr[0] = rc->ptr[1];
			LeftMove(rc, 2, rc, 1, rc->keynum-1);
			rc->keynum--;
			break;
		case 4:
			lc = p->ptr[order-1];
			q->ptr[i] = q->ptr[i-1];
			RightMove(q, i-1, q, i, i-1);
			q->key[1] = p->key[order];
			q->ptr[0] = lc->ptr[lc->keynum];
			p->key[order] = lc->key[lc->keynum];			
			lc->keynum--;
			break;
		case 5:
			rc = p->ptr[order+1];
			LeftMove(q, i+1, q, i, q->keynum-i);
			q->key[q->keynum] = p->key[order+1];
			q->ptr[q->keynum] = rc->ptr[0];
			LeftMove(rc, 1, q, q->keynum+1, rc->keynum);
			q->keynum += rc->keynum;
			free(p->ptr[order+1]);
			LeftMove(p, order+2, p, order+1, p->keynum-order-1);
			p->keynum--;
			if(p->keynum<s-1)
			{
				p->keynum++;				//����һ������ؼ��� 
				q = p;
				Delete(BT, q, q->keynum);
			}
			break;
		case 6:
			lc = p->ptr[order-1];
			lc->key[lc->keynum+1] = p->key[order];
			lc->ptr[lc->keynum+1] = q->ptr[0];
			LeftMove(q, 1, lc, lc->keynum+2, i-1);
			LeftMove(q, i+1, rc, lc->keynum+i+1, q->keynum-i);
			lc->keynum += q->keynum;
			free(p->ptr[order]);
			LeftMove(p, order+1, p, order, p->keynum-order);
			p->keynum--;
			if(p->keynum<s-1)
			{
				p->keynum++;				//����һ������ؼ��� 
				q = p;
				Delete(BT, q, q->keynum);				
			}
			break;
	}
}

Status SearchMinKey(BTree BT, Result *R)
{
	BTree q = BT;
	
	while(q && q->ptr[0])					//�����²�����˽���ƶ�
		q = q->ptr[0];
	
	if(q)
	{
		(*R).pt = q;
		(*R).i = 1;
		(*R).tag = 1;
		return OK;
	}
	else
		return ERROR;	
}

Status FoundParent(BTree q, BTree *p, int *order)	//B����Ϊ�� 
{
	*p = q->parent;
	
	if(*p==NULL)								//qָ������ 
	{
		*order = -1;
		return ERROR;
	}
	else
	{
		for(*order=0; (*p)->ptr[*order]!=q; (*order)++)
			;
		return OK;
	}
}

Status LeftMove(BTree old_ptr, int m, BTree new_ptr, int n, int len)
{
	int k;
	
	if(!old_ptr || !new_ptr || m<1 || m>old_ptr->keynum)
		return ERROR;
	
	for(k=0; k<len; k++,m++,n++)
	{
		new_ptr->key[n] = old_ptr->key[m];
		new_ptr->ptr[n] = old_ptr->ptr[m];
	}
	
	return OK;
}

Status RightMove(BTree old_ptr, int m, BTree new_ptr, int n, int len)
{
	int k;

	if(!old_ptr || !new_ptr || m<1 || m>old_ptr->keynum)
		return ERROR;
	
	for(k=0; k<len; k++,m--,n--)
	{
		new_ptr->key[n] = old_ptr->key[m];
		new_ptr->ptr[n-1] = old_ptr->ptr[m-1];
	}
	
	return OK;
}

void PrintBT_Level(BTree BT)
{
	BTree p[100], q[100];
	int i, j, k;
	int a, b, count;
	
	a = 1;
	p[a] = BT;
	count = 0;
	
	while(a)
	{
		printf("  �� %2d �йؼ��֣�", ++count);
		
		b = 0;
		for(i=1; i<=a; i++)
		{
			printf("(");			
			for(j=0; j<=p[i]->keynum; j++)
			{
				if(j)
					printf(" %2d", p[i]->key[j]);
				
				if(p[i]->ptr[j])
					q[++b] = p[i]->ptr[j];
			}
			printf(") ");			
		}
		
		printf("\n");
		
		a = b;
		for(k=1; k<=b; k++)
			p[k] = q[k];
	}
}

void PrintBT_InOreder(BTree BT)
{
	int j;
	
	if(BT)
	{
		for(j=0; j<=BT->keynum; j++)
		{
			PrintBT_InOreder(BT->ptr[j]);
			if(j<BT->keynum)
				printf("%d ", BT->key[j+1]);		
		}	
	}
}

#endif

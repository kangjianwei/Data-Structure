/*****************************
 *						     *
 * �ļ���: ��08 ��̬�洢���� *
 * 						     *
 * �ļ���: BuddySystem.c     *
 *    	    			     *
 * ��  ��: 8.2               * 
 *    	    				 *
 *****************************/

#ifndef BUDDYSYSTEM_C
#define BUDDYSYSTEM_C

#include "BuddySystem.h" 					//**��08 ��̬�洢����**//

void InitSpace_b(FreeList avail)
{
	int k;
	WORD_b *r;
	
	for(k=0; k<=M; k++)
	{
		avail[k].nodesize = (int)pow(2, k);
		avail[k].first = NULL;
	}
	
	r = (WORD_b *)malloc((int)pow(2, M)*sizeof(WORD_b));
	if(!r)
		exit(OVERFLOW);
	r->llink = r->rlink = r;
	r->tag = 0;
	r->kval = M;
	
	avail[M].first = r;
	
	start = r;
	end = r + avail[M].nodesize - 1;
}

/*�T�T�T�T�[
�U �㷨8.2�U 
�^�T�T�T�T*/
WORD_b* AllocBuddy(FreeList avail, int n)	//avail[0..m]Ϊ�����ÿռ��nΪ��������� 
{											//������־���ڷ���n���ڴ� 
	int k, i;
	WORD_b *pa, *pre, *suc, *pi;
	
	for(k=0; k<=M && (avail[k].nodesize<n || !avail[k].first); k++)
		;									//�����������Ҫ����ӱ� 
	
	if(k>M)
		return NULL;						//����ʧ�ܣ�����NULL
	else									//���з��� 
	{
		pa = avail[k].first;				//ָ��ɷ����ӱ�ĵ�һ����� 
		pre = pa->llink;					//�ֱ�ָ��ǰ���ͺ�� 
		suc = pa->rlink;
		
		if(pa==suc)
			avail[k].first = NULL;
		else
		{
			pre->rlink = suc;
			suc->llink = pre;
			avail[k].first = suc;
		}
		
		for(i=1; k-i>=0 && avail[k-i].nodesize>=n; i++)
		{
			pi = pa + (int)pow(2, k-i);
			pi->rlink = pi;
			pi->llink = pi;
			pi->tag = 0;
			pi->kval = k - i;
			avail[k-i].first = pi;
		}
		
		pa->tag = 1;
		pa->kval = k - (--i);
	}
	
	return pa;	
}

WORD_b* Buddy(WORD_b* p)	//startԭʼ���п���� 
{
	int s, m, n;
	
	s = p - start;	
	m = (int)pow(2, p->kval);
	n = (int)pow(2, p->kval+1);
	
	if(s%n==0)
		return p + m;
	
	if(s%n==m)
		return p - m;
}

void Reclaim_b(FreeList avail, WORD_b** p)
{
	WORD_b* s;
	
	s = Buddy(*p);			//sָ��p�Ļ��ĵ�ַ 
	
	while(s>=start && s<=end && s->tag==0 && s->kval==(*p)->kval)
	{
		if(s->llink==s && s->rlink==s)		//�����Ͻ���һ�����
			avail[s->kval].first = NULL;
		else
		{
			s->llink->rlink = s->rlink;
			s->rlink->llink = s->llink;
			
			if(avail[s->kval].first==s)					//s��������׽�� 
				avail[s->kval].first = s->rlink;
		}
		
		if((int)(*p-start)%(int)pow(2, (*p)->kval+1)==0)	//pΪǰ��
			(*p)->kval++;
		else
		{
			s->kval = (*p)->kval + 1;
			*p = s;
		}
		
		s = Buddy(*p);
	}
	
	(*p)->tag = 0;
	if(avail[(*p)->kval].first==NULL)
		avail[(*p)->kval].first = (*p)->llink = (*p)->rlink = *p;
	else
	{
		(*p)->rlink = avail[(*p)->kval].first;
		(*p)->llink = (*p)->rlink->llink;
		(*p)->rlink->llink = *p;
		(*p)->llink->rlink = *p;
		avail[(*p)->kval].first = *p;
	}
	
	*p = NULL;
}

void PrintLayout_b(FreeList avail)
{
	int k;
	WORD_b *r;
	int mark;
	
	for(k=0,mark=0; k<=M; k++)		//�ж��ڴ��Ƿ�ռ�� 
	{
		if(avail[k].first)
		{
			mark = 1;
			break;
		}
	}
	
	if(!mark)
		printf("�ڴ��ѱ�ռ����");
	else
	{
		printf("���п���ֹ��Χ��");
		for(k=0; k<=M; k++)
		{
			r = avail[k].first;
			if(r)
			{
				printf("��%d����%d", r-start+1, r+(int)pow(2, r->kval)-start);
				while(r->rlink!=avail[k].first)
				{
					r = r->rlink;
					printf("��%d����%d", r-start+1, r+(int)pow(2, r->kval)-start);
				}		
			}
		}	
	}
	printf("\n");
}

#endif

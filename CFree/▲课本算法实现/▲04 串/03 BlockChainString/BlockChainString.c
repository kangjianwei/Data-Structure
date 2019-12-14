/***************************************
 *                                     *
 * �ļ���: ��04 ��\03 BlockChainString *
 *                                     *
 * �ļ���: BlockChainString.c          *
 *                                     *
 ***************************************/

#ifndef BLOCKCHAINSTRING_C
#define BLOCKCHAINSTRING_C

#include "BlockChainString.h" 				//**��04 ��**//

void InitString_L(LString *T)
{
	(*T).head = NULL;
	(*T).tail = NULL;
	(*T).curlen = 0;
}

Status StrAssign_L(LString *T, char *chars)
{
	int len, i, j, k, count; 
	Chunk *r;
	
	InitString_L(T);
	
	len = strlen(chars);
	if(!len)								//charsΪ���ַ�ʱ���� 
		return ERROR;

	i = len / CHUNKSIZE;					//iΪ������ 
	j = len % CHUNKSIZE;					//jΪ������֮�������ַ�
	if(j) 
		i++;
	
	for(k=1; k<=i; k++)
	{
		r = (Chunk*)malloc(sizeof(Chunk));
		if(!r)
			exit(OVERFLOW);
		r->next = NULL;
		
		if(k==1)							//��һ����
			(*T).head = (*T).tail = r;
	 	else								//������֮��Ŀ� 
		{
			(*T).tail->next = r;
			(*T).tail = r;
		}
		
		for(count=0; count<CHUNKSIZE&&count+(k-1)*CHUNKSIZE<len; count++)
			(*T).tail->ch[count] = chars[count+(k-1)*CHUNKSIZE];	//����chars��T	
	}
	
	while(count<CHUNKSIZE)
	{
		(*T).tail->ch[count] = '\0';		//T�ж���ռ䲹��'\0' 
		count++;
	}
	
	(*T).curlen = len;
	
	return OK;
} 

Status StrCopy_L(LString *T, LString S)
{
	int i; 
	Chunk *r, *p;
	
	InitString_L(T);
	
	for(p=S.head; p; p=p->next)
	{
		r = (Chunk*)malloc(sizeof(Chunk));
		if(!r)
			exit(OVERFLOW);
		r->next = NULL;
		
		if(p==S.head)
			(*T).head = (*T).tail = r;
		else
		{
			(*T).tail->next = r;
			(*T).tail = r;
		}
		
		for(i=0; i<CHUNKSIZE; i++)
			(*r).ch[i] = (*p).ch[i];
	}
		
	(*T).curlen = S.curlen;

	return OK;
}

Status StrEmpty_L(LString S)
{
	if(S.head==NULL && S.tail==NULL && S.curlen==0)
		return TRUE;
	else
		return ERROR;
}

int StrCompare_L(LString S, LString T)
{
	int i;
	int s = S.curlen;
	int t = T.curlen;
	Chunk *p = S.head;
	Chunk *q = T.head;
	
	while(p && q)					//p��q����Ϊ��
	{
		for(i=0; i<CHUNKSIZE; i++)
		{
			if((*p).ch[i]!=(*q).ch[i])
				return (*p).ch[i]-(*q).ch[i];		
		}

		p = p->next;
		q = q->next;
	}
	
	return s-t;	
}

int StrLength_L(LString S)
{
	return S.curlen;
}

void ClearString_L(LString *S)
{
	Chunk *p, *q;
	
	p = (*S).head;
	
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	
	(*S).head = NULL;
	(*S).tail = NULL;
	(*S).curlen = 0;
}

void Concat_L(LString *T, LString S1, LString S2)
{
	int i, j, k, count;
	Chunk *r, *p, *q;
	
	InitString_L(T);
	
	r = (*T).head;
	p = S1.head;
	q = S2.head;
	i = j = k = 0;		//i��j��k�ֱ����T��S1��S2 
	
	while(p || q)
	{		
		if(!r)
		{
			r = (Chunk*)malloc(sizeof(Chunk));
			if(!r)
				exit(OVERFLOW);
			r->next = NULL;
				
			if(!(*T).head)
				(*T).head = (*T).tail = r;
			else
			{
				(*T).tail->next = r;
				(*T).tail = r;			
			}
		}
		
		if(p)
		{
			while(p && p->ch[j])
			{
				r->ch[i] = p->ch[j];	
				i = (i + 1) % CHUNKSIZE;
				j = (j + 1) % CHUNKSIZE;
				
				if(!j || !(p->ch[j]))
					p = p->next;
				if(!i)
				{
					r = r->next;
					break;
				}					
			}
		}
		else
		{
			while(q && q->ch[k])
			{
				r->ch[i] = q->ch[k];	
				i = (i + 1) % CHUNKSIZE;
				k = (k + 1) % CHUNKSIZE;
				
				if(!k || !(q->ch[k]))
					q = q->next;
				if(!i)
				{
					r = r->next;
					break;
				}					
			}		
		}		
	}

	(*T).curlen = S1.curlen + S2.curlen;
	
	count = ((*T).curlen-1) % CHUNKSIZE + 1;
	while(count<CHUNKSIZE)
	{
		(*T).tail->ch[count] = '\0';
		count++;
	}	
}

Status SubString_L(LString *Sub, LString S, int pos, int len)
{
	int i, j, k, count;
	Chunk *r, *p;
	
	InitString_L(Sub);
	
	if(StrEmpty_L(S))
		return ERROR;

	if(pos<1 || pos>S.curlen || len<0 || pos+len-1>S.curlen)
		return ERROR;
	
	for(count=1,p=S.head; pos>count*CHUNKSIZE; count++,p=p->next)
		;			//pָ���pos��Ԫ�� 
	
	r = (*Sub).head;
	i = 0;							//i���Ʊ���Ԫ�ظ��� 
	j = 0;							//j����Sub 
	k = (pos % CHUNKSIZE) - 1;		//k����S 

	while(i<len)
	{
		if(!r)
		{
			r = (Chunk*)malloc(sizeof(Chunk));
			if(!r)
				exit(OVERFLOW);
			r->next = NULL;
				
			if(!(*Sub).head)
				(*Sub).head = (*Sub).tail = r;
			else
			{
				(*Sub).tail->next = r;
				(*Sub).tail = r;			
			}		
		}
		
		while(i<len)
		{	
			(*r).ch[j] = (*p).ch[k];	
			j = (j + 1) % CHUNKSIZE;
			k = (k + 1) % CHUNKSIZE;
			i++;
			
			if(!k)
				p = p->next;
			if(!j)
			{
				r = r->next;
				break;			
			}
		}	
	}
	
	(*Sub).curlen = len;
	
	count = ((*Sub).curlen-1) % CHUNKSIZE + 1;
	while(count<CHUNKSIZE)
	{
		(*Sub).tail->ch[count] = '\0';
		count++;
	}	
	
	return OK;	
}
 
int Index_L(LString S, LString T, int pos)
{
	int i, s, t;
	LString sub;
	
	if(pos>0 && pos<=S.curlen)
	{
		s = S.curlen; 				//��������
		t = T.curlen; 				//T������
		i = pos;
     
		while(i+t-1<=s)
		{
			SubString_L(&sub, S, i, t); 	//subΪ��S�ĵ�i���ַ���,����Ϊt���Ӵ�

			if(StrCompare_L(sub, T)!=0) 	//sub������T
				i++;
			else
				return i;
		}
   }
   
   return 0;						//�Ҳ���ƥ����򷵻�0 
}

Status Replace_L(LString *S, LString T, LString V)
{
	int i;
	
	if(StrEmpty_L(T))
		return ERROR;
		
	i = Index_L(*S, T, 1);

	while(i)						//���ҵ���Tƥ����ַ���
	{ 
		StrDelete_L(S, i, StrLength_L(T));
		StrInsert_L(S, i, V);
		i += StrLength_L(V);
		i = Index_L(*S, T, i);
	}
	
	return OK; 
}

Status StrInsert_L(LString *S, int pos, LString T)
{
	Chunk *r, *p1, *p2, *q;
	int i, j, k, count;
	LString Tmp;

	if(pos<1 || pos>(*S).curlen+1)
		return ERROR;

	InitString_L(&Tmp);
	
	r = Tmp.head;
	p1 = (*S).head;
	p2 = NULL;
	q = T.head;
	i = j = k = 0;
	count = 1;
	
	while(p1 || p2 || q)
	{
		if(!r)
		{
			r = (Chunk*)malloc(sizeof(Chunk));
			if(!r)
				exit(OVERFLOW);
			r->next = NULL;
				
			if(!Tmp.head)
				Tmp.head = Tmp.tail = r;
			else
			{
				Tmp.tail->next = r;
				Tmp.tail = r;			
			}		
		}
		
		if(p1)
		{
			while(p1 && count<pos)
			{
				r->ch[i] = p1->ch[j];	
				i = (i + 1) % CHUNKSIZE;
				j = (j + 1) % CHUNKSIZE;
				count++;
				
				if(!j || !(p1->ch[j]))
					p1 = p1->next;
				if(!i)
				{
					r = r->next;
					break;
				}					
			}
			
			if(count==pos)
			{
				p2 = p1;
				p1 = NULL;
			}			
		}
		else if(q)
		{
			while(q && q->ch[k])
			{
				r->ch[i] = q->ch[k];	
				i = (i + 1) % CHUNKSIZE;
				k = (k + 1) % CHUNKSIZE;
				
				if(!k || !(q->ch[k]))
					q = q->next;
				if(!i)
				{
					r = r->next;
					break;
				}					
			}		
		}
		else
		{
			while(p2 && p2->ch[j])
			{
				r->ch[i] = p2->ch[j];	
				i = (i + 1) % CHUNKSIZE;
				j = (j + 1) % CHUNKSIZE;
				
				if(!j || !(p2->ch[j]))
					p2 = p2->next;
				if(!i)
				{
					r = r->next;
					break;
				}					
			}		
		}
	}
	
	Tmp.curlen = (*S).curlen + T.curlen;

	count = (Tmp.curlen-1)%CHUNKSIZE+1;
	while(count<CHUNKSIZE)
	{
		Tmp.tail->ch[count] = '\0';
		count++;
	}
	
	ClearString_L(S);
	
	(*S).curlen = Tmp.curlen;
	(*S).head = Tmp.head;
	(*S).tail = Tmp.tail;
	
	return OK;
}

Status StrDelete_L(LString *S, int pos, int len)
{
	Chunk *p, *q, *r;
	int count, first, last, m, n;

	if(pos<1 || pos>(*S).curlen || len<0 || pos+len-1>(*S).curlen)
		return ERROR;
	
	if(pos==1&&len==(*S).curlen)
		ClearString_L(S);
		
	first  = pos;
	last = pos+len-1;
	
	for(count=1,p=(*S).head; first>count*CHUNKSIZE; count++,p=p->next)
		;		//pָ��first���ڿ�
	
	for(q=p; last>count*CHUNKSIZE; count++,q=q->next)
		;		//qָ��last���ڿ�
	
	m = (first-1)%CHUNKSIZE;		//ɾ���������� 
	n = (last-1)%CHUNKSIZE;			//ɾ���յ������ 
	
	n = (n+1)%CHUNKSIZE;
	if(!n)
		q = q->next;
	
	while(q && q->ch[n])
	{
		p->ch[m] = q->ch[n];
		m = (m+1)%CHUNKSIZE;
		n = (n+1)%CHUNKSIZE;
		
		if(!m)
			p = p->next;	
		if(!n)
			q = q->next;		
	}
	
	(*S).curlen -= len;
	
	for(count=1,(*S).tail=(*S).head; (*S).curlen>count*CHUNKSIZE; count++,(*S).tail=(*S).tail->next)
		;							//rָ��ɾ����ɺ���յ��� 
	
	count = ((*S).curlen-1) % CHUNKSIZE + 1;
	while(count<CHUNKSIZE)
	{
		(*S).tail->ch[count] = '\0';
		count++;
	}
	
	r = (*S).tail->next;
	while(r)
	{
		(*S).tail->next = r->next;
		free(r);
		r = (*S).tail->next;
	}
	
	return OK;
}

void DestroyString_L(LString *S)
{
	//�����洢�ṹ�Ĵ����ܱ����� 
}

void StrPrint_L(LString S)
{
	int i = 0;
	Chunk *p = S.head;
	
	if(S.head==NULL && S.tail==NULL && S.curlen==0)
		printf("SΪ�մ����޷������");
	
	while(p)
	{
		if((*p).ch[i])
			printf("%c", (*p).ch[i]);
		i = (i + 1) % CHUNKSIZE;
		if(!i)
			p = p->next;
	}
}

/* δ���������в��� */ 
Status GetChar_L(LString S, char *c, int i)
{
	int m, n, count;
	Chunk *p;

	if(StrEmpty_L(S))
		return ERROR;

	if(i<1 || i>S.curlen)
		return ERROR;

	m = i / CHUNKSIZE;				//�����i��Ԫ���ڵڼ����� 
	n = i % CHUNKSIZE;				//�����i��Ԫ���ǵ�m�����еĵڼ���Ԫ�� 
	if(n)
		m++;

	for(count=1,p=S.head; count<m; count++)
		p = p->next;				//pָ���i��Ԫ�������Ŀ� 

	if(n)
		*c = (*p).ch[n-1];			//ע��ÿ���������һ���ַ��Ĵ��� 
	else
		*c = (*p).ch[CHUNKSIZE-1];

	return OK;
}

#endif

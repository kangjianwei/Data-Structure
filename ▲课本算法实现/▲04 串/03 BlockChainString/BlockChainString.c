/***************************************
 *                                     *
 * 文件夹: ▲04 串\03 BlockChainString *
 *                                     *
 * 文件名: BlockChainString.c          *
 *                                     *
 ***************************************/

#ifndef BLOCKCHAINSTRING_C
#define BLOCKCHAINSTRING_C

#include "BlockChainString.h" 				//**▲04 串**//

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
	if(!len)								//chars为空字符时错误 
		return ERROR;

	i = len / CHUNKSIZE;					//i为整块数 
	j = len % CHUNKSIZE;					//j为整块数之外多余的字符
	if(j) 
		i++;
	
	for(k=1; k<=i; k++)
	{
		r = (Chunk*)malloc(sizeof(Chunk));
		if(!r)
			exit(OVERFLOW);
		r->next = NULL;
		
		if(k==1)							//第一个块
			(*T).head = (*T).tail = r;
	 	else								//联接起之后的块 
		{
			(*T).tail->next = r;
			(*T).tail = r;
		}
		
		for(count=0; count<CHUNKSIZE&&count+(k-1)*CHUNKSIZE<len; count++)
			(*T).tail->ch[count] = chars[count+(k-1)*CHUNKSIZE];	//复制chars到T	
	}
	
	while(count<CHUNKSIZE)
	{
		(*T).tail->ch[count] = '\0';		//T中多余空间补上'\0' 
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
	
	while(p && q)					//p、q均不为空
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
	i = j = k = 0;		//i、j、k分别遍历T、S1、S2 
	
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
		;			//p指向第pos个元素 
	
	r = (*Sub).head;
	i = 0;							//i控制变量元素个数 
	j = 0;							//j遍历Sub 
	k = (pos % CHUNKSIZE) - 1;		//k遍历S 

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
		s = S.curlen; 				//主串长度
		t = T.curlen; 				//T串长度
		i = pos;
     
		while(i+t-1<=s)
		{
			SubString_L(&sub, S, i, t); 	//sub为从S的第i个字符起,长度为t的子串

			if(StrCompare_L(sub, T)!=0) 	//sub不等于T
				i++;
			else
				return i;
		}
   }
   
   return 0;						//找不到匹配的则返回0 
}

Status Replace_L(LString *S, LString T, LString V)
{
	int i;
	
	if(StrEmpty_L(T))
		return ERROR;
		
	i = Index_L(*S, T, 1);

	while(i)						//能找到与T匹配的字符串
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
		;		//p指向first所在块
	
	for(q=p; last>count*CHUNKSIZE; count++,q=q->next)
		;		//q指向last所在块
	
	m = (first-1)%CHUNKSIZE;		//删除起点结点序号 
	n = (last-1)%CHUNKSIZE;			//删除终点结点序号 
	
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
		;							//r指向删除完成后的终点结点 
	
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
	//块链存储结构的串不能被销毁 
}

void StrPrint_L(LString S)
{
	int i = 0;
	Chunk *p = S.head;
	
	if(S.head==NULL && S.tail==NULL && S.curlen==0)
		printf("S为空串，无法输出！");
	
	while(p)
	{
		if((*p).ch[i])
			printf("%c", (*p).ch[i]);
		i = (i + 1) % CHUNKSIZE;
		if(!i)
			p = p->next;
	}
}

/* 未在主函数中测试 */ 
Status GetChar_L(LString S, char *c, int i)
{
	int m, n, count;
	Chunk *p;

	if(StrEmpty_L(S))
		return ERROR;

	if(i<1 || i>S.curlen)
		return ERROR;

	m = i / CHUNKSIZE;				//计算第i个元素在第几个块 
	n = i % CHUNKSIZE;				//计算第i个元素是第m个块中的第几个元素 
	if(n)
		m++;

	for(count=1,p=S.head; count<m; count++)
		p = p->next;				//p指向第i个元素所属的块 

	if(n)
		*c = (*p).ch[n-1];			//注意每个块中最后一个字符的处理 
	else
		*c = (*p).ch[CHUNKSIZE-1];

	return OK;
}

#endif

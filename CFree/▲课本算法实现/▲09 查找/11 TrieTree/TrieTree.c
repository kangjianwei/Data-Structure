/**********************
 *                    *
 * 文件夹: ▲09 查找  *
 *                    *
 * 文件名: TrieTree.c *
 *                    *
 * 算  法: 9.16       *
 *                    *
 **********************/

#ifndef TRIETREE_C
#define TRIETREE_C

#include "TrieTree.h" 				//**▲09 查找**//

Status CreateTrie(FILE *fp, TrieTree *TT)
{
	Record tmp;
	int i;
	
	*TT = NULL;
	i = 0;
	
	while(Scanf(fp, "%s", &(tmp.key))==1)
		InsertTrie(TT, tmp); 
		
	return OK;
}

/*════╗
║算法9.16║ 
╚════*/
Record* SearchTrie(TrieTree TT, KeysType K)
{
	TrieTree p;
	int i;
	 
	for(p=TT,i=0; p&&p->kind==BRANCH&&i<=K.num; p=p->Ptr.bh.ptr[ord(K.ch[i])],i++)
		;
	
	if(p&&p->kind==LEAF&&cmp(p->Ptr.lf.K,K))
		return p->Ptr.lf.infoptr;					//查找成功
	else
		return NULL;								//查找不成功 
} 

Status InsertTrie(TrieTree *TT, Record R)
{
	TrieTree p, pre, np;
	int i, j;
	Record *r;
	KeysType Ko, K;
	
	r = (Record *)malloc(sizeof(Record));
	*r = R;
	strcpy(K.ch, R.key);
	K.num = strlen(R.key);
	
	if(!*TT)										//空树 
	{
		*TT = (TrieTree)malloc(sizeof(TrieNode));
		(*TT)->kind = BRANCH;
		for(i=0; i<=MAXKEYLEN; i++)
			(*TT)->Ptr.bh.ptr[i] = NULL;
		(*TT)->Ptr.bh.count = 0;
		
		p = (TrieTree)malloc(sizeof(TrieNode));		
		p->kind = LEAF;
		p->Ptr.lf.K = K;
		p->Ptr.lf.infoptr = r;
		(*TT)->Ptr.bh.ptr[ord(R.key[0])] = p;
		(*TT)->Ptr.bh.count++;
	}
	else											//非空树 
	{
		for(pre=NULL,p=*TT,i=0; p&&p->kind==BRANCH&&i<=K.num; pre=p,p=p->Ptr.bh.ptr[ord(R.key[i])],++i)
			;
		
		i--;										//退回失配的位置 
		
		if(p&&p->kind==LEAF&&cmp(p->Ptr.lf.K,K))
			return ERROR;							//记录已存在
		else
		{
			if(!p)
			{
				p = (TrieTree)malloc(sizeof(TrieNode));
				p->kind = LEAF;
				p->Ptr.lf.K = K;
				p->Ptr.lf.infoptr = r;
				pre->Ptr.bh.ptr[ord(R.key[i])] = p;
				pre->Ptr.bh.count++;
			}
			else
			{
				if(p->kind==LEAF)
				{
					Ko = p->Ptr.lf.K;
					pre->Ptr.bh.count--;
					
					do
					{
						np = (TrieTree)malloc(sizeof(TrieNode));
						np->kind = BRANCH;
						for(j=0; j<=MAXKEYLEN; j++)
							np->Ptr.bh.ptr[j] = NULL;
						np->Ptr.bh.count = 0;
						
						pre->Ptr.bh.ptr[ord(K.ch[i])] = np;
						pre->Ptr.bh.count++;
						pre = np;
						i++;	
					}while(ord(K.ch[i])==ord(Ko.ch[i]));
					
					pre->Ptr.bh.ptr[ord(Ko.ch[i])] = p;
					pre->Ptr.bh.count++;
					
					p = (TrieTree)malloc(sizeof(TrieNode));
					p->kind = LEAF;
					p->Ptr.lf.K = K;
					p->Ptr.lf.infoptr = r;
					pre->Ptr.bh.ptr[ord(K.ch[i])] = p;
					pre->Ptr.bh.count++;
				}
			}			
		} 
	}
}

Status DeleteTrie(TrieTree *TT, KeysType K)
{
	TrieTree p, pre, prepre, r;
	KeysType K0;
	int i, j;
		
	p=*TT, prepre=pre=NULL, i=0;
	
	while(p && p->kind==BRANCH && i<=K.num)
	{
		prepre = pre;
		pre = p;
		p = p->Ptr.bh.ptr[ord(K.ch[i])];
		i++;
	}

	if(p && p->kind==LEAF && cmp(p->Ptr.lf.K,K))			//查找成功，进行删除 
	{
		free(p->Ptr.lf.infoptr);							//释放叶子结点指向的记录 
		free(pre->Ptr.bh.ptr[ord(K.ch[i-1])]);				//释放记录 
		pre->Ptr.bh.ptr[ord(K.ch[i-1])] = NULL;
		pre->Ptr.bh.count--;
		
		if(pre->Ptr.bh.count==0)							//只可能发生在根结点上
		{
			free(*TT);
			*TT = NULL;
		}
		else
		{
			if(pre->Ptr.bh.count==1 && pre!=*TT)			//收缩剩余结点到上一个分支结点 
			{
				if(pre->Ptr.bh.ptr[0])						//只剩0号单元位置的结点 
				{
					r = pre->Ptr.bh.ptr[0];
					free(prepre->Ptr.bh.ptr[ord(K.ch[i-2])]);
					prepre->Ptr.bh.ptr[ord(K.ch[i-2])] = r;
				}				
				else										//查找另一个结点		
				{
					for(j=0,r=pre->Ptr.bh.ptr[j]; !r; r=pre->Ptr.bh.ptr[++j])
						;
						
					if(r->kind==LEAF)						//剩余结点为叶子结点时收缩 
					{
						K0 = r->Ptr.lf.K;
						r = pre->Ptr.bh.ptr[ord(K0.ch[i-1])];
						free(prepre->Ptr.bh.ptr[ord(K0.ch[i-2])]);
						prepre->Ptr.bh.ptr[ord(K0.ch[i-2])] = r;						
					}
				}					
			}
		}
		
		return OK; 
	}
	else
		return ERROR;		
}

int ord(char ch)
{
	if(isalpha(ch))
		return ch-'A'+1;
	else
		return 0;
}

Status cmp(KeysType A, KeysType B)
{
	int i;
	
	if(A.num!=B.num)
		return ERROR;
	else
	{
		for(i=0; i<A.num; i++)
		{
			if(A.ch[i]!=B.ch[i])
				return ERROR;
		}	
	}
			
	return OK;
}

void TraverseTrie(TrieTree TT, void(Visit)(Record*))
{
	TrieTree p;
	int i;
	
	if(TT)
	{
//		printf("%d\n", TT->Ptr.bh.count);
		for(i=0; i<=MAXKEYLEN; i++)
		{
			p = TT->Ptr.bh.ptr[i];
			
			if(p&&p->kind==LEAF)
				Visit(p->Ptr.lf.infoptr);
			else
			{
				if(p&&p->kind==BRANCH)
					TraverseTrie(p, Visit);
			}
		}
	}
}

#endif

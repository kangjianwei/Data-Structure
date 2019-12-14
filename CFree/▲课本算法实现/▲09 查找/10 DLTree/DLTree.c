/*********************
 *                   *
 * 文件夹: ▲09 查找 *
 *                   *
 * 文件名: DLTree.c  *
 *                   *
 * 算  法: 9.15      *
 *                   *
 *********************/

#ifndef DLTREE_C
#define DLTREE_C

#include "DLTree.h" 				//**▲09 查找**//

Status CreateDLTree(FILE *fp, DLTree *DLT)
{
	KeysType tmp;
	
	*DLT = (DLTree)malloc(sizeof(DLTNode));	//创建根结点 
	(*DLT)->kind = BRANCH;					//根结点定义为分支结点
	(*DLT)->symbol = '\0';
	(*DLT)->next = NULL;
	(*DLT)->Ptr.first = NULL; 
	
	while(Scanf(fp, "%s", &(tmp.ch))==1)
	{
		tmp.num = strlen(tmp.ch);
		
		InsertDLTree(DLT, tmp); 
	}
		
	return OK;
}

/*════╗
║算法9.15║ 
╚════*/
Record* SearchDLTree(DLTree DLT, KeysType K)
{
	DLTree p;
	int i;
	
	p = DLT->Ptr.first;
	i = 0;
	
	while(p && i<K.num)
	{
		while(p && p->symbol<K.ch[i])
			p = p->next;					//查找关键字的第i位

		if(p && p->symbol==K.ch[i])
		{
			p = p->Ptr.first;				//继续查找下一位 
			i++;						
		}
		else								//查找不成功，强制跳出循环 
			p = NULL; 
	}										//查找结束 
	
	if(p && p->kind==LEAF)					//查找成功 
		return p->Ptr.infoptr;
	else									//查找失败 
		return NULL;
} 

Status InsertDLTree(DLTree *DLT, KeysType K)
{
	DLTree p, q, h;
	int i, j;
	Record *s;
	
	i = 0;
	q = *DLT;								//指向查找完成时倒数第二个结点
	p = q->Ptr.first;						//指向查找完成时最后一个结点 
	
	while(p && i<K.num)
	{
		while(p && p->symbol<K.ch[i])
		{
			q = p;
			p = p->next;					//查找关键字的第i位
		}
		
		if(p && p->symbol==K.ch[i])
		{
			q = p;
			p = p->Ptr.first;				//继续查找下一位 
			i++;						
		}
		else
			break;
	}
	
	if(i<K.num)							//未遍历完 
	{
		for(j=i; j<=K.num; j++)			//将K中剩余的字符插入树中 
		{
			h = (DLTree)malloc(sizeof(DLTNode));
			
			if(j==i)
			{
				h->kind = BRANCH;
				h->symbol = K.ch[j];
				h->next = p;
				h->Ptr.first = NULL;
				
				if(q->Ptr.first==p)		//判断p和q的相对位置是上下还是左右关系 
					q->Ptr.first = h;
				else
					q->next = h;
			}
			else if(j>i&&j<K.num)
			{
				h->kind = BRANCH;
				h->symbol = K.ch[j];
				h->next = NULL;
				h->Ptr.first = NULL;
				q->Ptr.first = h;
			}
			else
			{
				h->kind = LEAF;
				h->symbol = '$';
				h->next = NULL;
				s = (char*)malloc((K.num+1)*sizeof(char));
				h->Ptr.infoptr = strcpy(s, K.ch);
				q->Ptr.first = h;
			}
			
			q = h;
		}
	}
	else								//已遍历完 
	{
		if(p->symbol=='$')				//完全匹配 
			return ERROR;				//未进行插入操作 
		else							//待查找关键字是键树中的一部分 
		{
			s = (char*)malloc((K.num+1)*sizeof(char));
			h = (DLTree)malloc(sizeof(DLTNode));
			h->kind = LEAF;
			h->symbol = '$';
			h->next = p;
			h->Ptr.infoptr = strcpy(s, K.ch);
			q->Ptr.first = h;							
		}		
	}
	
	return OK;	
}

void PrintKeys(DLTree DLT)
{
	if(DLT)
	{
		if(DLT->symbol=='\0')
			PrintKeys(DLT->Ptr.first);
		else if(DLT->symbol=='$')
			printf("%s ", DLT->Ptr.infoptr);
		else
			PrintKeys(DLT->Ptr.first);
		PrintKeys(DLT->next);
	}
}

#endif

/***********************
 *                     *
 * 文件夹: ▲09 查找   *
 *                     *
 * 文件名: HashTable.c *
 *                     *
 * 算  法: 9.17、9.18  *
 *                     *
 ***********************/

#ifndef HASHTABLE_C
#define HASHTABLE_C

#include "HashTable.h" 				//**▲09 查找**//

void InitHash(HashTable *H)
{
	(*H).count = 0;
	(*H).sizeindex = -1;
	(*H).elem = NULL;
}

Status CreateHash(HashTable *H, Table T)
{
	int i, tag;
	
	InitHash(H);
	
	RecreateHashTable(H);
	
	i=1;
	while(i<=T.length)				//将T中关键字依次插入到哈希表中
	{
		tag = InsertHash(H, T.elem[i].key);
		if(tag==SUCCESS)			//表中已有关键字或关键字顺利插入 
			i++;
		else						//重建哈希表后重新填充 
			i=1;
	}
	
	return OK;
}

/*════╗
║算法9.17║ 
╚════*/
//重写了课本算法 
Status SearchHash(HashTable H, KeyType K, int *p)
{
	int c, sup;
	
	c = 0;							//记录冲突次数 	
	sup = hashsize[H.sizeindex]/2;	//冲突上限 
	*p = fHash(H, K);				//p指向K应该插入的地址 	

	while(1)						//该位置有记录且与K不等
	{
		if(H.elem[*p]==NULLKEY)
			return NULLKEY;			
		else if(EQ(H.elem[*p], K))
			return DUPLICATE;		//表中已有此关键字
		else if(++c==sup)			//已达冲突上限 
			return FULL;
		else
			collision(H, p);		//重新定位p的地址 
	}
} 

/*════╗
║算法9.18║ 
╚════*/
//重写了课本算法 
Status InsertHash(HashTable *H, KeyType K)
{
	int flag, p; 

	flag = SearchHash(*H, K, &p);
	
	if(flag==FULL)				//表已满 
	{
		RecreateHashTable(H);	//重建哈希表  
		return UNSUCCESS;
	}		
	else
	{
		if(flag==NULLKEY)
		{
			H->elem[p] = K;		//插入K
			++(*H).count;
		}
		return SUCCESS; 
	}
}

Status RecreateHashTable(HashTable *H)
{
	int i, newv;
	HashTable *p;
	
	(*H).count = 0;
	(*H).sizeindex++;
	newv = hashsize[(*H).sizeindex];
	 
	if((*H).elem!=NULL)
		free((*H).elem);
	
	//扩充了哈希表容量
	(*H).elem = (KeyType *)malloc(newv*sizeof(KeyType));
	if((*H).elem==NULL)
		return ERROR;
		
	for(i=0; i<newv; i++)
		(*H).elem[i] = NULLKEY;
	
	return OK;
}

int fHash(HashTable H, KeyType K)	//只是简单的取余 
{	
	return K % hashsize[H.sizeindex];
}

void collision(HashTable H, int *p)	//简单的移位 
{
	*p = (*p+1)%hashsize[H.sizeindex];
}

void PrintHash(HashTable H)
{
	int i, v;
	
	v = hashsize[H.sizeindex];
	
	printf("哈希表容量为：%d，现有元素：%d 个，表中元素为：\n", v, H.count);
	
	for(i=0; i<v; i++)
	{
		if(H.elem[i]!=NULLKEY)
			printf("%d ",H.elem[i]);
	}
	
	printf("\n");
}

#endif

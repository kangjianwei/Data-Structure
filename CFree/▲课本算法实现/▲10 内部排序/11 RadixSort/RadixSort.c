/*******************************
 *                             *
 * 文件夹: ▲10 内部排序       *
 *                             *
 * 文件名: RadixSort.c         *
 *                             *
 * 算  法: 10.15、10.16、10.17 *
 *                             *
 *******************************/

#ifndef RADIXSORT_C
#define RADIXSORT_C

#include "RadixSort.h" 							//**▲10 内部排序**//

void CreateSLList(FILE *fp, SLList *L)
{
	int i;
	char s[1000];
		
	Scanf(fp, "%d", &((*L).keynum));			//关键字个数 
	
	(*L).recnum = 0;							//静态链表当前长度 
	
	while(Scanf(fp, "%s", &s)==1)
	{
		(*L).recnum++;
		
		for(i=0; i<(*L).keynum; i++)			//按低位到高位的顺序将关键字存储到keys 
			(*L).r[(*L).recnum].keys[(*L).keynum-1-i] = s[i];
	}
	
	for(i=0; i<(*L).recnum; i++)				//将L改造为静态链表（循环） 
		(*L).r[i].next = i + 1;
	(*L).r[(*L).recnum].next = 0;	
}

void Traverse(SLList L)
{
	int i, j;
	
	for(i=L.r[0].next; i; i=L.r[i].next)
	{
		for(j=L.keynum-1; j>=0; j--)
			printf("%c", L.r[i].keys[j]);
		
		printf(" ");
	}
	
	printf("\n");
}

/*═════╗
║ 算法10.17║ 
╚═════*/
void RadixSort(SLList *L)
{
	int i;
	ArrType f, e;

	for(i=0; i<(*L).keynum; i++)				//按最低位优先依次对各关键字进行分配和收集 
	{
		Distribute((*L).r, i, f, e);			//第i趟分配 
		Collect((*L).r, i, f, e);				//第i趟收集
	}
}

/*═════╗
║ 算法10.15║ 
╚═════*/
void Distribute(SLCell r[], int i, ArrType f, ArrType e)
{
	int j, p;
	
	for(j=0; j<RADIX; j++)						//各子表初始化为空表
	{
		f[j] = 0;
		e[j] = 0;	
	}
	
	for(p=r[0].next; p; p=r[p].next)
	{
		j = ord(r[p].keys[i]);					//ord将记录中第i个关键字映射到[0..RADIX-1] 
		
		if(!f[j])
			f[j] = p;
		else
			r[e[j]].next = p;
		
		e[j] = p;								//将p所指的结点插入第j个子表中 
	}
} 

/*═════╗
║ 算法10.16║ 
╚═════*/
void Collect(SLCell r[], int i, ArrType f, ArrType e)
{
	int j, t;
	 
	for(j=0; j<RADIX&&!f[j]; j=succ(j))			//找第一个非空子表，succ为求后继函数 
		;
	
	if(j<RADIX)
	{
		r[0].next = f[j];						//r[0].next指向第一个非空子表中第一个结点 
		t = e[j];
		
		while(j<RADIX)
		{
			for(j=succ(j); j<RADIX-1&&!f[j]; j=succ(j))
				;								//寻找下一个非空子表 
			
			if(f[j]&&j<=RADIX-1)				//链接两个非空子表 
			{
				r[t].next = f[j];
				t = e[j];
			}
		}
		
		r[t].next = 0;							//t指向最后一个非空子表中的最后一个结点 
	}
}

#endif

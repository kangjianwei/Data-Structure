#include <stdio.h>
#include <stdlib.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲01 绪论/Scanf.c"

/* 宏定义 */
#define MAXSIZE 100

/* 类型定义 */
typedef struct KNode		//邻接表结点类型 
{
	int key;
	struct KNode *next;
}KNode;				
typedef struct
{
	KNode *first;
}HNode;
typedef HNode HashTable[MAXSIZE];

/* 函数原型 */
void Algo_9_45(FILE *fp, HashTable H);	//创建哈希表 
int fHash_9_45(int key);				//生成i的哈希地址 
void Print_9_45(HashTable H);

int main(int argc, char *argv[])
{	
	FILE *fp;
	int p;
	HashTable H;

	fp = fopen("Data/Algo_9_45.txt","r");
	Algo_9_45(fp, H);
	fclose(fp);
	
	printf("输出哈希表中所有关键字：\n");
	Print_9_45(H);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━┓
┃题9.45：创建哈希表，用链地址法处理冲突┃
┗━━━━━━━━━━━━━━━━━━━*/
void Algo_9_45(FILE *fp, HashTable H)
{
	int i, p;
	int tmp;
	KNode *r, *h;
	
	for(i=0; i<MAXSIZE; i++)
		H[i].first = NULL;

	while(Scanf(fp, "%d", &tmp)==1)			//录入关键字到哈希表 
	{
		h = (KNode*)malloc(sizeof(KNode));
		h->key = tmp;
		h->next = NULL;
		
		p = fHash_9_45(tmp);
		
		if(H[p].first==NULL)
			H[p].first = h;
		else
		{
			if(H[p].first->key>tmp)
			{
				h->next = H[p].first;
				H[p].first = h;
			}
			else
			{
				r = H[p].first;
				
				while(r->next&&r->next->key<=tmp)
					r = r->next;
					
				h->next = r->next;
				r->next = h;					
			}
		}		
	}
}

int fHash_9_45(int key)		//哈希函数 
{
	return key%13;			//H(key) = key MOD 13
}

void Print_9_45(HashTable H)
{
	int i;
	KNode *r;
	
	for(i=1; i<MAXSIZE; i++)
	{
		if(H[i].first)
		{
			for(r=H[i].first; r; r=r->next)
				printf("%d ", r->key);
		}
	}
}

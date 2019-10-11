#include <stdio.h>
#include "../../../▲课本算法实现/▲10 内部排序/00 SequenceListType/SequenceListType.c"//**▲10 内部排序**//

/* 函数原型 */
void Algo_10_43(SqList_sort *L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
			
	printf("创建并输出一个任意序列...\n");
	fp = fopen("Data/Algo_10_43.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("将关键字按递增顺序排列...\n");
	Algo_10_43(&L); 
	Traverse(L, PrintKey);
	printf("\n");	
		
	return 0;
}

/*━━━━━━━━━┓
┃题10.43：计数排序 ┃
┗━━━━━━━━━*/
void Algo_10_43(SqList_sort *L)
{
	int i, j;
	SqList_sort Tmp;
	int c[(*L).length+1];
		
	Tmp = *L;
	
	for(i=1; i<=Tmp.length; i++)			//初始化c[] 
		c[i] = 0;
		
	for(i=1; i<=Tmp.length-1; i++)			//对每个记录统计比它小的关键字个数	
	{
		for(j=i+1; j<=Tmp.length; j++)
		{
			if(Tmp.r[i].key<Tmp.r[j].key)
				c[j]++;
			else
				c[i]++;
		}		
	}
	
	for(i=1; i<=Tmp.length; i++)			//排序 
		(*L).r[c[i]+1] = Tmp.r[i];
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

#include <stdio.h>
#include "../../../▲课本算法实现/▲10 内部排序/00 SequenceListType/SequenceListType.c"//**▲10 内部排序**//

/* 函数原型 */
void Algo_10_23(SqList_sort *L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
			
	printf("创建并输出一个任意序列...\n");
	fp = fopen("Data/Algo_10_23.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("将关键字按递增顺序排列...\n");
	Algo_10_23(&L); 
	Traverse(L, PrintKey);
	printf("\n");	
		
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━┓
┃题10.23：直接插入排序，以L.r[k+1]做监视哨兵 ┃
┗━━━━━━━━━━━━━━━━━━━━━━*/
void Algo_10_23(SqList_sort *L)
{
	int i, j, k;
	
	k = (*L).length;
	
	for(i=k-1; i>=1; i--)
	{
		if(LT((*L).r[i+1].key, (*L).r[i].key))
		{
			(*L).r[k+1] = (*L).r[i];				//复制为哨兵 
			for(j=i; LT((*L).r[j+1].key, (*L).r[k+1].key); ++j)
				(*L).r[j] = (*L).r[j+1];			//记录前移
			(*L).r[j] = (*L).r[k+1];				//插入到正确位置 
		}
	}
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

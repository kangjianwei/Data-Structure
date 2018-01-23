#include <stdio.h>
#include "../../../▲课本算法实现/▲10 内部排序\10 MergingSort/MergingSort.c"//**▲10 内部排序**//

/* 函数原型 */
void Algo_10_36(SqList_sort *L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
	
	printf("创建并输出一个任意序列...\n");
	fp = fopen("Data/Algo_10_36.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("归并排序...\n");
	Algo_10_36(&L); 
	Traverse(L, PrintKey);		
	printf("\n");	

	return 0;
}

/*━━━━━━━━━┓
┃题10.36：逐段归并 ┃
┗━━━━━━━━━*/
void Algo_10_36(SqList_sort *L)
{
	int l, len;
	int i, m, n;
	SqList_sort T;
	
	len = (*L).length;
	
	for(l=1; l<=len; l*=2)
	{
		i=1, m=l;
		n = 2*m>len ? len : 2*m;
		
		while(i<len&&m<len)
		{
			Merge((*L).r, T.r, i, m, n);
			i = n+1;
			m = i+l-1;
			n = i+2*l-1;
		}
		
		*L = T;		
	}
	
	(*L).length = len;
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

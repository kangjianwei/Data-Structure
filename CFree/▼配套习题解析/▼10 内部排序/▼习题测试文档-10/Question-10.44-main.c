#include <stdio.h>

/* 宏定义 */
#ifndef MAXSIZE
#define MAXSIZE 99							//顺序表的最大长度
#endif
#include "../../../▲课本算法实现/▲10 内部排序/00 SequenceListType/SequenceListType.c"//**▲10 内部排序**//

/* 函数原型 */
void Algo_10_44(SqList_sort *L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
			
	printf("创建并输出一个任意序列...\n");
	fp = fopen("Data/Algo_10_44.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("将关键字按递增顺序排列...\n");
	Algo_10_44(&L); 
	Traverse(L, PrintKey);
	printf("\n");	
		
	return 0;
}

/*━━━━━━━┓
┃题10.44：排序 ┃
┗━━━━━━━*/
void Algo_10_44(SqList_sort *L)
{
	int i, j, k;
	int number[MAXSIZE+1] = {0};	//设定所有关键字介于1~MAXSIZE之间
	SqList_sort T;
	
	T = *L;
	
	for(i=1; i<=T.length; i++)
		number[T.r[i].key]++;
	
	k = 0;
	
	for(i=1; i<=MAXSIZE; i++)
	{
		for(j=1; j<=number[i]; j++)
			(*L).r[++k].key = i;
	}
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

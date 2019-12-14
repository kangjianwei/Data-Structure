#include <stdio.h>
#include "../../../▲课本算法实现/▲10 内部排序/03 2-InsertSort/2-InsertSort.c"//**▲10 内部排序**//

/* 函数原型 */
void Algo_10_24(SqList_sort *L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
			
	printf("创建并输出一个任意序列...\n");
	fp = fopen("Data/Algo_10_24.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("将关键字按递增顺序排列...\n");
	Algo_10_24(&L); 
	Traverse(L, PrintKey);
	printf("\n");	
		
	return 0;
}

/*━━━━━━━━━━━┓
┃题10.24：2-路插入排序 ┃
┗━━━━━━━━━━━*/
void Algo_10_24(SqList_sort *L)
{
	TwoTayInsertSort(L);				//已定义 
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

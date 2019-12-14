#include <stdio.h>
#include "../../../▲课本算法实现/▲10 内部排序/00 SequenceListType/SequenceListType.c"//**▲10 内部排序**//

/* 函数原型 */
void Algo_10_31(SqList_sort *L, int low, int high);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
	
	printf("创建并输出一个任意序列...\n");
	fp = fopen("Data/Algo_10_31.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("将关键字按负数在前，正数在后的顺序排列...\n");
	Algo_10_31(&L, 1, L.length); 
	Traverse(L, PrintKey);
	printf("\n");	

	return 0;
}

/*━━━━━━━━━━━━━━━━━━┓
┃题10.31：整理序列(负数在前,正数在后)┃
┗━━━━━━━━━━━━━━━━━━*/
void Algo_10_31(SqList_sort *L, int low, int high)
{
	int pivotkey;	
	RcdType tmp;								//辅助空间 
	
	pivotkey = 0;								//枢纽处的关键字 
	
	while(low<high)								//从表的两端交替地向中间扫描 
	{
		while(low<high && (*L).r[high].key>=pivotkey)
			high--;
		
		tmp = (*L).r[high];						//将比枢轴记录小的记录交换到低端 
		(*L).r[high] = (*L).r[low];
		(*L).r[low] = tmp;
		
		while(low<high && (*L).r[low].key<=pivotkey)
			low++;
		
		tmp = (*L).r[high];						//将比枢轴记录大的记录交换到高端
		(*L).r[high] = (*L).r[low];
		(*L).r[low] = tmp; 
	}
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

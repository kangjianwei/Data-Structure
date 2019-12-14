#include <stdio.h>
#include "../../../▲课本算法实现/▲10 内部排序/00 SequenceListType/SequenceListType.c"//**▲10 内部排序**//

/* 函数原型 */
void Algo_10_46(SqList_sort *A, SqList_sort B);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort A, B;
			
	printf("创建并输出一个任意序列...\n");
	fp = fopen("Data/Algo_10_46.txt", "r");
	CreateSortList(fp, &B);
	Traverse(B, PrintKey);
	printf("\n");	

	printf("将关键字按递增顺序排列...\n");
	Algo_10_46(&A, B); 
	Traverse(A, PrintKey);
	printf("\n");	
		
	return 0;
}

/*━━━━━━━━━━━━━━━┓
┃题10.46：将B排序后的结果存入A ┃
┗━━━━━━━━━━━━━━━*/
void Algo_10_46(SqList_sort *A, SqList_sort B)
{
	int i, j, tmp;
	int order[B.length+1];					//记录当前位置应该包含的记录
	
	for(i=1; i<=B.length; i++)
		order[i] = i;
	
	for(i=1; i<=B.length-1; i++)			//冒泡排序 
	{
		for(j=B.length; j>i; j--)
		{
			if(B.r[order[j]].key<B.r[order[j-1]].key)
			{
				tmp = order[j];
				order[j] = order[j-1];
				order[j-1] = tmp;
			}
		}
	}
	
	(*A).length = B.length;
	
	for(i=1; i<=B.length; i++)
		(*A).r[i] = B.r[order[i]];
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

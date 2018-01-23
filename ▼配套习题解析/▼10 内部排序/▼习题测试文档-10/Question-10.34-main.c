#include <stdio.h>
#include "../../../▲课本算法实现/▲10 内部排序/00 SequenceListType/SequenceListType.c"//**▲10 内部排序**//

/* 类型定义 */
typedef SqList_sort HeapType;

/* 函数原型 */
void Algo_10_34(FILE *fp, HeapType *H);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	HeapType H;
	
	printf("逐次插入记录创建二叉堆...\n");
	fp = fopen("Data/Algo_10_34.txt", "r");
	Algo_10_34(fp, &H); 
	Traverse(H, PrintKey);
	printf("\n");	

	return 0;
}

/*━━━━━━━━━━━━┓
┃题10.34：二叉堆插入算法 ┃
┗━━━━━━━━━━━━*/
void Algo_10_34(FILE *fp, HeapType *H)
{
	RcdType tmp;
	int p, s;
	
	(*H).length = 0;
	
	while((Scanf(fp, "%d", &tmp.key))==1)
	{
		s = ++(*H).length;
		p = s/2;
		
		while(p && (*H).r[p].key>tmp.key)
		{
			(*H).r[s] = (*H).r[p];
			s = p;
			p = s/2;
		}
		
		(*H).r[s] = tmp;
	}
} 

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

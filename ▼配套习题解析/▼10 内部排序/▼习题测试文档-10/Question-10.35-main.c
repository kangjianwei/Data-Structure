#include <stdio.h>
#include "../../../▲课本算法实现/▲10 内部排序/00 SequenceListType/SequenceListType.c"//**▲10 内部排序**//

/* 类型定义 */
typedef SqList_sort TirHeapType;

/* 函数原型 */
void Algo_10_35(TirHeapType *H);
void TirHeapAdjust_10_35(TirHeapType *H, int p, int m);	//调整r[p..m]为大顶堆
void InsertTirHeap_10_35(FILE *fp, TirHeapType *H);		//三叉堆插入算法 
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	TirHeapType H;
	
	printf("逐次插入记录创建二叉堆...\n");
	fp = fopen("Data/Algo_10_35.txt", "r");
	InsertTirHeap_10_35(fp, &H); 
	Traverse(H, PrintKey);
	printf("\n");	

	printf("对三叉堆进行排序...\n");
	Algo_10_35(&H);
	Traverse(H, PrintKey);
	printf("\n");
		
	return 0;
}

/*━━━━━━━━━━━━┓
┃题10.35：三叉堆排序算法 ┃
┗━━━━━━━━━━━━*/
void Algo_10_35(TirHeapType *H)
{
	int count, s;
	RcdType tmp;

	count = (*H).length;
	
	while(count)						//排序前三叉堆已是大顶堆 
	{
		tmp = (*H).r[1];				//将最大关键字记录放到最后 
		(*H).r[1] = (*H).r[count];
		(*H).r[count] = tmp;
		
		count--;
		
		TirHeapAdjust_10_35(H, 1, count);//重新调整r[1..count]为大顶堆 
	}
}

void TirHeapAdjust_10_35(TirHeapType *H, int p, int m)
{
	int s, max;		//max指向拥有最大关键字的记录 
	RcdType tmp;
	
	tmp = (*H).r[p];
	
	while(3*p-1<=m)
	{
		s = 3*p-1;
		max = s;
		for(s=s+1; s<=m; s++)
		{
			if((*H).r[max].key<(*H).r[s].key)
				max = s;
		}
		
		if((*H).r[max].key>tmp.key)
			(*H).r[p] = (*H).r[max];
		else
			break;
			
		p = max;
	}
	
	(*H).r[p] = tmp;
}

void InsertTirHeap_10_35(FILE *fp, TirHeapType *H)
{
	RcdType tmp;
	int p, s;
	
	(*H).length = 0;
	
	while((Scanf(fp, "%d", &tmp.key))==1)
	{
		s = ++(*H).length;
		p = (s+1)/3;
		
		while(p && (*H).r[p].key<tmp.key)
		{
			(*H).r[s] = (*H).r[p];
			s = p;
			p = (s+1)/3;
		}
		
		(*H).r[s] = tmp;
	}
} 

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

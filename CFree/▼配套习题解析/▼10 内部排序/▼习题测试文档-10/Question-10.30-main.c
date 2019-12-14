#include <stdio.h>
#include "../../../▲课本算法实现/▲10 内部排序/00 SequenceListType/SequenceListType.c"//**▲10 内部排序**//

/* 类型定义 */
typedef struct
{
	int low;
	int high;
}SNode;

/* 函数原型 */
void Algo_10_30_1(SqList_sort *L, int low, int high);
void Algo_10_30_2(SqList_sort *L, int low, int high);
int Partition_10_30(SqList_sort *L, int low, int high);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
	
	printf("创建并输出一个任意序列...\n");
	fp = fopen("Data/Algo_10_30.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("(1)将关键字按递增顺序排列...\n");
	Algo_10_30_1(&L, 1, L.length); 
	Traverse(L, PrintKey);
	printf("\n");	

	printf("(2)将关键字按递增顺序排列...\n");
	Algo_10_30_1(&L, 1, L.length); 
	Traverse(L, PrintKey);
	printf("\n");
			
	return 0;
}

/*━━━━━━━━━━━━━┓
┃题10.30(1)：非递归快速排序┃
┗━━━━━━━━━━━━━*/
void Algo_10_30_1(SqList_sort *L, int low, int high)
{
	Status tag;						//标记序列是否无序 
	int pivotloc;					//枢纽位置 
	int lnum, rnum;					//左右子序列元素个数 
	int count;						//栈中元素个数 
	SNode Stack[100];				//栈，0号单元弃用 
	
	tag = TRUE;
	count=0;
	
	while(tag)
	{	
		pivotloc = Partition_10_30(L, low, high);
		if(pivotloc==low)			//序列已有序 
			tag = FALSE;
			 
		if(tag)						//当前子序列无序 
		{
			lnum = pivotloc-low;
			rnum = high-pivotloc;
			
			if(lnum>1||rnum>1)
			{
				count++;
				
				if(lnum<=rnum)		//左序列元素少，则右序列入栈，先判断左序列 
				{
					Stack[count].low = pivotloc+1;
					Stack[count].high = high;
					high = pivotloc-1;
				}
				else				//右序列元素少，则左序列入栈，先判断右序列 
				{
					Stack[count].low = low;
					Stack[count].high = pivotloc-1;
					low = pivotloc+1;		
				} 
			}
		}
		
		if(!tag || (lnum<=1&&rnum<=1))//当前子序列已有序 
		{
			if(count)				//抽取栈中序列 
			{
				low = Stack[count].low;
				high = Stack[count].high;
				count--;
				tag = TRUE;			//假设栈中序列无序		
			}
		}
	}
}

/*━━━━━━━━━━━━━┓
┃题10.30(2)：非递归快速排序┃
┗━━━━━━━━━━━━━*/
void Algo_10_30_2(SqList_sort *L, int low, int high)
{ 
	int pivotloc;					//枢纽位置 
	int lnum, rnum;					//左右子序列元素个数 
	int count;						//栈中元素个数 
	SNode Stack[100];				//栈，0号单元弃用 
	int i, j;
	RcdType tmp;
	
	count = 0;
	
	while(1)
	{		
		if(high-low+1<=3)					//待排记录<=3 
		{	
			for(i=high-low+1; i>=2; i--)	//冒泡排序 
			{				
				for(j=1; j<=i-1; j++)
				{
					if((*L).r[j+1].key<(*L).r[j].key)
					{
						tmp = (*L).r[j+1];
						(*L).r[j+1] = (*L).r[j];
						(*L).r[j] = tmp;
					} 
				}
			}
			
			if(count)
			{
				low = Stack[count].low;
				high = Stack[count].high;
				count--;		
			}
			else
				break;			
		}
		else					
		{
			pivotloc = Partition_10_30(L, low, high);
			
			lnum = pivotloc-low;
			rnum = high-pivotloc;
			
			count++;
			
			if(lnum<=rnum)			//左序列元素少，则右序列入栈，先判断左序列 
			{
				Stack[count].low = pivotloc+1;
				Stack[count].high = high;
				high = pivotloc-1;
			}
			else					//右序列元素少，则左序列入栈，先判断右序列 
			{
				Stack[count].low = low;
				Stack[count].high = pivotloc-1;
				low = pivotloc+1;		
			}			
		}
	}
}

int Partition_10_30(SqList_sort *L, int low, int high)
{
	int pivotkey;
	
	(*L).r[0] = (*L).r[low];					//用子表第一个记录作枢轴记录
	pivotkey = (*L).r[low].key;					//枢轴记录关键字 
	
	while(low<high)								//从表的两端交替地向中间扫描 
	{
		while(low<high && (*L).r[high].key>=pivotkey)
			high--;
		
		(*L).r[low] = (*L).r[high];				//将比枢轴记录小的记录交换到低端 
		
		while(low<high && (*L).r[low].key<=pivotkey)
			low++;
		
		(*L).r[high] = (*L).r[low];				//将比枢轴记录大的记录交换到高端
	}
	
	(*L).r[low] = (*L).r[0];					//枢轴记录到位 
		
	return low;									//返回枢轴所在位置 
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

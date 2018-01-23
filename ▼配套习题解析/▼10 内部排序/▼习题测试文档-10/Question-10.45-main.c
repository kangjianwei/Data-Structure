#include <stdio.h>
#include <math.h>
#include "../../../▲课本算法实现/▲10 内部排序/00 SequenceListType/SequenceListType.c"//**▲10 内部排序**//

/* 宏定义 */
#define Keynum 3							//关键字个数设定为3 

/* 函数原型 */
void Algo_10_45(SqList_sort *L);
int DigitBit_10_45(int x, int c);			//返回x第c位(1-个位,2-十位,3-百位...)的值 
void Print_10_45(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
			
	printf("创建并输出一个任意序列...\n");
	fp = fopen("Data/Algo_10_45.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, Print_10_45);
	printf("\n");	

	printf("将关键字按递增顺序排列...\n");
	Algo_10_45(&L); 
	Traverse(L, Print_10_45);
	printf("\n");	
		
	return 0;
}

/*━━━━━━━━━━━━━━━┓
┃题10.45：利用计数进行基数排序 ┃
┗━━━━━━━━━━━━━━━*/
void Algo_10_45(SqList_sort *L)
{
	int i, j, k;
	SqList_sort Tmp;
	int c[(*L).length+1];
	
	for(k=1; k<=Keynum; k++)
	{
		Tmp = *L;
		
		for(i=1; i<=Tmp.length; i++)		//初始化c[] 
			c[i] = 0;
			
		for(i=1; i<=Tmp.length-1; i++)		//对每个记录的某一位统计比它小的关键字个数	
		{
			for(j=i+1; j<=Tmp.length; j++)
			{								//从个位依次统计排序 
				if(DigitBit_10_45(Tmp.r[i].key, k)<=DigitBit_10_45(Tmp.r[j].key, k))
					c[j]++;
				else
					c[i]++;
			}		
		}
		
		for(i=1; i<=Tmp.length; i++)		//排序 
			(*L).r[c[i]+1] = Tmp.r[i];	
	}
}

int DigitBit_10_45(int x, int c)
{
	int a = pow(10,c);
	int b = pow(10,c-1);
	
	return (x%a-x%b)/b;
}

void Print_10_45(KeyType e)
{
	printf("%03d ", e);
}

#include <stdio.h>
#include "../../../���α��㷨ʵ��/��09 ����/00 Base/Base.c" //**��09 ����**//

/* �궨�� */
#define MAX 30			//�ؼ��ָ��� 

/* ���Ͷ��� */
typedef struct
{
	int start;			//��ǰ����� 
	int min;			//��ǰ����Ԫ����Сֵ 
}Index; 
typedef struct
{
	Table T;			//���п���Ԫ�� 
	Index Block[MAX]; 
	int bnum;			//��ĸ��� 
}Lookup;				//�ؼ��ֵ����Ĳ��ұ� 

/* ����ԭ�� */
int Algo_9_28(Lookup ST, KeyType key);
void CreateBlock_9_28(FILE* fp, Lookup *ST);

int main(int argc, char *argv[])
{	
	FILE *fp;
	Lookup ST;
	KeyType key = 89;
	int i;
		
	printf("���������һ�����ұ�...\n");
	fp = fopen("Data/Algo_9_28.txt", "r");	
	CreateBlock_9_28(fp, &ST); 
	Traverse(ST.T, PrintKey);	
	printf("\n");
	
	i = Algo_9_28(ST, key);
	if(!i)
		printf("�ؼ��� %d δ�ҵ�����\n", key);
	else
		printf("�ؼ��� %d ��˳���� %d ��λ�á�\n", key, i);
	printf("\n");
		
	return 0;
}

int Algo_9_28(Lookup ST, KeyType key)
{
	int low, high, mid;
	
	if(key<ST.Block[1].min)						//��ȷ���ؼ����ڿ��е�λ�� 
		low = 0;
	else if (key>=ST.Block[ST.bnum].min)
		low = ST.bnum;
	else
	{
		low=1, high=ST.bnum;
		
		while(high-low>1)
		{
			mid = (low + high) / 2;
			
			if(ST.Block[mid].min<=key)
				low = mid;
			else
				high = mid; 
		}	
	}

	if(low) 								//�ҵ��������Ŀ�󣬼�����˳���T�в���
	{
		if(low==ST.bnum)
			high = ST.T.length;
		else
			high = ST.Block[high].start-1;
		
		while(low<=high)
		{
			mid = (low+high)/2;
			
			if(key<ST.T.elem[mid].key)
				high = mid - 1;
			else if(key>ST.T.elem[mid].key)
				low = mid + 1;
			else
				return mid;
		}
	}
	
	return 0;		//δ�ҵ� 
}

void CreateBlock_9_28(FILE* fp, Lookup *ST)		//��������ұ� 
{
	int i;
	
	Create(fp, &ST->T, MAX);					//¼�����йؼ��ִ���˳���
	
	for(i=1,ST->bnum=0; i<=ST->T.length; i+=5)				//�趨���5��Ԫ�ع���һ���� 
	{
		ST->bnum++;
		ST->Block[ST->bnum].start = i;
		ST->Block[ST->bnum].min = ST->T.elem[i].key;
	}
}

#include <stdio.h>
#include "../../../���α��㷨ʵ��/��10 �ڲ�����/00 SequenceListType/SequenceListType.c"//**��10 �ڲ�����**//

/* ���Ͷ��� */
typedef struct
{
	int low;
	int high;
}SNode;

/* ����ԭ�� */
void Algo_10_30_1(SqList_sort *L, int low, int high);
void Algo_10_30_2(SqList_sort *L, int low, int high);
int Partition_10_30(SqList_sort *L, int low, int high);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
	
	printf("���������һ����������...\n");
	fp = fopen("Data/Algo_10_30.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("(1)���ؼ��ְ�����˳������...\n");
	Algo_10_30_1(&L, 1, L.length); 
	Traverse(L, PrintKey);
	printf("\n");	

	printf("(2)���ؼ��ְ�����˳������...\n");
	Algo_10_30_1(&L, 1, L.length); 
	Traverse(L, PrintKey);
	printf("\n");
			
	return 0;
}

/*����������������������������
����10.30(1)���ǵݹ��������
����������������������������*/
void Algo_10_30_1(SqList_sort *L, int low, int high)
{
	Status tag;						//��������Ƿ����� 
	int pivotloc;					//��Ŧλ�� 
	int lnum, rnum;					//����������Ԫ�ظ��� 
	int count;						//ջ��Ԫ�ظ��� 
	SNode Stack[100];				//ջ��0�ŵ�Ԫ���� 
	
	tag = TRUE;
	count=0;
	
	while(tag)
	{	
		pivotloc = Partition_10_30(L, low, high);
		if(pivotloc==low)			//���������� 
			tag = FALSE;
			 
		if(tag)						//��ǰ���������� 
		{
			lnum = pivotloc-low;
			rnum = high-pivotloc;
			
			if(lnum>1||rnum>1)
			{
				count++;
				
				if(lnum<=rnum)		//������Ԫ���٣�����������ջ�����ж������� 
				{
					Stack[count].low = pivotloc+1;
					Stack[count].high = high;
					high = pivotloc-1;
				}
				else				//������Ԫ���٣�����������ջ�����ж������� 
				{
					Stack[count].low = low;
					Stack[count].high = pivotloc-1;
					low = pivotloc+1;		
				} 
			}
		}
		
		if(!tag || (lnum<=1&&rnum<=1))//��ǰ������������ 
		{
			if(count)				//��ȡջ������ 
			{
				low = Stack[count].low;
				high = Stack[count].high;
				count--;
				tag = TRUE;			//����ջ����������		
			}
		}
	}
}

/*����������������������������
����10.30(2)���ǵݹ��������
����������������������������*/
void Algo_10_30_2(SqList_sort *L, int low, int high)
{ 
	int pivotloc;					//��Ŧλ�� 
	int lnum, rnum;					//����������Ԫ�ظ��� 
	int count;						//ջ��Ԫ�ظ��� 
	SNode Stack[100];				//ջ��0�ŵ�Ԫ���� 
	int i, j;
	RcdType tmp;
	
	count = 0;
	
	while(1)
	{		
		if(high-low+1<=3)					//���ż�¼<=3 
		{	
			for(i=high-low+1; i>=2; i--)	//ð������ 
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
			
			if(lnum<=rnum)			//������Ԫ���٣�����������ջ�����ж������� 
			{
				Stack[count].low = pivotloc+1;
				Stack[count].high = high;
				high = pivotloc-1;
			}
			else					//������Ԫ���٣�����������ջ�����ж������� 
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
	
	(*L).r[0] = (*L).r[low];					//���ӱ��һ����¼�������¼
	pivotkey = (*L).r[low].key;					//�����¼�ؼ��� 
	
	while(low<high)								//�ӱ�����˽�������м�ɨ�� 
	{
		while(low<high && (*L).r[high].key>=pivotkey)
			high--;
		
		(*L).r[low] = (*L).r[high];				//���������¼С�ļ�¼�������Ͷ� 
		
		while(low<high && (*L).r[low].key<=pivotkey)
			low++;
		
		(*L).r[high] = (*L).r[low];				//���������¼��ļ�¼�������߶�
	}
	
	(*L).r[low] = (*L).r[0];					//�����¼��λ 
		
	return low;									//������������λ�� 
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

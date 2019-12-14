#include <stdio.h>
#include "../../../���α��㷨ʵ��/��10 �ڲ�����/00 SequenceListType/SequenceListType.c"//**��10 �ڲ�����**//

/* ����ԭ�� */
void Algo_10_32(SqList_sort *L, int low, int high);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
	
	printf("���������һ����������...\n");
	fp = fopen("Data/Algo_10_32.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("���Ų�ͬɫ����1.2.3��˳�����...\n");
	Algo_10_32(&L, 1, L.length); 
	Traverse(L, PrintKey);
	printf("\n");	

	return 0;
}

/*������������������������
����10.32�������������� ��
������������������������*/
void Algo_10_32(SqList_sort *L, int low, int high)
{
	int cur;	
	RcdType tmp;						//�����ռ� 
	
	cur = low;
	
	while(cur<=high)					
	{
		if((*L).r[cur].key==1)			//1�����ɫ����ǰ�� 
		{
			tmp = (*L).r[low];
			(*L).r[low] = (*L).r[cur];
			(*L).r[cur] = tmp;
			low++;
			cur++;
		}
		else if((*L).r[cur].key==3)		//3������ɫ�������
		{
			tmp = (*L).r[high];
			(*L).r[high] = (*L).r[cur];
			(*L).r[cur] = tmp;
			high--;
		}
		else
			cur++;		
	}
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

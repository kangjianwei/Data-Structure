#include <stdio.h>

/* �궨�� */
#ifndef MAXSIZE
#define MAXSIZE 99							//˳������󳤶�
#endif
#include "../../../���α��㷨ʵ��/��10 �ڲ�����/00 SequenceListType/SequenceListType.c"//**��10 �ڲ�����**//

/* ����ԭ�� */
void Algo_10_44(SqList_sort *L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
			
	printf("���������һ����������...\n");
	fp = fopen("Data/Algo_10_44.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("���ؼ��ְ�����˳������...\n");
	Algo_10_44(&L); 
	Traverse(L, PrintKey);
	printf("\n");	
		
	return 0;
}

/*����������������
����10.44������ ��
����������������*/
void Algo_10_44(SqList_sort *L)
{
	int i, j, k;
	int number[MAXSIZE+1] = {0};	//�趨���йؼ��ֽ���1~MAXSIZE֮��
	SqList_sort T;
	
	T = *L;
	
	for(i=1; i<=T.length; i++)
		number[T.r[i].key]++;
	
	k = 0;
	
	for(i=1; i<=MAXSIZE; i++)
	{
		for(j=1; j<=number[i]; j++)
			(*L).r[++k].key = i;
	}
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

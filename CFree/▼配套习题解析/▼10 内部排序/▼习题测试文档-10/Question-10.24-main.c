#include <stdio.h>
#include "../../../���α��㷨ʵ��/��10 �ڲ�����/03 2-InsertSort/2-InsertSort.c"//**��10 �ڲ�����**//

/* ����ԭ�� */
void Algo_10_24(SqList_sort *L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
			
	printf("���������һ����������...\n");
	fp = fopen("Data/Algo_10_24.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("���ؼ��ְ�����˳������...\n");
	Algo_10_24(&L); 
	Traverse(L, PrintKey);
	printf("\n");	
		
	return 0;
}

/*������������������������
����10.24��2-·�������� ��
������������������������*/
void Algo_10_24(SqList_sort *L)
{
	TwoTayInsertSort(L);				//�Ѷ��� 
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

#include <stdio.h>
#include "../../../���α��㷨ʵ��/��10 �ڲ�����/04 TInsertSort/TInsertSort.c"//**��10 �ڲ�����**//

/* ����ԭ�� */
void Algo_10_25(SLinkList_sort *L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SLinkList_sort L;
			
	printf("���������һ����������...\n");
	fp = fopen("Data/Algo_10_24.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("���ؼ��ְ�����˳������...\n");
	Algo_10_25(&L); 
	Traverse(L, PrintKey);
	printf("\n");	
		
	return 0;
}

/*������������������������
����10.25������������� ��
������������������������*/
void Algo_10_25(SLinkList_sort *L)
{
	TInsertSort(L);					//�Ѷ��� 
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

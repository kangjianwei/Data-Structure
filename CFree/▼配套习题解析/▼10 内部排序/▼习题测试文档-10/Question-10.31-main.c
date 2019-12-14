#include <stdio.h>
#include "../../../���α��㷨ʵ��/��10 �ڲ�����/00 SequenceListType/SequenceListType.c"//**��10 �ڲ�����**//

/* ����ԭ�� */
void Algo_10_31(SqList_sort *L, int low, int high);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
	
	printf("���������һ����������...\n");
	fp = fopen("Data/Algo_10_31.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("���ؼ��ְ�������ǰ�������ں��˳������...\n");
	Algo_10_31(&L, 1, L.length); 
	Traverse(L, PrintKey);
	printf("\n");	

	return 0;
}

/*��������������������������������������
����10.31����������(������ǰ,�����ں�)��
��������������������������������������*/
void Algo_10_31(SqList_sort *L, int low, int high)
{
	int pivotkey;	
	RcdType tmp;								//�����ռ� 
	
	pivotkey = 0;								//��Ŧ���Ĺؼ��� 
	
	while(low<high)								//�ӱ�����˽�������м�ɨ�� 
	{
		while(low<high && (*L).r[high].key>=pivotkey)
			high--;
		
		tmp = (*L).r[high];						//���������¼С�ļ�¼�������Ͷ� 
		(*L).r[high] = (*L).r[low];
		(*L).r[low] = tmp;
		
		while(low<high && (*L).r[low].key<=pivotkey)
			low++;
		
		tmp = (*L).r[high];						//���������¼��ļ�¼�������߶�
		(*L).r[high] = (*L).r[low];
		(*L).r[low] = tmp; 
	}
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

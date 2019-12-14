#include <stdio.h>
#include "../../../���α��㷨ʵ��/��10 �ڲ�����/00 SequenceListType/SequenceListType.c"//**��10 �ڲ�����**//

/* ����ԭ�� */
void Algo_10_23(SqList_sort *L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
			
	printf("���������һ����������...\n");
	fp = fopen("Data/Algo_10_23.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("���ؼ��ְ�����˳������...\n");
	Algo_10_23(&L); 
	Traverse(L, PrintKey);
	printf("\n");	
		
	return 0;
}

/*����������������������������������������������
����10.23��ֱ�Ӳ���������L.r[k+1]�������ڱ� ��
����������������������������������������������*/
void Algo_10_23(SqList_sort *L)
{
	int i, j, k;
	
	k = (*L).length;
	
	for(i=k-1; i>=1; i--)
	{
		if(LT((*L).r[i+1].key, (*L).r[i].key))
		{
			(*L).r[k+1] = (*L).r[i];				//����Ϊ�ڱ� 
			for(j=i; LT((*L).r[j+1].key, (*L).r[k+1].key); ++j)
				(*L).r[j] = (*L).r[j+1];			//��¼ǰ��
			(*L).r[j] = (*L).r[k+1];				//���뵽��ȷλ�� 
		}
	}
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

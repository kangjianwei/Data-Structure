#include <stdio.h>
#include "../../../���α��㷨ʵ��/��10 �ڲ�����/00 SequenceListType/SequenceListType.c"//**��10 �ڲ�����**//

/* ����ԭ�� */
void Algo_10_43(SqList_sort *L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
			
	printf("���������һ����������...\n");
	fp = fopen("Data/Algo_10_43.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("���ؼ��ְ�����˳������...\n");
	Algo_10_43(&L); 
	Traverse(L, PrintKey);
	printf("\n");	
		
	return 0;
}

/*��������������������
����10.43���������� ��
��������������������*/
void Algo_10_43(SqList_sort *L)
{
	int i, j;
	SqList_sort Tmp;
	int c[(*L).length+1];
		
	Tmp = *L;
	
	for(i=1; i<=Tmp.length; i++)			//��ʼ��c[] 
		c[i] = 0;
		
	for(i=1; i<=Tmp.length-1; i++)			//��ÿ����¼ͳ�Ʊ���С�Ĺؼ��ָ���	
	{
		for(j=i+1; j<=Tmp.length; j++)
		{
			if(Tmp.r[i].key<Tmp.r[j].key)
				c[j]++;
			else
				c[i]++;
		}		
	}
	
	for(i=1; i<=Tmp.length; i++)			//���� 
		(*L).r[c[i]+1] = Tmp.r[i];
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

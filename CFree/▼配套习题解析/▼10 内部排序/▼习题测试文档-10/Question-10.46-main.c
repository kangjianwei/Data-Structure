#include <stdio.h>
#include "../../../���α��㷨ʵ��/��10 �ڲ�����/00 SequenceListType/SequenceListType.c"//**��10 �ڲ�����**//

/* ����ԭ�� */
void Algo_10_46(SqList_sort *A, SqList_sort B);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort A, B;
			
	printf("���������һ����������...\n");
	fp = fopen("Data/Algo_10_46.txt", "r");
	CreateSortList(fp, &B);
	Traverse(B, PrintKey);
	printf("\n");	

	printf("���ؼ��ְ�����˳������...\n");
	Algo_10_46(&A, B); 
	Traverse(A, PrintKey);
	printf("\n");	
		
	return 0;
}

/*��������������������������������
����10.46����B�����Ľ������A ��
��������������������������������*/
void Algo_10_46(SqList_sort *A, SqList_sort B)
{
	int i, j, tmp;
	int order[B.length+1];					//��¼��ǰλ��Ӧ�ð����ļ�¼
	
	for(i=1; i<=B.length; i++)
		order[i] = i;
	
	for(i=1; i<=B.length-1; i++)			//ð������ 
	{
		for(j=B.length; j>i; j--)
		{
			if(B.r[order[j]].key<B.r[order[j-1]].key)
			{
				tmp = order[j];
				order[j] = order[j-1];
				order[j-1] = tmp;
			}
		}
	}
	
	(*A).length = B.length;
	
	for(i=1; i<=B.length; i++)
		(*A).r[i] = B.r[order[i]];
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

#include <stdio.h>
#include "../../../���α��㷨ʵ��/��10 �ڲ�����/00 SequenceListType/SequenceListType.c"//**��10 �ڲ�����**//

/* ����ԭ�� */
void Algo_10_26(SqList_sort *L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
			
	printf("���������һ����������...\n");
	fp = fopen("Data/Algo_10_26.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("���ؼ��ְ�����˳������...\n");
	Algo_10_26(&L); 
	Traverse(L, PrintKey);
	printf("\n");	
		
	return 0;
}

/*��������������������������
����10.26����������(�Ķ�) ��
��������������������������*/
void Algo_10_26(SqList_sort *L)
{
	int i, j;
	RcdType tmp;
	int change;							//changeָʾÿһ�������н��н��������һ����¼��λ��
	
	for(i=(*L).length; i>=1; i=change-1)
	{		
		for(j=1; j<=i-1; j++)
		{
			if(LT((*L).r[j+1].key, (*L).r[j].key))
			{
				tmp = (*L).r[j+1];
				(*L).r[j+1] = (*L).r[j];
				(*L).r[j] = tmp;
				
				change = j+1;			//��change�������Ԫ�ؾ�����			 
			} 
		}
		
		if(change==j+1)					//������������������˵�������Ѿ�����
			break;
	}
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

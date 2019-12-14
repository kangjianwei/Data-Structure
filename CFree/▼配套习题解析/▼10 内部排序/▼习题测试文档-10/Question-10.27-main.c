#include <stdio.h>
#include "../../../���α��㷨ʵ��/��10 �ڲ�����/00 SequenceListType/SequenceListType.c"//**��10 �ڲ�����**//

/* ����ԭ�� */
void Algo_10_27(SqList_sort *L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
			
	printf("���������һ����������...\n");
	fp = fopen("Data/Algo_10_27.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("���ؼ��ְ�����˳������...\n");
	Algo_10_27(&L); 
	Traverse(L, PrintKey);
	printf("\n");	
		
	return 0;
}

/*������������������������
����10.27��˫���������� ��
������������������������*/
void Algo_10_27(SqList_sort *L)
{
	int i, j, k;
	RcdType tmp;
	Status tag;
	
	k = 1;											//ÿ���������ڵ���� 
	
	do
	{					
		for(i=k,tag=FALSE; i<=(*L).length-k; i++)	//��ǰ������ 
		{
			if(LT((*L).r[i+1].key, (*L).r[i].key))
			{
				tmp = (*L).r[i+1];
				(*L).r[i+1] = (*L).r[i];
				(*L).r[i] = tmp;
				
				tag = TRUE;							 
			} 
		}
		
		if(!tag)									//������������������˵�������Ѿ�����
			break;
			
		for(j=i-1,tag=FALSE; j>=k+1; j--)			//�Ӻ���ǰ�ű���					
		{
			if(LT((*L).r[j].key, (*L).r[j-1].key))
			{
				tmp = (*L).r[j];
				(*L).r[j] = (*L).r[j-1];
				(*L).r[j-1] = tmp;
				
				tag = TRUE; 
			}		
		}
		
		k++;
		
	}while(tag);
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

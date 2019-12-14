#include <stdio.h>
#include "../../../���α��㷨ʵ��/��10 �ڲ�����/00 SequenceListType/SequenceListType.c"//**��10 �ڲ�����**//

/* ����ԭ�� */
void Algo_10_29(SqList_sort *L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
			
	printf("���������һ����������...\n");
	fp = fopen("Data/Algo_10_29.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("���ؼ��ְ�����˳������...\n");
	Algo_10_29(&L); 
	Traverse(L, PrintKey);
	printf("\n");	
		
	return 0;
}

/*������������������������
����10.29����ż�������� ��
������������������������*/
void Algo_10_29(SqList_sort *L)
{
	int k, start;
	RcdType tmp;
	Status preTag, curTag;
	
	start = 1;
	preTag = TRUE;				//��¼�ϴα����Ƿ������� 
		
	while(1)
	{							
		for(k=start,curTag=FALSE; k+1<=(*L).length; k+=2)
		{
			if(LT((*L).r[k+1].key, (*L).r[k].key))
			{
				tmp = (*L).r[k+1];
				(*L).r[k+1] = (*L).r[k];
				(*L).r[k] = tmp;
				
				curTag = TRUE;	//��¼���α����Ƿ�������						 
			} 
		}
		
		if(!preTag && !curTag)	//�������α����޽�����Ϊ��˵������������ 
			break;
		else
		{
			preTag = curTag;
			start = start%2 + 1;//��㣨��ż�����Ͻ���		
		}
	}
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

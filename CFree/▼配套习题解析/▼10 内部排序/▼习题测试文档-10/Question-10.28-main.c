#include <stdio.h>
#include "../../../���α��㷨ʵ��/��10 �ڲ�����/00 SequenceListType/SequenceListType.c"//**��10 �ڲ�����**//

/* ����ԭ�� */
void Algo_10_28(SqList_sort *L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
			
	printf("���������һ����������...\n");
	fp = fopen("Data/Algo_10_28.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("���ؼ��ְ�����˳������...\n");
	Algo_10_28(&L); 
	Traverse(L, PrintKey);
	printf("\n");	
		
	return 0;
}

/*������������������������
����10.28��˫���������� ��
������������������������*/
void Algo_10_28(SqList_sort *L)
{
	int k, start, end, cache, dir;
	RcdType tmp;
	Status tag;
	
	dir = 1; 
	
	start = 1;
	end = (*L).length;
	
	while(1)
	{
		tag = FALSE;
							
		for(k=start; k!=end; k=k+dir)
		{
			if(LT((*L).r[k+1].key, (*L).r[k].key))
			{
				tmp = (*L).r[k+1];
				(*L).r[k+1] = (*L).r[k];
				(*L).r[k] = tmp;
				
				tag = TRUE;							 
			} 
		}
		
		if(!tag)								//������������������˵�������Ѿ�����
			break;		
		
		dir = -dir;								//�ı䷽��
		
		cache = start;
		start = end + 2*dir;					//��ǰ����������ϴα����յ�Ĺ�ϵ 
		end = cache + dir; 						//��ǰ�����յ����ϴα������Ĺ�ϵ
	}
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

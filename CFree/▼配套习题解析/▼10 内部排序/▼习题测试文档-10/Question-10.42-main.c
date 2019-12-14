#include <stdio.h>
#include <math.h>
#include "../../../���α��㷨ʵ��/��10 �ڲ�����/00 SequenceListType/SequenceListType.c"//**��10 �ڲ�����**//

/* ���Ͷ��� */
typedef struct
{
	int gnum;		//>=��ǰ�ؼ��ֵ������ؼ��ָ��� 
	int lnum;		//<=��ǰ�ؼ��ֵ������ؼ��ָ��� 
}SNode;

/* ����ԭ�� */
RcdType Algo_10_42(SqList_sort L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
	RcdType R;
			
	printf("���������һ����������...\n");
	fp = fopen("Data/Algo_10_42.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	R = Algo_10_42(L); 
	printf("��������ֵ��¼�Ĺؼ���Ϊ��%d��\n", R.key);
	printf("\n");	
		
	return 0;
}

/*������������������������
����10.42��Ѱ����ֵ��¼ ��
������������������������*/
RcdType Algo_10_42(SqList_sort L)
{
	int i, j, k;
	SNode sign[L.length+1];			//�洢���ں�С�ڵ�ǰ�ؼ��ֵ������ؼ��ָ��� 
	
	for(i=1; i<=L.length; i++)
	{
		sign[i].gnum = 0; 
		sign[i].lnum = 0;
	}
	
	for(i=1; i<=L.length-1; i++)
	{
		for(j=i+1; j<=L.length; j++)
		{
			if(L.r[i].key>L.r[j].key)
			{
				sign[i].lnum++;		//�ҵ�һ����iС�� 
				sign[j].gnum++;		//�ҵ�һ����j��� 
			}
			else if(L.r[i].key<L.r[j].key)
			{
				sign[i].gnum++;
				sign[j].lnum++;				
			}
		}
	}
	
	for(i=1; i<=L.length; i++)
	{
		k = abs(sign[i].gnum-sign[i].lnum);

		if(k==0||k==1)
			return L.r[i];
	}
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

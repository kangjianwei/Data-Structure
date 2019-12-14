#include <stdio.h>
#include "../../../���α��㷨ʵ��/��10 �ڲ�����/00 SequenceListType/SequenceListType.c"//**��10 �ڲ�����**//

/* ���Ͷ��� */
typedef SqList_sort TirHeapType;

/* ����ԭ�� */
void Algo_10_35(TirHeapType *H);
void TirHeapAdjust_10_35(TirHeapType *H, int p, int m);	//����r[p..m]Ϊ�󶥶�
void InsertTirHeap_10_35(FILE *fp, TirHeapType *H);		//����Ѳ����㷨 
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	TirHeapType H;
	
	printf("��β����¼���������...\n");
	fp = fopen("Data/Algo_10_35.txt", "r");
	InsertTirHeap_10_35(fp, &H); 
	Traverse(H, PrintKey);
	printf("\n");	

	printf("������ѽ�������...\n");
	Algo_10_35(&H);
	Traverse(H, PrintKey);
	printf("\n");
		
	return 0;
}

/*��������������������������
����10.35������������㷨 ��
��������������������������*/
void Algo_10_35(TirHeapType *H)
{
	int count, s;
	RcdType tmp;

	count = (*H).length;
	
	while(count)						//����ǰ��������Ǵ󶥶� 
	{
		tmp = (*H).r[1];				//�����ؼ��ּ�¼�ŵ���� 
		(*H).r[1] = (*H).r[count];
		(*H).r[count] = tmp;
		
		count--;
		
		TirHeapAdjust_10_35(H, 1, count);//���µ���r[1..count]Ϊ�󶥶� 
	}
}

void TirHeapAdjust_10_35(TirHeapType *H, int p, int m)
{
	int s, max;		//maxָ��ӵ�����ؼ��ֵļ�¼ 
	RcdType tmp;
	
	tmp = (*H).r[p];
	
	while(3*p-1<=m)
	{
		s = 3*p-1;
		max = s;
		for(s=s+1; s<=m; s++)
		{
			if((*H).r[max].key<(*H).r[s].key)
				max = s;
		}
		
		if((*H).r[max].key>tmp.key)
			(*H).r[p] = (*H).r[max];
		else
			break;
			
		p = max;
	}
	
	(*H).r[p] = tmp;
}

void InsertTirHeap_10_35(FILE *fp, TirHeapType *H)
{
	RcdType tmp;
	int p, s;
	
	(*H).length = 0;
	
	while((Scanf(fp, "%d", &tmp.key))==1)
	{
		s = ++(*H).length;
		p = (s+1)/3;
		
		while(p && (*H).r[p].key<tmp.key)
		{
			(*H).r[s] = (*H).r[p];
			s = p;
			p = (s+1)/3;
		}
		
		(*H).r[s] = tmp;
	}
} 

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

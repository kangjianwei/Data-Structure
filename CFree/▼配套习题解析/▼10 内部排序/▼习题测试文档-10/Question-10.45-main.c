#include <stdio.h>
#include <math.h>
#include "../../../���α��㷨ʵ��/��10 �ڲ�����/00 SequenceListType/SequenceListType.c"//**��10 �ڲ�����**//

/* �궨�� */
#define Keynum 3							//�ؼ��ָ����趨Ϊ3 

/* ����ԭ�� */
void Algo_10_45(SqList_sort *L);
int DigitBit_10_45(int x, int c);			//����x��cλ(1-��λ,2-ʮλ,3-��λ...)��ֵ 
void Print_10_45(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
			
	printf("���������һ����������...\n");
	fp = fopen("Data/Algo_10_45.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, Print_10_45);
	printf("\n");	

	printf("���ؼ��ְ�����˳������...\n");
	Algo_10_45(&L); 
	Traverse(L, Print_10_45);
	printf("\n");	
		
	return 0;
}

/*��������������������������������
����10.45�����ü������л������� ��
��������������������������������*/
void Algo_10_45(SqList_sort *L)
{
	int i, j, k;
	SqList_sort Tmp;
	int c[(*L).length+1];
	
	for(k=1; k<=Keynum; k++)
	{
		Tmp = *L;
		
		for(i=1; i<=Tmp.length; i++)		//��ʼ��c[] 
			c[i] = 0;
			
		for(i=1; i<=Tmp.length-1; i++)		//��ÿ����¼��ĳһλͳ�Ʊ���С�Ĺؼ��ָ���	
		{
			for(j=i+1; j<=Tmp.length; j++)
			{								//�Ӹ�λ����ͳ������ 
				if(DigitBit_10_45(Tmp.r[i].key, k)<=DigitBit_10_45(Tmp.r[j].key, k))
					c[j]++;
				else
					c[i]++;
			}		
		}
		
		for(i=1; i<=Tmp.length; i++)		//���� 
			(*L).r[c[i]+1] = Tmp.r[i];	
	}
}

int DigitBit_10_45(int x, int c)
{
	int a = pow(10,c);
	int b = pow(10,c-1);
	
	return (x%a-x%b)/b;
}

void Print_10_45(KeyType e)
{
	printf("%03d ", e);
}

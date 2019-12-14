#include <stdio.h>
#include "../../../���α��㷨ʵ��/��10 �ڲ�����/00 SequenceListType/SequenceListType.c"//**��10 �ڲ�����**//

/* ���Ͷ��� */
typedef SqList_sort HeapType;

/* ����ԭ�� */
void Algo_10_34(FILE *fp, HeapType *H);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	HeapType H;
	
	printf("��β����¼���������...\n");
	fp = fopen("Data/Algo_10_34.txt", "r");
	Algo_10_34(fp, &H); 
	Traverse(H, PrintKey);
	printf("\n");	

	return 0;
}

/*��������������������������
����10.34������Ѳ����㷨 ��
��������������������������*/
void Algo_10_34(FILE *fp, HeapType *H)
{
	RcdType tmp;
	int p, s;
	
	(*H).length = 0;
	
	while((Scanf(fp, "%d", &tmp.key))==1)
	{
		s = ++(*H).length;
		p = s/2;
		
		while(p && (*H).r[p].key>tmp.key)
		{
			(*H).r[s] = (*H).r[p];
			s = p;
			p = s/2;
		}
		
		(*H).r[s] = tmp;
	}
} 

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

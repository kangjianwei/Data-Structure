#include <stdio.h>
#include "../../../���α��㷨ʵ��/��09 ����/00 Base/Base.c" //**��09 ����**//

/* �궨�� */
#define MAX 20						//�ؼ��ָ��� 

/* ����ԭ�� */
int Algo_9_26(Table T, KeyType key, int low, int high);
int Algo_9_27(Table T, KeyType key);

int main(int argc, char *argv[])
{	
	FILE *fp;
	Table T;
	KeyType key = 18;
	int i;
		
	printf("���������һ�����ұ���С����...\n");
	fp = fopen("Data/Algo_9_26-9_27.txt", "r");	
	Create(fp, &T, MAX);
	Traverse(T, PrintKey);	
	printf("\n");

	printf("������ �� 9.26 ��֤... ������\n");	
	i = Algo_9_26(T, key, 1, T.length);
	if(!i)
		printf("�ؼ��� %d δ�ҵ�����\n", key);
	else
		printf("�ؼ��� %d �ڵ� %d ��λ�á�\n", key, i);
	printf("\n");

	printf("������ �� 9.27 ��֤... ������\n");	
	i = Algo_9_27(T, key);
	printf("�ؼ��� %d �ڵ� %d �����䡣\n", key, i);
	printf("\n");
	
	return 0;
}

int Algo_9_26(Table T, KeyType key, int low, int high)
{
	int mid;
	
	if(low>high)				//δ�ҵ�ʱ����0 
		return 0;

	mid = (low+high)/2;
	
	if(T.elem[mid].key==key)
		return mid;
	else if(T.elem[mid].key>key)
		return Algo_9_26(T, key, low, mid-1);
	else
		return Algo_9_26(T, key, mid+1, high);
}

int Algo_9_27(Table T, KeyType key)		//ʵ�����ǲ�ѯ�����ڵ����� 
{
	int low, high, mid;
	
	if(key<T.elem[1].key)
		return 0;

	if(key>=T.elem[T.length].key)
		return T.length;

	low = 1;
	high = T.length;
	
	while(high-low>1)					//���ұ�Ԫ�ش���1 
	{
		mid = (low + high) / 2;
		
		if(T.elem[mid].key<=key)
			low = mid;
		else
			high = mid; 
	}
	
	return low;
}

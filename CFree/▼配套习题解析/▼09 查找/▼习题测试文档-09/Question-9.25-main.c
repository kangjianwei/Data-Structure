#include <stdio.h>
#include "../../../���α��㷨ʵ��/��09 ����/00 Base/Base.c" //**��09 ����**//

/* �궨�� */
#define MAX 20						//�ؼ��ָ��� 

/* ����ԭ�� */
int Algo_9_25(Table T, KeyType key);

int main(int argc, char *argv[])
{	
	FILE *fp;
	Table T;
	KeyType key = 15;
	int i;
		
	printf("���������һ�����ұ��Դ���С��...\n");
	fp = fopen("Data/Algo_9_25.txt", "r");	
	Create(fp, &T, MAX+1);			//�࿪��һ����λ 
	Traverse(T, PrintKey);	
	printf("\n");
	
	i = Algo_9_25(T, key);
	if(i==MAX+1)
		printf("�ؼ��� %d δ�ҵ�����\n", key);
	else
		printf("�ؼ��� %d �ڵ� %d ��λ�á�\n", key, i);
	printf("\n");
		
	return 0;
}

int Algo_9_25(Table T, KeyType key)
{
	int i;
	
	T.elem[MAX+1].key = key;
	
	for(i=1; T.elem[i].key!=key; ++i)
		;
	
	return i;
}

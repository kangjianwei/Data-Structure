#include <stdio.h>
#include <stdlib.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��01 ����/Scanf.c"

/* �궨�� */
#define MAXSIZE 100

/* ���Ͷ��� */
typedef struct KNode		//�ڽӱ������� 
{
	int key;
	struct KNode *next;
}KNode;				
typedef struct
{
	KNode *first;
}HNode;
typedef HNode HashTable[MAXSIZE];

/* ����ԭ�� */
void Algo_9_45(FILE *fp, HashTable H);	//������ϣ�� 
int fHash_9_45(int key);				//����i�Ĺ�ϣ��ַ 
void Print_9_45(HashTable H);

int main(int argc, char *argv[])
{	
	FILE *fp;
	int p;
	HashTable H;

	fp = fopen("Data/Algo_9_45.txt","r");
	Algo_9_45(fp, H);
	fclose(fp);
	
	printf("�����ϣ�������йؼ��֣�\n");
	Print_9_45(H);
	printf("\n");
	
	return 0;
}

/*����������������������������������������
����9.45��������ϣ��������ַ�������ͻ��
����������������������������������������*/
void Algo_9_45(FILE *fp, HashTable H)
{
	int i, p;
	int tmp;
	KNode *r, *h;
	
	for(i=0; i<MAXSIZE; i++)
		H[i].first = NULL;

	while(Scanf(fp, "%d", &tmp)==1)			//¼��ؼ��ֵ���ϣ�� 
	{
		h = (KNode*)malloc(sizeof(KNode));
		h->key = tmp;
		h->next = NULL;
		
		p = fHash_9_45(tmp);
		
		if(H[p].first==NULL)
			H[p].first = h;
		else
		{
			if(H[p].first->key>tmp)
			{
				h->next = H[p].first;
				H[p].first = h;
			}
			else
			{
				r = H[p].first;
				
				while(r->next&&r->next->key<=tmp)
					r = r->next;
					
				h->next = r->next;
				r->next = h;					
			}
		}		
	}
}

int fHash_9_45(int key)		//��ϣ���� 
{
	return key%13;			//H(key) = key MOD 13
}

void Print_9_45(HashTable H)
{
	int i;
	KNode *r;
	
	for(i=1; i<MAXSIZE; i++)
	{
		if(H[i].first)
		{
			for(r=H[i].first; r; r=r->next)
				printf("%d ", r->key);
		}
	}
}

#include <stdio.h>
#include <string.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��01 ����/Scanf.c"

/* �궨�� */
#define MAXSIZE 100

/* ���Ͷ��� */
typedef struct
{
	char s[27];		//�ؼ��ֳ��Ȳ�����26 
}HNode;
typedef HNode HashTable[MAXSIZE];

/* ����ԭ�� */
void Algo_9_44(HashTable H);
Status CreateHash_9_44(FILE *fp, HashTable H);//������ϣ�� 
int fHash_9_44(char s[]);//����s����ĸ(��д)����ĸ���е�λ��

int main(int argc, char *argv[])
{	
	FILE *fp;
	int p;
	HashTable H;

	fp = fopen("Data/Algo_9_44.txt","r");
	CreateHash_9_44(fp, H);
	fclose(fp);
	
	printf("������ĸ�ֵ�˳�������ϣ�������йؼ��֣�\n");
	Algo_9_44(H);
	printf("\n");
	
	return 0;
}

/*����������������������������������������������
����9.44�����ؼ�������ĸ˳�������ϣ���йؼ��֩�
����������������������������������������������*/
void Algo_9_44(HashTable H)
{
	int i, j;
	
	for(i=1; i<=26; i++)
	{
		j = i;
		
		while(strcmp(H[j].s,"")!=0)
		{
			if(fHash_9_44(H[j].s)==i)
				printf("%s ", H[j].s);
			j = (j+1)%MAXSIZE;
		}
	} 
}

Status CreateHash_9_44(FILE *fp, HashTable H)
{
	int i, p;
	char tmp[26];
	
	for(i=0; i<MAXSIZE; i++)
		strcpy(H[i].s, "");

	while(Scanf(fp, "%s", tmp)==1)			//¼��ؼ��ֵ���ϣ�� 
	{
		p = fHash_9_44(tmp);
		
		while(strcmp(H[p].s, "")!=0)		//���ֳ�ͻ
			p = (p+1)%MAXSIZE;
		
		if(strcmp(H[p].s, "")==0)
			strcpy(H[p].s, tmp);
		else								//�˴�δ��ʧ����������� 
			return ERROR;		
	}
	
	return OK;
}

int fHash_9_44(char s[])		//��ϣ���� 
{
	return s[0]-'A'+1;			//�趨�ؼ�������ĸΪ��д 
}

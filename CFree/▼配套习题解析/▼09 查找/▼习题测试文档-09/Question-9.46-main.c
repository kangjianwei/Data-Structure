#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��01 ����/Scanf.c"

/* �궨�� */
#define MAXSIZE 20000

/* ���Ͷ��� */
typedef struct
{
	int row;
	int col;
	int key;
	int tag;					//tag=0:���Ϊ�� 
}HNode;
typedef HNode HashTable[MAXSIZE];

/* ����ԭ�� */
int Algo_9_46(HashTable H, int row, int col);
Status CreateHash_9_46(FILE *fp, HashTable H);//������ϣ�� 
int fHash_9_46(int row, int col);//��������ֵ���ɹ�ϣ��ַ 

int main(int argc, char *argv[])
{	
	FILE *fp;
	int p;
	HashTable H;

	fp = fopen("Data/Algo_9_46.txt","r");
	CreateHash_9_46(fp, H);
	fclose(fp);
	
	printf("���Ҳ��ԣ�\n");
	p = Algo_9_46(H, 622,64);
	printf("�±�Ϊ(%d %d)�Ĺؼ����ڹ�ϣ��� %d ��λ�á�\n", 622, 64, p);
	printf("\n");
	
	return 0;
}

/*����������������������������������������
����9.46������ָ������ֵ�ڹ�ϣ���е�λ�é�
����������������������������������������*/
int Algo_9_46(HashTable H, int row, int col)
{
	int p;
	
	p = fHash_9_46(row, col);						
	
	while(H[p].tag==1&&(H[p].row!=row||H[p].col!=col))
		p = (p+1)%MAXSIZE;		//�����֡���Ч��ײ����˳�����²��� 
	
	if(H[p].tag==1&&H[p].row==row&&H[p].col==col)
		return p;
	else
		return -1;				//������ֵ�µĹؼ��ֲ�����ʱ����-1 
}

Status CreateHash_9_46(FILE *fp, HashTable H)
{
	int i, p;
	int row, col, key;
	
	for(i=0; i<MAXSIZE; i++)
		H[i].tag = 0;

	while(Scanf(fp, "%d%d%d", &row, &col, &key)==3) //¼��ؼ��ֵ���ϣ�� 
	{
		p = fHash_9_46(row, col);
		
		while(H[p].tag==1)				//���ֳ�ͻ
			p = (p+1)%MAXSIZE;
		
		if(H[p].tag==0)
		{
			H[p].tag = 1;
			H[p].row = row;
			H[p].col = col;
			H[p].key = key;
		}
		else							//�˴�δ��ʧ����������� 
			return ERROR;		
	}
	
	return OK;
}

int fHash_9_46(int row, int col)	//��ϣ���� 
{
	int a, b, c;
	
	a = row%100;					//ȡ����ֵ�ĺ���λ
	b = col%100;
	c = a*100 + b;					//c�ķ�Χ��0~9999 
	
	return 2*c;
}

#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/07 ChildSiblingTree/ChildSiblingTree.c" //**��06 ���Ͷ�����**//

/* ����ԭ�� */
void Algo_6_71_1(CSTree T, int i);
void Algo_6_71_2(CSTree T, int i);

int main(int argc, char *argv[])
{
	CSTree T;
	FILE *fp; 

	printf("�����������У�ABE^F^^CG^^D^^^...\n");
	InitTree_CS(&T);
	fp = fopen("Data/Algo_6_71.txt", "r");
	CreateTree_CS(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("��TΪ��\n");
	Print_CS(T);
	printf("\n");
	
	printf("���� 1�����������������ӡ����\n");
	Algo_6_71_1(T, 0);
	printf("\n");

	printf("���� 2�����������������ӡ����\n");
	Algo_6_71_2(T, 0);
	printf("\n");
		
	return 0;
}

/*��������������������������������
����6.71�����������������ӡ����
��������������������������������*/
/* ����1��ֱ��ʹ�õݹ� */
void Algo_6_71_1(CSTree T, int i)			//i��ʼ��Ϊ0 
{
	int j;
	
	if(T)
	{
		for(j=1; j<=2*i; j++)
			printf(" ");		
		printf("%c\n", T->data);
		
		Algo_6_71_1(T->firstchild, i+1);
		Algo_6_71_1(T->nextsibling, i);		//�˴�Ϊi 
	}
}

/* ����2����ѭ����ʹ�õݹ� */
void Algo_6_71_2(CSTree T, int i)
{
	int j;
	CSTree p;
	
	if(T)
	{
		for(j=1; j<=2*i; j++)
			printf(" ");		
		printf("%c\n", T->data);
		
		for(p=T->firstchild; p; p=p->nextsibling)
			Algo_6_71_2(p, i+1);	
	}
}

#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/06 ChildTree/ChildTree.c" //**��06 ���Ͷ�����**//

/* ����ԭ�� */
void Algo_6_72_1(CTree T, int order, int i);
void Algo_6_72_2(CTree T, int order, int i);

int main(int argc, char *argv[])
{
	CTree T;
	FILE *fp;

	fp = fopen("Data/Algo_6_72.txt", "r");	
	InitTree_C(fp, &T); 
	CreateTree_C(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("��TΪ��\n");
	Print_C_1(T);
	printf("\n");
	
	printf("���������������ӡ����\n");
	Algo_6_72_1(T, T.r, 0);
	printf("\n");

	printf("���������������ӡ����\n");
	Algo_6_72_2(T, T.r, 0);
	printf("\n");
		
	return 0;
}

/*��������������������������������
����6.72�����������������ӡ����
��������������������������������*/
/* ����1��ֱ��ʹ�õݹ� */
void Algo_6_72_1(CTree T, int order, int i)			//i��ʼ��Ϊ0 
{
	int j, k;
	
	if(T.n)
	{
		for(j=1; j<=2*i; j++)
			printf(" ");		
		printf("%c\n", T.nodes[order].data);
		
		if(T.nodes[order].firstchild)				//���ʺ��ӽ�� 
			Algo_6_72_1(T, T.nodes[order].firstchild->child, i+1);
		
		k = Sibling_C_2(T, order, 1);				//���ؽ��order���ҽ���λ�� 
		if(k>=0)									//�������ֵܽ�� 
			Algo_6_72_1(T, k, i);
	}
}

/* ����2����ѭ����ʹ�õݹ� */
void Algo_6_72_2(CTree T, int order, int i)			//i��ʼ��Ϊ0 
{
	int j, k;
	ChildPtr p;
	
	if(T.n)
	{
		for(j=1; j<=2*i; j++)
			printf(" ");		
		printf("%c\n", T.nodes[order].data);
		
		for(p=T.nodes[order].firstchild; p; p=p->next)
			Algo_6_72_2(T, p->child, i+1);
	}
}

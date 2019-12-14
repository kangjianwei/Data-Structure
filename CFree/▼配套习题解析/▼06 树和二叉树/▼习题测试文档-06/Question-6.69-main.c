#include <stdio.h>
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/02 BinaryTree/BinaryTree.c" //**��06 ���Ͷ�����**//

/* ����ԭ�� */
void Algo_6_69(BiTree T, int i);

int main(int argc, char *argv[])
{
	BiTree T;
	FILE *fp;
	
	printf("�������������������У�T�� AB^D^^CE^F^^^...\n");
	InitBiTree(&T);
	fp = fopen("Data/Algo_6_69.txt", "r");
	CreateBiTree(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("������TΪ��\n");
	PrintTree(T);
	printf("\n");
	
	printf("�����������Ұ������ӡ����\n");
	Algo_6_69(T, 0);
	printf("\n");
	
	return 0;
}

/*����������������������������������
����6.69�������������Ұ������ӡ����
����������������������������������*/
void Algo_6_69(BiTree T, int i)			//i������Ը�������˼����������˲�����Ϣ 
{
	int j;
	
	if(T)
	{
		Algo_6_69(T->rchild, i+1);		//�ȷ��������� 
		
		for(j=1; j<=2*i; j++)			//i����2��Ϊ�����Ч�����ۣ�ʵ�ʿո������� 
			printf(" ");
		printf("%c\n", T->data);
		
		Algo_6_69(T->lchild, i+1);		//������������ 
	}
}

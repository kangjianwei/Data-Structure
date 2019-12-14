#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"				//**��01 ����**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/02 BinaryTree/BinaryTree.c" //**��06 ���Ͷ�����**//

/* ����ԭ�� */
Status Algo_6_36(BiTree B1, BiTree B2);

int main(int argc, char *argv[])
{
	BiTree B1, B2, B3;
	FILE *fp;												//����Դ 
	char tmp;
		
	InitBiTree(&B1); 
	InitBiTree(&B2);
	InitBiTree(&B3);
	
	printf("�������������������У�B1�� ABD^^E^^C^^...\n");
	printf("                      B2�� FGH^^I^^J^^...\n");
	printf("                      B3�� KLM^^N^^OP^^^...\n");
	fp = fopen("Data/Algo_6_36.txt", "r");
	CreateBiTree(fp, &B1);
	Scanf(fp, "%c", &tmp);			//�������з� 
	CreateBiTree(fp, &B2);
	Scanf(fp, "%c", &tmp);			//�������з� 
	CreateBiTree(fp, &B3);
	fclose(fp);
	printf("\n");
	
	printf("������B1Ϊ��\n");
	PrintTree(B1);
	printf("\n");
	printf("������B2Ϊ��\n");
	PrintTree(B2);
	printf("\n");
	printf("������B3Ϊ��\n");
	PrintTree(B3);
	printf("\n");

	if(Algo_6_36(B1, B2))
		printf("B1��B2���ƣ�\n");
	else
		printf("B1��B2�����ƣ���\n"); 

	if(Algo_6_36(B2, B3))
		printf("B2��B3���ƣ�\n");
	else
		printf("B1��B3�����ƣ���\n");  
	
	printf("\n");
	
	return 0;
}

/*����������������������������
����6.36���ж�B1��B2�Ƿ����Ʃ�
����������������������������*/
Status Algo_6_36(BiTree B1, BiTree B2)
{
	if(BiTreeEmpty(B1) && BiTreeEmpty(B2))			//��Ϊ���� 
		return TRUE;
	else
	{
		if(!BiTreeEmpty(B1) && !BiTreeEmpty(B2))	//����Ϊ���� 
		{
			if(Algo_6_36(B1->lchild, B2->lchild) && Algo_6_36(B1->rchild, B2->rchild))	//�ж��������� 
				return TRUE;	
		}
	}
	
	return FALSE;
}

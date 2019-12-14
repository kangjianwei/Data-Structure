#include <stdio.h>
#include <stdlib.h>										//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/02 BinaryTree/BinaryTree.c" //**��06 ���Ͷ�����**//

/* ����ԭ�� */
void Algo_6_50(FILE *fp, BiTree *T);

int main(int argc, char *argv[])
{
	BiTree T;
	FILE *fp; 

	printf("�������������������У�...\n");
	InitBiTree(&T);
	fp = fopen("Data/Algo_6_50.txt", "r");
	Algo_6_50(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("������TΪ��\n");
	PrintTree(T);	
	printf("\n");
	
	return 0;
}

/*������������������������������������������
����6.50�������򴴽���������������ʽ���⣩��
������������������������������������������*/
void Algo_6_50(FILE *fp, BiTree *T)
{
	char input[4];
	BiTree tmp[100];								//˳��洢������ÿ����� 
	int m, n;
	BiTree p;
	
	m = n = 0;
	printf("���������С�\n");
	while(1)
	{			
		Scanf(fp, "%s", input);
		printf("%s\n", input);
		
		if(input[1]=='^')							//�˳���־ 
			break;
		else
		{
			p = (BiTree)malloc(sizeof(BiTNode));
			if(!p)
				exit(OVERFLOW);
			p->data = input[1];
			p->lchild = p->rchild = NULL;
			
			if(input[0]=='^')						//�����   
				*T = p;
			else
			{
				while(tmp[m]->data!=input[0])		//Ѱ��������� 
					m++;
					
				if(input[2]=='L')
					tmp[m]->lchild = p;
				else
					tmp[m]->rchild = p;				
			}
			
			tmp[n++] = p;
		}
	}
}

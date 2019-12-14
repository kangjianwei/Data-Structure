#include <stdio.h>
#include <stdlib.h>								//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/02 BinaryTree/BinaryTree.c" //**��06 ���Ͷ�����**//

/* ����ԭ�� */
Status Algo_6_70(FILE *fp, BiTree *T);

int main(int argc, char *argv[])
{
	BiTree T;
	FILE *fp;
	
	printf("��Ϊʾ��¼�����У���д��ĸ����A(B(#,D),C(E(#,F),#))...\n");
	fp = fopen("Data/Algo_6_70.txt", "r");
	Algo_6_70(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("չʾ����������\n");
	PrintTree(T);
	printf("\n");
	
	return 0;
}

/*����������������������������������
����6.70�������������Ķ�������ṹ��
����������������������������������*/
Status Algo_6_70(FILE *fp, BiTree *T)
{
	char c;
	
	while(1)
	{
		Scanf(fp, "%c", &c);
		if(feof(fp))								//�ַ���ȡ��� 
			break;
		
		if(c=='#')
			*T = NULL;			
		else if(c>='A' && c<='Z')
		{
			*T = (BiTree)malloc(sizeof(BiTNode));	//����� 
			if(!(*T))
				exit(OVERFLOW);
			(*T)->data = c;
			(*T)->lchild = (*T)->rchild = NULL;
		}
		else if(c=='(')
		{
			Algo_6_70(fp, &(*T)->lchild);
			Algo_6_70(fp, &(*T)->rchild);
		}
		else
			break;				
	}
	
	return OK;
}

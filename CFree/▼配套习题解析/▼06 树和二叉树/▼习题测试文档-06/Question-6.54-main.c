#include <stdio.h>
#include <stdlib.h>										//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/02 BinaryTree/BinaryTree.c" //**��06 ���Ͷ�����**//

/* ����ԭ�� */
Status Algo_6_54(BiTree *T, TElemType sa[100]);

int main(int argc, char *argv[])
{
	BiTree T;
	TElemType sa[100], e;
	FILE *fp;
	int i;
	
	i = 0;
	fp = fopen("Data/Algo_6_54.txt", "r");
	Scanf(fp, "%c", &e);				//��ʼ������sa��Ŷ�������˳��ṹ
	while(!feof(fp))
	{
		sa[++i] = e;
		Scanf(fp, "%c", &e);		
	}
	fclose(fp);
	sa[0] = i;
	
	printf("��������������˳������ΪT�� ABCDEF^G^HI^J\n");
	InitBiTree(&T); 
	Algo_6_54(&T, sa);
	printf("\n");
	
	printf("������TΪ��\n");
	PrintTree(T);
	printf("\n");
	
	return 0;
}

/*������������������������������
����6.54������˳�������������
������������������������������*/
Status Algo_6_54(BiTree *T, TElemType sa[100])
{	
	int len = sa[0];								//0�ŵ�Ԫ�洢���������ȣ��������������㣩 
	int i, k; 
	BiTree p;
	BiTree node[100];								//��ʱ��ű����и����ָ��ĸ���Ʒ 
	
	for(i=1,k=1; i<=sa[0]; i++)
	{
		if(sa[i]=='^')
			p = NULL;
		else
		{
			p = (BiTree)malloc(sizeof(BiTNode));
			if(!p)
				exit(OVERFLOW);
			p->data = sa[i];
			p->lchild = p->rchild = NULL;		
		}
		
		if(i==1)
			*T = p;
		else
		{
			while(i/2!=k)
				k++;
			
			if(i==2*k)
				node[k]->lchild = p;
			if(i==2*k+1)
				node[k]->rchild = p;    
		}
												 
		node[i] = p;								//Ϊ����saͬ����node��0�ŵ�Ԫ����
	}
	
	return OK;
}

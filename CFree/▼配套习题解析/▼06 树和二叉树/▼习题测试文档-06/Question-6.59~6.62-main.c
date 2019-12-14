#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/07 ChildSiblingTree/ChildSiblingTree.c" //**��06 ���Ͷ�����**//

/* ����ԭ�� */
void Algo_6_59(CSTree T);
int Algo_6_60(CSTree T);
int Algo_6_61(CSTree T);
int Algo_6_62(CSTree T);

int main(int argc, char *argv[])
{
	CSTree T;
	FILE *fp;

	 
	printf("¼���������У�RAD^E^^B^CFG^H^K^^^^^...\n");
	InitTree_CS(&T);
	fp = fopen("Data/Algo_6_59-6.62.txt", "r");	 
	CreateTree_CS(fp, &T); 
	fclose(fp);
	printf("\n");
	
	printf("�������� 6.59 ��֤...������\n");
	{
		printf("������б�...\n��");
		Algo_6_59(T);
		printf("\n\n");	
	}
	
	printf("�������� 6.60 ��֤...������\n");
	{
		int count;
		
		count = Algo_6_60(T);
		printf("Ҷ�ӽ�����Ϊ��count = %d\n", count);
		printf("\n");	
	}

	printf("�������� 6.61 ��֤...������\n");
	{
		int degree;
		
		degree = Algo_6_61(T);
		printf("���Ķ�Ϊ��degree = %d\n", degree);
		printf("\n");	
	}	

	printf("�������� 6.62 ��֤...������\n");
	{
		int depth;
		
		depth = Algo_6_62(T);
		printf("�������Ϊ��depth = %d\n", depth);
		printf("\n");	
	}
		
	return 0;
}

/*������������������������
����6.59��������ĸ����ߩ�
������������������������*/
void Algo_6_59(CSTree T)
{
	CSTree p, q;
	
	if(T)
	{
		p = T;
		q = T->firstchild;
		
		while(q)
		{
			printf("(%c, %c) ", p->data, q->data);
			q = q->nextsibling;
		}
		
		Algo_6_59(T->firstchild);
		Algo_6_59(T->nextsibling);
	}
} 

/*����������������������������
����6.59��������Ҷ�ӽ�������
����������������������������*/
int Algo_6_60(CSTree T)
{	
	if(T)
	{
		if(!T->firstchild)
			return 1 + Algo_6_60(T->nextsibling);
		else
			return Algo_6_60(T->firstchild) + Algo_6_60(T->nextsibling);
	}
	else
		return 0;
}

/*������������������
����6.61�������Ķȩ�
������������������*/
int Algo_6_61(CSTree T)
{
	return TreeDegree_CS(T);						//�Ѷ��� 
}

/*��������������������
����6.62����������ȩ�
��������������������*/
int Algo_6_62(CSTree T)
{
	return TreeDepth_CS(T);							//�Ѷ��� 
}

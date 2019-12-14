#include <stdio.h>
#include <stdlib.h>								//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/07 ChildSiblingTree/ChildSiblingTree.c" //**��06 ���Ͷ�����**//

/* ����ԭ�� */
Status Algo_6_73(FILE *fp, CSTree *T);
void Algo_6_74(CSTree T);

int main(int argc, char *argv[])
{
	CSTree T;
	FILE *fp; 
		
	printf("������ �� 6.73 ��֤... ������\n");
	printf("��Ϊʾ����¼�����У�A(B(E,F),C(G),D)...\n");
	printf("��������-�ֵ�����...\n");
	fp = fopen("Data/Algo_6_73-6.74.txt", "r");
	Algo_6_73(fp, &T);
	fclose(fp);
	Print_CS(T);
	printf("\n");

	printf("������ �� 6.74 ��֤... ������\n");	
	printf("��������ӡ����-�ֵ�����...\n");
	Algo_6_74(T);
	printf("\n\n");	
		
	return 0;
}

/*����������������������������
����6.73����������-�ֵ����� ��
����������������������������*/
Status Algo_6_73(FILE *fp, CSTree *T)
{	
	char c;
	
	while(1)
	{
		Scanf(fp, "%c", &c);
		if(feof(fp))
			break;
	
		if(c>='A' && c<='Z')
		{
			*T = (CSTree)malloc(sizeof(CSNode));	//����� 
			if(!(*T))
				exit(OVERFLOW);
			(*T)->data = c;
			(*T)->firstchild = (*T)->nextsibling = NULL;
		}
		else if(c=='(')
			Algo_6_73(fp, &(*T)->firstchild);
		else if(c==',')
		{
			Algo_6_73(fp, &(*T)->nextsibling);		
			break;									//ע��˴�Ӧ�÷��� 
		}
		else
			break;				
	}
	
	return OK;
}

/*����������������������������������������
����6.74���������ʽ��ӡ����-�ֵ����� ��
����������������������������������������*/
void Algo_6_74(CSTree T)
{
	int i;
	CSTree p;
	
	if(T)
	{
		printf("%c", T->data);
		
		if(T->firstchild)
		{
			printf("(");
			
			for(p=T->firstchild; p; p=p->nextsibling)
			{
				Algo_6_74(p);
				if(p->nextsibling)				//���������һ���ֵܣ���"," 
					printf(",");
			}
			
			printf(")");
		}
	} 
}

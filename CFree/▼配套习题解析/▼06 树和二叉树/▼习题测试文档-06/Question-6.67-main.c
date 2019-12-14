#include <stdio.h>
#include <stdlib.h>										//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/07 ChildSiblingTree/ChildSiblingTree.c" //**��06 ���Ͷ�����**//

/* ����ԭ�� */
void Algo_6_67(FILE *fp, CSTree *T);

int main(int argc, char *argv[])
{
	CSTree T;
	FILE *fp;

	fp = fopen("Data/Algo_6_67.txt", "r");	
	Algo_6_67(fp, &T); 
	fclose(fp);
	printf("\n");
	
	printf("�����ĺ����ֵܶ�����Ϊ��\n");
	Print_CS(T);
	printf("\n");
	
	return 0;
}

/*��������������������������������
�� ��6.67���������ĺ���-�ֵܽṹ��
��������������������������������*/
void Algo_6_67(FILE *fp, CSTree *T)
{
	char input[3];
	CSTree tmp[100]; 								//˳��洢������ÿ�����
	CSTree p, q;
	int m, n, count;
	
	m = n = 0;
	count = 0;
	while(1)
	{
		printf("¼��� %d ����Ԫ�飺", ++count);
		Scanf(fp, "%s", input); 
		printf("%s\n", input);
		
		if(input[1]=='^')							//�˳���־ 
			break;
		else
		{
			p = (CSTree)malloc(sizeof(CSNode));
			if(!p)
				exit(OVERFLOW);
			p->data = input[1];
			p->firstchild = p->nextsibling = NULL;
			
			if(input[0]=='^')						//�����   
				*T = p;
			else
			{
				while(tmp[m]->data!=input[0])
					m++;

				if(tmp[m]->firstchild==NULL)		//��Ϊ��һ������ 
					tmp[m]->firstchild = p;
				else
				{
					q = tmp[m]->firstchild;			//Ѱ�Һ��������ĩ�� 
					while(q->nextsibling)
						q = q->nextsibling;
					q->nextsibling = p;
				}							
			}			
						
			tmp[n++] = p;			
		}
	}
}

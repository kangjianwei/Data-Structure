#include <stdio.h>
#include <stdlib.h>												//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	        //**��01 ����**//
#include "../../../���α��㷨ʵ��/��05 ����͹����/05 GeneralizedList-H&T/GeneralizedList-H-T.c" //**��05 ����͹����**//

/* ����ԭ�� */
Status Algo_5_35(FILE *fp, GList *L);
Status Creat_5_35(FILE *fp, GList *L);		//����ͷβ����洢��ʾ�Ĺ����

int main(int argc, char *argv[])
{
	GList L;	
	FILE *fp;
	
	printf("��������� L ...\n");
	fp = fopen("Data/Algo_5_35.txt", "r");
	Algo_5_35(fp, &L);
	fclose(fp);
		
	printf("L = ");
	Output_GL_H_T(L, 0);	
	printf("\n\n");	
		
	return 0;
}

/*��������������������
����5.35�����������
��������������������*/ 
Status Algo_5_35(FILE *fp, GList *L)	 
{
	char ch;
	
	ch = getc(fp);
	if(ch=='(')								//������ͷ�׸�'(' 
	{
		if(Creat_5_35(fp, L))				//��ʼ��������� 
			return OK;
	}
	
	return ERROR;
}

Status Creat_5_35(FILE *fp, GList *L)
{
	char ch;
	
	ch = getc(fp);
	
	if(ch==' ')					//����ձ� 
	{
		*L = NULL;
		if(getc(fp)!=')')
			return ERROR;
	}
	else
	{
		*L = (GList)malloc(sizeof(GLNode));	//����ǿձ���� 
		if(!*L)
			exit(OVERFLOW);	
		(*L)->tag = List;
		
		if(ch>='a' && ch<='z')				//����Ԫ����ԭ�ӣ���ԭ�ӽ�� 
		{
			(*L)->Union.ptr.hp = (GList)malloc(sizeof(GLNode));
			(*L)->Union.ptr.hp->tag = Atom;
			(*L)->Union.ptr.hp->Union.atom = ch;
		}
		else if(ch=='(')					//����Ԫ���Ǳ����½����� 									
			Creat_5_35(fp, &((*L)->Union.ptr.hp));
		else
			return ERROR;
		
		ch = getc(fp);						//��ǰ�����β 
		
		if(ch==')')							//��ǰ�������޽�� 
			(*L)->Union.ptr.tp = NULL;
		else if(ch==',')					//��ǰ�������н�� 
			Creat_5_35(fp, &((*L)->Union.ptr.tp));
		else
			return ERROR;	
	}
	
	return OK;	
}

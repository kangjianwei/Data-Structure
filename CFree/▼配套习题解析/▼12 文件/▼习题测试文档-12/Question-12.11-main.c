#include <stdio.h>
#include <stdlib.h>
#include "../../../���α��㷨ʵ��/��12 �ļ�/01 SequentialFile/MergeFile.c"	//**��12 �ļ�**//

/* ����ԭ�� */
void Algo_12_11(FILE *f, FILE *g, FILE *h, FILE *log);

int main(int argc, char *argv[])
{
	FILE *f, *g, *h, *log;
	FILE *fp;
			
	printf("������������ļ�f�������ļ�g...\n");
	f = fopen("main.file", "w+");
	g = fopen("affair.file", "w+");
	InitFile(f,g);
	printf("�����ļ���¼��");
	fp = fopen("main.file", "r");
	Print(fp, 0);
	printf("�������ļ���¼��");
	fp = fopen("affair.file", "r");
	Print(fp, 1);
	printf("\n");	

	printf("�������ļ�f�������ļ�g�������ļ�h...\n");	
	f = fopen("main.file", "r");	
	g = fopen("affair.file", "r");	
	h = fopen("new.file", "w+");
	MergeFile(f, g, h, log);	
	printf("�����ļ���¼��");
	fp = fopen("new.file", "r");
	Print(fp, 0);
	printf("��������־��¼��");
	if((fp=fopen("ErrorLog.file", "r"))!=NULL)
		Print(fp, 1);
	printf("\n\n");
	
	system("del *.file"); 			//ɾ��*.file�ļ� 
	
	return 0;
}

/*��������������������������������
����12.11���鲢���ļ��������ļ� ��
��������������������������������*/
void Algo_12_11(FILE *f, FILE *g, FILE *h, FILE *log)	
{
	MergeFile(f, g, h, log);				 
}

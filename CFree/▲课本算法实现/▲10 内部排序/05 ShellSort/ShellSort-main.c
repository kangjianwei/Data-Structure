/********************************
 *						        *
 * �ļ���: ��10 �ڲ�����        *
 * 						        *
 * �ļ���: ShellSort-main.c     *
 * 							    *
 * ��  ��: ϣ��������غ������� *
 *                              *
 ********************************/

#include <stdio.h>
#include "ShellSort.c"		//**��10 �ڲ�����**//

void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	SqList_sort L;
	
	printf("���������һ����������...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData.txt", "r");
		CreateSortList(fp, &L);
		Traverse(L, PrintKey);
		printf("\n");
	}	
	PressEnter;
	
	printf("��1��2\n������ ShellSort ����...\n");	//1��2.����ShellSort����
	{
		printf("���ؼ��ְ�����˳������...\n");
		ShellSort(&L, dlta, t); 
		Traverse(L, PrintKey);
		printf("\n");
	}	
	PressEnter;
		
	return 0;
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}

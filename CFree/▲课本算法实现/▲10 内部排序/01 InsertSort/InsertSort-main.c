/************************************
 *						            *
 * �ļ���: ��10 �ڲ�����            *
 * 						            *
 * �ļ���: InsertSort-main.c        *
 * 							        *
 * ��  ��: ֱ�Ӳ���������غ������� *
 *                                  *
 ************************************/

#include <stdio.h>
#include "InsertSort.c" 						//**��10 �ڲ�����**//

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
	
	printf("��1\n������ InsertSort ����...\n");	//1.����InsertSort����
	{
		printf("���ؼ��ְ�����˳������...\n");
		InsertSort(&L); 
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

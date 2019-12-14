/************************************
 *						            *
 * �ļ���: ��10 �ڲ�����            *
 * 						            *
 * �ļ���: 2-InsertSort-main.c      *
 * 							        *
 * ��  ��: 2-·����������غ������� *
 *                                  *
 ************************************/

#include <stdio.h>
#include "2-InsertSort.c" 		//**��10 �ڲ�����**//

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
	
	printf("��1\n������ TwoTayInsertSort ����...\n");	//1.����TwoTayInsertSort����
	{
		printf("���ؼ��ְ�����˳������...\n");
		TwoTayInsertSort(&L); 
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

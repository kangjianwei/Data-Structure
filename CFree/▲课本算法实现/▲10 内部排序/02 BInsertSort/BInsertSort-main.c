/************************************
 *						            *
 * �ļ���: ��10 �ڲ�����            *
 * 						            *
 * �ļ���: BInsertSort-main.c       *
 * 							        *
 * ��  ��: �۰����������غ������� *
 *                                  *
 ************************************/

#include <stdio.h>
#include "BInsertSort.c" 	//**��10 �ڲ�����**//

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
	
	printf("��1\n������ BInsertSort ����...\n");	//1.����BInsertSort����
	{
		printf("���ؼ��ְ�����˳������...\n");
		BInsertSort(&L); 
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

/************************************
 *						            *
 * �ļ���: ��10 �ڲ�����            *
 * 						            *
 * �ļ���: SelectSort-main.c        *
 * 							        *
 * ��  ��: ��ѡ��������غ������� *
 *                                  *
 ************************************/

#include <stdio.h>
#include "SelectSort.c" 									//**��10 �ڲ�����**//

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
	
	printf("��1��2\n������ SelectSort�� ����...\n");					//1��2.����SelectSort�Ȳ���
	{
		printf("���ؼ��ְ�����˳������...\n");
		SelectSort(&L); 
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

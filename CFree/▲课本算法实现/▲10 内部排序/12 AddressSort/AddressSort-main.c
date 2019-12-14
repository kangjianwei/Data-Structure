/**************************************
 *						              *
 * �ļ���: ��10 �ڲ�����              *
 * 						              *
 * �ļ���: AddressSort-main.c         *
 * 							          *
 * ��  ��: ˳����ַ������غ������� *
 *                                    *
 **************************************/

#include <stdio.h>
#include "AddressSort.c"		//**��10 �ڲ�����**//

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
	
	printf("��1��2\n������ AddressSort�� ����...\n");	//1��2.����AddressSort�Ȳ���
	{
		printf("���ؼ��ְ�����˳������...\n");
		AddressSort(&L); 
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
